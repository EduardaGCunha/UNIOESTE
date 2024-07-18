#include "circulo.h"

#include <iostream>
using namespace std;

Circulo::Circulo(double x, double y, double r){
    this->x = x;
    this->y = y;
    this->r = r;
}

double Circulo::getX() const{
    return x;
}

double Circulo::getY() const{
    return y;
}

double Circulo::getR() const{
    return r;
}

void Circulo::show(){
    cout << "(" << x << "," << y << "," << r << ")" << endl;
}

void Circulo::aumentar(){
    r += 1;
    cout << r << " " << endl;
}
