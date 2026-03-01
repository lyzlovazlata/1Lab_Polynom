#pragma once
#include "TList.h"
#include "Monom.h"
#include <iostream>

class Polynom {
public:
    TList<Monom> terms; // monom list that ordered for keys lexigraph

    Polynom();
    Polynom(const Polynom& other);

    Polynom& operator=(const Polynom& other);

    bool empty() const;
    int size();
    // Insert monom into right key-place 
    void addMonomSorted(const Monom& m);

    Polynom& operator+=(const Monom& m);

    Polynom& operator-=(const Monom& m);

    // poly add - lineal
    Polynom& operator+=(const Polynom& other);
    Polynom& operator-=(const Polynom& other);

    // Multing of polys - CUADRIC
    Polynom& operator*=(const Polynom& other);

    // made it friend ofr my comfort
    friend Polynom operator+(Polynom a, const Polynom& b) { a += b; return a; }
    friend Polynom operator-(Polynom a, const Polynom& b) { a -= b; return a; }
    friend Polynom operator*(Polynom a, const Polynom& b) { a *= b; return a; }

    friend Polynom operator+(Polynom a, const Monom& m) { a += m; return a; }
    friend Polynom operator-(Polynom a, const Monom& m) { a -= m; return a; }
    friend Polynom operator*(Polynom a, const Monom& m) {
        // linear too
        TLink<Monom>* t = a.terms.fp;
        while (t != nullptr) {
            t->val *= m;
            t = t->next;
        }
        return a;
    }

    double value(double x, double y, double z) const;

    // in: how many monoms, then coef and powers
    friend std::istream& operator>>(std::istream& is, Polynom& p) {
        int n;
        if (!(is >> n)) { is.setstate(std::ios::failbit); return is; }
        p.terms.clean();
        for (int idx = 0; idx < n; ++idx) {
            Monom m;
            if (!(is >> m)) { is.setstate(std::ios::failbit); return is; }
            p.addMonomSorted(m);
        }
        return is;
    }

    // out like 3x^2y - 4z + 5
    friend std::ostream& operator<<(std::ostream& os, const Polynom& p) {
        if (p.terms.fp == nullptr) { os << "0"; return os; }
        TLink<Monom>* t = p.terms.fp;
        bool first = true;
        while (t != nullptr) {
            const Monom& m = t->val;
            if (m.isZero()) { t = t->next; continue; }
            double c = m.getCoef();
            // знак и коэффициент
            if (first) {
                // if its first - js print
                os << m;
                first = false;
            }
            else {
                if (c >= 0) os << " + " << m;
                else os << " - ";
                // if its not first and neg - print abs
                if (c < 0) {
                    Monom absM = m;
                    absM *= -1.0;
                    os << absM;
                }
            }
            t = t->next;
        }
        return os;
    }

    void clear();
};