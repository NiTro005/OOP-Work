#include "character.h"

int Character::count = 0;
int Character::history_count = 1;

int main(){
	Warrior p2("Bob"); Archer p1("Stiv"); Vizzard p3("Cevin");
	Playing_field field(10, 10, &p1, &p2);
	int x = p1.get_x();
	return 0;
}