#include "arvore.h"
#include <iostream>
using namespace std;

Tree::Tree(int node){
    this->node = node;
    this->l = 0;
    this->r = 0;
}

void Tree::add(Tree **curnode, int val){
    if(*curnode == nullptr){
        *curnode = new Tree(val);
        cout << "Adicionado valor: " << val << endl;
    }else{
        if(val > (*curnode)->node) add(&((*curnode)->r), val);
        else add(&(*curnode)->l, val);
    }
}

void Tree::show(){
    if(this->l != nullptr) l->show();

    cout << node << endl;

    if(this->r != nullptr) r->show();
}

Tree::~Tree(){
    cout << "Destruindo arvore com vertice: " << this->node << endl;
    if(this->l != nullptr) delete l;
    if(this->r != nullptr) delete r;
}