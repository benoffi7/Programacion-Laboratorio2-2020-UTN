#include "Auto.h"
#include "string.h"

Auto::Auto()
{
    patente=0;
    color[0]='\0';
    marca[0]='\0';
};

Auto::Auto(int p, char c[], char m[])
{
    this->patente=p;
    strcpy(this->color, c);
    strcpy(this->marca, m);
};

void Auto::setPatente(int p)
{
    this->patente=p;
};

int Auto::getPatente()
{
    return this->patente;
};

void Auto::mostrar()
{
    cout<<patente<<endl;
    cout<<color<<endl;
    cout<<marca<<endl;
};
