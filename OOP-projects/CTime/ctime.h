#pragma once

class CTime {
	int hours, minutes, seconds;

public:
	CTime();
	CTime(int hours_, int minutes_, int seconds_);
	CTime(const CTime& time);
	~CTime();
};