#ifndef Player_GUARD
#define Player_GUARD

#include <string>
#include <vector>
#include "Letter.h"

class Player {
	
	std::string name;	
	std::string move;
	int score;
	std::vector<char> letterBag;

public:

	Player(std::string& name);
	void read_move(); // reads move
	bool has_availableMoves(std::vector<Letter> availableMoves); // verifies if the player as atleast 1 possible move	
	bool is_validMove(std::vector<Letter> availableMoves); // verifies if a move is valid
	void update_letterBag(char letter); // search for the a certain tile in the letterBag and removes it
	
	// add/remove tiles from the player letterbag
	void add_tile(char c);
	void remove_tile(int index);

	auxiliar in_letterBag(char tile); // verifies if a letter is in the playes's letterBag
	void show_letterBag(); // prints the player's letterbag
	bool operator < (const Player& player);

	//Gets:
	std::string get_name();
	int& get_score();
	std::string get_move();
	std::vector<char> get_letterBag();
};

#endif