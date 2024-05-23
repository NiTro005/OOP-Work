#pragma once
#include <iostream>
#include <ñstring.h>
#include <archive.h>
#include <windows.h>
#include <conio.h>
#include <time.h>

#define MAIN_MENU_SIZE 2
#define NOT_KEY 67
#define KEY_EXIT 27
#define KEY_ENTER 13
#define ARROW_KEY 224
#define KEY_SPACE 0
#define KEY_BACKSPACE 8
#define KEY_ARROW_RIGHT 77
#define KEY_ARROW_LEFT 75
#define KEY_ARROW_UP 72
#define KEY_ARROW_DOWN 80

class Game_element {
protected:
	int x, y;
public:
	Game_element(int x, int y) : x(x), y(y) {}
	Game_element(const Game_element& el) : x(el.x), y(el.y){}
	virtual void change_position(int new_x, int new_y) = 0;
	int get_x() const { return x; }
	int get_y() const { return y; }
};

class Character : public Game_element {
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
	void change_position(int new_x, int new_y);
	~Character();
};

class Playing_field {
	TArchive<TArchive<Game_element*>> field;
public:
	Playing_field(Game_element* player1, Game_element* player2, int width = 50, int height = 15);
	void restore_character(Character* character);
	Game_element* get_object_at(int x, int y);
	TArchive<Game_element*> get_neighbors(int x, int y);
private:
	void shuffle(int width, int height, int element_count); 
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


