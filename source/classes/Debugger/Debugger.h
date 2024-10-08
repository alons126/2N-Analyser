#ifndef DEBUGGER_H
#define DEBUGGER_H

#include <iostream>

using namespace std;

class Debugger
{
private:
    int StepTester = 1;

public:
    // default constructor --------------------------------------------------------------------------------------------------------------------------------------------------

    Debugger() = default;

    // PrintStepTester function ---------------------------------------------------------------------------------------------------------------------------------------------
    // Safety check function ------------------------------------------------------------------------------------------------------------------------------------------------

    void SafetyCheck_clas12ana_particles(const char *FILE, const int LINE,
                                         const bool &clas12ana_particles, std::vector<region_part_ptr> &allParticles, const int Nf);

    // PrintStepTester function ---------------------------------------------------------------------------------------------------------------------------------------------

    void PrintStepTester(const bool &DebuggerMode)
    {
        if (DebuggerMode)
        {
            std::cerr << "\n\nTest number " << StepTester << std::endl;
            std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__ << "\n\n"
                      << std::endl;
            ++StepTester;
        }
    }

    // PrintErrorMessage function -------------------------------------------------------------------------------------------------------------------------------------------

    void PrintErrorMessage(const std::string &ErrorMessage, const std::string &FunctionName = "")
    {
        std::cerr << "Error: " << ErrorMessage << std::endl;

        if (FunctionName != "")
        {
            std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__ << ", Function: " << FunctionName << std::endl;
        }
        else
        {
            std::cerr << "File: " << __FILE__ << ", Line: " << __LINE__ << std::endl;
        }

        std::cerr << "Aborting." << std::endl, exit(0);
    }

    void PrintErrorMessage(const char *FILE, const int LINE, const std::string &ErrorMessage, const std::string &FunctionName = "")
    {
        std::cerr << "Error: " << ErrorMessage << std::endl;

        if (FunctionName != "")
        {
            std::cerr << "File: " << FILE << ", Line: " << LINE << ", Function: " << FunctionName << std::endl;
        }
        else
        {
            std::cerr << "File: " << FILE << ", Line: " << LINE << std::endl;
        }

        std::cerr << "Aborting." << std::endl, exit(0);
    }
};

#endif // DEBUGGER_H
