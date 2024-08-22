#ifndef ARVORE_H
#define ARVORE_H

class Arvore{
    private:
        int node;
        Arvore *r;
        Arvore *l;
        Arvore(int n);
    public:
        static void add(int node, Arvore **root)
        void show();
        ~Arvore();
};

#endif