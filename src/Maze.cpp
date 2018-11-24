#include "Maze.h"
#include <cstdlib> // srand , rand
#include <vector>
#include <ctime>
#include <string>

Maze::Maze( int col = 2, int lin = 1 , 
	std::vecto<Cell> ptr_maze ) : col_(col) , lin_(lin)
{
	ptr_maze.reserve( col_* lin_);

	Make_maze( ptr_maze );
}

Maze::~Maze(){

	delete [] ptr_maze;
}

void Maze::Make_maze(std::vecto<Maze> ptr_maze ){

	for (std::vector<Maze>::iterator it = ptr_maze.begin() 
		; it != ptr_maze.end(); ++it){
		*it.Cell = Wall::TopWall    
	}
}

void Maze::knock_down( int x, int y , Cell::Wall wall){
	switch(wall){
		case Cell::Wall::Topwall:

	}
}