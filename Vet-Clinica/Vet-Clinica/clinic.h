#pragma once

#include <string>
#include <archive.h>
#include <ctime.h>


class FIO {
	std::string sourname;
	std::string name;
	std::string patronymic;
};


class Person {
	FIO full_name;
	TArchive <int> archive;
	CTime time;
	
};



