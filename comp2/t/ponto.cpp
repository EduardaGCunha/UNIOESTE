#include <iostream>
#include "ponto.h"
using namespace std;

Ponto::Ponto(double x, double y){
    cout << "Construindo objeto ponto" << endl;
    this->x = x;
    this->y = y;
}

double Ponto::getX(){
    return x;
}

double Ponto::getY(){
    return y;
}

void Ponto::show(){
    cout << "(x: " << x << ", y: " << y << ")" << endl;
}

Ponto::~Ponto(){
    cout << "Destruindo objeto ponto" << endl;
}

