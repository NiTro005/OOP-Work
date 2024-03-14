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
	if (month > 12 || month < 1) {state = ERROR;}
	else if (day > 28 || day < 1) {
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {state = ERROR;}
		else if (month == 2 && day > 28) {
			state = ERROR;
			if (year % 4 == 0 && day == 29) { state = SUCCESS; }
		}
		else { state = ERROR; }
	}
	return state;
}


Status CData::convert() {
	Status state = SUCCESS;
	if (day > 28) {
		if ((month == 4 || month == 6 || month == 9 || month == 11) && day > 30) {
			month += 1;
			day = day - 30;
		}
		else if (month == 2) {
			month += 1;
			day = day - 28;
			if ((year % 4 == 0) && day < 30) { day--; }
		}
		else if((month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) && day > 31){
			month += 1;
			day = day - 31;
		}
	}
	if (month > 12) {
		year += 1;
		month = month - 12;
	}
	if (day < 1) {
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

void CData::assign(CData& data) {
	data.day = this->day;
	data.month = this->month;
	data.year = this->year;

}
void CData::set_values(int day_, int month_, int year_) {
	day = day_;
	month = month_;
	year = year_;
}

Status CData::add_day(int day_) {
	Status state = SUCCESS;
	day += day_;
	if (day > 28)  state = convert();
	return state;
}


Status CData::add_month(int month_) {
	Status state = SUCCESS;
	month += month_;
	if (month > 12) {
		state = convert();
	}
	return state;

}
Status CData::add_year(int year_) {
	Status state = SUCCESS;
	year += year_;
	return state;
}
Status CData::sub_day(int day_) {
	Status state = SUCCESS;
	day -= day_;
	if (day < 1) {
		state = convert();
	}
	return state;
}

Status CData::sub_month(int month_) {
	Status state = SUCCESS;
	month -= month_;
	if (month < 1) {
		state = convert();
	}
	return state;

}
Status CData::sub_year(int year_) {
	Status state = SUCCESS;
	year -= year_;
	if (year < 0) {
		state = convert();
	}
	return state;
}

int CData::compare(const CData& data) {
	if (day == data.day && month == data.month && year == data.year) return 0;

	// data1 > data2
	if (year > data.year) return 1;
	if (month > data.month && data.year <= year) return 1;
	if (day > data.day && data.month <= month && data.year <= year) return 1;

	// data1 < data2
	if (data.year > year) return -1;
	if (data.month > month && year <= data.year) return -1;
	if (data.day > day && month <= data.month && year <= data.year) return -1;
}

CData::~CData() {}