#include <iostream>
using namespace std;

#include "inteiro.h"

InteiroSet::InteiroSet(int m){
    this->mask = m;
}

void InteiroSet::setMask(int m){
    this->mask = m;
}

int InteiroSet::getMask(){
    return mask;
}

void InteiroSet::insereElemento(int i){
    mask |= 1<<(i-1);
}

void InteiroSet::deleteElemento(int i){
    mask = mask & ~(1<<(i-1));
}

InteiroSet InteiroSet::uniao(const InteiroSet &other){
    int newMask = this->mask | other.mask;
    InteiroSet n(newMask);
    return n;
}

InteiroSet InteiroSet::interseccao(const InteiroSet &other){
    int newMask = this->mask & other.mask;
    InteiroSet n(newMask);
    return n;
}

string InteiroSet::toString() const {
    string s = "{";
    for(int i = 0; i < sizeof(mask) * 8; ++i){
        if(mask & (1 << i)){
            s += to_string(i + 1) + " ";
        }
    }
    s += "}";
    return s;
}

void InteiroSet::isEqual(const InteiroSet &other){
    if(this->mask != other.mask){
        cout << "Conjuntos não são iguais!\n";
    }else cout << "Conjuntos são iguais!\n";
}
