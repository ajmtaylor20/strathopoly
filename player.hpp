#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <string>

#include "space.hpp"

/*PROPERTY COLOURS*/
//enum colours = {brown, light_blue, pink, orange, red, yellow, green, dark_blue};

enum class Tokens {car, dog, hat, thimble};

class Space;

class Player
{
	private:
		std::string name;
		unsigned int position;
		unsigned int money;
		Tokens token;
		
	public:
		/*SETTERS*/
		void setName(std::string name_) {this->name = name_;}
		void setPosition(unsigned int pos) {this->position = pos;}
		void setToken(Tokens token_) {this->token = token_;}
		void setMoney(unsigned int money_) {this->money = money_;}
		
		/*GETTERS*/
		std::string getName() const {return this->name;}
		unsigned int getPosition() const {return this->position;}
		unsigned int getMoney() const {return this->money;}
		Tokens getToken() const {return this->token;}
						
		/*CHANGE MONEY BY A CERTAIN AMOUNT +/-*/
		void changeMoney(int);
		
		/*MOVE PLAYER BY AN AMOUNT*/
		void move(int);
};

#endif