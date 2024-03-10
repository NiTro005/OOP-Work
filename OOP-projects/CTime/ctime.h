#pragma once

enum Status { SUCCESS = 1, ERROR, WARNING };

class CTime {
	int hours, minutes, seconds;

public:
	CTime();
	CTime(int hours_, int minutes_, int seconds_);
	CTime(const CTime& time);
	Status input();
	Status check();
	void output();
	Status convert();
	~CTime();
};
