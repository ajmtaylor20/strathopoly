#include <iostream>
#include <fstream>
#include <sstream>
#include "gamemanager.hpp"

std::vector<Space*> GameManager::readSpaces()
{	
	/*CREATE NEW VECTOR TO STORE SPACE OBJECTS*/
	std::vector<Space*> spacevector;

	/*OPEN SPACE FILE*/
	std::ifstream infile("spaces.csv");
	
	/*TRACK ROW SO ROW 0 CAN BE AVOIDED*/
	int row = 0;
	
	while (infile)
	{
		/*CREATE BUFFER STRING*/
		std::string datastring;
		
		if (!std::getline(infile, datastring)) {break;} //if getline fales, break the loop
		
		/*CREATE STRING STREAM FROM BUFFER STRING*/
		std::istringstream strStream(datastring);
		
		/*CREATE NEW OBJECT AND START AT COLUMN 0*/
		Space* temp = new Space;
		int column = 0;
		
		/*FOR THE DuRATION OF THE STRING STREAM*/
		while (strStream)
		{
			std::string datastring;
			if(!std::getline(strStream, datastring, ',')) {break;}	//break datastring up by comma
			
			/*IGNORE ROW 0 AS IT CONTAINS LABELS*/
			if (row != 0)
			{
				/*READ DATA FROM EACH COLUMN AND UPDATE TEMP OBKECT*/
				switch(column)
				{
					case 0:	temp->setName(datastring); break;
					case 1: temp->setSpaceType(datastring); break;
					case 2: temp->setDescription(datastring); break;
					case 3: temp->setRent(std::stoi(datastring)); break;
					case 4: temp->setPrice(std::stoi(datastring)); break;
				}
				column++;
			}else{;/*do nothing with label row*/}
		}
		
		if(row != 0){spacevector.push_back(temp);} /*STORE NEWLY CREATED SPACE INTO VECTOR*/
		row++;
	}
	
	return spacevector;
}

std::vector<Player*> getPlayers()
{
	;	//get player stuff.
}

void GameManager::setup()
{
	/*CREATE A NEW GAMEBOARD AND STORE*/
	Board* gameboard_ = new Board;
	this->gameboard = gameboard_;
	
	/*CREATE SPACES FOR BOARD*/
	gameboard->setSpacesVector(readSpaces());	//store returned vector in gameboard
	
	/*GET PLAYER DATA*/
	gameboard->setPlayers(getPlayers());	//store returned vector in gameboard 
	
}

void GameManager::start()
{
	/*INTERFACE STUFF HERE*/
}

void GameManager::turn()
{
	/*	ASK PLAYER WHAT TO DO
		
		CALL BOARD METHOD THAT DOES THE FOLLOWING THINGS:
			MOVE()	CALL PLAYER'S MOVE METHOD
			DELETE()	CALL IF PLAYER LEAVES GAME
			BUY()	BUY CURRENT SPACE
			SELL()	SELL A SPACE*/
		
}