#include "Historial.h"
#include "Cafe.h"
#include "Te.h"
#include "Chocolate.h"
#include <iostream>
#include <fstream>
using namespace std;

Historial::~Historial() {
	for (int i = 0; i < (int)bebidas.size(); i++) {
		delete bebidas[i];
	}
	bebidas.clear();
}

void Historial::guardarHistorial() {
	ofstream archivo("Historial.txt", ios::binary);
	archivo.write((char*)& total_vendido, sizeof(total_vendido));
	for (int i = 0; i < (int)bebidas.size(); i++) {
		string nombre = bebidas[i]->getNombre();
		double precio = bebidas[i]->calcularPrecioFinal();
		int tamanio = nombre.size();
		archivo.write((char*)&tamanio, sizeof(tamanio));
		archivo.write(nombre.c_str(), tamanio);
		archivo.write((char*)&precio, sizeof(precio));
	} 
	archivo.close();
}

void Historial::cargarHistorial() {
	ifstream archivo("Historial.", ios::binary);
	if (archivo.is_open()) {
		cout << "No hay historial" << endl;
		return;
	}
	double total;
	archivo.read((char*)&total, sizeof(total));
	cout << "Historial de Bebidas Vendidas en Memoria: " << endl;
	while (archivo) {
		size_t tamanio;
		archivo.read((char*)&tamanio, sizeof(tamanio));
		if (!archivo) {
			break;
		}
		char* c = new char(tamanio + 1);
		archivo.read(c, tamanio);
		c[tamanio] = '\0';
		string nombre(c);
		delete[] c;

		double precio;
		archivo.read((char*)&precio, sizeof(precio));
		if (!archivo) {
			break;
		}
		
		archivo.close();
	}
}

Historial Historial::operator+(Bebida* b) {
	agregar(b);
	return *this;
}

void Historial::agregar(Bebida* b) {
	bebidas.push_back(b);
	total_vendido += b->calcularPrecioFinal();
}

void Historial::mostrarHistorial() {
	for (int i = 0; i < (int)bebidas.size(); i++) {
		cout << "No. " << i + 1 << " Nombre: " << bebidas[i]->getNombre() << " PrecioFinal: " << bebidas[i]->calcularPrecioFinal() << endl;
	}
	cout << "Ingresos totales hasta el momento: " << endl << "L. " << total_vendido << endl;
}
