#ifndef ESFERA_H
#define ESFERA_H

#include "circulo.h"

class Esfera : public Circulo{
    public:
        Esfera(double x, double y, double r);
        double getArea();
};

#endif