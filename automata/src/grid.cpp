//
// Created by couland-q on 22/11/22.
//

#include "../include/grid.hpp"

Grid::Grid(int w, int h) {
    m_size.w = w;
    m_size.h = h;
}

Grid::~Grid() {

}

void Grid::init(int w, int h, int nb_states) {
    m_size.w = w;
    m_size.h = h;

    for (size_t i = 0; i < m_size.h; i++) {
        m_cells.emplace_back(std::vector<Cell>{});

        for (size_t j = 0; j < m_size.w; j++) {
            m_cells[i].emplace_back(Cell(Random::get_int(0, nb_states - 1)));
        }
    }
}

void Grid::reset(int nb_states, int w, int h) {
    if (w == -1 && h == -1) {
        init(m_size.w, m_size.h, nb_states);
    }

    else {
        m_size.w = w;
        m_size.h = h;

        m_cells.clear();

        for (size_t i = 0; i < h; i++) {
            m_cells.emplace_back(std::vector<Cell>{});

            for (size_t j = 0; j < w; j++) {
                m_cells[i].emplace_back(Cell(Random::get_int(0, nb_states - 1)));
            }
        }
    }
}

void Grid::setRandomState(int nb_states) {
    for (auto& row: m_cells) {
        for (auto& tile: row) {
            tile.m_state = Random::get_int(0, nb_states - 1);
        }
    }
}

std::vector<std::vector<int>> Grid::getStatesCopy() {
    std::vector<std::vector<int>> states;

    for (size_t i = 0; i < m_cells.size(); i++) {
        states.emplace_back(std::vector<int>(m_cells[i].size(), -1));

        for (size_t j = 0; j < m_cells[i].size(); j++) {
            states[i][j] = m_cells[i][j].m_state;
        }
    }

    return states;
}

void Grid::setStates(std::vector<std::vector<int>> new_states) {
    for (size_t i = 0; i < new_states.size(); i++) {
        for (size_t j = 0; j < new_states[i].size(); j++) {
            m_cells[i][j].m_state = new_states[i][j];
        }
    }
}