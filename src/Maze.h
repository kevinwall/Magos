#ifndef MAZE_H_
#define MAZE_H_

#include <iostream>
#include <sstream>
#include <vector>
#include <string>

class Maze
{
public:
	
	struct Cell
	{
		bool TopWall ;
		bool RightWall; 
		bool BottomWall; 
		bool LeftWall ;

		bool Visited ;
		bool Path ;
		int id ;

		friend std::ostream& operator<<( std::ostream& os, const Cell& cells ){
			if( cells.TopWall == true and cells.RightWall == true and cells.BottomWall == true and
				cells.LeftWall == true ){
				os << " 1 ";
				return os;
			}

			os << " deu ruim";
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
	void knock_down( int x, int y, Maze::Wall wall);

	bool has_wall( int x, int y );

	bool has_right_wall( int x, int y );

	bool has_left_wall( int x, int y );

	bool has_top_wall( int x, int y );

	bool has_bottom_wall( int x, int y );

	bool ranged_out( int x, int y );

private:
	int col, lin;
	Cell* ptr_maze;
};

#endif