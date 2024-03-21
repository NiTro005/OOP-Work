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
        res.denominator = this->denominator * frac.denominator;
        return res;
    }
    Fraction operator=(const Fraction& frac) {
        if (this != &frac) {
            this->denominator = frac.denominator;
            this->numerator = frac.numerator;
        }
        return *this;
    }
    Fraction operator+=(const Fraction& frac) {
        this->denominator = this->numerator * frac.denominator + frac.numerator * this->denominator;
        this->numerator = this->denominator * frac.denominator;
        return *this;
    }
    Fraction operator-=(const Fraction& frac) {
        this->denominator = this->numerator * frac.denominator - frac.numerator * this->denominator;
        this->numerator = this->denominator * frac.denominator;
        return *this;
    }
    Fraction operator*=(const Fraction& frac) {
        this->denominator = this->numerator * frac.numerator;
        this->numerator = this->denominator * frac.denominator;
        return *this;
    }
    Fraction operator/=(const Fraction& frac) {
        this->denominator = this->numerator * frac.denominator;
        this->numerator = this->denominator * frac.numerator;
        return *this;
    }

private:
    void simplify();
};

int main() {
    Fraction fr_1, fr_2(3, 4), fr_3(5, 6), fr_4(fr_2);
    fr_1 = fr_2 + fr_3;

    return 0;
}