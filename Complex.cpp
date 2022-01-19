//
// Created by Tadija on 11/22/2021.
//
#include "Complex.h"
#include <cmath>

namespace complex{
    std::ostream& operator <<(std::ostream& os,const Complex &c) {
        return os << "(" << c.real << (c.img >=0 ? "+" : "") << c.img << "i)";
    }

    Complex operator+(const Complex &c1, const Complex &c2) {
        return {c1.real+c2.real,c1.img+c2.img};
    }

    Complex &Complex::operator+=(const Complex &c) {
        return *this=*this+c;
    }

    Complex &Complex::operator-=(const Complex &c){
        this->real -=c.real;
        this->img -=c.img;
        return *this;
    }

    Complex operator-(Complex c1,Complex c2) {
        return c1 -= c2;
    }

    Complex Complex::operator*(const Complex &c) const {
        //(ac-bd)+(ad+bc)i
        return {(this->real*c.real-this->img*c.img),(this->img *c.real+this->real*c.img)};
    }

    double abs(const Complex &c) {
        return sqrt(c.real *c.real+c.img*c.img);
    }

    double arg(const Complex &c) {
        return std::atan2(c.img,c.real)*180 / M_PI;
    }


    Complex Complex::operator~() const {
        return {real,-img};
    }

    Complex Complex::operator+() const {
        return *this;
    }

    bool operator==(Complex &c1, Complex &c2) {
        if(abs(c1.real-c2.real)<c1.delta && abs(c1.img-c2.img)< c1.delta) return true;
        return false;
    }

    bool operator!=(Complex &c1, Complex &c2) {
        return !(c1==c2);
    }

    std::istream &operator>>(std::istream &is, Complex &c) {
        std::cout << "Provide real and imaginary parts: ";
        return is >>c.real >> c.img;
    }
}


