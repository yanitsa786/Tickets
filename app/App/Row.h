#pragma once
#include<vector>
#include "Seat.h"
using std::vector;

class Row 
{
	size_t Row_Number;
	vector<Seat> seats;

public:
	Row()
	{
		Row_Number = 0;
	}

	Row(size_t _Row_Number, size_t Number_Of_Seats)
	{
		Row_Number = _Row_Number;
		for (int i = 0; i < Number_Of_Seats; i++)
		{
			Seat seat(_Row_Number, i);
			seats.push_back(seat);
		}
	}

	size_t size() const
	{
		return seats.size();
	}

	Seat& operator[](size_t i)
	{
		return seats[i];
	}

	const Seat& operator[](size_t i) const 
	{
		return seats[i];
	}
};