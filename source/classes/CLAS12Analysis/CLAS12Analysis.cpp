//
// Created by Alon Sportes on 06/09/2024.
//

#include "CLAS12Analysis.h"

// ReadInputParam function ----------------------------------------------------

/*
This is my edit based on the clas12ana function:
    void readInputParam(const char *filename);

It comes as a custemized version of readInputParam, that reads my
CLAS12Analysis additions from file
*/
void CLAS12Analysis::ReadInputParam(const char *filename) {
    ifstream infile;
    infile.open(filename);

    if (infile.is_open()) {
        string tp;

        // remove 3 lines of header
        for (int i = 0; i < 3; i++) getline(infile, tp);

        while (
            // read data from file object and put it into string:
            getline(infile, tp)) {
            stringstream ss(tp);
            string parameter, parameter2;
            double value;
            // get cut identifier
            ss >> parameter;
            if (parameter == "pid_cuts") {
                // get cut values
                ss >> parameter2;
                stringstream ss2(parameter2);
                string pid_v;
                string detector;
                int count = 0;  // parameter number
                int pid = -99;
                vector<double> par;

                while (getline(ss2, pid_v, ':')) {
                    if (count == 0)
                        pid = stoi(pid_v);
                    else if (count < 3)
                        par.push_back(atof(pid_v.c_str()));
                    else if (count == 3)
                        detector = pid_v;

                    count++;
                }
                if (pid != -99)  // if pid cut exists in file
                {
                    if (detector == "FD")
                        pid_cuts_fd.insert(
                            pair<int, vector<double> >(pid, par));
                    else if (detector == "CD")
                        pid_cuts_cd.insert(
                            pair<int, vector<double> >(pid, par));
                }
            }  // end PID cuts section

            else if (parameter == "vertex_cut") {
                ss >> parameter2;
                stringstream ss2(parameter2);
                string pid_v;
                int count = 0;
                string pid = "";
                vector<double> par;

                while (getline(ss2, pid_v, ':')) {
                    if (count == 0)
                        pid = pid_v;
                    else
                        par.push_back(atof(pid_v.c_str()));

                    count++;
                }

                if (pid != "")
                    vertex_cuts.insert(pair<string, vector<double> >(pid, par));
            } else if (parameter == "Momentum_cuts_ECAL") {  // My addition
                ss >> parameter2;
                stringstream ss2(parameter2);
                string pid_v;
                int count = 0;
                string pid = "";
                vector<double> par;

                while (getline(ss2, pid_v, ':')) {
                    if (count == 0)
                        pid = pid_v;
                    else
                        par.push_back(atof(pid_v.c_str()));

                    count++;
                }

                if (pid != "") {
                    Neutron_Momentum_cut = par.at(1);
                }
            } else if (parameter == "Beta_cut_ECAL") {  // My addition
                ss >> parameter2;
                stringstream ss2(parameter2);
                string pid_v;
                int count = 0;
                string pid = "";
                vector<double> par;

                while (getline(ss2, pid_v, ':')) {
                    if (count == 0)
                        pid = pid_v;
                    else
                        par.push_back(atof(pid_v.c_str()));

                    count++;
                }

                if (pid != "") {
                    FD_Neutral_Beta_Mean = par.at(0);
                    FD_Neutral_Beta_cut = par.at(1);
                }
            } else if (parameter == "dPhi_pFD_pCD") {  // My addition
                ss >> parameter2;
                stringstream ss2(parameter2);
                string pid_v;
                int count = 0;
                string pid = "";
                vector<double> par;

                while (getline(ss2, pid_v, ':')) {
                    if (count == 0)
                        pid = pid_v;
                    else
                        par.push_back(atof(pid_v.c_str()));

                    count++;
                }

                if (pid != "") {
                    dPhi_p1_p2_Mean = par.at(0);
                }
            }
        }
    } else
        cout << "Parameter file didn't read in " << endl;
    return;
}

// HTCCNpheCuts function ------------------------------------------------------

/*
This function is my addition. It comes to add the ability to cusomize and
disable the cut on the number of photo-electrons in the HTCC.
*/
bool CLAS12Analysis::HTCCNpheCuts(region_part_ptr p) {
    // true if inside cut
    double Nphe = p->che(HTCC)->getNphe();

    if (p->par()->getPid() == 11) {
        if (Nphe > htcc_Nphe_cut) {
            return true;
        } else {
            return false;
        }
    } else {
        return true;
    }
}

// CheckEcalSFCuts function ---------------------------------------------------

/*
This is my edit based on the clas12ana function:
    void checkEcalSFCuts(const region_part_ptr &p);

It allows the user to choose between the constant SF cuts
{SF_max_cut,SF_min_cut}, and the new SF cuts from clas12ana
*/
void CLAS12Analysis::CheckEcalSFCuts(const region_part_ptr &p) {
    if (f_old_ecalSFCut) {
        // If user wants constant SF cuts:
        if (p->par()->getPid() == 11) {
            double sampling_frac = getSF(p);

            if (sampling_frac < SF_max_cut && sampling_frac > SF_min_cut)
                return true;
            else
                return false;
        } else
            return false;
    } else {
        checkEcalSFCuts(p);
    }
}

// CheckVertex function -------------------------------------------------------

/*
This is my edit based on the clas12ana function:
    void checkVertex(const region_part_ptr &p)

It allows the user to choose between the old implementation of vertex cuts
from the MSc analysis and the implementation from clas12ana
*/
void CLAS12Analysis::CheckVertex(const region_part_ptr &p) {
    if (f_old_VertexCuts) {
        // If user wants MSc implementation of vertex cuts:

        // true if inside cut
        if (p->getRegion() == FD) {
            return ((p->par()->getVx() > vertex_x_cuts_FD.at(0) &&
                     p->par()->getVx() < vertex_x_cuts_FD.at(1)) &&
                    (p->par()->getVy() > vertex_y_cuts_FD.at(0) &&
                     p->par()->getVy() < vertex_y_cuts_FD.at(1)) &&
                    (p->par()->getVz() > vertex_z_cuts_FD.at(0) &&
                     p->par()->getVz() < vertex_z_cuts_FD.at(1)));
        } else if (p->getRegion() == CD) {
            return ((p->par()->getVx() > vertex_x_cuts_CD.at(0) &&
                     p->par()->getVx() < vertex_x_cuts_CD.at(1)) &&
                    (p->par()->getVy() > vertex_y_cuts_CD.at(0) &&
                     p->par()->getVy() < vertex_y_cuts_CD.at(1)) &&
                    (p->par()->getVz() > vertex_z_cuts_CD.at(0) &&
                     p->par()->getVz() < vertex_z_cuts_CD.at(1)));
        } else {
            return ((p->par()->getVx() > vertex_x_cuts.at(0) &&
                     p->par()->getVx() < vertex_x_cuts.at(1)) &&
                    (p->par()->getVy() > vertex_y_cuts.at(0) &&
                     p->par()->getVy() < vertex_y_cuts.at(1)) &&
                    (p->par()->getVz() > vertex_z_cuts.at(0) &&
                     p->par()->getVz() < vertex_z_cuts.at(1)));
        }
    } else {
        checkVertex(p);
    }
}

// CheckVertexCorrelation function --------------------------------------------

/*
This is my edit based on the clas12ana function:
    bool checkVertexCorrelation(const region_part_ptr &el,
                                const region_part_ptr &p);

It allows the user to choose between the old implementation of vertex
correlation cuts from the MSc analysis and the implementation from clas12ana
*/
bool CLAS12Analysis::CheckVertexCorrelation(const region_part_ptr &el,
                                            const region_part_ptr &p) {
    if (f_old_VertexCorrCuts) {
        // If user wants MSc implementation of vertex correlation cuts:

        // true if inside cut
        if (p->getRegion() == FD) {  //  TODO:  My addition!
            return ((p->par()->getVz() - el->par()->getVz()) >
                        vertex_corr_cuts_FD.at(0) &&
                    (p->par()->getVz() - el->par()->getVz()) <
                        vertex_corr_cuts_FD.at(1));
        } else if (p->getRegion() == CD) {
            return ((p->par()->getVz() - el->par()->getVz()) >
                        vertex_corr_cuts_CD.at(0) &&
                    (p->par()->getVz() - el->par()->getVz()) <
                        vertex_corr_cuts_CD.at(1));
        } else {
            return ((p->par()->getVz() - el->par()->getVz()) >
                        vertex_corr_cuts.at(0) &&
                    (p->par()->getVz() - el->par()->getVz()) <
                        vertex_corr_cuts.at(1));
        }
    } else {
        checkVertexCorrelation(el, p);
    }
}

// RunAnalysisCuts function ---------------------------------------------------

/*
This is my edit based on the clas12ana function:
    void Run(const std::unique_ptr<clas12::clas12reader> &c12);
*/
void CLAS12Analysis::RunAnalysisCuts(
    const std::unique_ptr<clas12::clas12reader> &c12) {
    Clear();
    current_run = c12->runconfig()->getRun();
    checkCutParameters();  // check run number has the right cuts

    auto particles = c12->getDetParticles();  // particles is now a std::vector
                                              // of particles for this event
    auto electrons_det = c12->getByID(11);

    /* My edit - start */
    auto protons_det = c12->getByID(2212);
    auto piplus_det = c12->getByID(211);
    auto piminus_det = c12->getByID(-211);

    // Filling multiplicity plots before cuts (BC) - no #e cuts:
    multi_p_BC_debug->Fill(protons_det.size());
    multi_cpi_BC_debug->Fill(piplus_det.size() + piminus_det.size());
    multi_p_vs_cpi_BC_debug->Fill(protons_det.size(),
                                  piplus_det.size() + piminus_det.size());

    // Filling multiplicity plots before cuts (BC) - 1e cut
    if (electrons_det.size() == 1) {
        multi_p_1e_cut_BC_debug->Fill(protons_det.size());
        multi_cpi_1e_cut_BC_debug->Fill(piplus_det.size() + piminus_det.size());
        multi_p_vs_cpi_1e_cut_BC_debug->Fill(
            protons_det.size(), piplus_det.size() + piminus_det.size());
    }

    int nf_initial = particles.size();
    /* My edit - end */

    // DEBUG plots
    if (debug_plots) {
        for (auto el : electrons_det) debug_c.fillBeforeEl(el);
    }

    /* My edit - start */
    // Applying electron quality cuts.
    // Loop runs all electrons in the event. */
    std::for_each(electrons_det.begin(), electrons_det.end(), [this](auto el) {
        if (!(
                // Photo-electron min cut (my edit):
                (!HTCCNpheCuts(el) && f_NpheCuts) ||
                // ECAL SF cuts (my edit):
                (!CheckEcalSFCuts(el) && f_ecalSFCuts) ||
                // ECAL SF cuts:
                (!checkEcalPCuts(el) && f_ecalPCuts) ||
                // ECAL Diagonoal SF cuts:
                (!checkEcalDiagCuts(el) && f_ecalDiagCuts) ||
                // ECAL edge cuts:
                (!EcalEdgeCuts(el) && f_ecalEdgeCuts) ||
                // Vertex cuts:
                (!checkVertex(el) && f_vertexCuts) ||
                // DC edge cuts:
                (!DCEdgeCuts(el) && f_DCEdgeCuts) ||
                // minium 800 MeV/c cut for electrons in class:
                (el->par()->getP() < 0.8)))
            setByPid(el);
    });
    /* My edit - end */

    if (debug_plots) {
        for (auto el : electrons) debug_c.fillAfterEl(el);
    }

    /* My edit - start */
    // Applying cuts on other particles is there is a good trigger electron:
    if (electrons.size() == 1) {
        if (debug_plots) {
            for (auto p : particles)
                if (p->par()->getPid() == 2212 || p->par()->getPid() == -211 ||
                    p->par()->getPid() == 211)
                    debug_c.fillBeforePart(p);
        }

        /*
          This may be a strange way to check the cuts, maybe there is a better
          way We need to ensure that the flag f_cuts is on otherwise we don't
          want to apply any cut The below logic will return particles that did
          not pass any cut (for only cut flags that are on Then I will invert
          the logic using !(logic) to return when the particle do pass all cuts

          (!checkPidCut(p) && f_pidCuts)    ||	         //PID cuts
          (!checkVertex(p) && f_vertexCuts) ||  //Vertex cut
          (!CDEdgeCuts(p)  && f_CDEdgeCuts) ||  //CD edge cut
          (!CDRegionCuts(p)  && f_CDRegionCuts) ||  //CD edge cut
          (!DCEdgeCuts(p) && f_DCEdgeCuts)  || //DC edge cut
          (!checkVertexCorrelation(electrons_det[0],p) && f_corr_vertexCuts)
          //Vertex correlation cut between electron
        */

        std::for_each(
            particles.begin(), particles.end(), [this, electrons_det](auto p) {
                if (p->par()->getCharge() == 0 && p->par()->getPid() != 11) {
                    // neutrals and electrons don't follow cuts below, skip them
                    setByPid(p);
                    // Add neutrals and electrons to allparticles:
                    addToAllParticles(p);
                    return;
                } else if (p->par()->getPid() != 11 && electrons.size() > 0) {
                    // Charged particles
                    ++event_mult;

                    bool check_pid_cuts = (
                        // Check if in proton PID:
                        (f_protonpidCuts && checkProtonPidCut(p)) ||
                        // Cuts or chi2pid cuts:
                        // If proton pid cuts is off but pid cuts on just use
                        // chi2pid
                        (f_pidCuts && checkPidCut(p)) ||
                        // if no pid cuts are specified let all particles pass
                        // pid cuts
                        (!f_protonpidCuts && !f_pidCuts));

                    if (!(
                            // PID cuts:
                            (!check_pid_cuts) ||
                            // Vertex cuts:
                            (!checkVertex(p) && f_vertexCuts) ||
                            // CD edge cuts:
                            (!CDEdgeCuts(p) && f_CDEdgeCuts) ||
                            // CD edge cuts:
                            (!CDRegionCuts(p) && f_CDRegionCuts) ||
                            // DC edge cuts:
                            (!DCEdgeCuts(p) && f_DCEdgeCuts) ||
                            // Vertex correlation with electron cuts:
                            (!checkVertexCorrelation(electrons_det[0], p) &&
                             f_corr_vertexCuts))) {
                        setByPid(p);
                        // Add all particles surviving the cuts in event to
                        // allparticles:
                        addToAllParticles(p);
                    }
                }
            });

        if (debug_plots) {
            for (auto p : protons) debug_c.fillAfterPart(p);
            for (auto p : piplus) debug_c.fillAfterPart(p);
            for (auto p : piminus) debug_c.fillAfterPart(p);

            for (auto el : electrons) debug_c.fillAfterEl(el);
        }
        multi_p_1e_cut_AC_debug->Fill(protons.size());
        multi_cpi_1e_cut_AC_debug->Fill(piplus.size() + piminus.size());
        multi_p_vs_cpi_1e_cut_AC_debug->Fill(protons.size(),
                                             piplus.size() + piminus.size());

    }  // good electron loop
    /* My edit - end */
}
