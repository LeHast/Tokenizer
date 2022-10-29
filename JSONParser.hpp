#pragma once

#include "Pair.hpp"
#include "EntityInstance.hpp"
#include "EntitySet.hpp"
#include "Tokenizer.hpp"

class JSONParser {
public:
    JSONParser(std::string nameOfInputFile);

    Pair parseAPair();
    EntityInstance parseJSONObject();
    EntitySet parseJSONEntity();

private:
    JSONTokenizer tokenizer; 
                             
};
