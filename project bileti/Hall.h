
#pragma once //directive that allows the file to be added only once until compilation
#include <vector> //constructing vectors or constructing vectors from arrays
#include "Date.h"
using std::vector; //std::vector is a sequence container that encapsulates dynamic size arrays

class Hall // creating class Hall
{
	//size_t - celi i polojielni chisla 
	size_t Hall_Number;  //номер на залата
	size_t Cnt_Rows; //редове 
	size_t Seats_On_Row; // брой места по редове
    vector<Date> booked_dates;

public:

	Hall() 
	
	{
		Hall_Number = 0;
		Cnt_Rows = 0;
		Seats_On_Row = 0;
		booked_dates = vector<Date>();
	}

	Hall(size_t _Hall_Number, size_t _Cnt_Rows, size_t _Seats_On_Row) //Constructor with parameters
	{
		Hall_Number = _Hall_Number;
		Cnt_Rows = _Cnt_Rows;
		Seats_On_Row = _Seats_On_Row;
		booked_dates = vector<Date>();
	}


	

	void book(const Date& date) //function for booking date
	{
		booked_dates.push_back(date); //zapazva se svobodna data, sled veche zaetite 
	}

	bool is_free(const Date& date) const  //proverqvame svobodna li e dadena data
	{
		for (int i = 0; i < booked_dates.size(); i++) //proverka
		{
			if (booked_dates[i] == date) // ako veche zaetite dati suvpadat s tazi , za koqto zapazvame vrushtame false
			{
				return false;
			}
		}
		return true; // ako e svobodna , vrushtame true
	}

	bool is_booked(const Date& date) const //proverqvame zapazena li e datata
	{
		return !is_free(date); //vrushtame false , ako e svobodna 
	}

	size_t get_Hall_Number() const
	{
		return Hall_Number;
	}

	size_t get_Number_Of_Rows() const 
	{
		return Cnt_Rows;
	}

	size_t get_Number_Of_Colums() const
	{
		return Seats_On_Row;
	}

};