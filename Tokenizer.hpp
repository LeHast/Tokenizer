
#ifndef EXPRESSIONEVALUATOR_LAB04_TOKENIZER_HPP
#define EXPRESSIONEVALUATOR_LAB04_TOKENIZER_HPP
#include <string>
#include <fstream>

#include "Token.hpp"

class JSONTokenizer {
public:
    explicit JSONTokenizer(const std::string &inputFile);

    JSONToken getToken();

private:
    std::string inputFileName;
    std::fstream inputStream;

    static bool isOpenBrace(char c);
    static bool isCloseBrace(char c);
    static bool isOpenBracket(char c);
    static bool isCloseBracket(char c);
    static bool isEndLine(char c);

};


#endif //EXPRESSIONEVALUATOR_LAB04_TOKENIZER_HPP
