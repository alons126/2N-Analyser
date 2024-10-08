#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <iostream>

#include "../DSCuts/DSCuts.h"
#include "../ParticleID/ParticleID.cpp"

using namespace std;

class Debugger
{
private:
    int StepTester = 1;

public:
    // default constructor --------------------------------------------------------------------------------------------------------------------------------------------------

    Debugger() = default;

    // SafetyCheck_clas12ana_particles function ------------------------------------------------------------------------------------------------------------------------------------------------

    void SafetyCheck_clas12ana_particles(const char *FILE, const int LINE,
                                         const bool &clas12ana_particles, std::vector<region_part_ptr> &allParticles, const int Nf);

    // SafetyCheck_FD_protons function ------------------------------------------------------------------------------------------------------------------------------------------------

    void SafetyCheck_FD_protons(const char *FILE, const int LINE,
                                const vector<int> &Protons_ind, std::vector<region_part_ptr> &protons, const DSCuts &p_mom_th);

    // SafetyCheck_leading_FD_neutron function ------------------------------------------------------------------------------------------------------------------------------------------------

    void SafetyCheck_Reco_leading_FD_neutron(const char *FILE, const int LINE,
                                             const bool &apply_nucleon_cuts, const bool &ES_by_leading_FDneutron, const int &NeutronsFD_ind_mom_max,
                                             std::vector<region_part_ptr> &allParticles, vector<int> &NeutronsFD_ind, ParticleID &pid);

    void SafetyCheck_Truth_leading_FD_neutron(const char *FILE, const int LINE,
                                              const bool &ES_by_leading_FDneutron, const int &TL_IDed_Leading_nFD_ind, const double &TL_IDed_Leading_nFD_momentum,
                                              const double &Leading_TL_FDNeutron_Momentum, vector<int> TL_NeutronsFD_mom_ind, mcpar_ptr mcpbank);

    // SafetyCheck_FD_neutron function ------------------------------------------------------------------------------------------------------------------------------------------------

    void SafetyCheck_FD_neutron(const char *FILE, const int LINE,
                                const bool &apply_nucleon_cuts, std::vector<region_part_ptr> &allParticles, const DSCuts &n_mom_th,
                                vector<int> &NeutronsFD_ind, ParticleID &pid);

    // SafetyCheck_AMaps function ------------------------------------------------------------------------------------------------------------------------------------------------

    void SafetyCheck_AMaps_Truth_electrons(const char *FILE, const int LINE,
                                           const int &particlePDGtmp, const bool &inFD_AMaps);

    void SafetyCheck_AMaps_Truth_protons(const char *FILE, const int LINE,
                                         const int &particlePDGtmp, const bool &inFD_AMaps);

    void SafetyCheck_AMaps_Truth_neutrons(const char *FILE, const int LINE,
                                          const int &particlePDGtmp, const bool &inFD_AMaps);

    // SafetyCheck_one_good_electron function ------------------------------------------------------------------------------------------------------------------------------------------------

    void SafetyCheck_one_good_electron(const char *FILE, const int LINE,
                                       std::vector<region_part_ptr> &electrons);

    // SafetyCheck_1e_cut_electron function ------------------------------------------------------------------------------------------------------------------------------------------------

    void SafetyCheck_1e_cut_electron(const char *FILE, const int LINE,
                                     std::vector<region_part_ptr> &electrons, const vector<int> &Electron_ind);

    // PrintStepTester function ---------------------------------------------------------------------------------------------------------------------------------------------

    void PrintStepTester(const bool &DebuggerMode)
    {
        if (DebuggerMode)
        {
            std::cerr << "\033[31m\n\nTest number " << StepTester << std::endl;
            std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__ << "\n\n"
                      << std::endl;
            ++StepTester;
        }
    }

    // PrintErrorMessage function -------------------------------------------------------------------------------------------------------------------------------------------

    void PrintErrorMessage(const std::string &ErrorMessage, const std::string &FunctionName = "")
    {
        std::cerr << "\033[31m\n\nError: " << ErrorMessage << std::endl;

        if (FunctionName != "")
        {
            std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__ << ", Function: " << FunctionName << std::endl;
        }
        else
        {
            std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl;
        }

        std::cerr << "Aborting.\033[0m" << std::endl, exit(0);
    }

    void PrintErrorMessage(const char *FILE, const int LINE, const std::string &ErrorMessage, const std::string &FunctionName = "")
    {
        std::cerr << "\033[31m\n\nError: " << ErrorMessage << std::endl;

        if (FunctionName != "")
        {
            std::cerr << "File: " << FILE << ", Line: " << LINE << ", Function: " << FunctionName << std::endl;
        }
        else
        {
            std::cerr << "File: " << FILE << ", Line: " << LINE << std::endl;
        }

        std::cerr << "Aborting.\033[0m" << std::endl, exit(0);
    }
};

#endif // DEBUGGER_H
