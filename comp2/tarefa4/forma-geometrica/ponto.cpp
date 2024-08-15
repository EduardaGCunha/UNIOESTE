#include <iostream>
using namespace std;
#include "ponto.h"

Ponto::Ponto(double x, double y){
    cout << "\nCriando objeto ponto\n";
    this->x = x;
    this->y = y;
}

void Ponto::show(){
     cout << "("
         << x
         << ","
         << y
         << ")" << endl;
}

Ponto::~Ponto(){
    cout << "\n Destruindo objeto Ponto" << endl;
    show();
}

double Ponto::getX(){
    return x; 
}

double Ponto::getY(){
    return y;
}




