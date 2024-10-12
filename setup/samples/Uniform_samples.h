#include <vector>

#ifndef UNIFORM_SAMPLES
#define UNIFORM_SAMPLES

#pragma region Uniform electron tester samples
/* Uniform electron tester samples */
void Config_Uniform_tester_e_samples(std::vector<std::string> &AnalyseFilePath_v, std::vector<std::string> &AnalyseFileSample_v,
                                     std::vector<std::string> &AnalyseFileDir_v, std::vector<std::string> &AnalyseFile_v,
                                     std::string &AnalyseFilePath, std::string &AnalyseFileSample, std::string &AnalyseFileDir, std::string &AnalyseFile)
{
    /* Uniform electron tester sample @ 2GeV */
    AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_Tester_e_1e";
    AnalyseFileSample = "reconhipo";
    AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    AnalyseFile = AnalyseFileDir + "*.hipo";
    AnalyseFilePath_v.push_back(AnalyseFilePath);
    AnalyseFileSample_v.push_back(AnalyseFileSample);
    AnalyseFileDir_v.push_back(AnalyseFileDir);
    AnalyseFile_v.push_back(AnalyseFile);

    /* Uniform electron tester sample @ 4GeV */
    AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut_Tester_e_1e";
    AnalyseFileSample = "reconhipo";
    AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    AnalyseFile = AnalyseFileDir + "*.hipo";
    AnalyseFilePath_v.push_back(AnalyseFilePath);
    AnalyseFileSample_v.push_back(AnalyseFileSample);
    AnalyseFileDir_v.push_back(AnalyseFileDir);
    AnalyseFile_v.push_back(AnalyseFile);

    /* Uniform electron tester sample @ 6GeV */
    AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut_Tester_e_1e";
    AnalyseFileSample = "reconhipo";
    AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    AnalyseFile = AnalyseFileDir + "*.hipo";
    AnalyseFilePath_v.push_back(AnalyseFilePath);
    AnalyseFileSample_v.push_back(AnalyseFileSample);
    AnalyseFileDir_v.push_back(AnalyseFileDir);
    AnalyseFile_v.push_back(AnalyseFile);
}
#pragma endregion

#pragma region Uniform samples @ 2GeV
/* Uniform samples @ 2GeV */

/* Uniform 1e @ 2GeV */
void Config_Uniform_1e_2GeV_samples(std::vector<std::string> &AnalyseFilePath_v, std::vector<std::string> &AnalyseFileSample_v,
                                    std::vector<std::string> &AnalyseFileDir_v, std::vector<std::string> &AnalyseFile_v,
                                    std::string &AnalyseFilePath, std::string &AnalyseFileSample, std::string &AnalyseFileDir, std::string &AnalyseFile)
{
    AnalyseFilePath_v.push_back("lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_1e");
    AnalyseFileSample_v.push_back("reconhipo");
    AnalyseFileDir_v.push_back("/" + AnalyseFilePath + "/" + AnalyseFileSample + "/");
    AnalyseFile_v.push_back(AnalyseFileDir + "*.hipo"); // all files
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_1e";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);
}

/* Uniform en @ 2GeV */
void Config_Uniform_en_2GeV_samples(std::vector<std::string> &AnalyseFilePath_v, std::vector<std::string> &AnalyseFileSample_v,
                                    std::vector<std::string> &AnalyseFileDir_v, std::vector<std::string> &AnalyseFile_v,
                                    std::string &AnalyseFilePath, std::string &AnalyseFileSample, std::string &AnalyseFileDir, std::string &AnalyseFile)
{
    AnalyseFilePath_v.push_back("lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_en");
    AnalyseFileSample_v.push_back("reconhipo");
    AnalyseFileDir_v.push_back("/" + AnalyseFilePath + "/" + AnalyseFileSample + "/");
    AnalyseFile_v.push_back(AnalyseFileDir + "*.hipo"); // all files
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_en";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);
}

/* Uniform ep @ 2GeV */
void Config_Uniform_ep_2GeV_samples(std::vector<std::string> &AnalyseFilePath_v, std::vector<std::string> &AnalyseFileSample_v,
                                    std::vector<std::string> &AnalyseFileDir_v, std::vector<std::string> &AnalyseFile_v,
                                    std::string &AnalyseFilePath, std::string &AnalyseFileSample, std::string &AnalyseFileDir, std::string &AnalyseFile)
{
    AnalyseFilePath_v.push_back("lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_ep");
    AnalyseFileSample_v.push_back("reconhipo");
    AnalyseFileDir_v.push_back("/" + AnalyseFilePath + "/" + AnalyseFileSample + "/");
    AnalyseFile_v.push_back(AnalyseFileDir + "*.hipo"); // all files
    // AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/2070MeV/OutPut_ep";
    // AnalyseFileSample = "reconhipo";
    // AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    // AnalyseFile = AnalyseFileDir + "*.hipo"; // all files
    // AnalyseFilePath_v.push_back(AnalyseFilePath);
    // AnalyseFileSample_v.push_back(AnalyseFileSample);
    // AnalyseFileDir_v.push_back(AnalyseFileDir);
    // AnalyseFile_v.push_back(AnalyseFile);
}
#pragma endregion

#pragma region Uniform samples @ 4GeV
/* Uniform samples @ 4GeV */

/* Uniform 1e @ 4GeV */
void Config_Uniform_1e_4GeV_samples(std::vector<std::string> &AnalyseFilePath_v, std::vector<std::string> &AnalyseFileSample_v,
                                    std::vector<std::string> &AnalyseFileDir_v, std::vector<std::string> &AnalyseFile_v,
                                    std::string &AnalyseFilePath, std::string &AnalyseFileSample, std::string &AnalyseFileDir, std::string &AnalyseFile)
{
    AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut_1e";
    AnalyseFileSample = "reconhipo";
    AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    AnalyseFilePath_v.push_back(AnalyseFilePath);
    AnalyseFileSample_v.push_back(AnalyseFileSample);
    AnalyseFileDir_v.push_back(AnalyseFileDir);
    AnalyseFile_v.push_back(AnalyseFile);
}

/* Uniform en @ 4GeV */
void Config_Uniform_en_4GeV_samples(std::vector<std::string> &AnalyseFilePath_v, std::vector<std::string> &AnalyseFileSample_v,
                                    std::vector<std::string> &AnalyseFileDir_v, std::vector<std::string> &AnalyseFile_v,
                                    std::string &AnalyseFilePath, std::string &AnalyseFileSample, std::string &AnalyseFileDir, std::string &AnalyseFile)
{
    AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut_en";
    AnalyseFileSample = "reconhipo";
    AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    AnalyseFilePath_v.push_back(AnalyseFilePath);
    AnalyseFileSample_v.push_back(AnalyseFileSample);
    AnalyseFileDir_v.push_back(AnalyseFileDir);
    AnalyseFile_v.push_back(AnalyseFile);
}

/* Uniform ep @ 4GeV */
void Config_Uniform_ep_4GeV_samples(std::vector<std::string> &AnalyseFilePath_v, std::vector<std::string> &AnalyseFileSample_v,
                                    std::vector<std::string> &AnalyseFileDir_v, std::vector<std::string> &AnalyseFile_v,
                                    std::string &AnalyseFilePath, std::string &AnalyseFileSample, std::string &AnalyseFileDir, std::string &AnalyseFile)
{
    AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/4029MeV/OutPut_ep";
    AnalyseFileSample = "reconhipo";
    AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    AnalyseFile = AnalyseFileDir + "*.hipo";                                             // all files
    AnalyseFilePath_v.push_back(AnalyseFilePath);
    AnalyseFileSample_v.push_back(AnalyseFileSample);
    AnalyseFileDir_v.push_back(AnalyseFileDir);
    AnalyseFile_v.push_back(AnalyseFile);
}
#pragma endregion

#pragma region Uniform samples @ 6GeV
/* Uniform samples @ 6GeV */

/* Uniform 1e @ 6GeV */
void Config_Uniform_1e_6GeV_samples(std::vector<std::string> &AnalyseFilePath_v, std::vector<std::string> &AnalyseFileSample_v,
                                    std::vector<std::string> &AnalyseFileDir_v, std::vector<std::string> &AnalyseFile_v,
                                    std::string &AnalyseFilePath, std::string &AnalyseFileSample, std::string &AnalyseFileDir, std::string &AnalyseFile)
{
    AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut_1e";
    AnalyseFileSample = "reconhipo";
    AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    AnalyseFile = AnalyseFileDir + "*.hipo"; // all files
    AnalyseFilePath_v.push_back(AnalyseFilePath);
    AnalyseFileSample_v.push_back(AnalyseFileSample);
    AnalyseFileDir_v.push_back(AnalyseFileDir);
    AnalyseFile_v.push_back(AnalyseFile);
}

/* Uniform en @ 6GeV */
void Config_Uniform_en_6GeV_samples(std::vector<std::string> &AnalyseFilePath_v, std::vector<std::string> &AnalyseFileSample_v,
                                    std::vector<std::string> &AnalyseFileDir_v, std::vector<std::string> &AnalyseFile_v,
                                    std::string &AnalyseFilePath, std::string &AnalyseFileSample, std::string &AnalyseFileDir, std::string &AnalyseFile)
{
    AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut_en";
    AnalyseFileSample = "reconhipo";
    AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    AnalyseFile = AnalyseFileDir + "*.hipo"; // all files
    AnalyseFilePath_v.push_back(AnalyseFilePath);
    AnalyseFileSample_v.push_back(AnalyseFileSample);
    AnalyseFileDir_v.push_back(AnalyseFileDir);
    AnalyseFile_v.push_back(AnalyseFile);
}

/* Uniform ep @ 6GeV */
void Config_Uniform_ep_6GeV_samples(std::vector<std::string> &AnalyseFilePath_v, std::vector<std::string> &AnalyseFileSample_v,
                                    std::vector<std::string> &AnalyseFileDir_v, std::vector<std::string> &AnalyseFile_v,
                                    std::string &AnalyseFilePath, std::string &AnalyseFileSample, std::string &AnalyseFileDir, std::string &AnalyseFile)
{
    AnalyseFilePath = "lustre24/expphy/volatile/clas12/asportes/2N_Analysis_Reco/Uniform_e-p-n_samples/5986MeV/OutPut_ep";
    AnalyseFileSample = "reconhipo";
    AnalyseFileDir = "/" + AnalyseFilePath + "/" + AnalyseFileSample + "/";
    AnalyseFile = AnalyseFileDir + "*.hipo"; // all files
    AnalyseFilePath_v.push_back(AnalyseFilePath);
    AnalyseFileSample_v.push_back(AnalyseFileSample);
    AnalyseFileDir_v.push_back(AnalyseFileDir);
    AnalyseFile_v.push_back(AnalyseFile);
}
#pragma endregion

#endif // UNIFORM_SAMPLES
