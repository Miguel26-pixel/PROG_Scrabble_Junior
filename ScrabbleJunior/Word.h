#ifndef Word_GUARD
#define Word_GUARD

#include <iostream>
#include <string>
#include <vector>
#include "Letter.h"

class Word {

	std::string word;
	char column, line; // coordinates of the letter on the board
	bool isCompleted = false; // says if the word has already been completed
	char dir; // direction of the word
	std::vector<Letter> letters;

public:

	Word(const std::string& word, const char& xpos, const char& ypos, const char& dir);
	Letter validMove(); // returns the only valid move in the word if it isn't completed already
	void update_letter(int index); //updates the letter played

	//Gets:
	bool get_isCompleted();
	std::string get_word();
	int get_xcoord();
	int get_ycoord();
	char get_dir();
	std::vector<Letter> get_letters();
};

#endif