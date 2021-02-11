#include <iostream>
#include <string>
#include "Board.h"
#include "Game.h"
#include <vector>
#include "Letter.h"
#include "Colors.h"
#include <Windows.h>

using namespace std;

void show_interface(Board& const board, Game& const game) {
    // prints the board, the scores and the lette pool of the player
    clrscr();
    board.drawBoard();
    cout << endl;
    game.show_playersScores();
    cout << endl;
    game.get_player().show_letterBag();
    cout << endl;

}

void welcome_message() {
    // prints "Welcome to scrabble in a colorful way
    string message = "Welcome to Scrabble Junior!!!";
    for (int i = 0; i < message.size(); i++) {
        setcolor((i + 1) % 16 , BLACK);
        cout << message.at(i);
    }
    setcolor(WHITE, BLACK);
    cout << "\n\n";
}


bool play_again() {

    // asks the user if he wants to play again; returns true if yes and false if no
    char answer;
    while (true) {
        cout << "Do you want to play again?? (Y for yes and N for no)" << endl;
        cin >> answer;
        cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        if (answer == 'Y' || answer == 'y') return true;
        if (answer == 'N' || answer == 'n') return false;
        cin.clear();
    }
}

int main() {

    welcome_message();

    do {
        bool run = true;    // true if the game is running false if it is finished

        Board board;
        Game game;

        // reads board until one valid is introduced
        do {
            board.readBoard();
            board.makeBoard();
            game = Game(board.get_letterPool());
            cin.ignore((numeric_limits<streamsize>::max)(), '\n');
        } while (!game.valid_game());

        game.create_players();
        game.setGame();

        // game loop
        while (run) {

            if (game.get_player().has_availableMoves(board.available_moves())) {

                int nMoves = 0; // counts the number of moves that the current player has made
                do {

                    show_interface(board, game);

                    // reads the player move
                    game.read_PlayerMove(board.available_moves());

                    // move converted to the board vector indexes
                    int x = game.get_player().get_move().at(1) - 'a';
                    int y = game.get_player().get_move().at(0) - 'A';  

                    board.update_board(x, y);
                    
                    game.update_playerLetterBag(board.get_board()[y][x].letter);

                    nMoves++;

                    game.update_players_scores(board.completed_words());

                } while (game.get_player().has_availableMoves(board.available_moves()) && nMoves < 2);
 
                game.draw_tiles();

                // checks if game has ended
                run = !board.check_endGame();

            }
            else if (game.get_letterPool().get_letterPool_size() != 0) {
                show_interface(board, game);
                game.swap_tiles();
            }
            else {
                show_interface(board, game);
                cout << "You don't have any valid moves to make!" << endl;
                cout << "There are no more tiles left in midle so you cant swap tiles... So you must pass!" << endl;
                // forces the current player to press enter to pass his turn
                string dummy;
                cout << "Press enter to pass to the next player" << endl;
                cin.ignore((numeric_limits<streamsize>::max)(), '\n');
                getline(cin, dummy);
            }

            game.update_player_turn();

        }
        // prints the board completed & shows the classification
        clrscr();
        board.drawBoard();
        cout << endl;
        game.show_classification();
    } while (play_again());
}
