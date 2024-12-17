#ifndef PILHA_H
#define PILHA_H

template<class T>
class Pilha {
private:

    class Node {
    protected:
        T *t;
        Node *prox;
    public:
        Node ( T *t, Node *prox) {
            this->t = t;
            this->prox = prox;
        }
    };
public:
    Node *node;

    Pilha () {
        node = 0;
    }


    void push ( T *t ) {
        node = new Node (t, node);
    }

    T* pop () {
        if (node) {
            Node *aux = node;
            T* ret = aux->t;
            node = node->prox;
            delete aux;
            return ret;
        } else {
            throw "Pilha vazia";
        }
    }

    T* topo () {
        if (node) {
            return node->t;
        } else {
            throw "Pilha vazia";
        }
    }
};

#endif // PILHA_H