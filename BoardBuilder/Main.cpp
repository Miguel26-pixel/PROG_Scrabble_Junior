#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cstring>
#include <random>
#include <fstream>
#include <sstream>
#include "Board.h"
#include <windows.h>
#include <ctime>
#include <algorithm>
#include "Clear_Wait.h"
#include "BoardBuilder.h"
#include "Fail.h"
#include <cstdlib>
#include "Tutorial.h"
#include "Validations.h"
using namespace std;
int main() {
	clock_t start = clock();
	srand(start);																	//getting the random seed

	while (true) {
		BoardBuilder bb = BoardBuilder();
		int sizeX, sizeY;
		string answer;
		vector<string> vec;
		string str, xy, hv;
		int index_choice = 0;
		Board p = Board();

		expose();																		//tutorial

		cout << START << endl;
		cout << LINES;
		cin >> sizeY;																	//number of lines of the board
		sizeY = fail_size(sizeY);
		cout << endl << COLLUMNS;
		cin >> sizeX;
		sizeX=fail_size(sizeX);																//number of colllums of the board
		p.obtain_dictionary(max(sizeX, sizeY));
		bb.write_out(2, sizeX, sizeY, " ", " ", " ", " ");
		clean();
		p.map_maker(sizeX, sizeY);														//make the empty board
		while (true) {
			clean();
			cout << SUGGESTION;															//sees what the user wants to do
			cin >> answer;
			answer=fail_answer(answer);
			clean();
			p.drawBoard(sizeX, sizeY);
			if (answer == "yes") {
				if (p.user_give_word(sizeX, sizeY, bb) == -1)							//option where the user gives the word
					break;
			}
			else {
				if (p.give_words_to_user(sizeX, sizeY, bb) == -1)						//option where  the program gives the words
					break;
			}
			cout << MORE_WORDS << endl;
			cin.clear();
			cin >> answer;
			answer=fail_answer(answer);
			if (answer == "yes")
				continue;
			else {
				if (p.end2save() == false)
					break;
				clean();
			}
		}
		cout << SAVE_BOARD << endl;														//sees if the user wnats to save the board
		cin.clear();
		cin >> answer;
		answer=fail_answer(answer);
		if (answer == "yes") {
			cin.clear();
			cout << NAME_BOARD << endl;
			cout << "Name:";
			cin >> answer;																//Name of the file
			answer = answer + ".txt";
			bb.write_out(4, 0, 0, " ", " ", " ", answer);								//saves the board
		}

		cout << PLAY_AGAIN << endl;
		cin.clear();
		cin >> answer;																	//gives the possiblity to make another board
		answer=fail_answer(answer);
		if (answer == "no")
			return 0;
		else
			clean();
			continue;

	}
}
