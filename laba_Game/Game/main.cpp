#include "Gameplay.h"

int Character::count = 0;
int Character::history_count = 1;

int main(){
	system("chcp 1251>>null");
	Gameplay gameplay;
	Warrior p2("Bob"); Archer p1("Stiv"); Vizzard p3("Cevin");
	gameplay.launch();
	system("pause>>null");
	return 0;
}