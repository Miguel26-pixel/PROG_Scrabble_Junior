#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include "Board.h"
#include "Colors.h"
using namespace std;

//set the background colour of the board
void setconsolecolor(int textColor, int bgColor) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), (textColor + (bgColor * 16))); //set the background colour of the board
}