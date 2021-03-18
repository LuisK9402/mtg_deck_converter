#include "Deck.h"

using namespace std;

Deck::Deck()
{
	std::cout << "Nuevo deck creado" << std::endl;
}

Deck::Deck(std::string nombre)
{
	std::cout << "Nuevo deck creado: " << nombre << std::endl;
}

bool Deck::isInMain(std::string nombre){
	std::list<Carta>::iterator it;
	for(it = this->main.begin(); it != this->main.end(); ++it){
		if(it->getName()==nombre){
			return true;
		}
	}
	return false;
}

void Deck::addMain(std::string carta){
	if (isInMain(carta))
	{
		incMain(carta,1);
	}
	else{
		Carta nuevaCarta(carta,1);
		main.push_back(nuevaCarta);
	}
}

void Deck::addMain(std::string carta, int cant){
	if (isInMain(carta))
	{
		incMain(carta,cant);
	}
	else{
		Carta nuevaCarta(carta,cant);
		main.push_back(nuevaCarta);
	}
}

int Deck::incMain(std::string nombre, int cantidad){
	std::list<Carta>::iterator it;
	for(it = this->main.begin(); it != this->main.end(); ++it){
		if(it->getName()==nombre){
			return it->inc(cantidad);
		}
	}
	return 0;
}

bool Deck::isInSide(std::string nombre){
	std::list<Carta>::iterator it;
	for(it = this->side.begin(); it != this->side.end(); ++it){
		if(it->getName()==nombre){
			return true;
		}
	}
	return false;
}

void Deck::addSide(std::string carta){
	if (isInSide(carta))
	{
		incSide(carta,1);
	}
	else{
		Carta nuevaCarta(carta,1);
		side.push_back(nuevaCarta);
	}
}

void Deck::addSide(std::string carta, int cant){
	if (isInSide(carta))
	{
		incSide(carta,cant);
	}
	else{
		Carta nuevaCarta(carta,cant);
		side.push_back(nuevaCarta);
	}
}

int Deck::incSide(std::string nombre, int cantidad){
	std::list<Carta>::iterator it;
	for(it = this->side.begin(); it != this->side.end(); ++it){
		if(it->getName()==nombre){
			return it->inc(cantidad);
		}
	}
	return 0;
}

void Deck::printDeck(){
	cout << "Nombre: " << this->nombre << endl;
	cout << "Main Deck:" << endl;
	std::list<Carta>::iterator it;
	for(it = this->main.begin(); it != this->main.end(); ++it){
		std::cout << "  " << it->getCantidad() << "  " << it->getName() << std::endl;
	}
	cout << "Side Deck:" << endl;
	for(it = this->side.begin(); it != this->side.end(); ++it){
		std::cout << "  " << it->getCantidad() << "  " << it->getName() << std::endl;
	}
}
	
void Deck::setName(string nombre){
	this->nombre = nombre;
}

string Deck::getName(){
	return this->nombre;
}

std::list<Carta>::iterator Deck::getMainBegin(){
	return this->main.begin();
}

std::list<Carta>::iterator Deck::getMainEnd(){
	return this->main.end();
}

std::list<Carta>::iterator Deck::getSideBegin(){
	return this->side.begin();
}

std::list<Carta>::iterator Deck::getSideEnd(){
	return this->side.end();
}

Deck::~Deck()
{
}