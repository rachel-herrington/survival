#include "Game.h"
#include "Scenario.h"
#include "VectorManipulator.h"

int main()
{

	srand(static_cast<unsigned int>(time(NULL)));
    
    Game game;
    Game* thisGame = &game;
    
	while (thisGame->getPlaying())
	{
        thisGame->playGame();
	}

	return 0;
}
