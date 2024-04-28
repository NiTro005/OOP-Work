#pragma once
#include <iostream>
#include <сstring.h>
#include <archive.h>
#include <cdate.h>
#include <ctime.h>


class Movie {
private:
    CString _title;
    CString _description;
    float _duration;
    float _rating;
public:
    Movie(const CString& title, const CString& description, int duration, float rating);
    const CString& getTitle() const;
    const CString& getDescription() const;
    float getDuration() const;
    float getRating() const;
};

class Hall {
    int _rows;
    int _seats;
    TArchive <TArchive <bool>> _freeSeats;
public:
    Hall(int rows, int seats);
    int get_rows() const;
    int get_seats() const;
    bool isSeatAvailable(int rows, int seats) const;
    void reserveSeat(int rows, int seats); // Бронирование всех мест
    void freeSeat(int rows, int seats); // Освобождение всех мест
};

class Show {
    CTime _time;
    CDate _date;
    Movie* _movie;
    Hall* _hall;
public:
    Show(const CTime& time, const CDate& date, Movie* movie, Hall* hall);
    const Movie& getMovie() const;
    const Hall& getHall() const;
    const CDate& getDate() const;
    const CTime& getTime() const;

};

class Ticket {
    Show* _show;
    int _row;
    int _seat;
    float _price;
public:
    Ticket(Show* show, int row, int seat, float price);
    const Show& getShow() const;
    int getRow() const;
    int getSeat() const;
    float getPrice() const;
};

class User{
protected:
	CString _login;
	CString _password;
public:
	User(const CString& login, const CString& password);
	CString get_login() const;
	CString get_password() const;
	void set_login(const CString& login);
	void set_password(const CString& password);
};



class Admin : public User {
public:

};