#include "character.h"

//ïîìåíÿòü ñèñòåìó ïåðåìåøèâàíèÿ
void Playing_field::shuffle(int width, int height, int element_count) {
    srand(time(NULL));
    element_count+= 2;
    if (width <= 0 || height <= 0) { throw std::logic_error("Íåêîðåêòíûé ðàçìåð ïîëÿ"); }
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (element_count == 0) {  
                break;
            }
            int randX = rand() % width;
            int randY = rand() % height;
            Game_element *temp= field[i][j];
            field[i][j] = field[randY][randX];
            field[randY][randX] = temp;
            if (field[i][j] != nullptr) { field[i][j]->change_position(i, j); }
            if (field[randY][randX] != nullptr) { field[randY][randX]->change_position(randY, randX); }
            element_count -= 1;
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
    int element_count = (width * height) * 0.03;
    for (i = 0; i < height; i++) {
        bool flag = false;
        for (j = 0; j < width; j++) {
            if (i * width + j >= element_count) {
                flag = true; break;
            }
            field[i][j] = create_random_element();
        }
        if (i * width >= element_count) { break; }
        if (flag) { break; }
    }
    if (j == width) { i++; j = 0; }
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
        character->change_position(y, x);
    }
    else { restore_character(character); }
}
void Playing_field::set_element(int x, int y, Game_element* element) {
    field[y][x] = element;
}
Game_element* Playing_field::create_random_element() {
    srand(time(NULL));
    int type = rand() % 101;
    if (type > 50) { type = 0; }
    else { type = 1; }
    type = 0;
    switch (type) {
    case 0: {
        CString name_object = "Potion";
        int mass = rand() % 5 + 1;
        int typePotion = rand() % 100;
        if (typePotion < 24) { typePotion = 0; }
        else if(typePotion > 24 && typePotion < 50){ typePotion = 1; }
        else if (typePotion > 75) { typePotion = 3; }
        else { typePotion = 2; }
        Potion::Type potion_type = static_cast<Potion::Type>(typePotion);
        int value = rand() % 50 + 1;
        Potion* potion = new Potion(name_object, mass, potion_type, value);
        return potion;
    }
    case 1: {
        CString name_object = "Weapon";
        int mass = rand() % 10 + 1;
        int bonus_power = rand() % 20 + 1;

        Sword* sword = new Sword(name_object, mass, bonus_power, rand() % 10 + 1);
        return sword;
    }
    }
    return nullptr;
}
