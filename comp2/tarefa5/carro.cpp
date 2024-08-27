#include "carro.h"
#include <iostream>
using namespace std;

Carro::Carro(int litro, int pos, int consumo){
    this->litro = litro;
    this->pos = pos;
    this->consumo = consumo;
}

void Carro::abastecer(int l){
    /*
        caso essa quantidade de litros não ultrapasse a quantidade permitida
        de litros no tanque, então encha. Do contrário, avise ao condutor que
        não é possível encher mais. 
    */
    if(this->litro + l > 50){
        cout << "Não é possível abastecer mais que 50 litros. Tanque cheio.\n";
        this->litro = 50;
        return; //early return;
    }

    this->litro += l;

    cout << "Gasolina no tanque: " << this->litro << ".\n";
}

void Carro::mover(int km){
    //garantindo que o usuário se moverá para frente independente da quantidade de km
    int dist = (km - this->pos > 0)? km - this->pos : km + this->pos;


    /*
       caso não haja gasolina o suficiente para terminar o trajeto, avisar ao condutor
       e andar apenas o possível. Do contrário, mover-se essa quantidade de km e diminuir 
       a quantidade de litros baseado no consumo do carro.
    */
    if((dist/this->consumo) > this->litro){
        cout << "Não é possível completar o trajeto.\n";
        this->pos = dist - (dist/this->litro);
        this->litro = 0;
    }else{
        this->pos = km;
        this->litro -= (dist/this->consumo);
    }
    cout << "Posição atual: " << this->pos << "\n";
    cout << "Gasolina no tanque: " << this->litro << ".\n";
}

//Destrutor
Carro::~Carro(){
    cout << "Destruindo objeto carro\n";
}

