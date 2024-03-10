#include "ctime.h"
#include <iostream>

Status check();
Status convert();
void output();

CTime::CTime(){
	int hours = 0;
	int minutes = 0;
	int seconds = 0;
}
CTime::CTime(int hours_, int minutes_, int seconds_) 
{
	hours = hours_;
	minutes = minutes_;
	seconds = seconds_;
}
CTime::CTime(const CTime& time) {
	hours = time.hours;
	minutes = time.minutes;
	seconds = time.seconds;
}

Status CTime :: input() {
	Status state = SUCCESS;
	char colon;
	std::cin >> hours >> colon
		>> minutes >> colon
		>> seconds;
	state = check();
	if (state == ERROR) {
		state = convert();
		
	}
	if(state != ERROR){
		output();
	}
	return state;
}

Status CTime::check() {
	Status state = SUCCESS;
	if (hours > 23 || hours < 0) {
		state = ERROR;
	}
	else if (minutes > 59 || minutes < 0) {
		state = ERROR;
	}
	else if (seconds > 59 || seconds < 0) {
		state = ERROR;
	}
	return state;
}

Status CTime::convert() {
	Status state = SUCCESS;
	if (seconds >= 60) {
		minutes += 1;
		seconds = seconds - 60;
	}
	if (minutes >= 60) {
		hours += 1;
		minutes = minutes - 60;
	}
	if (hours >= 24 && hours <= 48) {
		hours = hours - 24;
		state = WARNING;
	}
	if (seconds < 0) {
		minutes -= 1;
		seconds = seconds + 60;
	}
	if (minutes < 0) {
		hours -= 1;
		minutes = minutes + 60;
	}
	if (hours < 0) {
		hours = 24 + hours;
		state = WARNING;
	}
	if (seconds >= 60 || minutes >= 60 || hours >= 24 || seconds < 0 || minutes < 0 || hours < 0)
		state = ERROR;
	return state;
}

void CTime::output() {
	std::cout << hours << ":"
		<< minutes << ":"
		<< seconds << std::endl;
}

CTime::~CTime() {}