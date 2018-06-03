#include "Scenario.h"
#include "Function.h"
#include "VectorManipulator.h"
#include <iostream>
#include <string>

using std::ifstream;
using std::ofstream;

Scenario::Scenario(unsigned int scenarioIDIn, std::string scenarioNameIn, std::string descriptionIn, std::string inspectEnvPathIn, std::string successPathIn, std::string failurePathIn, std::string deadPathIn, std::string inspectEnvTextIn, std::string successTextIn, std::string failureTextIn, std::string deadTextIn)
{
    scenarioID = scenarioIDIn;
    scenarioName = scenarioNameIn;
    description = descriptionIn;
    inspectEnvPath = inspectEnvPathIn;
    successPath = successPathIn;
    failurePath = failurePathIn;
    deadPath = deadPathIn;
    inspectEnvText = inspectEnvTextIn;
    successText = successTextIn;
    failureText = failureTextIn;
    deadText = deadTextIn;
 
}

unsigned int Scenario::getScenarioID() { return scenarioID; }
void Scenario::setScenarioID(unsigned int scenarioIDIn) { scenarioID = scenarioIDIn; }

std::string Scenario::getScenarioName() { return scenarioName; }
void Scenario::setScenarioName(std::string scenarioNameIn) { scenarioName = scenarioNameIn; }

std::string Scenario::getDescription() { return description; }
void Scenario::setDescription(std::string descriptionIn) { description = descriptionIn; }

std::string Scenario::getInspectEnvPath() { return inspectEnvPath; }
void Scenario::setInspectEnvPath(std::string inspectEnvPathIn) { inspectEnvPath = inspectEnvPathIn; }

std::string Scenario::getSuccessPath() { return successPath; }
void Scenario::setSuccessPath(std::string successPathIn) { successPath = successPathIn; }

std::string Scenario::getFailurePath() { return failurePath; }
void Scenario::setFailurePath(std::string failurePathIn) { failurePath = failurePathIn; }

std::string Scenario::getDeadPath() { return deadPath; }
void Scenario::setDeadPath(std::string deadPathIn) { deadPath = deadPathIn; }

std::string Scenario::getInspectEnvText() { return inspectEnvText; }
void Scenario::setInspectEnvText(std::string inspectEnvTextIn) { inspectEnvText = inspectEnvTextIn; }

std::string Scenario::getSuccessText() { return successText; }
void Scenario::setSuccessText(std::string successTextIn) { successText = successTextIn; }

std::string Scenario::getFailureText() { return failureText; }
void Scenario::setFailureText(std::string failureTextIn) { failureText = failureTextIn; }

std::string Scenario::getDeadText() { return deadText; }
void Scenario::setDeadText(std::string deadTextIn) { deadText = deadTextIn; }

Scenario::Scenario() //TODO Remove this test info once VectorManipulator functioning properly
{
}

Scenario::~Scenario()
{
}

std::vector<Scenario> Scenario::loadScenario(std::ifstream& inFile, int scenarioVecSizeIn)
{
    std::vector<Scenario> scen;

    scen.reserve(scenarioVecSizeIn);
    
    for(int c = 0; c < scenarioVecSizeIn; c++)
    {
        std::string label;
    
            inFile >> label >> scenarioID;
            inFile >> label;
            getline(inFile, scenarioName);
            getline(inFile, description);
            getline(inFile, inspectEnvPath);
            getline(inFile, successPath);
            getline(inFile, failurePath);
            getline(inFile, deadPath);
            getline(inFile, inspectEnvText);
            getline(inFile, successText);
            getline(inFile, failureText);
            getline(inFile, deadText);
            inFile >> label;
        
        scen.push_back(*this);
    }
    
    for(int c= 0; c < scenarioVecSizeIn; c++)
    {
        std::cout << scen[c].getScenarioID(); //For testing to make sure the vector populated properly
    }
    
    return scen;
}

void Scenario::scenarioOptions()
{
    std::cout << '\n' << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << '\n';
    std::cout << '\n' << "[SCENARIO ID]:" << scenarioID;
    std::cout << '\n' << "[SCENARIO NAME]:" << scenarioName;
    std::cout << '\n' << description << '\n';
    std::cout << '\n' << "[MAKE A DECISION]..." << '\n';
    std::cout << "[1] " << "[PLAYER STATUS]" << '\t' << '\t';
    std::cout << "[2] " << deadPath << '\t' << '\t';
    std::cout << "[3] " << inspectEnvPath << '\t' << '\t';
    std::cout << "[4] " << successPath << '\t' << '\t';
    std::cout << "[5] " << failurePath << '\n' << '\n';
    std::cout << '\n' << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << '\n';
}

void Scenario::printStoryArt() //TODO Update scenarioID values
{
    Function print;
    
    if(scenarioID == 15) {
        print.outArt("wolves.txt");
    } else if(scenarioID == 13) {
        print.outArt("bear.txt");
    } else if(scenarioID == 6) {
        print.outArt("journal.txt");
    } else {
        //print nothing
    }
}

