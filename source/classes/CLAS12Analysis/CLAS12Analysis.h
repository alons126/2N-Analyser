//
// Created by Alon Sportes on 06/09/2024.
//

#ifndef CLAS12ANALYSIS_H
#define CLAS12ANALYSIS_H

#include "../clas12Ana/clas12ana.cpp"

/* This is my edit of the RG-M analysis code */

// TODO: change vertex cuts loading to be from .txt file.

class CLAS12Analysis : public clas12ana
{
private:
    // My Vz and dVz cuts ----------------------------------------------------------------------------------------------------------------------------------------------------

    vector<double> vertex_x_cuts_FD = {-99, 99};
    vector<double> vertex_x_cuts_CD = {-99, 99};

    vector<double> vertex_y_cuts_FD = {-99, 99};
    vector<double> vertex_y_cuts_CD = {-99, 99};

    vector<double> vertex_z_cuts_FD = {-99, 99};
    vector<double> vertex_z_cuts_CD = {-99, 99};

    vector<double> vertex_corr_cuts_FD = {-99, 99}; // electron vertex <-> particle vertex correlation cuts (FD only)
    vector<double> vertex_corr_cuts_CD = {-99, 99}; // electron vertex <-> particle vertex correlation cuts (CD only)

    // My all particles vector -----------------------------------------------------------------------------------------------------------------------------------------------

    std::vector<region_part_ptr> allparticles;

    // My attributs ----------------------------------------------------------------------------------------------------------------------------------------------------------

    bool f_NpheCuts = false;

    double htcc_Nphe_cut = 2;
    double Neutron_Momentum_cut = 9999.;
    double FD_Neutral_Beta_cut = 9999.;
    double FD_Neutral_Beta_Mean = 1.;
    double dPhi_p1_p2_Mean = 9999.;

    // TODO: ME: in the old clas12ana version, SF cuts where:
    double SF_max_cut = .28;
    double SF_min_cut = .2;

    double dc_edge_cut = 10; // My addition (from Larry)

    // My debugging plots ----------------------------------------------------------------------------------------------------------------------------------------------------

    TH2D* multi_p_vs_cpi_BC_debug = new TH2D("multi_p_vs_cpi_BC_debug",
                                             "#font[12]{#p} vs. #font[12]{##pi^{#pm}} BC (no #e cuts, CD & FD);#font[12]{#p};#font[12]{##pi^{#pm}}",
                                             10, 0, 10, 10, 0, 10);
    TH1D* multi_p_BC_debug = new TH1D("multi_p_BC_debug", "#font[12]{#p} BC (no #e cuts, CD & FD);#font[12]{#p}", 10, 0, 10);
    TH1D* multi_cpi_BC_debug = new TH1D("multi_cpi_BC_debug", "#font[12]{##pi^{#pm}} BC (no #e cuts, CD & FD);#font[12]{##pi^{#pm}}", 10, 0, 10);

    TH2D* multi_p_vs_cpi_AC_debug = new TH2D("multi_p_vs_cpi_AC_debug",
                                             "#font[12]{#p} vs. #font[12]{##pi^{#pm}} AC (no #e cuts, CD & FD);#font[12]{#p};#font[12]{##pi^{#pm}}",
                                             10, 0, 10, 10, 0, 10);
    TH1D* multi_p_AC_debug = new TH1D("multi_p_AC_debug", "#font[12]{#p} AC (no #e cuts, CD & FD);#font[12]{#p}", 10, 0, 10);
    TH1D* multi_cpi_AC_debug = new TH1D("multi_cpi_AC_debug", "#font[12]{##pi^{#pm}} AC (no #e cuts, CD & FD);#font[12]{##pi^{#pm}}", 10, 0, 10);

    TH2D* multi_p_vs_cpi_1e_cut_BC_debug = new TH2D("multi_p_vs_cpi_1e_cut_BC_debug",
                                                    "#font[12]{#p} vs. #font[12]{##pi^{#pm}} BC (1e cut, CD & FD);#font[12]{#p};#font[12]{##pi^{#pm}}",
                                                    10, 0, 10, 10, 0, 10);
    TH1D* multi_p_1e_cut_BC_debug = new TH1D("multi_p_1e_cut_BC_debug", "#font[12]{#p} BC (1e cut, CD & FD);#font[12]{#p}", 10, 0, 10);
    TH1D* multi_cpi_1e_cut_BC_debug = new TH1D("multi_cpi_1e_cut_BC_debug", "#font[12]{##pi^{#pm}} BC (1e cut, CD & FD);#font[12]{##pi^{#pm}}", 10, 0, 10);

    TH2D* multi_p_vs_cpi_1e_cut_AC_debug = new TH2D("multi_p_vs_cpi_1e_cut_AC_debug",
                                                    "#font[12]{#p} vs. #font[12]{##pi^{#pm}} AC (1e cut, CD & FD);#font[12]{#p};#font[12]{##pi^{#pm}}",
                                                    10, 0, 10, 10, 0, 10);
    TH1D* multi_p_1e_cut_AC_debug = new TH1D("multi_p_1e_cut_AC_debug", "#font[12]{#p} AC (1e cut, CD & FD);#font[12]{#p}", 10, 0, 10);
    TH1D* multi_cpi_1e_cut_AC_debug = new TH1D("multi_cpi_1e_cut_AC_debug", "#font[12]{##pi^{#pm}} AC (1e cut, CD & FD);#font[12]{##pi^{#pm}}", 10, 0, 10);

    // My private functions --------------------------------------------------------------------------------------------------------------------------------------------------

    void MyClear()
    {
        allparticles.clear();
        Clear();
    }

public:
    // My public functions ---------------------------------------------------------------------------------------------------------------------------------------------------

    void setVzcutsFD(double min, double max)
    {
        vertex_z_cuts_FD.at(0) = min;
        vertex_z_cuts_FD.at(1) = max;
    }

    void setVzcutsCD(double min, double max)
    {
        vertex_z_cuts_CD.at(0) = min;
        vertex_z_cuts_CD.at(1) = max;
    }

    void setVertexCorrCutsLimFD(double min, double max)
    {
        vertex_corr_cuts_FD.at(0) = min;
        vertex_corr_cuts_FD.at(1) = max;
    }

    void setVertexCorrCutsLimCD(double min, double max)
    {
        vertex_corr_cuts_CD.at(0) = min;
        vertex_corr_cuts_CD.at(1) = max;
    }

    double getEcalSFUpperCut() { return SF_max_cut; }

    double getEcalSFLowerCut() { return SF_min_cut; }

    double getDCEdgeCuts() { return dc_edge_cut; }

    double getEcalEdgeCuts() { return ecal_edge_cut; }

    void setNpheCuts(bool flag = true) { f_NpheCuts = flag; }

    double getNpheCuts() { return htcc_Nphe_cut; }

    double getNeutronMomentumCut() { return Neutron_Momentum_cut; }

    double getNeutralBetaCut() { return FD_Neutral_Beta_cut; }

    double getNeutralBetaCutMean() { return FD_Neutral_Beta_Mean; }

    double getdPhiCutMean()
    {
        if (dPhi_p1_p2_Mean == 9999.)
        {
            return 0;
        }
        else
        {
            return dPhi_p1_p2_Mean;
        }
    };

    std::vector<region_part_ptr> getParticles() { return allparticles; }

    void addToAllParticles(region_part_ptr p) { allparticles.push_back(p); }

    bool HTCCNpheCuts(region_part_ptr p);

    double GetPidCutSigma(int Pid, string region)
    {
        // TODO: My addition?
        if (region == "CD")
        {
            auto itter_CD = pid_cuts_cd.find(Pid);

            return itter_CD->second.at(1);
        }
        else if (region == "FD")
        {
            auto itter_FD = pid_cuts_fd.find(Pid);

            return itter_FD->second.at(1);
        }
        else
        {
            //TODO: figure out what to do in this case
            return -9999;
        }
    }

    double GetPidCutMean(int Pid, string region)
    {
        // TODO: My addition?
        if (region == "CD")
        {
            auto itter_CD = pid_cuts_cd.find(Pid);

            return itter_CD->second.at(0);
        }
        else if (region == "FD")
        {
            auto itter_FD = pid_cuts_fd.find(Pid);

            return itter_FD->second.at(0);
        }
        else
        {
            //TODO: figure out what to do in this case
            return -9999;
        }
    }
};

#endif //CLAS12ANALYSIS_H
