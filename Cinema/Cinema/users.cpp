#include "cinema.h"

User::User(const CString& login, const CString& password) : _login(login), _password(_password) {}
CString User:: get_login() const { return _login; }
CString User:: get_password() const { return _password; }
void User::set_login(const CString& login) { 
	_login = login; 
}
void User::set_password(const CString& password) { _password = password; }


Guest::Guest(const CString& username, const CString& password, const CString& phone, const CString& email) : User(username, password), _phone(phone), _email(email) {}
void Guest::bookTicket(Show& show, int row, int seat) {
    if (!show.getHall().isSeatAvailable(row, seat)) { return; }
    _ticket = Ticket(show, row, seat);
    show.getHall().reserveSeat(row, seat);
}
void Guest::TicketInfo(const Ticket& ticket) {

}

Admin::Admin(const CString& username, const CString& password): User(username, password){}
const Movie& Admin::addMovie(const CString& title, const CString& description, float duration, float rating) {
    Movie* movie = new Movie(title, description, duration, rating);
    _movies.push_back(*movie);
    return *movie;
}
void Admin::removeMovie(const CString& title) {
    for (size_t i = 0; i < _movies.size(); i++) {
        if (_movies[i].getTitle() == title) {
            _movies.remove_by_index(i);
            return;
        }
    }
    throw std::runtime_error("Movie not found");
}

bool Admin::isTimeAvailable(int hallNumber, const CTime& time, const CDate& date) {
    for (size_t i = 0; i < _shows.size(); i++) {
        if (_shows[i].getHall().get_number() == hallNumber &&
            _shows[i].getDate() == date && _shows[i].getTime() == time) {
            return false;
        }
    }
    return true;
}

void Admin::createShow(const Movie& movie, const Cinema& halls, const CTime& first_time, const CDate& first_date, int price) {
    TArchive <Hall> Halls = halls.getHalls();
    bool isAvailable = false;
    int hallNumber = 0;
    Hall* hall = nullptr;
    for (size_t i = 0; i < Halls.size(); i++) {
        if (isTimeAvailable(Halls[i].get_number(), first_time, first_date)) {
            isAvailable = true;
            hallNumber = Halls[i].get_number();
            hall = &Halls[i];
            break;
        }
    }
    if (isAvailable && hall != nullptr) {
        Show newShow(first_time, first_date, movie, hall, price);
        _shows.push_back(newShow);
    }
    else {
        std::cout << "No available halls for this time" << std::endl;
    }
}

