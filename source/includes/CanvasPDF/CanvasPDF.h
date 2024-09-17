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

// ======================================================================================================================================================================
// PDF file canvas
// ======================================================================================================================================================================

// Canvas variables -----------------------------------------------------------------------------------------------------------------------------------------------------

int num_of_hist_per_row = 4;
int num_of_hist_per_col = 3;

int CanvasPDF_ind = 1;

TCanvas *CanvasPDF = new TCanvas("CanvasPDF", "CanvasPDF", 1000 * num_of_hist_per_row, 750 * num_of_hist_per_col); // normal res

// Canvas functions -----------------------------------------------------------------------------------------------------------------------------------------------------

void ConfigCanvasPDF()
{
    for (int i = 1; i < num_of_hist_per_row * num_of_hist_per_col + 1; i++)
    {
        CanvasPDF->cd(i)->SetGrid();
        CanvasPDF->cd(i)->SetBottomMargin(0.14);
        CanvasPDF->cd(i)->SetLeftMargin(0.16);
        CanvasPDF->cd(i)->SetRightMargin(0.12);
    }
}

void SetCanvasPDFind(int &CanvasPDFind)
{
    if (CanvasPDFind <= 0)
    {
        CanvasPDFind = 1;
    }
    else if (CanvasPDFind > num_of_hist_per_row * num_of_hist_per_col)
    {
        CanvasPDFind = CanvasPDFind - num_of_hist_per_row * num_of_hist_per_col;
    } else {
        CanvasPDFind = CanvasPDFind;
    }
}