#ifndef CIRCULO_H
#define CIRCULO_H

class Circulo {
private:
    double x;
    double y;
    double r;
public:
    Circulo(double x, double y, double r);

    double getX() const;
    double getY() const;
    double getR() const;
    void aumentar();
    double diminuir() const;
    void setR(double newR);

    void show();

    ~Circulo() = default;
};

#endif