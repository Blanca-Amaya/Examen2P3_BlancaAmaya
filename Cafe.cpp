#include "Cafe.h"

Cafe::Cafe(const string nombre2, double precioBase2, int gramos_cafeina2) : Bebida(nombre2, precioBase2), gramos_cafeina(gramos_cafeina2) {
}

Cafe::~Cafe() {

}

double Cafe::calcularPrecioFinal() {
	double precio = getPrecioBase();
	return precio + (gramos_cafeina / 100.0) * precio;
}

int Cafe::getGramosCafeina() const {
	return gramos_cafeina;
}

void Cafe::setGramosCafeina(int gramos2) {
	gramos_cafeina = gramos2;
}

