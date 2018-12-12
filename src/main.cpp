#include <iostream>
#include "Maze.h"
#include "Render.h"
#include "build.h"
#include <cstdlib>


int main(int argc, char const *argv[]){
	
	int lin, col, rend_l, rend_col;

	if(argc == 5)
	{
		lin = std::atoi(argv[1]);
		col = std::atoi(argv[2]);

		rend_l = std::atoi(argv[3]);
		rend_col = std::atoi(argv[4]);
	}
	else if(argc == 4)
	{
		lin = std::atoi(argv[1]);
		col = std::atoi(argv[2]);

		rend_l = std::atoi(argv[3]);
		rend_col = rend_l;
	}
	else
	{
		lin = 10;
		col = 10;

		rend_l = 300;
		rend_col = 300;
	}

	Maze maze( lin, col );

	Render r(&maze, rend_l, rend_col);
	// Laço para gerar imagens conforme for quebrando as paredes
	int count = 0;
	r.draw( count );
	count++;
	
	while( maze.check_cell()){
		if(maze.build()){
			Render r(&maze, rend_l, rend_col);
			r.draw( count );
			count++;
		}		
	}
	bool solved = false;
	maze.solve( 0, 0, solved);
	Render d(&maze, rend_l, rend_col);
	d.draw(count);
	



	return 0;	
}