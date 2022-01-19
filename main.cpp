#include "Array.h"
#include <cstdlib>
#include "Iterator.h"
using namespace complex;



int main() {
    Array a, b;
    a=move(b);
    a[0]={1,2};
    a[1]= {3,4};
    a[2]={1,2};
    cout <<a[1]<<"\n";
    b=a;
    cout<<b[2]<< "\n";
    cout << "pozicija: "<< a(1,4,a[0])<<"\n";
    for (int i=0;i<a.getCap();i++){
        a[i]=Complex(i=3,i*2+1);
    }
    Iterator it=a.getIter();

    return 0;
/*
    int n=rand();
    int arr[n];
    std::cout << n;
    Complex c1{1, -3},c2{2,4},c3{3,2};
    std::cout << c1<< "\n";
    std::cout << real(c1) << "|" << img(c1) << std::endl;
    Complex c4=c1+c2;
    std::cout << c4<<std::endl;
    c1+=c3;
    std::cout << (c1-=c2) << "\n";
    std::cout << (c1-={1,-1})<< "\n";
    c3=c1*c2;
    std::cout << c3<< "\n";
    std::cout << "abs: " << abs(c1)<< "\n";
    std::cout << "arg: " << arg(c1) << "\n";
    std::cout << "konj: " << ~c1 << "\n";
    c1={1/10. +4/6.,0.5};
    c2={46/60.,0.5};
    std::cout <<"c1==c2: " << (c1==c2) << "\n";
    std::cout <<"c1!=c2: " << (c1!=c2) << "\n";

    std::cin >>c4;
    std::cout << c4;
    return 0;*/
}