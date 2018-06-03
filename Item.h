#ifndef Item_h
#define Item_h
#pragma once
#include <iostream>

class Item
{
private:
	unsigned int itemID;
    int afflictionID;
	std::string itemName;
    std::string itemDesc;
    std::string healText;
    std::string invalidUse;
	std::string usedFor;
    bool isInInventory = true;
    bool usable = false;

public:
	//constuctors
    Item(unsigned int itemIDIn, int afflictionIDIn, std::string itemNameIn, std::string itemDescIn, std::string healTextIn, std::string invalidUseIn, std::string usedForIn, bool isInInventoryIn, bool usableIn);
	Item();
	~Item();
	
	//getters and setters
	unsigned int getItemID();
	void setItemID(unsigned int itemIDIn);

    int getAfflictionID();
    void setAfflictionID(int afflictionIDIn);
    
	std::string getItemName();
	void setItemName(std::string itemNameIn);

	std::string getItemDesc();
	void setItemDesc(std::string itemDescIn);
    
    std::string getHealText();
    void setHealText(std::string  healTextIn);
    
    std::string getInvalidUse();
    void setInvalidUse(std::string invalidUseIn);
    
    std::string getUsedFor();
    void setUsedFor(std::string usedForIn);
    
    bool getIsInInventory();
    void setIsInInventory(bool isInInventoryIn);
    
    bool getUsable();
    void setUsable(bool usableIn);
	
    void itemOptions();
    std::vector<Item>loadItems(std::ifstream& inItemFile, int itemSizeIn);
};

#endif /* Item.h */

