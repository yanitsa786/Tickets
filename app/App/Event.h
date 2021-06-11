
#pragma once
#include <string>
#include <vector>
#include "Seat.h"
#include "Row.h"
using std::vector; //std::vector e konteiner za posledovatelnost, koito kapsulira masivi s dinamichen razmer
using std::string;

class Event
{
	string Event_Name;
	Date date;
	vector<Row> rows;
	int Hall_Index;

public:
	Event() //defaulten constructor
	{
		Hall_Index = 0;
	}

	Event(const string& _Event_Name, size_t Number_Of_Rows, size_t Number_Of_Colums, const Date& _date, size_t _Hall_Index) //konstruktor s parametri
	{
		Event_Name = _Event_Name;
		date = _date;
		Hall_Index = _Hall_Index;

		for (int i = 0; i < Number_Of_Rows; i++) 
		{
			Row new_row(i, Number_Of_Colums);
			rows.push_back(new_row);
		}
	}

	string get_Event_Name() const
	{
		return Event_Name;
	}

	int get_Hall_Index() const
	{
		return Hall_Index;
	}

	int get_Number_Of_Columns() const
	{
		if (rows.empty()) 
		{
			return 0;
		}
		
			return rows[0].size();
		
	}

	int get_All_Seats() const
	{
		if (rows.empty()) 
		{
			return 0;
		}
		else 
		{
			return rows.size() * get_Number_Of_Columns();
		}
	}

	int get_Booked_Seats() const 
	{
		int counter = 0;
		for (int i = 0; i < rows.size(); i++)
		{
			for (int j = 0; j < rows[i].size(); j++)
			{
				if (rows[i][j].is_booked())
				{
					counter++;
				}
			}
		}
		return counter;
	}

	int get_Free_Seats() const
	{
		return get_All_Seats() - get_Booked_Seats();
	}

	int get_booked_seats_which_are_not_bought() const
	{
		int counter = 0;
		for (int i = 0; i < rows.size(); i++) 
		{
			for (int j = 0; j < rows[i].size(); j++)
			{
				if (rows[i][j].is_booked() && !rows[i][j].is_bought())
				{
					counter++;
				}
			}
		}
		return counter;
	}

	int get_bought_seats_in_date_interval(const Date& date_from, const Date& date_to) const
	{
		int counter = 0;
		for (int i = 0; i < rows.size(); i++)
		{
			for (int j = 0; j < rows[i].size(); j++) 
			{
				if (rows[i][j].is_bought_in_date_interval(date_from, date_to)) 
				{
					counter++;
				}
			}
		}
		return counter;
	}

	int get_Seat_Number(int serial_number) 
	{
		for (int i = 0; i < rows.size(); i++)
		{
			for (int j = 0; j < rows[i].size(); j++) 
			{
				if (rows[i][j].get_ticket_serial_number() == serial_number)
				{
					return j;
				}
			}
		}
		return -1;
	}

	Date get_date() const
	{
		return date;
	}

	bool is_valid(size_t Row_Number, size_t Seat_Number) const
	{
		return 0 <= Row_Number && Row_Number < rows.size()
			&& 0 <= Seat_Number && Seat_Number < get_Number_Of_Columns();
	}

	bool is_booked(size_t Row_Number, size_t Seat_Number) const
	{
		return rows[Row_Number][Seat_Number].is_booked();
	}

	bool is_bought(size_t Row_Number, size_t Seat_Number) const
	{
		return rows[Row_Number][Seat_Number].is_bought();
	}

	void book_seat(size_t Row_Number, size_t Seat_Number, const string& note)
	{
		if (!is_booked(Row_Number, Seat_Number))
		{
			rows[Row_Number][Seat_Number].book();
			rows[Row_Number][Seat_Number].set_note(note);
		}
	}

	void unbook_seat(size_t Row_Number, size_t Seat_Number)
	{
		if (is_booked(Row_Number, Seat_Number))
		{
			rows[Row_Number][Seat_Number].unbook();
			rows[Row_Number][Seat_Number].set_note("");
		}
	}

	void buy_ticket(size_t Row_Number, size_t Seat_Number)
	{
		if (!is_bought(Row_Number, Seat_Number)) 
		{
			rows[Row_Number][Seat_Number].buy();
		}
	}
};
