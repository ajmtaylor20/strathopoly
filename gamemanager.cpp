#include <iostream>
#include <fstream>
#include <limits>
#include <algorithm>
#include <sstream>

#include <stdlib.h>
#include <time.h>

#include "gamemanager.hpp"
#include "board.hpp"

/*GENERIC DATA GATHERING FROM USER*/
template<typename T>
T getData(std::vector<T> allowedValues = {})
{
	bool valid = true;
	T temp;
		
	do
	{
		std::cin >> temp;	//attempt to gather data
		
		/*IF ALL_VALS NOT EMPTY AND ENTERED DATA IS NOT IN THE LIST*/
		if ( (allowedValues.size() != 0) and (std::find(allowedValues.begin(), allowedValues.end(), temp) == allowedValues.end()) )
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Sorry, That Input Is Not Recognised. Please Re-Enter!: ";
			valid = false;
		}
		
		/*IF CIN FAILS, CLEAR CIN AND ASK FOR RE-ENTRY*/
		else if (std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			valid = false;
			std::cout << "Please Re-Enter Data \n";
		}else{valid = true;}
		
		
	}while(!valid);	//loop around until valid data is entered
	
	/*CLEAR CIN*/
	std::cin.clear();
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	
	return temp;
}


GameManager::~GameManager()
{
	if (this->gameboard != nullptr)
	{
		delete gameboard;
	}
}

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

std::vector<Player*> GameManager::getPlayers()
{
	int numplayers = 0;
	int token = 0;
	std::vector<Player*> playervector;
	
	std::cout << "How many players: ";	//get player stuff
	numplayers = getData<int>({2, 3, 4, 5, 6});
	std::cout << numplayers;
	
	for (int i = 0; i < numplayers; i++)
	{
		Player* temp = new Player;
		
		std::cout << "Please Enter Your Name, Player " << i+1 << ": ";
		std::string name = getData<std::string>();
		temp->setName(name);
		temp->setPosition(0);	//start at GO
		temp->setMoney(1500);	//start all players with $1500
		
		playervector.push_back(temp);	//place in vector
	}
	
	return playervector;
}

void GameManager::setup()
{
	/*CREATE A NEW GAMEBOARD AND STORE*/
	Board* gameboard_ = new Board;
	this->gameboard = gameboard_;
	
	/*CREATE SPACES FOR BOARD*/
	gameboard->setSpaces(readSpaces());	//store returned vector in gameboard
	
	/*GET PLAYER DATA*/
	gameboard->setPlayers(getPlayers());	//store returned vector in gameboard
	
}

void GameManager::start()
{
	
	/*GATHER CURRENT PLAYERS*/;
	
}

void GameManager::turn()
{
	/*FIND OUT WHAT SPACE THE USER IS ON*/
		;
}

/**************************************************/
/**************************************************/
/**************************************************/

/*DEBUG*/

/*PRINT OUT ALL CURRENT PLAYERS*/
void GameManager::printPlayers()
{
	auto vec = gameboard->getPlayers();
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		/*DEREFERENCE ITERATOR TWICE TO PRINT PLAYER*/
		std::cout << " " << *(*it) << " ";
	}
}

/*PRINT OUT ALL CURRENT SPACES*/
void GameManager::printSpaces()
{
	auto vec = gameboard->getSpaces();
	std::cout << "Alloc game board\n";
	std::cout << vec.size() << "\n";
	for (auto it = vec.begin(); it != vec.end(); it++)
	{
		/*DEREFERENCE ITERATOR TWICE TO PRINT PLAYER*/
		std::cout << *(*it);
	}
	std::cout << "finish print spaces" << "\n";
}
