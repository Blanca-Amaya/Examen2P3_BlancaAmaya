#pragma once
#include <vector>
#include "Bebida.h"
using namespace std;

class Historial {
private:
	double total_vendido;
	vector <Bebida*> bebidas;
public:
	~Historial();
	void guardarHistorial();
	void cargarHistorial();
	Historial operator+(Bebida* b);
};

