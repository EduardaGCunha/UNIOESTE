#include <iostream>
using namespace std;

#include "circulo.h"

int main(){
    Circulo c1(1, 1, 5);
    c1.show();
    c1.aumentar();
    c1.aumentar();
    c1.aumentar();
    cout << c1.getR() << endl;
}