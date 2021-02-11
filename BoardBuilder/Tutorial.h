#ifndef Toturial_Guard
#define Toturial_Guard
#include "Board.h"
#include "Colors.h"
#include "BoardBuilder.h"
#include "Validations.h"
#include "Prints.h"

	/*
	*shows the beginning of the program asking if the user wants to see the tutorial
	*/
	void expose(); 

	/*
	*shows the first lesson , about what the user is going to do
	*/
	void explain_word(); 

	/*
	*second lesson , we try to explain how intersections can exist
	*/
	void explain_board_intersections(); 

#endif