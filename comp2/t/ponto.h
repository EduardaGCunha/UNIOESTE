#ifndef PONTO_H
#define PONTO_H

class Ponto {
private:
    double x;
    double y;
public:
    Ponto(double x, double y);

    virtual double getX();
    virtual double getY();
    virtual void show();

    virtual ~Ponto();
};

#endif