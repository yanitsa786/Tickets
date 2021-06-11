
#pragma once
#include<iostream>
#include<string>
#include<vector>
#include "Hall.h"
#include "Event.h"
#include "Date.h"
using std::string;
using std::vector;
using std::cin;
using std::cout;
using std::endl;


class App
{
	vector<Hall> halls;
	vector<Event> events;


	Event* find_event(const string& Event_Name, const Date& date) 
	{
		for (int i = 0; i < events.size(); i++)
		{
			if (events[i].get_Event_Name() == Event_Name && events[i].get_date() == date)
			{
				return &(events[i]);
			}
		}
		return nullptr;
	}


	void add_event()
	{
		Date date;
		size_t Index_Of_Hall;
		string Event_Name;

		cin >> date >> Index_Of_Hall >> Event_Name;

		if (halls[Index_Of_Hall].is_booked(date))
		{
			cout << "Hall is not available !" << endl;
		}

		else 
		{
			size_t Number_Of_Rows = halls[Index_Of_Hall].get_Number_Of_Rows();
			size_t Number_Of_Colums = halls[Index_Of_Hall].get_Number_Of_Colums();
			Event New_Event(Event_Name, Number_Of_Rows, Number_Of_Colums, date, Index_Of_Hall);
			events.push_back(New_Event);
			halls[Index_Of_Hall].book(date);
		}
	}


	void free_seats() 
	{
		string Event_Name;
		Date date;

		cin >> Event_Name >> date;

		Event* Found_Event = find_event(Event_Name, date);

		if (Found_Event != nullptr)
		{
			cout << Found_Event->get_Free_Seats() << endl;
		}

		else
		{
			cout << "Event is not found!" << endl;
		}
	}


	void book()
	{
		size_t Row_Number;
		size_t Seat_Number;
		Date date;
		string Event_Name;
		string note;

		cin >> Row_Number >> Seat_Number >> date >> Event_Name >> note;

		Event* Found_Event = find_event(Event_Name, date);

		if (Found_Event != nullptr) 
		{
			if (Found_Event->is_valid(Row_Number, Seat_Number) && !Found_Event->is_booked(Row_Number, Seat_Number))
			{
				Found_Event->book_seat(Row_Number, Seat_Number, note);
			}
			else
			{
				cout << "Seat is not available or it's already booked !" << endl;
			}
		}
		else
		{
			cout << "Event is not found !" << endl;
		}
	}


	void unbook()
	{
		size_t Row_Number;
		size_t Seat_Number;
		Date date;
		string Event_Name;

		cin >> Row_Number >> Seat_Number >> date >> Event_Name;

		Event* Found_Event = find_event(Event_Name, date);

		if (Found_Event != nullptr) 
		{
			if (Found_Event->is_valid(Row_Number, Seat_Number) && Found_Event->is_booked(Row_Number, Seat_Number)) 
			{
				Found_Event->unbook_seat(Row_Number, Seat_Number);
			}
			else 
			{
				cout << "Seat is not available or it's not booked!" << endl;
			}
		}
		else
		{
			cout << "Event is not found!" << endl;
		}
	}


	void buy() 
	{
		size_t Row_Number;
		size_t Seat_Number;
		Date date;
		string Event_Name;

		cin >> Row_Number >> Seat_Number >> date >> Event_Name;

		Event* Found_Event = find_event(Event_Name, date);

		if (Found_Event != nullptr) 
		{
			if (Found_Event->is_valid(Row_Number, Seat_Number) && !Found_Event->is_bought(Row_Number, Seat_Number))
			{
				Found_Event->buy_ticket(Row_Number, Seat_Number);
			}
			else 
			{
				cout << "Seat is not available or it's already bought! Please choose another seat!" << endl;
			}
		}
		else 
		{
			cout << "Event is not found!" << endl;
		}
	}


	
	void check()
	{
		size_t Serial_Number;
		cin >> Serial_Number;
		for (int i = 0; i < events.size(); i++) 
		{
			size_t Seat_Number = events[i].get_Seat_Number(Serial_Number);
			if (Seat_Number != -1)
			{
				cout << "Ticket is valid ! Seat: " << Seat_Number << endl;
			}
			else 
			{
				cout << "Ticket is not valid !" << endl;
			}
		}
	}


	void report() 
	{
		Date date_from;
		Date date_to;
		cin >> date_from >> date_to;

		size_t Hall_Index;
		bool we_have_read_hall = false;

		if (cin.peek() != '\n') //https://www.cplusplus.com/reference/istream/istream/peek/ - source
		//Returns the next character in the input sequence, without extracting it: The character is left as the next character to be extracted from the stream.
		{
			cin >> Hall_Index;
			we_have_read_hall = true;
		}

		for (int i = 0; i < events.size(); i++)
		{
			if (!we_have_read_hall || events[i].get_Hall_Index() == Hall_Index)
			{
				cout << events[i].get_Event_Name() << ", " << events[i].get_date() << ": "
					<< events[i].get_bought_seats_in_date_interval(date_from, date_to) << endl;
			}
		}
	}

public:
	void run() 
	{
		cout << "Please enter  dates in this format: YYYY-MM-DD !" << endl;

		string command;

		while (true) 
		{
			cin >> command;

			if (command == "addevent") {
				add_event();
			}
			else if (command == "freeseats") {
				free_seats();
			}
			else if (command == "book") {
				book();
			}
			else if (command == "unbook") {
				unbook();
			}
			else if (command == "buy") {
				buy();
			}
			else if (command == "check") {
				check();
			}
			else if (command == "report") {
				report();
			}
		}
	}
};
