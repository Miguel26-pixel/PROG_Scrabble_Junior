#ifndef Pool_GUARD
#define Pool_GUARD

#include <vector>

class Pool {

	std::vector<char> letterPool;

public:

	Pool();
	Pool(std::vector<char>& Pool);
	bool is_empty(); // verifies if the pool is empty
	char draw_random_tile();	// draws one random tile from the pool
	void add_tile(char tile); // adds one tile to the pool

	//Gets and sets:
	int get_letterPool_size(); 
	void set_letterPool(std::vector<char>& letterPool);
};

#endif
