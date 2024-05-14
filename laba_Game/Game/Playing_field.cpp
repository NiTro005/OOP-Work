#include "character.h"

Playing_field::Playing_field(int width, int height, Game_element* player1, Game_element* player2) {
    field.resize(height);
    for (int i = 0; i < height; i++) {
        field[i].resize(width);
        for (int j = 0; j < width; j++) {
            field[i][j] = nullptr;
        }
    }
    int i = 0, j = 0;
    int element_count = (width * height) * 0.10;
    for (int i = 0; i < height ; i++) {
        bool flag = false;
        if (i * width >= element_count) { break; }
        for (int j = 0; j < width; j++) {
            if (i * width + j >= element_count) { flag = true; break; }
            field[i][j] = nullptr;  //заменить на рандомный элемент
        }
        if (flag) { break; }
    }
    field[i][j] = player1;
    if (j + 1 < width) { field[i][j + 1] = player2; }
    else { field[i + 1][0] = player2; }
}

void Playing_field::set_character(Character* character) {
    field.push_back(character);
}