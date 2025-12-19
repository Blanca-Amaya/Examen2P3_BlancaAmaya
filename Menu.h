#pragma once
#include <vector>
//#include "Cafe.h"
//#include "Te.h"
//#include "Chocolate.h"
#include "Bebida.h"
#include <iostream>
using namespace std;

class Menu {
private:
	vector <Bebida*> menu;
public:
	~Menu();
	void eliminar(int indice);
	void verMenu();
	void vaciarMenu();
	void guardarMenu();
	void cargarMenu();

	Menu operator+(Bebida* b);
	void agregar(Bebida* b);
	int tam();
	Bebida* getBebida(int b2);
};

