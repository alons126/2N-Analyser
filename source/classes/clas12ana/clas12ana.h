#ifndef CLAS12ANA_HH
#define CLAS12ANA_HH

#include <TF1.h>
#include <math.h>

#include <iostream>
#include <map>
#include <sstream>
#include <vector>

#include "TCanvas.h"
#include "TFile.h"
#include "TH1D.h"
#include "TH2D.h"
#include "TLorentzVector.h"
#include "TVector3.h"
#include "clas12debug.cpp" // My edit
#include "clas12reader.h"
#include "region_particle.h"

#define CLAS12ANA_DIR _CLAS12ANA_DIR

using namespace std;
using namespace clas12;

// #############Íß
// Analysis suite for CLAS12 analysis
// #############

class clas12ana : public clas12reader
{
public:
    clas12ana() { Init(); };

    clas12ana(bool debug) : debug_plots{debug} { Init(); };

    ~clas12ana()
    {
        if (debug_plots)
            debug_c.WriteDebugPlots(debug_out_file);
    };

    void Init();
    void WriteSFEcalCuts();
    void InitSFEcalCuts();
    void InitSFPCuts();
    void readInputParam(const char *inFile);
    void readInputSRCParam(const char *inFile);
    void readEcalPPar(const char *filename);
    void readEcalSFPar(const char *filename);
    void printParams();

    //   void InitDebugPlots();
    void Clear();
    void clearInputParam();
    void Run(const std::unique_ptr<clas12::clas12reader> &c12);

    double getSF(const region_part_ptr &p);

    void setEcalPCuts(bool flag = true)
    {
        f_ecalPCuts = flag;
    }; // option to have several cuts
    void setEcalSFCuts(bool flag = true)
    {
        f_ecalSFCuts = flag;
    }; // option to have several cuts
    void setEcalDiagCuts(bool flag = true)
    {
        f_ecalDiagCuts = flag;
    }; // option to have several cuts
    void setDCEdgeCuts(bool flag = true) { f_DCEdgeCuts = flag; };
    void setCDEdgeCuts(bool flag = true) { f_CDEdgeCuts = flag; };
    void setCDRegionCuts(bool flag = true) { f_CDRegionCuts = flag; };
    void setEcalEdgeCuts(bool flag = true) { f_ecalEdgeCuts = flag; };
    void setPidCuts(bool flag = true) { f_pidCuts = flag; };
    void setProtonPidCuts(bool flag = true) { f_protonpidCuts = flag; };
    void setGhostTrackCuts(bool flag = true) { f_ghostTrackCuts = flag; };
    void setVertexCuts(bool flag = true) { f_vertexCuts = flag; };
    void setVertexCorrCuts(bool flag = true) { f_corr_vertexCuts = flag; };

    void setDebugPlots(bool flag = true) { debug_plots = flag; };
    void setDebugFile(TString file) { debug_out_file = file; };

    void checkCutParametersCut();

    int getCDRegion(const region_part_ptr &p);

    TVector3 getCOM(TLorentzVector l, TLorentzVector r, TLorentzVector q);

    std::vector<region_part_ptr> getByPid(int pid)
    {
        if (pid == 11)
            return electrons;
        else if (pid == 2212)
            return protons;
        else if (pid == 2112)
            return neutrons;
        else if (pid == 45)
            return deuterons;
        else if (pid == 211)
            return piplus;
        else if (pid == -211)
            return piminus;
        else if (pid == 321)
            return kplus;
        else if (pid == -321)
            return kminus;
        else if (pid == 0)
            return neutrals;
        else
            return otherpart;
    }

    void setByPid(const region_part_ptr &p)
    {
        int pid = p->par()->getPid();

        if (checkProtonPidCut(p) && f_protonpidCuts)
            pid = 2212;

        if (!checkProtonPidCut(p) && f_protonpidCuts && f_pidCuts &&
            p->getRegion() == clas12::CD && pid == 2212)
            pid = 9999;

        if (pid == 11)
            electrons.push_back(p);
        else if (pid == 2212)
        {
            // is a proton if not a ghost track and check for PID by TOF vs
            // momentum assignment
            if (!(checkGhostTrackCD(p) && f_ghostTrackCuts))
                protons.push_back(p);
        }
        else if (pid == 2112)
            neutrons.push_back(p);
        else if (pid == 45)
            deuterons.push_back(p);
        else if (pid == 211)
            piplus.push_back(p);
        else if (pid == -211)
            piminus.push_back(p);
        else if (pid == 321)
            kplus.push_back(p);
        else if (pid == -321)
            kminus.push_back(p);
        else if (pid == 0)
            neutrals.push_back(p);
        else
            otherpart.push_back(p);
    }

    double getEventMult() { return event_mult; };
    bool EcalEdgeCuts(const region_part_ptr &p);
    bool checkEcalPCuts(const region_part_ptr &p);
    bool checkEcalSFCuts(const region_part_ptr &p);
    bool checkEcalDiagCuts(const region_part_ptr &p);
    bool checkPidCut(const region_part_ptr &p);
    bool checkProtonPidCut(const region_part_ptr &p);
    bool checkVertex(const region_part_ptr &p);
    bool DCEdgeCuts(const region_part_ptr &p);
    bool CDEdgeCuts(const region_part_ptr &p);

    bool checkGhostTrackCD(const region_part_ptr &p);

    bool checkVertexCorrelation(const region_part_ptr &el,
                                const region_part_ptr &p);

    bool CDRegionCuts(const region_part_ptr &p);

    void setVxcuts(double min, double max)
    {
        vertex_x_cuts.at(0) = min;
        vertex_x_cuts.at(1) = max;
    };
    void setVycuts(double min, double max)
    {
        vertex_y_cuts.at(0) = min;
        vertex_y_cuts.at(1) = max;
    };

    void setVertexCorrCuts_FD(double min, double max)
    {
        vertex_corr_cuts_fd.at(0) = min;
        vertex_corr_cuts_fd.at(1) = max;
    };
    void setVertexCorrCuts_CD(double min, double max)
    {
        vertex_corr_cuts_cd.at(0) = min;
        vertex_corr_cuts_cd.at(1) = max;
    };

    void checkCutParameters();

    void setCDCutRegion(int region) { region_cut = region; };

    void getLeadRecoilSRC(TLorentzVector beam, TLorentzVector target, TLorentzVector el);
    std::vector<region_part_ptr> getLeadSRC() { return lead_proton; };
    std::vector<region_part_ptr> getRecoilSRC() { return recoil_proton; };
    std::vector<region_part_ptr> getByPid(std::vector<region_part_ptr> particles, int pid);

    // clas12debug getdebug_c() { return std::move(debug_c); } // My addition
    map<string, vector<double>> vertex_cuts;                          // map< x,y,z, {min,max}>// My addition
    vector<double> vertex_z_cuts = {-99, 99};                         // My addition
    double getEcalEdgeCuts() { return ecal_edge_cut; }                // My addition
    bool getdebug_plots() { return debug_plots; }                     // My addition
    TString getdebug_out_file() { return debug_out_file; }            // My addition
    map<int, vector<double>> getpid_cuts_cd() { return pid_cuts_cd; } // My addition
    map<int, vector<double>> getpid_cuts_fd() { return pid_cuts_fd; } // My addition

    void Insertpid_cuts_fd(int pid, vector<double> par) // My addition
    {
        pid_cuts_fd.insert(pair<int, vector<double>>(pid, par));
    }
    void Insertpid_cuts_cd(int pid, vector<double> par) // My addition
    {
        pid_cuts_cd.insert(pair<int, vector<double>>(pid, par));
    }
    void Insertvertex_cuts(string pid, vector<double> par) // My addition
    {
        vertex_cuts.insert(pair<string, vector<double>>(pid, par));
    }

    vector<double> getvertex_x_cuts() { return vertex_x_cuts; }                   // My addition
    vector<double> getvertex_y_cuts() { return vertex_y_cuts; }                   // My addition
    vector<double> getvertex_z_cuts() { return vertex_z_cuts; }                   // My addition
    int getcurrent_run() { return current_run; }                                  // My addition
    void setcurrent_run(int crun) { current_run = crun; }                         // My addition
    bool getf_ecalSFCuts() { return f_ecalSFCuts; }                               // My addition
    bool getf_ecalPCuts() { return f_ecalPCuts; }                                 // My addition
    bool getf_ecalDiagCuts() { return f_ecalDiagCuts; }                           // My addition
    bool getf_ecalEdgeCuts() { return f_ecalEdgeCuts; }                           // My addition
    bool getf_vertexCuts() { return f_vertexCuts; }                               // My addition
    bool getf_DCEdgeCuts() { return f_DCEdgeCuts; }                               // My addition
    bool getf_protonpidCuts() { return f_protonpidCuts; }                         // My addition
    bool getf_pidCuts() { return f_pidCuts; }                                     // My addition
    bool getf_CDEdgeCuts() { return f_CDEdgeCuts; }                               // My addition
    bool getf_CDRegionCuts() { return f_CDRegionCuts; }                           // My addition
    bool getf_corr_vertexCuts() { return f_corr_vertexCuts; }                     // My addition
    bool getf_ghostTrackCuts() { return f_ghostTrackCuts; }                     // My addition
    std::vector<region_part_ptr> getelectrons() { return electrons; }             // My addition
    std::vector<region_part_ptr> getprotons() { return protons; }                 // My addition
    std::vector<region_part_ptr> getdeuterons() { return deuterons; }             // My addition
    std::vector<region_part_ptr> getneutrals() { return neutrals; }               // My addition
    std::vector<region_part_ptr> getneutrons() { return neutrons; }               // My addition
    std::vector<region_part_ptr> getpiplus() { return piplus; }                   // My addition
    std::vector<region_part_ptr> getpiminus() { return piminus; }                 // My addition
    std::vector<region_part_ptr> getkplus() { return kplus; }                     // My addition
    std::vector<region_part_ptr> getkminus() { return kminus; }                   // My addition
    std::vector<region_part_ptr> getotherpart() { return otherpart; }             // My addition
    void increaseevent_mult() { ++event_mult; }                                   // My addition
    void setdebug_fileName(TString db_fileName) { debug_out_file = db_fileName; } // My addition
    TString getdebug_fileName() { return debug_out_file; }                        // My addition

    clas12debug debug_c; // debug class for plotting general plots (my edit - moved to public!)

    // My edit - these particles vectors were moved to public!
    std::vector<region_part_ptr> electrons;
    std::vector<region_part_ptr> protons;
    std::vector<region_part_ptr> deuterons;
    std::vector<region_part_ptr> neutrals;
    std::vector<region_part_ptr> neutrons;
    std::vector<region_part_ptr> piplus;
    std::vector<region_part_ptr> piminus;
    std::vector<region_part_ptr> kplus;
    std::vector<region_part_ptr> kminus;
    std::vector<region_part_ptr> otherpart;

private:
    TString debug_out_file = "debugPlots.root";

    // SRC
    std::vector<region_part_ptr> lead_proton;
    std::vector<region_part_ptr> recoil_proton;

    // prototype function for fitting ECAL electron cuts
    TF1 *ecal_p_fcn[2][7];  // 0 upper 1 lower fiducial
    TF1 *ecal_sf_fcn[2][7]; // 0 upper 1 lower fiducial

    TF1 *ecal_p_mean_fcn[7];  // mean function for plotting
    TF1 *ecal_sf_mean_fcn[7]; // mean function for plotting

    // proton pid TOF vs momentum
    TF1 *proton_pid_mean =
        new TF1("proton_pid_mean",
                "[0]*(1 + ([1]/(x-[3])) + ([2]/pow(x-[3],2)))", 0, 10);
    TF1 *proton_pid_sigma =
        new TF1("proton_pid_sigma",
                "[0]*(1 + ([1]/(x-[3])) + ([2]/pow(x-[3],2)))", 0, 10);

    double ecal_p_fcn_par[7][6];  // sector, parameter
    double ecal_sf_fcn_par[7][6]; // sector, parameter

    int current_run = -1;
    int previous_run = -1;
    int current_cut_run = -1;
    int sigma_cut = 3;

    bool f_ecalSFCuts = true;
    bool f_ecalPCuts = true;
    bool f_ecalDiagCuts = true;
    bool f_ecalEdgeCuts = true;
    bool f_DCEdgeCuts = true;
    bool f_CDEdgeCuts = true;
    bool f_pidCuts = true;
    bool f_vertexCuts = true;
    bool f_corr_vertexCuts = true;
    bool f_protonpidCuts =
        true;                     // PID of CD protons handled not by chi2pid (CLAS) but our own
    bool f_ghostTrackCuts = true; // ghost track cut in CD

    // optional cut
    bool f_CDRegionCuts = false;

    map<int, vector<double>>
        pid_cuts_cd; // map<pid, {min,max cut}> Central Detector (CD)
    map<int, vector<double>>
        pid_cuts_fd; // map<pid, {min,max cut}> Forward Detector (FD)

    map<int, vector<double>>
        vertex_z_cuts_cd; // map<pid, {min,max cut}> Central Detector (CD)
    map<int, vector<double>>
        vertex_z_cuts_fd; // map<pid, {min,max cut}> Forward Detector (FD)

    vector<double> vertex_x_cuts = {-99, 99};
    vector<double> vertex_y_cuts = {-99, 99};

    vector<double> vertex_corr_cuts_cd = {
        -1.8, 3.1}; // electron vertex <-> particle vertex correlation cuts
    vector<double> vertex_corr_cuts_fd = {
        -3.5, 5.8}; // electron vertex <-> particle vertex correlation cuts

    const double pi = 3.1415926535;
    const double c = 29.9792458; // speed of light ns/cm

    double pcal_energy_cut = 0.06; //(GeV) minimum energy cut
    double ecal_edge_cut = 14;     // cm
    double ecal_diag_cut = 0.2;    // diagonal cut on SF
    double cd_edge_cut = 0.5;      // distance to edge cut
    double min_mom_pt = 0.15;      // min momentum transverse in CD MeV/c

    double proton_sigma = 2;
    double ghost_track_cut =
        5; // deg; cuts the angle between CD tracks and FD tracks to remove
           // ghost tracks (track measured in both CD and FD)

    std::vector<double> dc_edge_cut_el = {
        4.5, 3.5, 7.5}; // units cm; {region1, region2, region3} cuts for
                        // electrons INBENDING
    std::vector<double> dc_edge_cut_ptr = {
        2.5, 3, 10.5}; // units cm; {region1, region2, region3} cuts for
                       // protons  OUTBENDING

    int region_cut =
        2; // region 2 of CD had strange occupancy not nessecarily bad

    // SRC Cuts
    std::vector<double> q2_cut = {1.5, 99};        // Q^2 cut
    std::vector<double> xb_cut = {1.2, 99};        // x-borken
    std::vector<double> pmiss_cut = {.25, 1.2};    // missing momentum cut
    std::vector<double> recoil_mom_cut = {.3, 1.}; // missing momentum cut
    std::vector<double> mmiss_cut = {0, 1.2};      // missing mass cut
    std::vector<double> pq_cut = {0, 0.96};        //|p|/|q| cut
    std::vector<double> theta_pq_cut = {
        0, 180}; // degrees angle between pLead & q
    std::vector<double> mom_lead_cut = {
        1., 5.}; // min momentum of lead particle GeV/c

    // constants
    double mass_proton = 0.938272; // GeV/c2
    double mass_neutron = 0.939565;
    double mass_pion = 0.13957;
    double mass_deuterium = 1.8756;

    double beam_energy = 0;
    double event_mult = 0; // charged particle multiplicity

    bool debug_plots = false;
};

#endif
