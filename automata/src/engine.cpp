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

    m_automata.setGridSize(100, 100);
    m_automata.grid.m_cell_size = 5;

    return true;
}

void Engine::run() {
    //Fill the surface white
    SDL_FillRect(m_window.m_screen_surface, nullptr, Colours::getColour(m_window.m_screen_surface->format,
                                                                        Colours::blue));

    //Update the surface
    SDL_UpdateWindowSurface(m_window.m_window);

    Uint32 beg_loop, end_loop, elapsed_time;
    elapsed_time = 0;
    fps_max = 15;

    bool quit = false;
    SDL_Event e;

    while (!quit) {

        beg_loop = SDL_GetTicks();

        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        end_loop = SDL_GetTicks();

        elapsed_time += end_loop - beg_loop;

        // Update
        if(elapsed_time > (1.0f / fps_max) * 1000) {
            m_window.drawBackground();
            SDL_RenderClear(m_window.m_renderer);
            m_window.drawGrid(m_automata.grid);
            SDL_RenderPresent(m_window.m_renderer);

            m_automata.oneStep();
            elapsed_time -= (1.0f / fps_max) * 1000;
        }
    }
}