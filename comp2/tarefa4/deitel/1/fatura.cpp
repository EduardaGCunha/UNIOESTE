#include <iostream>
using namespace std;

#include "fatura.h"

Fatura::Fatura(string id, string description, int item, double price){
    this->id = id;
    this->description = description;
    this->item = item;
    this->price = price;
}

void Fatura::setId(string id){
    this->id = id;
}

void Fatura::setDescription(string description){
    this->description = description;
}

void Fatura::setItem(int item){
    this->item = item;
}

void Fatura::setPrice(double price){
    if(price < 0) this->price = 0.0;
    else this->price = price;
}

string Fatura::getId(){
    return id;
}

string Fatura::getDescription(){
    return description;
}

int Fatura::getItem(){
    return item;
}

double Fatura::getPrice(){
    return price;
}

double Fatura::getTotalFatura(){
    cout << "São " << item << " itens de valor " << price; 
    cout << " custando ";
    double valor = item*price; 
    if(valor < 0) return 0.0;
    else return valor; 
}


Fatura::~Fatura(){
    cout << "Destruindo Fatura\n";
}