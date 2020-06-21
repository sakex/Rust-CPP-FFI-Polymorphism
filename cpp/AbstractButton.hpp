//
// Created by alexandre on 20.06.20.
//

#ifndef MEDIUM_ABSTRACT_BUTTON_H
#define MEDIUM_ABSTRACT_BUTTON_H

#include <string>

class AbstractButton {
public:
    virtual void click() = 0;
    virtual std::string innerText() = 0;
};


#endif //MEDIUM_ABSTRACT_BUTTON_H
