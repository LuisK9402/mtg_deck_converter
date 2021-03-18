#include "Carta.h"

Carta::Carta(std::string nombre, int cantidad)
{
	this->nombre = nombre;
	this->cantidad = cantidad;
}

Carta::Carta(std::string nombre)
{
	this->nombre = nombre;
}

int Carta::inc(){
	this->cantidad = this->cantidad + 1;
	return this->cantidad;
}

int Carta::inc(int cant){
	this->cantidad = this->cantidad + cant;
	return this->cantidad;
}

int Carta::dec(){
	if(this->cantidad>0){
		this->cantidad = this->cantidad - 1;
	}
	return this->cantidad;
}

int Carta::dec(int cant){
	if(cant>this->cantidad){
		this->cantidad = 0;
	}
	else{
		this->cantidad = this->cantidad - cant;
	}
	return this->cantidad;
}

std::string Carta::getName(){
	return this->nombre;
}

int Carta::getCantidad(){
	return this->cantidad;
}

Carta::~Carta()
{
}