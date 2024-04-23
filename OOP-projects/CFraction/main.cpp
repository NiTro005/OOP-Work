#include "fraction.h"

int main() {
    Fraction fr_1, fr_2(3, 4), fr_3(5, 6), fr_4(fr_2), fr_5;
    fr_1 = fr_2 + fr_3;
    std::cout << fr_1 << std::endl;
    std::cin >> fr_5;
    fr_5 /= 3;
    fr_1 = fr_1 + 4;
    fr_1 = 4 + fr_1;
    std::cout << fr_5 << std::endl;
    if (fr_2 == fr_4) {
        std::cout << "TRUE" << std::endl;
    }
    else { std::cout << "FALSE" << std::endl; }

    if (fr_2 > 1) {
        std::cout << "TRUE" << std::endl;
    }
    else { std::cout << "FALSE" << std::endl; }
    return 0;
}