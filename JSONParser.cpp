
#include "JSONParser.hpp"

JSONParser::JSONParser(std::string nameOfInputFile): tokenizer {nameOfInputFile}{
}


/* Creates the values from the token to a pair.
*  @return Returns the pair created.
*/ 
Pair JSONParser::parseAPair() {
    JSONToken token = tokenizer.getToken();
    std::string tempSt, tempStpair;
    double tempDouPair;

    while (!token.isString() && !token.isNumber()) {
        token = tokenizer.getToken();
    }

    tempSt = token.getString();
    token = tokenizer.getToken();
    token = tokenizer.getToken();

    if (token.isNumber()) {
        tempDouPair = token.getNumber();
        Pair pair(tempSt, tempDouPair);

        return pair;
    }
    else {
        tempStpair = token.getString();
        Pair pair(tempSt, tempStpair);

        return pair;
    }
}

/* Creates a object (instance) with pairs.
*  @return Returns the object created.
*/
EntityInstance JSONParser::parseJSONObject(){
    JSONToken token = tokenizer.getToken();

    if (token.isOpenBracket()) {
        token = tokenizer.getToken();
    }

    if (!token.isOpenBrace()) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntityInstance instance;
    do {
        Pair pair = parseAPair();
        instance.addPair(pair);
        token = tokenizer.getToken();
    } while (token.isComma());  

    if (!token.isCloseBrace()) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    return instance;
}


/* Creates an Entity with all the objects.
*  @return Returns the entity created.
*/
EntitySet JSONParser::parseJSONEntity(){
    JSONToken token = tokenizer.getToken();

    // [
    if (!token.isOpenBracket()) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an open brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }
    EntitySet entitySet;

    do {
        EntityInstance insTemp = parseJSONObject();
        entitySet.addEntity(insTemp);
        token = tokenizer.getToken();
    } while (token.isComma());

    // ]
    if (!token.isCloseBracket()) {
        std::cout << "Error: JSONParser::parseJSONObject: Expected an close brace, but found" << std::endl;
        token.print();
        std::cout << "Terminating..." << std::endl;
        exit(1);
    }

	return entitySet;
}

