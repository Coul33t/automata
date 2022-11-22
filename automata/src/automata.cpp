//
// Created by couland-q on 22/11/22.
//

#include "../include/automata.hpp"

Automata::Automata() {
    grid.init(20, 20);
    grid.m_cell_size = 5;
}

Automata::Automata(int w, int h, int cell_size) {
    grid.init(w, h);
    grid.m_cell_size = cell_size;
}

Automata::~Automata() {

}

void Automata::one_step() {

}