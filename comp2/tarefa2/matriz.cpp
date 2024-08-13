#include "matriz.hpp"

Matriz::Matriz(){
    this->lines=0;
    this->columns=0;
}

Matriz::Matriz(int l, int c){
    this->lines = l;
    this->columns = c;
}

void Matriz::setXY(int x, int y, int v){
    this->matriz[x][y] = v;
}

int Matriz::getXY(int x, int y){
    return this->matriz[x][y];
}

Matriz Matriz::operator+(const Matriz &other){
    if(this->lines != other.lines && this->columns != other.columns){
        throw "Matrizes de tamanho distintos. Impossível de somar.";
    }

    Matriz result = Matriz(this->lines, this->columns);

    for(int i = 0; i < this->lines; i++){
        for(int j = 0; j < this->columns; j++){
            result.matriz[i][j] = this->matriz[i][j] + other.matriz[i][j];
        }
    }

    return result;
}

Matriz Matriz::operator-(const Matriz &other){
        if(this->lines != other.lines && this->columns != other.columns){
        throw "Matrizes de tamanho distintos. Impossível de subtrair.";
    }

    Matriz result = Matriz(this->lines, this->columns);

    for(int i = 0; i < this->lines; i++){
        for(int j = 0; j < this->columns; j++){
            result.matriz[i][j] = this->matriz[i][j] - other.matriz[i][j];
        }
    }

    return result;
}

void Matriz::operator=(const Matriz &other){
        if(this->lines != other.lines && this->columns != other.columns){
        throw "Matrizes de tamanho distintos. Impossível de igualar.";
    }

    for(int i = 0; i < this->lines; i++){
        for(int j = 0; j < this->columns; j++){
            this->matriz[i][j] = other.matriz[i][j];
        }
    }
}

void Matriz::operator+=(const Matriz &other){
        if(this->lines != other.lines && this->columns != other.columns){
        throw "Matrizes de tamanho distintos. Impossível de somar e atribuir a primeira.";
    }

    for(int i = 0; i < this->lines; i++){
        for(int j = 0; j < this->columns; j++){
            this->matriz[i][j] += other.matriz[i][j];
        }
    }
}

void Matriz::operator-=(const Matriz &other){
        if(this->lines != other.lines && this->columns != other.columns){
        throw "Matrizes de tamanho distintos. Impossível de subtrair e atribuir a primeira.";
    }

    for(int i = 0; i < this->lines; i++){
        for(int j = 0; j < this->columns; j++){
            this->matriz[i][j] -= other.matriz[i][j];
        }
    }
}

Matriz Matriz::operator*(const Matriz &other){
        if(this->lines != other.lines && this->columns != other.columns){
        throw "Matrizes de tamanho distintos. Impossível de multiplicar.";
    }

    Matriz temp = Matriz(this->lines, other.columns);
    
    for (int i=0; i<this->lines; i++){
        for (int j=0; j<this->columns; j++){
            temp.matriz[i][j] = 0;
            for (int k=0; k<this->columns; k++) temp.matriz[i][j] += this->matriz[i][k] * other.matriz[k][j];
        }
    }
    
    *this = temp;
}


bool Matriz::equals ( const Matriz &other) {
    if (this->lines != other.lines ||
            this->columns != other.columns) {
        return false;
    }
    for ( int i=0; i<lines; i++)
    {
        for ( int j=0; j<columns; j++)
        {
            if (matriz[i][j]!=other.matriz[i][j]) {
                return false;
            }
        }
    }
    return true;
}

Matriz *Matriz::transposta () {
    Matriz *tr = new Matriz(columns, lines);
    for ( int i=0; i<lines; i++)
    {
        for ( int j=0; j<columns; j++)
        {
            this->matriz[j][i] = this->matriz[i][j];
        }
    }
    return tr;
}

Matriz *Matriz::oposta () {
    Matriz *op = new Matriz(lines,columns);
    for ( int i=0; i<lines; i++)
    {
        for ( int j=0; j<columns; j++)
        {
            op->matriz[i][j] = -this->matriz[i][j];
        }
    }
    return op;
}

Matriz Matriz::nula () {
    Matriz matriz (lines, columns);
    return matriz;
}

bool Matriz::identidade() {
    if (lines!=columns) {
        throw "Uma matriz identidade precisa ser quadrada";
    }
    for ( int i=0; i<lines; i++)
    {
        for ( int j=0; j<columns; j++)
        {
            if (i==j && matriz[i][j]!=1)
            {
                return false;
            }
            if (i!=j && matriz[i][j]!=0)
            {
                return false;
            }
        }
    }
    return true;
}

bool Matriz::diagonal() {
    if (lines!=columns) {
        throw "Uma matriz diagonal precisa ser quadrada";
    }
    for ( int i=0; i<lines; i++)
    {
        for ( int j=0; j<columns; j++)
        {
            if (i!=j && matriz[i][j]!=0)
            {
                return false;
            }
        }
    }
    return true;
}

bool Matriz::singular() {
    if (lines!=columns) {
        throw "Uma matriz singular precisa ser quadrada";
    }
    if (diagonal()) {
        for ( int i=1; i<lines; i++)
        {
            if (matriz[i-1][i-1]!=matriz[i][i])
            {
                return false;
            }
        }
    }
    return true;
}

bool Matriz::simetrica() {
    if (lines!=columns) {
        throw "Uma matriz simetrica precisa ser quadrada";
    }
    Matriz *t = this->transposta();
    bool bret = this->equals(*t);
    delete t;
    return bret;

    // return this->equals(this->transposta());
}

bool Matriz::antisimetrica() {
    if (lines!=columns) {
        throw "Uma matriz simetrica precisa ser quadrada";
    }
    Matriz *t = this->transposta();
    Matriz *o = this->oposta();
    bool bret = o->equals(*t);
    delete t;
    delete o;
    return bret;

    //return this->oposta()->equals(this->transposta());
}

std::ostream &operator<<(std::ostream &out, const Matriz &m ) {
    out << m.lines << " " << m.columns << std::endl;
    for ( int i=0; i<m.lines; i++)
    {
        for ( int j=0; j<m.columns; j++)
        {
            out << m.matriz[i][j] << " ";
        }
        out << std::endl;
    }
    return out;
}

std::istream &operator>>(std::istream &in, Matriz &m ) {
    in >> m.lines;
    in >> m.columns;
    for ( int i=0; i<m.lines; i++)
    {
        for ( int j=0; j<m.columns; j++)
        {
            in >> m.matriz[i][j];
        }
    }
    return in;
}


