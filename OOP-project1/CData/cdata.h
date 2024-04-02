#pragma once
#include <iostream>
enum Status { SUCCESS = 1, ERROR, WARNING };

class CDate{
	int day, month, year;
public:
	CDate();
	CDate(int day_, int month_, int year_);
	CDate(const CDate& data);
	~CDate();

	Status input();
	Status check();
	void output();
	Status convert();
	void assign(const CDate& data);
	void set_values(int day_, int month_, int year_);
	Status add_year(int  year_);
	Status add_month(int month_);
	Status add_day(int day_);
	Status sub_year(int  year_);
	Status sub_month(int month_);
	Status sub_day(int day_);
	int compare(const CDate& data);
};
