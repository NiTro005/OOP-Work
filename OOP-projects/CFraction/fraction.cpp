#include "fraction.h"


    Fraction Fraction::operator+(const Fraction& frac) {
        Fraction res(*this);
        res.numerator = this->numerator * frac.denominator + frac.numerator * this->denominator;
        res.denominator = this->denominator * frac.denominator;
        simplify();
        return res;
    }
    Fraction Fraction::operator-(const Fraction& frac) {
        Fraction res(*this);
        res.numerator = this->numerator * frac.denominator - frac.numerator * this->denominator;
        res.denominator = this->denominator * frac.denominator;
        simplify();
        return res;
    }
    Fraction Fraction::operator*(const Fraction& frac) {
        Fraction res(*this);
        res.numerator = this->numerator * frac.numerator;
        res.denominator = this->denominator * frac.denominator;
        simplify();
        return res;
    }
    Fraction Fraction::operator/(const Fraction& frac) {
        Fraction res(*this);
        res.numerator = this->numerator * frac.denominator;
        res.denominator = this->denominator * frac.numerator;
        simplify();
        return res;
    }
    Fraction Fraction::operator=(const Fraction& frac) {
        if (this != &frac) {
            this->denominator = frac.denominator;
            this->numerator = frac.numerator;
        }
        simplify();
        return *this;
    }
    Fraction Fraction::operator+=(const Fraction& frac) {
        this->denominator = this->numerator * frac.denominator + frac.numerator * this->denominator;
        this->numerator = this->denominator * frac.denominator;
        simplify();
        return *this;
    }
    Fraction Fraction::operator-=(const Fraction& frac) {
        this->denominator = this->numerator * frac.denominator - frac.numerator * this->denominator;
        this->numerator = this->denominator * frac.denominator;
        simplify();
        return *this;
    }
    Fraction Fraction::operator*=(const Fraction& frac) {
        this->denominator = this->numerator * frac.numerator;
        this->numerator = this->denominator * frac.denominator;
        simplify();
        return *this;
    }
    Fraction Fraction::operator/=(const Fraction& frac) {
        this->denominator = this->numerator * frac.denominator;
        this->numerator = this->denominator * frac.numerator;
        simplify();
        return *this;
    }
    bool Fraction::operator==(const Fraction& frac) const {
        return (numerator == frac.numerator) && (denominator == frac.denominator);
    }
    bool Fraction::operator!=(const Fraction& frac) const {
        return (numerator != frac.numerator) || (denominator != frac.denominator);
    }
    bool Fraction::operator>=(const Fraction& frac) const {
        return (numerator * frac.denominator >= frac.numerator * denominator);
    }
    bool Fraction::operator<=(const Fraction& frac) const {
        return (numerator * frac.denominator <= frac.numerator * denominator);
    }
    bool Fraction::operator>(const Fraction& frac) const {
        return (numerator * frac.denominator > frac.numerator * denominator);
    }
    bool Fraction::operator<(const Fraction& frac) const {
        return (numerator * frac.denominator < frac.numerator * denominator);
    }

    Fraction operator+(Fraction& frac, int value) {
        frac.numerator = frac.numerator + value * frac.denominator;
        frac.simplify();
        return frac;
    }
    Fraction operator+(int value, Fraction& frac) {
        frac.numerator = frac.numerator + value * frac.denominator;
        frac.simplify();
        return frac;
    }
    Fraction operator-(Fraction& frac, int value) {
        frac.numerator = frac.numerator - value * frac.denominator;
        frac.simplify();
        return frac;
    }
    Fraction operator-(int value, Fraction& frac) {
        frac.numerator = frac.numerator - value * frac.denominator;
        frac.simplify();
        return frac;
    }
    Fraction operator*(Fraction& frac, int value) {
        frac.numerator = frac.numerator * value;
        frac.simplify();
        return frac;
    }
    Fraction operator*(int value, Fraction& frac) {
        frac.numerator = frac.numerator * value;
        frac.simplify();
        return frac;
    }
    Fraction operator/(Fraction& frac, int value) {
        frac.denominator = frac.denominator * value;
        frac.simplify();
        return frac;
    }
    Fraction operator/(int value, Fraction& frac) {
        frac.denominator = frac.denominator * value;
        frac.simplify();
        return frac;
    }
    Fraction operator+=(Fraction& frac, int value) {
        frac.numerator += value * frac.denominator;
        frac.simplify();
        return frac;
    }
    Fraction operator+=(int value, Fraction& frac) {
        frac.numerator += value * frac.denominator;
        frac.simplify();
        return frac;
    }
    Fraction operator-=(Fraction& frac, int value) {
        frac.numerator -= value * frac.denominator;
        frac.simplify();
        return frac;
    }
    Fraction operator-=(int value, Fraction& frac) {
        frac.numerator -= value * frac.denominator;
        frac.simplify();
        return frac;
    }
    Fraction operator*=(Fraction& frac, int value) {
        frac.numerator *= value;
        frac.simplify();
        return frac;
    }
    Fraction operator*=(int value, Fraction& frac) {
        frac.numerator *= value;
        frac.simplify();
        return frac;
    }
    Fraction operator/=(Fraction& frac, int value) {
        frac.denominator *= value;
        frac.simplify();
        return frac;
    }
    Fraction operator/=(int value, Fraction& frac) {
        frac.denominator *= value;
        frac.simplify();
        return frac;
    }

    bool operator==(const Fraction& frac, int value) {
        return frac.numerator == value * frac.denominator;
    }
    bool operator==(int value, const Fraction& frac) {
        return frac.numerator == value * frac.denominator;
    }
    bool operator!=(const Fraction& frac, int value) {
        return frac.numerator != value * frac.denominator;
    }
    bool operator!=(int value, const Fraction& frac) {
        return frac.numerator != value * frac.denominator;
    }
    bool operator>=(const Fraction& frac, int value) {
        return frac.numerator >= value * frac.denominator;
    }
    bool operator>=(int value, const Fraction& frac) {
        return frac.numerator >= value * frac.denominator;
    }
    bool operator<=(const Fraction& frac, int value) {
        return frac.numerator <= value * frac.denominator;
    }
    bool operator<=(int value, const Fraction& frac) {
        return frac.numerator <= value * frac.denominator;
    }
    bool operator>(const Fraction& frac, int value) {
        return frac.numerator > value * frac.denominator;
    }
    bool operator>(int value, const Fraction& frac) {
        return frac.numerator > value * frac.denominator;
    }
    bool operator<(const Fraction& frac, int value) {
        return frac.numerator < value * frac.denominator;
    }
    bool operator<(int value, const Fraction& frac) {
        return frac.numerator < value * frac.denominator;
    }

    

    std::ostream& operator<<(std::ostream& out, const Fraction& frac)
    {
        out << frac.numerator << '/' << frac.denominator;
        return out;
    }
    std::istream& operator>>(std::istream& in, Fraction& frac)
    {
        char colon;
        in >> frac.numerator >> colon >> frac.denominator;
        frac.simplify();
        return in;
    }

    int Fraction::gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    void Fraction::simplify() {
        int del = this->gcd(numerator, denominator);
        numerator /= del;
        denominator /= del;
    }

