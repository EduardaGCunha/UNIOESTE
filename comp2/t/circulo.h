#ifndef CIRCULO_H
#define CIRCULO_H

#include "ponto.h"
class Circulo : public Ponto {
private: 
    double r;
public:
    Circulo(double x, double y, double r);
    double getR();
    void show();
    void aumentar();
    void diminuir();

    ~Circulo();

};


#endif