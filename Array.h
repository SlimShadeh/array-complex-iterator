                                                                                                //
// Created by Tadija on 11/29/2021.
//
#ifndef UNTITLED1_ARRAY_H
#define UNTITLED1_ARRAY_H

#include "Complex.h"
#include "Iterator.h"
using namespace complex;
using namespace std;

class Array {
    friend class Iterator;
    int cap;
    Complex* data;

    friend class Complex;
    void clear();
    void copy(const Array &a);
    void move(Array &a);
    friend void swap(Array &a, Array &b);
public:
    int getCap () const { return cap;}
    explicit Array(int cap=5);
    Array(const Array &a);
    Array(Array &&a);
/*
    Array &operator =(const Array &a);
    Array &operator =(Array &&a);
*/
    const Complex &operator [](int ind) const;
    Complex &operator [](int ind);

    int operator()(int low, int high, Complex& c) const;
    int operator()( Complex& c) const;

    Array &operator=(Array a);
    ~Array();

    Iterator getIter();
};



#endif //UNTITLED1_ARRAY_H
