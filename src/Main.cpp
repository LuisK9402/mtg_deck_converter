#include "Deck.h"
#include "Carta.h"
#include "Conversor.h"

using namespace std;

string getExt(string s);

int main(int argc, char **argv){
	if(argc!=3){
		printf("ERROR: Expected 2 arguments, got %d. Indicate origin file and destination file",argc-1);
	}
	else{

		string input_file = argv[1];
		string output_file = argv[2];

		string in_extension = getExt(input_file);
		string out_extension = getExt(output_file);

		Deck newDeck = toDeck(in_extension, input_file);
		newDeck.printDeck();

		deckTo(out_extension, newDeck, output_file);
		// Deck mydeck("Dragon Satanico de Judas");
		// mydeck.addMain("Kuriboh");
		// mydeck.addMain("Kuriboh");
		// mydeck.addMain("Kuriboh");
		// mydeck.addMain("Summoned Skull");
		// mydeck.addMain("Summoned Skull");
		// mydeck.addMain("Summoned Skull");
		// mydeck.addMain("Summoned Skull");
		// mydeck.addMain("Dark Magician");
		// mydeck.addMain("Celtic Guardian",7);
		// mydeck.addMain("Dark Magician",3);
		// mydeck.addMain("Summoned Skull");
		// mydeck.printDeck();
	}
}

string getExt(string s){
	std::string delimiter = ".";

	size_t pos = 0;
	std::string token;
	while ((pos = s.find(delimiter)) != std::string::npos) {
		token = s.substr(0, pos);
		s.erase(0, pos + delimiter.length());
	}
	return s;
}