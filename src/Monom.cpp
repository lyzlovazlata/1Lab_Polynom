#include "Monom.h"

// i think it will never be used but ok it should be
Monom:: Monom() {
    coef = 0.0;
    data.key = 0;
    // thats how we use help-functions
    data.powers[2] = powToStored(0); // x, why? cause lexicographic order. x is
    // more important than others, so it uses the biggest byte
    data.powers[1] = powToStored(0); // y
    data.powers[0] = powToStored(0); // z
}

// main constructor we use - from coef and powers
Monom:: Monom(double _coef, int i, int j, int k) {
    if (i < MIN_POWER || i > MAX_POWER) throw - 1;
    if (j < MIN_POWER || j > MAX_POWER) throw - 1;
    if (k < MIN_POWER || k > MAX_POWER) throw - 1;

    coef = _coef;
    data.key = 0;
    data.powers[2] = powToStored(i);
    data.powers[1] = powToStored(j);
    data.powers[0] = powToStored(k);
}

// ofc save my dynamic memory
Monom:: Monom(const Monom& other) {
    data.key = other.data.key;
    coef = other.coef;
}

Monom& Monom::operator=(const Monom& other) {
    if (this == &other) return *this;
    data.key = other.data.key;
    coef = other.coef;
    return *this;
}

// if we want to take our powers
int Monom:: getI() const { return storedToPow(data.powers[2]); }
int Monom::getJ() const { return storedToPow(data.powers[1]); }
int Monom::getK() const { return storedToPow(data.powers[0]); }
// other helpers-geters
double Monom::getCoef() const { return coef; }
void Monom::setCoef(double c) { coef = c; }
unsigned int Monom::key() const { return data.key; }
// dont forget apout epsilon! we work with doublies :)
bool Monom::isZero() const { return std::fabs(coef) < E; }

// my comparators means ONLY POWERS, so we compare keys
bool Monom::operator==(const Monom& m) const {
    return data.key == m.data.key;
}

bool Monom::operator!=(const Monom& m) const {
    return data.key != m.data.key;
}

bool Monom::operator>=(const Monom& m) const {
    return data.key >= m.data.key;
}
bool Monom:: operator<=(const Monom& m) const {
    return data.key <= m.data.key;
}
bool Monom:: operator>(const Monom& m) const {
    return data.key > m.data.key;
}
bool Monom::operator<(const Monom& m) const {
    return data.key < m.data.key;
}

// we can add ONLY monoms with the same powers (keys)
Monom Monom:: operator+(const Monom& m) {
    if (*this != m) throw - 2;
    return Monom(coef + m.coef, data.key);
}

Monom Monom:: operator-(const Monom& m){
    if (*this != m) throw - 2;
    return Monom(coef - m.coef, data.key);
}

Monom& Monom::operator+=(const Monom& m) {
    if (*this != m) throw - 2;
    coef += m.coef;
    if (std::fabs(coef) < E) coef = 0.0;
    return *this;
}

Monom& Monom::operator-=(const Monom& m) {
    if (*this != m) throw - 2;
    coef -= m.coef;
    if (std::fabs(coef) < E) coef = 0.0;
    return *this;
}

// mult works with every monom, but we nees our i j k to make it
Monom Monom::operator*(const Monom& m){
    int nx = getI() + m.getI();
    int ny = getJ() + m.getJ();
    int nz = getK() + m.getK();
    if (nx < MIN_POWER || nx > MAX_POWER) throw - 1;
    if (ny < MIN_POWER || ny > MAX_POWER) throw - 1;
    if (nz < MIN_POWER || nz > MAX_POWER) throw - 1;
    return Monom(coef * m.coef, nx, ny, nz);
}

Monom& Monom::operator*=(const Monom& m) {
    int nx = getI() + m.getI();
    int ny = getJ() + m.getJ();
    int nz = getK() + m.getK();
    if (nx < MIN_POWER || nx > MAX_POWER) throw - 1;
    if (ny < MIN_POWER || ny > MAX_POWER) throw - 1;
    if (nz < MIN_POWER || nz > MAX_POWER) throw - 1;
    coef *= m.coef;
    data.powers[2] = powToStored(nx);
    data.powers[1] = powToStored(ny);
    data.powers[0] = powToStored(nz);
    return *this;
}

// idk if we need this in this lab 
Monom Monom::operator*(double c) {
    return Monom(coef * c, data.key);
}

Monom& Monom:: operator*=(double c) {
    coef *= c;
    if (std::fabs(coef) < E) coef = 0.0;
    return *this;
}

// unar minus
Monom Monom:: operator-() {
    return Monom(-coef, data.key);
}

// solving our monom
double Monom::value(double x, double y, double z) const {
    return coef * std::pow(x, getI()) * std::pow(y, getJ()) * std::pow(z, getK());
}