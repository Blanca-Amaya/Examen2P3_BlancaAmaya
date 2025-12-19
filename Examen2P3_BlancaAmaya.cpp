#include <iostream>
#include "Menu.h"
#include "Historial.h"
#include "Cafe.h"
#include "Chocolate.h"
#include "Te.h"
#include <ctime>
#include <string>
#include <locale>
using namespace std;

void LomosCoffee() {
    int opcion;
    bool resp = true;
    Menu* menu = new Menu();
    Historial* historial = new Historial();

    while (resp) {
        cout << "¡Bienvenido al sistema Lomo's Coffee! Pónganse cómodo y siéntese a manejar su local :D" << endl;
        cout << "1. Ver Menú" << endl;
        cout << "2. Agregar al Menú" << endl;
        cout << "3. Eliminar del Menú" << endl;
        cout << "4. Vaciar Menú" << endl;
        cout << "5. Guardar Menú" << endl;
        cout << "6. Cargar Menú" << endl;
        cout << "7. Vender Bebidas" << endl;
        cout << "8. Ver Historial" << endl;
        cout << "9. Salir" << endl;
        cout << "Ingrese la opción que desea realizar: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            menu->verMenu();
            break;

        case 2: {
            string nombre;
            double precio;
            int tipo;

            cout << "Ingrese nombre de la bebida: ";
            cin >> nombre;

            do {
                cout << "Ingrese Precio Base de la bebida: ";
                cin >> precio;
                if (precio <= 0) {
                    cout << "Precio inválido :(" << endl;
                }
            } while (precio <= 0);

            do {
                cout << "1. Café" << endl;
                cout << "2. Té" << endl;
                cout << "3. Chocolate" << endl;
                cout << "Ingrese Tipo de la bebida: ";
                cin >> tipo;
                if (tipo < 1 || tipo > 3) {
                    cout << "Tipo invalido" << endl;
                }
            } while (tipo < 1 || tipo > 3);

            int valor;
            Bebida* b = nullptr;

            switch (tipo) {
            case 1:
                do {
                    cout << "Ingrese gramos de cafeina (1-100): ";
                    cin >> valor;
                    if (valor < 1 || valor > 100) {
                        cout << "Valor debe ser 1-100" << endl;
                    }
                } while (valor < 1 || valor > 100);
                b = new Cafe(nombre, precio, valor);
                break;

            case 2:
                do {
                    cout << "Ingrese esencia de las hierbas (1-100): ";
                    cin >> valor;
                    if (valor < 1 || valor > 100) {
                        cout << "Valor debe ser 1-100" << endl;
                    }
                } while (valor < 1 || valor > 100);
                b = new Te(nombre, precio, valor);
                break;

            case 3:
                do {
                    cout << "Ingrese gramos de azucar (1-100): ";
                    cin >> valor;
                    if (valor < 1 || valor > 100) {
                        cout << "Valor debe ser 1-100" << endl;
                    }
                } while (valor < 1 || valor > 100);
                b = new Chocolate(nombre, precio, valor);
                break;
            }

            if (b) {
                *menu = *menu + b;
                cout << "Bebida agregada." << endl;
            }
            break;
        }

        case 3: {
            menu->verMenu();
            if (menu->tam() > 0) {
                int i;
                do {
                    cout << "Elija la bebida que quiere eliminar (1-" << menu->tam() << "): " << endl;
                    cin >> i;
                    if (i < 1 || i > menu->tam()) {
                        cout << "Índice de bebida no existente" << endl;
                    }
                } while (i < 1 || i > menu->tam());

                menu->eliminar(i - 1);
            }
            break;
        }

        case 4:
            menu->vaciarMenu();
            break;

        case 5:
            menu->guardarMenu();
            break;

        case 6:
            menu->cargarMenu();
            break;

        case 7: {
            cout << "|---Pantalla de Ventas---|" << endl;
            menu->verMenu();

            if (menu->tam() > 0) {
                int id;
                do {
                    cout << "Ingrese el índice de la bebida a vender (0 para terminar): ";
                    cin >> id;

                    if (id == 0) {
                        break;
                    }

                    if (id < 1 || id > menu->tam()) {
                        cout << "Número fuera de rango" << endl;
                    }
                    else {
                        Bebida* b = menu->getBebida(id - 1);
                        if (b) {
                            *historial = *historial + b;
                        }
                    }
                } while (true);

                historial->guardarHistorial();
            }
            break;
        }

        case 8:
            cout << "1. Ver historial en memoria" << endl;
            cout << "2. Cargar historial desde archivo" << endl;
            cout << "Opción: ";
            int opcionHistorial;
            cin >> opcionHistorial;

            if (opcionHistorial == 1) {
                historial->mostrarHistorial();
            }
            else if (opcionHistorial == 2) {
                historial->cargarHistorial();
            }
            else {
                cout << "Opción inválida" << endl;
            }
            break;

        case 9:
            cout << "Saliendo..." << endl;
            resp = false;
            break;

        default:
            cout << "Opción inválida" << endl;
            break;
        }
    }

    delete menu;
    delete historial;
}

void menu() {
    int opcion;
    bool resp = true;

    while (resp) {
        cout << "<><><><><><>MENÚ><><><><><><><>" << endl;
        cout << "1. Lomo's Coffee" << endl;
        cout << "2. Salir" << endl;
        cout << "Ingrese la opción que desea realizar: ";
        cin >> opcion;

        switch (opcion) {
        case 1:
            LomosCoffee();
            break;
        case 2:
            cout << "Saliendo..." << endl;
            resp = false;
            break;
        default:
            cout << "Opción inválida" << endl;
            break;
        }
    }
}

int main() {
    setlocale(LC_ALL, "spanish");
    menu();
}