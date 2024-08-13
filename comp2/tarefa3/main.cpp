#include <iostream>
#include "arvore.h"

using namespace std;

int main(){
    Tree *root = 0;
    int n = 10;
    int arr[n] = {1, 7, 8, 4, 5, 9, 3, 2, 6};
    for(int i = 0; i < n; i++){
        root->add(&root, arr[i]);
    }
    root->show();

    delete root;
}