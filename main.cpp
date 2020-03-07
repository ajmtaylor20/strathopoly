#include <iostream>
#include <vector>
#include "gamemanager.hpp"
int main()
{
	GameManager mygame;
	mygame.setup();
	mygame.printPlayers();
	mygame.printSpaces();

	return 0;
}