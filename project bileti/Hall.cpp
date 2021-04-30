
#pragma once
#include "Hall.h" // инклудваме само холл.х , тъй като сме в цпп


// сетър за номера на залата
void Hall::setHall_Number(size_t newHall_Number)
{
	hall_Number = newHall_Number;
}

//сетър за редовете
void Hall::setCnt_Rows(size_t newCnt_Rows)
{
	cnt_Rows = newCnt_Rows;
}

//сетър за местата на ред
void Hall::setSeats_On_Row(size_t newSeats_On_Row)
{
	seats_On_Row = newSeats_On_Row;
}

//гетър за номер на залата
size_t Hall::getHall_Number() const
{
	return hall_Number;
}

//гетър за редовете
size_t Hall::getCnt_Rows() const
{
	return cnt_Rows;
}
//гетър за местата на ред
size_t Hall::getSeats_On_Row() const
{
	return seats_On_Row;
}

//дефолтен конструтор /конструктор за общо ползване 
Hall::Hall()
{
	this->setHall_Number(200);
	this->setCnt_Rows(10);
	this->setSeats_On_Row(9);
}

//консруктор, който не е дефолтен
Hall::Hall(size_t newHall_Number, size_t newCnt_Rows, size_t newSeats_On_Row)
{
	this->setHall_Number(newHall_Number);
	this->setCnt_Rows(newCnt_Rows);
	this->setSeats_On_Row(newSeats_On_Row);
}