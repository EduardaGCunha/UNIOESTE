#include <bits/stdc++.h>
#include "pilha.h"
using namespace std;



int main() {
    string expressao = "3 4 + 2 * 7 /"; // Exemplo: (3 + 4) * 2 / 7
    Pilha<int> p;
    int a = 1;
    p.push(&a);
   
    cout << p.topo() << endl;
    
    return 0;
}
