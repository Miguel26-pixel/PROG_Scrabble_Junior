#include <iostream>
#include <string>
#include <vector>
#include <map>
#include "Board.h"
#include "Colors.h"
#include "Clear_Wait.h"
#include "BoardBuilder.h"
#include "Validations.h"
#include "Tutorial.h"
#include <time.h>
#include "Fail.h"
#include "Prints.h"
using namespace std;

//shows the beginning of the program asking if the user wants to see the tutorial
void expose() {
	setconsolecolor(YELLOW, BLACK);
	cout << WELCOME << endl << endl << endl;
	setconsolecolor(WHITE, BLACK);
	cout << FIRST_OF_ALL << endl << endl;
	cout << NEED_RULES << endl;
	cout << NEED_HELP << endl;
	string answer;
	cout << ANSWER_TUTORIAL;
	cin >> answer;
	fail_answer(answer);
	if (answer == "yes") {
		clean();
		explain_word();
		explain_board_intersections();
	}
	else
		clean();

}

//shows the first lesson , about what the user is going to do
void explain_word() {
	Board b;
	string answer;

	cout << TO_START;

	setconsolecolor(YELLOW, BLACK);
	cout << WHAT_TO_DO << endl;
	setconsolecolor(WHITE, BLACK);
	cout << endl;

	cout << WORK << endl << endl;
	cout << AT_LEAST << endl;
	cout << TEN_RANDOM << endl;

	b.map_maker(7,7);																//makes a example board
	b.obtain_dictionary(7);															//obtains the dictionary to make the board
	b.generate_words(7, 7, 7);														//generates a example a list words

	cout << EXTREMELY << endl;
	wait();
	cout << UNDERSTAND << endl;
	cin >> answer;
	answer=fail_answer(answer);
	if (answer == "yes") {
		cout << TO_THE_NEXT_LESSON << endl;
		clean();
	}
	else {
		cout << NOP << endl;
		wait();
		clean();
		explain_word();
	}

 }


//second lesson , we try to explain how intersections can exist
void explain_board_intersections() {
	Board bo = Board();
	BoardBuilder bob;
	string answer;

	setconsolecolor(YELLOW, BLACK);
	cout << SECOND_LESSON;
	setconsolecolor(WHITE, BLACK);

	cout << INTERSECTIONS << endl << endl;
	cout << INTERSECT_BUT;

	setconsolecolor(YELLOW, BLACK);
	cout << ARE_RULES << endl<< endl;
	setconsolecolor(WHITE, BLACK);

	cout << INTERSECT_RULE << endl;
	wait();

	bo.map_maker(7, 7);																// makes a example board
	bo.put_word("mother", "Aa", "H", bob);											//put a word
	bo.put_word("master", "Aa", "V", bob);											// make a good intersection
	bo.drawBoard(7, 7);																// prints that board

	cout << UNDERSTAND << endl;
	cout << "ANSWER:";
	cin >> answer;
	answer=fail_answer(answer);
	if (answer == "yes") {
		cout << NICE << endl;
		clean();
	}
	else {
		cout << NOP << endl;														// if the user say that he/she didin't understand the program shows the lesson again
		wait();
		clean();
		explain_board_intersections();
	}
}