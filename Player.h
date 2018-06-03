#ifndef Player_h
#define Player_h
#include <iostream>

class Player
{
private:
	int injury = -1;
    
public:
	Player(int injuryIn);
	Player();
	~Player();

	int getInjury();
	void setInjury(int InjuryIn);

	void grievousAffliction();
    void healAffliction();
	void checkStats();

};

#endif /* Player_h */
