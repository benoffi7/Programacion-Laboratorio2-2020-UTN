#include "Auto.h"

Auto::Auto(){
    this->patente = 0;
    this->color = "";
    this->marca = "";
}

Auto::Auto(int patente){
    this->patente = patente;
    this->color = "";
    this->marca = "";
}

Auto::Auto(int patente, string color, string marca){
    this->patente = patente;
    this->color = color;
    this->marca = marca;
}

void Auto::setPatente(int patente){
    this->patente = patente;
}

int Auto::getPatente(){
    return this->patente;
}

void Auto::setColor(string color){
    this->color = color;
}

string Auto::getColor(){
    return this->color;
}

void Auto::setMarca(string marca){
    this->marca = marca;
}

string Auto::getMarca(){
    return this->marca;
}

void Auto::mostrar(){
    cout << "Patente....: " << this->patente << endl;
    cout << "Color......: " << this->color << endl;
    cout << "Marca......: " << this->marca << endl;
}
