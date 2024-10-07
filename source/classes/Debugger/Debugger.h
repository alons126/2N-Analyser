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

    void PrintErrorMessage(const std::string &ErrorMessage, const std::string &FunctionName)
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
    }
};

#endif // DEBUGGER_H
