#include "Bebida.h"

Bebida::Bebida(const string nombre2, double precioBase2) : nombre(nombre2), precioBase(precioBase2) {}

double Bebida::calcularPrecioFinal() {
	return 0.0;
}

Bebida::~Bebida() {

}

string Bebida::getNombre() const {
	return nombre;
}

double Bebida::getPrecioBase() const {
	return precioBase;
}

void Bebida::setNombre(string nombre2) {
	nombre = nombre2;
}

void Bebida::setPrecioBase(double precio2) {
	precioBase = precio2;
}
