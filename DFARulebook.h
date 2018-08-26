//
// Created by jason on 18-8-23.
//

#ifndef REGULARENGINE_DFARULEBOOK_H
#define REGULARENGINE_DFARULEBOOK_H

#include <iostream>
#include <string>
class DFARulebook {
public:
    string rules;
    DFARulebook();
    ~DFARulebook();
    bool next_state();

private:
};

class DFARulebook {
    constructor(rules) {
            this._rules = rules
    }

    next_state(state, character) {
        let rule = this.rule_for(state, character)

        return rule ? rule.follow() : false
    }

    rule_for(state, character) {

        let findNextState = this._rules.find((rule) => {
                return rule.appliesTo(state, character)
        })

        return findNextState !==  undefined ? findNextState : false
    }
}

#endif //REGULARENGINE_DFARULEBOOK_H
