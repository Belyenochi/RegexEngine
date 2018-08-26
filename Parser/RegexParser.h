//
// Created by jason on 18-8-26.
//

#ifndef REGULARENGINE_REGEXPARSER_H
#define REGULARENGINE_REGEXPARSER_H

#include "Regex.hpp"
#include <vector>
using namespace std;
// <regex> ::= <term> '|' <regex>
//             |  <term>

// <term> ::= { <factor> }

// <factor> ::= <base> { '*' }

// <base> ::= <char>
//        |  '\' <char>
//        |  '(' <regex> ')'

class RegexParse {
private:
    vector<char>* input;
public:
    RegexParse(vector<char>* input);

    Regex* parse();

    Regex* compilerRegex();

    Regex* compilerTerm();

    Regex* compilerFactor();

    Regex* compilerBase();

    char peek();

    void eat(char c);

    char next();

    bool more();
};



#endif //REGULARENGINE_REGEXPARSER_H
