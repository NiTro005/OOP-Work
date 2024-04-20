#include "character.h"

Character:: Character(std::string name, int hp , int power , int armor) : _hp(hp), _power(power), _armor(armor) {
	if (name == "") { _name = "Character" + std::to_string(history_count); }
	else { name = _name; }
	count++;
	history_count++;
}

Character::Character (const Character& c) : _hp(c._hp),
_armor(c._armor), _power(c._power) {
	history_count++; count++;
}


int Character::get_hp() {
	return _hp;
}

void Character::set_hp(int newhp) {
	_hp = newhp;
}

int Character::get_power() {
	return _power;
}

void Character::set_power(int newpower) {
	_power = newpower;
}

int Character::get_armor() {
	return _armor;
}

void Character::set_armor(int newarmor) {
	_armor = newarmor;
}


Character::~Character() { count--; }