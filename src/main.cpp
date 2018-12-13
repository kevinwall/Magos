#include <iostream>
#include "Maze.h"
#include "Render.h"
#include "build.h"
#include <cstdlib>
#include "solve.h"

int main(int argc, char const *argv[]){
	
	int lin, col, rend_l, rend_col; // Variáveis com os tamanhos de linha(lin), coluna(col) do labirinto e os tamanhos da imagem (render_l e render_col)

	if(argc == 5) // Caso o usuário tenha digitado todos os 4 valores.
	{
		lin = std::atoi(argv[1]);
		col = std::atoi(argv[2]);

		rend_l = std::atoi(argv[3]);
		rend_col = std::atoi(argv[4]);
	}
	else if(argc == 4) // Caso o usuário tenha digitado apenas 3 valores (dimensões do labirinto e uma dimensão da imagem).
	{
		lin = std::atoi(argv[1]);
		col = std::atoi(argv[2]);

		rend_l = std::atoi(argv[3]);
		rend_col = rend_l;
	}
	else if(argc == 3) // Caso o usuário tenha digitdo apenas as dimensões do labirinto.
	{
		lin = std::atoi(argv[1]);
		col = std::atoi(argv[2]);

		rend_l = lin * 100;
		rend_col = col * 100;
	}
	else // Caso o usuário não tenha digitado nada ou mais parâmetros que o especificado.
	{
		lin = 10;
		col = 10;

		rend_l = 300;
		rend_col = 300;
	}

	Maze maze( lin, col ); // Criamos o labirinto.

	Render r(&maze, rend_l, rend_col); // Criamos o render e ligamos ele ao labirinto.

	
	int count = 0; // Contador das imagens
	r.draw( count ); // Mandamos desenhar a imagem base (sem nada destruído)
	count++;
	
	// Laço para gerar imagens conforme for quebrando as paredes
	while( maze.check_cell()){
		if(maze.build()){
			Render r(&maze, rend_l, rend_col);
			r.draw( count );
			count++;
		}		
	}

	// Começando a resolver o labirinto.
	bool solved = false; // Variável que verifica se o labirinto já foi resolvido.
	Render d(&maze, rend_l, rend_col); // Render que irá desenhar o labirinto resolvido.

	solve the_solve(&d, &maze); // Criamos um solver para resolver o labirinto.
	the_solve.resolve(0,0, solved,count); // Tentamos resolver o labirinto.
	//d.draw(count); // Desenhamos o labirinto resolvido.
	

	return 0;	
}