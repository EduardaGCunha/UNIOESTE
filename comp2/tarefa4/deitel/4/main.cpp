#include <iostream>
using namespace std;

#include "inteiro.h"

int main(){
    InteiroSet set1(6), set2(10);

    cout << "Set 1: " << set1.toString() << endl;
    cout << "Set 2: " << set2.toString() << endl;

    set1.insereElemento(1); // Adicionando o elemento 1
    cout << "Elementos de set1 após inserir 1: " << set1.toString() << endl;

    // Deletando um elemento de set2
    set2.deleteElemento(4); // Removendo o elemento 4
    cout << "Elementos de set2 após deletar 4: " << set2.toString() << endl;

    // União dos dois conjuntos
    InteiroSet uniaoSet = set1.uniao(set2);
    cout << "União de set1 e set2: " << uniaoSet.toString() << endl;

    // Interseção dos dois conjuntos
    InteiroSet interseccaoSet = set1.interseccao(set2);
    cout << "Interseção de set1 e set2: " << interseccaoSet.toString() << endl;

    // Verificando se os conjuntos são iguais
    set1.isEqual(set2);

    return 0;
}   