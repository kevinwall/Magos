#include "Maze.h"
#include <algorithm>
#include <chrono>       // std::chrono::system_clock
#include "Render.h"
// Função para consultar a quantidade de linha máximas
int Maze::size_l()
{
	return lin;
}
// Função para cosultar a quantidade de colunas máximas
int Maze::size_c()
{
	return col;
}
//Construtor do maze que cria um vetor baseado nas linhas e colunas 
// e dar o indices  para cada célula
Maze::Maze( int col_ = 2, int lin_ = 1 ) 
{
	col = col_  ;
	lin = lin_;
	ptr_maze =  new Cell[ col* lin];

	for( int i = 0 ; i < col*lin ; i++){
		ptr_maze[i].set_p = i;  
	}


	std::srand( ( unsigned int ) std::time(NULL));
}
// Destrutor da classe maze que deleta a memória alocada dinamicamente pelo maze.
Maze::~Maze()
{
	delete [] ptr_maze;
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
// Função auxiliar para consultar se há parede direita
bool Maze::has_right_wall( int x, int y ){
	return ptr_maze[ col * y + x ].RightWall;
}
// Função auxiliar para consultar se há parede esquerda

bool Maze::has_left_wall( int x, int y ){
	return ptr_maze[ col * y + x ].LeftWall;
}
// Função auxiliar para consultar se há parede em cima

bool Maze::has_top_wall( int x, int y ){
	return ptr_maze[ col * y + x ].TopWall;
}
// Função auxiliar para consultar se há parede em baixo

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
			if( x <= 0 or ptr_maze[ col * x + y].set_p ==
			ptr_maze[ (col * (x-1) + y)].set_p ) return false;

			ptr_maze[ col * x + y].TopWall = false;
			ptr_maze[ col * (x-1) + y].BottomWall = false;
			
			set_same_number( std::max(ptr_maze[col * x + y].set_p,
			ptr_maze[ col * (x-1) + y].set_p),std::min(ptr_maze[col * x + y].set_p,
			ptr_maze[ col * (x-1) + y].set_p)); 

			return true;
		case Maze::Wall::m_RightWall:// condição caso seja da borda 
		   //ou as celular ja estiverem conectadas, retornar falso
			if( y >= (size_c()-1) or ptr_maze[ col * x + y].set_p ==
			ptr_maze[ col * x + (y+1)].set_p ) return false;

			ptr_maze[ col * x + y].RightWall = false;			
			ptr_maze[ col * x + (y+1)].LeftWall = false;
			
			set_same_number( std::max(ptr_maze[col * x + y].set_p,
			ptr_maze[ col * x + (y+1)].set_p),std::min(ptr_maze[col * x + y].set_p,
			ptr_maze[ col * x + (y+1)].set_p)); 


			return true;
		case Maze::Wall::m_BottomWall:// condição caso seja da borda 
		   //ou as celular ja estiverem conectadas, retornar falso
			if( x >= (size_l()-1) or ptr_maze[ col * x + y].set_p ==
			ptr_maze[ col * (y+1) + x].set_p ) return false;

			ptr_maze[ col * x + y].BottomWall = false;			
			ptr_maze[ col * (x+1) +y].TopWall = false;
			
			set_same_number( std::max(ptr_maze[(col * x) + y].set_p,
			ptr_maze[ col * (x+1) + y].set_p),std::min(ptr_maze[col * x + y].set_p,
			ptr_maze[ col * (x+1) + y].set_p)); 

			return true;	
		case Maze::Wall::m_LeftWall:// condição caso seja da borda 
		   //ou as celular ja estiverem conectadas, retornar falso
			if( y <= 0 or ptr_maze[ col * x + y].set_p ==
			ptr_maze[ col * x + (y-1)].set_p ) return false;

			ptr_maze[ col * x + y].LeftWall = false;
			ptr_maze[ col * x + (y-1)].RightWall = false;
			// Seta o menor valor entre as celular vizinhas para unir elas
			set_same_number( std::max(ptr_maze[col * x + y].set_p,
			ptr_maze[ col * x + (y-1)].set_p),std::min(ptr_maze[col * x + y].set_p,
			ptr_maze[ col * x + (y-1)].set_p)); 

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
	//return rand_lin[std::rand() %  size_l()];
	return std::rand() %  size_l();
}
// escolhe uma coordenada y randomicamente
int Maze::choose_y( ){
	//return rand_col[std::rand() %  size_c()];
	return std::rand() %  size_c();
}
// escolhe uma parede para quebrar randomicamente
Maze::Wall Maze::choose_wall(){
	switch( std::rand() % 4 ){
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
	for( int i = 0; i < size_l() * size_c()  ; i++){
		if( ptr_maze[i].set_p == old){

			ptr_maze[i].set_p = young;
		}
	}
}
// Função que consulta se uma celula foi visitada(fins de deuparação).Necessaria para o solve
int Maze::is_visited( int x, int y ){
	return ptr_maze[ col * y + x ].Visited;
}
// Função que altera se uma célula foi visitada
void Maze::set_visited( int x, int y, int Visited_){
	ptr_maze[  col * x  + y ].Visited = Visited_;
}
// /Função que utilizada pelo solve para verificar se uma celula foi visitada
int Maze::get_visited( int x, int y){
	return ptr_maze[  col * x  + y ].Visited ;
}
