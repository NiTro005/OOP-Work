#pragma once
#include "character.h"

class Gameplay {
	Playing_field _field;
public:
	Gameplay(Character* player1, Character* player2, int width = 15, int height = 15);
};
