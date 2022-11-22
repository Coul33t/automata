//
// Created by couland-q on 22/11/22.
//

#include "../include/colours.hpp"

namespace Colours {
    Uint32 getColour(const Window& window, const std::vector<int>& rgb) {
        return SDL_MapRGB(window.m_screen_surface->format, rgb[0], rgb[1], rgb[2]);
    }
}