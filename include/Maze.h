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


class Maze
{
public:
	/** 	
	*@brief Struct da cell que tem as paredes , condição de visitada e o indice dela  	
	*/
	struct Cell
	{
		bool TopWall ;
		bool RightWall; 
		bool BottomWall; 
		bool LeftWall ;

		int Visited ;
		int set_p;
		/** 	
		*@brief Função auxiliar de depuração  	
		*/
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
	/** 	
	*@brief Enumerador das paredes que servirar para quebrar as paredes em knock_down  	
	*/
	enum Wall{
		None = 0,
		m_TopWall = 1,
		m_RightWall = 2,
		m_BottomWall = 4,
		m_LeftWall = 8
	};
	/** 	
	*@brief Função auxiliar de depuração  	
	*/
	void print_maze();
	Maze(int col , int lin );
	~Maze() = default;
	/**
	*@brief Função que derruba uma parede
	*/
	bool knock_down( int x, int y, Maze::Wall wall);
	/**
	*@brief Função que serve para consultar se há parede 
	*/
	bool has_wall( int x, int y );
	/**
	*@brief Função que serve para consultar se há parede direita
	*/
	bool has_right_wall( int x, int y );
	/**
	*@brief Função que serve para consultar se há parede esquerda
	*/
	bool has_left_wall( int x, int y );
	/**
	*@brief Função que consultar se há parede de cima
	*/
	bool has_top_wall( int x, int y );
	/**
	*@brief Função que consultar se há parede de baixo
	*/
	bool has_bottom_wall( int x, int y );
	/**
	*@brief Função que serve para imperdir que seja acessado uma posição fora dos limites
	*/
	bool ranged_out( int x, int y );
	/**
	*@brief Função que consulta uma linha
	*/
	int size_l();
	/**
	*@brief Função que consulta uma coluna
	*/
	int size_c();
	/**
	*@brief Função que derruba as paredes proceduralmente 
	*/
	bool build( );
	/**
	*@brief Função que serve para escolher uma posição de coluna de célula 
	*/
	int choose_x( );
	/**
	*@brief Função que serve para escolher uma posição da linha da célula
	*/
	int choose_y( );
	/**
	*@brief Função que serve para escolher uma parede de uma célula 
	*/
	Maze::Wall choose_wall();
	/**
	*@brief Função auxiliar server para o laço do build
	*@details Ela faz com que o laço saiba quando todas as células estão ligadas ou não 
	*/
	bool check_cell();
	/**
	*@brief Função auxiliar que iguala os indices das células que estão ligadas umas às outras 
	*/
	void set_same_number( int old ,  int young);
	/** 	
	*@brief Função auxiliar de depuração  
	*@return a resposta de se a ceula foi visitada ou não	
	*/
	int is_visited(int x, int y);
	/**
	*@brief altera a condição de visitada de uma célula 
	*/
	void set_visited( int x, int y, int Visited_);

	int get_visited( int x, int y );

private:
	int col, lin;
	Cell* ptr_maze;

	//int * rand_lin;
	//int * rand_col;
	//int * rand_wall;
};

#endif