
#ifndef EXPRESSIONEVALUATOR_LAB04_TOKEN_HPP
#define EXPRESSIONEVALUATOR_LAB04_TOKEN_HPP

#include <string>

class JSONToken {
public:
    JSONToken() : _isOpenBrace{ false }, _isCloseBrace{ false }, _isString{ false },
        _isColon{ false }, _isNumber{ false }, _isCloseBracket{ false }, _isOpenBracket{false},
        _isComma{ false }, _isCharacter{false}{};

    void print();

    // [ and ]
    void makeOpenBrace(char c) {
        _openBrace = c;
        _isOpenBrace = true;
        _isCharacter = true;
    }
    void makeCloseBrace(char c) {
        _closeBrace = c;
        _isCloseBrace = true;
        _isCharacter = true;
    }
    bool isOpenBrace() { return _isOpenBrace; }
    bool isCloseBrace() { return _isCloseBrace; }
    char getOpenBrace() { return _openBrace; }
    char getCloseBrace() { return _closeBrace; }
    //-----------------------------------

    // { and }
    void makeOpenBracket(char c) {
        _openBracket = c;
        _isOpenBracket = true;
        _isCharacter = true;
    }
    void makeCloseBracket(char c) {
        _closeBracket = c;
        _isCloseBracket = true;
        _isCharacter = true;
    }
    bool isOpenBracket() { return _isOpenBracket; }
    bool isCloseBracket() { return _isCloseBracket; }
    char getOpenBracket() { return _openBracket; }
    char getCloseBracket() { return _closeBracket; }
    //-----------------------------------

    // String
    void makeString(std::string str) {
        _key = str;
        _isString = true;
    }
    bool isString() { return _isString; }
    std::string getString() { return _key; }
    //-----------------------------------

    // Colon :
    void makeColon(char c) {
        _colon = c;
        _isColon = true;
        _isCharacter = true;
    }
    bool isColon() { return _isColon; }
    char getColon() { return _colon; }
    //-----------------------------------

    // Number
    void makeNumber(double n) {  // turns the token into a number token
        _number = n;
        _isNumber = true;
    }
    double getNumber() { return _number; }
    bool isNumber() { return _isNumber; }
    //-----------------------------------

    // Comma
    void makeComma(char c) {
        _comma = c;
        _isComma = true;
        _isCharacter = true;
    }
    bool isComma() { return _isComma; }
    char getComma() { return _comma; }
    //-----------------------------------

    // eof
    bool isEOF() { return _isCloseBrace; }
    //-----------------------------------

    bool isCharater() { return _isCharacter; }

private:
    double _number;
    std::string _key, _vDate;
    char _openBrace, _closeBrace, _openBracket, _closeBracket, _colon, _comma, _character;
    bool _isOpenBrace, _isCloseBrace, _isString, _isColon, _isNumber, _isComma, _isCloseBracket, _isOpenBracket ,_isCharacter;
};


#endif //EXPRESSIONEVALUATOR_LAB04_TOKEN_HPP
