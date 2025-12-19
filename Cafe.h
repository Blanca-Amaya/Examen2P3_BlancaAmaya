#pragma once
#include "Bebida.h"
using namespace std;

class Cafe : public Bebida{
private:
	int gramos_cafeina;
public:
	Cafe(const string nombre2, double precioBase2, int gramos_cafeina2);
	double calcularPrecioFinal() override;

	// getters
	int getGramosCafeina() const;
	
	// setters
	void setGramosCafeina(int gramos2);
};

