//
// Created by jason on 18-8-26.
//

#ifndef REGULARENGINE_CHOOSE_H
#define REGULARENGINE_CHOOSE_H

#include "Regex.hpp"

class Choose :public Regex {
private :
    Regex *thisOne,*thatOne;

public:
    Choose (Regex* thisOne, Regex* thatOne) {
        this->thisOne = thisOne;
        this->thatOne = thatOne;
    }
    void toNFA() {

    }
};
#endif //REGULARENGINE_CHOOSE_H
