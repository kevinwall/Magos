#include <iostream>
#include <cstring>

#define STB_IMAGE_WRITE_IMPLEMENTATION
#include "../include/stb_image_write.h"

#include "../include/canvas.h"

using namespace canvas;

int main(void)
{
    // Cria um objeto canvas de 800 por 600 pixels de dimensão.
    Canvas c( 800, 600 );

    // Definie a cor de fundo da imagem.
    c.clear( LIGHT_GREY );

    // Vamos desenhar um retângulo cujo canto superior esquerdo está em (100,100).
    coord_type orig_x{100}, orig_y{100};
    // Vamos utilizar uma linha com 3 pixels de largura.
    c.thickness( 3 );
    // Um retângulo pode ser formado através do desenho de 4 linhas.
    c.hline( orig_x, orig_x, 300, RED );
    c.vline( orig_x, orig_y, 200, STEEL_BLUE );
    c.hline( orig_x, orig_y+200, 300, GREEN );
    c.vline( orig_x+300, orig_y, 200, YELLOW );
    // Preencher o interior do retângulo com um quadrado de 50 x 50 pixels.
    c.box( orig_x+125, orig_y+75, 50, 50, DEEP_SKY_BLUE );

    // Recuperar as informações do Canvas (imagem) para poder gravar um arquivo PNG.
    auto width = c.width();
    auto height = c.height();
    auto pixels = c.buffer(); // Ponteiro para o vetor de bytes representando a imagem.

    Canvas a(c); 
    Canvas b;
    b = c;

    auto width_2 = a.width();
    auto height_2 = a.height();
    auto pixels_2 = a.buffer(); // Ponteiro para o vetor de bytes representando a imagem.

    auto width_3 = b.width();
    auto height_3 = b.height();
    auto pixels_3 = b.buffer(); // Ponteiro para o vetor de bytes representando a imagem.

    // Invocando a função de gravação da biblioteca STB para gravar PNG.
    stbi_write_png_compression_level = 0;    // defaults to 8; set to higher for more compression
    stbi_write_png( "teste.png",      // file name
                width, height,        // image dimensions
                3,                    // # of channels per pixel
                pixels,               // the pixels
                width*3)  ;           // length of a row (in bytes), see above.

    stbi_write_png_compression_level = 0;    // defaults to 8; set to higher for more compression
    stbi_write_png( "teste2.png",      // file name
                width_2, height_2,        // image dimensions
                3,                    // # of channels per pixel
                pixels_2,               // the pixels
                width_2*3)  ;           // length of a row (in bytes), see above.

    stbi_write_png_compression_level = 0;    // defaults to 8; set to higher for more compression
    stbi_write_png( "teste3.png",      // file name
                width_3, height_3,        // image dimensions
                3,                    // # of channels per pixel
                pixels_3,               // the pixels
                width_3*3)  ;           // length of a row (in bytes), see above.

}
