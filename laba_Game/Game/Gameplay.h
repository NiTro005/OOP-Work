#pragma once
#include "character.h"

class Gameplay{
private:
	Playing_field* field;
	Character* player1;
	Character* player2;
public:
	void launch();
private:
	void start();
	void ShowCreateCharacter();
	void ShowMainMenu();
	void updateStatus();
	void descriptCharacter();
	void PlayerMove(Character* character);
};
