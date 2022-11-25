//
// Created by couland-q on 22/11/22.
//

#ifndef AUTOMATA_WINDOW_HPP
#define AUTOMATA_WINDOW_HPP

#include <iostream>
#include <SDL.h>

#include "types.hpp"
#include "grid.hpp"
#include "colours.hpp"

enum Shape {rect};

class Window {
public:
    Window();
    Window(int w, int h);
    ~Window();

    bool init(int w = -1, int = -1);

    void drawShape(const Shape& shape, const Colour& col);
    void drawBackground();
    void drawGrid(const Grid& grid);

    void setRenderDrawColor(const Colour& col);

    //The window we'll be rendering to
    SDL_Window* m_window = nullptr;

    //The surface contained by the window
    SDL_Surface* m_screen_surface = nullptr;

    //The window renderer
    SDL_Renderer* m_renderer = nullptr;

    Size m_window_size;
};
#endif //AUTOMATA_WINDOW_HPP
