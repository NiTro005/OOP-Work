#include "ctime.h"
#include <iostream>


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

void CTime::assign(const CTime& time) {
		this->hours = time.hours;
		this->minutes = time.minutes;
		this->seconds = time.seconds;

}
void CTime:: set_values(int hours_, int minutes_, int seconds_) {
	Status state = SUCCESS;
	hours = hours_;
	minutes = minutes_;
	seconds = seconds_;
}

Status CTime:: add_hours(int hours_) {
	Status state = SUCCESS;
	hours += hours_;
	if (hours >= 24) { state = convert(); }
	return state;
}

Status CTime::add_minutes(int minutes_) {
	Status state = SUCCESS;
	minutes += minutes_;
	if (minutes >= 60) {
		state = convert();
	}
	return state;
}

Status CTime::add_seconds(int seconds_) {
	Status state = SUCCESS;
	seconds += seconds_;
	if (seconds >= 60) {
		state = convert();
	}
	return state;
}

Status CTime::sub_hours(int hours_) {
	Status state = SUCCESS;
	hours -= hours_;
	if (hours < 0) {
		state = convert();
	}
	return state;
}

Status CTime::sub_minutes(int minutes_) {
	Status state = SUCCESS;
	minutes -= minutes_;
	if (minutes < 0) {
		state = convert();
	}
	return state;
}

Status CTime::sub_seconds(int seconds_) {
	Status state = SUCCESS;
	seconds -= seconds_;
	if (seconds < 0) {
		state = convert();
	}
	return state;
}

int CTime::compare(const CTime& time) {
	if (hours == time.hours && minutes == time.minutes && seconds == time.seconds) return 0;

	// time1 > time2
	if (hours > time.hours) return 1;
	if (minutes > time.minutes && time.hours <= hours) return 1;
	if (seconds > time.seconds && time.minutes <= minutes && time.hours <= hours) return 1;

	// time1 < time2
	if (time.hours > hours) return -1;
	if (time.minutes > minutes && hours <= time.hours) return -1;
	if (time.seconds > seconds && minutes <= time.minutes && hours <= time.hours) return -1;
}

bool CTime:: operator<=(const CTime& other) const {
	if (hours < other.hours) {
		return true;
	}
	else if (hours > other.hours) {
		return false;
	}
	else {
		if (minutes < other.minutes) {
			return true;
		}
		else if (minutes > other.minutes) {
			return false;
		}
		else {
			return seconds <= other.seconds;
		}
	}
}

// перегрузка оператора +
CTime CTime::operator+(float value) const {
	int totalSeconds = static_cast<int>(value) + seconds;
	int totalMinutes = totalSeconds / 60 + minutes;
	int totalHours = totalMinutes / 60 + hours;

	totalSeconds %= 60;
	totalMinutes %= 60;

	return CTime(totalHours, totalMinutes, totalSeconds);
}

bool CTime::operator>(const CTime& other) const {
	if (hours > other.hours) {
		return true;
	}
	else if (hours < other.hours) {
		return false;
	}
	else {
		if (minutes > other.minutes) {
			return true;
		}
		else if (minutes < other.minutes) {
			return false;
		}
		else {
			return seconds > other.seconds;
		}
	}
}

CTime::~CTime() {}