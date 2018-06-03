#ifndef Function_h
#define Function_h
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>

class Function
{
    
private:
    
public:
    Function();
    virtual ~Function();
    
    void outMsg(std::string message);
    void outArt(std::string txtFile);
    void invalidInput();
    void toContinue();
    void outInventoryDesign();
    std::string getFileContents(std::ifstream& Reader);
};

#endif /* Function_h */
