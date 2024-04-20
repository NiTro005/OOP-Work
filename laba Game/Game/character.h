#pragma once
#include <iostream>
#include <string>
class Character {
protected:
	std::string _name;
	int _hp;
	int _power;
	int _armor;

public:
	static int history_count;
	static int count;

	int get_hp();
	void set_hp(int newhp);
	int get_power();
	void set_power(int newpower);
	int get_armor();
	void set_armor(int newarmor);

	Character(std::string name = "", int hp = 100, int power = 10, int armor = 20);
	Character(const Character& c);
	virtual int attack(Character& c) = 0;
	virtual void defence(Character& c, int damage) = 0;
	~Character();
};

class Warrior : public Character {
	bool _shield;
	int _protection_shield;
public:
	Warrior(const Warrior& c);
	Warrior(std::string name, int hp = 100, int power = 5, int armor = 50, bool shield = true);
	int attack(Character& c);
	void defence(Character& c, int damage);
private:
	void spikes(Character& c);
};

class Archer : public Character {
	bool _arrows;
	bool _bow;
	int _protection_bow;

public:
	Archer(const Archer& c);
	Archer(std::string name, int hp = 75, int power = 25, int armor = 35, bool _bow = true);
	int attack(Character& c);
	void defence(Character& c, int damage);
private:
	int _bow_magic(Character& c);
};



