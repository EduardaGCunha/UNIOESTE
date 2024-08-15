#include "empregado.h"
#include <iostream>
using namespace std;

Empregado::Empregado(string n, string sn, double s){
    this->nome = n;
    this->sobrenome = sn;
    this->salario = s;
}

string Empregado::getName(){
    return nome;
}

double Empregado::getPayment(){
    return salario;
}

string Empregado::getSurname(){
    return sobrenome;
}

void Empregado::setName(string s){
    this->nome = s;
}

void Empregado::setSurname(string s){
    this->sobrenome = s;
}

void Empregado::setPayment(double p){
    this->salario = p;
}

Empregado::~Empregado(){
    cout << "Destruindo objeto Empregado\n";
}
