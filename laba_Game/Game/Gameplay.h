#pragma once
#include "character.h"

void MainMenu();
void CharacterCreationMenu();
void updateCharacterDesccript();



class Gameplay{
	Playing_field _field;
public:
	Gameplay(Character* player1 = nullptr, Character* player2 = nullptr, int width = 15, int height = 15);
};
