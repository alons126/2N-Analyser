//
// Created by Alon Sportes on 06/09/2024.
//

#ifndef CLAS12ANALYSIS_H
#define CLAS12ANALYSIS_H

#include "../CLAS1212Debugger/CLAS1212Debugger.cpp"
#include "../clas12Ana/clas12ana.cpp"

/* This is my edit of the RG-M analysis code */

// TODO: change vertex cuts loading to be from .txt file.

class CLAS12Analysis : public clas12ana {
   private:
    // My Vz and dVz cuts
    // ----------------------------------------------------------------------------------------------------------------------------------------------------

    CLAS1212Debugger Debug_c;  // debug class for plotting general plots
    // My Vz and dVz cuts
    // ----------------------------------------------------------------------------------------------------------------------------------------------------

    vector<double> vertex_x_cuts_FD = {-99, 99};
    vector<double> vertex_x_cuts_CD = {-99, 99};

    vector<double> vertex_y_cuts_FD = {-99, 99};
    vector<double> vertex_y_cuts_CD = {-99, 99};

    vector<double> vertex_z_cuts_FD = {-99, 99};
    vector<double> vertex_z_cuts_CD = {-99, 99};

    vector<double> vertex_corr_cuts_FD = {
        -99,
        99};  // electron vertex <-> particle vertex correlation cuts (FD only)
    vector<double> vertex_corr_cuts_CD = {
        -99,
        99};  // electron vertex <-> particle vertex correlation cuts (CD only)

    // My all particles vector
    // -----------------------------------------------------------------------------------------------------------------------------------------------

    std::vector<region_part_ptr> allparticles;

    // My attributs
    // ----------------------------------------------------------------------------------------------------------------------------------------------------------

    bool f_NpheCuts = false;
    bool f_old_ecalSFCut = false;      // Old constant cuts from MSc analysis
    bool f_old_VertexCuts = true;      // Old vetex cuts from MSc analysis
    bool f_old_VertexCorrCuts = true;  // Old vetex cuts from MSc analysis

    double htcc_Nphe_cut = 2;
    double Neutron_Momentum_cut = 9999.;
    double FD_Neutral_Beta_cut = 9999.;
    double FD_Neutral_Beta_Mean = 1.;
    double dPhi_p1_p2_Mean = 9999.;

    // TODO: ME: in the old clas12ana version, SF cuts where:
    double SF_max_cut = .28;
    double SF_min_cut = .2;

    double dc_edge_cut = 10;  // My addition (from Larry)

    // My private functions
    // --------------------------------------------------------------------------------------------------------------------------------------------------

    void ClearParticles() {
        allparticles.clear();
        Clear();  // This is the clas12ana function
    }

   public:
    CLAS12Analysis() { Init(); };

    CLAS12Analysis(bool debug) : debug_plots{debug} { Init(); };

    ~CLAS12Analysis() {
        if (debug_plots) {
            debug_c.WriteDebugPlots(debug_out_file);
            Debug_c.WriteMyDebugPlots(debug_out_file);
        }
    }
};

// My public functions
// ---------------------------------------------------------------------------------------------------------------------------------------------------

void setVzcutsFD(double min, double max) {
    vertex_z_cuts_FD.at(0) = min;
    vertex_z_cuts_FD.at(1) = max;
}

void setVzcutsCD(double min, double max) {
    vertex_z_cuts_CD.at(0) = min;
    vertex_z_cuts_CD.at(1) = max;
}

void setVertexCorrCutsLimFD(double min, double max) {
    vertex_corr_cuts_FD.at(0) = min;
    vertex_corr_cuts_FD.at(1) = max;
}

void setVertexCorrCutsLimCD(double min, double max) {
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

double getdPhiCutMean() {
    if (dPhi_p1_p2_Mean == 9999.) {
        return 0;
    } else {
        return dPhi_p1_p2_Mean;
    }
};

std::vector<region_part_ptr> getParticles() { return allparticles; }

// addToAllParticles function ---------------------------------------------

void addToAllParticles(region_part_ptr p) { allparticles.push_back(p); }

// GetPidCutSigma function ------------------------------------------------

double GetPidCutSigma(int Pid, string region) {
    // TODO: My addition?
    if (region == "CD") {
        auto itter_CD = pid_cuts_cd.find(Pid);

        return itter_CD->second.at(1);
    } else if (region == "FD") {
        auto itter_FD = pid_cuts_fd.find(Pid);

        return itter_FD->second.at(1);
    } else {
        // TODO: figure out what to do in this case
        return -9999;
    }
}

// GetPidCutMean function -------------------------------------------------

double GetPidCutMean(int Pid, string region) {
    // TODO: My addition?
    if (region == "CD") {
        auto itter_CD = pid_cuts_cd.find(Pid);

        return itter_CD->second.at(0);
    } else if (region == "FD") {
        auto itter_FD = pid_cuts_fd.find(Pid);

        return itter_FD->second.at(0);
    } else {
        // TODO: figure out what to do in this case
        return -9999;
    }
}

// ReadInputParam function ------------------------------------------------

/*
This is my edit based on the clas12ana function:
    void readInputParam(const char *filename);

It comes as a custemized version of readInputParam, that reads my
CLAS12Analysis additions from file
*/
void ReadInputParam(const char *filename);

// HTCCNpheCuts function --------------------------------------------------

/*
This function is my addition. It comes to add the ability to cusomize and
disable the cut on the number of photo-electrons in the HTCC.
*/
bool HTCCNpheCuts(region_part_ptr p);

// CheckEcalSFCuts function -----------------------------------------------

/*
This is my edit based on the clas12ana function:
    void checkEcalSFCuts(const region_part_ptr &p);

It allows the user to choose between the constant SF cuts
{SF_max_cut,SF_min_cut}, and the new SF cuts from clas12ana
*/
void CheckEcalSFCuts(const region_part_ptr &p);

// CheckVertex function ---------------------------------------------------

/*
This is my edit based on the clas12ana function:
    void checkVertex(const region_part_ptr &p)

It allows the user to choose between the old implementation of vertex cuts
from the MSc analysis and the implementation from clas12ana
*/
void CheckVertex(const region_part_ptr &p);

// CheckVertexCorrelation function ----------------------------------------

/*
This is my edit based on the clas12ana function:
    bool checkVertexCorrelation(const region_part_ptr &el,
                                const region_part_ptr &p);

It allows the user to choose between the old implementation of vertex
correlation cuts from the MSc analysis and the implementation from clas12ana
*/
bool CheckVertexCorrelation(const region_part_ptr &el,
                            const region_part_ptr &p);

// RunAnalysisCuts function -----------------------------------------------

/*
This is my edit based on the clas12ana function:
    void Run(const std::unique_ptr<clas12::clas12reader> &c12);
*/
void RunAnalysisCuts(const std::unique_ptr<clas12::clas12reader> &c12);
}
;

#endif  // CLAS12ANALYSIS_H
