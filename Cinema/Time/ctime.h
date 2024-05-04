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
	void assign( const CTime& time);
	void set_values(int hours_, int minutes_, int seconds_);
	Status add_hours(int hours_);
	Status add_minutes(int minutes_);
	Status add_seconds(int minutes_);
	Status sub_hours(int hours_);
	Status sub_minutes(int minutes_);
	Status sub_seconds(int minutes_);
	int compare(const CTime& time);
	~CTime();
	bool operator<=(const CTime& other) const;
	CTime operator+(float value) const;
	bool operator>(const CTime& other) const;
	bool operator==(const CTime& other) const;
};

