#ifndef CONVERSOR_H
#define CONVERSOR_H

#include "Deck.h"

Deck toDeck(std::string ext, std::string archivo);
void deckTo(std::string ext, Deck deck, std::string archivo);

Deck dck2Deck(std::string archivo);
void deck2cod(Deck deck, std::string archivo);

// To extract info from strings

std::string getBeforeFirst(std::string s, std::string del);
std::string getAfterFirst(std::string s, std::string del);
std::string getBetween(std::string s, std::string del1, std::string del2);

#endif /* CONVERSOR_H */