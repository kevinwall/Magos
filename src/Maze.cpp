#include "Maze.h"
#include <cstdlib> // srand , rand
#include <vector>
#include <ctime>
#include <string>

Maze::Maze( int col, int lin) : lin(lin_) , col(col_) 
{
	maze = new FlagCell [ col * lin];

	Make_maze();
}

Maze::~Maze(){

	delete [] maze;
}

void Maze::Maze_maze(){

	
}