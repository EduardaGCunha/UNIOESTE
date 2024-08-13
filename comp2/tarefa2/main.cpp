#include <fstream>
#include "matriz.hpp"
using namespace std;


int main(){
    filebuf F;
    F.open("matriz.txt", ios::in);
    istream is(&F);

    Matriz m1, m2;

    is >> m1 >> m2;

    F.close();

    cout << "Matriz 1" << endl;
    cout << m1 << endl;
    cout << endl;

    cout << "Matriz 2" << endl;
    cout << m2 << endl;
    cout << endl;

    cout << "Soma da matriz 1 e matriz 2" << endl;
    cout << m1 + m2 << endl;

    cout << "Subtração da matriz 1 e matriz 2" << endl;
    cout << m1 - m2 << endl;

    cout << "Soma os conteúdos da matriz 2 na matriz 1" << endl;
    m1 += m2;
    cout << m1 << endl;

    cout << "Subtraí os conteúdos da matriz 2 na matriz 1" << endl;
    m1-=m2;
    cout << m1 << endl;

    cout << "Multiplicação da matriz 1 e matriz 2" << endl;
    cout << m1 * m2 << endl;
    return 0;
}