void neutron_multi_counter() {
    std::cout << std::endl;

    // Open the file containing the histogram
    TFile *file = TFile::Open("/Users/alon/Code runs/Uniform-sample-generator/Uniform_en_sample_2070MeV/02 AMaps generation (with 2N analysis code)/v5/00 AMaps tests/Uniform_en_sample_2070MeV_S03AC_NC_AMaps_ChainRunV5_R2_20s150b/Uniform_en_sample_2070MeV_plots.root");
//    TFile *file = TFile::Open("/Users/alon/Code runs/Uniform-sample-generator/Uniform_en_sample_4029MeV/02 AMaps generation (with 2N analysis code)/v5/00 AMaps tests/Uniform_en_sample_4029MeV_S03AC_NC_AMaps_ChainRunV5_R2_20s150b/Uniform_en_sample_4029MeV_plots.root");
//    TFile *file = TFile::Open("/Users/alon/Code runs/Uniform-sample-generator/Uniform_en_sample_5986MeV/02 AMaps generation (with 2N analysis code)/v5/00 AMaps tests/Uniform_en_sample_5986MeV_S03AC_NC_AMaps_ChainRunV5_R2_20s150b/Uniform_en_sample_5986MeV_plots.root");
//    TFile *file = TFile::Open("/Users/alon/Code runs/2N-Analysis/C12x4_sim_G18_Q204_6GeV_MSc/05_Final_runs/v3/C12x4_simulation_G18_Q204_6GeV_S03AC_NC_wNSaC_wFCwKC_wKW_v3_ReRun2/C12x4_simulation_G18_Q204_6GeV_plots.root");
    if (!file || file->IsZombie()) {
        std::cerr << "Error: Could not open file." << std::endl;
        return;
    }

    // Retrieve the histogram
    TH1D *h = (TH1D *)file->Get("Multiplicity of FD neutrons by redef. APID&AV (1e cut, FD)");
//    TH1D *h = (TH1D *)file->Get("Multiplicity of FD neutrons by redef. APID&AV (nFDpCD, FD)");
    if (!h) {
        std::cerr << "Error: Histogram not found." << std::endl;
        file->Close();
        return;
    }

    // Remove error bars by setting bin errors to zero
    for (int bin = 1; bin <= h->GetNbinsX(); ++bin) {
        h->SetBinError(bin, 0);  // Reset errors to zero
    }

    // Define the range for upper (2 to 10, for example)
    double x_min = 1.0;
    double x_mid = 2.0;
    double x_max = 10.0;
    int bin_min = h->FindBin(x_min);
    int bin_mid = h->FindBin(x_mid);
    int bin_max = h->FindBin(x_max);

    // Calculate the total number of entries in the histogram (using GetEntries)
    double total_entries = h->GetEntries();

    std::cout << std::endl;

    // Calculate the number of entries in the min range (between x_min and x_max)
    double entries_in_min_range = 0;
    for (int bin = bin_min; bin <= bin_max; ++bin) {
        entries_in_min_range += h->GetBinContent(bin);  // Sum the bin contents in the upper range
        std::cout << "entries_in_min_range for bin = " << bin << " in the range (" << x_min << "," << x_max << ")" << " is " << h->GetBinContent(bin) << std::endl;
    }
    
    std::cout << std::endl;

    // Calculate the number of entries in the mid range (between x_mid and x_max)
    double entries_in_mid_range = 0;
    for (int bin = bin_mid; bin <= bin_max; ++bin) {
        entries_in_mid_range += h->GetBinContent(bin);  // Sum the bin contents in the upper range
        std::cout << "entries_in_mid_range for bin = " << bin << " in the range (" << x_mid << "," << x_max << ")" << " is " << h->GetBinContent(bin) << std::endl;
    }

    std::cout << std::endl;

    // Calculate the upper percentage
    double upper_percentage = (entries_in_mid_range / entries_in_min_range) * 100;

    // Print the results
    std::cout << "Total number of entries: " << total_entries << std::endl;
    std::cout << "Number of entries in min range (" << x_min << ", " << x_max << "): " << entries_in_min_range << std::endl;
    std::cout << "Number of entries in mid range (" << x_mid << ", " << x_max << "): " << entries_in_mid_range << std::endl;
    std::cout << "Upper percentage: " << upper_percentage << "%" << std::endl;

//    // Draw the histogram without error bars
//    TCanvas *c = new TCanvas("c", "Histogram without Error Bars", 800, 600);
//    h->Draw();  // This will plot the histogram without error bars
//    c->SaveAs("histogram_without_errorbars.png");

    // Close the file
    file->Close();
    delete file;
//    delete c;
}
