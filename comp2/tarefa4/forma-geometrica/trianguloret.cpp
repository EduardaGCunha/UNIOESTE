#include <iostream>
using namespace std;

#include "trianguloret.h"

TrianguloRetangulo::TrianguloRetangulo(Ponto *p1, Ponto *p2){
    this->p1 = p1;
    this->p2 = p2;
}

double TrianguloRetangulo::getArea(){
    cout << "\nArea do Triangulo Retangulo: ";
    return (abs(p1->getX() - p2->getX()) * abs(p1->getY() - p2->getY())) / 2;
}
