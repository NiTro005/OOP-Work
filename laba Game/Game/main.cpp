#include "character.h"

int Character::count = 0;
int Character::history_count = 1;

int main(){
	Warrior p2("Bob"); Archer p1("Stiv", 46, 25, 0);
	p1.defence(p2, p2.attack(p1));

	p2.defence(p1, p1.attack(p2));
	p2.defence(p1, p1.attack(p2));

	p1.defence(p2, p2.attack(p1));
	p1.defence(p2, p2.attack(p1));
	p1.defence(p2, p2.attack(p1));
	p1.defence(p2, p2.attack(p1));
	p1.defence(p2, p2.attack(p1));

	p2.defence(p1, p1.attack(p2));
	p2.defence(p1, p1.attack(p2));
	p2.defence(p1, p1.attack(p2));
	p2.defence(p1, p1.attack(p2));
	p2.defence(p1, p1.attack(p2));
	p2.defence(p1, p1.attack(p2));
	return 0;
}