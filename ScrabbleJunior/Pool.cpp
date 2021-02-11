#include "Pool.h"
#include <vector>

using namespace std;

Pool::Pool() {};

Pool::Pool(vector<char>& pool) {
	letterPool = pool;
}

void Pool::set_letterPool(vector<char>& letterPool) {
	this->letterPool = letterPool;
}

bool Pool::is_empty() {
	// verifies if the letterPool is empty
	return (letterPool.size() == 0);
}

char Pool::draw_random_tile() {
	// draws a random tile e erases that tile from the letterPool
	int random_tile_idx = rand() % letterPool.size();
	char random_tile = letterPool[random_tile_idx];
	letterPool.erase(letterPool.begin() + random_tile_idx);
	return random_tile;
}

int Pool::get_letterPool_size() {
	return letterPool.size();
}

void Pool::add_tile(char tile) {
	letterPool.push_back(tile);
}