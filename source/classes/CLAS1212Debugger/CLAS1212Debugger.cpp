#include "CLAS1212Debugger.h"

// WriteMyDebugPlots function ---------------------------------------------

/*
This is my addition based on the clas12debug function:
    void WriteDebugPlots(TString file);

It comes to add my debugging plots to the clas12ana debugging plots
*/
void CLAS1212Debugger::WriteMyDebugPlots(TString file) {
    TFile f_debugOut(file, "UPDATE");

    // Multiplicity plots before and after cuts (no #e cuts):
    multi_p_vs_cpi_BC_debug->Write();
    multi_p_vs_cpi_AC_debug->Write();
    multi_p_BC_debug->Write();
    multi_p_AC_debug->Write();
    multi_cpi_BC_debug->Write();
    multi_cpi_AC_debug->Write();

    // Multiplicity plots before and after cuts (1e cut):
    multi_p_vs_cpi_1e_cut_BC_debug->Write();
    multi_p_vs_cpi_1e_cut_AC_debug->Write();
    multi_p_1e_cut_BC_debug->Write();
    multi_p_1e_cut_AC_debug->Write();
    multi_cpi_1e_cut_BC_debug->Write();
    multi_cpi_1e_cut_AC_debug->Write();

    f_debugOut.Close();
}