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

class Object : public Game_element {
protected:
	CString _name_object;
	int _mass;
public:
	Object(const CString& name_object, int mass) :_name_object(name_object), _mass(mass), Game_element(0, 0) {}
	const CString& get_name_object() const { return _name_object; }
	int get_mass() const { return _mass; }
	void change_position(int new_x, int new_y){x = new_x; y = new_y;}
};

class Bakpack {
	TArchive<Object*> objects;
	int sum_mass = 0;
	int max_mass = 15;
public:
	void addItem( Object* obj) { objects.push_back(obj); }
	void useItem();
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
	const CString& get_name() const;


	Character(CString name, int hp = 100, int power = 10, int armor = 20);
	Character(const Character& c);
	virtual int attack(Character& c) = 0;
	virtual void defence(Character& c, int damage) = 0;
	virtual const CString& get_class() const = 0;
	void change_position(int new_x, int new_y);
	~Character();
};


class Playing_field {
	TArchive<TArchive<Game_element*>> field;
public:
	Playing_field(Game_element* player1, Game_element* player2, int width = 70, int height = 20);
	void restore_character(Character* character);
	Game_element* get_object_at(int x, int y);
	TArchive<Game_element*> get_neighbors(int x, int y);
	void set_element(int x, int y, Game_element* element);
private:
	void shuffle(int width, int height, int element_count); 
	Game_element* create_random_element();
};

class Warrior : public Character {
	bool _shield;
	int _protection_shield;
public:
	Warrior(const Warrior& c);
	Warrior(CString name, int hp = 100, int power = 20, int armor = 50, bool shield = true);
	int attack(Character& c);
	void defence(Character& c, int damage);
	const CString& get_class() const;
	void set_shield(int protection) { _protection_shield += protection; _shield = true; }
private:
	void spikes(Character& c);
};

class Archer : public Character {
	bool _arrows;
	bool _bow;
	int _protection_bow;
public:
	Archer(const Archer& c);
	Archer(CString name, int hp = 65, int power = 25, int armor = 20, bool _bow = true);
	int attack(Character& c);
	void defence(Character& c, int damage);
	void set_protection_bow(int arrows) { _protection_bow += arrows; }
	const CString& get_class() const;

private:
	int _bow_magic(Character& c);
};

class Vizzard : public Character {
	enum Magic { empty, poison, fire, heal, mana_bust, lighting, shield } magical;
	bool mana;
	int amount_of_mana;
public:
	Vizzard(const Vizzard&);
	Vizzard(CString name, int hp = 75, int power = 30, int armor = 40, int amount_of_mana = 100);
	int attack(Character& c);
	void defence(Character& c, int damage);
	const CString& get_class() const;
	void set_mana(int mana) { amount_of_mana += mana; }
private:
	int UseMagic(Character& c, Magic magic);
};


class Weapon : public Object {
protected:
	int bonus_power;
public:
	Weapon(const CString& name_object, int mass, int bonus_power) : Object(name_object, mass), bonus_power(bonus_power) {}
	int get_bonus_power() const { return bonus_power; }
	virtual bool can_use(const Character& character) const = 0;
};


class Bow : public Weapon {
	int arrows;
public:
	Bow(const CString& name_object, int mass, int bonus_power, int arrows) : Weapon(name_object, mass, bonus_power), arrows(arrows) {}
	bool can_use(const Character& character) const {
		return dynamic_cast<const Archer*>(&character) != nullptr;
	}
	int use(Archer& archer) { archer.set_protection_bow(arrows); archer.set_power(archer.get_power() + bonus_power); }
};

class Sword : public Weapon {
	int protection;
public:
	Sword(const CString& name_object, int mass, int bonus_power, int protection) : Weapon(name_object, mass, bonus_power), protection(protection) {}
	bool can_use(const Character& character) const {
		return dynamic_cast<const Warrior*>(&character) != nullptr;
	}
	int use(Warrior& warrior) { warrior.set_shield(protection); warrior.set_power(bonus_power); }
};

class Staff : public Weapon {
	int mana;
public:
	Staff(const CString& name_object, int mass, int bonus_power, int mana) : Weapon(name_object, mass, bonus_power), mana(mana) {}
	bool can_use(const Character& character) const {
		return dynamic_cast<const Vizzard*>(&character) != nullptr;
	}
	int use(Vizzard& vizzard) { vizzard.set_mana(mana); vizzard.set_power(bonus_power); }
};

class Potion : public Object {
public:
	enum Type { heal, power, life, armor };
private:
	Type type;
	int value;
public:
	Potion(const CString& name_object, int mass, Type type, int value) : Object(name_object, mass), type(type), value(value) {}
	Type get_type() { return type; }
	int get_value() { return value; }
	int use(Character& character);
};
