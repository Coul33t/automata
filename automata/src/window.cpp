//
// Created by couland-q on 22/11/22.
//

#include "../include/window.hpp"

Window::Window() {

}

Window::Window(int w, int h) {
    m_window_size.w = w;
    m_window_size.h = h;
}

Window::~Window() {
    //Destroy window
    SDL_DestroyWindow(m_window);

    //Quit SDL subsystems
    SDL_Quit();
}

bool Window::init(int w, int h) {

    if (w <= 0 && h <= 0 && m_window_size.w <= 0 && m_window_size.h <= 0) {
        std::cout << "[WARNING] both m_window_size and size parameters are all <= 0." << std::endl;
    }

    //Initialize SDL
    if(SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cout << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if (w > 0 && h > 0) {
        m_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    w, h, SDL_WINDOW_SHOWN);
    }

    else {
        m_window = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
                                    m_window_size.w, m_window_size.h, SDL_WINDOW_SHOWN);
    }

    if(m_window == nullptr) {
        std::cout << "Window could not be created! SDL_Error: " << SDL_GetError() << std::endl;
        return false;
    }

    m_screen_surface = SDL_GetWindowSurface(m_window);

    return true;
}

void Window::drawShape(const Shape& shape, const colour& col) {
    if (shape == Shape::rect) {
        SDL_FillRect(m_screen_surface, nullptr, Colours::getColour(*m_window, col));
    }
}

void Window::drawGrid(const Grid& grid) {
    for (size_t i = 0; i < grid.m_tiles.size(); i++) {
        for (size_t j = 0; j < grid.m_tiles[i].size(); j++) {

        }
    }
}