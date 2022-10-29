#pragma once

#include <iostream>
#include <vector>
#include "Pair.hpp"
#include <fstream>

class EntityInstance{
public:
    void addPair(Pair& pair); // Add a new pair to this entity.
    int numAttributes();  // how many pairs are in this instance?
    std::vector<std::string> attributeNames();
    void printInJSON(int numSpaces);   // prints this object. 
    void printInCSV(std::vector<std::string> arguments);

    double close();
    double ema12();
    double ema26();
    double macd();
    //void printInJSONHelper(int numSpaces, std::ofstream& out);   // prints this object. 

private:


    std::vector<Pair> entityPairs;
    // more variables here as necessary.
};

