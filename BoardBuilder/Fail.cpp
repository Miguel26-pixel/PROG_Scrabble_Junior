#include <iostream>
#include <string>
#include "Fail.h"
#include "Prints.h"
using namespace std;

string fail_answer(string answer) {
    while (cin.fail() || (answer != "yes" && answer != "no")) {                     //answer is valid when it's "yes" or "no"
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << FAIL_ANSWER << endl;
        cin >> answer;
    }
    return answer;
}


int fail_size(int size) {
    while (cin.fail() || size < 2 || size>20) {                                     //size is valid when it's a int number between 2 and 20
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << FAIL_SIZE << endl;
        cin >> size;
    }
    return size;
}


string fail_word(string word){
    while (cin.fail()) {                                                            //it's valid when it's one string
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << FAIL_WORD << endl;
        cin >> word;
    }
    return word;
}


string fail_place_board(string xy,int sizeX, int sizeY) {
    while (cin.fail()||xy.at(0)<'A'||xy.at(0)>char('A'+sizeY-1)||
        xy.at(1)> char('a' + sizeX - 1) ||xy.at(1)<'a'||xy.length()!=2) {      //the input is valid when it's like Aa
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << FAIL_PLACE_WORD << endl;
        cin >> xy;
    }
    return xy;
}


string fail_orientation(string hv) {
    while (cin.fail() || (hv!="H" && hv!="V") || hv.length() != 1) {                //the input is valid if it's H or V
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << FAIL_ORIENTATION << endl;
        cin >> hv;
    }
    return hv;
}


int fail_index_choice(int index_choice, int vector_size) {
    while (cin.fail() || index_choice<1 || index_choice>vector_size) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << FAIL_INDEX_CHOICE << endl;
        cin >> index_choice;
    }
    return index_choice;
}