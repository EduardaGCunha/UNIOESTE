#ifndef TRIANGULORETANGULO_H
#define TRIANGULORETANGULO_H

#include "forma-geometrica.h"
#include "ponto.h"

class TrianguloRetangulo : public FormaGeometrica {
    private:
        Ponto *p1;
        Ponto *p2;
    public:
        TrianguloRetangulo(Ponto *p1, Ponto *p2);
        double getArea();

};

#endif