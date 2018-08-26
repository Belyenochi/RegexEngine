//
// Created by jason on 18-8-26.
//

#ifndef REGULARENGINE_PRIMITIVE_H
#define REGULARENGINE_PRIMITIVE_H

#include "Regex.hpp"
class Primitive : public Regex {
private:
    char c;

public:
    Primitive(char c) {
        this->c = c;
    }
    void toNFA() {

    }
};
#endif //REGULARENGINE_PRIMITIVE_H
