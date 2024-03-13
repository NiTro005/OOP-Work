#pragma once
class CData{
	int day, month, year;
public:
	CData();
	CData(int day_, int month_, int year_);
	CData(const CData& data);
};
