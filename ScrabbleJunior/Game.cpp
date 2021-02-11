#include <iostream>
#include "Game.h"
#include "Board.h"
#include <string>
#include "Player.h"
#include <limits>
#include <time.h>
#include <algorithm>
#include "Pool.h"

using namespace std;

// default connstructor
Game::Game() {}

Game::Game(vector<char> letterPool) {

	this->letterPool = Pool(letterPool);
	while (!read_nPlayers() && (nPlayers < 2 || nPlayers > 4));
	srand(time(NULL)); // creates a random seed based on the current time

}

bool Game::read_nPlayers() {
	
	// asks the user the number of players
	
	cout << "How many players will be playing?? ";
	cin >> nPlayers;
	return (!cin.fail() && cin.peek() == '\n');

}

void Game::create_players() {
	// asks the name of players and creates an objet Player for each player
	for (int i = 0; i < nPlayers; i++) {
		string name;
		cout << "Choose your name player" << i + 1 << ": ";
		getline(cin, name);
		players.push_back(Player(name));
	}
}

void Game::setGame() {

	// resets players scores
	for (int i = 0; i < nPlayers; i++) {
		players[i].get_score() = 0;
	}

	// Draw 7 tiles to each player
	for (int i = 0; i < nPlayers; i++) {
		for (int j = 0; j < 7; j++) {
			players[i].add_tile(letterPool.draw_random_tile());
		}
	}
}

void Game::draw_tiles() {

	// draw the tiles after each round until the pool is empty
	
	while (letterPool.get_letterPool_size() != 0 && players[player_turn].get_letterBag().size() < 7) {		
		players[player_turn].add_tile(letterPool.draw_random_tile());
	}
}

void Game::swap_tiles() {
	
	// swaps two tiles if the player hasn't any available moves
	cout << "Choose two tiles to swap: ";
	for (int i = 0; i < 2; i++) {
		char tile;
		do {
			if (cin >> tile && cin.peek() == '\n') {
				auxiliar tile_info = players[player_turn].in_letterBag(tile);
				if (tile_info.isValid) {
					// swap tile
					players[player_turn].remove_tile(tile_info.idx);
					players[player_turn].add_tile(letterPool.draw_random_tile());
					letterPool.add_tile(tile);
					break;
				}
			}
			cout << "Invalid Tile" << endl;
			cin.ignore((numeric_limits<streamsize>::max)(), '\n');
			cin.clear();

		} while (true);
	}
}

void Game::update_players_scores(int completedwords_total) {
	// adds the points earned in the turn
	players[player_turn].get_score() += completedwords_total - completed_words; // o aumento do score será dado pelo número total de palavras completas menos o número de palavras completas até à rinda anterior
	completed_words = completedwords_total;
}

Pool Game::get_letterPool() {
	return letterPool;
}

Player Game::get_player() {
	return players[player_turn];
}

void Game::update_playerLetterBag(char letter) {
	players[player_turn].update_letterBag(letter);
}

void Game::read_PlayerMove(vector<Letter> available_moves) {
	
	do {
		players[player_turn].read_move();
	} while (!players[player_turn].is_validMove(available_moves));
}

void Game::show_playersScores() {
	//prints the players scores
	cout << "Scores:" << endl;
	for (int i = 0; i < nPlayers; i++) {
		cout << players[i].get_name() << "'s score -> " << players[i].get_score() << endl;
	}
}

void Game::show_classification() {
	
	// prints the classification of each player. In case of a tie the thw winner is the player who wrote the number first

	vector<string> phrases = { "1st place - ", "2nd place - " , "3rd place - " , "4th place - " };

	sort(players.begin(), players.end());
	for (int i = 0; i < nPlayers; i++) {
		cout <<  phrases[i] << players[i].get_name() << " (" << players[i].get_score() << ")" << endl;
	}
}

bool Game::valid_game() {
	
	// verifies if there's at least 7 letters for each player

	if (letterPool.get_letterPool_size() / nPlayers >= 7) return true;
	cout << "There aren't enought letters for the number of players (minimum 7 letter per player)" << endl;
	return false;

}

int Game::get_nPlayers() {
	return nPlayers;
}

void Game::update_player_turn() {
	player_turn = (player_turn + 1) % nPlayers;
}