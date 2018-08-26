//
// Created by jason on 18-8-26.
//
#include "RegexParser.h"
#include "Regex.hpp"
#include <iostream>
#include <string>

int main() {
    RegexParse *regex;
    Regex *re;
    vector<char> s;
    vector<char> *inputVector = &s;
    char c;
    string input;

    cin >> input;
    for (int i = 0; i < input.length(); ++i) {
        inputVector->push_back(input[i]);
    }
    regex = new RegexParse(inputVector);
    re = regex->parse();

    return 0;
}
