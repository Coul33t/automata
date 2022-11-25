//
// Created by couland-q on 22/11/22.
//

#include "../include/colours.hpp"

namespace Colours {
    Uint32 getColour(SDL_PixelFormat* format, const std::vector<int>& rgb) {
        return SDL_MapRGB(format, rgb[0], rgb[1], rgb[2]);
    }

    Colour getGreyFromState(int state, int max_state) {
        float factor = static_cast<float>(state) / static_cast<float>(max_state);
        return Colour{static_cast<int>(255 * factor), static_cast<int>(255 * factor), static_cast<int>(255 * factor)};
    }
}