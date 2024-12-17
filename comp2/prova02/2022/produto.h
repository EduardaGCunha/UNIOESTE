#ifndef PRODUTO_H
#define PRODUTO_H

#include <iostream>
using namespace std;

class Produto{
    private:
        string id;
        string name;
        int quantity;
        double price;
    public:
        Produto();
        Produto(string id);
        Produto(string id, string s, int qtd, double p);
        string getId();
        string getName();
        int getQuantity();
        int getPrice();
        void setId(string id);
        void setName(string s);
        void setQtd(int qtd);
        void setPrice(double p);
        friend ostream &operator<<(ostream &out, const Produto &p);
        ~Produto();
};

#endif