#include "character.h"

Character:: Character(CString name, int hp , int power , int armor) : _hp(hp), _power(power), _armor(armor), Game_element(0, 0) {
	CString n;
	if (name.empty()) { 
		_name = "Character ";
		n.ToString(history_count);
		_name.append(n); }
	else { _name = name; }
	count++;
	history_count++;
}

Character::Character (const Character& c) : _hp(c._hp),
_armor(c._armor), _power(c._power), Game_element(0, 0) {
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


void Character:: change_position(int new_y, int new_x) {
	x = new_x;
	y = new_y;
}
const CString& Character::get_name() const {
	return _name;
}

Character::~Character() { count--; }