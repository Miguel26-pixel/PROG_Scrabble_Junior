#ifndef Letter_GUARD
#define Letter_GUARD
#include <vector>
#include <string>

// saves the information abaut a letter
struct Letter{

	char letter;
	char xpos, ypos;
	bool played = false; // true if that letter has already been played
	std::vector<std::string> inWords;
	Letter(const char& letter, const char& xpos, const char& ypos) : letter(letter), xpos(xpos), ypos(ypos) {}
	Letter() : letter(' ') {}
};


// guarda se uma letra está na letterBag do jogador e qual o index dessa letra
struct auxiliar {

	bool isValid = false;
	int idx = 0;
};

#endif