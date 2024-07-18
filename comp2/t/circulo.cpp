#include <iostream>
#include "circulo.h"

using namespace std;

// Construtor do Circulo
Circulo::Circulo(double x, double y, double r) : Ponto(x, y){
    cout << "Construindo objeto circulo" << endl;
    this->r = r;
}

double Circulo::getR(){
    return r;
}

void Circulo::show(){
    cout << "(x: " << Ponto :: getX() << ", y: " << Ponto::getY() << ", r: ";
    cout << r << ")" << endl;
}

void Circulo::aumentar(){
    r++;
}

void Circulo:: diminuir(){
    if(r > 0) r--;
    else cout << "Raio não pode ser negativo" << endl;
}

Circulo::~Circulo(){
    cout << "\nDestruindo Circulo" << endl;
}

