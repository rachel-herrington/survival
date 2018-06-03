#include "Item.h"
#include <vector>
#include <fstream>

Item::Item(unsigned int itemIDIn, int afflictionIDIn, std::string itemNameIn, std::string itemDescIn, std::string healTextIn, std::string invalidUseIn, std::string usedForIn, bool isInInventoryIn, bool usableIn)
{
    itemID = itemIDIn;
    afflictionID = afflictionIDIn;
    itemName = itemNameIn;
    itemDesc = itemDescIn;
    healText = healTextIn;
    invalidUse = invalidUseIn;
    usedFor = usedForIn;
    isInInventory = isInInventoryIn;
    usable = usableIn;
}

Item::Item(){}
Item::~Item(){}

unsigned int Item::getItemID() { return itemID; }
void Item::setItemID(unsigned int itemIDIn) { itemID = itemIDIn; }

int Item::getAfflictionID() { return afflictionID; }
void Item::setAfflictionID(int afflictionIDIn) { afflictionID = afflictionIDIn; }

std::string Item::getItemName() { return itemName; }
void Item::setItemName(std::string itemNameIn) { itemName = itemNameIn; }

std::string Item::getItemDesc() { return itemDesc; }
void Item::setItemDesc(std::string itemDescIn) { itemDesc = itemDescIn; }

std::string Item::getHealText() { return healText; }
void Item::setHealText(std::string healTextIn) { healText = healTextIn; }

std::string Item::getInvalidUse() { return invalidUse; }
void Item::setInvalidUse(std::string invalidUseIn) { invalidUse = invalidUseIn; }

std::string Item::getUsedFor() { return usedFor; }
void Item::setUsedFor(std::string usedForIn) { usedFor = usedForIn; }

bool Item::getIsInInventory() { return isInInventory; }
void Item::setIsInInventory(bool isInInventoryIn) { isInInventory = isInInventoryIn; }

bool Item::getUsable() { return usable; }
void Item::setUsable(bool usableIn) { usable = usableIn; }

std::vector<Item> Item::loadItems(std::ifstream& inItemFile, int itemSizeIn)
{
    std::vector<Item> items;
    
    items.reserve(itemSizeIn);
    
    for(int c = 0; c < itemSizeIn; c++)
    {
        std::string label;
        
        inItemFile >> label >> afflictionID;
        inItemFile >> label;
        getline(inItemFile, itemName);
        getline(inItemFile, itemDesc);
        getline(inItemFile, healText);
        getline(inItemFile, invalidUse);
        getline(inItemFile, usedFor);
        inItemFile >> label;
        
        items.push_back(*this);
    }
    
    for(int c= 0; c < itemSizeIn; c++)
    {
        std::cout << items[c].getItemID(); //For testing to make sure the vector populated properly
    }
    return items;
}

void Item::itemOptions()
{
    if(getIsInInventory()) {
        std::cout << '\n' << "[" << itemID << "]" << itemName << ": " << itemDesc << '\n';
    }
}


