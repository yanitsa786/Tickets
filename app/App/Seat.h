#pragma once
#include<string>
#include<cstdlib>
#include<ctime>
#include"Date.h"
using std::string;

class Seat
{
	size_t Row_Number;
	size_t Seat_Number;
	bool booked;
	string note;
	size_t ticket_serial_number;
	Date date_of_buying;


	
	Date Today_date() 
	{
		time_t now = time(0); //tipe_t is time-related type
		tm* apparent_time = localtime(&now);  //type tm holds the date and time in the form of a C structure
		int year = 1900 + apparent_time->tm_year; //year since 1900
		int month = 1 + apparent_time->tm_mon; //month of year from 0 to 11
		int day = apparent_time->tm_mday; //day of month from 1 to 31
		Date date(year, month, day);

		return Today_date();
	}
	
	//https://www.tutorialspoint.com/cplusplus/cpp_date_time.htm - source

public:

	Seat()
	{
		Row_Number = 0;
		Seat_Number = 0;
		booked = false;
		note = "";
		ticket_serial_number = 0;
	}

	Seat(size_t _Row_Number, size_t _Seat_Number)
	{
		Row_Number = _Row_Number;
		Seat_Number = _Seat_Number;
		booked = false;
		note = "";
		ticket_serial_number = 0;
	}

	bool is_bought_in_date_interval(const Date& date_from, const Date& date_to) const 
	{
		return date_of_buying >= date_from && date_of_buying <= date_to;

	}

	bool is_booked() const 
	{
		return booked;
	}

	void book() 
	{
		booked = true;
	}

	void unbook() 
	{
		booked = false;
	}


	void set_note(const string& _note) 
	{
		note = _note;
	}

	string get_note() const
	{
		return note;
	}


	bool is_bought() const
	{
		return ticket_serial_number != 0;
	}

	void buy() 
	{
		if (!is_bought())
		{
			book();
			ticket_serial_number = (Row_Number * 100 + Seat_Number) * 10000;
			date_of_buying = Today_date();
		}
	}

	int get_ticket_serial_number() const
	{
		return ticket_serial_number;
	}
};