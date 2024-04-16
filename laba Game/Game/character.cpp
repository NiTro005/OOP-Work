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

Character::~Character() { count--; }