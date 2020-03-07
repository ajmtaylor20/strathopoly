#ifndef SPACE_HPP
#define SPACE_HPP

#include <iostream>
#include <string>
#include "player.hpp"

class Player;

class Space
{
	private:
		std::string name;
		std::string description;
		Player* owner;
		std::string spaceType;
		unsigned int rent, price;
	
	public:
		/*GETTERS*/
		std::string getName() const {return this->name;}
		std::string getDescription() const {return this->description;}
		Player* getOwner() const {return this->owner;}
		std::string getSpaceType() const {return this->spaceType;}
		unsigned int getRent() const {return this->rent;}
		unsigned int getPrice() const {return this->price;}
		
		/*SETTERS*/
		void setName(std::string name_) {this->name = name_;}
		void setDescription(std::string description_) {this->description = description_;}
		void setOwner(Player* player) {this->owner = player;}
		void setSpaceType(std::string type) {this->spaceType = type;}
		void setRent(int rent_) {this->rent = rent_;}
		void setPrice(int price_) {this->price = price_;}
		
		/*OVERLOAD << OPERATOR [OUTPUT STREAMS]*/
		friend std::ostream& operator<<(std::ostream &out, const Space &space);
		
		
};

#endif