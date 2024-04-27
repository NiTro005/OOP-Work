#pragma once
#include <iostream>
#include <string.h>
#include <archive.h>
#include <ctime.h>
#include <cdate.h>

enum Gender { Male, Female };
enum Specialize {unknow, surgion, ornithologist, laboratory_assistant, therapist, surgeon, ultrasound_diagnostician, anesthetist, dermatologist, cardiologist };
enum IlnessTip {Cancer, Obesity, Fractures, Heartworm, Fleas_and_ticks, Diarrhea, Cough, Ear_infections, Arthritis, Cataracts};
enum Species { cat, dog, snake, parrot, rat, pig };

class FIO {
	CString firstname;
	CString sourname;
	CString patronymic;
};

class Person {
protected:
	FIO full_name;
	CDate birthday;
	Gender gender;
};
class Adress {
	CString city;
	CString street;
	CString home;
};

class Passport {
	int number;
	int seria;
	Adress registration;
};

class Client : Person {
	Passport passport;
	CString email;
	CString phone;
	Adress adress;
public:
	void change_phone(CString& phone);

};

class OpenHours {
	CTime startwork;
	CTime endwork;
	CTime dinner;
};

class Ilness {
	IlnessTip ilness;
	CString treatment;
	CString symptoms;
};

class Doctor : Person {
	Specialize job;
	int StageOfWork;
	OpenHours timework;
public:
	void diagnoz(Ilness& i);
	void prescribe_treatment(Ilness& i);
};

class Pet {
	CString name;
	int age;
	Species spec;
	Client* master;
	Ilness ilness;
};


class Visit {
	bool followUpNeeded;
	CString notes;
	Doctor* doc;
	Pet* pet;
public:
	void operation(Pet& p);
};

class Story_visits : Visit {
	TArchive <Visit> visits;
public:
	void add_visits_history(const Visit& v);
	const TArchive <Visit> getVisit();
};