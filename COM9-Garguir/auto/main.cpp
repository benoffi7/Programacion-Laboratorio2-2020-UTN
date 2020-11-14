#include <iostream>
#include "Auto.h"

using namespace std;

int main()
{
    cout << "Hello world!" << endl;

    Auto autos[100];

    Auto auto1;

    Auto auto2(123);

    Auto auto3(124, "Rojo", "Fiat");

    cout << endl << " Auto 1 " << endl;
    auto1.mostrar();

    cout << endl << " Auto 2 " << endl;
    auto2.mostrar();

    cout << endl << " Auto 3 " << endl;
    auto3.mostrar();

    auto1.setPatente(125);
    auto1.setColor("Amarillo");
    auto1.setMarca("Mercedes Benz");

    if(auto1.getColor() == "Amarillo"){
        cout << "El auto es amarillo " << endl;
    }

    cout << endl << " Auto 1 " << endl;
    auto1.mostrar();
    auto2.setColor("Azul");
    cout << endl << "Auto 2 - Color: " << auto2.getColor() << endl;

    return 0;
}
