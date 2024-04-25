#include "character.h"
#include <time.h>

Vizzard::Vizzard(CString name, int hp, int power, int armor, int amount_of_mana) : Character(name, hp, power, armor), amount_of_mana(amount_of_mana), mana(true), magical(empty) {};
Vizzard::Vizzard(const Vizzard& c) : Character(c._name, c._hp, c._power, c._armor), amount_of_mana(c.amount_of_mana), mana(c.mana), magical(c.magical) {};

int Vizzard::attack(Character& c) {
	int damage = _power;
	srand(time(NULL));
	int random = rand() % 7;
	magical = (Magic)random;
	damage += UseMagic(c, magical);
	amount_of_mana += 10;
	return damage;
}

void Vizzard::defence(Character& c, int damage) {
	if (magical == Magic::shield) {
		return;
	}
	if (_armor > 0) {
		_armor -= damage;
		if (_armor < 0) {
			_hp += _armor; _armor = 0;
		}
	}
	else { _hp -= damage; }
}

int Vizzard::UseMagic(Character& c, Magic magic) {
	int damage = 0;
	if (amount_of_mana > 25) {
		if (magic == Magic::fire) {
			damage = _power * 2;
		}
		if (magic == Magic::heal) {
			_hp += 20;
		}
		if (magic == Magic::lighting) {
			damage = 10;
			c.set_armor(0);
		}
		if (magic == Magic::mana_bust) {
			amount_of_mana += 60;
		}
		if (magic == Magic::poison) {
			damage = 10;
			if (c.get_power() >= 5) {
				c.set_power(c.get_power() - 2);
			}
		}
		if (magic != Magic::empty) { amount_of_mana -= 25; }
	}
	return damage;
}