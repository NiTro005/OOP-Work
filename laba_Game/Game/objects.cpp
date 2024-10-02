#include "character.h"

int Potion::use(Character& character) {
    switch (type) {
    case heal:
        character.set_hp(character.get_hp() + value);
        break;
    case power:
        character.set_power(character.get_power() + value);
        break;
    case armor:
        character.set_armor(character.get_armor() + value);
    case life:
        return 1;
    }
    return 0;
}

void Bakpack::useItem() {

}

