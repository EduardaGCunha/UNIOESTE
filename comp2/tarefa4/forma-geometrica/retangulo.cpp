#include <iostream>
using namespace std;

#include "retangulo.h"

Retangulo::Retangulo(Ponto *p1, Ponto *p2){
    this->p1 = p1;
    this->p2 = p2;
}

double Retangulo::getArea(){
    cout << "\nArea do Retangulo: ";
    return abs(p1->getX() - p2->getX())*abs(p1->getY() - p2->getY());
}

Retangulo::~Retangulo(){
    cout << "\nDestruindo Retangulo\n";
}