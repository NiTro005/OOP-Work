#include <iostream>

class Fraction {
    int numerator;       // числитель
    int denominator;     // заменатель
public:
    Fraction(): numerator(0), denominator(1) {}
    Fraction(int num, int dem) : numerator(num), denominator(dem) {}
    Fraction(const Fraction& frac) : numerator(frac.numerator), denominator(frac.denominator) {}

    Fraction operator+(const Fraction& frac) {
        Fraction res(*this);
        res.numerator = this->numerator * frac.denominator + frac.numerator * this->denominator;
        res.denominator = this->denominator + frac.denominator;
        return res;
    }

private:
    void simplify();
};

int main() {
    Fraction fr_1, fr_2(3, 4), fr_3(5, 6), fr_4(fr_2);
    fr_1 = fr_2 + fr_3;
    return 0;
}