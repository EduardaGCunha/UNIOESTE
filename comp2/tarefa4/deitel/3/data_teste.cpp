#include <iostream>
using namespace std;

#include "data.h"

int main(){
    Data data(30, 10, 2004);
    Data data2(1, 1, 1994);

    data.avancar(172800);
    data.show();
    data.retroceder(172800);
    data.show();
    data2.show();
    data2.retroceder(172800);

    data2.show();
}