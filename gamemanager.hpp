#ifndef GAMEMANAGER_HPP
#define GAMEMANAGER_HPP

/*GAME MANAGER HANDLES COMMUNICATION BETWEEN CLASSES*/

#include "player.hpp"
#include "space.hpp"
#include "board.hpp"

class Player;
class Space;
class Board;

class GameManager
{
	private:
		Board* gameboard;
		
		/*ITERATOR FOR CURRENT PLAYER*/
		std::vector<Player*>::iterator currentPlayer;
		
	public:
	
		GameManager() {};
		~GameManager() {};
	
		void setBoard(Board* brd) {this->gameboard = brd;}
		Board* getBoard () const {return this->gameboard;}

		/*READ IN SPACE DATA IN CSV FORMAT*/
		std::vector<Space*> readSpaces();
		
		/*GET PLAYERS INFO*/
		std::vector<Player*> getPlayers();
		
		/*READ IN DATA AND FINALISE GAMEBOARD*/
		void setup();
		
		/*MAIN GAMECODE GOES HERE*/
		void start();
		
		/*LET'S A PLAYER TAKE THEIR TURN*/
		void turn();
		
		/*DEBUG FUNCTIONS*/
		void printPlayers();
		
};



#endif