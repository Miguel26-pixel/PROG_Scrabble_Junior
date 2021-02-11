#include "Player.h"
#include <string>
#include <iostream>

using namespace std;

Player::Player(string& name) {
	this->name = name;
}

void Player::show_letterBag() {
	// prints the player's name and letterBag
	cout << "It's your turn, " << name << "!" << endl;
	cout << "Your tiles are: ";
	for (int i = 0; i < letterBag.size(); i++) {
		cout << letterBag[i] << " ";
	}
}

void Player::read_move() {
	// reads the move from the console
	cout << endl;
	cout << "Choose your move (exemple Aa): ";
	cin >> move;
}

bool Player::has_availableMoves(vector<Letter> availableMoves) {
	
	// verifies if the player has any available moves
	// available moves: array with all available moves in the current state of the game

	for (size_t i = 0; i < availableMoves.size(); i++) {
		for (int j = 0; j < letterBag.size(); j++) {
			if (letterBag[j] == availableMoves[i].letter) {
				return true;
			}
		}
	}
	return false;
}

string Player::get_move() {
	return move;
}

int& Player::get_score() {
	return score;
}

string Player::get_name() {
	return name;
}

bool Player::is_validMove(vector<Letter> availableMoves) {
	
	// verifies if a move is valid

	if (!cin.fail() && move.length() == 2 && (move.at(0) >= 'A' && move.at(0) <= 'Z') && (move.at(1) >= 'a' && move.at(1) <= 'z')) {

		// searches for the move in the availableMoves
		for (size_t i = 0; i < availableMoves.size(); i++) {
			if (move.at(0) == availableMoves[i].ypos && move.at(1) == availableMoves[i].xpos) {
				if (in_letterBag(availableMoves[i].letter).isValid)	return true;
			}
		}
	}
	cerr << "Invalid move!" << endl;
	cin.ignore((numeric_limits<streamsize>::max)(), '\n');
	cin.clear();
	return false;
}

auxiliar Player::in_letterBag(char letter) {
	// verifies if a letter is in the letterBag
	// returns a struct with a boolean true if the letter is in the letterbag and the index of that letter

	auxiliar tile_info;  

	for (int j = 0; j < letterBag.size(); j++) {
		if (letter == letterBag[j]) {
			tile_info.isValid = true;
			tile_info.idx = j;
		}
	}
	return tile_info;
}

void Player::update_letterBag(char letter) {
	// searches for a tile in the letterBag and removes it
	for (size_t i = 0; i < letterBag.size(); i++) {
		if (letterBag[i] == letter) {
			remove_tile(i);
			break;
		}
	}
}

void Player::add_tile(char c) {
	letterBag.push_back(c);
}

void Player::remove_tile(int index) {
	letterBag.erase(letterBag.begin() + index);
}

vector<char> Player::get_letterBag() {
	return letterBag;
}

bool Player::operator < (const Player& player) {	
	return (this->score > player.score);
}