#pragma once
#define MAX_POWER 10
#define MIN_POWER -5
#define E 1e-6

#include <iostream>
#include <cmath>
// Union, it helps us to save our powers as keys in char bytes
union Data {
    unsigned int key;
    unsigned char powers[3];
};

// Monom, made with union to compare monoms and make operations
class Monom {
private:
    Data data;      // compact representation of powers
    double coef;

    // private constructor from coef + key, need only for ops, not user
    Monom(double _coef, unsigned int _key) : coef(_coef) {
        data.key = _key;
    }

    // convert stored byte to actual exponent (with MIN_POWER!!!! helps to store negative powers)
    int storedToPow(unsigned char stored) const {
        return static_cast<int>(stored) + MIN_POWER;
    }

    // revers of previous funk
    unsigned char powToStored(int exp) {
        if (exp < MIN_POWER || exp > MAX_POWER) throw - 1;
        return static_cast<unsigned char>(exp - MIN_POWER);
    }

public:
    // i think it will never be used but ok it should be
    Monom();

    // main constructor we use - from coef and powers
    Monom(double _coef, int i, int j, int k);
    // ofc save my dynamic memory
    Monom(const Monom& other);
    Monom& operator=(const Monom& other);

    // if we want to take our powers
    int getI() const;
    int getJ() const;
    int getK() const;
    // other helpers-geters
    double getCoef() const;
    void setCoef(double c);
    unsigned int key() const;
    // dont forget apout epsilon! we work with doublies :)
    bool isZero() const;

    // my comparators means ONLY POWERS, so we compare keys
    bool operator==(const Monom& m) const;
    bool operator!=(const Monom& m) const;
    bool operator>=(const Monom& m) const;
    bool operator<=(const Monom& m) const;
    bool operator>(const Monom& m) const;
    bool operator<(const Monom& m) const;

    // we can add ONLY monoms with the same powers (keys)
    Monom operator+(const Monom& m);
    Monom operator-(const Monom& m);

    Monom& operator+=(const Monom& m);

    Monom& operator-=(const Monom& m);

    // mult works with every monom, but we nees our i j k to make it
    Monom operator*(const Monom& m);

    Monom& operator*=(const Monom& m);
    // idk if we need this in this lab 
    Monom operator*(double c);

    Monom& operator*=(double c);

    // unar minus
    Monom operator-();

    // solving our monom
    double value(double x, double y, double z) const;

    //outing
    // it looks like coef*x^i y^j z^k (skip 0, ^1 )
friend std::ostream& operator<<(std::ostream& os, const Monom& m) {
    if (m.isZero()) {
        os << "0";
        return os;
    }

    int i = m.getI();
    int j = m.getJ();
    int k = m.getK();

    bool hasVars = (i != 0 || j != 0 || k != 0);

    double c = m.coef;

    if (!hasVars) {
        os << c;
        return os;
    }
    if (std::fabs(c - 1.0) < E) {}
    else if (std::fabs(c + 1.0) < E) {
        os << "-";
    }
    else {
        os << c;
    }

    if (i != 0) {
        os << "x";
        if (i != 1) os << "^" << i;
    }
    if (j != 0) {
        os << "y";
        if (j != 1) os << "^" << j;
    }
    if (k != 0) {
        os << "z";
        if (k != 1) os << "^" << k;
    }

    return os;
}

    // easy in - coef i j k
    friend std::istream& operator>>(std::istream& is, Monom& m) {
        double c;
        int i, j, k;
        // bad in FORMAT - like abc. (Why failbit - cause op>> usually
        // doesnt throw, but we can use failbit to know thats something is wrong
        if (!(is >> c >> i >> j >> k)) {
            is.setstate(std::ios::failbit);
            return is;
        }
        // not format but VALUES
        if (i < MIN_POWER || i > MAX_POWER || j < MIN_POWER || j > MAX_POWER || k < MIN_POWER || k > MAX_POWER) {
            is.setstate(std::ios::failbit);
            return is;
        }
        m.coef = c;
        m.data.powers[2] = m.powToStored(i);
        m.data.powers[1] = m.powToStored(j);
        m.data.powers[0] = m.powToStored(k);
        return is;
    }
};