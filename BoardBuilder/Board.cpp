#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Clear_Wait.h"
#include "Board.h"
#include "Colors.h"
#include "BoardBuilder.h"
#include "Fail.h"
#include "Validations.h"
#include "Prints.h"
using namespace std;

//prints the board
void Board::drawBoard( int sizeX,  int sizeY) {

	for (int i = 0; i <= sizeY; i++) {

		if (i > 0) {
			for (int j = 0; j <= sizeX; j++) {
				if (j > 0) {
					setconsolecolor(BLACK, LIGHTGRAY);
					cout << Showed_board[i - 1][j - 1] << ' ';
				}
				else {
					setconsolecolor(WHITE, BLACK);
					cout << (char)(i + 64) << ' ';
				}
			}
		}
		else {
			cout << "  ";
			for (int j = 0; j < sizeX; j++) { cout << (char)(j + 97) << ' '; }
		}
		setconsolecolor(WHITE, BLACK);
		cout << endl;
	}
	setconsolecolor(WHITE, BLACK);
}


void Board::map_maker( int sizeX,  int sizeY) {
	for (int y = 0; y < sizeY; y++) {
		vector<char> vector;
		for (int x = 0; x < sizeX; x++) {													//makes a empty 2D vector
			vector.push_back(' ');
		}
		Showed_board.push_back(vector);
	}
}

//makes the dictionary
void Board::obtain_dictionary(int max_) {
	number_of_letters = 0;
	ifstream f_in;
	f_in.open("WORDS.TXT");																	//original dictionary
	string st;
	while (getline(f_in, st)) {
		if (st.length() > (size_t)1 && st.length() <= (size_t)max_)
			AlphabeticWords.push_back(st);
	}
}


int Board::generate_words( int sizeX,  int sizeY,  int max_) {
	int counter = 0;																		//counter of times searching for one word
	Prov_words.clear();																		// clears this vector
	int random_index = 0;
	for (int i = 0; i < 10; i++) {
		int counter = 0;
		random_index = rand() % AlphabeticWords.size();										// manange a random number for index
		while (valid_word_prov(Prov_words, AlphabeticWords[random_index])	|| 				// the word must not be already in the list 
		!valid(Showed_board, sizeX, sizeY,AlphabeticWords[random_index])&&counter<10000) {  //search only 10000 times for word

			random_index = rand() % Board::AlphabeticWords.size();
			counter++;
		}
		if (counter == 10000) {
			if (Prov_words.size() == 0) {													// sees if the program found any word
				cout << CANT_FIND << endl;
				return -1;
			}
			else
				break;
		}
		else{
			cout << i + 1 << "-" << AlphabeticWords[random_index] << endl;					//printing the list to the user
			Prov_words.push_back(AlphabeticWords[random_index]);							// creating the list
		}
	}
	return 0;
}


Board::Board() {}


void Board::put_word(string wd, string xy, string hv,BoardBuilder &bb) {
	if (hv == "H") {																		//horizontal
		for (size_t j = 0; j < wd.length(); j++) {
			if (Showed_board[xy.at(0) - 'A'][xy.at(1) - 'a' + j] == ' ')					//sees if is a new letter on the board
				number_of_letters++;
			Showed_board[xy.at(0) - 'A'][xy.at(1) - 'a' + j] = wd.at(j);					//change the board
		}
	}
	else {																					//vertical
		for (size_t j = 0; j < wd.length(); j++) {
			if (Showed_board[xy.at(0) - 'A'+j][xy.at(1) - 'a'] == ' ')						//sees if is a new letter on the board
				number_of_letters++;
			Showed_board[xy.at(0) - 'A' + j][xy.at(1) - 'a'] = wd.at(j);					//change the board
		}
	}
	bb.write_out(3, 0, 0, wd, xy,hv, "");

}

vector<string> Board::getProv() {return Board::Prov_words;}


int Board::get_number_of_letters() { return Board::number_of_letters;}


bool Board::end2save() {
	string s = "";
	if (get_number_of_letters() < 14) {														//impossible board
		clean();
		cout << WANT_TO_STOP << endl;
		cout << IMPOSSIBLE_BOARD << endl;
		cin >> s;
		s=fail_answer(s);
		if (s == "yes")
			return false;
	}
	else if (get_number_of_letters() < 21) {												//only two players board
		clean();
		cout << WANT_TO_STOP << endl;
		cout << TWO_PLAYERS << endl;
		cin >> s;
		s=fail_answer(s);
		if (s == "yes")
			return false;
	}
	else if (get_number_of_letters() < 28) {												//only two or three players board
		clean();
		cout << WANT_TO_STOP << endl;
		cout << THREE_PLAYERS << endl;
		cin >> s;
		s=fail_answer(s);
		if (s == "yes")
			return false;
	}
	else {
		clean(); 
		cout << WANT_TO_STOP << endl;
		cin >> s;
		s=fail_answer(s);
		if (s == "yes")
			return false;
	}
	return true;
}


int Board::user_give_word(int sizeX, int sizeY, BoardBuilder &bb) {
	string word="" , cross="", dir="",answer="";
	clean();
	drawBoard(sizeX, sizeY);

	while (!Is_In_Search(AlphabeticWords, word)) {											//check if the word is valid
		cout << GIVE_WORDS << endl;
		cin >> word;
		word=fail_word(word);
	}

	cout << WHERE_TO_PUT << endl;
	cin >> cross;
	cross=fail_place_board(cross,sizeX,sizeY);													//verification

	cout << DIRECTION << endl;
	cin >> dir;																				//verification
	dir=fail_orientation(dir);

	while (!valid_where_word(word, cross, dir,Showed_board, sizeX, sizeY, Prov_words,1)||
		!Is_In_Search(AlphabeticWords,word)) {												//validation of the spot the user chose
		clean();
		cout << DONT_FIT << endl;
		cout << MAYBE_NO_ONE << endl;
		cout << "ANSWER(yes or no):";
		cin >> answer;
		answer=fail_answer(answer);
		if (answer == "yes")
			user_give_word(sizeX, sizeY, bb);
		else
			return -1;
	}
	put_word(word, cross, dir, bb);															//put the word in the board
	clean();
	drawBoard(sizeX, sizeY);																//print the board

	return 0;
}


int Board::give_words_to_user(int sizeX, int sizeY, BoardBuilder &bb) {
	string str, xy, hv;
	int index_choice = 0;
	cout << REMEMBER_TEN << endl;
	if (Board::generate_words(sizeX, sizeY, max(sizeX, sizeY)) == -1) {
		return -1;
	}
	cin >> index_choice;
	index_choice=fail_index_choice(index_choice, Prov_words.size());										//verification
	clean();
	drawBoard(sizeX, sizeY);
	cout << Prov_words[index_choice - 1] << endl << endl;
	cout << PLACE_WORD << endl;
	cin >> xy;
	xy=fail_place_board(xy,sizeX,sizeY);
	cout << DIRECTION << endl;
	cin >> hv;
	hv=fail_orientation(hv);
	while (!valid_where_word(Board::Prov_words[index_choice-1], xy, hv, Showed_board, sizeX, sizeY, Prov_words, 1)) {
		cout << CHOOSE_AGAIN << endl;
		for (size_t i = 0; i < Board::Prov_words.size(); i++)
			cout << i + 1 << "-" << Board::Prov_words[i] << endl;
		cin >> index_choice;
		index_choice=fail_index_choice(index_choice, Prov_words.size());
		cout << PLACE_WORD << endl;
		cin >> xy;
		xy=fail_place_board(xy,sizeX,sizeY);
		cout << DIRECTION << endl;
		cin >> hv;
		hv=fail_orientation(hv);

	}
	put_word(Prov_words[index_choice - 1], xy, hv, bb);
	clean();
	drawBoard(sizeX, sizeY);

	return 0;
}


vector<vector<char>> Board::getShowed_board() {
	return Showed_board;
}