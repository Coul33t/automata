//
// Created by couland-q on 22/11/22.
//

#ifndef AUTOMATA_ENGINE_HPP
#define AUTOMATA_ENGINE_HPP

#include "window.hpp"
#include "automata.hpp"
#include "colours.hpp"

class Engine {
public:
    Engine();
    ~Engine();

    bool init(int window_w, int window_h);
    void run();

    Window m_window;
    Automata m_automata;
    float fps_max = 30.0;
};
#endif //AUTOMATA_ENGINE_HPP
