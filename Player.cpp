#include "Player.h"

Player::Player(int injuryIn)
{
	injury = injuryIn;
}

Player::Player()
{
}

Player::~Player() {}

int Player::getInjury() { return injury; }
void Player::setInjury(int injuryIn) { injury = injuryIn; }

void Player::checkStats()
{
    std::cout << '\n' << "[STATUS]: ";
	switch(injury)
	{
	case 0:
		std::cout << '\t' << "[AFFLICTION] BROKEN BONES";
		break;
	case 1:
		std::cout << '\t' << "[AFFLICTION] BOTULISM";
		break;
	case 2:
		std::cout << '\t' << "[AFFLICTION] STARVING";
		break;
	case 3:
		std::cout << '\t' << "[AFFLICTION] HYPOTHERMIA";
        break;
    case 4:
        std::cout << '\t' << "[AFFLICTION] FROSTBITE";
        break;
    case 5:
        std::cout << '\t' << "[AFFLICTION] BITE WOUND";
        break;
    case 6:
        std::cout << '\t' << "[AFFLICTION] EXHAUSTION";
        break;
    case 7:
        std::cout << '\t' << "[AFFLICTION] DISORIENTED";
        break;
    case 8:
        std::cout << '\t' << "[AFFLICTION] DELIRIUM";
        break;
    default:
        std::cout << '\t' << "You are not injured.";
        break;
	}
}

void Player::healAffliction()
{
	injury = -1;
}

void Player::grievousAffliction()
{
    std::cout << "[GRIEVOUS AFFLICTION] Your are too weak to continue, there is no hope of survival." << '\n';
}

