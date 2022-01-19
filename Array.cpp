//
// Created by Tadija on 11/29/2021.
//

#include "Array.h"

Array::Array(int cap): cap(cap), data(new Complex[cap]) {

}

Array::~Array() {
    clear();

}

Array::Array(const Array &a) {
    cout << "Pozvao se copy konstruktor.\n";
    copy(a);
}

Array::Array(Array &&a) {
    cout << "Pozvao se move operator.\n";
    move(a);
}
/*

Array& Array::operator=(const Array &a) {
    cout <<"copy assignment.\n";

if (this !=&a){
    clear();
    copy(a);
    }
    return *this;

    Array tmp=a;
    swap(*this,tmp);
    return *this;
}

Array &Array::operator=(Array &&a) {
    cout <<"move assignment.\n";

if(this !=&a){
        this->data=a.data;
        cap=a.cap;
        a.data=nullptr;
    }

    swap(*this,a);
    return *this;
}
*/

void Array::clear() {
    delete[] data;
    data=nullptr;
}

void Array::copy(const Array &a) {
    data=new Complex[cap=a.cap];
    for(int i=0;i<cap;i++){
        data[i]=a.data[i];
    }
}

void Array::move(Array &a) {
    this->data=a.data;
    cap=a.cap;
    a.data=nullptr;
}

void swap(Array &a, Array &b) {
    swap(a.cap,b.cap);
    swap(a.data,b.data);
}

Array &Array::operator=(Array a) {\
    swap(*this,a);
    return *this;
}

Complex &Array::operator[](int ind) {
    return const_cast<Complex &>((const_cast<const Array &>(*this))[ind]);
}

const Complex &Array::operator[](int ind) const {
    if(ind <0 or ind >=cap) exit(1);
    return data[ind];
}

int Array::operator()(int low, int high,  Complex &c) const {
    if (low < 0)
        low = 0;
    if (low >= cap)
        low = cap - 1;
    if (high < 0)
        high = 0;
    if (high >= cap)
        high = cap - 1;
    for (int i = low; i <= high; i++) {
        if (data[i] == c)
            return i;
    }
    return -1;
}
int Array::operator()( Complex &c) const {
    return (*this)(0,cap-1,c);
}

