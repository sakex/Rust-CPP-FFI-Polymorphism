//
// Created by alexandre on 21.06.20.
//

#include "Engine.hpp"

namespace GUI {
    Engine::Engine() : buttons() {

    }

    void Engine::registerButton(AbstractButton *button) {
        buttons.push_back(button);
    }

    void Engine::click() {
        for (auto *b: buttons) {
            b->click();
            std::cout << b->innerText() << std::endl;
        }
    }
}