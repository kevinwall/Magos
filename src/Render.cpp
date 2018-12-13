#include "Render.h"
#include <iostream>
#include <cmath>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image_write.h"

Render::Render(Maze* maze, size_t height_, size_t width_)
{
	
	m_maze = maze; // Set the pointer to reference the maze we want to draw.
	auto width = width_; // Gets the image line size.
	auto height = height_; // Gets the image collum size.

	m_canvas = canvas::Canvas(width, height); // Creates a Canvas to render the image.
	m_canvas.clear(canvas::LIGHT_GREY); // Seting the background color to grey.
	m_canvas.thickness( 1 ); // Seting the line thickness to 3.

	border_h = width / 10; // Getting the horizontal border size.
	border_v = height / 10; // Getting the vertical border size.

	tam_h = (width - (2*border_h)) / m_maze->size_c(); // Getting the horizontal cell size.
	tam_v = (height - (2*border_v)) / m_maze->size_l(); // Getting the vertical cell size.
	

	b_box_h = tam_h / 4; // Getting the horizontal space between the cell wall and the box.
	b_box_v = tam_v / 4; // Getting the vertical space between the cell wall and the box.


	box_h = tam_h - (2*b_box_h); // Getting the box horizontal size.
	box_v = tam_v - (2*b_box_v); // Getting the box vertical size.

	
	
}

// The function we're using to draw the maze.
void Render::draw( int count )
{
	
	int i, j;

	// For each cell, we draw all the walls.
	for(i = 0; i < m_maze->size_l(); i++)
	{
		for(j = 0; j < m_maze->size_c(); j++)
		{
			if(m_maze->has_left_wall( j, i )) //If the cell has the left wall.
			{
				m_canvas.vline((border_h+(j*tam_h)), (border_v+(i*tam_v)), tam_v+1, canvas::BLACK);
			}
			
			if(m_maze->has_top_wall( j, i )) //If the cell has the top wall.
			{
				m_canvas.hline((border_h+(j*tam_h)), (border_v+(i*tam_v)), tam_h+1, canvas::BLACK);
			}

			if(m_maze->has_right_wall( j, i )) //If the cell has the right wall.
			{
				m_canvas.vline((border_h+(j*tam_h+tam_h)), (border_v+(i*tam_v)), tam_v+1, canvas::BLACK);
			}

			if(m_maze->has_bottom_wall( j, i )) //If the cell has the bottom wall.
			{
				m_canvas.hline((border_h+(j*tam_h)), (border_v+(i*tam_v+tam_v)), tam_h+1, canvas::BLACK);
			}

			if(m_maze->is_visited(j,i) == 1) // If the cell it's a invalid path
			{
				m_canvas.box( (border_h+(j*tam_h)) + b_box_h, (border_v+(i*tam_v)) + b_box_v , box_h, box_v, canvas::YELLOW );
			}

			if(m_maze->is_visited(j,i) == 2) // If the cell it's a valid path
			{
				m_canvas.box( (border_h+(j*tam_h)) + b_box_h , (border_v+(i*tam_v)) + b_box_v , box_h, box_v, canvas::RED );
			}

			if(i == 0 and j == 0) // If it's the entrance
			{
				m_canvas.box( (border_h+(j*tam_h)) + b_box_h, (border_v+(i*tam_v)) + b_box_v , box_h, box_v, canvas::LIGHT_BLUE);
			}

			if(i == m_maze->size_l()-1 and j == m_maze->size_c()-1) // If it's the exit
			{
				m_canvas.box( (border_h+(j*tam_h)) + b_box_h, (border_v+(i*tam_v)) + b_box_v , box_h, box_v, canvas::GREEN);
			}
			
		}	
	}

	// Here we get the canvas dimensions to create the png.
	auto width = m_canvas.width();
    auto height = m_canvas.height();
    auto pixels = m_canvas.buffer();

     // Invocando a função de gravação da biblioteca STB para gravar PNG.
    stbi_write_png_compression_level = 0;    // defaults to 8; set to higher for more compression
   	std::string name_file = "Maze" + std::to_string(count) +".png";
    stbi_write_png( name_file.c_str(),      // file name
                width, height,        // image dimensions
                3,                    // # of channels per pixel
                pixels,               // the pixels
                width*3)  ;           // length of a row (in bytes), see above.
}