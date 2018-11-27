#include <iostream>
#include "Maze.h"

int main(){
	Maze maze( 2 , 3 );

	maze.print_maze();
	if( maze.has_wall( 1 , 2) == false){
		std::cout << "Falta uma parede na célula [1,2]"<< "\n";
	}else {
		std::cout << "Há todas as paredes " << "\n"; 
	}

	maze.knock_down( 1 , 2 , Maze::Wall::m_LeftWall);

	if( maze.has_left_wall( 1 , 2) == false){
		std::cout << "Parede esquerda destruida na célula [1,2]"<< "\n";
	}

	maze.knock_down( 1 , 2 , Maze::Wall::m_RightWall);

	if( maze.has_right_wall( 1 , 2) == false){
		std::cout << "Parede direita destruida na célula [1,2]"<< "\n";
	}
	
	maze.knock_down( 1 , 2 , Maze::Wall::m_TopWall);
	
	if( maze.has_top_wall( 1 , 2) == false){
		std::cout << "Parede de cima destruida na célula [1,2]"<< "\n";
	}
	
	maze.knock_down( 1 , 2 , Maze::Wall::m_BottomWall);

	if( maze.has_bottom_wall( 1 , 2) == false){
		std::cout << "Parede de baixo destruida na célula [1,2]"<< "\n";
	}
	
	maze.print_maze();

	if( maze.has_wall( 1 , 2) == false){
		std::cout << "Tem nenhuma parede na célula [1,2]"<< "\n";
	}

	return 0;	
}