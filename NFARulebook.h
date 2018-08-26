//
// Created by jason on 18-8-25.
//
#include <vector>
#include <iostream>

using namespace std;

template<class type>
class NFARulebook {
public:
    NFARulebook(vector<type> rules) {
        this->rules = rules;
    }
    ~NFARulebook() {
        cout << "delete NFARulebook..." << endl;
    }
    NextStates(vector<type> states,string character) {
        
    }
private:
    vector<type> rules;
};