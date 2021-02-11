#ifndef Fail_Guard
#define Fail_Guard
#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <cstring>
#include <fstream>
#include <sstream>
#include <windows.h>
#include <ctime>

/*
*sees if the input answer is valid
@param answer- it has to be "yes" or "no"
*/
std::string fail_answer(std::string answer);


/*
*sees if the input size is valid
@param size- it has to be a number between 2 and 20
*/
int fail_size( int size);


/*
*sees if the input word is valid
@param word- is has to be a string
*/
std::string fail_word(std::string word);


/*
*sees if the input xy is valid
@param xy- is has to be like Aa
@param sizeX
@param sizeY
*/
std::string fail_place_board(std::string xy,int sizeX, int sizeY);


/*
*sees if the input hv is valid
@param hv- is has to be "H" or "V"
*/
std::string fail_orientation(std::string hv);


/*
*sees if the input index_choice is valid
@param index_choice- is has to bigger than 1 and lower than vector_size
@param vector_size
*/
int fail_index_choice(int index_choice, int vector_size);


#endif