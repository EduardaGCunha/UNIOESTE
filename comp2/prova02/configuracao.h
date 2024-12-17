#ifndef CONFIGURACAO_H
#define CONFIGURACAO_H
#include <iostream>
using namespace std;

class Configuracao{
    private:
        static Configuracao *me; 
        string config;
        Configuracao();
    public: 
        static Configuracao *getInstance();
        void setConfig(string msg);
        string getConfig();
        void doLog(string msg);
        ~Configuracao();

};

#endif