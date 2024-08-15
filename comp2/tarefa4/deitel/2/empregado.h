#ifndef EMPREGADO_H
#define EMPREGADO_H

#include <iostream>
using namespace std;

class Empregado{
    private:
        string nome;
        string sobrenome;
        double salario;
    public:
        Empregado(string n, string sn, double s);
        string getName();
        string getSurname();
        double getPayment();
        
        void setName(string s);
        void setSurname(string s);
        void setPayment(double p);
        ~Empregado();
};

#endif