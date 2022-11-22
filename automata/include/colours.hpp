//
// Created by couland-q on 22/11/22.
//

#ifndef AUTOMATA_COLOURS_H
#define AUTOMATA_COLOURS_H

#include <vector>
#include <map>
#include <string>
#include <SDL.h>
#include "window.hpp"
#include "types.hpp"

namespace Colours {
    inline colour black = {0, 0, 0};
    inline colour white = {255, 255, 255};
    inline colour red = {255, 0, 0};
    inline colour green = {0, 255, 0};
    inline colour blue = {0, 0, 255};
    inline colour yellow = {255, 255, 0};

    Uint32 getColour(const Window& window, const std::vector<int>& rgb);
}

#endif //AUTOMATA_COLOURS_H
