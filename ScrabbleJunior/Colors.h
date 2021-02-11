#ifndef Colors_GUARD
#define Colors_GUARD
//colors

const unsigned int BLACK = 0;
const unsigned int BLUE = 1;
const unsigned int GREEN = 2;
const unsigned int CYAN = 3;
const unsigned int RED = 4;
const unsigned int MAGENTA = 5;
const unsigned int BROWN = 6;
const unsigned int LIGHTGRAY = 7;
const unsigned int DARKGRAY = 8;
const unsigned int LIGHTBLUE = 9;
const unsigned int LIGHTGREEN = 10;
const unsigned int LIGHTCYAN = 11;
const unsigned int LIGHTRED = 12;
const unsigned int LIGHTMAGENTA = 13;
const unsigned int YELLOW = 14;
const unsigned int WHITE = 15;

void clrscr(void);

// Set text color & background
void setcolor(unsigned int color, unsigned int background_color);

#endif