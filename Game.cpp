#include "Game.h"
#include "Function.h"
#include "Scenario.h"
#include "VectorManipulator.h"
#include "Player.h"

Game::Game()
{
    choice = -1;
    playing = true;
    injuryCounter = 0;
}

Game::~Game()
{

}

void Game::playGame()
{
    using std::cout;
    using std::cin;
    
    //Initialization
    Function print;
    Player player;
    Player* playerPtr = &player;
    VectorManipulator vector;
    vector.setupNewGame();
    Item item;
    Item* itemPtr = &item;
    Scenario scen = *vector.setScenarioVector();
    Scenario* scenario = &scen;
    vector.iterator = scenario->getScenarioID();

    MainMenu: //GOTO label for Main Menu switch statement
    print.outArt("gametitle.txt");
    cin >> choice;
    switch (choice) //Main Menu
    {
        case 0 :  // Exit Game
            print.outMsg("[SELECTED] Exit Game");
            playing = false;
            break;
            
        case 1 : //Play Game
            print.outMsg("[SELECTED] Play Game");
            print.outArt("introduction.txt");
            do
            {   //Start Scenarios
                scenario->printStoryArt();
                scenario->scenarioOptions();
             
                cin >> choice;
                
                if(scenario->getScenarioID() == 16 & choice == 4) {
                    print.outArt("ending.txt");
                    print.toContinue();
                    goto MainMenu;
                }

                switch (choice)
                {
                    case 0 : // GOTO Main Menu label
                        print.outMsg("[RETURNING TO MAIN MENU]...");
                        print.toContinue();
                        goto MainMenu;
                        break;
                            
                    case 1 : //Player Status & Inventory
                        print.outInventoryDesign();
                        print.outArt("inventory.txt");
                        vector.printStatus(itemPtr, playerPtr);
                        if(playerPtr->getInjury() == -1) {
                            injuryCounter = 0;
                        }
                        print.outInventoryDesign();
                        print.toContinue();
                        break;
                            
                    case 2 : //Death
                        print.outArt("death.txt");
                        cout << '\n' << scenario->getFailureText() << '\n';
                        cout << '\n' << scenario->getDeadText() << '\n';
                        print.toContinue();
                        goto MainMenu;
                        break;
                            
                    case 3 : //Inspect Environment
                        cout << '\n' << scenario->getInspectEnvText() << '\n';
                        break;
                            
                    case 4: //Success
                        cout << '\n' << scenario->getSuccessText() << '\n';
                        vector.setSuccess(true);
                        scenario = vector.setScenarioVector();
                        break;
                            
                    case 5: //Failure
                        cout << '\n' << scenario->getFailureText() << '\n';
                        vector.setSuccess(false);
                        if(scenario->getScenarioID() != 16) {
                            scenario = vector.setScenarioVector();
                        }
                        vector.scenarioFailure(playerPtr);
                        injuryCounter = injuryCounter + 1;
                        std::cout << "[PLAYER STATUS] UPDATED" << '\n';
                        if(injuryCounter == 2) {
                            print.outArt("death.txt");
                            playerPtr->grievousAffliction();
                            injuryCounter = 0;
                            print.toContinue();
                            goto MainMenu;
                        }
                        break;
                            
                    default :
                    print.invalidInput();
                }

            } while (choice != -1);
            break;
            
        case 2 : //Print tutorial
            print.outMsg("[SELECTED] Tutorial");
            print.outArt("tutorial.txt");
            print.toContinue();
            break;
            
        case 3 : //Print credits
            print.outMsg("[SELECTED] Credits");
            print.outArt("credits.txt");
            print.toContinue();
            break;
            
        default :
            print.invalidInput();
    }
}


