#ifndef PONTO_H
#define PONTO_H

class Ponto {
    private:
        double x;
        double y;
    public:
        Ponto(double x, double y);
        void show();
        double getX();
        double getY();
        ~Ponto();
};

#endif