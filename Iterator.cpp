//
// Created by Tadija on 11/29/2021.
//
#include "Iterator.h"

Iterator::Iterator(Array & arr):arr(arr),ptr(arr.data){}

Complex *Iterator::operator->() const {
    return ptr;
}

Complex &Iterator::operator*() const {
    return *ptr;
}

Iterator::operator bool() const {
    return ptr>=arr.data and ptr < arr.data +arr.cap;
}

bool Iterator::operator!() const {
    return *this == false;
}

Iterator &Iterator::operator++() {
    ++ptr;
    return *this;
}

Iterator Iterator::operator++(int k) {
    return ++(*this);
}

Iterator Array::getIter() {
    return Iterator(*this);
}
