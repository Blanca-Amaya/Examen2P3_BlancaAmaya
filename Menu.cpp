#include "Menu.h"
#include "Cafe.h"
#include "Te.h"
#include "Chocolate.h"
#include <iostream>
#include <fstream>
#include <sstream>

Menu::~Menu() {
	vaciarMenu();
}

void Menu::eliminar(int indice) {
	if (indice >= 0 && indice < (int)menu.size()) {
		delete menu[indice];
		menu.erase(menu.begin() + indice);
	}
	else {
		cout << "Indice invalido" << endl;
	}
}

void Menu::verMenu() {
	if (menu.empty()) {
		cout << "Menu vacio" << endl;
		return;
	}

	cout << "Menú disponible: " << endl;
	for (int i = 0; i < (int)menu.size(); i++) {
		if (menu[i] != nullptr) {
			cout << "No. " << (i + 1) << " " << menu[i]->getNombre() << " PrecioFinal: " << menu[i]->calcularPrecioFinal() << endl;
		}
	}
}

void Menu::vaciarMenu() {
	for (int i = 0; i < (int)menu.size(); i++) {
		if (menu[i] != nullptr) {
			delete menu[i];
		}
	}
	menu.clear();
	cout << "Menú vaciado correctamente." << endl;
}

void Menu::guardarMenu() {
	ofstream archivo("Menu.txt");
	for (int i = 0; i < (int)menu.size(); i++) {
		Cafe* cafe = dynamic_cast<Cafe*>(menu[i]);
		Te* te = dynamic_cast<Te*>(menu[i]);
		Chocolate* chocolate = dynamic_cast<Chocolate*>(menu[i]);
		if (cafe) {
			archivo << "Cafe," << cafe->getNombre() << "," << cafe->getGramosCafeina() << "," << cafe->getPrecioBase() << ",\n";
		}
		if (te) {
			archivo << "Te," << te->getNombre() << "," << te->getEsenciaHerbal() << "," << te->getPrecioBase() << ",\n";
		}
		if (chocolate) {
			archivo << "Chocolate," << chocolate->getNombre() << "," << chocolate->getGramosAzucar() << "," << chocolate->getPrecioBase() << ",\n";
		}
	}
	archivo.close();
}

void Menu::cargarMenu() {
	ifstream archivo("Menu.txt");
	if (!archivo.is_open()) {
		cout << "Menu.txt no existe" << endl;
		return;
	}
	vaciarMenu();

	string linea;
	while (getline(archivo, linea)) {
		stringstream ss(linea);
		string nombre, precio, tipo, charac;
		getline(ss, tipo, ',');
		getline(ss, nombre, ',');
		getline(ss, charac, ',');
		getline(ss, precio, ',');

		if (tipo.empty() || nombre.empty()) {
			continue;
		}

		try {
			double precio2 = stod(precio);
			int charac2 = stoi(charac);

			if (tipo == "Cafe") {
				menu.push_back(new Cafe(nombre, precio2, charac2));
			}
			else if (tipo == "Te") {
				menu.push_back(new Te(nombre, precio2, charac2));
			}
			else if (tipo == "Chocolate") {
				menu.push_back(new Chocolate(nombre, precio2, charac2));
			}
		}
		catch (const exception& e) {
			cout << "Hubo un error procesando las lineas" << endl;
		}
	}
	archivo.close();
}

Menu Menu::operator+(Bebida* b) {
	agregar(b);
	return *this;
}

void Menu::agregar(Bebida* b) {
	menu.push_back(b);
}

int Menu::tam() {
	return (int)menu.size();
}

Bebida* Menu::getBebida(int b2) {
	if (b2 >= 0 && b2 < (int)menu.size()) {
		return menu[b2];
	}
	return nullptr;
}