#ifndef GRID_HPP
#define GRID_HPP

#include <vector>
#include <map>

#include "../../extlib/random/random.hpp"

#include "tile.hpp"
#include "types.hpp"

class Grid {
public:
    explicit Grid(int w = 20, int h = 10);
    ~Grid();

    void init(int w, int h);
    void reset(int w = 1, int h = 1);
    void setRandomState();

    int compute_state(int x, int y);

    std::vector<std::vector<Tile>> m_tiles;
    Size m_size;
    size_t m_cell_size;
    std::map<int, colour> colours_association;
};
#endif