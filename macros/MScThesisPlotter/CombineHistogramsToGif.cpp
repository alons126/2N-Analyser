#include <vector>
#include <string>
#include <sstream>
#include <iostream>
#include "TH2D.h"
#include "TCanvas.h"

void CombineHistogramsToGif(TCanvas *Sep_canv, std::vector<TH2D *> &Histograms2D, const int &ww, const int &wh, const std::string SavePath,
                            const std::string &outputGif, const std::string &SliceVariant, const std::string &delay, const std::string &loop)
{
    Sep_canv->cd();

    int GIFnumber;

    if (SliceVariant == "TL")
    {
        GIFnumber = 1;
    }
    else if (SliceVariant == "Reco")
    {
        GIFnumber = 2;
    }
    else if (SliceVariant == "Ratio")
    {
        GIFnumber = 3;
    }
    else if (SliceVariant == "AMaps")
    {
        GIFnumber = 4;
    }

    // cout << "1\n";
    // cout << Histograms2D.size() << "\n";
    // cout << "1b\n";

    std::vector<std::string> imageFiles;

    // Loop over the histograms and save each one as an image
    for (size_t i = 0; i < Histograms2D.size(); ++i)
    {
        // cout  << "1c\n";

        std::ostringstream oss;
        oss << SavePath << "/" << "hist_" << i + 1 << ".png"; // Create unique filenames for each image
        // oss << "hist_" << i << ".png"; // Create unique filenames for each image
        std::string imageName = oss.str();
        imageFiles.push_back(imageName);

        if (Histograms2D[i]->Integral() == 0. || Histograms2D[i]->GetEntries() == 0)
        {
            double x_1 = 0.2, y_1 = 0.3, x_2 = 0.86, y_2 = 0.7;
            double diplayTextSize = 0.1;

            TPaveText *displayText = new TPaveText(x_1, y_1, x_2, y_2, "NDC");
            displayText->SetTextSize(diplayTextSize), displayText->SetFillColor(0), displayText->AddText("Empty histogram"), displayText->SetTextAlign(22);
            Histograms2D[i]->Draw(), displayText->Draw();
            Sep_canv->SaveAs(imageName.c_str());
        }
        else
        {
            Histograms2D[i]->Draw("COLZ");
            Sep_canv->SaveAs(imageName.c_str());
        }
    }

    // cout << "2\n";

    // Use ImageMagick's 'convert' command to combine the images into a GIF
    std::ostringstream command;
    command << "magick -delay " << delay << " -loop " << loop << " "; // Adjust delay and looping as necessary
    // command << "convert -delay " << delay << " -loop " << loop << " "; // Adjust delay and looping as necessary
    for (const auto &imageFile : imageFiles)
    {
        command << imageFile << " ";
    }
    command << SavePath << "/" << GIFnumber << "_" << outputGif;
    // command << outputGif;

    // Execute the command to create the GIF
    int result = system(command.str().c_str());
    if (result == 0)
    {
        std::cout << "GIF created successfully: " << SavePath << "/" << outputGif << "_" << std::endl;
        // std::cout << "GIF created successfully: " << outputGif << std::endl;
    }
    else
    {
        std::cerr << "Error creating GIF!" << std::endl;
    }

    // Optionally, remove the individual images after creating the GIF
    for (const auto &imageFile : imageFiles)
    {
        std::remove(imageFile.c_str());
    }

    Histograms2D.clear();
}