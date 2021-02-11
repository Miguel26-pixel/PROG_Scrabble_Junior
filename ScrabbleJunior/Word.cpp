#include "Word.h"
#include <iostream>
#include "Letter.h"

using namespace std;

Word::Word(const string& word, const char& column, const char& line, const char& dir) {
	
	this->word = word;
	this->column =	column;
	this->line = line;
	this->dir = dir;

	// converts the string word to a vector of Letters
	for (size_t i = 0; i < this->word.length(); i++) {
		if (this->dir == 'H') {
			Letter letter(this->word.at(i), this->column + i, this->line);
			this->letters.push_back(letter);
		}
		else if (this->dir == 'V') {
			Letter letter(this->word.at(i), this->column, this->line + i);
			this->letters.push_back(letter);
		}
	}
}

string Word::get_word() {
	return word;
}

int Word::get_xcoord() {
	return column - 'a';
}

int Word::get_ycoord() {
	return line - 'A';
}

char Word::get_dir() {
	return dir;
}

vector<Letter> Word::get_letters() {
	return letters;
}

Letter Word::validMove() {

	// return the only valid in the word
	for (size_t i = 0; i < word.length(); i++) {
		if (!letters[i].played) {
			return letters[i];
		}
	}
}

bool Word::get_isCompleted() {
	
	// return if a word is completed on the board. If not checks if it hasn't been completed and then returns if it completed or not
	if (isCompleted) return isCompleted;

	// checks if the has been completed
	for (size_t i = 0; i < letters.size(); i++) {
		if (!letters[i].played) {
			isCompleted = false;
			break;
		}
		isCompleted = true;
	}
	return isCompleted;
}

void Word::update_letter(int index) {
	// updates the letter after a move 
	letters[index].played = true;
}