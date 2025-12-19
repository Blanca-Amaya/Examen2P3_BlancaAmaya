#pragma once
#include "Bebida.h"
using namespace std;

class Te : public Bebida{
private:
	int esencia_herbal;
public:
	Te(string nombre2, double precioBase2, int esencia_herbal2);
	double calcularPrecioFinal() override;

	// getters
	int getEsenciaHerbal() const;

	//setters
	void setEsenciaHerbal(int esencia_herbal2);
};

