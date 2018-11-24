/*!
 * Canvas class implementation.
 * @file canvas.cpp
 */

#include <stdexcept>
#include <iostream>

#include "../include/canvas.h"

namespace canvas {

    /*!
     * Deep copy of the canvas.
     * @param clone The object we are copying from.
     */
    Canvas::Canvas( const Canvas & clone )
    {
        this->m_width = clone.m_width;
        this->m_height = clone.m_height;
        this->m_line_thikness = clone.m_line_thikness;

        m_pixels = new component_t [ m_height * m_width * 3 ];

       for(size_t i{0}; i < m_height * m_width * 3; i++)
       {
            this->m_pixels[i] = clone.m_pixels[i];
       }
    }


    /*!
     * @param source The object we are copying information from.
     * @return A reference to the `this` object.
     */
    Canvas& Canvas::operator=( const Canvas & source )
    {
        delete [] m_pixels;

        this->m_width = source.m_width;
        this->m_height = source.m_height;
        this->m_line_thikness = source.m_line_thikness;

        m_pixels = new component_t [ m_height * m_width * 3 ];

        std::memmove(m_pixels, source.m_pixels, m_height * m_width * 3);

        return *this;
    }

    void Canvas::clear( const Color& color )
    {
        for(size_t i{0}; i < m_height * m_width * 3; i++)
        {
            m_pixels[i] = color.channels[0];
            m_pixels[++i] = color.channels[1];
            m_pixels[++i] = color.channels[2];
        }
    }

    /*!
     * @throw `std::invalid_argument()` it the pixel coordinate is located outside the canvas.
     * @param p The 2D coordinate of the pixel we want to know the color of.
     * @return The pixel color.
     */
    Color Canvas::pixel( coord_type x, coord_type y ) const
    {
        if(x >= m_width or y >= m_height or x < 0 or y < 0)
        {
            throw std::invalid_argument("Coordenadas fora da imagem");
        }

        auto R = m_pixels[(y*3*m_width) + x*3];
        auto G = m_pixels[(y*3*m_width) + (x*3) + 1];
        auto B = m_pixels[(y*3*m_width) + (x*3) + 2];

        return Color(R,G,B);
    }

    /*!
     * @note Nothing is done if the  pixel coordinate is located outside the canvas.
     * @param p The 2D coordinate of the pixel we want to change the color.
     * @param c The color.
     */
    void Canvas::pixel( coord_type x, coord_type y, const Color& c )
    {
        if(x >= m_width or y >= m_height or x < 0 or y < 0)
        {
            //Nothing  
        }
        else
        {
            m_pixels[(y*3*m_width) + x*3] = c.channels[0];
            m_pixels[(y*3*m_width) + (x*3) + 1] = c.channels[1];
            m_pixels[(y*3*m_width) + (x*3) + 2] = c.channels[2];
        }
    }


    /*!
     * Draws on the canvas a horizontal line.
     * @param p The 2D coordinate of the initial pixel of the line.
     * @param length The horizontal length of the line in pixels.
     */
    void Canvas::hline( coord_type x, coord_type y, size_t length, const Color& color )
    {
        for(size_t i{0}; i < length; i++)
        {   
            auto num = y;

            for(size_t j{1}; j <= m_line_thikness; j++)
            {
                auto origin = (num*3*m_width) + (x*3);

                //std::cout<<"Valor de X e Y e origin "<<x<<" "<<y<<" "<<origin<<std::endl;

                m_pixels[origin] = color.channels[0];
                m_pixels[origin+1] = color.channels[1];
                m_pixels[origin+2] = color.channels[2];
            
                num++;
            }

            x++;
        }
    }

    /*!
     * Draws on the canvas a vertical line.
     * @param p The 2D coordinate of the initial pixel of the line.
     * @param length The vertical length of the line in pixels.
     */
    void Canvas::vline( coord_type x, coord_type y, size_t length, const Color& color )
    {
        for(size_t i{0}; i < length; i++)
        {
            auto num = x;

            for(size_t j{1}; j <= m_line_thikness; j++)
            {
                auto origin = (y*3*m_width) + (num*3);

                //std::cout<<"Valor de Y e origin "<<y<<" "<<origin<<std::endl;

                m_pixels[origin] = color.channels[0];
                m_pixels[origin+1] = color.channels[1];
                m_pixels[origin+2] = color.channels[2];

                num++;
            }

            y++;
        }
    }

    /*!
     * Draws on the canvas a filled box. The origin of the box is the top-left corner.
     * The box is compose of horizontal lines, drawn top to bottom.
     * @param p The 2D coordinate of the initial pixel of the box (top-left corner).
     * @param width The box's width in pixels.
     * @param height The box's heigth in pixels.
     */
    void Canvas::box( coord_type x, coord_type y, size_t width, size_t height , const Color& color)
    {
        for(size_t i{0}; i < height; i++)
        {
            hline(x,y+i, width, color);
        }
    }
}

//================================[ canvas.cpp ]================================//
