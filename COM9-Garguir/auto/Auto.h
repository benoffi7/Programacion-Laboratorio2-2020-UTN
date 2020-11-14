#ifndef AUTO_H_INCLUDED
#define AUTO_H_INCLUDED
#include <iostream>
#include <string>

using namespace std;

class Auto
{

private:
    int patente;
    string color;
    string marca;

public:
    /// Metodos Constructores
    Auto();
    Auto(int patente);
    Auto(int patente, string color, string marca);

    /// Metodos Setters y Getters
    void setPatente(int patente);
    int getPatente();

    void setColor(string color);
    string getColor();

    void setMarca(string marca);
    string getMarca();

    void mostrar();
};



#endif // AUTO_H_INCLUDED
