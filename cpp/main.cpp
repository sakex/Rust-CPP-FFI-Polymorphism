//
// Created by alexandre on 20.06.20.
//

#include "Engine.hpp"
#include "CounterButton.hpp"

int main() {
    GUI::Engine engine;
    auto * button = new CounterButton();
    engine.registerButton(button);
    engine.click();
    return 0;
}