#include "space.hpp"
#include <iostream>

std::ostream& operator<<(std::ostream &out, const Space &space)
{
	out
	<< "Name: " << space.name << "\n"
	<< "Description: " << space.description << "\n"
	<< "Type: " << space.spaceType << "\n"
	<< "Rent: " << space.rent << "\n"
	<< "Price: " << space.price << "\n";
	
	return out;
}