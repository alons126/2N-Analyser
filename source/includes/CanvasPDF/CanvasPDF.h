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
        CanvasPDFind = CanvasPDFind + 1;
    }
}

void CopyPadContent(TPad* sourcePad, TPad* targetPad) {
    if (!sourcePad || !targetPad) {
        std::cerr << "Error: One of the pads is null." << std::endl;
        return;
    }

    // Get the list of primitives (objects) in the source pad
    TList* primList = sourcePad->GetListOfPrimitives();
    if (!primList) {
        std::cerr << "Error: No primitives found in the source pad." << std::endl;
        return;
    }

    // Loop over all the primitives in the source pad and draw them in the target pad
    TIter next(primList);
    TObject* obj;
    while ((obj = next())) {
        if (!obj) {
            std::cerr << "Error: Null object encountered in the primitive list." << std::endl;
            continue;  // Skip null objects
        }

        targetPad->cd();
        if (obj->InheritsFrom("TAttDrawable")) {  // Ensure the object is drawable
            obj->DrawClone();  // Draw a clone of each primitive in the target pad
        } else {
            std::cerr << "Warning: Object is not drawable. Skipping." << std::endl;
        }
    }

    targetPad->Update();
}