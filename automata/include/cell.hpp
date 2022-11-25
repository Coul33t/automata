//
// Created by couland-q on 22/11/22.
//

#ifndef AUTOMATA_TILE_HPP
#define AUTOMATA_TILE_HPP

class Tile {
public:
    Tile();
    explicit Tile(int state);
    ~Tile();

    int m_state;
};
#endif //AUTOMATA_TILE_HPP
