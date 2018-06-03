#ifndef Scenario_h
#define Scenario_h
#include "Game.h"
#include <stdio.h>
#include <string>
#include <fstream>

class Scenario
{
    
private:
    unsigned int scenarioID;
    std::string scenarioName;
    std::string description;
    std::string inspectEnvPath;
    std::string successPath;
    std::string failurePath;
    std::string deadPath;
    std::string inspectEnvText;
    std::string successText;
    std::string failureText;
    std::string deadText;
    
public:
    Scenario();
    Scenario(unsigned int scenarioIDIn, std::string scenarioNameIn, std::string descriptionIn, std::string inspectEnvPathIn, std::string successPathIn, std::string failurePathIn, std::string deadPathIn, std::string inspectEnvTextIn, std::string successTextIn, std::string failureTextIn, std::string deadTextIn);
    ~Scenario();
        
    unsigned int getScenarioID();
    void setScenarioID(unsigned int scenarioIDIn);
    
    std::string getScenarioName();
    void setScenarioName(std::string scenarioNameIn);
    
    std::string getDescription();
    void setDescription(std::string descriptionIn);
    
    std::string getInspectEnvPath();
    void setInspectEnvPath(std::string inspectEnvPathIn);
    
    std::string getSuccessPath();
    void setSuccessPath(std::string successPathIn);
    
    std::string getFailurePath();
    void setFailurePath(std::string failurePathIn);
    
    std::string getDeadPath();
    void setDeadPath(std::string deadPathIn);
    
    std::string getInspectEnvText();
    void setInspectEnvText(std::string inspectEnvTextIn);
    
    std::string getSuccessText();
    void setSuccessText(std::string successTextIn);
    
    std::string getFailureText();
    void setFailureText(std::string failureTextIn);
    
    std::string getDeadText();
    void setDeadText(std::string deadTextIn);
    
    void scenarioOptions();
    std::vector<Scenario> loadScenario(std::ifstream& inFile, int vecSizeIn);
    void printStoryArt();
};

#endif /* Scenario_h */

