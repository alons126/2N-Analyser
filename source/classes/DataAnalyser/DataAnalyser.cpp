//
// Created by alons on 05/08/2024.
//

#include "DataAnalyser.h"

// DataAnalyser constructors ----------------------------------------------------------------------------------------------------------------------------------

/* Default constructor */
DataAnalyser::DataAnalyser(const string &FileType)
{
    string AnalyserMode = ConfigureAnalyserMode(FileType);
    RunEventAnalyser(AnalyserMode);
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

void DataAnalyser::RunEventAnalyser(const string &AnalyserMode)
{
    if (AnalyserMode == "Truth level")
    {
        gst g;
        g.Loop();
    }
    else if (AnalyserMode == "Detector Simulation")
    {
        EventAnalyser(AnalyseFilePath.at(i), AnalyseFileSample.at(i), AnalyseFile.at(i));
    }
};
