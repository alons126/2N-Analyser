#include <iostream>
#include <vector>
#include <TF1.h>
#include <math.h>
#include <map>

#include <cstdlib>
#include <iomanip>
#include <chrono>
#include <typeinfo>
#include <sstream>

#include <TFile.h>
#include <TTree.h>
#include <TLorentzVector.h>
#include <TH1.h>
#include <TH2.h>
#include <TLatex.h>
#include <TChain.h>
#include <TCanvas.h>
#include <TStyle.h>
#include <TDatabasePDG.h>
#include <TApplication.h>
#include <TROOT.h>

void plotter()
{
    TCanvas *c1 = new TCanvas("c1");
    c1->cd(1);
    TH1F *h1 = new TH1F("h1","test", 30, -3, 3);
    h1->FillRandom("gaus", 2000);
    h1->Draw("e1p");

    TCanvas *c2 = new TCanvas("c2");
    c2->Divide(2, 2);
    c2->cd(2);
    c1->DrawClonePad();
    c2->cd(3);
    // h1copy->SetFillColor(kRed);
    c1->DrawClonePad();

    //     TCanvas *c1 = new TCanvas("c1");
    // c1->Divide(2, 2);
    // c1->cd(1);
    // TH1F *h1 = new TH1F("h1","test", 30, -3, 3);
    // h1->FillRandom("gaus", 2000);
    // // TH1F *h1copy = h1->DrawCopy();
    // c1->cd(2);
    // h1->DrawCopy("lego2");
    // c1->cd(3);
    // h1->Fit("gaus");
    // h1->DrawCopy();
    // c1->cd(4);
    // h1->Draw("e1p");

    // TCanvas *c2 = new TCanvas("c2");
    // c2->Divide(2, 2);
    // c2->cd(2);
    // c1->DrawClonePad();
    // c2->cd(3);
    // // h1copy->SetFillColor(kRed);
    // c1->DrawClonePad();
}
