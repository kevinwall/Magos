#ifndef CANVAS_H
#define CANVAS_H

class Canvas
{
	private:
		unsigned char *m_pixels;
	public:
		// Classe que armazena o valor de um pixel
		struct Pixel
		{
			// Constói um pixel branco.
			Pixel(int r = 255, int g = 255, int b = 255) : RGB(r,g,b)
			{/*Empty*/}

			// Destrutor default.
			~Pixel() = default;

			// Função que modifica a cor do pixel
			void set_color(int r, int g, int b);

			private:
				// Bytes correspondentes a cada valor da escada RGB.
				unsigned char RGB[3];
		};

		// Construtor padrão que cria a matriz de pixels com o tamanho desejado.
		Canvas(int width, int length) : m_pixels(new unsigned char [width*length])
		{/*Empty*/}

		// Destrutor que deleta o vetor de pixels.
		~Canvas();

		// Retorna um ponteiro para o vetor de pixels (matriz convertida).
		unsigned char * get_pixels();

		// Cria uma linha horizontal.
		void hline(int x, int y, int w, Pixel color);

		// Cria uma linha vertical.
		void vline(int x, int y, int w, Pixel color);

		// Não entendi pra que serve ainda.
		void box(int x, int y, int w, int l, Pixel color);
};

#endif