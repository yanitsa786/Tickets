
#pragma once 
#include <iostream>
#include <cstring>
#include "Tickets.h"


void Tickets::print()
{
	std::cout << this->name << " " << this->quantity << " ";
	std::cout << std::endl;
}

void Ticket::Ticket()
{
	quantity = 0;
}


class Tickets {

private:

	char name[30];
	char hall[10];
	char date[400];
	char note[200];
	int seat;
	int row;

public:

	//konstruktor

	Tickets();

	Tickets(char name, char date, char hall);

	
};

Tickets::Tickets(const char* _name, const char*_date, const char* _hall)
{

	strcpy(Name, _name);
	quantity = _quantity;

}


Tickets::Tickets(const Tickets& other)
{
	strcpy(Name, other.Name);
	quantity = other.quantity;
}

Tickets& Tickets::operator=(const Tickets& other)
{
	if (this != &other)
	{
		strcpy(Name, other.Name);
		quantity = other.quantity;
	}
	return *this;
}

Tickets& Tickets::operator+=(double _quantity)
{
	quantity += _quantity;
	return *this;
}

Tickets& Tickets::operator-=(double _quantity)
{
	quantity -= _quantity;
	return *this;
}



int main()
{
    
}


