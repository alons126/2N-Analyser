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

const double c = 29.9792458;

void printProgress(double percentage);

void Usage()
{
  std::cerr << "Usage: ./code <MC =1,Data = 0> <Ebeam(GeV)> <path/to/ouput.root> <path/to/ouput.pdf> <path/to/cutfile.txt> <path/to/input.hipo> \n";
}


void monitor_ep()
{
    char *args[] = {"somefile.pdf"};
    char **my_argv = args;
//    string file = "somefile.pdf";
    char * pdfFile = my_argv[0];

    TCanvas * myText = new TCanvas("myText","myText",1000,1000);
    TLatex text;
    text.SetTextSize(0.05);

    char fileName[100];
    sprintf(fileName,"%s[",pdfFile);
    myText->SaveAs(fileName);
    sprintf(fileName,"%s",pdfFile);
    
    myText->cd();
    text.DrawLatex(0.2,0.9,"(e,e') Candidates:");
    text.DrawLatex(0.2,0.8,"No Cuts");
    myText->Print(fileName,"pdf");
    myText->Clear();
    
    sprintf(fileName,"%s]",pdfFile);

}


void printProgress(double percentage) {
  int val = (int) (percentage * 100);
  int lpad = (int) (percentage * PBWIDTH);
  int rpad = PBWIDTH - lpad;
  printf("\r%3d%% [%.*s%*s]", val, lpad, PBSTR, rpad, "");
  fflush(stdout);
}

