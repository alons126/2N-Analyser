#include "Debugger.h"

void Debugger::SafetyCheck(const char *FILE, const int LINE,
                           const bool &clas12ana_particles, std::vector<region_part_ptr> &allParticles, const int Nf)
{
    if ((clas12ana_particles) && (allParticles.size() != Nf))
        {
            PrintErrorMessage(FILE, LINE, "allParticles.size() is different than Nf!", "");
        }
}