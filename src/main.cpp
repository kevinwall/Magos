#include <iostream>
#include "Maze.h"
#include "Render.h"
#include "build.h"
#include <cstdlib>

<<<<<<< HEAD
int main(){
	Maze maze( 10, 20 );
=======
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
>>>>>>> 22dc95355ff2b2067f31d23445ef9b42c25c20c0

	Maze maze( lin, col );

	/*
	maze.print_maze();
	if( maze.has_wall( 1 , 2) == false){
		std::cout << "Falta uma parede na célula [1,2]"<< "\n";
	}else {
		std::cout << "Há todas as paredes " << "\n"; 
	}
	*/

	//std::cout << maze.size_c() << " " << maze.size_l() ;

	 // for( auto i = 0 ; i < 5 ; i++){
	 // 	for (int j = 0; j < 5; j++)
	 // 	{
	 // 		maze.knock_down( j , i , Maze::Wall::m_LeftWall);
	 // 		maze.knock_down( j , i , Maze::Wall::m_TopWall);
	 // 		maze.knock_down( j , i , Maze::Wall::m_BottomWall);
	 // 		maze.knock_down( j , i , Maze::Wall::m_RightWall);

	 // 	}
	 // }
	// maze.knock_down( 1 , 2 , Maze::Wall::m_LeftWall);

	// if( maze.has_left_wall( 1 , 2) == false){
	// 	std::cout << "Parede esquerda destruida na célula [1,2]"<< "\n";
	// }
	/*
	maze.knock_down( 1 , 2 , Maze::Wall::m_RightWall);

	if( maze.has_right_wall( 1 , 2) == false){
		std::cout << "Parede direita destruida na célula [1,2]"<< "\n";
	}
	
	maze.knock_down( 1 , 4 , Maze::Wall::m_TopWall);
	
	if( maze.has_top_wall( 1 , 4) == false){
		std::cout << "Parede de cima destruida na célula [1,2]"<< "\n";
	}
	
	maze.knock_down( 1 , 2 , Maze::Wall::m_BottomWall);

	if( maze.has_bottom_wall( 1 , 2) == false){
		std::cout << "Parede de baixo destruida na célula [1,2]"<< "\n";
	}
	
	maze.print_maze();

	if( maze.has_wall( 1 , 2) == false){
		std::cout << "Tem nenhuma parede na célula [1,2]"<< "\n";
	}*/


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