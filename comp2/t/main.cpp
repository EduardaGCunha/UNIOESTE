#include <iostream>
#include "ponto.h"
#include "circulo.h"
using namespace std;


int main(){
    Ponto *p1 = new Ponto(1.2, 1.3);
    p1->show();
    Ponto *p2 = new Circulo(5.0, 7.5, 3.0);
    p2->show();
    Circulo *c1 = new Circulo(0.8, 2.1, 6.4);

    for(int i = 0; i < 10; i++) c1->aumentar();
    c1->show();
    for(int i = 0; i < 7; i++) c1->diminuir();
    c1->show();

    delete p1;
    delete p2;
    delete c1;
}