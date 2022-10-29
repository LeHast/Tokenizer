
#include <iostream>
#include "Tokenizer.hpp"

JSONTokenizer::JSONTokenizer(const std::string &inputFile): inputFileName{inputFile} {
    inputStream.open(inputFile, std::ios::in);
}

bool JSONTokenizer::isOpenBrace(char c) {
    return c == '{';
}

bool JSONTokenizer::isCloseBrace(char c)
{
    return c == '}';
}

bool JSONTokenizer::isOpenBracket(char c)
{
    return c == '[';
}

bool JSONTokenizer::isCloseBracket(char c)
{
    return c == ']';
}

bool JSONTokenizer::isEndLine(char c)
{
    return c != ',' && c != '}';
}

/* Gets a character from the input file to add the to the token
*  @return the token added.
*/
JSONToken JSONTokenizer::getToken() {
    if(!inputStream.is_open()) {
        std::cout << "Input stream in Tokenizer::getToken is not open. Terminating...\n";
        exit(4);
    }

    char c;
    inputStream >> c;

    if (isOpenBrace(c)) {
        JSONToken token;
        token.makeOpenBrace(c);
        return token;
    }

    if (isCloseBrace(c)) {
        JSONToken token;
        token.makeCloseBrace(c);
        return token;
    }

    if (isOpenBracket(c)) {
        JSONToken token;
        token.makeOpenBracket(c);
        return token;
    }

    if (isCloseBracket(c)) {
        JSONToken token;
        token.makeCloseBracket(c);
        return token;
    }

    //colon : 
    if (c == ':') {
        JSONToken token;
        token.makeColon(c);
        return token;
    }


    //comma , 
    if (c == ',') {
        JSONToken token;
        token.makeComma(c);
        return token;
    }

    //number
    if (isdigit(c) || c == '-') {
        std::string str;
        while (isEndLine(c)) {
            str += c;
            inputStream >> c;
        }
        inputStream.putback(c);
        JSONToken token;
        double temp = std::stod(str);
        token.makeNumber(temp);
        return token;
    }
    
    //string
    if (c == '"') {
        std::string str;
        inputStream >> c >> std::noskipws;
        while (c != '"') {
            str += c;
            inputStream >> c;
        }
        JSONToken token;
        token.makeString(str);
        inputStream >> std::skipws;
        return token;
    }
    std::cout << "Unexpected character in input ->" << c << "<-\n";
    std::cout << "Terminating...\n";
    exit(5);
}