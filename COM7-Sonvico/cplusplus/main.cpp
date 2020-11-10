#include <iostream>
#include "stdlib.h"
#include "stdlib.h"
#include "Auto.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Auto autito1;

    Auto autito2(1234, "Rojo", "Ford");

    autito1.mostrar();

    autito2.mostrar();

    autito1.setPatente(10);

    autito1.mostrar();

    return 0;
}
