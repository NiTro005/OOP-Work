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



Show:: Show(const CTime& time, const CDate& date, const Movie& movie, Hall* hall, int price)
	: _movie(movie), _hall(hall), _date(date), _time(time), _price(price) {}
const Movie& Show::getMovie() const { return _movie; }
Hall& Show::getHall() const { return *_hall; }
const CDate& Show::getDate() const { return _date; }
const CTime& Show::getTime() const { return _time; }
int Show::getPrice() const { return _price; }


Ticket:: Ticket(const Show& show, int row, int seat)
    : _show(show), _row(row), _seat(seat) {}
const Show& Ticket:: getShow() const { return _show; }
int Ticket::getRow() const { return _row; }
int Ticket::getSeat() const { return _seat; }
