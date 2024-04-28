#include "cinema.h"

User::User(const CString& login, const CString& password) : _login(login), _password(_password) {}
CString User:: get_login() const { return _login; }
CString User:: get_password() const { return _password; }
void User::set_login(const CString& login) { 
	_login = login; 
}
void User::set_password(const CString& password) { _password = password; }