#include "Debugger.h"

void Debugger::SafetyCheck_clas12ana_particles(const char *FILE, const int LINE,
                                               const bool &clas12ana_particles, std::vector<region_part_ptr> &allParticles, const int Nf)
{
    if ((clas12ana_particles) && (allParticles.size() != Nf))
    {
        PrintErrorMessage(FILE, LINE, "allParticles.size() is different than Nf!", "");
    }
}

void Debugger::SafetyCheck_FD_protons(const char *FILE, const int LINE,
                                      const vector<int> &Protons_ind, std::vector<region_part_ptr> &protons, const DSCuts &p_mom_th)
{
    for (int i = 0; i < Protons_ind.size(); i++)
    {
        if (protons[i]->getRegion() == FD)
        {
            double Reco_Proton_Momentum = protons[i]->getP();

            if (!((Reco_Proton_Momentum <= p_mom_th.GetUpperCut()) && (Reco_Proton_Momentum >= p_mom_th.GetLowerCut())))
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