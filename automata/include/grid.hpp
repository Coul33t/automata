#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <map>

#include "../../extlib/random/random.hpp"

#include "cell.hpp"
#include "types.hpp"
#include "tools.hpp"

#include <iostream>

class Grid {
public:
    explicit Grid(int w = 20, int h = 10);
    ~Grid();

    void init(int w, int h, int nb_states);
    void reset(int nb_states, int w = 1, int h = 1);
    void setRandomState(int nb_states);

    std::vector<std::vector<int>> getStatesCopy();
    void setStates(std::vector<std::vector<int>> new_states);

    int compute_state(int x, int y);

    std::vector<std::vector<Cell>> m_cells;
    Size m_size;
    size_t m_cell_size;
    std::map<int, Colour> colours_association;
};
#endif