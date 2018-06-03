#ifndef Game_h
#define Game_h
#include <ctime>
#include <iomanip>

class Game
{

private:
    int choice;
    int injuryCounter;
    bool playing;
    
public:
    
	Game();  // Constructor
	virtual ~Game();  // Virtual deconstructor
    
	// Functions
    void playGame();

	// Accessors
	inline bool getPlaying() const { return this -> playing; }
};

#endif
