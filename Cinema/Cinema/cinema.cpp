#include "cinema.h"

Movie:: Movie(const CString& title, const CString& description, int duration, float rating)
	: _title(title),_description(description), _duration(duration), _rating(rating) {}
const CString& Movie::getTitle() const { return _title; }
const CString& Movie::getDescription() const { return _description; }
float Movie::getDuration() const { return _duration; }
float Movie::getRating() const { return _rating; }


Hall:: Hall(int rows, int seats) : _rows(rows), _seats(seats), _freeSeats(rows, TArchive<bool>(seats, true)) {}
int Hall:: get_rows() const { return _rows; }
int Hall::get_seats() const { return _seats; }
bool Hall::isSeatAvailable(int rows, int seats) const { return _freeSeats[rows][seats]; }
void Hall:: reserveSeat(int rows, int seats) { _freeSeats[rows][seats] = false; }
void Hall:: freeSeat(int rows, int seats) { _freeSeats[rows][seats] = true; }



Show:: Show(const CTime& time, const CDate& date, Movie* movie, Hall* hall)
	: _movie(movie), _hall(hall), _date(date), _time(time) {}
const Movie& Show::getMovie() const { return *_movie; }
const Hall& Show::getHall() const { return *_hall; }
const CDate& Show::getDate() const { return _date; }
const CTime& Show::getTime() const { return _time; }
