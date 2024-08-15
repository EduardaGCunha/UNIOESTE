#include <iostream>
using namespace std;
#include "fatura.h"
int main(){
    Fatura fatura("123", "livro", 2, 35.90);
    cout << fatura.getId() << " " << fatura.getDescription() << " " << fatura.getItem() << " " << fatura.getPrice() << endl; 
    cout << fatura.getTotalFatura() << endl;

    fatura.setPrice(-1.2);
    cout << "Impossível negativar a fatura " << " " << fatura.getPrice() << endl;
}