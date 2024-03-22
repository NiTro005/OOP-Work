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
        simplify();
        return res;
    }
    Fraction operator-(const Fraction& frac) {
        Fraction res(*this);
        res.numerator = this->numerator * frac.denominator - frac.numerator * this->denominator;
        res.denominator = this->denominator * frac.denominator;
        simplify();
        return res;
    }
    Fraction operator*(const Fraction& frac) {
        Fraction res(*this);
        res.numerator = this->numerator * frac.numerator;
        res.denominator = this->denominator * frac.denominator;
        simplify();
        return res;
    }
    Fraction operator/(const Fraction& frac) {
        Fraction res(*this);
        res.numerator = this->numerator * frac.denominator;
        res.denominator = this->denominator * frac.numerator;
        simplify();
        return res;
    }
    Fraction operator=(const Fraction& frac) {
        if (this != &frac) {
            this->denominator = frac.denominator;
            this->numerator = frac.numerator;
        }
        simplify();
        return *this;
    }
    Fraction operator+=(const Fraction& frac) {
        this->denominator = this->numerator * frac.denominator + frac.numerator * this->denominator;
        this->numerator = this->denominator * frac.denominator;
        simplify();
        return *this;
    }
    Fraction operator-=(const Fraction& frac) {
        this->denominator = this->numerator * frac.denominator - frac.numerator * this->denominator;
        this->numerator = this->denominator * frac.denominator;
        simplify();
        return *this;
    }
    Fraction operator*=(const Fraction& frac) {
        this->denominator = this->numerator * frac.numerator;
        this->numerator = this->denominator * frac.denominator;
        simplify();
        return *this;
    }
    Fraction operator/=(const Fraction& frac) {
        this->denominator = this->numerator * frac.denominator;
        this->numerator = this->denominator * frac.numerator;
        simplify();
        return *this;
    }
    bool operator==(const Fraction& frac) const {
        return (numerator == frac.numerator) && (denominator == frac.denominator);
    }
    bool operator!=(const Fraction& frac) const {
        return (numerator != frac.numerator) || (denominator != frac.denominator);
    }
    bool operator>=(const Fraction& frac) const {
        return (numerator * frac.denominator >= frac.numerator * denominator);
    }
    bool operator<=(const Fraction& frac) const {
        return (numerator * frac.denominator <= frac.numerator * denominator);
    }
    bool operator>(const Fraction& frac) const {
        return (numerator * frac.denominator > frac.numerator * denominator);
    }
    bool operator<(const Fraction& frac) const {
        return (numerator * frac.denominator < frac.numerator * denominator);
    }

    friend Fraction operator+(Fraction& frac, int value) {
        frac.numerator = frac.numerator + value * frac.denominator;
        frac.simplify();
        return frac;
    }
    friend Fraction operator+(int value, Fraction& frac) {
        frac.numerator = frac.numerator + value * frac.denominator;
        frac.simplify();
        return frac;
    }
    friend Fraction operator-(Fraction& frac, int value) {
        frac.numerator = frac.numerator - value * frac.denominator;
        frac.simplify();
        return frac;
    }
    friend Fraction operator-(int value, Fraction& frac) {
        frac.numerator = frac.numerator - value * frac.denominator;
        frac.simplify();
        return frac;
    }
    friend Fraction operator*(Fraction& frac, int value) {
        frac.numerator = frac.numerator * value;
        frac.simplify();
        return frac;
    }
    friend Fraction operator*(int value, Fraction& frac) {
        frac.numerator = frac.numerator * value;
        frac.simplify();
        return frac;
    }
    friend Fraction operator/(Fraction& frac, int value) {
        frac.denominator = frac.denominator * value;
        frac.simplify();
        return frac;
    }
    friend Fraction operator/(int value, Fraction& frac) {
        frac.denominator = frac.denominator * value;
        frac.simplify();
        return frac;
    }
    friend Fraction operator+=(Fraction& frac, int value) {
        frac.numerator += value * frac.denominator;
        frac.simplify();
        return frac;
    }
    friend Fraction operator+=(int value, Fraction& frac) {
        frac.numerator += value * frac.denominator;
        frac.simplify();
        return frac;
    }
    friend Fraction operator-=(Fraction& frac, int value) {
        frac.numerator -= value * frac.denominator;
        frac.simplify();
        return frac;
    }
    friend Fraction operator-=(int value, Fraction& frac) {
        frac.numerator -= value * frac.denominator;
        frac.simplify();
        return frac;
    }
    friend Fraction operator*=(Fraction& frac, int value) {
        frac.numerator *= value;
        frac.simplify();
        return frac;
    }
    friend Fraction operator*=(int value, Fraction& frac) {
        frac.numerator *= value;
        frac.simplify();
        return frac;
    }
    friend Fraction operator/=(Fraction& frac, int value) {
        frac.denominator *= value;
        frac.simplify();
        return frac;
    }
    friend Fraction operator/=(int value, Fraction& frac) {
        frac.denominator *= value;
        frac.simplify();
        return frac;
    }

    friend bool operator==(const Fraction& frac, int value) {
        return frac.numerator == value * frac.denominator;
    }
    friend bool operator==(int value, const Fraction& frac) {
        return frac.numerator == value * frac.denominator;
    }
    friend bool operator!=(const Fraction& frac, int value) {
        return frac.numerator != value * frac.denominator;
    }
    friend bool operator!=(int value, const Fraction& frac) {
        return frac.numerator != value * frac.denominator;
    }
    friend bool operator>=(const Fraction& frac, int value) {
        return frac.numerator >= value * frac.denominator;
    }
    friend bool operator>=(int value, const Fraction& frac) {
        return frac.numerator >= value * frac.denominator;
    }
    friend bool operator<=(const Fraction& frac, int value) {
        return frac.numerator <= value * frac.denominator;
    }
    friend bool operator<=(int value, const Fraction& frac) {
        return frac.numerator <= value * frac.denominator;
    }
    friend bool operator>(const Fraction& frac, int value) {
        return frac.numerator > value * frac.denominator;
    }
    friend bool operator>(int value, const Fraction& frac) {
        return frac.numerator > value * frac.denominator;
    }
    friend bool operator<(const Fraction& frac, int value) {
        return frac.numerator < value * frac.denominator;
    }
    friend bool operator<(int value, const Fraction& frac) {
        return frac.numerator < value * frac.denominator;
    }

    

    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac)
    {
        out << frac.numerator << '/' << frac.denominator;
        return out;
    }
    friend std::istream& operator>>(std::istream& in, Fraction& frac)
    {
        char colon;
        in >> frac.numerator >> colon >> frac.denominator;
        frac.simplify();
        return in;
    }

private:
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    void simplify() {
        int del = this->gcd(numerator, denominator);
        numerator /= del;
        denominator /= del;
    }
};

int main() {
    Fraction fr_1, fr_2(3, 4), fr_3(5, 6), fr_4(fr_2), fr_5;
    fr_1 = fr_2 + fr_3;
    std::cout << fr_1 << std::endl;
    std::cin >> fr_5;
    fr_5 /= 3;
    std::cout << fr_5 << std::endl;
    if (fr_2 == fr_4) {
        std::cout << "TRUE" << std::endl;
    }
    else{ std::cout << "FALSE" << std::endl; }

    if (fr_2 > 1) {
        std::cout << "TRUE" << std::endl;
    }
    else { std::cout << "FALSE" << std::endl; }
    return 0;
}