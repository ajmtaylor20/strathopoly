#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include "player.hpp"

class Player;

/*DEFINE WHAT TYPES OF SPACE CAN EXIST*/
enum spaceTypes {JAIL, GO, GOTOJAIL, PROPERTY};

class Space
{
	private:
		std::string name;
		std::string description;
		Player* owner;
		spaceTypes spaceType;
		unsigned int rent;
	
	public:
		/*GETTERS*/
		std::string getName() const {return this->name;}
		std::string getDescription() const {return this->description;}
		Player* getOwner() const {return this->owner;}
		spaceTypes getSpaceType() const {return this->spaceType;}
		unsigned int getRent() const {return rent;}
		
		/*SETTERS*/
		void setName(std::string name_) {this->name = name_;}
		void setDescription(std::string description_) {this->description = description_;}
		void setOwner(Player* player) {this->owner = player;}
		void setSpaceType(spaceTypes type) {this->spaceType = type;}
		void setRent(int rent_) {this->rent = rent_;}
		
};

#endif