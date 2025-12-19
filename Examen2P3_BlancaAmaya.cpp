#include <iostream>
#include "Menu.h"
#include "Historial.h"
#include "Cafe.h"
#include "Chocolate.h"
#include "Te.h"
using namespace std;



void LomosCoffee() {
    int opcion;
    bool resp = true;
    Menu* menu = new Menu();
    Historial* historial = new Historial();
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
            menu->verMenu();
            break;
        case 2: {
            string nombre;
            double precio;
            int tipo;
            cout << "Ingrese el nombre de la bebida: ";
            cin >> nombre;
            cout << "Ingrese Precio Base de la bebida: ";
            cin >> precio;
            if (precio <= 0) {
                cout << "Precio inválido :C" << endl;
                break;
            }
            cout << "1. Cafe, 2. Te, 3. Chocolate";
            cin >> tipo;
            int valor;
            Bebida* b = nullptr;
            switch (tipo) {
            case 1:
                cout << "Ingrese gramos de cafeina: ";
                cin >> valor;
                if (valor < 1 || valor > 100) {
                    cout << "Valor debe ser 1-100" << endl;
                    break;
                }
                b = new Cafe(nombre, precio, valor);
            case 2:
                cout << "Ingrese la esencia herbal: ";
                cin >> valor;
                if (valor < 1 || valor > 100) {
                    cout << "Valor debe ser 1-100" << endl;
                    break;
                }
                b = new Te(nombre, precio, valor);
            case 3:
                cout << "Ingrese gramos de azucar: ";
                cin >> valor;
                if (valor < 1 || valor > 100) {
                    cout << "Valor debe ser 1-100" << endl;
                    break;
                }
                b = new Chocolate(nombre, precio, valor);
            default:
                cout << "Opcion invalida";
                break;
            }
            if (b) {
                *menu = *menu + b;
                cout << "Bebida agregada." << endl;
            }
            break;
        }
            
        case 3:
            menu->verMenu();
            if (menu->tam() > 0) {
                int i;
                do {
                    cout << "Elija la bebida que quiere eliminar (1-" << menu->tam() << "): " << endl;
                    cin >> i;
                    if (i < 1 || i > menu->tam()) {
                        cout << "Indice invalido. " << endl;
                    }
                } while (i < 1 || 1 > menu->tam());
            }
            break;
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
            menu->verMenu();
            if (menu->tam() > 0) {
                int id;
                do {
                    cout << "Ingrese el indice de la bebida a vender: ";
                    cin >> id;
                    if (id == 0) {
                        break;
                    } 

                    if (id < 1 || id > menu->tam()) {
                        cout << "Indice invalido" << endl;
                    }
                    else {
                        Bebida* b = menu->getBebida(id - 1);
                        if (b) {
                            *historial = *historial + b;
                            
                        }
                    }
                } while (id != 0);
                historial->guardarHistorial();
            } 
        }
        case 8:
            historial->mostrarHistorial();
            historial->cargarHistorial();
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
    menu();
}