#pragma once
#include "Bebida.h"

class Chocolate : public Bebida {
private:
	int gramos_azucar;
public:
	Chocolate(const string nombre2, double precioBase2, int gramos_azucar2);
	double calcularPrecioFinal() override;

	// getters
	int getGramosAzucar() const;

	// setters
	void setGramosAzucar(int gramos_azucar2);
};

