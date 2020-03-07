#include <iostream>
#include <vector>

#include <stdlib.h>
#include <time.h>

#include "board.hpp"

struct dice
{
	int die1, die2;
};

dice rolldice()
{	
	dice temp;
	srand((unsigned) time(0)); //seed random number generator
	temp.die1 = 1+ (rand() % 6); 	// 'roll' first die
	temp.die2 = 1+ (rand() % 6);	// 'roll' second die
	return temp;
}

Board::Board(){}

Board::Board(std::vector<Space*> spaces_, std::vector<Player*> players_, std::vector<Player*> jail_)
{
	this->spaces = spaces_; this->players = players_; this->jail = jail_;
}

int Board::findSpace(std::string name)
{
	/*CREATE ITERATOR AND ITERATE UNTIL THE END OF THE SPACES LIST*/
	for (std::vector<Space*>::iterator it = this->spaces.begin(); it != this->spaces.end(); it++)
	{
		if ((*it)->getName() == name)
		{
			return (std::distance(spaces.begin(), it));	//return space index
		}
	}
	
	return -1;
}

Board::~Board()
{
	/*CREATE ITERATOR AND ITERATE UNTIL THE END OF THE SPACES LIST*/
	for (std::vector<Space*>::iterator it = this->spaces.begin(); it != this->spaces.end(); it++)
	{
		if (*it != nullptr)
		{
			/*FREE MEMORY ALLOCATED FOR SPACE*/
			delete *it;
			
			/*REMOVE FROM VECTOR*/
			this->spaces.erase(it);
		}
	}
	
	/*CREATE ITERATOR AND ITERATE UNTIL THE END OF THE PLAYERS LIST*/
	for (std::vector<Player*>::iterator it = this->players.begin(); it != this->players.end(); it++)
	{
		if (*it != nullptr)
		{
			/*FREE MEMORY ALLOCATED FOR PLAYER*/
			delete *it;
			
			/*REMOVE FROM VECTOR*/
			this->players.erase(it);
		}
	}
}


bool Board::isJailed(Player* player)
{
	bool isjailed = false;
	
	for (std::vector<Player*>::iterator it = this->jail.begin(); it != this->jail.end(); it++)
	{
		if (player = *it)
		{
			isjailed = true;
		}
	}
	
	return isjailed;
}


unsigned int Board::getNumberOfSpaces()
{
	return this->spaces.size();
}

void Board::jailPlayer(Player* player)
{
	/*IF PLAYER IS NOT JAILED*/
	if (!(this->isJailed(player)))
	{
		/*ADD AND MOVE TO JAIL*/
		jail.push_back(player);
		player->setPosition(this->findSpace("jail"));	//avoids passing go
	}
}

void Board::movePlayer(Player* player)
{
	/*ROLL DICE*/
	dice roll = rolldice();
	int moveTotal = roll.die1 + roll.die2;
	
	/*TODO CHECK IF MOVE IS A DOUBLE, AND LET MULTIPLE ROLLS HAPPEN. IMPLEMENT GO SPACE STUFF*/
	
	/*MOVE PLAYER AND ACTIVATE THE SPACE*/
	
	/*IF THE MOVE WILL TAKE THE PLAYER PASSED THE TOTAL NUMBER OF SPACES, WRAP AROUND*/
	if ((player->getPosition() + moveTotal) >= (this->spaces.size()))
	{
		int currentPosition = player->getPosition();
		int newPosition = (currentPosition + moveTotal) - spaces.size();
		player->setPosition(newPosition);
	}else{
		player->move(moveTotal);		//simply move the player with the move method
	}
}

void Board::activateSpace(Player* player)
{
	/*GET THE SPACE TYPE FROM THE SPACE OBJECT*/
	std::string type = spaces[player->getPosition()]->getSpaceType();
	
	/*EXECUTE CODE DEPENDING ON TYPE*/
	if (type == "GO")
	{
		;//GO CODE
	}
	else if (type == "JAIL")
	{
		;//JAIL CODE
	}
	else if (type == "GOTOJAIL")
	{
		;//GOTO JAIL CODE
	}
	else if (type == "PROPERTY")
	{
		;//PROPRETY CODE
	}
}

