#include "character.h"


//помен€ть систему перемешивани€
void Playing_field::shuffle(int width, int height, int element_count) {
    srand(time(NULL));
    element_count+=2;
    if (width <= 0 || height <= 0) { throw std::logic_error("Ќекоректный размер пол€"); }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (element_count == 0) {  break; }
            int randX = rand() % width;
            int randY = rand() % height;
            Game_element* temp = field[i][j];
            field[i][j] = field[randY][randX];
            field[randY][randX] = temp;
            if (field[i][j] != nullptr) { field[i][j]->change_position(i, j); }
            if (field[randY][randX] != nullptr) { field[randY][randX]->change_position(randY, randX); }
            element_count--;
        }
        if (element_count == 0) { break; }
    }
}


Playing_field::Playing_field(Game_element* player1, Game_element* player2, int width, int height) {
    field.resize(height);
    for (int i = 0; i < height; i++) {
        field[i].resize(width);
        for (int j = 0; j < width; j++) {
            field[i][j] = nullptr;
        }
    }
    int i = 0, j = 0;
    int element_count = (width * height) * 0.10;
    for (i = 0; i < height ; i++) {
        bool flag = false;
        if (i * width >= element_count) { break; }
        for (j = 0; j < width; j++) {
            if (i * width + j >= element_count) { 
                flag = true; break; }
            field[i][j] = nullptr;  //заменить на рандомный элемент
        }
        if (flag) { break; }
    }
    field[i][j] = player1;
    if (j + 1 < width) { field[i][j + 1] = player2; }
    else { field[i + 1][0] = player2; }
    shuffle(width, height, element_count);
}

Game_element* Playing_field::get_object_at(int x, int y) {
    if (x < 0 || x >= field[0].size() || y < 0 || y >= field.size()) {
        return nullptr;
    }
    return field[y][x];
}

TArchive<Game_element*> Playing_field::get_neighbors(int x, int y) {
    TArchive<Game_element*> neighbors;
    for (int i = y - 1; i <= y + 1; i++) {
        for (int j = x - 1; j <= x + 1; j++) {
            if (i >= 0 && i < field.size() && j >= 0 && j < field[i].size() && !(i == y && j == x)) {
                neighbors.push_back(field[i][j]);
            }
        }
    }
    return neighbors;
}

void Playing_field::restore_character(Character* character) {
    srand(time(NULL));
    int empty_cells = 0;
    for (int i = 0; i < field.size(); ++i) {
        for (int j = 0; j < field[i].size(); ++j) {
            if (field[i][j] == nullptr) {
                ++empty_cells;
            }
        }
    }
    if (empty_cells == 0) {
        throw std::runtime_error("No empty cells in playing field");
    }
    int y = rand() % field.size();
    int x = rand() % field[y].size();
    if (field[y][x] == nullptr) {
        field[y][x] = character;
    }
    else { restore_character(character); }
}