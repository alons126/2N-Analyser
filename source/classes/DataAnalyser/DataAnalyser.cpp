//
// Created by alons on 05/08/2024.
//

#include "DataAnalyser.h"

// DataAnalyser constructors ----------------------------------------------------------------------------------------------------------------------------------

/* Default constructor */
DataAnalyser::DataAnalyser(const string &FileType, const string &AnalyseFilePath, const string &AnalyseFileSample, const string &AnalyseFile)
{
    string AnalyserMode = ConfigureAnalyserMode(FileType);
    RunEventAnalyser(AnalyserMode, AnalyseFilePath, AnalyseFileSample, AnalyseFile);
}

// ConfigureAnalyserMode function -----------------------------------------------------------------------------------------------------------------------------

string DataAnalyser::ConfigureAnalyserMode(const string &FileType)
{
    string AnalyserMode;

    if (FileType == "root")
    {
        AnalyserMode = "Truth level";
    }
    else if (FileType == "hipo")
    {
        AnalyserMode = "Detector Simulation";
    }
    else
    {
        cout << "\nCould not find file type!! Exiting...\n\n", exit(0);
    }

    return AnalyserMode;
}

// RunEventAnalyser functions ---------------------------------------------------------------------------------------------------------------------------------

void DataAnalyser::RunEventAnalyser(const string &AnalyserMode, const string &AnalyseFilePath, const string &AnalyseFileSample, const string &AnalyseFile)
{
    if (AnalyserMode == "Truth level")
    {
        gst g;
        g.Loop();
    }
    else if (AnalyserMode == "Detector Simulation")
    {
        EventAnalyser(AnalyseFilePath, AnalyseFileSample, AnalyseFile);
    }
};
