#ifndef Board_Guard
#define Board_Guard
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <ctime>
#include "BoardBuilder.h"
#include "Validations.h"
#include "Tutorial.h"
#include "Fail.h"
class BoardBuilder;

class Board {
public:
	/*
	*constructor
	*/
	Board(); 

	/*
	*prints the board
	@param sizeX
	@param sizeY
	*/
	void drawBoard( int sizeX, int sizeY);

	/*
	*makes a empty board with the sizes the user inputed
	@param sizeX
	@param sizeY
	*/
	void map_maker( int sizeX, int sizeY); 

	/*
	*obtains the dictionary from the file
	@param max_-maximum lenght that a word can have
	*/
	void obtain_dictionary(int max_);


	/*
	*get the variable prov_words
	*/
	std::vector<std::string> getProv(); 

	/*
	*get the variable number_of_letters
	*/
	int get_number_of_letters(); 

	/*
	*functions that make the warnings to the user after finished the board
	*/
	bool end2save();

	/*
	*function with the option where the program gives a list of words to the user
	*returns -1 if the program can´t find any word that could fit in the board
	*returns 0 otherwise
	@param sizeX
	@param sizeY
	@param &bb- reference to the object made in function main
	*/
	int give_words_to_user( int sizeX, int sizeY, BoardBuilder &bb);

	/*
	*function with the option where the user gives a suggestion of a word
	@param sizeX
	@param sizeY
	@param &bb- reference to the object made in function main
	*/
	int user_give_word( int sizeX, int sizeY, BoardBuilder &bb);

	/*
	*returns the vector Showed_board
	*/
	std::vector<std::vector<char >> getShowed_board();

	/*
	*put the word in the word
	@param wd-word
	@param xy-where
	@param hv-orientation
	@param BoardBuilder bb
	*/
	void put_word(std::string wd, std::string xy, std::string hv, BoardBuilder& bb);

	/*
	*generates the words to the user
	*if the program can't find any words returns -1 otherwise 0
	@param sizeX
	@param sizeY
	@param max_- max lenght a word can have to fit in the board
	*/
	int generate_words(int sizeX, int sizeY, int max_);

private:

	std::vector<std::vector<char>> Showed_board; 
	// vector 2D -> the board

	std::vector<std::string>Prov_words;
	// temporary words given to the user

	std::vector<std::string> AlphabeticWords; 
	// the dictionary

	int number_of_letters=0; 
	// represents the number of letters in the board on that moment
};
#endif
