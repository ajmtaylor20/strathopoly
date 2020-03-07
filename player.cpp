#include <iostream>
#include "player.hpp"

void Player::move(int x)
{
	this->position += x;
}

void Player::changeMoney(int x)
{
	this->money += x;
}

std::ostream& operator<<(std::ostream &out, const Player &player)
{
	out << "Name: " << player.name << ". Wealth: $" << player.money << std::endl;
	return out;
}