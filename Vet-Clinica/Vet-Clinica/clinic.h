#pragma once

#include <string>

#include <archive.h>
#include <cdate.h>


class FIO {
	std::string sourname;
	std::string name;
	std::string patronymic;
};


class Person {
	FIO full_name;
	CDate birthday;
	
	
};



