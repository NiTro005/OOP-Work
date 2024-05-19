#pragma once
#include <iostream>
class Fraction {
    int numerator;       // ÷èñëèòåëü
    int denominator;     // çàìåíàòåëü
public:
    Fraction() : numerator(0), denominator(1) {}
    Fraction(int num, int dem) : numerator(num), denominator(dem) {}
    Fraction(const Fraction& frac) : numerator(frac.numerator), denominator(frac.denominator) {}

    Fraction operator+(const Fraction& frac);
    Fraction operator-(const Fraction& frac);
    Fraction operator*(const Fraction& frac);
    Fraction operator/(const Fraction& frac);

    Fraction& operator+=(const Fraction& frac);
    Fraction& operator-=(const Fraction& frac);
    Fraction& operator*=(const Fraction& frac);
    Fraction& operator/=(const Fraction& frac);
    Fraction& operator=(const Fraction& frac);

    Fraction& operator+=(int value);
    Fraction& operator-=(int value);
    Fraction& operator*=(int value);
    Fraction& operator/=(int value);


    bool operator==(const Fraction& frac) const;
    bool operator>=(const Fraction& frac) const;
    bool operator<=(const Fraction& frac) const;
    bool operator>(const Fraction& frac) const;
    bool operator<(const Fraction& frac) const;
    bool operator!=(const Fraction& frac) const;


    friend Fraction operator+(const Fraction& frac, int value);
    friend Fraction operator-(const Fraction& frac, int value);
    friend Fraction operator*(const Fraction& frac, int value);
    friend Fraction operator/(const Fraction& frac, int value);
    friend Fraction operator+(int value, const Fraction& frac);
    friend Fraction operator-(int value, const Fraction& frac);
    friend Fraction operator*(int value, const Fraction& frac);
    friend Fraction operator/(int value, const Fraction& frac);


    friend bool operator==(const Fraction& frac, int value);
    friend bool operator==(int value, const Fraction& frac);
    friend bool operator>=(const Fraction& frac, int value);
    friend bool operator>=(int value, const Fraction& frac);
    friend bool operator<=(const Fraction& frac, int value);
    friend bool operator<=(int value, const Fraction& frac);
    friend bool operator!=(const Fraction& frac, int value);
    friend bool operator!=(int value, const Fraction& frac);
    friend bool operator>(const Fraction& frac, int value);
    friend bool operator>(int value, const Fraction& frac);
    friend bool operator<(const Fraction& frac, int value);
    friend bool operator<(int value, const Fraction& frac);

    friend std::ostream& operator<<(std::ostream& out, const Fraction& frac);
    friend std::istream& operator>>(std::istream& in, Fraction& frac);

private:
    int gcd(int a, int b);
    void simplify();
};
