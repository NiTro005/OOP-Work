#include "cdata.h"

CData::CData() {
	int day = 0;
	int month = 0;
	int year = 0;
}
CData::CData(int day_, int month_, int year_)
{
	day = day_;
	month = month_;
	year = year_;
}
CData::CData(const CData& data) {
	day = data.day;
	month = data.month;
	year = data.year;
}

Status CData::input() {
	Status state = SUCCESS;
	char colon;
	std::cin >> day >> colon
		>> month >> colon
		>> year;
	state = check();
	if (state == ERROR) {
		state = convert();

	}
	if (state != ERROR) {
		output();
	}
	return state;
}

Status CData::check() {
	Status state = SUCCESS;
	if (month > 12 || month < 1) {
		state = ERROR;
	}
	else if (day > 31 || day < 1) {
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
			state = ERROR;
		}
		else if (month == 2 && day > 28) {
			state = ERROR;
			if ((year % 4 == 0) && day < 30) { state = SUCCESS; }
		}
		else { state = ERROR; }
	}
	return state;
}


Status CData::convert() {
	Status state = SUCCESS;
	if (day > 31) {
		if (month == 4 || month == 6 || month == 9 || month == 11) {
			month += 1;
			day = day - 30;
		}
		else if (month == 2) {
			month += 1;
			day = day - 28;
			if ((year % 4 == 0) && day < 30) { day--; }
		}
		else if(month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12){
			month += 1;
			day = day - 31;
		}
	}
	if (month > 12) {
		year += 1;
		month = month - 12;
	}
	if (day < 0) {
		month -= 1;
		day = day + 31;
	}
	if (month < 1) {
		year -= 1;
		month = month + 12;
	}
	if (year < 0) {
		state = WARNING;
	}
	if (day > 31 || month > 12 || day < 1 || month < 1) {
		state = ERROR;
	}
	return state;
}


void CData::output() {
	std::cout << day << "."
		<< month << "."
		<< year << std::endl;
}

CData::~CData() {}