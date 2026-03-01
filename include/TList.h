#pragma once
#include <stdexcept>

template<class T>
struct TLink {
    T val;
    TLink* next;
    TLink(const T& _val = T(), TLink* _next = nullptr)
        : val(_val), next(_next) {
    }
};

template<class T>
class TIterator {
    TLink<T>* cur;
public:
    TIterator(TLink<T>* _cur = nullptr) : cur(_cur) {}

    bool hasNext() {
        return cur != nullptr;
    }

    T& next() {
        if (!hasNext()) throw - 1;
        T& tmp = cur->val;
        cur = cur->next;
        return tmp;
    }
};

template<class T>
class TList {
public:
    TLink<T>* fp;  // head
    TLink<T>* lp;  // tail

    TList() {
        fp = nullptr;
        lp = nullptr;
    }

    ~TList() {
        clean();
    }

    TList(const TList<T>& other) {
        fp = nullptr;
        lp = nullptr;

        TLink<T>* t = other.fp;
        while (t != nullptr) {
            addLast(t->val);
            t = t->next;
        }
    }

    TList& operator=(const TList<T>& other) {
        if (this == &other) return *this;

        clean();
        TLink<T>* t = other.fp;
        while (t != nullptr) {
            addLast(t->val);
            t = t->next;
        }
        return *this;
    }

    void clean() {
        while (fp != nullptr)
            delFirst();
    }

    bool empty() {
        return fp == nullptr;
    }

    int size() {
        int cnt = 0;
        TLink<T>* t = fp;
        while (t != nullptr) {
            cnt++;
            t = t->next;
        }
        return cnt;
    }

    void addFirst(const T& v) {
        TLink<T>* node = new TLink<T>(v, fp);
        fp = node;
        if (lp == nullptr)
            lp = node;
    }

    void addLast(const T& v) {
        TLink<T>* node = new TLink<T>(v, nullptr);

        if (fp == nullptr) {
            fp = node;
            lp = node;
            return;
        }

        lp->next = node;
        lp = node;
    }

    void delFirst() {
        if (fp == nullptr) return;

        TLink<T>* tmp = fp;
        fp = fp->next;
        delete tmp;

        if (fp == nullptr)
            lp = nullptr;
    }

    void delLast() {
        if (fp == nullptr) return;

        if (fp == lp) {
            delete fp;
            fp = nullptr;
            lp = nullptr;
            return;
        }

        TLink<T>* t = fp;
        while (t->next != lp)
            t = t->next;

        delete lp;
        lp = t;
        lp->next = nullptr;
    }

    void insertInd(int n, const T& val) {
        if (n < 0) throw - 1;

        if (n == 0) {
            addFirst(val);
            return;
        }

        TLink<T>* t = fp;
        int i = 0;
        while (i < n - 1 && t != nullptr) {
            t = t->next;
            i++;
        }

        if (t == nullptr) throw - 1;

        TLink<T>* node = new TLink<T>(val, t->next);
        t->next = node;

        if (t == lp)
            lp = node;
    }
    // funk to not to work with ptrs every time when we need to delet smth
    void delInd(int n) {
        if (n < 0) throw - 1;

        if (n == 0) {
            delFirst();
            return;
        }

        TLink<T>* t = fp;
        int i = 0;
        while (i < n - 1 && t != nullptr) {
            t = t->next;
            i++;
        }

        if (t == nullptr || t->next == nullptr) throw - 1;

        TLink<T>* d = t->next;
        t->next = d->next;

        if (d == lp)
            lp = t;

        delete d;
    }

    T& operator[](int ind) {
        if (ind < 0) throw - 1;

        TLink<T>* t = fp;
        int i = 0;

        while (i < ind && t != nullptr) {
            t = t->next;
            i++;
        }

        if (t == nullptr) throw - 1;
        return t->val;
    }

    TIterator<T> iter() {
        return TIterator<T>(fp);
    }
};