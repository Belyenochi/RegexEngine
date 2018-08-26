//
// Created by jason on 18-8-23.
//

#ifndef REGULARENGINE_DFA_H
#define REGULARENGINE_DFA_H

#include <iostream>
#include <string>
class StateTranRule {
public:
    string state;
    string character;
    string next_state;
    StateTranRule(string state,string character,state next_state);
    ~StateTranRule();
    bool appliesTo(string state, string character);
    string follow();
    string toString();
private:

};
StateTranRule::StateTranRule(string state,string character,state next_state) {
    this->state = state;
    this->character = character;
    this->next_state = next_state;
}
StateTranRule::~StateTranRule() {
    std::cout << "状态转移方程对象析构ing..." << endl;
}
bool StateTranRule::appliesTo(string state, string character) {
    return this.state == state && this->character == character;
}

string StateTranRule::follow() {
    return this->next_state;
}

string StateTranRule::toString() {
    return "#<FARule> " + this.state + "-- "  + this._character + " "
}




class DFA {
    constructor(current_state, accept_states, rulebook) {
        this._current_state = current_state
        this._accept_states = accept_states
        this._rulebook = rulebook
    }

    accepting() {
        return this._accept_states.indexOf(this.current_state) != -1
    }

    read_character(character, save_current_state) {
        let next_state = this._rulebook.next_state(this.current_state, character)

        this.current_state = (next_state === false ? save_current_state : next_state)
    }

    read_string(string) {
            let save_current_state,read_string = Array.from(string)
            save_current_state = this._current_state

            read_string.forEach((item) => {
                this.read_character(item, save_current_state)
            })

            this._current_state === false ? save_current_state : this._current_state
    }
}

class DFADesign {
    constructor(start_state, accept_states, rulebook) {
        this._start_state = start_state
        this._accept_states = accept_states
        this._rulebook = rulebook
    }

    to_dfa() {
        return new DFA(this._start_state, this._accept_states, this._rulebook)
    }

    accepts(string) {
            let dfa = this.to_dfa()
            dfa.read_string(string)


            return dfa.accepting()
    }
}

var rulebook = new DFARulebook([
new FARule(1, 'a', 2),	new FARule(1, 'b', 1),
new FARule(2, 'a', 2),	new FARule(2, 'b', 3),
new FARule(3, 'a', 3),	new FARule(3, 'b', 3),
])

//rulebook.next_state(1, 'a')

dfa_design = new DFADesign(1, [3], rulebook)

dfa_design.accepts('cc')




#endif //REGULARENGINE_DFA_H
