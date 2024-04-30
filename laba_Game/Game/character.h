#pragma once
#include <iostream>
#include <ñstring.h>
#include <archive.h>

class Character {
protected:
	CString _name;
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

	Character(CString name, int hp = 100, int power = 10, int armor = 20);
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
	Warrior(CString name, int hp = 100, int power = 5, int armor = 50, bool shield = true);
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
	Archer(CString name, int hp = 75, int power = 25, int armor = 35, bool _bow = true);
	int attack(Character& c);
	void defence(Character& c, int damage);
private:
	int _bow_magic(Character& c);
};

class Vizzard : public Character {
	enum Magic{empty, poison, fire, heal, mana_bust, lighting, shield } magical;
	bool mana;
	int amount_of_mana;
public:
	Vizzard(const Vizzard&);
	Vizzard(CString name, int hp = 75, int power = 25, int armor = 30, int amount_of_mana = 100);
	int attack(Character& c);
	void defence(Character& c, int damage);
private:
	int UseMagic(Character& c, Magic magic);
};


