#ifndef CARTA_H
#define CARTA_H

#include <iostream>

class Carta
{
private:
	std::string nombre;
	int cantidad;
public:
	Carta(std::string nombre, int cantidad);
	Carta(std::string nombre);
	int inc();
	int inc(int cant);
	int dec();
	int dec(int cant);
	std::string getName();
	int getCantidad();
	~Carta();
};

#endif /* CARTA_H */