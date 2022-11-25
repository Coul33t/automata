//
// Created by couland-q on 22/11/22.
//

#ifndef AUTOMATA_CELL_HPP
#define AUTOMATA_CELL_HPP

class Cell {
public:
    Cell();
    explicit Cell(int state);
    ~Cell();

    int m_state;
};
#endif //AUTOMATA_CELL_HPP
