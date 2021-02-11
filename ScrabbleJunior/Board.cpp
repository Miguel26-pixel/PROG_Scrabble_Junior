#include "Board.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Colors.h"

using namespace std;

void Board::get_board_name() {
    
    // asks the user the path to the board file
    cout << "What's the board file name/path to the board file? " << endl;
    getline(cin, boardFile);

}

void Board::readBoard() {

    // reads the words and the dimensions from a text file

    char temp;
    string line;
    string coords, dir, word;

    wordList.clear();
    
    // opens the text file
    do {
        get_board_name();
        file.open(boardFile);
        if (!file.fail()) {
            break;
        }
        cerr << "Error opening the file" << endl;
    } while (true);
    
    // reads the dimensions
    getline(file, line);
    stringstream ss(line);
    ss >> height >> temp >> width;

    // reads the words
    while (getline(file, line)) {
        if (line == "") continue;
        stringstream ss(line);
        ss >> coords >> dir >> word;
        if(coords.length() != 2) break;                                 
        Word aWord(word, coords.at(1), coords.at(0), dir.at(0));
        wordList.push_back(aWord);
        this->nWords += 1;
    }
    file.close();
}

void Board::makeBoard() {

    // Fills the board with the words and creates a relation between the letter in a certain position and the woard that it belongs
    
    // reserves the space for the board
    board.resize(height);
    for (int i = 0; i < height; i++) {
        board[i].resize(width);
    }
    
    
    // fills the board with the words
    for (size_t i = 0; i < wordList.size(); i++) {
        for (size_t k = 0; k < wordList[i].get_word().length(); k++) {
            int x, y;
            
            if (wordList[i].get_dir() == 'H') 
                x = wordList[i].get_xcoord() + k, y = wordList[i].get_ycoord();
            else
                x = wordList[i].get_xcoord(), y = wordList[i].get_ycoord() + k;
            
            if (board[y][x].letter == ' ') {
                board[y][x] = wordList[i].get_letters()[k];
                letterPool.push_back(board[y][x].letter); // adds the letter on the board to the letter pool
            }
            board[y][x].inWords.push_back(wordList[i].get_word());
        }
    }
}

void Board::drawBoard() {

    // prints the board on the consol
    
    for (int i = -1; i < height; i++) {
        cout << "  ";

        for (int j = -1; j < width; j++) {
            // prints the first line of the board
            if (i == -1) {
                if (j == -1) cout << "  ";
                else cout << (char)(j + 97) << ' ';
            }

            else {
                if (j == -1) {
                    setcolor(WHITE, BLACK);
                    cout << (char)(i + 65) << ' ';
                }
                else {
                    if (board[i][j].played) { 
                        setcolor(RED, LIGHTGRAY);
                        cout << board[i][j].letter << ' ';
                    }
                    else {
                        setcolor(BLACK, LIGHTGRAY);
                        cout << board[i][j].letter << ' ';
                    }
                }
            }

        }
        setcolor(WHITE, BLACK);
        cout << '\n';
    }
        
    setcolor(RED, BLACK);
    cout << "Red -> filled tile";
    setcolor(WHITE, BLACK);
}

vector<char> Board::get_letterPool() {
    return letterPool;
}

vector<Letter> Board::available_moves() {

    // creates a vector with all the available moves
    vector<Letter> availableMoves;
    for (size_t i = 0; i < wordList.size(); i++) {
        if (!wordList[i].get_isCompleted()) {
            availableMoves.push_back(wordList[i].validMove());
        }
    }
    
    return availableMoves;
}


int Board::completed_words() {
    
    // counts the total number of completed words
    int completedWords = 0;

    for (size_t i = 0; i < wordList.size(); i++) {
        if (wordList[i].get_isCompleted()) completedWords++;
    }
    return completedWords;
}

void Board::update_board(int x, int y) {
 
    board[y][x].played = true;

    // Search for the words that belong to letter played and updates those words
    for (size_t i = 0; i < board[y][x].inWords.size(); i++) {
        for (size_t j = 0; j < wordList.size(); j++) {
            if (board[y][x].inWords[i] == wordList[j].get_word()) {
                if (wordList[j].get_dir() == 'H') 
                    wordList[j].update_letter(x - wordList[j].get_xcoord());
                else if (wordList[j].get_dir() == 'V') 
                    wordList[j].update_letter(y - wordList[j].get_ycoord());
            }
        }
    }
}

vector<vector<Letter>> Board::get_board() {
    return board;
}

bool Board::check_endGame() {
    
    // verifies if game has ended
    if (completed_words() == nWords) {
        return true;
    }
    return false;
}