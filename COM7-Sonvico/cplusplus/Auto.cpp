#include <iostream>
#include "Auto.h"
#include "string.h"

using namespace std;



Auto::Auto()
{
    patente=0;
    color[0]='\0';
    marca[0]='\0';
};

Auto::Auto(int p, char c[], char m[])
{
    patente=p;
    strcpy(color, c);
    strcpy(marca, m);
};

void Auto::setPatente(int p)
{
    patente=p;
};

int Auto::getPatente()
{
    return patente;
};

void Auto::mostrar()
{
    cout<<patente<<endl;
    cout<<color<<endl;
    cout<<marca<<endl;
};
