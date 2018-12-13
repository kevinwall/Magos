#ifndef SOLVE_H_
#define SOLVE_H_


#include "Render.h"
#include "Maze.h" // Maze class

class solve{
public:
	solve(Render* render, Maze* maze) : m_render(render), m_maze(maze) 
		{ /*empty*/};

	void resolve( int x, int y, bool& solved, int& count);

private:
	Render* m_render;
	Maze* m_maze;
};



#endif