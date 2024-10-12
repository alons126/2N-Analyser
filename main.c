#include "source/classes/DataAnalyser/DataAnalyser.cpp"

using namespace std;

int main()
{
    ConfigSampleChain();
    ConfigCanvasPDF();

    auto start = std::chrono::system_clock::now(); // Start counting running time

    int Num_of_analysed_samples = 0;

    cout << "\nLooping over sample chain...\n";

    for (int i = 0; i < AnalyseFilePath_v.size(); i++)
    {
        std::string AnalyseFilePath0 = AnalyseFilePath_v.at(i);
        std::string AnalyseFileSample0 = AnalyseFileSample_v.at(i);
        std::string AnalyseFileDir0 = AnalyseFileDir_v.at(i);
        std::string AnalyseFile0 = AnalyseFile_v.at(i);

        std::string FileType = AnalyseFile_v.at(i).substr(AnalyseFile_v.at(i).find_last_of(".") + 1);

        cout << "\nAnalyseFilePath:\t" << AnalyseFilePath0 << "\n";
        cout << "AnalyseFileSample:\t" << AnalyseFileSample0 << "\n";
        cout << "AnalyseFileDir:\t" << AnalyseFileDir0 << "\n";
        cout << "AnalyseFile:\t" << AnalyseFile0 << "\n\n";

        cout << "FileType:\t" << FileType << "\n";

        DataAnalyser Analysis(FileType, AnalyseFilePath0, AnalyseFileSample0, AnalyseFile0);
        std::string AnalyserMode = Analysis.ConfigureAnalyserMode(FileType);

        cout << "Analyser mode:\t'" << AnalyserMode << "'\n";

        cout << "\n---------------------------------------------------------------------------\n\n";
        cout << "Analysis mode:\t'" << AnalyserMode << "'" << "\n";
        cout << "Code version:\t" << Ver << "\n";

        ++Num_of_analysed_samples;

        if (AnalyseFilePath_v.size() > 1)
        { // Delete all ROOT objects whose class names start with TH (to prevent a memory leak)
            // gDirectory->Delete("TH*;*");
            gDirectory->Clear();
        }
    }

    cout << "#(analysed samples):\t" << Num_of_analysed_samples << "\n";

    auto end = std::chrono::system_clock::now();
    auto elapsed_time_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    double elapsed_time_minutes = elapsed_time_seconds.count() / 60;

    if (elapsed_time_seconds.count() < 60)
    {
        std::cout << "Running time:\t" << elapsed_time_seconds.count() << " seconds\n\n";
    }
    else
    {
        std::cout << "Running time:\t" << to_string_with_precision(elapsed_time_minutes, 3) << " minutes\n\n";
    }
}
