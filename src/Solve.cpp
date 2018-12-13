#include "solve.h"

void solve::resolve( int x , int y, bool& solved,int& count){
	m_maze->set_visited( x,y,2);
	m_render->draw(count);
	count++;
	if( x == (m_maze->size_l()-1) and y == (m_maze->size_c()-1)){
		solved = true;
	}else {

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
		}
		if (!solved)m_maze->set_visited( x,y,1);

	}
}