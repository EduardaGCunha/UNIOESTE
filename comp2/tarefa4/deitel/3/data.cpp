#include "data.h"

#include <iostream>
using namespace std;

Data::Data(int d, int m, int a){
    this->dia = d;
    this->mes = m;
    this->ano = a;
}

int Data::getDia(){
    return dia;
}

int Data::getMes(){
    return mes;
}

int Data::getAno(){
    return ano;
}

void Data::setDia(int d){
    this->dia = d;
}

void Data::setAno(int a){
    this->ano = a;
}

void Data::setMes(int m){
    this->mes = m;
}

void Data::show(){
    cout << "Data: " << dia << "/" << mes << "/" << ano << ".\n";
}

bool bissexto(int a) {
    return (a % 4 == 0 && a % 100 != 0) || (a % 400 == 0);
}

int checarDia(int m, int a) {
    int dias[] = {31, bissexto(a) ? 29 : 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return dias[m - 1];
}


void Data::avancar(int seconds){
    if(seconds < 86400) return;
    int d = seconds/84600;
    dia += d;
    while(dia > checarDia(mes, ano)){
        dia-= checarDia(mes, ano);
        mes++;
        if(mes > 12){
            mes = 1;
            ano++;
        }
    }

}

void Data::retroceder(int seconds){
    if(seconds < 86400) return;
    int d = seconds/84600;
    dia -= d;
    //cout << dia << endl;
    while(dia < 1){
        mes--;
        if(mes < 1){
            mes = 12;
            ano--;
        }
        dia += checarDia(mes, ano);
    }
}



Data::~Data(){
    cout << "\nDestruindo objeto Data\n";
}