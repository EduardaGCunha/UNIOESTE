#include <iostream>
#include "configuracao.h"
#include "calculadora.h"
#include "calculadora2.h"
using namespace std;

int main(){
    Calculadora c1; 
    Calculadora2<double> c2;
    Calculadora2<int> c3;
    cout << c1.soma(5, 6) << endl;
    cout << c2.soma(5.5, 6.7) << endl;
    cout << c3.subtrai(4, 2) << endl;
    Configuracao* config = Configuracao::getInstance();
    cout << config->getConfig() << endl;

    config->setConfig("Tema: Escuro");
    cout << config->getConfig() << endl;
     
}