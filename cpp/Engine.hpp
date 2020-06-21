//
// Created by alexandre on 20.06.20.
//

#ifndef MEDIUM_ENGINE_HPP
#define MEDIUM_ENGINE_HPP

#include "AbstractButton.hpp"
#include <vector>
#include <iostream>

namespace GUI {
    class Engine {
    public:
        Engine();

        void registerButton(AbstractButton *button);

        void click();

    private:
        std::vector<AbstractButton *> buttons;
    };
}

#endif //MEDIUM_ENGINE_HPP
