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
    void reserveSeat(int rows, int seats); // Бронирование местa
    void freeSeat(int rows, int seats); // Освобождение местa
};

class Show {
    CTime _time;
    CDate _date;
    Movie _movie;
    Hall* _hall;
    int _price;
public:
    Show(const CTime& time, const CDate& date,const Movie& movie, Hall* hall, int price);
    const Movie& getMovie() const;
    Hall& getHall() const;
    const CDate& getDate() const;
    const CTime& getTime() const;
    int getPrice() const;

};

class Ticket {
    Show _show;
    int _row;
    int _seat;
public:
    Ticket(const Show& show, int row, int seat);
    const Show& getShow() const;
    int getRow() const;
    int getSeat() const;
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

class Guest : public User {
    CString _phone;
    CString _email;
public:
    Guest(const CString& username, const CString& password, const CString& phone, const CString& email);
    void bookTicket(Show& show, int row, int seat); //бронь места
};
