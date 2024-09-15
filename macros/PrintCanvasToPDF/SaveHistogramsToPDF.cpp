#define PBSTR "||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||"
#define PBWIDTH 60

#include <cstdlib>
#include <iostream>
#include <chrono>
#include <vector>
#include <typeinfo>

#include <TFile.h>
#include <TTree.h>
#include <TLorentzVector.h>
#include <TH1.h>
#include <TH2.h>
#include <TLatex.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TStyle.h>

using namespace std;

/* SaveHistogramsToPDF - my edit */
void SaveHistogramsToPDF() {
    const char* pdfFileName = "somefile.pdf";
    
    // Create a canvas
    TCanvas* canvas = new TCanvas("canvas", "Canvas for saving histograms", 800, 600);

    // Start the multi-page PDF
    canvas->Print(Form("%s[", pdfFileName)); // Open the PDF file

    // Select the canvas (just in case)
    canvas->cd();

    TLatex text;
    text.SetTextSize(0.05);
    text.DrawLatex(0.2,0.9,"(e,e') Candidates:");
    text.DrawLatex(0.2,0.8,"No Cuts");

    // Force canvas to recognize modifications
    canvas->Modified();
    canvas->Update();

    // Save the current canvas content to the PDF
    canvas->Print(pdfFileName);
    
    // End the multi-page PDF
    canvas->Print(Form("%s]", pdfFileName)); // Close the PDF file

    delete canvas;
}

/* SaveHistogramsToPDF - original ChatGPT function */
void SaveHistogramsToPDF(std::vector<TH1*> histList, const char* pdfFileName) {
   // Create a canvas
   TCanvas* canvas = new TCanvas("canvas", "Canvas for saving histograms", 800, 600);

   // Start the multi-page PDF
   canvas->Print(Form("%s[", pdfFileName)); // Open the PDF file

   // Loop through the list of histograms
   for (TH1* hist : histList) {
       canvas->cd();      // Select the canvas
       hist->Draw();      // Draw the histogram on the canvas
       canvas->Print(pdfFileName); // Save the current canvas (histogram) to the PDF
   }

   // End the multi-page PDF
   canvas->Print(Form("%s]", pdfFileName)); // Close the PDF file

   delete canvas;
}
