#ifndef MAZE_H_
#define MAZE_H_

class Maze
{
public:
	enum Wall{
		None = 0,
		TopWall = 1, // Cima
		RightWall = 2, // Direita
		BottomWall = 4,// Baixo
		LeftWall = 8 // Esquerda
	}

	struct Cell
	{
		int lin, col;
		Cell( int lin_ = 0 , int col_ = 0) :
			 lin(lin_) , col(col_) { /*empty*/}
	};


	Maze(int col , int lin);
	~Maze();

	int col, lin;
private:
	struct FlagCell
	{
		int walls_destroyed; // paredes destruidas
		bool already_visited; // celulas já visitadas
		int id_cell; // identificação da célula
	};
};

#endif