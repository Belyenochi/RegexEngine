//
// Created by jason on 18-8-26.
//
#include "RegexParser.h"
#include <string>
#include "Empty.hpp"
#include "Choose.hpp"
#include "Concatenation.hpp"
#include "Primitive.hpp"
#include "Reptition.hpp"
using  namespace std;
// <regex> ::= <term> '|' <regex>
//             |  <term>

// <term> ::= { <factor> }

// <factor> ::= <base> { '*' }

// <base> ::= <char>
//        |  '\' <char>
//        |  '(' <regex> ')'

RegexParse::RegexParse(vector<char>* input) {
    this->input = input;
}

Regex* RegexParse::parse() {
    return this->compilerRegex();
}

Regex* RegexParse::compilerRegex() {
    Regex *term = this->compilerTerm(),*regex;

    if (!this->more() && this->peek() == '|') {
        this->eat ('|') ;
        regex = this->compilerRegex();

        return new Choose(term,regex);
    } else {
        return term ;
    }
}

Regex* RegexParse:: compilerTerm() {
    Regex *factor,*nextFactor;

    factor = this->compilerFactor();

    while (!this->more() && this->peek() != ')' && this->peek() != '|') {
        nextFactor = this->compilerFactor();
        factor = new Concatenation(factor,nextFactor);
    }

    return factor ;
}

Regex* RegexParse::compilerFactor() {
    Regex *base = this->compilerBase();

    while (!this->more() && this->peek() == '*') {
        this->eat('*');
        base = new Reptition(base);
    }

    return base ;
}

Regex* RegexParse::compilerBase() {
    switch (this->peek()) {
        case '(': {
            this->eat('(');
            Regex *r = this->compilerRegex();
            this->eat(')');
            return r;
        }
        case '\\': {
            this->eat ('\\') ;
            char esc = this->next();
            return new Primitive(esc);
        }
        default:
            return new Primitive(this->next());
    }
}

char RegexParse::peek() {
    return input->at(0);
}

void RegexParse::eat(char c) {
    string msg ;

    if (this->peek() == c)
        input->erase(input->begin());
    else {
        msg += "Expected: ";
        msg += c;
        msg += "; got: ";
        msg += this->peek();
        throw msg;
    }
}

char RegexParse::next() {
    char c = this->peek();
    eat(c);
    return c;
}

bool RegexParse::more() {
    return input->empty();
}

