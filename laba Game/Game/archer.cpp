#include "character.h"

Archer::Archer(CString name, int hp, int power, int armor, bool _bow) : Character(name, hp, power, armor), _bow(_bow), _arrows(true), _protection_bow(7){};
Archer::Archer(const Archer& c) : Character(c._name, c._hp, c._power, c._armor), _bow(c._bow), _arrows(c._arrows), _protection_bow(c._protection_bow) {};

int Archer::attack(Character& c) {
	_armor += 5;
	int power = _power;
	_arrows = false;
	if (_hp < 45) { _arrows = true; }
	if (_bow) {
		if (!_arrows) { power = _bow_magic(c); }
		_protection_bow--;
		if (_protection_bow == 0) { _bow = false; }
	}
	else { power = 5; }
	return power;
}

void Archer::defence(Character& c, int damage) {
	if (_armor > 0) {
		_armor -= damage;
		if (_armor < 0) {
			_hp += _armor; _armor = 0;
		}
	}
	else { _hp -= damage; }
	if (!_arrows) { _hp +=_bow_magic(c); }
}

int Archer::_bow_magic(Character& c) {
	if (_arrows) {
		return c.get_power() / 5;
	}
	else {
		return _power * 2;
	}

}