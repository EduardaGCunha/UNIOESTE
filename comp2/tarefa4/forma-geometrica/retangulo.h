#ifndef RETANGULO_H
#define RETANGULO_H

#include "ponto.h"
#include "forma-geometrica.h"

class Retangulo : public FormaGeometrica {
    private: 
        Ponto *p1;
        Ponto *p2;
    public:
        Retangulo(Ponto* p1, Ponto* p2);
        double getArea();
        ~Retangulo();
};

#endif