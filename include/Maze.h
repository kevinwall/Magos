#ifndef MAZE_H_
#define MAZE_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>
#include <string>
#include <stack>
#include <list>

class Maze
{
public:
	
	struct Cell
	{
		bool TopWall ;
		bool RightWall; 
		bool BottomWall; 
		bool LeftWall ;

		int Visited ;
		int set_p;

		friend std::ostream& operator<<( std::ostream& os, const Cell& cells ){
			if( cells.TopWall == true and cells.RightWall == true and cells.BottomWall == true and
				cells.LeftWall == true ){
				os << " Nada destruido ";
				return os;
			}
			
			os << "Alguma parede destruida";

			return os;
		}
		Cell();
	};

	enum Wall{
		None = 0,
		m_TopWall = 1,
		m_RightWall = 2,
		m_BottomWall = 4,
		m_LeftWall = 8
	};
	void print_maze();
	Maze(int col , int lin );
	~Maze() = default;
	bool knock_down( int x, int y, Maze::Wall wall);

	bool has_wall( int x, int y );

	bool has_right_wall( int x, int y );

	bool has_left_wall( int x, int y );

	bool has_top_wall( int x, int y );

	bool has_bottom_wall( int x, int y );

	bool ranged_out( int x, int y );

	int size_l();

	int size_c();

	bool build( );

	int choose_x( );

	int choose_y( );

	Maze::Wall choose_wall();

	bool check_cell();

	void set_same_number( int old ,  int young);

	void solve( int x, int y, bool& solved);

	int is_visited(int x, int y);

private:
	int col, lin;
	Cell* ptr_maze;

	int * rand_lin;
	int * rand_col;
	int * rand_wall;
};

#endif