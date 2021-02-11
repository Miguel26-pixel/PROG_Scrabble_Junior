#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Board.h"
#include "Colors.h"
#include "BoardBuilder.h"
#include "Validations.h"
using namespace std;


bool valid(vector<vector<char>> mapping, int sizeX, int sizeY, string wd) {
	// if the board it's not empty this sees if the word fits somewhere on the board
	for (int i = 0; i < sizeY; i++) { //sees every line
		for (int j = 0; j < sizeX; j++) { //sees every collumn
			string s = "";
			s = s + char('A' + i) + char('a' + j);
			if (valid_xy(wd, s, "H", sizeX, sizeY) &&
				valid_xyHV(wd, s, "H", mapping, sizeX, sizeY)) { 					//if fits with horizontal orientation
				return true;
			}
			if (valid_xy(wd, s, "V", sizeX, sizeY) &&
				valid_xyHV(wd, s, "V", mapping, sizeX, sizeY)) { 					//if fits with vertical orientation
				return true;
			}
		}
	}
	return false;
}


bool valid_word_prov(vector<string> sel, string str) {
	for (size_t i = 0; i < sel.size(); i++) {
		if (sel[i] == str) {									 					//if the string is in the vector returns true
			return true;
		}
	}
	return false;												 					//returns false otherwise
}


bool valid_word_sel(vector<string> sel, string str) {
	for (size_t i = 0; i < sel.size(); i++) {
		if (sel[i] == str) {
			return false;									    					//if the string is in the vector returns false
		}
	}
	return true;											    					//returns true otherwise
}

//sees if the word fits in the limits of the board
bool valid_xy(string wd, string xy, string hv, int sizeX, int sizeY) {
	if (hv == "H") {																//horizontal orientation
		for (size_t j = 0; j < wd.length(); j++) {
			if (xy.at(0) - 'A' < sizeY && xy.at(1) - 'a' + j < (size_t)sizeX)
				continue;
			else
				return false;
		}
	}
	else {																			//vertical orientation
		for (size_t j = 0; j < wd.length(); j++) {
			if (xy.at(0) - 'A' + j < (size_t)sizeY && xy.at(1) - 'a' < sizeX)
				continue;
			else
				return false;
		}
	}
	return true;
}

//function that returns true if the word is valid where the user wants to plce in
bool valid_xyHV(string wd, string xy, string hv, vector<vector<char>> mapping, int sizeX, int sizeY) {
	if (hv == "H")
		return valid_xyH(wd, xy, mapping, sizeX, sizeY); 							//function for vertical words
	else
		return valid_xyV(wd, xy, mapping, sizeX, sizeY); 							//function for horizontal words
}

//Function that sees if the vertical word is valid where the user wants to put it 
bool valid_xyV(string wd, string xy, vector<vector<char>> mapping, int sizeX, int sizeY) { //words with the vertical orientation
	for (size_t i = 0; i < wd.length(); i++) {
		if (mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a'] != ' ' &&					//sees if the place it's empty
			mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a'] != wd.at(i))				//sees if the char in the place it's equal to char we want to put 
			return false;															// returns false if it's different from empty or the right char
	}
	for (size_t i = 0; i < wd.length() - 1; i++) {
		if (mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a'] == wd.at(i) &&				//if there are two chars, one after another (equals to which we want to put) at the place we want to put 
			mapping[xy.at(0) - 'A' + i + 1][xy.at(1) - 'a'] == wd.at(i+1))

			return false;															//returns false if there are
	}

	//UP limit
	if (xy.at(0) != 'A') {
		if (mapping[xy.at(0) - 'A' - 1][xy.at(1) - 'a'] != ' ')						//if not sees if the place before it's empty
			return false;															//returns false if the condition before it's false
	}

	//BOTTOM limit
	if (char(xy.at(0) + wd.length() - 1) != char('A' + sizeY - 1)) {
		if (mapping[xy.at(0) - 'A' + wd.length()][xy.at(1) - 'a'] != ' ')			//if not sees if the place after it's empty
			return false;															//returns false if the condition before it's false
	}

	//LEFT limit
	if (xy.at(1) == 'a') {

		for (size_t i = 0; i < wd.length() - 1; i++) {
			if (mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a' + 1] != ' ' &&			//if there are two chars, one after another on the collumn after where the user wants to put
				mapping[xy.at(0) - 'A' + i + 1][xy.at(1) - 'a' + 1] != ' ')
				return false;														//returns false if there are
		}


		for (size_t i = 0; i < wd.length(); i++) {
			if (mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a'] == ' ' &&				//sees if any of the chars stays next to another from other word
				mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a' + 1] != ' ')
				return false;														//returns false if there is
		}
	}

	//RIGHT limit
	else if (xy.at(1) == char('a' + sizeX - 1)) {
		for (size_t i = 0; i < wd.length() - 1; i++) {

			if (mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a' - 1] != ' ' &&
				mapping[xy.at(0) - 'A' + 1 + i][xy.at(1) - 'a' - 1] != ' ')			//if there are two chars, one after another on the collumn before where the user wants to put
				return false;
		}
		for (size_t i = 0; i < wd.length(); i++) {
			if (mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a'] == ' ' &&				//sees if any of the chars stays next to another from other word
				mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a' - 1] != ' ')
				return false;														//returns false if there is
		}
	}

	//NOT IN THE LIMITS
	else {																			//sees all the same conditions when the user wants do place a words inside the limits of the board

		for (size_t i = 0; i < wd.length() - 1; i++) {

			if ((mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a' - 1] != ' ' &&
				mapping[xy.at(0) - 'A' + 1 + i][xy.at(1) - 'a' - 1] != ' ') ||      //condition of words next to the place with the same orientation
				(mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a' + 1] != ' ' &&
					mapping[xy.at(0) - 'A' + 1 + i][xy.at(1) - 'a' + 1] != ' '))
				return false;
		}
		for (size_t i = 0; i < wd.length(); i++) {
			if ((mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a'] == ' ' &&
				mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a' + 1] != ' ') ||		 	//condition of words next to the place with different orientation
				(mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a'] == ' ' &&
					mapping[xy.at(0) - 'A' + i][xy.at(1) - 'a' - 1] != ' '))
				return false;
		}
	}
	return true;													 				//returns true if any of these conditions returned false
}


//Function that sees if the horizontal word is valid where the user wants to put it
bool valid_xyH(string wd, string xy, vector<vector<char>> mapping, int sizeX, int sizeY) { //words with horizontal orientation

	for (size_t i = 0; i < wd.length(); i++) {
		if (mapping[xy.at(0) - 'A'][xy.at(1) - 'a' + i] != ' ' &&					//sees if the place it's empty
			mapping[xy.at(0) - 'A'][xy.at(1) - 'a' + i] != wd.at(i))				//sees if the char in the place it's equal to char we want to put 
			return false;															// returns false if it's different from empty or the right char
	}

	for (size_t i = 0; i < wd.length() - 1; i++) {									//if there are two chars, one after another (equals to which we want to put) at the place we want to put 
		if (mapping[xy.at(0) - 'A'][xy.at(1) - 'a' + i] == wd.at(i) &&				//sees if the word is the same 
			mapping[xy.at(0) - 'A'][xy.at(1) - 'a' + i + 1] == wd.at(i+1))
			return false;															//returns false if there are
	}

	//LEFT limit
	if (xy.at(1) != 'a') {
		if (mapping[xy.at(0) - 'A'][xy.at(1) - 'a' - 1] != ' ')						//if not sees if the place before it's empty
			return false;
	}

	//RIGHT limit
	if (char(xy.at(1) + wd.length() - 1) != char('a' + sizeX - 1)) {				//sees if the place after it's empty
		if (mapping[xy.at(0) - 'A'][xy.at(1) - 'a' + wd.length()] != ' ')
			return false;
	}

	//UP limit
	if (xy.at(0) == 'A') {
		for (size_t i = 0; i < wd.length() - 1; i++) {
			if (mapping[xy.at(0) - 'A' + 1][xy.at(1) - 'a' + i] != ' ' &&			//sees if there is a word under it
				mapping[xy.at(0) - 'A' + 1][xy.at(1) - 'a' + 1 + i] != ' ')
				return false;
		}
		for (size_t i = 0; i < wd.length(); i++) {
			if (mapping[xy.at(0) - 'A'][xy.at(1) - 'a' + i] == ' ' &&
				mapping[xy.at(0) - 'A' + 1][xy.at(1) - 'a' + i] != ' ')				//sees if the word could be adjacent to another
				return false;
		}
	}

	//BOTTOM limit
	else if (xy.at(0) == char('A' + sizeY - 1)) {
		for (size_t i = 0; i < wd.length() - 1; i++) {
			if (mapping[xy.at(0) - 'A' - 1][xy.at(1) - 'a' + i] != ' ' &&			//sees if there is a word on it
				mapping[xy.at(0) - 'A' - 1][xy.at(1) - 'a' + 1 + i] != ' ')
				return false;
		}
		for (size_t i = 0; i < wd.length(); i++) {
			if (mapping[xy.at(0) - 'A'][xy.at(1) - 'a' + i] == ' ' &&
				mapping[xy.at(0) - 'A' - 1][xy.at(1) - 'a' + i] != ' ')				//sees if the word could be adjacent to another
				return false;
		}
	}

	//NOT IN THE LIMITS																//sees all the same conditions when the user wants do place a words inside the limits of the board
	else {
		for (size_t i = 0; i < wd.length() - 1; i++) {
			if ((mapping[xy.at(0) - 'A' - 1][xy.at(1) - 'a' + i] != ' ' &&
				mapping[xy.at(0) - 'A' - 1][xy.at(1) - 'a' + 1 + i] != ' ') ||
				(mapping[xy.at(0) - 'A' + 1][xy.at(1) - 'a' + i] != ' ' && 			//condition of words next to the place with the same orientation
					mapping[xy.at(0) - 'A' + 1][xy.at(1) - 'a' + 1 + i] != ' '))
				return false;
		}
		for (size_t i = 0; i < wd.length(); i++) {
			if ((mapping[xy.at(0) - 'A'][xy.at(1) - 'a' + i] == ' ' &&
				mapping[xy.at(0) - 'A' - 1][xy.at(1) - 'a' + i] != ' ') ||
				(mapping[xy.at(0) - 'A'][xy.at(1) - 'a' + i] == ' ' &&				//condition of words next to the place with different orientation
					mapping[xy.at(0) - 'A' + 1][xy.at(1) - 'a' + i] != ' '))
				return false;
		}
	}
	return true;
}

//function with the purpose of not reapeting always the same if condition
bool valid_where_word(string wd, string xy, string hv, vector<vector<char>> mapping, int sizeX, int sizeY, vector<string> prov, int what) {
	if (what == 1) {
		if (valid_xy(wd, xy, hv, sizeX, sizeY) && valid_xyHV(wd, xy, hv, mapping, sizeX, sizeY))
			return true;
	}																				//easier than using always the same
	else {
		if (valid_xy(wd, xy, hv, sizeX, sizeY) && valid_word_prov(prov, wd))
			return true;
	}
	return false;
}

// Function that uses binary search to find a word in the vector, if it can't find the word, returns false
bool Is_In_Search(vector<string> vector, string word) {
	int l = 0, h = (int)vector.size() - 1;
	
	while (l <= h) {
		int m = (l + h) / 2;
		if (vector[m] == word) return true;
		if (vector[m] > word)
			h = m - 1;
		else
			l = m + 1;
	}
	
	return false;
}