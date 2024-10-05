
#include "ExperimentParameters.h"

// Constructor ----------------------------------------------------------------------------------------------------------------------------------------

//<editor-fold desc="Constructor">
ExperimentParameters::ExperimentParameters(const string &AnalyseFilePath, const string &AnalyseFileSample)
{
    SampleName = ConfigureSampleName(AnalyseFilePath, AnalyseFileSample);
    BeanEnergy = ConfigureBeanEnergy(SampleName);

    if (SampleName.find("H1") <= SampleName[SampleName.size() - 1])
    {
        TargetElement = "H1";
        TargetElementPDG = 1000010010;
        TotalBaryonNumber_A = 1;
        TotalChargeNumber_Z = 1;
        StrangeQuarksNumber_L = IsomerNumber_I = 0;
    }
    else if ((SampleName.find("c12") <= SampleName[SampleName.size() - 1]) || (SampleName.find("C12") <= SampleName[SampleName.size() - 1]) ||
             (SampleName.find("12c") <= SampleName[SampleName.size() - 1]) || (SampleName.find("12C") <= SampleName[SampleName.size() - 1]) ||
             (SampleName.find("_c_") <= SampleName[SampleName.size() - 1]) || (SampleName.find("_C_") <= SampleName[SampleName.size() - 1]))
    {
        TargetElement = "C12";
        TargetElementPDG = 1000060120;
        TotalBaryonNumber_A = 12;
        TotalChargeNumber_Z = 6;
        StrangeQuarksNumber_L = IsomerNumber_I = 0;
    }
    else if (SampleName.find("Ca48") <= SampleName[SampleName.size() - 1])
    {
        TargetElement = "Ca48";
        TargetElementPDG = 1000200480;
        TotalBaryonNumber_A = 48;
        TotalChargeNumber_Z = 20;
        StrangeQuarksNumber_L = IsomerNumber_I = 0;
    }
    else if (SampleName.find("Ar40") <= SampleName[SampleName.size() - 1])
    {
        TargetElement = "Ar40";
        TargetElementPDG = 1000180400;
        TotalBaryonNumber_A = 40;
        TotalChargeNumber_Z = 18;
        StrangeQuarksNumber_L = IsomerNumber_I = 0;
    }
    else
    {
        TargetElement = "UNKOWN";
        TargetElementPDG = -9999;
        TotalBaryonNumber_A = TotalChargeNumber_Z = StrangeQuarksNumber_L = IsomerNumber_I = 0;
    }
}
//</editor-fold>

// ConfigureSampleName function -----------------------------------------------------------------------------------------------------------------------------------------

//<editor-fold desc="ConfigureSampleName function">
string ExperimentParameters::ConfigureSampleName(const string &AnalyseFilePath, const string &AnalyseFileSample)
{
    string sName = "unknown_sample_598636MeV"; // to set beamE = 5.98636 by default;

    if (findSubstring(AnalyseFilePath, "Uniform_e-p-n_samples"))
    { // Uniform samples
        if (findSubstring(AnalyseFilePath, "OutPut_e_tester_1e"))
        { // Electron tester samples
            if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_e_tester_1e")
            { // Uniform, simulation, 2GeV, ifarm
                if (AnalyseFileSample == "reconhipo")
                {
                    BeamAt2GeV = SimulationSample = true;
                    sName = "Uniform_sample_e_tester_2070MeV";
                }
            }
            else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut_e_tester_1e")
            { // Uniform, simulation, 4GeV, ifarm
                if (AnalyseFileSample == "reconhipo")
                {
                    BeamAt4GeV = SimulationSample = true;
                    sName = "Uniform_sample_e_tester_4029MeV";
                }
            }
            else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut_e_tester_1e")
            { // Uniform, simulation, 6GeV, ifarm
                if (AnalyseFileSample == "reconhipo")
                {
                    BeamAt6GeV = SimulationSample = true;
                    sName = "Uniform_sample_e_tester_5986MeV";
                }
            }
        }
        else
        { // Uniform samples for acceptance maps
            if (findSubstring(AnalyseFilePath, "2070MeV"))
            { /* 2GeV samples
                 NOTE: here '2070MeV' has to be in the sample path! */
                if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_1e")
                { // Uniform 1e, simulation, 2GeV, ifarm
                    if (AnalyseFileSample == "reconhipo")
                    {
                        BeamAt2GeV = SimulationSample = true;
                        sName = "Uniform_1e_sample_2070MeV";
                    }
                }
                else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_ep")
                { // Uniform ep, simulation, 2GeV, ifarm
                    if (AnalyseFileSample == "reconhipo")
                    {
                        BeamAt2GeV = SimulationSample = true;
                        sName = "Uniform_ep_sample_2070MeV";
                    }
                }
                else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_en")
                { // Uniform en, simulation, 2GeV, ifarm
                    if (AnalyseFileSample == "reconhipo")
                    {
                        BeamAt2GeV = SimulationSample = true;
                        sName = "Uniform_en_sample_2070MeV";
                    }
                }
            }
            else if (findSubstring(AnalyseFilePath, "4029MeV"))
            { /* 4GeV samples
                 NOTE: here '4029MeV' has to be in the sample path! */
                if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut_1e")
                { // Uniform 1e, simulation, 4GeV, ifarm
                    if (AnalyseFileSample == "reconhipo")
                    {
                        BeamAt4GeV = SimulationSample = true;
                        sName = "Uniform_1e_sample_4029MeV";
                    }
                }
                else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut_ep")
                { // Uniform ep, simulation, 4GeV, ifarm
                    if (AnalyseFileSample == "reconhipo")
                    {
                        BeamAt4GeV = SimulationSample = true;
                        sName = "Uniform_ep_sample_4029MeV";
                    }
                }
                else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut_en")
                { // Uniform en, simulation, 4GeV, ifarm
                    if (AnalyseFileSample == "reconhipo")
                    {
                        BeamAt4GeV = SimulationSample = true;
                        sName = "Uniform_en_sample_4029MeV";
                    }
                }
            }
            else if (findSubstring(AnalyseFilePath, "5986MeV"))
            { /* 6GeV samples
                 NOTE: here '5986MeV' has to be in the sample path! */
                if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut_1e")
                { // Uniform 1e, simulation, 6GeV, ifarm
                    if (AnalyseFileSample == "reconhipo")
                    {
                        BeamAt6GeV = SimulationSample = true;
                        sName = "Uniform_1e_sample_5986MeV";
                    }
                }
                else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut_ep")
                { // Uniform ep, simulation, 6GeV, ifarm
                    if (AnalyseFileSample == "reconhipo")
                    {
                        BeamAt6GeV = SimulationSample = true;
                        sName = "Uniform_ep_sample_5986MeV";
                    }
                }
                else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut_en")
                { // Uniform en, simulation, 6GeV, ifarm
                    if (AnalyseFileSample == "reconhipo")
                    {
                        BeamAt6GeV = SimulationSample = true;
                        sName = "Uniform_en_sample_5986MeV";
                    }
                }
            }
        }
    }
    else if (AnalyseFilePath == "volatile/clas12/rg-m/48Ca/dst/recon")
    { // Ca48, data, 6GeV, ifarm
        if (AnalyseFileSample == "015832")
        {
            BeamAt6GeV = DataSample = true;
            sName = "Ca48_data_6GeV_run_015832";
        }
        else if (AnalyseFileSample == "015843")
        {
            BeamAt6GeV = DataSample = true;
            sName = "Ca48_data_6GeV_run_015843";
        }
        else if (AnalyseFileSample == "015852")
        {
            BeamAt6GeV = DataSample = true;
            sName = "Ca48_data_6GeV_run_015852";
        }
        else if (AnalyseFileSample == "015854")
        {
            BeamAt6GeV = DataSample = true;
            sName = "Ca48_data_6GeV_run_015854";
        }
    }
    else if (AnalyseFilePath == "cache/hallb/scratch/rg-m/LH2/8.6.0")
    { // LH2, data, 6GeV, ifarm
        if (AnalyseFileSample == "015032")
        {
            BeamAt6GeV = DataSample = true;
            sName = "LH2_data_6GeV_run_015032";
        }
    }
    //
    else if (AnalyseFilePath == "cache/clas12/rg-m/production/pass1/2gev/H/dst/recon")
    { // H1, data, 2GeV, ifarm (Q2 study)
        if (AnalyseFileSample == "015634")
        {
            BeamAt2GeV = DataSample = true;
            sName = "H1_data_2GeV_run_015634";
        }
    }
    // else if (AnalyseFilePath == "cache/clas12/rg-m/production/pass1/4gev/Ar/dst/recon")
    // { // H1, data, 4GeV, ifarm (Q2 study)
    //     if (AnalyseFileSample == "015743")
    //     {
    //         BeamAt4GeV = DataSample = true;
    //         sName = "H1_data_4GeV_run_015743";
    //     }
    // }
    else if (AnalyseFilePath == "cache/clas12/rg-m/production/pass1/6gev/H/dst/recon")
    { // H1, data, 6GeV, ifarm (Q2 study)
        if (AnalyseFileSample == "015028")
        {
            BeamAt6GeV = DataSample = true;
            sName = "H1_data_6GeV_run_015028";
        }
    }
    else if (AnalyseFilePath == "cache/clas12/rg-m/production/pass1/2gev/D/dst/recon")
    { // D2, data, 2GeV, ifarm (Q2 study)
        if (AnalyseFileSample == "")
        {
            BeamAt2GeV = DataSample = true;
            sName = "D2_data_2GeV";
        }
    }
    // else if (AnalyseFilePath == "cache/clas12/rg-m/production/pass1/4gev/Ar/dst/recon")
    // { // D2, data, 4GeV, ifarm (Q2 study)
    //     if (AnalyseFileSample == "015743")
    //     {
    //         BeamAt4GeV = DataSample = true;
    //         sName = "D2_data_4GeV_run_015743";
    //     }
    // }
    else if (AnalyseFilePath == "cache/clas12/rg-m/production/pass1/6gev/D/dst/recon")
    { // D2, data, 6GeV, ifarm (Q2 study)
        if (AnalyseFileSample == "015443")
        {
            BeamAt6GeV = DataSample = true;
            sName = "D2_data_6GeV_run_015443";
        }
    }
    else if (AnalyseFilePath == "cache/clas12/rg-m/production/pass1/2gev/Ar/dst/recon")
    { // Ar40, data, 2GeV, ifarm (Q2 study)
        if (AnalyseFileSample == "015672")
        {
            BeamAt2GeV = DataSample = true;
            sName = "Ar40_data_2GeV_run_015672";
        }
    }
    else if (AnalyseFilePath == "cache/clas12/rg-m/production/pass1/4gev/Ar/dst/recon")
    { // Ar40, data, 4GeV, ifarm (Q2 study)
        if (AnalyseFileSample == "015743")
        {
            BeamAt4GeV = DataSample = true;
            sName = "Ar40_data_4GeV_run_015743";
        }
    }
    else if (AnalyseFilePath == "cache/clas12/rg-m/production/pass1/6gev/Ar/dst/recon")
    { // Ar40, data, 6GeV, ifarm (Q2 study)
        if (AnalyseFileSample == "015792")
        {
            BeamAt6GeV = DataSample = true;
            sName = "Ar40_data_6GeV_run_015792";
        }
    }
    else if (AnalyseFilePath == "cache/clas12/rg-m/production/pass1/2gev/C/dst/recon")
    { // C, data, 2GeV, ifarm (Q2 study)
        if (AnalyseFileSample == "015664")
        {
            BeamAt2GeV = DataSample = true;
            sName = "C12_data_2GeV_run_015664";
        }
    }
    else if (AnalyseFilePath == "cache/clas12/rg-m/production/pass1/4gev/C/dst/recon")
    { // C, data, 4GeV, ifarm (Q2 study)
        if (AnalyseFileSample == "015778")
        {
            BeamAt4GeV = DataSample = true;
            sName = "C12_data_4GeV_run_015778";
        }
    }
    else if (AnalyseFilePath == "cache/clas12/rg-m/production/pass1/6gev/Cx4/dst/recon")
    {                                      // Cx4, data, 6GeV, ifarm
        if (AnalyseFileSample == "015186") // (Q2 study)
        {
            BeamAt6GeV = DataSample = true;
            sName = "C12x4_data_6GeV_run_015186";
        }
        else if (AnalyseFileSample == "015187")
        {
            BeamAt6GeV = DataSample = true;
            sName = "C12x4_data_6GeV_run_015187";
        }
        else if (AnalyseFileSample == "015188")
        {
            BeamAt6GeV = DataSample = true;
            sName = "C12x4_data_6GeV_run_015188";
        }
        else if (AnalyseFileSample == "015189")
        {
            BeamAt6GeV = DataSample = true;
            sName = "C12x4_data_6GeV_run_015189";
        }
        else if (AnalyseFileSample == "015190")
        {
            BeamAt6GeV = DataSample = true;
            sName = "C12x4_data_6GeV_run_015190";
        }
        else if (AnalyseFileSample == "015191")
        {
            BeamAt6GeV = DataSample = true;
            sName = "C12x4_data_6GeV_run_015191";
        }
        else if (AnalyseFileSample == "015192")
        {
            BeamAt6GeV = DataSample = true;
            sName = "C12x4_data_6GeV_run_015192";
        }
        else if (AnalyseFileSample == "015193")
        {
            BeamAt6GeV = DataSample = true;
            sName = "C12x4_data_6GeV_run_015193";
        }
        else if (AnalyseFileSample == "015194")
        {
            BeamAt6GeV = DataSample = true;
            sName = "C12x4_data_6GeV_run_015194";
        }
        else if (AnalyseFileSample == "015195")
        {
            BeamAt6GeV = DataSample = true;
            sName = "C12x4_data_6GeV_run_015195";
        }
        else if (AnalyseFileSample == "")
        {
            BeamAt6GeV = DataSample = true;
            sName = "C12x4_data_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_02")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_02)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_02_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_03")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_03)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_03_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_04")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_04)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_04_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_05")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_05)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_05_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_06")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_06)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_06_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_07")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_07)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_07_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_08")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_08)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_08_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_09")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_09)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_09_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_10")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_10)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_10_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_11")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_11)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_11_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_12")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_12)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_12_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_13")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_13)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_13_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_14")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_14)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_14_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_15")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_15)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_15_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_16")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_16)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_16_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_17")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_17)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_17_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_18")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_18)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_18_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_19")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_19)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_19_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_20")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_20)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_20_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_21")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_21)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_21_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_22")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_22)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_22_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_23")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_23)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_23_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_24")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_24)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_24_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_25")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_25)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_25_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_26")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_26)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_26_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_27")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_27)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_27_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_28")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_28)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_28_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_29")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_29)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_29_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_30")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_30)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_30_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_31")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_31)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_31_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_32")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_32)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_32_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_33")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_33)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_33_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_34")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_34)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_34_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_35")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_35)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_35_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_36")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_36)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_36_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_37")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_37)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_37_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_38")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_38)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_38_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_39")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_39)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_39_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_40")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_40)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_40_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_02")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_02)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_02_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_03")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_03)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_03_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_04")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_04)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_04_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_05")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_05)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_05_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_06")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_06)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_06_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_07")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_07)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_07_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_08")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_08)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_08_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_09")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_09)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_09_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_10")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_10)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_10_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_11")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_11)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_11_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_12")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_12)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_12_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_13")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_13)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_13_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_14")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_14)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_14_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_15")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_15)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_15_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_16")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_16)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_16_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_17")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_17)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_17_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_18")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_18)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_18_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_19")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_19)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_19_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_20")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_20)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_20_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_21")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_21)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_21_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_22")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_22)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_22_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_23")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_23)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_23_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_24")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_24)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_24_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_25")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_25)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_25_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_26")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_26)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_26_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_27")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_27)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_27_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_28")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_28)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_28_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_29")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_29)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_29_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_30")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_30)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_30_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_31")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_31)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_31_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_32")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_32)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_32_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_33")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_33)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_33_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_34")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_34)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_34_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_35")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_35)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_35_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_36")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_36)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_36_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_37")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_37)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_37_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_38")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_38)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_38_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_39")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_39)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_39_4GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_40")
    { // C, simulation, 4GeV, ifarm (Q2 study; Q2_0_40)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt4GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_40_4GeV";
        }
    }

    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_40")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_40)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_40_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_41")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_41)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_41_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_42")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_42)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_42_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_43")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_43)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_43_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_44")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_44)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_44_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_45")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_45)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_45_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_46")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_46)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_46_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_47")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_47)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_47_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_48")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_48)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_48_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_49")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_49)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_49_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_50")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_50)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_50_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_51")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_51)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_51_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_52")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_52)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_52_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_53")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_53)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_53_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_54")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_54)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_54_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_55")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_55)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_55_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_56")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_56)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_56_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_57")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_57)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_57_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_58")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_58)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_58_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_59")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_59)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_59_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_60")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_60)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_60_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_61")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_61)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_61_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_62")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_62)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_62_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_63")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_63)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_63_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_64")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_64)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_64_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_65")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_65)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_65_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_66")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_66)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_66_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_67")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_67)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_67_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_68")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_68)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_68_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_69")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_69)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_69_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_70")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_70)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_70_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_71")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_71)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_71_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_72")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_72)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_72_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_73")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_73)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_73_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_74")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_74)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_74_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_75")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_75)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_75_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_76")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_76)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_76_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_77")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_77)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_77_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_78")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_78)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_78_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_79")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_79)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_79_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_80")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_80)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_G18_Q2_0_80_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_40")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_40)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_40_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_41")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_41)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_41_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_42")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_42)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_42_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_43")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_43)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_43_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_44")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_44)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_44_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_45")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_45)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_45_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_46")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_46)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_46_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_47")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_47)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_47_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_48")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_48)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_48_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_49")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_49)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_49_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_50")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_50)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_50_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_51")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_51)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_51_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_52")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_52)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_52_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_53")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_53)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_53_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_54")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_54)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_54_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_55")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_55)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_55_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_56")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_56)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_56_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_57")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_57)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_57_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_58")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_58)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_58_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_59")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_59)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_59_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_60")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_60)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_60_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_61")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_61)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_61_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_62")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_62)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_62_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_63")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_63)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_63_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_64")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_64)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_64_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_65")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_65)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_65_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_66")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_66)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_66_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_67")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_67)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_67_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_68")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_68)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_68_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_69")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_69)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_69_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_70")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_70)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_70_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_71")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_71)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_71_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_72")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_72)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_72_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_73")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_73)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_73_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_74")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_74)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_74_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_75")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_75)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_75_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_76")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_76)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_76_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_77")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_77)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_77_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_78")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_78)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_78_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_79")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_79)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_79_6GeV";
        }
    }
    else if (AnalyseFilePath == "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_80")
    { // C, simulation, 6GeV, ifarm (Q2 study; Q2_0_80)
        if (AnalyseFileSample == "reconhipo")
        {
            BeamAt6GeV = SimulationSample = true;
            sName = "C12_simulation_SuSa_Q2_0_80_6GeV";
        }
    }

    //<editor-fold desc="Safety checks">
    if (!BeamAt2GeV && !BeamAt4GeV && !BeamAt6GeV)
    {
        cout << "\n\nConfigureSampleName: beam energy unknown! Configured variables are:\n";
        cout << "AnalyseFilePath = " << AnalyseFilePath << "\n";
        cout << "sName = " << sName << "\n";
        cout << "BeamAt2GeV = " << BeamAt2GeV << "\n";
        cout << "BeamAt4GeV = " << BeamAt4GeV << "\n";
        cout << "BeamAt6GeV = " << BeamAt6GeV << "\n";
        cout << "Exiting...\n", exit(0);
    }

    if (BeamAt2GeV && BeamAt4GeV && BeamAt6GeV)
    {
        cout << "\n\nConfigureSampleName: beam energy configuration error! Configured variables are:\n";
        cout << "AnalyseFilePath = " << AnalyseFilePath << "\n";
        cout << "sName = " << sName << "\n";
        cout << "BeamAt2GeV = " << BeamAt2GeV << "\n";
        cout << "BeamAt4GeV = " << BeamAt4GeV << "\n";
        cout << "BeamAt6GeV = " << BeamAt6GeV << "\n";
        cout << "SimulationSample = " << SimulationSample << "\n";
        cout << "DataSample = " << DataSample << "\n";
        cout << "Exiting...\n", exit(0);
    }

    if (SimulationSample && DataSample)
    {
        cout << "\n\nConfigureSampleName: sample type unknown! Configured variables are:\n";
        cout << "AnalyseFilePath = " << AnalyseFilePath << "\n";
        cout << "sName = " << sName << "\n";
        cout << "BeamAt2GeV = " << BeamAt2GeV << "\n";
        cout << "BeamAt4GeV = " << BeamAt4GeV << "\n";
        cout << "BeamAt6GeV = " << BeamAt6GeV << "\n";
        cout << "SimulationSample = " << SimulationSample << "\n";
        cout << "DataSample = " << DataSample << "\n";
        cout << "Exiting...\n", exit(0);
    }

    if (!SimulationSample && !DataSample)
    {
        cout << "\n\nConfigureSampleName: sample type configuration error! Configured variables are:\n";
        cout << "AnalyseFilePath = " << AnalyseFilePath << "\n";
        cout << "sName = " << sName << "\n";
        cout << "BeamAt2GeV = " << BeamAt2GeV << "\n";
        cout << "BeamAt4GeV = " << BeamAt4GeV << "\n";
        cout << "BeamAt6GeV = " << BeamAt6GeV << "\n";
        cout << "SimulationSample = " << SimulationSample << "\n";
        cout << "DataSample = " << DataSample << "\n";
        cout << "Exiting...\n", exit(0);
    }
    //</editor-fold>

    ConfigureVaryingSampleName(sName);
    ConfigureVz_cuts(sName);
    ConfiguredVz_cuts(sName);

    return sName;
}
//</editor-fold>

// ConfigureVaryingSampleName function -----------------------------------------------------------------------------------------------------------------------------------------

//<editor-fold desc="ConfigureVaryingSampleName function">
void ExperimentParameters::ConfigureVaryingSampleName(const string &sn)
{ // TODO: change this to VaryingSampleName of the appropriate data. currently the same for all data.
    if (findSubstring(sn, "sim") ||
        (findSubstring(sn, "Uniform") || findSubstring(sn, "iniform") ||
         findSubstring(sn, "Isotrop") || findSubstring(sn, "isotrop")))
    { // Sample is simulation
        //        VaryingSampleName = SampleName;
        VaryingSampleName = "C12x4_simulation_G18_Q204_6GeV";
    }
    else if (findSubstring(sn, "data"))
    { // Sample is data
        VaryingSampleName = "C12x4_simulation_G18_Q204_6GeV";

        cout << "\n====================================================================\n";
        cout << "\t\t\t\tVaryingSampleName is unifor to all samples!!!\n";
        cout << "\n====================================================================\n";

        // if (findSubstring(sn, "C12") && BeamAt6GeV) {
        //     VaryingSampleName = "C12x4_simulation_G18_Q204_6GeV";
        // } else {
        //     cout << "\n\n\nExperimentParameters::GetVaryingSampleName: no corresponding simulation sample! Exiting...\n", exit(0);
        // }
    }
    else
    {
        cout << "\n\n\nExperimentParameters::ConfigureVaryingSampleName: sample can't be configured! Exiting...\n", exit(0);
    }
}
//</editor-fold>

// ConfigureVz_cuts function -----------------------------------------------------------------------------------------------------------------------------------------

//<editor-fold desc="ConfigureVz_cuts function">
void ExperimentParameters::ConfigureVz_cuts(const string &sn)
{
    if (findSubstring(sn, "Uniform"))
    { // Sample is uniform simulation
        if (findSubstring(sn, "2070MeV"))
        {
            if (sn == "Uniform_1e_sample_2070MeV")
            {
                Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -10., 0.);
                Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -10., 0.);
                Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -5., -1.);
            }
            else if (sn == "Uniform_ep_sample_2070MeV")
            {
                Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -10., 0.);
                Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -10., 0.);
                Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -5., -1.);
            }
            else if (sn == "Uniform_en_sample_2070MeV")
            {
                Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -10., 0.);
                Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -10., 0.);
                Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -5., -1.);
            }
        }
        else if (findSubstring(sn, "4029MeV"))
        {
            if (sn == "Uniform_1e_sample_4029MeV")
            {
                Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
                Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -8., 3.);
                Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 2.);
            }
            else if (sn == "Uniform_ep_sample_4029MeV")
            {
                Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
                Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -8., 3.);
                Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 2.);
            }
            else if (sn == "Uniform_en_sample_4029MeV")
            {
                Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
                Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -8., 3.);
                Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 2.);
            }
        }
        else if (findSubstring(sn, "5986MeV"))
        {
            if (sn == "Uniform_1e_sample_5986MeV")
            {
                Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
                Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -8., 3.);
                Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 2.);
            }
            else if (sn == "Uniform_ep_sample_5986MeV")
            {
                Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
                Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -8., 3.);
                Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 2.);
            }
            else if (sn == "Uniform_en_sample_5986MeV")
            {
                Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
                Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -8., 3.);
                Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 2.);
            }
        }
    }
    else if (findSubstring(sn, "simulation"))
    { // Sample is simulation
        if (sn == "C12x4_simulation_G18_Q204_6GeV")
        { // 4-foil
            Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -8., 3.);
            Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 2.);
        }
        else if (sn == "C12_simulation_G18_Q204_6GeV")
        { // 1-foil
            Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -5, 5);
            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -5, 5);
            Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -2, 1);
        }
    }
    else if (findSubstring(sn, "data"))
    { // Sample is data
        if (sn == "Ar40_data_2GeV_run_015672")
        {
            Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -12., -3.);
            Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., -4.);
        }
        else if (sn == "Ar40_data_4GeV_run_015743")
        {
            Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -9., -2.);
            Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., -4.);
        }
        else if (sn == "Ar40_data_6GeV_run_015792")
        {
            Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -9., -2.);
            Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., -4.);
        }
        else if (sn == "C12_data_2GeV_run_015664")
        {
            Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -9., -1.);
            Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -4., 0.);
        }
        else if (sn == "C12_data_4GeV_run_015778")
        {
            Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -6., 1.);
            Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -4., -1.);
        }
        else if (sn == "D2_data_2GeV")
        {
            Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -10., 1.);
            Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 0.);
        }
        else if (sn == "D2_data_6GeV_run_015443")
        {
            Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -7., 3.);
            Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 1.);
        }
        else if (sn == "H1_data_2GeV_run_015634")
        {
            Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -11., 1.);
            Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 0.);
        }
        else if (sn == "H1_data_6GeV_run_015028")
        {
            Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -7., 1.);
            Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 1.);
        }
        else if (findSubstring(sn, "C12x4_data_6GeV_run_0151"))
        {
            if (findSubstring(sn, "C12x4_data_6GeV_run_015186"))
            { // 4-foil
                Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
                Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -7., 2.);
                Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 2.);
            }
            else if (findSubstring(sn, "C12x4_data_6GeV_run_015187"))
            { // 4-foil
                Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
                Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -7., 2.);
                Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 2.);
            }
            else if (findSubstring(sn, "C12x4_data_6GeV_run_015188"))
            { // 4-foil
                Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
                Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -8., 3.);
                //            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -7., 2.);
                Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 2.);
            }
            else
            {
                Vz_cuts = Vz_cuts_def;
                Vz_cuts_FD = Vz_cuts_FD_def;
                Vz_cuts_CD = Vz_cuts_CD_def;
            }
        }
        else if (sn == "C12x4_data_6GeV")
        { // Sample is data (full 4-foil run)
            Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -7., 2.);
            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -8., 3.);
            Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -7., 2.);
        }
        else if (sn == "LH2_data_6GeV_run_015032")
        {
            Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -15, 5);
            Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -15, 5);
            Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -15, 5);
        }
    }
    else
    {
        Vz_cuts = DSCuts("Vertex z component", "", "", "1e cut", 0, -5, 5);
        Vz_cuts_FD = DSCuts("Vertex z component", "FD", "", "1e cut", 0, -5, 5);
        Vz_cuts_CD = DSCuts("Vertex z component", "CD", "", "1e cut", 0, -5, 5);
    }
}
//</editor-fold>

// ConfigureVz_cuts function -----------------------------------------------------------------------------------------------------------------------------------------

//<editor-fold desc="ConfigureVz_cuts function">
void ExperimentParameters::ConfiguredVz_cuts(const string &sn)
{
    if (findSubstring(sn, "Uniform"))
    { // Sample is uniform simulation
        if (findSubstring(sn, "2070MeV"))
        {
            if (sn == "Uniform_1e_sample_2070MeV")
            {
                dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -9999, 9999);
                dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -9999, 9999);
                dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -9999, 9999);
            }
            else if (sn == "Uniform_ep_sample_2070MeV")
            {
                dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -4, 2);
                dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -4, 2);
                dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -1, 3);
            }
            else if (sn == "Uniform_en_sample_2070MeV")
            {
                dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -9999, 9999);
                dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -9999, 9999);
                dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -9999, 9999);
            }
        }
        else if (findSubstring(sn, "4029MeV"))
        {
            if (sn == "Uniform_1e_sample_4029MeV")
            {
                dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
                dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -5, 4);
                dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -5, 4);
            }
            else if (sn == "Uniform_ep_sample_4029MeV")
            {
                dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
                dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -5, 4);
                dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -5, 4);
            }
            else if (sn == "Uniform_en_sample_4029MeV")
            {
                dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
                dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -5, 4);
                dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -5, 4);
            }
        }
        else if (findSubstring(sn, "5986MeV"))
        {
            if (sn == "Uniform_1e_sample_5986MeV")
            {
                dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
                dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -5, 4);
                dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -5, 4);
            }
            else if (sn == "Uniform_ep_sample_5986MeV")
            {
                dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
                dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -5, 4);
                dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -5, 4);
            }
            else if (sn == "Uniform_en_sample_5986MeV")
            {
                dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
                dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -5, 4);
                dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -5, 4);
            }
        }
    }
    else if (findSubstring(sn, "simulation"))
    { // Sample is simulation
        if (sn == "C12x4_simulation_G18_Q204_6GeV")
        { // 4-foil
            dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
            dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -5, 4);
            dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -5, 4);
        }
        else if (sn == "C12_simulation_G18_Q204_6GeV")
        { // 1-foil
            dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
            dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -5, 4);
            dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -5, 4);
        }
    }
    else if (findSubstring(sn, "data"))
    { // Sample is data
        if (sn == "Ar40_data_2GeV_run_015672")
        {
            dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
            dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -4, 8);
            dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -2, 6);
        }
        else if (sn == "Ar40_data_4GeV_run_015743")
        {
            dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
            dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -8, 4);
            dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -4, 2);
        }
        else if (sn == "Ar40_data_6GeV_run_015792")
        {
            dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
            dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -8, 4);
            dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -4, 2);
        }
        else if (sn == "C12_data_2GeV_run_015664")
        {
            dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
            dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -3, 5);
            dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -2, 5);
        }
        else if (sn == "C12_data_4GeV_run_015778")
        {
            dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
            dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -6, 3);
            dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -4, 2);
        }
        else if (sn == "D2_data_2GeV")
        {
            dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
            dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -5, 7);
            dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -2, 5);
        }
        else if (sn == "D2_data_6GeV_run_015443")
        {
            dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
            dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -7, 3);
            dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -5, 3);
        }
        else if (sn == "H1_data_2GeV_run_015634")
        {
            dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
            dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -3, 6);
            dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -2, 5);
        }
        else if (sn == "H1_data_6GeV_run_015028")
        {
            dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
            dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -6, 2);
            dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -4, 2);
        }
        else if (findSubstring(sn, "C12x4_data_6GeV_run_0151"))
        {
            if (findSubstring(sn, "C12x4_data_6GeV_run_015186"))
            { // 4-foil
                dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
                dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -5, 4);
                dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -5, 4);
            }
            else if (findSubstring(sn, "C12x4_data_6GeV_run_015187"))
            { // 4-foil
                dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
                dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -5, 4);
                dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -5, 4);
            }
            else if (findSubstring(sn, "C12x4_data_6GeV_run_015188"))
            { // 4-foil
                dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
                dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -5, 4);
                dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -5, 4);
            }
            else
            {
                dVz_cuts = dVz_cuts_def;
                dVz_cuts_FD = dVz_cuts_FD_def;
                dVz_cuts_CD = dVz_cuts_CD_def;
            }
        }
        else if (sn == "C12x4_data_6GeV")
        { // Sample is data (full 4-foil run)
            dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -5, 4);
            dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -5, 4);
            dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -5, 4);
        }
        else if (sn == "LH2_data_6GeV_run_015032")
        {
            dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -8, 4);
            dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -8, 4);
            dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -8, 4);
        }
    }
    else
    {
        dVz_cuts = DSCuts("dVz", "", "", "1e cut", 0, -8, 4);
        dVz_cuts_FD = DSCuts("dVz", "FD", "", "1e cut", 0, -8, 4);
        dVz_cuts_CD = DSCuts("dVz", "CD", "", "1e cut", 0, -8, 4);
    }
}
//</editor-fold>

// ConfigureBeanEnergy function -----------------------------------------------------------------------------------------------------------------------------------------

//<editor-fold desc="ConfigureBeanEnergy function">
double ExperimentParameters::ConfigureBeanEnergy(const string &sn)
{
    double be;

    if (findSubstring(sn, "598636MeV") || findSubstring(sn, "598636mev") || findSubstring(sn, "598636") || findSubstring(sn, "5986MeV") ||
        findSubstring(sn, "5986mev") || findSubstring(sn, "5986") || findSubstring(sn, "6GeV") || findSubstring(sn, "6Gev") || findSubstring(sn, "6gev"))
    {
        be = 5.98636;
    }
    else if (findSubstring(sn, "402962MeV") || findSubstring(sn, "402962mev") || findSubstring(sn, "402962") || findSubstring(sn, "4029MeV") ||
             findSubstring(sn, "4029mev") || findSubstring(sn, "4029") || findSubstring(sn, "4GeV") || findSubstring(sn, "4Gev") || findSubstring(sn, "4gev"))
    {
        be = 4.02962;
    }
    else if (findSubstring(sn, "207052MeV") || findSubstring(sn, "207052mev") || findSubstring(sn, "207052") || findSubstring(sn, "2070MeV") ||
             findSubstring(sn, "2070mev") || findSubstring(sn, "2070") || findSubstring(sn, "2GeV") || findSubstring(sn, "2Gev") || findSubstring(sn, "2gev"))
    {
        be = 2.07052;
    }

    return be;
}
//</editor-fold>

// GetBeanEnergy function -----------------------------------------------------------------------------------------------------------------------------------------

//<editor-fold desc="GetBeanEnergy function">
double ExperimentParameters::GetBeanEnergy() { return BeanEnergy; }
//</editor-fold>

// AddToHipoChain function ----------------------------------------------------------------------------------------------------------------------------------------

//<editor-fold desc="Description">
void ExperimentParameters::AddToHipoChain(HipoChain &chain, const string &sn, const string &AnalyseFilePath, const string &AnalyseFileSample, const string &AnalyseFile)
{
    bool PrintOut = true;

    if (DataSample)
    {
        if (sn == "C12x4_data_6GeV")
        {
            if (AnalyseFileSample == "")
            {
                /* Data in cache/clas12/rg-m/production/pass1/6gev/Cx4/dst/recon */
                vector<string> Runs = {"015186", "015187", "015188", "015189", "015190", "015191", "015192", "015193", "015194", "015196", "015199", "015200", "015202",
                                       "015203", "015204", "015205", "015206", "015207", "015210", "015212", "015213", "015214", "015215", "015217", "015219", "015220",
                                       "015221", "015223", "015224", "015225", "015226", "015228", "015234", "015235", "015236", "015238", "015239", "015240", "015241",
                                       "015242", "015243", "015245", "015246", "015247", "015248", "015249", "015250", "015252", "015253", "015254", "015255", "015257",
                                       "015258", "015259", "015260", "015261", "015262", "015263", "015264", "015265", "015266", "015269", "015270", "015271", "015272",
                                       "015273", "015274", "015275", "015278", "015279", "015280", "015282", "015283", "015284", "015286", "015287", "015288", "015289",
                                       "015290", "015291", "015292", "015293", "015294", "015295", "015296", "015298", "015300", "015301", "015302", "015303", "015304",
                                       "015305", "015306", "015307", "015308", "015309", "015310", "015311", "015312", "015313", "015314", "015316", "015317"};

                for (int i = 0; i < Runs.size(); i++)
                {
                    string TempAnalyseFile = "/" + AnalyseFilePath + "/" + Runs.at(i) + "/*.hipo";
                    chain.Add(TempAnalyseFile.c_str());

                    if (PrintOut)
                    {
                        cout << TempAnalyseFile << " directory added to HipoChain!\n";
                    }
                }

                if (PrintOut)
                {
                    cout << "\n";
                }
            }
        }
        else if (sn == "D2_data_2GeV")
        {
            if (AnalyseFileSample == "")
            {
                /* Data in cache/clas12/rg-m/production/pass1/2gev/D/dst/recon */
                vector<string> Runs = {
                    "015567", "015573", "015578", "015583", "015590", "015595", "015602", "015608", "015613", "015618", "015624",
                    "015568", "015574", "015579", "015586", "015591", "015598", "015603", "015609", "015614", "015619", "015625",
                    "015569", "015575", "015580", "015587", "015592", "015599", "015604", "015610", "015615", "015620", "015626",
                    "015570", "015576", "015581", "015588", "015593", "015600", "015606", "015611", "015616", "015622", "015627",
                    "015572", "015577", "015582", "015589", "015594", "015601", "015607", "015612", "015617", "015623"};

                for (int i = 0; i < Runs.size(); i++)
                {
                    string TempAnalyseFile = "/" + AnalyseFilePath + "/" + Runs.at(i) + "/*.hipo";
                    chain.Add(TempAnalyseFile.c_str());

                    if (PrintOut)
                    {
                        cout << TempAnalyseFile << " directory added to HipoChain!\n";
                    }
                }

                if (PrintOut)
                {
                    cout << "\n";
                }
            }
        }
        else
        {
            chain.Add(AnalyseFile.c_str());
        }
    }
    else if (SimulationSample)
    {
        chain.Add(AnalyseFile.c_str());

        if (PrintOut)
        {
            cout << AnalyseFile << " directory added to HipoChain!\n\n";
        }
    }
}
//</editor-fold>
