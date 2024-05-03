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
    Ticket(show, row, seat);
    show.getHall().reserveSeat(row, seat);
}
void Guest::TicketInfo(const Ticket& ticket) {

}

Admin::Admin(const CString& username, const CString& password): User(username, password){}
void Admin::addMovie(const CString& title, const CString& description, int duration, float rating) {
    Movie movie(title, description, duration, rating);
    _movies.push_back(movie);
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
void Admin::createShow(const Movie& movie, Hall* hall, const CTime& first_time, const CDate& first_date) {

}