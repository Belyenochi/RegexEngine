//
// Created by jason on 18-8-26.
//

#ifndef REGULARENGINE_REPTITION_H
#define REGULARENGINE_REPTITION_H

#include "Regex.hpp"

class Reptition: public Regex {
private:
    Regex *internal;

public:
    Reptition(Regex *internal) {
        this->internal = internal ;
    }
    void toNFA() {

    }
};


#endif //REGULARENGINE_REPTITION_H
