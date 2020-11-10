#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

class Auto
{
private:
    int patente;
    char color[20];
    char marca[20];


public:
    Auto();
    Auto(int p, char c[], char m[]);

    void setPatente(int p);
    int getPatente();


    void mostrar();
};


#endif // AUTO_H_INCLUDED
