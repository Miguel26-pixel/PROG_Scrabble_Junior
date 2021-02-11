#ifndef Validation_Guard
#define Validation_Guard
#include "Board.h"
#include "BoardBuilder.h"

	/*
	*sees if the the word fits somewhere, returns true if does
	@param mapping
	@param sizeX
	@param sizeY
	@param wd
	*/
	bool valid(std::vector<std::vector<char>> mapping, int sizeX, int sizeY, std::string wd);

	/*
	*if the string is in the vector returns true
	@param sel-vector
	@param str-string
	*/
	bool valid_word_prov(std::vector<std::string> sel, std::string str); 

	/*
	*if the string is in the vector returns false
	@param sel - vector
	@param str - string
	*/
	bool valid_word_sel(std::vector<std::string> sel, std::string str); 

	/*
	*returns true if the word will fit in the limits of the board
	@param wd-word
	@param hv-orientation
	@param sizeX
	@param sizeY
	*/
	bool valid_xy(std::string wd, std::string xy, std::string hv, int sizeX,  int sizeY);

	/*
	*returns true if the word intersects correctly with the rest of the words that ar already in the board
	@param wd-word
	@param hv-orientation
	@param sizeX
	@param sizeY
	@param mapping- board
	*/
	bool valid_xyHV(std::string wd, std::string xy, std::string hv, std::vector<std::vector<char>> mapping,  int sizeX,  int sizeY);
	
	/*
	*returns true if the word intersectcs correctly (horizontal oreintation)
	@param wd-word
	@param sizeX
	@param sizeY
	@param mapping- board
	*/
	bool valid_xyH(std::string wd, std::string xy, std::vector<std::vector<char>> mapping, int sizeX, int sizeY);

	/*
	*returns true if the word intersectcs correctly (vertical oreintation)
	@param wd-word
	@param sizeX
	@param sizeY
	@param mapping- board
	*/
	bool valid_xyV(std::string wd, std::string xy, std::vector<std::vector<char>> mapping, int sizeX, int sizeY);

	/*
	*function with the purpose of not reapeting always the same if condition
	*/
	bool valid_where_word(std::string wd, std::string xy, std::string hv, std::vector<std::vector<char>> mapping, int sizeX,  int sizeY, std::vector<std::string> prov,int what);

	/*
	*Function that uses binary search to find a word in the vector, if it can't find the word, returns false
	@param vector
	@param word
	*/
	bool Is_In_Search(std::vector<std::string> vector, std::string word);

#endif