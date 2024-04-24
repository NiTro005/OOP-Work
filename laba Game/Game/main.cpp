#include "character.h"

int Character::count = 0;
int Character::history_count = 1;

int main(){
	Warrior p2("Bob"); Archer p1("Stiv"); Vizzard p3("Cevin");
	/*p1.defence(p3, p3.attack(p1));
	p1.defence(p3, p3.attack(p1));
	p1.defence(p3, p3.attack(p1));
	p1.defence(p3, p3.attack(p1));
	p1.defence(p3, p3.attack(p1));
	p1.defence(p3, p3.attack(p1));*/

	p3.defence(p1, p1.attack(p3));
	p3.defence(p1, p1.attack(p3));
	p3.defence(p1, p1.attack(p3));
	return 0;
}