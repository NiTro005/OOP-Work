#include "character.h"
#include <time.h>

Vizzard::Vizzard(std::string name, int hp, int power, int armor, int amount_of_mana) : Character(name, hp, power, armor), amount_of_mana(amount_of_mana), mana(true), magical(empty) {};
Vizzard::Vizzard(const Vizzard& c) : Character(c._name, c._hp, c._power, c._armor), amount_of_mana(c.amount_of_mana), mana(c.mana), magical(c.magical) {};

int Vizzard::attack(Character& c) {
	srand(time(NULL));
	magical = (Magic)rand() % 7;

	return _power;
}

void Vizzard::defence(Character& c, int damage) {
	
}

int Vizzard::UseMagic(Character& c, Magic magic) {

}