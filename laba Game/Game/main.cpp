#include "character.h"

int Character::count = 0;
int Character::history_count = 1;

int main(){
	Warrior p1("Bob", 120, 10, 30, true), p2("Stiv", 120, 10, 30, true);
	p2.defence(p1, p1.attack(p2));
	p2.defence(p1, p1.attack(p2));
	p2.defence(p1, p1.attack(p2));
	p2.defence(p1, p1.attack(p2));
	return 0;
}