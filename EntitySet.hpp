#pragma once

#include <vector>
#include <fstream>
#include "EntityInstance.hpp"
#include "EntitySet.hpp"

class EntitySet {
public:
    EntitySet();

    void addEntity(EntityInstance&);
    void printInJSON(int numSpaces);
    //void printInJSONHelper(int numSpaces);

    void printInCSV(std::vector<std::string> arguments);

    void changeInstance(std::vector<EntityInstance>& toInstance);

    std::vector<EntityInstance> getEntityInstances(); // returns "instances"
     // more member functions here.

private:
    std::vector<EntityInstance> instances;
};