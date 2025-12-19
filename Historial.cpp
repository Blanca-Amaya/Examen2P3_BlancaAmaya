#include "Historial.h"
#include "Cafe.h"
#include "Te.h"
#include "Chocolate.h"
#include <iostream>
#include <fstream>
using namespace std;

Historial::~Historial() {
	for (int i = 0; i < (int)bebidas.size(); i++) {
		if (bebidas[i] != nullptr) {
			delete bebidas[i];
			bebidas[i] = nullptr;
		}
	}
	bebidas.clear();
}

void Historial::guardarHistorial() {
	total_vendido = 0;
	for (int i = 0; i < (int)bebidas.size(); i++) {
		if (bebidas[i] != nullptr) {
			total_vendido += bebidas[i]->calcularPrecioFinal();
		}
	}

	ofstream archivo("Historial.dat", ios::binary);
	if (!archivo.is_open()) {
		cout << "Error al abrir archivo para guardar." << endl;
		return;
	}

	archivo.write((char*)&total_vendido, sizeof(total_vendido));

	for (int i = 0; i < (int)bebidas.size(); i++) {
		if (bebidas[i] == nullptr) continue;

		string nombre = bebidas[i]->getNombre();
		double precio = bebidas[i]->calcularPrecioFinal();

		int tamanio = (int)nombre.size();
		archivo.write((char*)&tamanio, sizeof(tamanio));
		archivo.write(nombre.c_str(), tamanio);

		archivo.write((char*)&precio, sizeof(precio));
	}
	archivo.close();
	cout << "Historial guardado." << endl;
}

void Historial::cargarHistorial() {
	ifstream archivo("Historial.dat", ios::binary);
	if (!archivo.is_open()) {
		cout << "No hay historial" << endl;
		return;
	}

	archivo.read((char*)&total_vendido, sizeof(total_vendido));

	cout << "Historial de Bebidas Vendidas en Memoria: " << endl;

	int contador = 1;
	while (!archivo.eof()) {
		int tamanio;
		archivo.read((char*)&tamanio, sizeof(tamanio));
		if (archivo.eof()) break;

		char* c = new char[tamanio + 1];
		archivo.read(c, tamanio);
		c[tamanio] = '\0';
		string nombre(c);
		delete[] c;

		double precio;
		archivo.read((char*)&precio, sizeof(precio));
		if (archivo.eof()) break;

		cout << "No. " << contador << " Nombre: " << nombre << " PrecioFinal: " << precio << endl;
		contador++;
	}

	cout << "Ingresos totales hasta el momento: " << endl;
	cout << "L. " << total_vendido << endl;

	archivo.close();
}

Historial Historial::operator+(Bebida* b) {
	agregar(b);
	return *this;
}

void Historial::agregar(Bebida* b) {
	if (b == nullptr) return;

	Bebida* copia = nullptr;

	Cafe* cafe = dynamic_cast<Cafe*>(b);
	Te* te = dynamic_cast<Te*>(b);
	Chocolate* chocolate = dynamic_cast<Chocolate*>(b);

	if (cafe != nullptr) {
		copia = new Cafe(b->getNombre(), b->getPrecioBase(), cafe->getGramosCafeina());
	}
	else if (te != nullptr) {
		copia = new Te(b->getNombre(), b->getPrecioBase(), te->getEsenciaHerbal());
	}
	else if (chocolate != nullptr) {
		copia = new Chocolate(b->getNombre(), b->getPrecioBase(), chocolate->getGramosAzucar());
	}

	if (copia != nullptr) {
		bebidas.push_back(copia);
	}
}

void Historial::mostrarHistorial() {
	if (bebidas.empty()) {
		cout << "Historial vacio" << endl;
		return;
	}

	cout << "Historial de Bebidas Vendidas en Memoria: " << endl;
	double total_memoria = 0;
	for (int i = 0; i < (int)bebidas.size(); i++) {
		if (bebidas[i] != nullptr) {
			double precio = bebidas[i]->calcularPrecioFinal();
			total_memoria += precio;
			cout << "No. " << i + 1 << " Nombre: " << bebidas[i]->getNombre()
				<< " PrecioFinal: " << precio << endl;
		}
	}
	cout << "Ingresos totales hasta el momento: " << endl;
	cout << "L. " << total_memoria << endl;
}