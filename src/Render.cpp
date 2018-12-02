#include "Render.h"
#include <iostream>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image_write.h"

Render::Render(Maze& maze)
{
	m_maze = &maze; // Set the pointer to reference the maze we want to draw.
	auto height = 10 * m_maze->size_c(); // Gets the maze collum size.
	auto widht = 10 * m_maze->size_l(); // Gets the maze lines size.

	m_canvas = canvas::Canvas(height, widht); // Creates a Canvas to render the image.
	m_canvas.clear(canvas::LIGHT_GREY); // Seting the background color to grey.
	m_canvas.thickness( 1 ); // Seting the line thickness to 3.

	border_h = widht / 10; // Getting the horizontal border size.
	border_v = height / 10; // Getting the vertical border size.

	tam_h = (widht- (2*border_h)) / m_maze->size_c(); // Getting the horizontal cell size.
	tam_v = (height - (2*border_v)) / m_maze->size_l(); // Getting the vertical cell size.
}


void Render::draw()
{
	
	int i, j;

	// For each cell, we draw the left and upper wall.
	for(i = 0; i < m_maze->size_l(); i++)
	{
		for(j = 0; j < m_maze->size_c(); j++)
		{
			if(m_maze->has_left_wall( i, j )) //If the cell has the left wall.
			{
				m_canvas.vline((border_h+(i*tam_h)), (border_v+(j*tam_v)), tam_v+1, canvas::BLACK);
			}
			
			if(m_maze->has_top_wall( i, j ))
			{
				m_canvas.hline((border_h+(i*tam_h)), (border_v+(j*tam_v)), tam_h+1, canvas::BLACK);
			}
			
		}	
	}

	m_canvas.vline(m_canvas.width()-border_h, border_v, m_canvas.width()-(2*border_v), canvas::BLACK);
	m_canvas.hline(border_h, m_canvas.height()-border_v, m_canvas.height()-(2*border_h)+1, canvas::BLACK);

	auto width = m_canvas.width();
    auto height = m_canvas.height();
    auto pixels = m_canvas.buffer();

     // Invocando a função de gravação da biblioteca STB para gravar PNG.
    stbi_write_png_compression_level = 0;    // defaults to 8; set to higher for more compression
    stbi_write_png( "teste.png",      // file name
                width, height,        // image dimensions
                3,                    // # of channels per pixel
                pixels,               // the pixels
                width*3)  ;           // length of a row (in bytes), see above.
}