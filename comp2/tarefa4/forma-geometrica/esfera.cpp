#include <iostream>
using namespace std;

#include "esfera.h"

Esfera::Esfera(double x, double y, double r) : Circulo(x, y, r){
}

double Esfera::getArea() {
    cout << "\nArea da Esfera: ";
    return 4*r*r*3.14;
}