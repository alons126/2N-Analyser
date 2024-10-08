#include "Debugger.h"

// SafetyCheck_clas12ana_particles function ------------------------------------------------------------------------------------------------------------------------------------------------

void Debugger::SafetyCheck_clas12ana_particles(const char *FILE, const int LINE,
                                               const bool &clas12ana_particles, std::vector<region_part_ptr> &allParticles, const int Nf)
{
    if ((clas12ana_particles) && (allParticles.size() != Nf))
    {
        PrintErrorMessage(FILE, LINE, "allParticles.size() is different than Nf!", "");
    }
}

// SafetyCheck_FD_protons function ------------------------------------------------------------------------------------------------------------------------------------------------

void Debugger::SafetyCheck_FD_protons(const char *FILE, const int LINE,
                                      const vector<int> &Protons_ind, std::vector<region_part_ptr> &protons, const DSCuts &p_mom_th)
{
    for (int i = 0; i < Protons_ind.size(); i++)
    {
        if (protons[i]->getRegion() == FD)
        {
            double Reco_Proton_Momentum = protons[i]->getP();

            if (!((Reco_Proton_Momentum <= p_mom_th.GetUpperCutConst()) && (Reco_Proton_Momentum >= p_mom_th.GetLowerCutConst())))
            {
                PrintErrorMessage(FILE, LINE, "FD proton check: there are FD protons outside momentum th. range!", "");
            }

            for (int j = i + 1; j < Protons_ind.size(); j++)
            {
                if (Protons_ind.at(i) == Protons_ind.at(j))
                {
                    PrintErrorMessage(FILE, LINE, "FD proton check: duplicated FD protons!", "");
                }
            }
        }
    }
}

// SafetyCheck_leading_FD_neutron function ------------------------------------------------------------------------------------------------------------------------------------------------

void Debugger::SafetyCheck_leading_FD_neutron(const char *FILE, const int LINE,
                                              const bool &apply_nucleon_cuts, const bool &ES_by_leading_FDneutron, const int &NeutronsFD_ind_mom_max, std::vector<region_part_ptr> &allParticles,
                                              vector<int> &NeutronsFD_ind, ParticleID &pid)
{
    if (ES_by_leading_FDneutron)
    {

        // Safety checks that leading nFD is neutron by definition
        if (NeutronsFD_ind_mom_max != -1)
        {
            bool LeadingnFDPCAL = (allParticles[NeutronsFD_ind_mom_max]->cal(clas12::PCAL)->getDetector() == 7);   // PCAL hit
            bool LeadingnFDECIN = (allParticles[NeutronsFD_ind_mom_max]->cal(clas12::ECIN)->getDetector() == 7);   // ECIN hit
            bool LeadingnFDECOUT = (allParticles[NeutronsFD_ind_mom_max]->cal(clas12::ECOUT)->getDetector() == 7); // ECOUT hit

            if (allParticles[NeutronsFD_ind_mom_max]->getRegion() != FD)
            {
                PrintErrorMessage(FILE, LINE, "Leading reco nFD check: Leading nFD is not in the FD!", "");
            }

            if (!((allParticles[NeutronsFD_ind_mom_max]->par()->getPid() == 2112) || (allParticles[NeutronsFD_ind_mom_max]->par()->getPid() == 22)))
            {
                PrintErrorMessage(FILE, LINE, ("Leading reco nFD check: A neutron PDG is not 2112 or 22 (" + to_string(allParticles[NeutronsFD_ind_mom_max]->par()->getPid())), "");
            }

            if (LeadingnFDPCAL)
            {
                PrintErrorMessage(FILE, LINE, "Leading reco nFD check: neutron hit in PCAL!", "");
            }

            if (!(LeadingnFDECIN || LeadingnFDECOUT))
            {
                PrintErrorMessage(FILE, LINE, "Leading reco nFD check: no neutron hit in ECIN or ECOUT!", "");
            }
        }

        // Safety check for leading nFD assignment
        if ((NeutronsFD_ind.size() > 0) && (NeutronsFD_ind_mom_max == -1))
        {
            PrintErrorMessage(FILE, LINE, "Leading reco nFD check: leading was not assigned!", "");
        }

        if (NeutronsFD_ind.size() == 1)
        {
            if (NeutronsFD_ind.at(0) != NeutronsFD_ind_mom_max)
            {
                PrintErrorMessage(FILE, LINE, "Leading reco nFD check: leading was assigned incorrectly!", "");
            }
        }
        else if (NeutronsFD_ind.size() > 1)
        {
            for (int &i : NeutronsFD_ind)
            {
                double Leading_neutron_momentum = pid.GetFDNeutronP(allParticles[NeutronsFD_ind_mom_max], apply_nucleon_cuts);
                double Temp_neutron_momentum = pid.GetFDNeutronP(allParticles[i], apply_nucleon_cuts);
                double dMomentum = Leading_neutron_momentum - Temp_neutron_momentum;

                if (dMomentum < 0)
                {
                    PrintErrorMessage(FILE, LINE, "Leading reco nFD check: assigned nFD is not the leading!", "");
                }
            }
        }
    }
}

// SafetyCheck_FD_neutron function ------------------------------------------------------------------------------------------------------------------------------------------------

void Debugger::SafetyCheck_FD_neutron(const char *FILE, const int LINE,
                                      const bool &apply_nucleon_cuts, std::vector<region_part_ptr> &allParticles, const DSCuts &n_mom_th,
                                      vector<int> &NeutronsFD_ind, ParticleID &pid)
{
    for (int i = 0; i < NeutronsFD_ind.size(); i++)
    {
        double Reco_Neutron_Momentum = pid.GetFDNeutronP(allParticles[NeutronsFD_ind.at(i)], apply_nucleon_cuts);

        if (!((Reco_Neutron_Momentum <= n_mom_th.GetUpperCut()) && (Reco_Neutron_Momentum >= n_mom_th.GetLowerCut())))
        {
            cout << "\033[33m\n\nallParticles[NeutronsFD_ind.at(i)]->par()->getPid() = " << allParticles[NeutronsFD_ind.at(i)]->par()->getPid()
                 << "\n\033[0m";
            cout << "\033[33mReco_Neutron_Momentum = " << Reco_Neutron_Momentum << "\n\033[0m";
            cout << "\033[33mn_mom_th.GetUpperCut() = " << n_mom_th.GetUpperCut() << "\n\033[0m";
            cout << "\033[33mn_mom_th.GetLowerCut() = " << n_mom_th.GetLowerCut() << "\n\033[0m";
            cout << "\033[33m\n\nFD neutron check: there are FD neutrons outside momentum th. range! Exiting...\n\n", exit(0);
            PrintErrorMessage(FILE, LINE, "FD neutron check: there are FD neutrons outside momentum th. range!", "");
        }

        for (int j = i + 1; j < NeutronsFD_ind.size(); j++)
        {
            if (NeutronsFD_ind.at(i) == NeutronsFD_ind.at(j))
            {
                PrintErrorMessage(FILE, LINE, "FD neutron check: duplicated FD neutrons!", "");
            }
        }
    }
}