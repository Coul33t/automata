//
// Created by couland-q on 22/11/22.
//

#include "../include/engine.hpp"

Engine::Engine() {

}

Engine::~Engine() {

}

bool Engine::init(int window_w, int window_h) {
    if (!m_window.init(window_w, window_h)) {
        std::cout << "[ERROR] Window couldn't be initialised." << std::endl;
        return false;
    }

    return true;
}

void Engine::run() {
    //Fill the surface white
    SDL_FillRect(m_window.m_screen_surface, nullptr, Colours::getColour(m_window, Colours::blue));

    //Update the surface
    SDL_UpdateWindowSurface(m_window.m_window);

    //Hack to get window to stay up
    SDL_Event e;
    bool quit = false;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        m_automata.one_step();
    }
}