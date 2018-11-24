#ifndef MAZE_H_
#define MAZE_H_

class Maze
{
private:
	int col, lin;
	std::vector<Cell> ptr_maze;
public:
	
	struct Cell
	{
		struct FlagCell
			{
				bool path = false; // paredes destruidas
				bool visited = false; // celulas já visitadas
			};

		enum Wall{
			None = 0,
			TopWall = 1, // Cima
			RightWall = 2, // Direita
			BottomWall = 4,// Baixo
			LeftWall = 8 // Esquerda
		};

		Cell( int col, int lin , Wall wall) : col_(col) , lin_(lin) {
			wall = 15;
		}

	};

	Maze(int col , int lin , std::vector<Maze> ptr_maze );
	~Maze();
	Make_maze( std::vector<Maze> ptr_maze );

	void get_lin(){
		return this->lin;
	}

	void get_col(){
		return this->col;
	}
};

#endif