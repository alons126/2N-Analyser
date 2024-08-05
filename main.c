#include "source/classes/DataAnalyser/DataAnalyser.cpp"

using namespace std;

int main() {
    auto start = std::chrono::system_clock::now(); // Start counting running time

    string FileType = AnalyseFile.substr(AnalyseFile.find_last_of(".") + 1);

    cout << "\n" << "AnalyseFile:\t" << AnalyseFile << "\n";
    cout << "FileType:\t" << FileType << "\n";

    DataAnalyser Analysis(FileType);
    std::string AnalyserMode = Analysis.ConfigureAnalyserMode(FileType);

    cout << "Analyser mode:\t'" << AnalyserMode << "'\n";

    cout << "\n---------------------------------------------------------------------------\n\n";
    cout << "Analysis mode:\t'" << AnalyserMode << "'" << "\n";
    cout << "Code version:\t" << Ver << "\n";

    auto end = std::chrono::system_clock::now();
    auto elapsed_time_seconds = std::chrono::duration_cast<std::chrono::seconds>(end - start);
    double elapsed_time_minutes = elapsed_time_seconds.count() / 60;

    if (elapsed_time_seconds.count() < 60) {
        std::cout << "Running time:\t" << elapsed_time_seconds.count() << " seconds\n\n";
    } else {
        std::cout << "Running time:\t" << to_string_with_precision(elapsed_time_minutes, 3) << " minutes\n\n";
    }
}
