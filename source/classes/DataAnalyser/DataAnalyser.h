//
// Created by alons on 05/08/2024.
//

#ifndef DATAANALYSER_H
#define DATAANALYSER_H

#include "../../../Old_analysers/DetectorSimulationAnalyser.C"
#include "../../../Old_analysers/TruthLevelAnalyser.c"

class DataAnalyser
{
private:
public:
    // default constructor --------------------------------------------------------------------------------------------------------------------------------------------------

    DataAnalyser(const string &FileType, const string &AnalyseFilePath, const string &AnalyseFileSample, const string &AnalyseFile);

    // ConfigureAnalyserMode function -----------------------------------------------------------------------------------------------------------------------------

    string ConfigureAnalyserMode(const string &FileType);

    // RunEventAnalyser functions ---------------------------------------------------------------------------------------------------------------------------------

    void RunEventAnalyser(const string &AnalyserMode, const string &AnalyseFilePath, const string &AnalyseFileSample, const string &AnalyseFile);
};

#endif // DATAANALYSER_H
