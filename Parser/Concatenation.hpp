//
// Created by jason on 18-8-26.
//

#ifndef REGULARENGINE_CONCATENATION_H
#define REGULARENGINE_CONCATENATION_H

#include "Regex.hpp"

class Concatenation: public Regex {
private:
    Regex *first,*second;
public:
    Concatenation (Regex *first, Regex *second) {
        this->first = first;
        this->second = second;
    }
    void toNFA() {

    }
};


#endif //REGULARENGINE_CONCATENATION_H
