#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Board.h"
#include "BoardBuilder.h"
#include "Tutorial.h"
using namespace std;

void BoardBuilder::write_out(int what, int sizeX, int sizeY, string wd, string xy, string hv,string st) {
	ofstream f_out;
	if (what == 2) {
																							//sizes of the board
		lines = sizeY;
		collumns = sizeX;
	}
	else if (what == 3) {
																							//saving the values to make the txt file
		wd = lower_to_upper(wd);															//transforms the lower letter in upper letters
		words_of_board.push_back(wd);
		positions_of_board.push_back(xy);
		direction_of_words.push_back(hv);
	}
	else {
		f_out.open(st);																		//opens the file that the user named
		f_out << lines << " x " << collumns << endl;
		for (size_t i = 0; i < words_of_board.size(); i++) {								//place on the board,direction,word
			f_out << positions_of_board[i] << " " << direction_of_words[i] << " " << words_of_board[i] << endl; 
		}
		f_out.close();																		//closes the file
	}
}

BoardBuilder::BoardBuilder(){}


string BoardBuilder::lower_to_upper(string st) {
	string s = "";
	for (size_t i = 0; i < st.length(); i++) {
		s = s + char(toupper(st.at(i)));													//transformation
	}
	return s;
}