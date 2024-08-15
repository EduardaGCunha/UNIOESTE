#ifndef DATA_H
#define DATA_H

class Data{
    private:
        int dia; 
        int mes;
        int ano;
    public: 
        Data(int dia, int mes, int ano);
        int getDia();
        int getMes();
        int getAno();

        bool bissexto(int a);

        void setDia(int d);
        void setMes(int m);
        void setAno(int a);

        void show();
        void retroceder(int segundos);
        void avancar(int segundos);
        ~Data();
};

#endif