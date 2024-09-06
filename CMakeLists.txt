cmake_minimum_required(VERSION 3.16.3)
project(project)

set(CMAKE_CXX_STANDARD 14)

# Find ROOT
find_package(ROOT REQUIRED)

# Include ROOT
include_directories(${ROOT_INCLUDE_DIRS})

## Set the path to CLAS12ROOT includes and libraries
#set(CLAS12ROOT_INCLUDE_DIR /home/alon/clas12root/Clas12Root)
#set(CLAS12BANKS_INCLUDE_DIR /home/alon/clas12root/Clas12Banks)
#set(HIPO4_INCLUDE_DIR /home/alon/clas12root/hipo4)
#
## Include directories for CLAS12ROOT
#include_directories(${CLAS12ROOT_INCLUDE_DIR})
#include_directories(${CLAS12BANKS_INCLUDE_DIR})
#include_directories(${HIPO4_INCLUDE_DIR})
#
## Set library paths
#set(CLAS12ROOT_LIBRARY /home/alon/clas12root/lib/libClas12Root.so)
#set(CLAS12BANKS_LIBRARY /home/alon/clas12root/lib/libClas12Banks.so)
#set(HIPO4_LIBRARY /home/alon/clas12root/lib/libHipo4.so)
#
## Check if the library files exist
#if (NOT EXISTS ${CLAS12ROOT_LIBRARY})
#    message(FATAL_ERROR "CLAS12ROOT_LIBRARY does not exist at ${CLAS12ROOT_LIBRARY}")
#endif()
#
#if (NOT EXISTS ${CLAS12BANKS_LIBRARY})
#    message(FATAL_ERROR "CLAS12BANKS_LIBRARY does not exist at ${CLAS12BANKS_LIBRARY}")
#endif()
#
#if (NOT EXISTS ${HIPO4_LIBRARY})
#    message(FATAL_ERROR "HIPO4_LIBRARY does not exist at ${HIPO4_LIBRARY}")
#endif()
#
## Collect all .cpp files in the src directory
#file(GLOB CLAS12ROOT_SOURCES "${CLAS12ROOT_INCLUDE_DIR}/*.cpp")
#file(GLOB CLAS12BANKS_SOURCES "${CLAS12BANKS_INCLUDE_DIR}/*.cpp")
#file(GLOB HIPO4_SOURCES "${HIPO4_INCLUDE_DIR}/*.cpp")

# Add executable
#add_executable(project ${CLAS12ROOT_SOURCES} ${CLAS12BANKS_SOURCES} ${HIPO4_SOURCES})

include_directories(.)
include_directories(macros)
include_directories(setup)
include_directories(setup/CLAS12DAnalysis)
include_directories(setup/CLAS12DAnalysis/CLAS12DAnalyser)
include_directories(setup/CLAS12DAnalysis/CLAS12DASettings)
include_directories(setup/CLAS12DAnalysis/CLAS12DHistograms)
include_directories(source)
include_directories(source/classes)
include_directories(source/classes/AMaps)
include_directories(source/classes/clas12ana)
include_directories(source/classes/clas12ana/clas12ana_ver_1_myedit)
include_directories(source/classes/clas12ana/other)
include_directories(source/classes/DEfficiency)
include_directories(source/classes/Directories)
include_directories(source/classes/DSCuts)
include_directories(source/classes/ExperimentParameters)
include_directories(source/classes/hData)
include_directories(source/classes/hPlots)
include_directories(source/classes/MomentumResolution)
include_directories(source/classes/TargetParameters)
include_directories(source/classes/TLCuts)
include_directories(source/data)
include_directories(source/functions)
include_directories(source/functions/AngleCalc)
include_directories(source/functions/DrawAndSaveFunctions)
include_directories(source/functions/EventProperties)
include_directories(source/functions/FitFunctions)
include_directories(source/functions/Math_func)
include_directories(source/functions/other)
include_directories(source/functions/PID_functions)
include_directories(source/other)
include_directories(source/Structures_beta)

add_executable(project ${CLAS12ROOT_SOURCES} ${CLAS12BANKS_SOURCES} ${HIPO4_SOURCES}
        macros/Other/process_events.C
        macros/PlotsEffAndACorr2x3/PlotsACorr2x3Electron.cpp
        macros/PlotsEffAndACorr2x3/PlotsACorr2x3Nucleon.cpp
        macros/PlotsEffAndACorr2x3/PlotsEff2x3.cpp
        macros/PlotsEffAndACorr2x3/PlotsEff2x3Electron.cpp
        macros/PlotsEffAndACorr2x3/PlotsEff2x3Nucleon.cpp
        macros/AMapsDiveTest.cpp
        macros/BetaFitAndSave.cpp
        macros/BetaFitAndSaveApprax.cpp
        "macros/MCtoDATAcomp - Copy (2).cpp"
        "macros/MCtoDATAcomp - Copy.cpp"
        macros/MCtoDATAcomp.cpp
        macros/plots4x4.txt
        macros/PlotsBeta4x4.cpp
        macros/PlotsEffAndACorr2x3.cpp
        macros/plotter_1x1.cpp
        macros/plotter_1x2.cpp
        macros/plotter_2x2.cpp
        "macros/PoliFitter - Copy.cpp"
        macros/PoliFitter.cpp
        macros/process_events.C
        setup/CLAS12DAnalysis/CLAS12DAnalyser/CLAS12DAnalyser.cpp
        setup/CLAS12DAnalysis/CLAS12DAnalyser/CLAS12DAnalyser.h
        setup/CLAS12DAnalysis/CLAS12DASettings/CLAS12DASettings.cpp
        setup/CLAS12DAnalysis/CLAS12DASettings/CLAS12DASettings.h
        setup/CLAS12DAnalysis/CLAS12DHistograms/CLAS12DHistograms.cpp
        setup/CLAS12DAnalysis/CLAS12DHistograms/CLAS12DHistograms.h
        setup/codeSetup.h
        setup/TruthLevelAnalyser.h
        source/classes/AMaps/AMaps.cpp
        source/classes/AMaps/AMaps.h
        source/classes/clas12ana/clas12ana_ver_1_myedit/clas12ana.h
        source/classes/clas12ana/clas12ana_ver_1_myedit/example_ana.cpp
        "source/classes/clas12ana/other/clas12ana - Copy (2).h"
        "source/classes/clas12ana/other/clas12ana - Copy.h"
        source/classes/clas12ana/clas12ana_ver_2_myedit_LatestMSc/clas12ana.h
        source/classes/clas12ana/clas12ana_ver_2_myedit_LatestMSc/clas12ana_ver_1_myedit.h
        "source/classes/clas12ana/clas12ana_ver_2_myedit_LatestMSc/example_ana - Copy.cpp"
        source/classes/clas12ana/clas12ana_ver_2_myedit_LatestMSc/example_ana.cpp
        source/classes/clas12ana/clas12ana_ver_2_myedit_LatestMSc/skim_events.cpp
        source/classes/DEfficiency/DEfficiency.cpp
        source/classes/DEfficiency/DEfficiency.h
        source/classes/Directories/Directories.cpp
        source/classes/Directories/Directories.h
        source/classes/DSCuts/DSCuts.h
        source/classes/ExperimentParameters/ExperimentParameters.cpp
        source/classes/ExperimentParameters/ExperimentParameters.h
        source/classes/hData/hData.cpp
        source/classes/hData/hData.h
        source/classes/hPlots/hPlot1D.cpp
        source/classes/hPlots/hPlot1D.h
        source/classes/hPlots/hPlot1DStack.cpp
        source/classes/hPlots/hPlot1DStack.h
        source/classes/hPlots/hPlot2D.cpp
        source/classes/hPlots/hPlot2D.h
        source/classes/MomentumResolution/MomentumResolution.cpp
        source/classes/MomentumResolution/MomentumResolution.h
        source/classes/TargetParameters/TargetParameters.h
        source/classes/TLCuts/TLCuts.cpp
        source/classes/TLCuts/TLCuts.h
        source/data/AcceptanceCorrections/C12_simulation_6GeV_T5/ACorr_data_-_C12_simulation_6GeV_T5.root
        source/data/AcceptanceCorrections/C12_simulation_6GeV_T5_first_10/ACorr_data_-_C12_simulation_6GeV_T5_first_10.root
        source/data/AcceptanceCorrections/C12_simulation_6GeV_T5_first_100/ACorr_data_-_C12_simulation_6GeV_T5_first_100.root
        source/data/AcceptanceCorrections/C12_simulation_6GeV_T5_first_250/ACorr_data_-_C12_simulation_6GeV_T5_first_250.root
        source/data/AcceptanceCorrections/C12_simulation_G18_2GeV/ACorr_data_-_C12_simulation_G18_2GeV.root
        source/data/AcceptanceCorrections/C12_simulation_G18_Q208_6GeV/ACorr_data_-_C12_simulation_G18_Q208_6GeV.root
        source/data/AcceptanceCorrections/Ca48_simulation_G18_10a_02_11b_6GeV/ACorr_data_-_Ca48_simulation_G18_10a_02_11b_6GeV.root
        source/data/PIDCuts/clas12ana_ver_1_myedit/ana.par
        source/data/PIDCuts/clas12ana_ver_1_myedit/ecal.par
        source/data/PIDCuts/clas12ana_ver_1_myedit/Fitted_PID_Cuts__C12_simulation_6GeV_T5.par
        source/data/PIDCuts/clas12ana_ver_1_myedit/Fitted_PID_Cuts__C12_simulation_6GeV_T5_first_10.par
        source/data/PIDCuts/clas12ana_ver_1_myedit/Fitted_PID_Cuts__C12_simulation_6GeV_T5_first_100.par
        source/data/PIDCuts/clas12ana_ver_1_myedit/Fitted_PID_Cuts__Ca48_data_6GeV_run_015832.par
        source/data/PIDCuts/clas12ana_ver_1_myedit/Fitted_PID_Cuts__Ca48_simulation_G18_10a_02_11b_6GeV.par
        source/data/PIDCuts/clas12ana_ver_1_myedit/Fitted_PID_Cuts__LH2_data_6GeV_run_015032.par
        source/data/PIDCuts/ana.par
        source/data/PIDCuts/ecal.par

        source/data/PIDCuts/paramsPI_40Ca_x2.dat
        source/data/PIDCuts/paramsPI_LD2_x2.dat
        source/data/PIDCuts/paramsSF_40Ca_x2.dat
        source/data/PIDCuts/paramsSF_LD2_x2.dat
        source/functions/AngleCalc/CalcdPhi.h
        source/functions/AngleCalc/GetBinFromAng.h
        source/functions/DrawAndSaveFunctions/DrawAndSaveACorrPlots.h
        source/functions/DrawAndSaveFunctions/DrawAndSaveEfficiencyPlots.h
        source/functions/DrawAndSaveFunctions/DrawAndSaveFSRatio.h
        source/functions/EventProperties/GetParticleName.h
        source/functions/EventProperties/GetParticleNameLC.h
        source/functions/EventProperties/GetParticleNameShort.h
        source/functions/EventProperties/SetDRegion.h
        source/functions/EventProperties/SetFSRatioSaveDir.h
        source/functions/EventProperties/SetSaveDir.h
        source/functions/EventProperties/SetStatsTitle.h
        source/functions/EventProperties/SettingSaveNames.h
        source/functions/EventProperties/SetTitle.h
        source/functions/EventProperties/SetType.h
        source/functions/EventProperties/SetXAxisTitle.h
        source/functions/EventProperties/SetYAxisTitle.h
        source/functions/FitFunctions/BetaFit.h
        source/functions/FitFunctions/BetaFitApprax.h
        source/functions/FitFunctions/FitFunction.h
        source/functions/Math_func/poly34.cpp
        source/functions/Math_func/poly34.h
        source/functions/other/neutron_veto.h
        source/functions/other/NeutronECAL_Cut_Veto.h
        source/functions/PID_functions/ChargedParticleID.h
        source/functions/PID_functions/FDNeutralParticle.h
        source/functions/PID_functions/FDNeutralParticleID.h
        source/functions/PID_functions/GetFDNeutronP.h
        source/functions/PID_functions/GetFDNeutrons.h
        source/functions/PID_functions/GetFDPhotons.h
        source/functions/PID_functions/GetGoodParticles.h
        source/functions/PID_functions/GetGoodProtons.h
        source/functions/PID_functions/NeutralParticleID.h
        source/functions/PID_functions/nParticleID.h
        source/functions/drawtext.h
        source/functions/FillByInt.h
        source/functions/findSubstring.h
        source/functions/GeneralFunctions.h
        source/functions/GetPi0MomTh.h
        source/functions/GetTruthLevelCuts.h
        source/functions/HistogramPlottingFunctions.h
        source/functions/neutron_veto.h
        source/functions/NeutronECAL_Cut_Veto.h
        source/functions/PlotsEff2x3.h
        source/functions/quit.h
        source/functions/StackPlot3.h
        source/functions/StackPlot4.h
        source/functions/TLKinCutsCheck.h
        source/functions/to_string_with_precision.h
        "source/other/fitexample - Copy.c"
        source/other/fitexample.c
        source/other/hPlot1D_example.cpp
        source/Structures_beta/Histogram1D.cpp
        source/constants.h
        macros/Other/db_script.txt
        Old_analysers/DetectorSimulationAnalyser.C
        git_handle.sh
        main.c
        run.sh
        Old_analysers/TruthLevelAnalyser.c
        TempInclude/Classes/HistogramsTemp/HistogramsTemp.cpp
        TempInclude/Classes/HistogramsTemp/HistogramsTemp.h
        source/classes/Settings/Settings.cpp
        source/classes/Settings/Settings.h
        source/classes/Settings/CustomPlotsDirectory.cpp
        source/classes/Settings/CustomPlotsDirectory.h
        source/classes/ParticleID/ParticleID.cpp
        source/classes/ParticleID/ParticleID.h
        source/classes/RecoAnalyser/RecoAnalyser.cpp
        source/classes/RecoAnalyser/RecoAnalyser.h
        source/classes/AMaps/CustomSliceLimits.h
        macros/zoomed_in_histogram.cpp
        source/classes/DataAnalyser/DataAnalyser.cpp
        source/classes/DataAnalyser/DataAnalyser.h
        source/classes/clas12ana/clas12ana.cpp
        source/classes/clas12ana/clas12ana_ver_3_original/clas12ana.cpp
        source/classes/CLAS12Analysis/CLAS12Analysis.cpp
        source/classes/CLAS12Analysis/CLAS12Analysis.h)

## Link against ROOT and CLAS12ROOT libraries
#target_link_libraries(project ${ROOT_LIBRARIES})

target_link_libraries(project ${ROOT_LIBRARIES})
#target_link_libraries(project ${ROOT_LIBRARIES} ${CLAS12ROOT_LIBRARY} ${CLAS12BANKS_LIBRARY} ${HIPO4_LIBRARY})
