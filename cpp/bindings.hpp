//
// Created by alexandre on 20.06.20.
//

#ifndef MEDIUM_BINDINGS_HPP
#define MEDIUM_BINDINGS_HPP

#include "Engine.hpp"

// Snake case for Rust

struct AbstractButtonBinding;



extern "C" {
struct AbstractButtonBinding {
    void (*click)(void *cont);

    char const *(*inner_text)(void *cont);

    void *context;
};

}

class ButtonBindingConcrete : public AbstractButton {
public:
    explicit ButtonBindingConcrete(AbstractButtonBinding *_binding);

    ~ButtonBindingConcrete();

    void click() override;

    std::string innerText() override;


private:
    AbstractButtonBinding *binding;
};

extern "C" GUI::Engine *engine_factory();

extern "C" void register_button(GUI::Engine *engine, AbstractButtonBinding *button);

extern "C" void click(GUI::Engine *engine);


#endif //MEDIUM_BINDINGS_HPP
