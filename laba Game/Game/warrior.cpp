#include "character.h"

Warrior::Warrior(std::string name, int hp, int power, int armor, bool shield) : Character(name, hp, power, armor), _shield(shield), _protection_shield(3) {};
Warrior::Warrior(const Warrior& c) : Character(c._name, c._hp, c._power, c._armor), _shield(c._shield), _protection_shield(c._protection_shield) {};

int Warrior::attack(Character& c) {
	return this->_power;
}

void Warrior::defence(Character& c, int damage) {
	
	if (this->_shield != false) {
		_protection_shield--;
		if (_protection_shield == 0) {
			this->_shield = false;
		}
		return;
	}
	else {
		if (this->_armor > 0) {
			this->_armor -= damage;
			if (this->_armor < 0) {
				this->_hp += this->_armor; this->_armor = 0;
			}
		}
	}
}