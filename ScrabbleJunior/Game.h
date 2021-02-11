#ifndef Game_GUARD
#define Game_GUARD

#include "Board.h"
#include "Player.h"
#include <vector>
#include "Pool.h"

class Game {

	int nPlayers;	// number of players
	int player_turn = 0; // says which player is playing
	Pool letterPool;	
	int completed_words = 0; // contains the number of words completed until the last round
	std::vector<Player> players;	// vector with a player oblect for each player

	bool read_nPlayers(); // reads the number of players

public:

	Game(); // default constructor;
	Game(std::vector<char> letterPool);
	void create_players(); 
	void setGame(); // sets the players scores to 0 and draws 7 tiles to each player
	void draw_tiles(); // draws 2 tiles at the end of each round til the letterPool is empty
	void swap_tiles(); // swap 2 tiles if there arent any avaiable moves
	void update_players_scores(int completedwords_total); // adds the number of points scored in a move
	void update_playerLetterBag(char letter);
	void read_PlayerMove(std::vector<Letter> available_moves);
	bool valid_game(); // verifies if there is atleast 7 letters for each player
	void update_player_turn();

	// print functions
	void show_playersScores();
	void show_classification();
	
	//Gets:
	int get_nPlayers();
	Player get_player(); // returns the current player playing
	Pool get_letterPool();
};

#endif