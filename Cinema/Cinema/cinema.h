#pragma once
#include <iostream>
#include <ñstring.h>
#include <archive.h>
#include <cdate.h>
#include <ctime.h>

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