#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED

#include <iostream>

using namespace std;

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

    /// completar los demas set y get


    void mostrar();

};



#endif // AUTO_H_INCLUDED
