#ifndef FATURA_H
#define FATURA_H

#include <string>
using namespace std;

class Fatura{
    private:
        string id;
        string description;
        int item;
        double price;
    public:
        Fatura(string id, string description, int item, double price);
        string getId();
        string getDescription();
        int getItem();
        double getPrice();
        double getTotalFatura();

        void setId(string id);
        void setDescription(string description);
        void setItem(int item);
        void setPrice(double Price);
        ~Fatura();

};


#endif