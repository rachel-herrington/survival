#ifndef VectorManipulator_h
#define VectorManipulator_h
#include "Scenario.h"
#include "Item.h"
#include "Player.h"
#include <vector>
#include <stdio.h>

class VectorManipulator
{
private:
    std::vector<Item> items;
    std::vector<Scenario> scenarios;
    int scenarioVecSize = 17;
    int itemSize = 13;
    bool success = true;
    bool start = true;
    bool invisible = false;
    
public:
    VectorManipulator(bool successIn, bool startIn);
    VectorManipulator();
    ~VectorManipulator();
    
    unsigned int iterator = 0;
    
    bool getSuccess();
    void setSuccess(bool successIn);
    
    bool getStart();
    void setStart(bool startIn);
    
    void setupNewGame();
    Scenario* setScenarioVector();
    Item* setItemVector();
    Player* scenarioFailure(Player *playerPtr);
    void printStatus(Item* itemPtr, Player* playerPtr);
    
};

#endif /* VectorManipulator_h */
