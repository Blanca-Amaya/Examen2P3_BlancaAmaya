#include <iostream>
using namespace std;

void LomosCoffee() {
    int opcion;
    bool resp = true;
    while (resp) {
        cout << "¡Bienvenido al sistema Lomo's Coffee! Pónganse cómodo y siéntese a manejar su local :D" << endl;
        cout << "1. Ver Menú" << endl;
        cout << "2. Agregar Menú" << endl;
        cout << "3. Eliminar del Menú" << endl;
        cout << "4. Vaciar Menú" << endl;
        cout << "5. Guardar Menú" << endl;
        cout << "6. Cargar Menú" << endl;
        cout << "7. Vender Bebidas" << endl;
        cout << "8. Ver Historial" << endl;
        cout << "9. Salir" << endl;
        cout << "Ingrese la opción que desea realizar: " << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:

            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        case 8:

            break;
        case 9:
            cout << "Saliendo..." << endl;
            resp = false;
            break;
        default:
            cout << "Opcion invalida" << endl;
            return;
        }
    }
}

void menu() {
    int opcion;
    bool resp = true;
    while (resp) {
        cout << "<><><><><><> MENÚ <><><><><><>" << endl;
        cout << "1. Lomo's Coffee" << endl;
        cout << "2. Salir." << endl;
        cin >> opcion;
        switch (opcion) {
        case 1:
            LomosCoffee();
            break;
        case 2:
            cout << "Saliendo..." << endl;
            resp = false;
            break;
        }
    }
}

int main() {
    
}