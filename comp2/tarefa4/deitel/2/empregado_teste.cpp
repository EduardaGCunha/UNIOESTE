
#include <iostream>
using namespace std;
#include "empregado.h"

int main(){
    Empregado e1("Marcelo", "Silva", 1222.50);
    Empregado e2("Maria", "Nogueira", 15000.50);

    cout << "Salario anual de " << e1.getName() << " " << e1.getPayment()*12 << endl;
    cout << "Salario anual de " << e2.getName() << " " << e2.getPayment()*12 << endl;

    double aumento = e1.getPayment()*1.1;
    e1.setPayment(aumento);
    cout << "Aumento de 10% no salario anual de " << e1.getName() << " eh " << e1.getPayment()*12 << endl;
    aumento = e2.getPayment()*1.1;
    e2.setPayment(aumento);
    cout << "Aumento de 10% no salario anual de " << e2.getName() << " eh " << e2.getPayment()*12 << endl;
}