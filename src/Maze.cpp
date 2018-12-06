#include "Maze.h"

int Maze::size_l()
{
	return lin;
}

int Maze::size_c()
{
	return col;
}

Maze::Maze( int col_ = 2, int lin_ = 1 ) 
{
	col = col_  ;
	lin = lin_;
	ptr_maze =  new Cell[ col* lin];
}
// função para verificar se tá válido as imprenssões
void Maze::print_maze(){
	for( int i = 0 ; i < col * lin ; i++){
		std::cout << ptr_maze[i] << std::endl;
	}
	std::cout << std::endl;
}
// Construtor da célula
Maze::Cell::Cell(){
	 TopWall = true ;
	 RightWall = true ; 
	 BottomWall = true ; 
	 LeftWall = true ;
}
// Verificação se há muros
bool Maze::has_wall( int x, int y ){
	return ptr_maze[ col * y  + x].LeftWall or ptr_maze[ col * y + x].RightWall or ptr_maze[ col * y  + x].TopWall
	or ptr_maze[ col * y  + x].BottomWall;
}

bool Maze::has_right_wall( int x, int y ){
	return ptr_maze[ col * y + x ].RightWall;
}

bool Maze::has_left_wall( int x, int y ){
	return ptr_maze[ col * y + x ].LeftWall;
}

bool Maze::has_top_wall( int x, int y ){
	return ptr_maze[ col * y + x ].TopWall;
}

bool Maze::has_bottom_wall( int x, int y ){
	return ptr_maze[ col * y + x ].BottomWall;
}

bool Maze::ranged_out( int x, int y ){
	if( x > lin or y > col or x < 0 or y < 0){
		return false ;
	}

	return true;
}
                                    
// função que derruba as paredes
void Maze::knock_down( int x, int y , Maze::Wall wall){
	if( !ranged_out(x,y)){
		throw std::string(" Coordenadas inválidas");
	}
	switch(wall){
		case Maze::Wall::m_TopWall:
			ptr_maze[ col * y + x].TopWall = false;
			if( ranged_out( y-1, x) == true ){
				ptr_maze[ col * y-1 + x].BottomWall = false;
			}
			break;
		case Maze::Wall::m_RightWall:
			ptr_maze[ col * y + x].RightWall = false;
			if( ranged_out( y, x+1) == true ){
				ptr_maze[ col * y + (x+1)].LeftWall = false;
			}
			break;
		case Maze::Wall::m_BottomWall:
			ptr_maze[ col * y + x].BottomWall = false;
			if( ranged_out( y+1, x) == true ){
				ptr_maze[ col * y+1 + x].TopWall = false;
			}
			break;	
		case Maze::Wall::m_LeftWall:
			ptr_maze[ col * y + x].LeftWall = false;
			if( ranged_out( y, x-1) == true ){
				ptr_maze[ col * y + (x-1)].RightWall = false;
			}
			break;
		default : 
			break;	
	}

}