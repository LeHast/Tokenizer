
#include <iostream>
#include <iomanip>
#include "Token.hpp"

/* Print the character into the token.
*/
void JSONToken::print() {
    // [ ]
    if (isOpenBrace()) {
        std::cout << getOpenBrace() << std::endl;
    }
    else if (isCloseBrace()) {
        std::cout << getCloseBrace() << std::endl;
    }
    // { }
    else if (isOpenBracket()) {
        std::cout << getOpenBracket() << std::endl;
    }
    else if (isCloseBracket()) {
        std::cout << getCloseBracket() << std::endl;
    }
    // String
    else if (isString()) {
        std::cout << getString() << std::endl;
    }
    // :
    else if (isColon()) {
        std::cout << getColon() << std::endl;
    }
    // Number
    else if (isNumber()) {
        std::cout << std::setprecision(16) << getNumber() << std::endl;
    }
    // ,
    else if (isComma()) {
        std::cout << getComma() << std::endl;
    }
    else if (" ") {
        std::cout << getComma() << std::endl;
    }
    else {
        std::cout << "Unknown token.";
    }

}