#include "cinema.h"

Movie:: Movie(const CString& title, const CString& description, int duration, float rating)
	: _title(title),_description(description), _duration(duration), _rating(rating) {}
const CString& Movie::getTitle() const { return _title; }
const CString& Movie::getDescription() const { return _description; }
float Movie::getDuration() const { return _duration; }
float Movie::getRating() const { return _rating; }



void Hall:: reserveSeat(int rows, int seats) { _freeSeats[rows][seats] = false; }
void Hall:: freeSeat(int rows, int seats) { _freeSeats[rows][seats] = true; }


