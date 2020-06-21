//
// Created by alexandre on 20.06.20.
//

#ifndef MEDIUM_COUNTERBUTTON_HPP
#define MEDIUM_COUNTERBUTTON_HPP

#include "AbstractButton.hpp"

class CounterButton: public AbstractButton {
public:
    CounterButton(): count(0) {
    }

    void click() override {
        count++;
    }

    std::string innerText() override {
        return "Count: " + std::to_string(count);
    }

private:
    int count;
};

#endif //MEDIUM_COUNTERBUTTON_HPP
