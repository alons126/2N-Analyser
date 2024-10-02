#include <vector>

#ifndef ANALYSER_CODESETUP_H
#define ANALYSER_CODESETUP_H

#define MomResDebugMacro false
#define FullAnalyser true
#define IndependentCanvasPDF false

#include "../source/constants.h"
#include "../source/includes/CanvasPDF/CanvasPDF.h"
#include "../source/classes/Directories/Directories.cpp"
#include "../source/classes/ExperimentParameters/ExperimentParameters.cpp"
#include "../source/functions/GeneralFunctions.h"
#include "../source/functions/HistogramPlottingFunctions.h"
#include "../source/functions/quit.h"

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                         Code version                                                                                //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::string Ver = "DetSim testings";

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                    File & path definitions                                                                          //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/*
   Drives:
   * Storage (D:) = d
   * Alon's Passport (F:) = h
   * Alon's Portable (G:) = g
*/

// ======================================================================================================================================================================
// Path definitions
// ======================================================================================================================================================================

//<editor-fold desc="path definitions">
/* Histogram plots output directory */
const std::string WorkingDirectory = GetCurrentDirectory() + "/";
const std::string plots_path = "/lustre24/expphy/volatile/clas12/asportes/Analysis_output";
// const std::string plots_path = WorkingDirectory + "00_plots";

/* setup directory and directories */
const std::string SettingsDirectory = WorkingDirectory + "setup" + "/";

/* source directory and directories */
const std::string SourcesDirectory = WorkingDirectory + "source" + "/";
const std::string DataDirectory = SourcesDirectory + "data" + "/";
const std::string ACorrDirectory = DataDirectory + "AcceptanceCorrections" + "/";
const std::string AcceptanceMapsDirectory = DataDirectory + "AcceptanceMaps" + "/";
const std::string AcceptanceWeightsDirectory = DataDirectory + "AcceptanceWeights" + "/";
const std::string MomentumResolutionDirectory = DataDirectory + "NeutronResolution" + "/";
const std::string NucleonCutsDirectory = DataDirectory + "NucleonCuts" + "/";
const std::string PIDCutsDirectory = DataDirectory + "PIDCuts" + "/";

const std::string plots_TList_FileType = "_plots.root";
const std::string plots_TFile_FileType = "_plots.pdf";
const std::string log_file_name = "Run_log.txt";
const std::string plots_log_save_Directory = plots_path + "/" + log_file_name;
//</editor-fold>

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                 Samples in sample chain                                                                             //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

std::vector<std::string> AnalyseFilePath_v, AnalyseFileSample_v, AnalyseFileDir_v, AnalyseFile_v;
std::string AnalyseFilePath, AnalyseFileSample, AnalyseFileDir, AnalyseFile;

// file_name definition -------------------------------------------------------------------------------------------------------------------------------------------------

// std::string file_name = "12C_2222GeV_GTEST19_10b_00_000";
std::string file_name = "general_file";

// HIPO files for Q2 study ----------------------------------------------------------------------------------------------------------------------------------------------

void ConfigSampleChain()
{
    // ==================================================================================================================================================================
    // Data runs
    // ==================================================================================================================================================================

    // H1 ---------------------------------------------------------------------------------------------------------------------------------------------------------------

    // /* H1 2.07052GeV - run 015634 (ifarm DATA files - H1 DATA files) */
    // AnalyseFilePath = "cache/clas12/rg-m/production/pass1/2gev/H/dst/recon";
    // AnalyseFileSample = "015634";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all data files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // /* H1 4.02962GeV - run 015743 (ifarm DATA files - H1 DATA files) */
    // AnalyseFilePath = "cache/clas12/rg-m/production/pass1/4gev/Ar/dst/recon";
    // AnalyseFileSample = "015743";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all run files

    // /* H1 5.98636GeV - run 015028 (ifarm DATA files - H1 DATA files) */
    // AnalyseFilePath = "cache/clas12/rg-m/production/pass1/6gev/H/dst/recon";
    // AnalyseFileSample = "015028";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all run files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // D2 ---------------------------------------------------------------------------------------------------------------------------------------------------------------

    // /* D2 2.07052GeV - all runs (ifarm DATA files - D2 DATA files) */
    // AnalyseFilePath = "cache/clas12/rg-m/production/pass1/2gev/D/dst/recon";
    // AnalyseFileSample = "";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all data files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // /* D2 4.02962GeV - run 015743 (ifarm DATA files - D2 DATA files) */
    // AnalyseFilePath = "cache/clas12/rg-m/production/pass1/4gev/Ar/dst/recon";
    // AnalyseFileSample = "015743";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all run files

    // /* D2 5.98636GeV - run 015443 (ifarm DATA files - D2 DATA files) */
    // AnalyseFilePath = "cache/clas12/rg-m/production/pass1/6gev/D/dst/recon";
    // AnalyseFileSample = "015443";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all run files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // C12 --------------------------------------------------------------------------------------------------------------------------------------------------------------

    // /* C12 2.07052GeV - run 015664 (ifarm DATA files - C12 DATA files) */
    // AnalyseFilePath = "cache/clas12/rg-m/production/pass1/2gev/C/dst/recon";
    // AnalyseFileSample = "015664";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all run files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // /* C12 4.02962GeV - run 015778 (ifarm DATA files - C12 DATA files) */
    // AnalyseFilePath = "cache/clas12/rg-m/production/pass1/4gev/C/dst/recon";
    // AnalyseFileSample = "015778";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all run files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // /* C12x4 5.98636GeV - run 015188 (ifarm DATA files - C12x4 DATA files) */
    // AnalyseFilePath = "cache/clas12/rg-m/production/pass1/6gev/Cx4/dst/recon";
    // AnalyseFileSample = "015188";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "rec_clas_015188.evio.01685-01689.hipo"; // 1 run file
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all run files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // Ar40 -------------------------------------------------------------------------------------------------------------------------------------------------------------

    // /* Ar40 2.07052GeV - run 015672 (ifarm DATA files - Ar40 DATA files) */
    // AnalyseFilePath = "cache/clas12/rg-m/production/pass1/2gev/Ar/dst/recon";
    // AnalyseFileSample = "015672";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all run files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // /* Ar40 4.02962GeV - run 015743 (ifarm DATA files - Ar40 DATA files) */
    // AnalyseFilePath = "cache/clas12/rg-m/production/pass1/4gev/Ar/dst/recon";
    // AnalyseFileSample = "015743";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all run files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // /* Ar40 5.98636GeV - run 015792 (ifarm DATA files - Ar40 DATA files) */
    // AnalyseFilePath = "cache/clas12/rg-m/production/pass1/6gev/Ar/dst/recon";
    // AnalyseFileSample = "015792";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all run files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // ==================================================================================================================================================================
    // Uniform simulation files
    // ==================================================================================================================================================================
    // These samples were used to generate the acceptance maps

    // Electron tester samples ------------------------------------------------------------------------------------------------------------------------------------------

    // /* Uniform electron tester sample @ 2GeV */
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_e_tester_1e";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo";
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // /* Uniform electron tester sample @ 4GeV */
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut_e_tester_1e";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo";
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // /* Uniform electron tester sample @ 6GeV */
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut_e_tester_1e";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo";
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // Uniform samples --------------------------------------------------------------------------------------------------------------------------------------------------

    /* Uniform sample @ 2GeV */

    // // Uniform 1e @ 2GeV:
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_1e";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // Uniform ep @ 2GeV:
    AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_ep";
    AnalyseFileSample = "reconhipo";
    AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "recon_Uniform_ep_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    AnalyseFilePath_v.push_back(AnalyseFilePath);
    AnalyseFileSample_v.push_back(AnalyseFileSample);
    AnalyseFileDir_v.push_back(AnalyseFileDir);
    AnalyseFile_v.push_back(AnalyseFile);

    // // Uniform en @ 2GeV:
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_en";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_en_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // /* Uniform sample @ 4GeV */

    // // Uniform 1e @ 4GeV:
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut_1e";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_4029MeV_1000_torus-1.0.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // // Uniform ep @ 4GeV:
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut_ep";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_ep_sample_4029MeV_1000_torus-1.0.hipo"; // 1 file
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_ep_sample_4029MeV_255_torus-1.0.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // // Uniform en @ 4GeV:
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut_en";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_en_sample_4029MeV_1000_torus-1.0.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // /* Uniform sample @ 6GeV */

    // // Uniform 1e @ 6GeV:
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut_1e";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_5986MeV_1000_torus-1.0.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // // Uniform ep @ 6GeV:
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut_ep";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_ep_sample_5986MeV_1000_torus-1.0.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // // Uniform en @ 6GeV:
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut_en";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_en_sample_5986MeV_1000_torus-1.0.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // Small Q2 test samples --------------------------------------------------------------------------------------------------------------------------------------------

    /* G18 Q2 4GeV */

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_02";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_03";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_04";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_05";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_06";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_07";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_08";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_09";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_10";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_11";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_12";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_13";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_14";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_15";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_16";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_17";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_18";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_19";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_20";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_21";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_22";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_23";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_24";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_25";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_26";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_27";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_28";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_29";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_30";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_31";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_32";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_33";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_34";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_35";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_36";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_37";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_38";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_39";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/4029MeV/Q2_0_40";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    /* SuSa Q2 4GeV */

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_02";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_03";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_04";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_05";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_06";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_07";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_08";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_09";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_10";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_11";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_12";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_13";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_14";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_15";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_16";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_17";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_18";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_19";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_20";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_21";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_22";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_23";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_24";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_25";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_26";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_27";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_28";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_29";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_30";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_31";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_32";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_33";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_34";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_35";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_36";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_37";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_38";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_39";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/4029MeV/Q2_0_40";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    /* G18 Q2 6GeV */

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_40";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_41";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_42";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_43";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_44";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_45";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_46";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_47";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_48";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_49";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_50";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_51";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_52";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_53";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_54";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_55";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_56";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_57";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_58";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_59";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_60";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_61";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_62";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_63";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_64";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_65";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_66";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_67";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_68";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_69";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_70";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_71";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_72";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_73";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_74";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_75";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_76";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_77";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_78";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_79";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/G18_10a_00_000/Q2_th_test_samples/5986MeV/Q2_0_80";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    /* SuSs Q2 6GeV */

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_40";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_41";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_42";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_43";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_44";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_45";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_46";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_47";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_48";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_49";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_50";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_51";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_52";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_53";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_54";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_55";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_56";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_57";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_58";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_59";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_60";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_61";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_62";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_63";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_64";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_65";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_66";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_67";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_68";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_69";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_70";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_71";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_72";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_73";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_74";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_75";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_76";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_77";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_78";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_79";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/2N_Analysis_Reco_Samples/C12/GEM21_11a_00_000/Q2_th_test_samples/5986MeV/Q2_0_80";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // // AnalyseFile = AnalyseFileDir + "recon_Uniform_1e_sample_2070MeV_1000_torus0.5.hipo"; // 1 file
    // AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);

    // ==================================================================================================================================================================
    // Old simulation files for local runs
    // ==================================================================================================================================================================

    /* Local hipo files - Uniform sample @ 6GeV */
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/598636MeV"; // Storage (D:)
    // AnalyseFileSample = "reconhipo";                                                               // my test with Justin's code; all particle data saved
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "recon_Uniform_sample_598636MeV_*.hipo";                        // 11 files

    //  AnalyseFilePath = "mnt/d/e4nu/hipo_data_files";                                              // Storage (D:)
    // //AnalyseFilePath = "mnt/h/e4nu/hipo_data_files";                                              // Alon's Passport (F:)
    // //AnalyseFilePath = "mnt/g/e4nu/hipo_data_files";                                              // Alon's Portable (G:)
    //  AnalyseFileSample = "C12x4_G18_02a_00_000_Q204_598636MeV";                                   // my test with Justin's code; all particle data saved
    //  AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // //AnalyseFile = AnalyseFileDir + "*.hipo";
    // //AnalyseFile = AnalyseFileDir + "recon_C12x4_G18_02a_00_000_Q204_598636MeV_9_torus-1.0.hipo"; // 1 file
    //  AnalyseFile = AnalyseFileDir + "recon_C12x4_G18_02a_00_000_Q204_598636MeV_51*.hipo";         // 11 files
    // //AnalyseFile = AnalyseFileDir + "recon_C12x4_G18_02a_00_000_Q204_598636MeV_5*.hipo";          // 111 files
    // //AnalyseFile = AnalyseFileDir + "recon_C12x4_G18_02a_00_000_Q204_598636MeV_2*.hipo";          // 512 files

    // ==================================================================================================================================================================
    // Other ROOT files
    // ==================================================================================================================================================================

    //////<editor-fold desc="root files">
    // AnalyseFilePath = "home/alon/project";
    // AnalyseFileSample = "Downloads";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "/" + "12C_2222GeV_GEM21_11a_00_000_wfsi_mk2.root";
    ////AnalyseFile = AnalyseFileDir + "/" + "e_on_1000060120_2222MeV_em.gst.root";
    ////AnalyseFile = "./e_on_1000060120_598636MeV.gst.root";

    ////<editor-fold desc="SuSAv2 fix for thesis">
    // AnalyseFilePath = "home/alon/project";
    // AnalyseFileSample = "Downloads";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    ////AnalyseFile = AnalyseFileDir + "/" + "12C_2222GeV_GTEST19_10b_00_000.root"; // Original problem
    // AnalyseFile = AnalyseFileDir + "/" + "e_on_1000060120_EMMEC_test_myBranch.root"; // Initial fix with 1M events (myBranch)
    ////</editor-fold>

    // AnalyseFilePath = "mnt/d/e4nu/hipo_data_files";
    // AnalyseFileSample = "recon_qe_GENIE_C_598636MeV_Q2_0_4_test_1";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";

    // AnalyseFilePath = "home/alon/project";
    // AnalyseFileSample = "Downloads";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "e_on_1000060120_2222MeV_em.gst.root";

    // AnalyseFileSample = "recon_qe_GENIE_C_598636MeV_Q2_0_4_test_1";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/" + "first_50_test" + "/";

    // AnalyseFilePath = "pnfs/genie/scratch/users/asportes/script_jobs/detector_sim_truth_level";
    // AnalyseFileSample = "detector_sim_truth_level/C12_G18_10a_02_11b_2GeV_QEL_test";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    ////AnalyseFile = AnalyseFileDir + "Ca48_G18_10a_02_11b_207052MeV.root";
    // AnalyseFile = AnalyseFileDir + "e_on_1000060120_2070MeV.root";

    // AnalyseFilePath = "home/alon/project";
    // AnalyseFileSample = "Downloads";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    ////AnalyseFile = AnalyseFileDir + "Ca48_G18_10a_02_11b_207052MeV.root";
    // AnalyseFile = AnalyseFileDir + "Ca48_G18_10a_02_11b_Q205_598636MeV.root";

    // AnalyseFilePath = "lustre19/expphy/volatile/clas12/asportes/truthLevelROOTFiles";
    // AnalyseFileSample = "C12_G18_10a_02_11b_207052MeV";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "C12_G18_10a_02_11b_207052MeV.root";

    // AnalyseFilePath = "mnt/d/e4nu/root_data_files/Detector_sim_truth_level_files";
    // AnalyseFileSample = "598636MeV_Q2_0_5";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    //
    ////AnalyseFile = AnalyseFileDir + "e_on_1000060120_598636MeV_Q2_0_5.gst.root";
    ////AnalyseFile = "./nu_SuSAv2_fix_test_12C_2222GeV_CC_myBranch_10M.root";
    // AnalyseFile = "./nu_SuSAv2_fix_test_12C_2222GeV_CCMEC_myBranch_10M.root";
}

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//                                                                    Other parameters                                                                                 //
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

//<editor-fold desc="Other parameters">

// ======================================================================================================================================================================
// BEnergyToNucleus definition
// ======================================================================================================================================================================

double BEnergyToNucleus;

// ======================================================================================================================================================================
// Simulation parameters extraction
// ======================================================================================================================================================================

int Target_pdg, Probe_pdg;
std::string Target_nucleus, Probe;
double BeamEnergy;

// ======================================================================================================================================================================
// Histogram ranges
// ======================================================================================================================================================================

//<editor-fold desc="Histogram range variables">

////<editor-fold desc="Chi2 plots">
// double Chi2_upper_lim, Chi2_lower_lim;
////</editor-fold>

//<editor-fold desc="Vertex plots">
double Vertex_upper_lim, Vertex_lower_lim, dV_upper_lim, dV_lower_lim;
//</editor-fold>

//<editor-fold desc="Theta histograms">

//<editor-fold desc="Theta histograms (2p)">
double theta_lp_upper_lim_2p, theta_lp_lower_lim_2p, theta_p1_upper_lim_2p, theta_p1_lower_lim_2p, theta_p2_upper_lim_2p, theta_p2_lower_lim_2p;
double dtheta_upper_lim_2p, dtheta_lower_lim_2p;
//</editor-fold>

//<editor-fold desc="Theta histograms (1n1p)">
double theta_lp_upper_lim_1n1p, theta_lp_lower_lim_1n1p, theta_p_upper_lim_1n1p, theta_p_lower_lim_1n1p, theta_n_upper_lim_1n1p, theta_n_lower_lim_1n1p;
double dtheta_upper_lim_1n1p, dtheta_lower_lim_1n1p;
//</editor-fold>

//</editor-fold>

//<editor-fold desc="Phi histograms">

//<editor-fold desc="Phi histograms (2p)">
double phi_lp_upper_lim_2p, phi_lp_lower_lim_2p, phi_p1_upper_lim_2p, phi_p1_lower_lim_2p, phi_p2_upper_lim_2p, phi_p2_lower_lim_2p;
double dphi_upper_lim_2p, dphi_lower_lim_2p;
//</editor-fold>

//<editor-fold desc="Phi histograms (1n1p)">
double phi_lp_upper_lim_1n1p, phi_lp_lower_lim_1n1p, phi_p_upper_lim_1n1p, phi_p_lower_lim_1n1p, phi_n_upper_lim_1n1p, phi_n_lower_lim_1n1p;
double dphi_upper_lim_1n1p, dphi_lower_lim_1n1p;
//</editor-fold>

//</editor-fold>

//<editor-fold desc="Energy histograms">

//<editor-fold desc="Energy histograms (2p)">
double fsEl_upper_lim_2p, fsEl_lower_lim_2p;
double fsEl_QEL_upper_lim_2p, fsEl_QEL_lower_lim_2p, fsEl_MEC_upper_lim_2p, fsEl_MEC_lower_lim_2p;
double fsEl_RES_upper_lim_2p, fsEl_RES_lower_lim_2p, fsEl_DIS_upper_lim_2p, fsEl_DIS_lower_lim_2p;
double fsEl_VS_theta_lp_upper_lim_2p_x, fsEl_VS_theta_lp_lower_lim_2p_x, fsEl_VS_theta_lp_upper_lim_2p_y, fsEl_VS_theta_lp_lower_lim_2p_y;
//</editor-fold>

//<editor-fold desc="Energy histograms (1n1p)">
double fsEl_upper_lim_1n1p, fsEl_lower_lim_1n1p;
double fsEl_QEL_upper_lim_1n1p, fsEl_QEL_lower_lim_1n1p, fsEl_MEC_upper_lim_1n1p, fsEl_MEC_lower_lim_1n1p;
double fsEl_RES_upper_lim_1n1p, fsEl_RES_lower_lim_1n1p, fsEl_DIS_upper_lim_1n1p, fsEl_DIS_lower_lim_1n1p;
double fsEl_VS_theta_lp_upper_lim_1n1p_x, fsEl_VS_theta_lp_lower_lim_1n1p_x, fsEl_VS_theta_lp_upper_lim_1n1p_y, fsEl_VS_theta_lp_lower_lim_1n1p_y;
//</editor-fold>

//</editor-fold>

//<editor-fold desc="Energy Transfer histograms">

//<editor-fold desc="Energy Transfer histograms (all interactions)">

//<editor-fold desc="Energy Transfer histograms (all interactions, 2p)">
double E_Trans_all_ang_all_int_upper_lim_2p, E_Trans_all_ang_all_int_lower_lim_2p;
double E_Trans15_all_upper_lim_2p, E_Trans15_all_lower_lim_2p, E_Trans45_all_upper_lim_2p, E_Trans45_all_lower_lim_2p, E_Trans90_all_upper_lim_2p, E_Trans90_all_lower_lim_2p;
//</editor-fold>

//<editor-fold desc="Energy Transfer histograms (all interactions, 1n1p)">
double E_Trans_all_ang_all_int_upper_lim_1n1p, E_Trans_all_ang_all_int_lower_lim_1n1p;
double E_Trans15_all_upper_lim_1n1p, E_Trans15_all_lower_lim_1n1p, E_Trans45_all_upper_lim_1n1p, E_Trans45_all_lower_lim_1n1p, E_Trans90_all_upper_lim_1n1p, E_Trans90_all_lower_lim_1n1p;
//</editor-fold>

//</editor-fold>

//<editor-fold desc="Energy Transfer histograms (QEL only)">

//<editor-fold desc="Energy Transfer histograms (QEL only, 2p)">
double E_Trans15_QEL_upper_lim_2p, E_Trans15_QEL_lower_lim_2p, E_Trans45_QEL_upper_lim_2p, E_Trans45_QEL_lower_lim_2p, E_Trans90_QEL_upper_lim_2p, E_Trans90_QEL_lower_lim_2p;
//</editor-fold>

//<editor-fold desc="Energy Transfer histograms (QEL only, 1n1p)">
double E_Trans15_QEL_upper_lim_1n1p, E_Trans15_QEL_lower_lim_1n1p, E_Trans45_QEL_upper_lim_1n1p, E_Trans45_QEL_lower_lim_1n1p, E_Trans90_QEL_upper_lim_1n1p, E_Trans90_QEL_lower_lim_1n1p;
//</editor-fold>

//</editor-fold>

//<editor-fold desc="Energy Transfer histograms (MEC only)">

//<editor-fold desc="Energy Transfer histograms (MEC only, 2p)">
double E_Trans15_MEC_upper_lim_2p, E_Trans15_MEC_lower_lim_2p, E_Trans45_MEC_upper_lim_2p, E_Trans45_MEC_lower_lim_2p, E_Trans90_MEC_upper_lim_2p, E_Trans90_MEC_lower_lim_2p;
//</editor-fold>

//<editor-fold desc="Energy Transfer histograms (MEC only, 1n1p)">
double E_Trans15_MEC_upper_lim_1n1p, E_Trans15_MEC_lower_lim_1n1p, E_Trans45_MEC_upper_lim_1n1p, E_Trans45_MEC_lower_lim_1n1p, E_Trans90_MEC_upper_lim_1n1p, E_Trans90_MEC_lower_lim_1n1p;
//</editor-fold>

//</editor-fold>

//<editor-fold desc="Energy Transfer histograms (RES only)">

//<editor-fold desc="Energy Transfer histograms (RES only, 2p)">
double E_Trans15_RES_upper_lim_2p, E_Trans15_RES_lower_lim_2p, E_Trans45_RES_upper_lim_2p, E_Trans45_RES_lower_lim_2p, E_Trans90_RES_upper_lim_2p, E_Trans90_RES_lower_lim_2p;
//</editor-fold>

//<editor-fold desc="Energy Transfer histograms (RES only, 1n1p)">
double E_Trans15_RES_upper_lim_1n1p, E_Trans15_RES_lower_lim_1n1p, E_Trans45_RES_upper_lim_1n1p, E_Trans45_RES_lower_lim_1n1p, E_Trans90_RES_upper_lim_1n1p, E_Trans90_RES_lower_lim_1n1p;
//</editor-fold>

//</editor-fold>

//<editor-fold desc="Energy Transfer histograms (DIS only)">

//<editor-fold desc="Energy Transfer histograms (DIS only, 2p)">
double E_Trans15_DIS_upper_lim_2p, E_Trans15_DIS_lower_lim_2p, E_Trans45_DIS_upper_lim_2p, E_Trans45_DIS_lower_lim_2p, E_Trans90_DIS_upper_lim_2p, E_Trans90_DIS_lower_lim_2p;
//</editor-fold>

//<editor-fold desc="Energy Transfer histograms (DIS only, 1n1p)">
double E_Trans15_DIS_upper_lim_1n1p, E_Trans15_DIS_lower_lim_1n1p, E_Trans45_DIS_upper_lim_1n1p, E_Trans45_DIS_lower_lim_1n1p, E_Trans90_DIS_upper_lim_1n1p, E_Trans90_DIS_lower_lim_1n1p;
//</editor-fold>

//</editor-fold>

//</editor-fold>

//<editor-fold desc="Inclusive Energy Transfer histograms">
double E_Trans15_all_inclusive_upper_lim, E_Trans15_all_inclusive_lower_lim;
double E_Trans15_QEL_inclusive_upper_lim, E_Trans15_QEL_inclusive_lower_lim, E_Trans15_MEC_inclusive_upper_lim, E_Trans15_MEC_inclusive_lower_lim;
double E_Trans15_RES_inclusive_upper_lim, E_Trans15_RES_inclusive_lower_lim, E_Trans15_DIS_inclusive_upper_lim, E_Trans15_DIS_inclusive_lower_lim;
double E_Trans_VS_q_all_inclusive_upper_lim_x, E_Trans_VS_q_all_inclusive_lower_lim_x, E_Trans_VS_q_all_inclusive_upper_lim_y, E_Trans_VS_q_all_inclusive_lower_lim_y;
double E_Trans_VS_q_QEL_inclusive_upper_lim_x, E_Trans_VS_q_QEL_inclusive_lower_lim_x, E_Trans_VS_q_QEL_inclusive_upper_lim_y, E_Trans_VS_q_QEL_inclusive_lower_lim_y;
double E_Trans_VS_q_MEC_inclusive_upper_lim_x, E_Trans_VS_q_MEC_inclusive_lower_lim_x, E_Trans_VS_q_MEC_inclusive_upper_lim_y, E_Trans_VS_q_MEC_inclusive_lower_lim_y;

double E_Trans_VS_q3_all_upper_lim_x_2p, E_Trans_VS_q3_all_lower_lim_x_2p, E_Trans_VS_q3_all_upper_lim_y_2p, E_Trans_VS_q3_all_lower_lim_y_2p;
double E_Trans_VS_q3_QEL_upper_lim_x_2p, E_Trans_VS_q3_QEL_lower_lim_x_2p, E_Trans_VS_q3_QEL_upper_lim_y_2p, E_Trans_VS_q3_QEL_lower_lim_y_2p;
double E_Trans_VS_q3_MEC_upper_lim_x_2p, E_Trans_VS_q3_MEC_lower_lim_x_2p, E_Trans_VS_q3_MEC_upper_lim_y_2p, E_Trans_VS_q3_MEC_lower_lim_y_2p;

double E_Trans_VS_q3_all_upper_lim_x_1n1p, E_Trans_VS_q3_all_lower_lim_x_1n1p, E_Trans_VS_q3_all_upper_lim_y_1n1p, E_Trans_VS_q3_all_lower_lim_y_1n1p;
double E_Trans_VS_q3_QEL_upper_lim_x_1n1p, E_Trans_VS_q3_QEL_lower_lim_x_1n1p, E_Trans_VS_q3_QEL_upper_lim_y_1n1p, E_Trans_VS_q3_QEL_lower_lim_y_1n1p;
double E_Trans_VS_q3_MEC_upper_lim_x_1n1p, E_Trans_VS_q3_MEC_lower_lim_x_1n1p, E_Trans_VS_q3_MEC_upper_lim_y_1n1p, E_Trans_VS_q3_MEC_lower_lim_y_1n1p;
//</editor-fold>

//<editor-fold desc="E_cal restoration histograms">

//<editor-fold desc="E_cal range">
double E_cal_QEL_upper_lim_range, E_cal_QEL_lower_lim_range, E_cal_MEC_upper_lim_range, E_cal_MEC_lower_lim_range;
double E_cal_RES_upper_lim_range, E_cal_RES_lower_lim_range, E_cal_DIS_upper_lim_range, E_cal_DIS_lower_lim_range;
//</editor-fold>

//<editor-fold desc="E_cal restoration histograms (2p)">
double E_cal_QEL_upper_lim_2p, E_cal_QEL_lower_lim_2p, E_cal_MEC_upper_lim_2p, E_cal_MEC_lower_lim_2p;
double E_cal_RES_upper_lim_2p, E_cal_RES_lower_lim_2p, E_cal_DIS_upper_lim_2p, E_cal_DIS_lower_lim_2p;
//</editor-fold>

//<editor-fold desc="E_cal restoration histograms (1n1p)">
double E_cal_QEL_upper_lim_1n1p, E_cal_QEL_lower_lim_1n1p, E_cal_MEC_upper_lim_1n1p, E_cal_MEC_lower_lim_1n1p;
double E_cal_RES_upper_lim_1n1p, E_cal_RES_lower_lim_1n1p, E_cal_DIS_upper_lim_1n1p, E_cal_DIS_lower_lim_1n1p;
//</editor-fold>

//</editor-fold>

//<editor-fold desc="Momentum histograms">

//<editor-fold desc="Momentum histograms (2p)">
double P_L_hist_upper_lim_2p, P_L_hist_lower_lim_2p, P_R_hist_upper_lim_2p, P_R_hist_lower_lim_2p, P_lp_hist_upper_lim_2p, P_lp_hist_lower_lim_2p;
//</editor-fold>

//<editor-fold desc="Momentum histograms (1n1p)">
double P_p_hist_upper_lim_1n1p, P_p_hist_lower_lim_1n1p, P_n_hist_upper_lim_1n1p, P_n_hist_lower_lim_1n1p, P_lp_hist_upper_lim_1n1p, P_lp_hist_lower_lim_1n1p;
//</editor-fold>

//</editor-fold>

//<editor-fold desc="MicroBooNE plots">

//<editor-fold desc="MicroBooNE gamma plots (unweighted)">
double Gamma_Lab_upper_lim, Gamma_Lab_lower_lim, Gamma_mu_p_tot_upper_lim, Gamma_mu_p_tot_lower_lim;
//</editor-fold>

//<editor-fold desc="MicroBooNE gamma plots (Q4 weighted)">
double Gamma_Lab_weighted_upper_lim, Gamma_Lab_weighted_lower_lim, Gamma_mu_p_tot_weighted_upper_lim, Gamma_mu_p_tot_weighted_lower_lim;
//</editor-fold>

//<editor-fold desc="MicroBooNE gamma plots (all int., no pions)">
double Gamma_Lab_noPions_All_Int_upper_lim, Gamma_Lab_noPions_All_Int_lower_lim, Gamma_Lab_noPions_All_Int_weighted_upper_lim, Gamma_Lab_noPions_All_Int_weighted_lower_lim;
double Gamma_Lab_noPions_QEL_upper_lim, Gamma_Lab_noPions_QEL_lower_lim, Gamma_Lab_noPions_QEL_weighted_upper_lim, Gamma_Lab_noPions_QEL_weighted_lower_lim;
double Gamma_Lab_noPions_MEC_upper_lim, Gamma_Lab_noPions_MEC_lower_lim, Gamma_Lab_noPions_MEC_weighted_upper_lim, Gamma_Lab_noPions_MEC_weighted_lower_lim;
double Gamma_Lab_noPions_RES_upper_lim, Gamma_Lab_noPions_RES_lower_lim, Gamma_Lab_noPions_RES_weighted_upper_lim, Gamma_Lab_noPions_RES_weighted_lower_lim;
double Gamma_Lab_noPions_DIS_upper_lim, Gamma_Lab_noPions_DIS_lower_lim, Gamma_Lab_noPions_DIS_weighted_upper_lim, Gamma_Lab_noPions_DIS_weighted_lower_lim;
//</editor-fold>

//<editor-fold desc="MicroBooNE dP_T plots">
double dP_T_hist_upper_lim, dP_T_hist_lower_lim, dP_T_hist_weighted_upper_lim, dP_T_hist_weighted_lower_lim;
//</editor-fold>

//<editor-fold desc="MicroBooNE momentum plots (for self-examination)">
double P_L_hist_upper_lim, P_L_hist_lower_lim, P_R_hist_upper_lim, P_R_hist_lower_lim, P_lp_hist_upper_lim, P_lp_hist_lower_lim, P_pion_hist_upper_lim, P_pion_hist_lower_lim;
//</editor-fold>

//</editor-fold>

//</editor-fold>

//</editor-fold>

#endif // ANALYSER_CODESETUP_H
