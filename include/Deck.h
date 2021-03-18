#ifndef DECK_H
#define DECK_H

#include <iostream>
#include <list>
#include "Carta.h"

class Deck
{
private:
	std::string nombre;
	std::list<Carta> main;
	std::list<Carta> side;
	Carta* commnader;
public:
	Deck();
	Deck(std::string nombre);
	~Deck();
	void addMain(std::string carta);
	void addMain(std::string carta, int cant);
	void addMain(std::list<Carta> main);
	bool isInMain(std::string);
	int incMain(std::string nombre, int cantidad);
	void addSide(std::string carta);
	void addSide(std::string carta, int cant);
	void addSide(std::list<Carta> main);
	bool isInSide(std::string);
	int incSide(std::string nombre, int cantidad);
	void printDeck();
	void setName(std::string nombre);
	std::string getName();
	std::list<Carta>::iterator getMainBegin();
	std::list<Carta>::iterator getMainEnd();
	std::list<Carta>::iterator getSideBegin();
	std::list<Carta>::iterator getSideEnd();
};

#endif  /* DECK_H */