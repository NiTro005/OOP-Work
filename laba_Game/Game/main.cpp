#include "Gameplay.h"

int Character::count = 0;
int Character::history_count = 1;

int main(){
	system("chcp 1251>>null");
	system("title Mini_Dota");
	Gameplay gameplay;
	gameplay.launch();
	system("pause>>null");
	return 0;
}