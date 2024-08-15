#ifndef CIRCULO_H
#define CIRCULO_H

#include "ponto.h"
#include "forma-geometrica.h"

class Circulo : public Ponto, public FormaGeometrica {
    public:
        double r;
        Circulo(double x, double y, double r);
        double getArea();
};

#endif