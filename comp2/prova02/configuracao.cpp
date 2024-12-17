#include "configuracao.h"
#include <iostream>
using namespace std;

Configuracao *Configuracao::me= 0;
Configuracao::Configuracao(){
    this->config = "";
}

Configuracao *Configuracao::getInstance(){
    if(!me) me = new Configuracao();
    return me; 
}

void Configuracao::doLog(string msg){
    cout << msg << endl;
}

void Configuracao::setConfig(string msg){
    this->config = msg;
}

string Configuracao::getConfig(){
    return this->config;
}

Configuracao::~Configuracao(){
    me = 0;
}