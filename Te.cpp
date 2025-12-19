#include "Te.h"

Te::Te(string nombre2, double precioBase2, int esencia_herbal2) : Bebida(nombre2, precioBase2), esencia_herbal(esencia_herbal2){
}

double Te::calcularPrecioFinal() {
	double precio = getPrecioBase();
	return precio + (esencia_herbal / 100.0) * precio;
}

int Te::getEsenciaHerbal() const {
	return esencia_herbal;
}

void Te::setEsenciaHerbal(int esencia_herbal2) {
	esencia_herbal = esencia_herbal2;
}
