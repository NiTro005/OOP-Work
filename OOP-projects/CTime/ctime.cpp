#include "ctime.h"
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