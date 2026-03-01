#include "Polynom.h"

Polynom:: Polynom() {}

Polynom::Polynom(const Polynom& other) {
    terms = other.terms; // js give it to TList
}

Polynom& Polynom::operator=(const Polynom& other) {
    if (this == &other) return *this;
    terms = other.terms;
    return *this;
}

bool Polynom::empty() const { return terms.fp == nullptr; }
int Polynom::size() { return terms.size(); }

// Insert monom into right key-place 
void Polynom::addMonomSorted(const Monom& m) {
    if (m.isZero()) return;

    // empty list, just add
    if (terms.fp == nullptr) {
        terms.addFirst(m);
        return;
    }

    // if m should be before head
    if (m > terms.fp->val) {
        terms.addFirst(m);
        return;
    }

    // walk with prev, cur pointers until cur->val <= m or end
    TLink<Monom>* prev = nullptr;
    TLink<Monom>* cur = terms.fp;
    while (cur != nullptr && cur->val > m) {
        prev = cur;
        cur = cur->next;
    }

    // Case 1 found equal monom - merge into cur
    if (cur != nullptr && cur->val == m) {
        cur->val += m;
        if (cur->val.isZero()) {
            // need to remove cur
            if (prev == nullptr) {
                // cur is head
                terms.delFirst();
            }
            else {
                prev->next = cur->next;
                if (cur == terms.lp) {
                    // removed last element? update lp!!
                    terms.lp = prev;
                }
                delete cur;
            }
        }
        return;
    }

    // Case 2 cur == nullptr - empty list just add
    if (cur == nullptr) {
        terms.addLast(m);
        return;
    }

    // Case 3 insert between prev and cur
    TLink<Monom>* node = new TLink<Monom>(m, cur);
    if (prev == nullptr) {
        terms.fp = node; // didnt want to add bur VS told me it can be null
        // ive already checked it but ok
    }
    else {
        prev->next = node;
    }
    // lp unchanged (we didnt insert at tail)
}

Polynom& Polynom::operator+=(const Monom& m) {
    addMonomSorted(m);
    return *this;
}

Polynom& Polynom::operator-=(const Monom& m) {
    Monom tmp = m;
    tmp *= -1.0;
    addMonomSorted(tmp);
    return *this;
}

// poly add - lineal
Polynom& Polynom::operator+=(const Polynom& other) {
    // making new poly - then going thru 2 lists and add needed link
    Polynom res;
    TLink<Monom>* p = this->terms.fp;
    TLink<Monom>* q = other.terms.fp;

    while (p != nullptr && q != nullptr) {
        if (p->val == q->val) {
            Monom m = p->val; // copy
            m += q->val;      // add coefs
            // if its not zero - merge
            if (!m.isZero()) res.terms.addLast(m);
            p = p->next;
            q = q->next;
        }
        else if (p->val > q->val) {
            res.terms.addLast(p->val);
            p = p->next;
        }
        else {
            res.terms.addLast(q->val);
            q = q->next;
        }
    }

    // if theres something left (its already ordered)
    while (p != nullptr) {
        res.terms.addLast(p->val);
        p = p->next;
    }
    while (q != nullptr) {
        res.terms.addLast(q->val);
        q = q->next;
    }

    this->terms = res.terms;
    return *this;
}

Polynom& Polynom::operator-=(const Polynom& other) {
    Polynom neg = other;
    TLink<Monom>* t = neg.terms.fp;
    while (t != nullptr) {
        t->val *= -1.0;
        t = t->next;
    }
    *this += neg;
    return *this;
}


// Multing of polys - CUADRIC
Polynom& Polynom::operator*=(const Polynom& other) {
    // еcheck if some of plynoms is 0
    if (this->terms.fp == nullptr || other.terms.fp == nullptr) {
        this->terms.clean();
        return *this;
    }

    Polynom result;
    // cycle for 1st poly monoms
    TLink<Monom>* p = this->terms.fp;
    while (p != nullptr) {

        // its temporary poly -  from multint 1 monom on poly
        Polynom temp;

        TLink<Monom>* q = other.terms.fp;
        while (q != nullptr) {
            Monom prod = p->val * q->val;

            if (!prod.isZero())
                temp.terms.addLast(prod); // IF WE ADD - ITS ORDERED!! DONT NEED ADDSORTED

            q = q->next;
        }

        // add two polys - LINEAR
        result += temp;

        p = p->next;
    }

    this->terms = result.terms;
    return *this;
}

double Polynom::value(double x, double y, double z) const {
    double sum = 0.0;
    TLink<Monom>* t = terms.fp;
    while (t != nullptr) {
        sum += t->val.value(x, y, z);
        t = t->next;
    }
    return sum;
}

void Polynom:: clear() { terms.clean(); }