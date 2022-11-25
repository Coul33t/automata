//
// Created by couland-q on 22/11/22.
//

#include "../include/automata.hpp"

Automata::Automata() {
    grid.init(20, 10, 2);
    grid.m_cell_size = 5;
}

Automata::Automata(int w, int h, int cell_size, int nb_states) {
    grid.init(w, h, nb_states);
    grid.m_cell_size = cell_size;
}

Automata::~Automata() {

}

void Automata::setGridSize(int w, int h) {
    grid.reset(2, w, h);
}

std::vector<Coord> Automata::getNeighbours(int x, int y) {
    std::vector<Coord> neighbours;

    for (int i = -1; i < 2; i++) {
        for (int j = -1; j < 2; j++) {
            // Skip current cell
            if (i != 0 || j != 0) {
                Coord new_neighbour;

                new_neighbour.x = x + j;

                if (new_neighbour.x < 0) {
                    new_neighbour.x = grid.m_size.w - 1;
                }

                else if (new_neighbour.x >= grid.m_size.w) {
                    new_neighbour.x = 0;
                }

                new_neighbour.y = y + i;

                if (new_neighbour.y < 0) {
                    new_neighbour.y = grid.m_size.h - 1;
                }

                else if (new_neighbour.y >= grid.m_size.h) {
                    new_neighbour.y = 0;
                }

                neighbours.push_back(new_neighbour);
            }
        }
    }

    return neighbours;
}

int Automata::sumNeighbours(const std::vector<Coord>& neighbours) {
    int sum = 0;

    for (auto& coord: neighbours) {
        sum += grid.m_cells[coord.x][coord.y].m_state;
    }

    return sum;
}

int Automata::secondMajorityWins(const std::vector<Coord>& neighbours) {
    std::vector<int> states_count(nb_states, 0);

    for (auto& neighbour: neighbours) {
        states_count[grid.m_cells[neighbour.y][neighbour.x].m_state]++;
    }

    int idx = -1;
    int max_val = -1;

    // Max value
    *(std::max_element(states_count.begin(), states_count.end())) = -1;

    for (size_t i = 0; i < states_count.size(); i++) {
        if (states_count[i] > -1 && states_count[i] > max_val) {
            idx = i;
            max_val = states_count[i];
        }
    }

    return idx;
}

int Automata::firstMajorityWins(const std::vector<Coord>& neighbours) {
    std::vector<int> states_count(nb_states, 0);

    for (auto& neighbour: neighbours) {
        states_count[grid.m_cells[neighbour.y][neighbour.x].m_state]++;
    }

    int idx = -1;
    int max_val = -1;

    for (size_t i = 0; i < states_count.size(); i++) {
        if (states_count[i] > max_val) {
            idx = i;
            max_val = states_count[i];
        }
    }

    return idx;
}

int Automata::gameOfLife(int state, const std::vector<Coord>& neighbours) {
    for (auto& neighbour: neighbours) {
        int sum = sumNeighbours(neighbours);

        if (state == 0 && sum == 3) {
            return 1;
        }

        if (state == 1 && sum == 2 || sum == 3) {
            return 1;
        }

        else {
            return 0;
        }
    }

    return 0;
}

void Automata::oneStep() {
    std::vector<std::vector<int>> temp_grid = grid.getStatesCopy();

    for (size_t i = 0; i < grid.m_size.h; i++) {
        for (size_t j = 0; j < grid.m_size.w; j++) {
            //temp_grid[i][j] = secondMajorityWins(getNeighbours(j, i));
            temp_grid[i][j] = gameOfLife(temp_grid[i][j], getNeighbours(i, j));
        }
    }

    grid.setStates(temp_grid);
}