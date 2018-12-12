#include "Maze.h"
#include <algorithm>
#include <chrono>       // std::chrono::system_clock

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

	for( int i = 0 ; i < col*lin ; i++){
		ptr_maze[i].set_p = i;  
	}

	rand_lin = new int[lin];

	for(auto j{0}; j < lin; j++)
	{
		rand_lin[j] = j;
	}

	rand_col = new int[col];

	for(auto k{0}; k < col; k++)
	{
		rand_col[k] = k;
	}

	rand_wall = new int[4];

	for(auto d{0}; d < 4; d++)
	{
		rand_wall[d] = d;
	}

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();	
	std::shuffle(rand_lin, rand_lin+lin, std::default_random_engine(seed));
	std::shuffle(rand_col, rand_col+col, std::default_random_engine(seed));
	std::shuffle(rand_wall, rand_wall+4, std::default_random_engine(seed));

	std::srand( ( unsigned int ) std::time(NULL));
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
// checagem de se estiver fora do ranged
bool Maze::ranged_out( int x, int y ){
	if( x > lin or y > col or x < 0 or y < 0){
		return false ;
	}

	return true;
}
                                    
// função que derruba as paredes
bool Maze::knock_down( int x, int y , Maze::Wall wall){
	if( !ranged_out(x,y)){
		throw std::string(" Coordenadas inválidas");
	}
	switch(wall){
		case Maze::Wall::m_TopWall:// condição caso seja da borda 
		   //ou as celular ja estiverem conectadas, retornar falso
			if( y <= 0 or ptr_maze[ col * y + x].set_p ==
			ptr_maze[ col * (y-1) + x].set_p ) return false;

			ptr_maze[ col * y + x].TopWall = false;
			ptr_maze[ col * (y-1) + x].BottomWall = false;
			
			set_same_number( std::max(ptr_maze[col * y + x].set_p,
			ptr_maze[ col * (y-1) + x].set_p),std::min(ptr_maze[col * y + x].set_p,
			ptr_maze[ col * (y-1) + x].set_p)); 

			return true;
		case Maze::Wall::m_RightWall:// condição caso seja da borda 
		   //ou as celular ja estiverem conectadas, retornar falso
			if( x >= (size_l()-1) or ptr_maze[ col * y + x].set_p ==
			ptr_maze[ col * y + (x+1)].set_p ) return false;

			ptr_maze[ col * y + x].RightWall = false;			
			ptr_maze[ col * y + (x+1)].LeftWall = false;
			
			set_same_number( std::max(ptr_maze[col * y + x].set_p,
			ptr_maze[ col * y + (x+1)].set_p),std::min(ptr_maze[col * y + x].set_p,
			ptr_maze[ col * y + (x+1)].set_p)); 


			return true;
		case Maze::Wall::m_BottomWall:// condição caso seja da borda 
		   //ou as celular ja estiverem conectadas, retornar falso
			if( y >= (size_c()-1) or ptr_maze[ col * y + x].set_p ==
			ptr_maze[ col * (y+1) + x].set_p ) return false;

			ptr_maze[ col * y + x].BottomWall = false;			
			ptr_maze[ col * (y+1) + x].TopWall = false;
			
			set_same_number( std::max(ptr_maze[col * y + x].set_p,
			ptr_maze[ col * (y+1) + x].set_p),std::min(ptr_maze[col * y + x].set_p,
			ptr_maze[ col * (y+1) + x].set_p)); 

			return true;	
		case Maze::Wall::m_LeftWall:// condição caso seja da borda 
		   //ou as celular ja estiverem conectadas, retornar falso
			if( x <= 0 or ptr_maze[ col * y + x].set_p ==
			ptr_maze[ col * y + (x-1)].set_p ) return false;

			ptr_maze[ col * y + x].LeftWall = false;
			ptr_maze[ col * y + (x-1)].RightWall = false;
			// Seta o menor valor entre as celular vizinhas para unir elas
			set_same_number( std::max(ptr_maze[col * y + x].set_p,
			ptr_maze[ col * y + (x-1)].set_p),std::min(ptr_maze[col * y + x].set_p,
			ptr_maze[ col * y + (x-1)].set_p)); 

			return true;

		case None:
			return false;	
	}

	return false;


}
// quebra as paredes randomicamente de uma celula randomica
// e retorna true caso ela possa ser quebrada
bool Maze::build( ){

	return knock_down( choose_x(), choose_y(), choose_wall());

}
// escolhe uma coordenada y randomicamente
int Maze::choose_x( ){
	return rand_lin[std::rand() %  size_l()];
}
// escolhe uma coordenada y randomicamente
int Maze::choose_y( ){
	return rand_col[std::rand() %  size_c()];
}
// escolhe uma parede para quebrar randomicamente
Maze::Wall Maze::choose_wall(){
	switch( rand_wall[std::rand() % 4] ){
		case 0 :
			return Maze::Wall::m_TopWall;
		case 1 :
			return Maze::Wall::m_RightWall;
		case 2 :
			return Maze::Wall::m_BottomWall;
		case 3 :
			return Maze::Wall::m_LeftWall;
	}

	return Maze::Wall::m_BottomWall;
	
}
// Função que checa o numero das celulas para juntar o "conjunto" entre elas depois
bool Maze::check_cell(){
	for( int i = 1; i < size_l() * size_c() ; i++){
		if( ptr_maze[i].set_p != 0){
			return true;
		}
	}

	return false;
}
// Função que serve para setar o numero da "menor" celula para deixarem todas com mesmo numero 
// para em seguida para o laço com o check cell que irá parar quando todas tiverem o mesmo numero
void Maze::set_same_number( int old ,  int young){
	for( int i = 0; i < size_l() * size_c() ; i++){
		if( ptr_maze[i].set_p == old){
			ptr_maze[i].set_p = young;
		}
	}
}

void Maze::solve( int x , int y, bool& solved){
	ptr_maze[  col * y  + x ].Visited = 2;
	//std::cout << solved << std::endl;
	//std::cout << x << " " << lin << " " << y << " " << col << std::endl;
	if( x == (lin -1) and y == (col-1)){
		solved = true;
	}else {

		if( !(has_bottom_wall(x,y)) 
			and ptr_maze[  col * (y+1)  + x ].Visited == 0
			and !solved){
			solve( x, y+1,solved);
		}if( !(has_right_wall(x,y))
			and ptr_maze[  col * y  + (x+1) ].Visited == 0
			and !solved){
			solve( x+1, y,solved);
		}if( !(has_top_wall(x,y))
			and ptr_maze[  col * (y-1)  + x ].Visited == 0
			and !solved){
			solve( x, y-1,solved);
		}if( !(has_left_wall(x,y))
			and ptr_maze[  col * y  + (x-1) ].Visited == 0
			and !solved){
			solve( x-1, y,solved);
		}
		if (!solved) ptr_maze[ col * y + x].Visited = 1;

	}
}

int Maze::is_visited( int x, int y ){
	return ptr_maze[ col * y + x ].Visited;
}