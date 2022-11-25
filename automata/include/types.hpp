//
// Created by couland-q on 22/11/22.
//

#ifndef AUTOMATA_TYPES_HPP
#define AUTOMATA_TYPES_HPP

#include <cstddef> // size_t

#define Colour std::vector<int>

struct Size {
    int w, h;

    Size() {
        w = 0;
        h = 0;
    }

    Size(int w, int h) {
        this->w = w;
        this->h = h;
    }
};

struct Coord {
    int x, y;

    Coord() {
        x = 0;
        y = 0;
    }

    Coord(int x, int y) {
        this->x = x;
        this->y = y;
    }
};
#endif //AUTOMATA_TYPES_HPP
