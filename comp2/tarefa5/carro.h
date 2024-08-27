#ifndef CARRO_H
#define CARRO_H

class Carro{
    private:
        int litro;
        int pos;
        int consumo;
    public:
        Carro(int litro, int pos, int consumo);
        //aumenta a quantidade de litro
        void abastecer(int l);
        //move o carro em uma determinada distancia
        void mover(int km);
        ~Carro();
};

#endif

