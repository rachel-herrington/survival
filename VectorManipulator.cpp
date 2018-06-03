#include "VectorManipulator.h"
#include <iostream>

using std::vector;
using std::ifstream;

VectorManipulator::VectorManipulator(bool successIn, bool startIn)
{
    success =  successIn;
    start = startIn;
}

VectorManipulator::VectorManipulator()
{
}

VectorManipulator::~VectorManipulator()
{
}

bool VectorManipulator::getSuccess() { return success; }
void VectorManipulator::setSuccess(bool successIn) { success = successIn; }

bool VectorManipulator::getStart() { return start; }
void VectorManipulator::setStart(bool startIn){ start = startIn; }

void VectorManipulator::setupNewGame()
{
    scenarios.reserve(scenarioVecSize);
    ifstream inFile("loadscenario.txt");
    if(inFile) {
        Scenario scen;
        scenarios = scen.loadScenario(inFile, scenarioVecSize);
    }
    else {
        std::cout << "Load All Scenarios Failed" << '\n';
    }
    inFile.close();
    
    items.reserve(itemSize);
    ifstream inItemFile("item.txt");
    if(inItemFile) {
        Item item;
        items = item.loadItems(inItemFile, itemSize);
    }
    else {
        std::cout << "Load All Items Failed" << '\n';
    }
    inItemFile.close();
}

Scenario* VectorManipulator::setScenarioVector()
{
    if(start) {
        start = false;
        return &scenarios[iterator];
    } else {
        if(success) {
            if(iterator % 2 == 0) {
                iterator = iterator + 2;
                return &scenarios[iterator];
            } else {
                iterator = iterator + 1;
                return &scenarios[iterator];
            }
        } else {
            iterator = iterator + 1;
            return &scenarios[iterator];
        }
    }
    return 0;
}

void VectorManipulator::printStatus(Item* itemPtr, Player* playerPtr)
{
    int select;
    
    if(iterator < 6) {
        std::cout << "[INVENTORY EMPTY]" << '\n';
    } else {
        for(int i = 0; i < itemSize; i++) {
            itemPtr = &items[i];
            itemPtr->setItemID(i+1);
            if(playerPtr->getInjury() == itemPtr->getAfflictionID()) {
                itemPtr->setUsable(true);
                std::cout << '\n' << itemPtr->getUsable() << '\n';
            }
            itemPtr->itemOptions();
        }
    }
    playerPtr->checkStats();
    
    if(iterator > 5) {
        std::cout << '\n' << "Enter the number for the item you want to select: ";
        std::cin >> select;
        if(select <= 0 || select > itemSize) {
            std::cout << '\n' << "Invalid input" << '\n';
        } else {
            itemPtr = &items[select - 1];
            std::cout << '\n' << "You have selected: " << itemPtr->getItemName();
            if(itemPtr->getUsable()) {
                playerPtr->healAffliction();
                std::cout << '\n' << itemPtr->getHealText() << '\n';
                itemPtr->setUsable(false);
                itemPtr->setIsInInventory(false);
            } else {
                std::cout << '\n' << itemPtr->getInvalidUse() << '\n';
            }
        }
    }
}

Player* VectorManipulator::scenarioFailure(Player *playerPtr)
{
    if(iterator == 1 || iterator == 3) {
        playerPtr->setInjury(0);        //Broken Bones
        return playerPtr;
    } else if(iterator == 2 || iterator == 4 || iterator == 11){
        playerPtr->setInjury(3);        //Hypothermia
        return playerPtr;
    } else if(iterator == 8 || iterator == 9){
        playerPtr->setInjury(6);        //Exhaustion
        return playerPtr;
    } else if(iterator == 5){
        playerPtr->setInjury(1);        //Botulism
        return playerPtr;
    } else if(iterator == 6 || iterator == 7 || iterator == 10){
        playerPtr->setInjury(4);        //Frostbite
        return playerPtr;
    } else if(iterator == 15){
        playerPtr->setInjury(7);        //Disoriented
        return playerPtr;
    } else if(iterator == 12){
        playerPtr->setInjury(2);        //Starvation
        return playerPtr;
    } else if(iterator == 13 || iterator == 14){
        playerPtr->setInjury(2);        //Bite Wound
        return playerPtr;
    } else if(iterator == 16){
        playerPtr->setInjury(8);        //Delirium
        return playerPtr;
    }
    return 0;
}

