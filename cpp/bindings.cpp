//
// Created by alexandre on 21.06.20.
//

#include "bindings.hpp"

ButtonBindingConcrete::ButtonBindingConcrete(AbstractButtonBinding *_binding) : binding{_binding} {
}

void ButtonBindingConcrete::click() {
    (*binding->click)(binding->context);
}

std::string ButtonBindingConcrete::innerText() {
    char const *text = (*binding->inner_text)(binding->context);
    return std::string(text);
}

GUI::Engine *engine_factory() {
    return new GUI::Engine();
}

ButtonBindingConcrete::~ButtonBindingConcrete()  {
    delete binding;
}

void register_button(GUI::Engine *engine, AbstractButtonBinding *button) {
    auto *concrete = new ButtonBindingConcrete(button);
    engine->registerButton(concrete);
};

void click(GUI::Engine* engine){
    engine->click();
}