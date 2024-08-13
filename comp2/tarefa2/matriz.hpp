#ifndef MATRIX_HPP
#define MATRIZ_HPP

#include <iostream>
#include <string.h>
const int MAXN = 100;

class Matriz {
    private:
        int matriz[MAXN][MAXN];
        int lines;
        int columns;
    public:
        Matriz();
        Matriz(int lines, int columns);

        void setXY(int x, int y, int v);
        int getXY(int x, int y);

        bool equals(const Matriz &other);
        Matriz *transposta();
        Matriz *oposta();
        Matriz nula();
        bool identidade();
        bool diagonal();
        bool singular();
        bool simetrica();
        bool antisimetrica();

        Matriz operator+(const Matriz &other);
        Matriz operator-(const Matriz &other);
        Matriz operator*(const Matriz &other);
        void operator=(const Matriz &other);
        void operator+=(const Matriz &other);
        void operator-=(const Matriz &other);
        friend std::ostream &operator<<(std::ostream &out, const Matriz &m);
        friend std::istream &operator>>(std::istream &in, Matriz &m);
};


#endif

