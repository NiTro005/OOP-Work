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