//
// Created by couland-q on 22/11/22.
//

#ifndef AUTOMATA_AUTOMATA_HPP
#define AUTOMATA_AUTOMATA_HPP

#include "grid.hpp"

class Automata {
public:
    Automata();
    Automata(int w, int h, int cell_size, int nb_states);
    ~Automata();

    void setGridSize(int w, int h);

    std::vector<Coord> getNeighbours(int x, int y);
    int sumNeighbours(const std::vector<Coord>& neighbours);

    int firstMajorityWins(const std::vector<Coord>& neighbours);
    int secondMajorityWins(const std::vector<Coord>& neighbours);
    int gameOfLife(int state, const std::vector<Coord>& neighbours);

    void oneStep();

    Grid grid;

    bool periodicity = true;
    int nb_states = 2;
};
#endif //AUTOMATA_AUTOMATA_HPP
