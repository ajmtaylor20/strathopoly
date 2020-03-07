#ifndef BOARD_HPP
#define BOARD_HPP

#include <iostream>
#include <vector>
#include <string>

#include "player.hpp"

class Board
{
	private:
		
		std::vector<Space*> spaces;
		std::vector<Player*> players;
		std::vector<Player*> jail;
		
	public:
		
		/*ONLY ALLOW A FULLY INITIALISED BOARD*/
		Board(std::vector<Space*>, std::vector<Player*>, std::vector<Player*>);
		~Board();
		
		/*FIND A SPACE BY NAME. SPACE INDEX IS RETURNED*/
		int findSpace(std::string);	//note, returns -1 if space was not found
		
		/*SETTERS*/
		void setSpacesVector(std::vector<Space*> spaces_) {this->spaces = spaces_;}
		void setPlayersVector(std::vector<Player*> players_) {this->players= players_;}
		void setJailedPlayersVector(std::vector<Player*> jail_) {this->jail = jail_;}
		
		/*GETTERS*/
		std::vector<Space*> getSpacesVector() const {return this->spaces;}
		std::vector<Player*> getPlayersVector() const {return this->players;}
		std::vector<Player*> getJailedPlayersVector() const {return this->jail;}
				
		/*RETURNS TRUE IF PLAYER IS JAILED*/
		bool isJailed(Player*);	
		
		/*RETURN THE NUMBER OF SPACES ON THE BOARD*/
		unsigned int getNumberOfSpaces();
		
		/*PLAYER FUNCTIONS*/
		void jailPlayer(Player*); 		//move to jail square and place in jail continaer
		void movePlayer(Player*); 	//move player by some amount
		
		/*SPACE FUNCTIONS*/
		void activateSpace(Player*);	//can get everything it needs from the player pointer
		
};

#endif