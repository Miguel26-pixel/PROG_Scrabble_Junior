#ifndef BoardBuilder_Guard
#define BoardBuilder_Guard
#include "Board.h"
#include "Tutorial.h"


class BoardBuilder {

public:
    /*
    constructor of BoardBuilder
    */
    BoardBuilder();

    /*
    *All the things that involve the txt file
    @param what- what the function it's gonna do
    @param sizeX
    @param sizeY
    @param wd- word
    @param xy- spot where the word it's gonna be placed
    @param hv- orientation
    @param st- string
    */
    void write_out(int what, int sizeX, int sizeY, std::string wd, std::string xy, std::string hv, std::string st);

private:

    /*
    *transforms the lower letters in upper letters
    @param st-string
    */
    std::string lower_to_upper(std::string st);

    std::vector<std::string> words_of_board;
    //vector with the words that the user chose

    std::vector<std::string> positions_of_board;
    //vector with the coordenates of the words

    std::vector<std::string> direction_of_words;
    //vector with the directions

    int lines = 0, collumns = 0;
    //represent the sizes of the board

};

#endif