#include "solve.h"
//Única função do solve que resolve o caminho do labirinto utilizando backtracking
void solve::resolve( int x , int y, bool& solved,int& count){
	m_maze->set_visited( x,y,2);
	m_render->draw(count);
	count++;
	if( x == (m_maze->size_l()-1) and y == (m_maze->size_c()-1)){
		solved = true;
	}else {
		// No if's seguintes,temos que verifica o caminho na seguinte ênfase:
		// baixo, direita, cima e baixo.
		//Ele verifica se caso a celula vizinha n foi visitada e se tem parede
		if( !(m_maze->has_bottom_wall(y,x)) 
			and m_maze->get_visited( x+1 , y) == 0
			and !solved){
			resolve( x+1, y,solved,count);
		}if( !(m_maze->has_right_wall(y,x))
			and m_maze->get_visited( x , y+1) == 0
			and !solved){
			resolve( x, y+1,solved,count);
		}if( !(m_maze->has_top_wall(y,x))
			and m_maze->get_visited( x-1 , y) == 0
			and !solved){
			resolve( x-1, y,solved,count);
		}if( !(m_maze->has_left_wall(y,x))
			and m_maze->get_visited( x , y-1) == 0
			and !solved){
			resolve( x, y-1,solved,count);
		}//Caso foi visitada, ela marca como visitada
		if (!solved)m_maze->set_visited( x,y,1);
		//Se for uma parede,faz nada.
	}
}