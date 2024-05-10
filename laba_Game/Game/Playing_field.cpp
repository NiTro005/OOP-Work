#include "character.h"

Playing_field::Playing_field(int width, int height) {
    field.resize(height);
    for (int i = 0; i < height; i++) {
        field[i].resize(width);
        for (int j = 0; j < width; j++) {
            field[i][j] = nullptr;
        }
    }
    // ������� ��������� ������� ���� �� ��������� ������������� ���������� � ��������
    // ...
}

void Playing_field::set_character(Character* character) {
    field.push_back(character);
}