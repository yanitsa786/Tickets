
#pragma once //директива , която поставя ограничение даден файл да бъде добавен само веднъж по време на компилиране
#include <string>
#include <fstream> //Stream class to both read and write from/to files
using std::istream; // za da moga da izpolzvam >> 
using std::ostream; // za da moga da izpolzvam <<  
using std::string; 
using std::to_string;

class Date 
{
	string Date_As_String;		// YYYY-MM-DD

public:
	Date() //defaut constructor

	{
		Date_As_String = "";
	}

	Date(const string& _date) //copy constructor
	{
		Date_As_String = _date;
	}

	Date(size_t year, size_t month, size_t day) //constructor with parameters
	
	{
		string Month_As_String = to_string(month); // month & day = string
		string Day_As_String = to_string(day);

		if (month < 10)
		{
			Month_As_String = "0" + Month_As_String; //pr 01,02....09
		}

		if (day < 10) 
		{
			Day_As_String = "0" + Day_As_String; //pr 01,02....09
		}

		Date_As_String = to_string(year) + "-" + Month_As_String + "-" + Day_As_String; 2000-09-02
	}

	bool operator==(const Date& other) const 
	{
		return Date_As_String == other.Date_As_String;
	}

	// "2000-05-12" < "2021-04-09"
	// "2020-09-08" < "2021-09-08"
	bool operator<(const Date& other) const 
	{
		return Date_As_String < other.Date_As_String;
	}

	bool operator<=(const Date& other) const 
	{
		return Date_As_String <= other.Date_As_String;
	}

	bool operator>=(const Date& other) const
	{
		return Date_As_String >= other.Date_As_String;
	}

	friend istream& operator>>(istream& in, Date& date); //credit github  , friend function 
	friend ostream& operator<<(ostream& out, const Date& date); 
};

istream& operator>>(istream& in, Date& date) //operator za izvlichane na informaciq , prilojen kym vhodqsht potok
{
	in >> date.Date_As_String;

	return in;
}

ostream& operator<<(ostream& out, const Date& date) //output na informaciqta , pr out << 2021-02-16 
{
	out << date.Date_As_String;

	return out;
}

