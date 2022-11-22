//
// Created by couland-q on 22/11/22.
//

#ifndef AUTOMATA_AUTOMATA_HPP
#define AUTOMATA_AUTOMATA_HPP

#include "grid.hpp"

class Automata {
public:
    Automata();
    Automata(int w, int h, int cell_size);
    ~Automata();

    void one_step();

    Grid grid;

    bool periodicity = false;
};
#endif //AUTOMATA_AUTOMATA_HPP
