//
// Created by couland-q on 22/11/22.
//

#include "../include/grid.hpp"

Grid::Grid(int w, int h) {
    m_size.w = w;
    m_size.h = h;

    m_tiles.reserve(h);
    for (size_t i = 0; i < h; i++) {
        m_tiles[i].resize(w);
    }
}

Grid::~Grid() {

}

void Grid::init(int w, int h) {
    m_size.w = w;
    m_size. h= h;

    for (size_t i = 0; i < m_size.h; i++) {

        m_tiles.emplace_back(std::vector<Tile>{});

        for (size_t j = 0; j < m_size.w; j++) {
            m_tiles[i].emplace_back(Tile());
        }
    }
}

void Grid::reset(int w, int h) {
    if (w == -1 && h == -1) {
        init(m_size.w, m_size.h);
    }

    else {
        m_tiles.clear();
        m_tiles.resize(h);

        for (size_t i = 0; i < h; i++) {
            m_tiles[i].clear();
            m_tiles[i].resize(w);

            for (size_t j = 0; j < m_size.w; j++) {
                m_tiles[i].emplace_back(Tile());
            }
        }
    }
}

void Grid::setRandomState() {
    for (auto& row: m_tiles) {
        for (auto& tile: row) {

        }
    }
}
