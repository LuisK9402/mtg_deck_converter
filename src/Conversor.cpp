#include "Conversor.h"
#include "Carta.h"
#include <iostream>
#include <fstream>

using namespace std;

Deck toDeck(string ext, string archivo){
	Deck newDeck;
	if (ext == "dck") return dck2Deck(archivo);
	return newDeck;
}

void deckTo(string ext, Deck deck, string archivo){
	if (ext == "cod") deck2cod(deck,archivo);
}

Deck dck2Deck(string archivo){
	Deck newDeck;
	string nombre_carta;
	int cantidad_carta;
	cout << "Convirtiendo " << archivo << " de dck a Deck" << endl;

	// Create a text string, which is used to output the text file
	string linea;

	// Read from the text file
	ifstream MyReadFile(archivo);

	// Reads the name
	getline (MyReadFile, linea);
	getline (MyReadFile, linea);
	newDeck.setName(getAfterFirst(linea,"="));

	// Checks if deck has commander
	getline (MyReadFile, linea);
	if(linea == "[Commander]"){
		getline (MyReadFile, linea);
		nombre_carta = getBetween(linea," ","|");
		newDeck.addSide(nombre_carta);
	}

	getline (MyReadFile, linea);
	if(linea == "[Main]"){
		while (getline (MyReadFile, linea)) {
			if(linea == "[Side]") break;
			cantidad_carta =  stoi(getBeforeFirst(linea," "));
			nombre_carta = getBetween(linea," ","|");
			newDeck.addMain(nombre_carta, cantidad_carta);
		}		
	}

	if(linea == "[Side]"){
		while (getline (MyReadFile, linea)) {
			cantidad_carta =  stoi(getBeforeFirst(linea," "));
			nombre_carta = getBetween(linea," ","|");
			newDeck.addSide(nombre_carta, cantidad_carta);
		}		
	}

	// Close the file
	MyReadFile.close();

	return newDeck;
}

void deck2cod(Deck deck, string archivo){
	// Create a text string, which is used to output the text file
	string linea;
	// Iterator
	std::list<Carta>::iterator it;

	// Read from the text file
	ofstream MyReadFile(archivo);

	MyReadFile << "<?xml version=\"1.0\" encoding=\"UTF-8\"?>" << endl;
	MyReadFile << "<cockatrice_deck version=\"1\">" << endl;
	MyReadFile << "\t<deckname>" << deck.getName() << "</deckname>" <<endl;
	MyReadFile << "\t<comments></comments>" <<endl;
	MyReadFile << "\t<zone name=\"main\">" <<endl;

	for(it = deck.getMainBegin(); it != deck.getMainEnd(); ++it){
		std::cout << "  " << it->getCantidad() << "  " << it->getName() << std::endl;
		MyReadFile << "\t\t<card number=\"" << it->getCantidad() << "\"  name=\"" << it->getName() << "\"/>" << endl;
	}
	
	MyReadFile << "\t</zone>" <<endl;
	MyReadFile << "\t<zone name=\"side\">" <<endl;

	for(it = deck.getSideBegin(); it != deck.getSideEnd(); ++it){
		MyReadFile << "\t\t<card number=\"" << it->getCantidad() << "\"  name=\"" << it->getName() << "\"/>" << endl;
	}

	MyReadFile << "\t</zone>" <<endl;
	MyReadFile << "</cockatrice_deck>";

	MyReadFile.close();
}

std::string getBeforeFirst(std::string s, std::string del){
	std::string delimiter = del;

	size_t pos = 0;
	std::string token;
	pos = s.find(delimiter);
	token = s.substr(0, pos);
	return token;
}

std::string getAfterFirst(std::string s, std::string del){
	std::string delimiter = del;

	size_t pos = 0;
	std::string token;
	pos = s.find(delimiter);
	s.erase(0, pos + delimiter.length());
	return s;
}

std::string getBetween(std::string s, std::string del1, std::string del2){
	string nuevaS;
	nuevaS = getAfterFirst(s,del1);
	nuevaS = getBeforeFirst(nuevaS,del2);
	return nuevaS;
}