#pragma once
#include "character.h"

class Gameplay{
private:
	Playing_field* field;
	Character* player1;
	Character* player2;
	TArchive<CString> states;
public:
	void launch();
private:
	void start();
	void ShowCreateCharacter();
	void ShowMainMenu();
	void ShowGameMenu();
	void updateStatus(const CString& str);
	void descriptCharacter();
	void PlayerMove();
};
