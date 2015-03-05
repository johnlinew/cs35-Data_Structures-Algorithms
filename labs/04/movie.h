#ifndef MOVIE_H
#define MOVIE_H

#include <string>
#include "movieList.h"

/* getChoice prompts user for playing options and obtains
 *   legal choice
 *   Inputs: None
 *   Return: int representing the user's choice
 */
int getChoice();                 

/* loadFilm loads an ASCII movie into a list object
 *   Input: pointer to dynamically allocated MovieList object
 *   Return: True if the file was properly loaded
 */
bool loadFilm(MovieList* movieList, string filename);

//TODO Declare additional functions here

#endif
