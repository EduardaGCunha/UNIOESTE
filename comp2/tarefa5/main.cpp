#include <iostream>
using namespace std;
#include "carro.h"

int main(){
    Carro c1(0, 0, 15), c2(0, 0, 15);

    cout << "---------------ABASTECIMENTO--------------" << endl;
    cout << "Abastecendo carro c1\n"; 
    c1.abastecer(20);
    cout << "Abastecendo carro c2\n"; 
    c2.abastecer(30);
    cout << "-------------------------------------------" << endl;

    cout << "---------------MOVIMENTO--------------" << endl;

    cout << "Movendo carro c1 em 200km\n"; 
    c1.mover(200);
    cout << endl;
    cout << "Movendo carro c2 em 400km\n"; 
    c2.mover(400);
    cout << endl;

    cout << "Movendo carro c1 em mais 100km\n"; 
    c2.mover(100);
     cout << endl;
    cout << "Abastecendo carro c2 para completar trajeto\n"; 
    c2.abastecer(61);
     cout << endl;
    cout << "-------------------------------------------" << endl;

}

