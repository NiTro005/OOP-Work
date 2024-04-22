#pragma once

#include <string>
#include <archive.h>
#include <ctime.h>
#include <cdate.h>

enum Gender { Male, Female };

class FIO {
	std::string sourname;
	std::string name;
	std::string patronymic;
};

class Adress {

};

class Person {
	FIO full_name;
	CDate birthday;
	Gender gender;
};



