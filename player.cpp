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