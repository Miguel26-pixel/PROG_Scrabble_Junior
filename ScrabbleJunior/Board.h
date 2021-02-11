#ifndef Board_GUARD
#define Board_GUARD

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include "Word.h"
#include "Letter.h"

class Board {

	std::vector<std::vector<Letter>> board;
	std::string boardFile;
	std::ifstream file;
	int width, height;
	std::vector<Word> wordList;
	std::vector<char> letterPool;
	int nWords = 0;

	void get_board_name();  // asks for the board file name or the path to the file with the board

public:

	void readBoard(); // opens and reads the board file and saves the words in the wordList and letters in letterPool
	void makeBoard(); // adds the words to the board vector; creates a list with all the letters on the board
	void drawBoard(); // displays the board on the screen
	int completed_words(); // counts the number of completed words
	std::vector<Letter> available_moves(); // creates a vector with all the valid moves
	void update_board(int x, int y); // changes the letter on the board to played (meaning that letter has been played) 
	bool check_endGame(); // return true if all the words have been completed

	//Gets
	std::vector<std::vector<Letter>> get_board();
	std::vector<char> get_letterPool();
};

#endif