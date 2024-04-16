#pragma once
#include <iostream>
#include <string>

int Character::count = 0;
int Character::history_count = 1;

class Character {
protected:
	std::string _name;
	int _hp;
	int _power;
	int _armor;

public:
	static int history_count;
	static int count;
	Character(std::string name = "", int hp = 100, int power = 10, int armor = 20);
	Character(const Character& c);
	virtual int attack(Character& c);
	virtual void defence(Character& c, int damage);
	~Character();
};

class Warrior : public Character {
	bool _shield;
public:
	Warrior(const Warrior& c);
	Warrior(std::string name, int hp = 150, int power = 5, int armor = 50, bool shield = true);
	int attack(Character& c);
	void defence(Character& c, int damage);
};

