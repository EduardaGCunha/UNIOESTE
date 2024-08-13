#ifndef ARVORE_H
#define ARVORE_H

class Tree {
    private:
        int node;
        Tree *r;
        Tree *l;
        Tree(int node);
    public:
        static void add(Tree **node, int val);
        void show();
        ~Tree();
};

#endif