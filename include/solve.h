#ifndef SOLVE_H_
#define SOLVE_H_


#include "Render.h"// Render class
#include "Maze.h" // Maze class

class solve{
public:
	/*
	*@brief Construtor do solve que servirá para ligar o solve da classe maze e render
	*/
	solve(Render* render, Maze* maze) : m_render(render), m_maze(maze) 
		{ /*empty*/};
	/*
	*@brief IA em backtracking que resolve o maze 
	*/
	void resolve( int x, int y, bool& solved, int& count);

private:
	/*
	*@brief Ponteiro do Render e Maze
	*/
	Render* m_render;
	Maze* m_maze;
};



#endif