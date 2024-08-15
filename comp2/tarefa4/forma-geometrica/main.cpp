#include <iostream>
#include "forma-geometrica.h"
#include "circulo.h"
#include "retangulo.h"
#include "trianguloret.h"
#include "esfera.h"

using namespace std;

int main(){
    Ponto p1(10, 20);
    Ponto p2(5, 10);

    FormaGeometrica * formas[4];
    formas[0] =  new Circulo(1.5, 2.0, 4.0);
    formas[1] = new Retangulo(&p1, &p2);
    formas[2] = new TrianguloRetangulo(&p1, &p2);
    formas[3] = new Esfera(7.5, 4.2, 10.1);

    for (int i = 0; i < 4; i++)
    {
        cout << formas[i]->getArea() << endl;
    }
    

    for (int i = 0; i < 4; i++)
    {
        delete formas[i];
    }
    
}