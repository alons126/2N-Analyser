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
void CLAS12Analysis::ReadInputParam(const char *filename)
{
    ifstream infile;
    infile.open(filename);

    if (infile.is_open())
    {
        string tp;

        // remove 3 lines of header
        for (int i = 0; i < 3; i++)
            getline(infile, tp);

        while (
            // read data from file object and put it into string:
            getline(infile, tp))
        {
            stringstream ss(tp);
            string parameter, parameter2;
            double value;
            // get cut identifier
            ss >> parameter;
            if (parameter == "pid_cuts")
            {
                // get cut values
                ss >> parameter2;
                stringstream ss2(parameter2);
                string pid_v;
                string detector;
                int count = 0; // parameter number
                int pid = -99;
                vector<double> par;

                while (getline(ss2, pid_v, ':'))
                {
                    if (count == 0)
                        pid = stoi(pid_v);
                    else if (count < 3)
                        par.push_back(atof(pid_v.c_str()));
                    else if (count == 3)
                        detector = pid_v;

                    count++;
                }
                if (pid != -99) // if pid cut exists in file
                {
                    if (detector == "FD")
                        Insertpid_cuts_fd(pid, par);
                    else if (detector == "CD")
                        Insertpid_cuts_cd(pid, par);
                }
            } // end PID cuts section

            else if (parameter == "vertex_cut")
            {
                ss >> parameter2;
                stringstream ss2(parameter2);
                string pid_v;
                int count = 0;
                string pid = "";
                vector<double> par;

                while (getline(ss2, pid_v, ':'))
                {
                    if (count == 0)
                        pid = pid_v;
                    else
                        par.push_back(atof(pid_v.c_str()));

                    count++;
                }

                if (pid != "")
                    Insertvertex_cuts(pid, par);
            }
            else if (parameter == "Momentum_cuts_ECAL")
            { // My addition
                ss >> parameter2;
                stringstream ss2(parameter2);
                string pid_v;
                int count = 0;
                string pid = "";
                vector<double> par;

                while (getline(ss2, pid_v, ':'))
                {
                    if (count == 0)
                        pid = pid_v;
                    else
                        par.push_back(atof(pid_v.c_str()));

                    count++;
                }

                if (pid != "")
                {
                    Neutron_Momentum_cut = par.at(1);
                }
            }
            else if (parameter == "Beta_cut_ECAL")
            { // My addition
                ss >> parameter2;
                stringstream ss2(parameter2);
                string pid_v;
                int count = 0;
                string pid = "";
                vector<double> par;

                while (getline(ss2, pid_v, ':'))
                {
                    if (count == 0)
                        pid = pid_v;
                    else
                        par.push_back(atof(pid_v.c_str()));

                    count++;
                }

                if (pid != "")
                {
                    FD_Neutral_Beta_Mean = par.at(0);
                    FD_Neutral_Beta_cut = par.at(1);
                }
            }
            else if (parameter == "dPhi_pFD_pCD")
            { // My addition
                ss >> parameter2;
                stringstream ss2(parameter2);
                string pid_v;
                int count = 0;
                string pid = "";
                vector<double> par;

                while (getline(ss2, pid_v, ':'))
                {
                    if (count == 0)
                        pid = pid_v;
                    else
                        par.push_back(atof(pid_v.c_str()));

                    count++;
                }

                if (pid != "")
                {
                    dPhi_p1_p2_Mean = par.at(0);
                }
            }
        }
    }
    else
        cout << "Parameter file didn't read in " << endl;
    return;
}

// HTCCNpheCuts function ------------------------------------------------------

/*
This function is my addition. It comes to add the ability to cusomize and
disable the cut on the number of photo-electrons in the HTCC.
*/
bool CLAS12Analysis::HTCCNpheCuts(region_part_ptr p)
{
    // true if inside cut
    double Nphe = p->che(HTCC)->getNphe();

    if (p->par()->getPid() == 11)
    {
        if (Nphe > htcc_Nphe_cut)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return true;
    }
}

// CheckEcalSFCuts function ---------------------------------------------------

/*
This is my edit based on the clas12ana function:
    bool checkEcalSFCuts(const region_part_ptr &p);

It allows the user to choose between the constant SF cuts
{SF_max_cut,SF_min_cut}, and the new SF cuts from clas12ana
*/
bool CLAS12Analysis::CheckEcalSFCuts(const region_part_ptr &p)
{
    if (f_old_ecalSFCut)
    {
        // If user wants constant SF cuts:
        if (p->par()->getPid() == 11)
        {
            double sampling_frac = getSF(p);

            if (sampling_frac < SF_max_cut && sampling_frac > SF_min_cut)
                return true;
            else
                return false;
        }
        else
            return false;
    }
    else
    {
        return checkEcalSFCuts(p);
    }
}

// CheckVertex function -------------------------------------------------------

/*
This is my edit based on the clas12ana function:
    bool checkVertex(const region_part_ptr &p)

It allows the user to choose between the old implementation of vertex cuts
from the MSc analysis and the implementation from clas12ana
*/
bool CLAS12Analysis::CheckVertex(const region_part_ptr &p)
{
    if (f_old_VertexCuts)
    {
        // If user wants MSc implementation of vertex cuts:

        // true if inside cut
        if (p->getRegion() == FD)
        {
            return ((p->par()->getVx() > vertex_x_cuts_FD.at(0) && p->par()->getVx() < vertex_x_cuts_FD.at(1)) &&
                    (p->par()->getVy() > vertex_y_cuts_FD.at(0) && p->par()->getVy() < vertex_y_cuts_FD.at(1)) &&
                    (p->par()->getVz() > vertex_z_cuts_FD.at(0) && p->par()->getVz() < vertex_z_cuts_FD.at(1)));
        }
        else if (p->getRegion() == CD)
        {
            return ((p->par()->getVx() > vertex_x_cuts_CD.at(0) && p->par()->getVx() < vertex_x_cuts_CD.at(1)) &&
                    (p->par()->getVy() > vertex_y_cuts_CD.at(0) && p->par()->getVy() < vertex_y_cuts_CD.at(1)) &&
                    (p->par()->getVz() > vertex_z_cuts_CD.at(0) && p->par()->getVz() < vertex_z_cuts_CD.at(1)));
        }
        else
        {
            return ((p->par()->getVx() > getvertex_x_cuts().at(0) && p->par()->getVx() < getvertex_x_cuts().at(1)) &&
                    (p->par()->getVy() > getvertex_y_cuts().at(0) && p->par()->getVy() < getvertex_y_cuts().at(1)) &&
                    (p->par()->getVz() > getvertex_z_cuts().at(0) && p->par()->getVz() < getvertex_z_cuts().at(1)));
        }
    }
    else
    {
        return checkVertex(p);
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
bool CLAS12Analysis::CheckVertexCorrelation(const region_part_ptr &el, const region_part_ptr &p)
{
    if (f_old_VertexCorrCuts)
    {
        // If user wants MSc implementation of vertex correlation cuts:

        // true if inside cut
        if (p->getRegion() == FD)
        { //  TODO:  My addition!
            return ((p->par()->getVz() - el->par()->getVz()) > vertex_corr_cuts_FD.at(0) && (p->par()->getVz() - el->par()->getVz()) < vertex_corr_cuts_FD.at(1));
        }
        else if (p->getRegion() == CD)
        {
            return ((p->par()->getVz() - el->par()->getVz()) > vertex_corr_cuts_CD.at(0) && (p->par()->getVz() - el->par()->getVz()) < vertex_corr_cuts_CD.at(1));
        }
        else
        {
            return ((p->par()->getVz() - el->par()->getVz()) > vertex_corr_cuts.at(0) && (p->par()->getVz() - el->par()->getVz()) < vertex_corr_cuts.at(1));
        }
    }
    else
    {
        return checkVertexCorrelation(el, p);
    }
}
// SetByPid function ------------------------------------------------------

/*
This is my edit based on the clas12ana function:
    void setByPid(const region_part_ptr &p);

it provids the same functionality, only that is filles allparticle vector in addition to each particles species
*/
void CLAS12Analysis::SetByPid(const region_part_ptr &p)
{
    int pid = p->par()->getPid();

    if (checkProtonPidCut(p) && getf_protonpidCuts())
        pid = 2212;

    if (!checkProtonPidCut(p) && getf_protonpidCuts() && getf_pidCuts() && p->getRegion() == clas12::CD && pid == 2212)
        pid = 9999;

    if (pid == 11)
    {
        electrons.push_back(p);
        // allparticles.push_back(p);
    }
    else if (pid == 2212)
    {
        // is a proton if not a ghost track and check for PID by TOF vs
        // momentum assignment
        if (!(checkGhostTrackCD(p) && getf_ghostTrackCuts()))
        {
            protons.push_back(p);
            // allparticles.push_back(p);
        }
    }
    else if (pid == 2112)
    {
        neutrons.push_back(p);
        // allparticles.push_back(p);
    }
    else if (pid == 45)
    {
        deuterons.push_back(p);
        // allparticles.push_back(p);
    }
    else if (pid == 211)
    {
        piplus.push_back(p);
        // allparticles.push_back(p);
    }
    else if (pid == -211)
    {
        piminus.push_back(p);
        // allparticles.push_back(p);
    }
    else if (pid == 321)
    {
        kplus.push_back(p);
        // allparticles.push_back(p);
    }
    else if (pid == -321)
    {
        kminus.push_back(p);
        // allparticles.push_back(p);
    }
    else if (pid == 0)
    {
        neutrals.push_back(p);
        // allparticles.push_back(p);
    }
    else
    {
        otherpart.push_back(p);
        // allparticles.push_back(p);
    }
}

// RunAnalysisCuts function ---------------------------------------------------

/*
This is my edit based on the clas12ana function:
    void Run(const std::unique_ptr<clas12::clas12reader> &c12);
*/
void CLAS12Analysis::RunAnalysisCuts(const std::unique_ptr<clas12::clas12reader> &c12)
{
    Clear();
    setcurrent_run(c12->runconfig()->getRun());
    checkCutParameters(); // check run number has the right cuts

    auto particles = c12->getDetParticles(); // particles is now a std::vector of particles for this event
    auto electrons_det = c12->getByID(11);

    /* My edit - start */
    auto protons_det = c12->getByID(2212);
    auto piplus_det = c12->getByID(211);
    auto piminus_det = c12->getByID(-211);

    // Filling multiplicity plots before cuts (BC) - no #e cuts:
    Debug_c.multi_p_BC_debug->Fill(protons_det.size());
    Debug_c.multi_cpi_BC_debug->Fill(piplus_det.size() + piminus_det.size());
    Debug_c.multi_p_vs_cpi_BC_debug->Fill(protons_det.size(), piplus_det.size() + piminus_det.size());

    // Filling multiplicity plots before cuts (BC) - 1e cut
    if (electrons_det.size() == 1)
    {
        Debug_c.multi_p_1e_cut_BC_debug->Fill(protons_det.size());
        Debug_c.multi_cpi_1e_cut_BC_debug->Fill(piplus_det.size() + piminus_det.size());
        Debug_c.multi_p_vs_cpi_1e_cut_BC_debug->Fill(protons_det.size(), piplus_det.size() + piminus_det.size());
    }

    int nf_initial = particles.size();
    /* My edit - end */

    // DEBUG plots
    if (getdebug_plots())
    {
        for (auto el : electrons_det)
            debug_c.fillBeforeEl(el);
    }

    /* My edit - start */
    // Applying electron quality cuts.
    // Loop runs all electrons in the event. */
    std::for_each(electrons_det.begin(), electrons_det.end(), [this](auto el)
                  {
        if (!(
                // Photo-electron min cut (my edit):
                (!HTCCNpheCuts(el) && f_NpheCuts) ||
                // ECAL SF cuts (my edit):
                (!CheckEcalSFCuts(el) && getf_ecalSFCuts()) ||
                // ECAL SF cuts:
                (!checkEcalPCuts(el) && getf_ecalPCuts()) ||
                // ECAL Diagonoal SF cuts:
                (!checkEcalDiagCuts(el) && getf_ecalDiagCuts()) ||
                // ECAL edge cuts:
                (!EcalEdgeCuts(el) && getf_ecalEdgeCuts()) ||
                // Vertex cuts:
                (!checkVertex(el) && getf_vertexCuts()) ||
                // DC edge cuts:
                (!DCEdgeCuts(el) && getf_DCEdgeCuts()) ||
                // minium 800 MeV/c cut for electrons in class:
                (el->par()->getP() < 0.8)))
            SetByPid(el); });
    /* My edit - end */

    if (getdebug_plots())
    {
        for (auto el : getelectrons())
            debug_c.fillAfterEl(el);
    }

    /* My edit - start */
    // Applying cuts on other particles is there is a good trigger electron:
    if (getelectrons().size() == 1)
    {
        if (getdebug_plots())
        {
            for (auto p : particles)
                if (p->par()->getPid() == 2212 || p->par()->getPid() == -211 || p->par()->getPid() == 211)
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

        std::for_each(particles.begin(), particles.end(), [this, electrons_det](auto p)
                      {
                if (p->par()->getCharge() == 0 && p->par()->getPid() != 11) {
                    // neutrals and electrons don't follow cuts below, skip them
                    SetByPid(p);
                    return;
                } else if (p->par()->getPid() != 11 && getelectrons().size() > 0) {
                    // Charged particles
                    increaseevent_mult();

                    bool check_pid_cuts = (
                        // Check if in proton PID:
                        (getf_protonpidCuts() && checkProtonPidCut(p)) ||
                        // Cuts or chi2pid cuts:
                        // If proton pid cuts is off but pid cuts on just use
                        // chi2pid
                        (getf_pidCuts() && checkPidCut(p)) ||
                        // if no pid cuts are specified let all particles pass
                        // pid cuts
                        (!getf_protonpidCuts() && !getf_pidCuts()));

                    if (!(
                            // PID cuts:
                            (!check_pid_cuts) ||
                            // Vertex cuts:
                            (!checkVertex(p) && getf_vertexCuts()) ||
                            // CD edge cuts:
                            (!CDEdgeCuts(p) && getf_CDEdgeCuts()) ||
                            // CD edge cuts:
                            (!CDRegionCuts(p) && getf_CDRegionCuts()) ||
                            // DC edge cuts:
                            (!DCEdgeCuts(p) && getf_DCEdgeCuts()) ||
                            // Vertex correlation with electron cuts:
                            (!checkVertexCorrelation(electrons_det[0], p) &&
                             getf_corr_vertexCuts()))) {
                        SetByPid(p);
                    }
                } });

        if (getdebug_plots())
        {
            for (auto p : getprotons())
                debug_c.fillAfterPart(p);
            for (auto p : getpiplus())
                debug_c.fillAfterPart(p);
            for (auto p : getpiminus())
                debug_c.fillAfterPart(p);

            for (auto el : getelectrons())
                debug_c.fillAfterEl(el);
        }

        Debug_c.multi_p_1e_cut_AC_debug->Fill(getprotons().size());
        Debug_c.multi_cpi_1e_cut_AC_debug->Fill(getpiplus().size() + getpiminus().size());
        Debug_c.multi_p_vs_cpi_1e_cut_AC_debug->Fill(getprotons().size(), getpiplus().size() + getpiminus().size());

        // Add all particles after PID (and one reco electron) in the allparticles vector
        for (auto el : getelectrons())
            allparticles.push_back(el);
        for (auto p : getprotons())
            allparticles.push_back(p);
        for (auto d : getdeuterons())
            allparticles.push_back(d);
        for (auto neut : getneutrals())
            allparticles.push_back(neut);
        for (auto n : getneutrons())
            allparticles.push_back(n);
        for (auto pip : getpiplus())
            allparticles.push_back(pip);
        for (auto pim : getpiminus())
            allparticles.push_back(pim);
        for (auto kp : getkplus())
            allparticles.push_back(kp);
        for (auto km : getkminus())
            allparticles.push_back(km);
        for (auto o : getotherpart())
            allparticles.push_back(o);
        
    } // good electron loop
    /* My edit - end */
}

// ConfigureElectronCuts function -----------------------------------------

/*
This function configures electron quality cuts.
*/
void CLAS12Analysis::ConfigureElectronCuts(
    const bool apply_cuts, // master
    const bool apply_Nphe_cut, DSCuts &Nphe_cuts_FD,
    const bool apply_ECAL_SF_cuts, const char *filename_SF_cuts,
    DSCuts &SF_cuts, const bool apply_ECAL_P_cuts, const char *filename_P_cuts,
    const bool apply_ECAL_diag_cut, const bool apply_ECAL_fiducial_cuts,
    DSCuts &PCAL_edge_cuts)
{
    if (apply_cuts)
    {
        // Cuts on electrons only:
        if (apply_Nphe_cut)
        {
            // making f_NpheCuts = ture (HTCC cuts)
            Nphe_cuts_FD =
                DSCuts("Nphe", "FD", "Electron", "1e cut", 0, getNpheCuts());
            setNpheCuts();
        }

        if (apply_ECAL_SF_cuts)
        {
            // making f_ecalSFCuts = ture
            // TODO: ask justin what are these cuts:
            // TODO: ask justin for these cuts for LH2 and C12 (and other
            // elements)
            readEcalSFPar(filename_SF_cuts);
            // TODO: RECHECK WHAT ARE THE CUTS HERE:
            SF_cuts = DSCuts("SF", "FD", "Electron", "1e cut", 0.24865,
                             getEcalSFLowerCut(), getEcalSFUpperCut());

            setEcalSFCuts();
        }

        if (apply_ECAL_P_cuts)
        {
            // making f_ecalPCuts = ture
            // TODO: ask justin what are these cuts:
            // TODO: ask justin for these cuts for LH2 and C12 (and other
            // elements)
            readEcalPPar(filename_P_cuts);

            setEcalPCuts();
        }

        if (apply_ECAL_diag_cut)
        {
            // making f_ecalDiagCuts = ture
            setEcalDiagCuts();
        }

        if (apply_ECAL_fiducial_cuts)
        {
            // making f_ecalEdgeCuts = ture (ECAL fiducial cuts)
            PCAL_edge_cuts = DSCuts("PCAL edge", "FD", "Electron", "1e cut", 0,
                                    getEcalEdgeCuts());
            setEcalEdgeCuts();
        }
    }
}

// ConfigureChargedHadronCuts function ------------------------------------

/*
This function configures charged hadron cuts.
*/
void CLAS12Analysis::ConfigureChargedHadronCuts(
    const bool apply_cuts, // master
    const bool apply_chi2_cuts_1e_cut, const char *filename_PIDCuts_1,
    const char *filename_PIDCuts_2, DSCuts &Chi2_Proton_cuts_CD,
    DSCuts &Chi2_Proton_cuts_FD, DSCuts &Chi2_piplus_cuts_CD,
    DSCuts &Chi2_piplus_cuts_FD, DSCuts &Chi2_piminus_cuts_CD,
    DSCuts &Chi2_piminus_cuts_FD, const bool apply_CD_edge_cuts,
    const bool apply_CD_region_cuts, const bool apply_ghostTrackCuts)
{
    if (apply_cuts)
    {
        // Cuts on all charged hadrons:
        if (!apply_chi2_cuts_1e_cut)
        {
            ReadInputParam(filename_PIDCuts_1);
        }
        else if (apply_chi2_cuts_1e_cut)
        {
            cout << "\nLoading fitted pid cuts...\n\n";
            ReadInputParam(filename_PIDCuts_2); // load sample-appropreate cuts
                                                // file from CutsDirectory

            /* Overwriting PID cuts according to SampleName */
            Chi2_Proton_cuts_CD.SetCutPram(GetPidCutMean(2212, "CD"),
                                           -GetPidCutSigma(2212, "CD"),
                                           GetPidCutSigma(2212, "CD"));
            Chi2_Proton_cuts_FD.SetCutPram(GetPidCutMean(2212, "FD"),
                                           -GetPidCutSigma(2212, "FD"),
                                           GetPidCutSigma(2212, "FD"));
            Chi2_piplus_cuts_CD.SetCutPram(GetPidCutMean(211, "CD"),
                                           -GetPidCutSigma(211, "CD"),
                                           GetPidCutSigma(211, "CD"));
            Chi2_piplus_cuts_FD.SetCutPram(GetPidCutMean(211, "FD"),
                                           -GetPidCutSigma(211, "FD"),
                                           GetPidCutSigma(211, "FD"));
            Chi2_piminus_cuts_CD.SetCutPram(GetPidCutMean(-211, "CD"),
                                            -GetPidCutSigma(-211, "CD"),
                                            GetPidCutSigma(-211, "CD"));
            Chi2_piminus_cuts_FD.SetCutPram(GetPidCutMean(-211, "FD"),
                                            -GetPidCutSigma(-211, "FD"),
                                            GetPidCutSigma(-211, "FD"));

            setProtonPidCuts(); // making f_protonpidCuts = true
            setPidCuts();       // making f_pidCuts = true
        }

        if (apply_CD_edge_cuts)
        {
            // making f_CDEdgeCuts = true
            setCDEdgeCuts();
        }

        if (apply_CD_region_cuts)
        {
            // making f_CDRegionCuts = true
            setCDRegionCuts();
        }

        if (apply_ghostTrackCuts)
        {
            // making f_ghostTrackCuts = true
            setGhostTrackCuts();
        }
    }
}

// ConfigureChargedParticleCuts function ----------------------------------

/*
This function configures charged particle cuts that are not included in
either ConfigureElectronCuts and ConfigureChargedHadronCuts.
*/
void CLAS12Analysis::ConfigureChargedParticleCuts(
    const bool apply_cuts, // master
    const bool apply_Vz_cuts, DSCuts Vz_cut, DSCuts Vz_cut_FD, DSCuts Vz_cut_CD,
    const bool apply_dVz_cuts, DSCuts dVz_cuts, DSCuts dVz_cuts_FD,
    DSCuts dVz_cuts_CD, const bool apply_DC_fiducial_cuts,
    DSCuts DC_edge_cuts)
{
    if (apply_cuts)
    { // Cuts on all charged particles:
        if (apply_Vz_cuts)
        {
            setVertexCuts(); // making f_vertexCuts = ture
            setVzcuts(Vz_cut.GetLowerCut(),
                      Vz_cut.GetUpperCut()); // setting Vz cuts for all
                                             // (charged?) particles
            setVzcutsFD(
                Vz_cut_FD.GetLowerCut(),
                Vz_cut_FD.GetUpperCut()); // setting Vz cuts for all charged
                                          // particles (FD only)
            setVzcutsCD(
                Vz_cut_CD.GetLowerCut(),
                Vz_cut_CD.GetUpperCut()); // setting Vz cuts for all charged
                                          // particles (CD only)
        }

        if (apply_dVz_cuts)
        {
            setVertexCorrCuts(); // making f_corr_vertexCuts = ture
            setVertexCorrCutsLim(
                dVz_cuts.GetLowerCut(),
                dVz_cuts.GetUpperCut()); // setting dVz cuts (general)
            setVertexCorrCutsLimFD(
                dVz_cuts_FD.GetLowerCut(),
                dVz_cuts_FD.GetUpperCut()); // setting dVz cuts (FD only)
            setVertexCorrCutsLimCD(
                dVz_cuts_CD.GetLowerCut(),
                dVz_cuts_CD.GetUpperCut()); // setting dVz cuts (CD only)
        }

        if (apply_DC_fiducial_cuts)
        {
            // making f_DCEdgeCuts = ture (DC fiducial cuts?)
            DC_edge_cuts = DSCuts("DC edge", "FD", "Electron", "1e cut", 0,
                                  getDCEdgeCuts());
            setDCEdgeCuts();
        }
    }
}

// ConfigureNucleonCuts function ------------------------------------------

/*
This function configures nucleon cuts.
*/
void CLAS12Analysis::ConfigureNucleonCuts(
    const bool apply_cuts, // master
    const bool apply_nucleon_cuts, DSCuts &n_momentum_cuts_ABF_FD_n_from_ph,
    DSCuts &n_momentum_cuts_ABF_FD_n_from_ph_apprax,
    DSCuts &Beta_max_cut_ABF_FD_n_from_ph,
    DSCuts &Beta_max_cut_ABF_FD_n_from_ph_apprax,
    const char *filename_NucleonCuts, const bool limless_mom_eff_plots,
    const bool is2GeVSample, DSCuts &n_mom_th, DSCuts &TL_n_mom_cuts,
    double beamE, const bool apply_nBeta_fit_cuts, DSCuts &Beta_cut,
    DSCuts &dphi_p1_p2_2p, DSCuts &dphi_pFD_pCD_2p,
    DSCuts &dphi_pFD_pCD_pFDpCD)
{
    if (apply_cuts)
    {
        if (!apply_nucleon_cuts)
        {
            /* Setting neutron momentum cut before beta fit (i.e., no cut!) */
            n_momentum_cuts_ABF_FD_n_from_ph =
                DSCuts("Momentum_cuts_ECAL", "FD-ECAL", "Neutron", "", 0,
                       n_mom_th.GetLowerCut(), 9999);
            n_momentum_cuts_ABF_FD_n_from_ph_apprax =
                DSCuts("Momentum_cuts_ECAL_apprax", "FD-ECAL_apprax", "Neutron",
                       "", 0, n_mom_th.GetLowerCut(), 9999);

            /* Setting variables to log beta fit parameters into (i.e., no cut!)
             */
            Beta_max_cut_ABF_FD_n_from_ph = DSCuts(
                "Beta_cut_ECAL", "FD-ECAL", "", "nFDpCD", 1, -9999, 9999);
            Beta_max_cut_ABF_FD_n_from_ph_apprax =
                DSCuts("Beta_cut_ECAL_apprax", "FD-ECAL_apprax", "", "1n", 1,
                       -9999, 9999);
        }
        else
        {
            cout << "\n\nLoading fitted Beta cuts...\n\n";
            ReadInputParam(
                filename_NucleonCuts); // load sample-appropreate cuts file
                                       // from CutsDirectory

            /* Setting nucleon cuts - only if NOT plotting efficiency plots! */
            if (limless_mom_eff_plots || is2GeVSample)
            {
                /* If sample is with 2GeV beam energy, no fit is needed. */
                n_mom_th.SetUpperCut(beamE);
                TL_n_mom_cuts.SetUpperCut(beamE);
            }
            else
            {
                /* Else, load values from fit. */
                if (apply_nBeta_fit_cuts)
                {
                    n_mom_th.SetUpperCut(getNeutronMomentumCut());
                    TL_n_mom_cuts.SetUpperCut(getNeutronMomentumCut());
                    Beta_cut.SetUpperCut(
                        getNeutralBetaCut()); // Log values of beta fit
                                              // cut (for monitoring)
                    Beta_cut.SetMean(
                        getNeutralBetaCutMean()); // Log values of beta
                                                  // fit cut (for
                                                  // monitoring)
                }
            }

            dphi_p1_p2_2p.SetMean(getdPhiCutMean());
            dphi_pFD_pCD_2p.SetMean(getdPhiCutMean());
            dphi_pFD_pCD_pFDpCD.SetMean(getdPhiCutMean());
        }

        printParams();
    }
}