#include "character.h"

Warrior::Warrior(std::string name, int hp, int power, int armor, bool shield) : Character(name, hp, power, armor), _shield(shield) {};
Warrior::Warrior(const Warrior& c) : Character(c._name, c._hp, c._power, c._armor), _shield(c._shield) {};

int Warrior::attack(Character& c) {

}