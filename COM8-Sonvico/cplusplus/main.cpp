#include <iostream>
#include "Auto.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Auto autito1;

    Auto autito2(12345, "Rojo", "Ford");

    autito1.mostrar();

    autito2.mostrar();

    autito1.setPatente(1984);

    autito1.mostrar();

    return 0;
}
