#include "circulo.h"
#include <iostream>
using namespace std;

Circulo::Circulo(double x, double y, double r) : Ponto(x, y){
    this-> r = r;
}

double Circulo::getArea(){
    cout << "\nArea do Circulo: ";
    return 3.14*r*r;
}