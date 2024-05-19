#pragma once
#include <iostream>

enum Stat { Success = 1, Error, Warning };

class CDate{
	int day, month, year;
public:
	CDate();
	CDate(int day_, int month_, int year_);
	CDate(const CDate& data);
	~CDate();

	Stat input();
	Stat check();
	void output();
	Stat convert();
	void assign(const CDate& data);
	void set_values(int day_, int month_, int year_);
	Stat add_year(int  year_);
	Stat add_month(int month_);
	Stat add_day(int day_);
	Stat sub_year(int  year_);
	Stat sub_month(int month_);
	Stat sub_day(int day_);
	int compare(const CDate& data);
	bool operator==(const CDate& other) const {
		return (day == other.day && month == other.month && year == other.year);
	}
};
