#include "Chocolate.h"

Chocolate::Chocolate(const string nombre2, double precioBase2, int gramos_azucar2) : Bebida(nombre2, precioBase2), gramos_azucar(gramos_azucar2){
}

double Chocolate::calcularPrecioFinal() {
	double precio = getPrecioBase();
	return precio + (gramos_azucar / 100) * precio;
}
