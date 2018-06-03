#include "Function.h"
#include <stdio.h>
#include <time.h>

Function::Function()
{
    
}

Function::~Function()
{
    
}

void Function::outMsg(std::string message)
{
    std::cout << '\n' << message << '\n' << '\n';
}

void Function::invalidInput()
{
    std::cout << '\n' << "[INVALID SELECTION] " << '\n' << "Press enter to continue" << '\n' << '\n';
    std::cin.ignore();
    std::cin.clear();
    std::cin.get();
}
void Function::toContinue()
{
    std::cout << "[CONTINUE] <Press enter>" << '\n' << '\n';
    std::cin.ignore();
    std::cin.clear();
    std::cin.get();
}

std::string Function::getFileContents(std::ifstream& Reader)
{
    std::string Lines = "";                        //All lines
    if (Reader)
    {
        while (Reader.good ())                     //Check file
        {
            std::string TempLine;                  //Temp line
            std::getline(Reader , TempLine);       //Get temp line
            TempLine += '\n';                      //Add newline character
            Lines += TempLine;                     //Add newline
        }
        return Lines;
    }
    else return "[ERROR] File does not exist. Check your file path.";
}

void Function::outArt(std::string txtFile)
{
    std::ifstream Reader(txtFile);                //Open file
    std::string Art = getFileContents(Reader);    //Get file
    std::cout << Art << '\n';                     //Print it to the screen
    Reader.close ();                              //Close file
}

void Function::outInventoryDesign() {
    std::cout << '\n' << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << '\n';
}



