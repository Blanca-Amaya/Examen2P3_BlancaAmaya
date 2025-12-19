#pragma once
#include <string>
using namespace std;

class Bebida {
private:
	string nombre;
	double precioBase;
public:
	Bebida(const string nombre2, double precioBase2);
	virtual double calcularPrecioFinal();
	
	// getters 
	string getNombre() const;
	double getPrecioBase() const;
	
	// setters
	void setNombre(string nombre2);
	void setPrecioBase(double precio2);
};

