#include "character.h"
int main(){
	Character p1, p2("Bob", 120, 10, 30);
	p2.attack(p1);
	std::cout << p1.count << " " << Character::count;
	return 0;
}