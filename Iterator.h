//
// Created by Tadija on 11/29/2021.
//

#ifndef UNTITLED1_ITERATOR_H
#define UNTITLED1_ITERATOR_H

#include "Array.h"

class Iterator {
    Array &arr;
    Complex *ptr;

    friend class Array;

    Iterator(Array &arr);
public:
    Iterator(const Iterator &i)= default;
    Iterator& operator=(const Iterator &i)=delete;
    Complex *operator->() const;
    Complex &operator*() const;
    operator bool () const;
    bool operator!() const;
    Iterator& operator ++();
    Iterator operator ++(int k);

};


#endif //UNTITLED1_ITERATOR_H
