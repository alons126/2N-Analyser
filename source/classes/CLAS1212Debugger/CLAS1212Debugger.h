#include "../clas12ana/clas12debug.cpp"

class CLAS1212Debugger : public clas12debug {
   private:
    // My debugging plots -----------------------------------------------------

    TH2D *multi_p_vs_cpi_BC_debug =
        new TH2D("multi_p_vs_cpi_BC_debug",
                 "#font[12]{#p} vs. #font[12]{##pi^{#pm}} BC (no #e cuts, CD & "
                 "FD);#font[12]{#p};#font[12]{##pi^{#pm}}",
                 10, 0, 10, 10, 0, 10);
    TH1D *multi_p_BC_debug = new TH1D(
        "multi_p_BC_debug",
        "#font[12]{#p} BC (no #e cuts, CD & FD);#font[12]{#p}", 10, 0, 10);
    TH1D *multi_cpi_BC_debug = new TH1D(
        "multi_cpi_BC_debug",
        "#font[12]{##pi^{#pm}} BC (no #e cuts, CD & FD);#font[12]{##pi^{#pm}}",
        10, 0, 10);

    TH2D *multi_p_vs_cpi_AC_debug =
        new TH2D("multi_p_vs_cpi_AC_debug",
                 "#font[12]{#p} vs. #font[12]{##pi^{#pm}} AC (no #e cuts, CD & "
                 "FD);#font[12]{#p};#font[12]{##pi^{#pm}}",
                 10, 0, 10, 10, 0, 10);
    TH1D *multi_p_AC_debug = new TH1D(
        "multi_p_AC_debug",
        "#font[12]{#p} AC (no #e cuts, CD & FD);#font[12]{#p}", 10, 0, 10);
    TH1D *multi_cpi_AC_debug = new TH1D(
        "multi_cpi_AC_debug",
        "#font[12]{##pi^{#pm}} AC (no #e cuts, CD & FD);#font[12]{##pi^{#pm}}",
        10, 0, 10);

    TH2D *multi_p_vs_cpi_1e_cut_BC_debug =
        new TH2D("multi_p_vs_cpi_1e_cut_BC_debug",
                 "#font[12]{#p} vs. #font[12]{##pi^{#pm}} BC (1e cut, CD & "
                 "FD);#font[12]{#p};#font[12]{##pi^{#pm}}",
                 10, 0, 10, 10, 0, 10);
    TH1D *multi_p_1e_cut_BC_debug =
        new TH1D("multi_p_1e_cut_BC_debug",
                 "#font[12]{#p} BC (1e cut, CD & FD);#font[12]{#p}", 10, 0, 10);
    TH1D *multi_cpi_1e_cut_BC_debug = new TH1D(
        "multi_cpi_1e_cut_BC_debug",
        "#font[12]{##pi^{#pm}} BC (1e cut, CD & FD);#font[12]{##pi^{#pm}}", 10,
        0, 10);

    TH2D *multi_p_vs_cpi_1e_cut_AC_debug =
        new TH2D("multi_p_vs_cpi_1e_cut_AC_debug",
                 "#font[12]{#p} vs. #font[12]{##pi^{#pm}} AC (1e cut, CD & "
                 "FD);#font[12]{#p};#font[12]{##pi^{#pm}}",
                 10, 0, 10, 10, 0, 10);
    TH1D *multi_p_1e_cut_AC_debug =
        new TH1D("multi_p_1e_cut_AC_debug",
                 "#font[12]{#p} AC (1e cut, CD & FD);#font[12]{#p}", 10, 0, 10);
    TH1D *multi_cpi_1e_cut_AC_debug = new TH1D(
        "multi_cpi_1e_cut_AC_debug",
        "#font[12]{##pi^{#pm}} AC (1e cut, CD & FD);#font[12]{##pi^{#pm}}", 10,
        0, 10);

   public:
    // WriteMyDebugPlots function ---------------------------------------------

    /*
    This is my addition based on the clas12debug function:
        void WriteDebugPlots(TString file);

    It comes to add my debugging plots to the clas12ana debugging plots
    */
    void WriteMyDebugPlots(TString file);
};