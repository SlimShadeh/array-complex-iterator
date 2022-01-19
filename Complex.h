//
// Created by Tadija on 11/22/2021.
//
#include <iostream>
#ifndef UNTITLED1_COMPLEX_H
#define UNTITLED1_COMPLEX_H

namespace complex {
    class Complex {

        double real, img;
        static constexpr const double delta=0.001;
    public:
        Complex(double real=0,double img=0) : real(real), img(img) {}

        friend std::ostream& operator <<(std::ostream& os,const Complex &c);
        friend std::istream& operator >>(std::istream &is,Complex &c1);
        double getReal() const { return real; }
        double getImg() const { return img; }
        friend double real(Complex c) { return c.real; }
        friend double img(Complex c) { return c.img; }

        friend Complex operator+(const Complex &c1,const Complex &c2);

        Complex& operator+=(const Complex& c);

        Complex& operator -=(const Complex& c);

        friend Complex operator-(Complex c1,Complex c2);

        Complex operator*(const Complex &c) const;

        friend double abs(const Complex &c);

        friend double arg(const Complex &c);

        Complex operator~() const;

        Complex operator+() const;
        friend bool operator ==(Complex &c1,Complex &c2);
        friend bool operator !=(Complex &c1,Complex &c2);

    };
    Complex operator ""i(unsigned long long val);

//Complex operator ""i(long double val);
}


#endif //UNTITLED1_COMPLEX_H
