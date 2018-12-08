#ifndef RENDER_H
#define RENDER_H

#include "Maze.h" // Maze class
#include "canvas.h" // Canvas class
#include "common.h" // Color class

class Render
{
private:
	Maze* m_maze; // Pointer to the maze we want to render a image from.
	canvas::Canvas m_canvas; // A pointer to the canvas to make the .png image of the maze.
	int tam_h; // The horizontal size of one cell.
	int tam_v; // The vertical size of one cell.
	int border_h; // The horizontal border size.
	int border_v; // The vertical border size.

public:
	/* 
	The constructor witch links the Render to the maze witch 
	is going to be rendered and creates the canvas with the desired size.
	*/
	Render(Maze* maze, size_t height_, size_t width_);

	/* 
	Default destructor witch is going to delete the class 
	not destroy the maze, that can still be used in other classes.
	*/
	~Render() = default;

	/*
	The function that is going to create the image representing the actual state of the maze.
	*/
	void draw( int count); 

	void set_maze( Maze* maze ){
	 	m_maze = maze;
	}
};

#endif