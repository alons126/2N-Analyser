void histogram_macro() {
    // Open the ROOT file and retrieve the histogram
    TFile *file = TFile::Open("your_file.root");
    if (!file || file->IsZombie()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    TH1D *h = (TH1D *)file->Get("Multiplicity of FD neutrons by redef. APID&AV (nFDpCD, FD)");
    if (!h) {
        std::cerr << "Error: Histogram not found." << std::endl;
        file->Close();
        return;
    }

    // Create canvas with specified dimensions
    TCanvas *c = new TCanvas("c1", "c2", 1000 * 1.25, 750 * 1.25);
    c->cd()->SetGrid();
    c->cd()->SetBottomMargin(0.14);
    c->cd()->SetLeftMargin(0.16);
    c->cd()->SetRightMargin(0.16);
    c->cd()->SetTopMargin(0.12);

    // Draw the full histogram
    h->Draw();

    // Create and configure upper and lower range histograms
    TH1D *hUpper = (TH1D *)h->Clone("hUpper");
    hUpper->GetXaxis()->SetRangeUser(2, 10);
    TH1D *hUpperClone = (TH1D *)hUpper->Clone("hUpperClone");

    TH1D *hLower = (TH1D *)h->Clone("hLower");
    hLower->GetXaxis()->SetRangeUser(0, 2);
    TH1D *hLowerClone = (TH1D *)hLower->Clone("hLowerClone");

    // Calculate entries in the specified range (2 to 10)
    int bin_min = h->FindBin(2);
    int bin_max = h->FindBin(10);

    double entries_in_range = 0;
    for (int bin = bin_min; bin <= bin_max; ++bin) {
        entries_in_range += h->GetBinContent(bin);  // Sum the bin contents
    }

    double totalEntries = h->Integral();
    double upperPercentage = (entries_in_range / totalEntries) * 100;

    // Print results
    std::cout << "\n\nTotal number of events:\t" << h->GetEntries() << "\n";
    std::cout << "Total number of events (upper):\t" << entries_in_range << "\n";
    std::cout << "Total number of events (lower):\t" << h->GetEntries() - entries_in_range << "\n";
    std::cout << "Upper percentage:\t" << upperPercentage << "%\n\n";

    // Save images
    c->SaveAs("01_reg.png");
    c->Clear();

    hUpperClone->Draw();
    c->SaveAs("02_hUpper.png");
    c->Clear();

    hLowerClone->Draw();
    c->SaveAs("03_hLower.png");
    c->Clear();

    // Clean up
    file->Close();
    delete file;
    delete c;
}