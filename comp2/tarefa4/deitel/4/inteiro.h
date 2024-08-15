#ifndef INTEIRO_H
#define INTEIRO_H

#include <iostream>
using namespace std;

class InteiroSet{
    //prof estou usando mask pra treinar bitmask pra fase 2 da OBI e da maratona
    private:
        int mask;
    public:
        InteiroSet(int mask);
        void setMask(int m);
        void insereElemento(int i);
        void deleteElemento(int i);
        int getMask();

        InteiroSet uniao(const InteiroSet &other);
        InteiroSet interseccao(const InteiroSet &other);
        string toString() const;
        void isEqual(const InteiroSet &other);

};
#endif 