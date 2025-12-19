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
	// guarda únicamente el NOMBRE y el PRECIO FINAL de CADA BEBIDA DEL VECTOR en el ARCHIVO BINARIO
	void guardarHistorial(); 

	void cargarHistorial();

	// sobrecarga
	Historial operator+(Bebida* b);
};

