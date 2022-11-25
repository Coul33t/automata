//
// Created by couland-q on 22/11/22.
//

#ifndef AUTOMATA_COLOURS_H
#define AUTOMATA_COLOURS_H

#include <vector>
#include <map>
#include <string>
#include <SDL.h>
#include "types.hpp"

namespace Colours {
    inline Colour black         = {  0,   0,   0};
    inline Colour white         = {255, 255, 255};
    inline Colour red           = {255,   0,   0};
    inline Colour green         = {  0, 255,   0};
    inline Colour blue          = {  0,   0, 255};
    inline Colour yellow        = {255, 255,   0};

    inline Colour cream         = {254, 251, 234};
    inline Colour coral         = {255, 127,  80};
    inline Colour orange        = {255, 165,   0};
    inline Colour lightskyblue  = {135, 206, 250};
    Uint32 getColour(SDL_PixelFormat* format, const std::vector<int>& rgb);
    Colour getGreyFromState(int state, int max_state);
}

#endif //AUTOMATA_COLOURS_H
