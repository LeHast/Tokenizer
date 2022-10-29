#include "EntitySet.hpp"

EntitySet::EntitySet(){
}

/* Add an entityInstance to the vector.
*  @param entity; Entity to be add it.
*/
void EntitySet::addEntity(EntityInstance& entity){
	instances.push_back(entity);
}

/* Print the instances in the vector.
*
*  @param arguments: A vector of key values to print.
*/
void EntitySet::printInCSV(std::vector<std::string> arguments){

	for (int i = 0; i < arguments.size(); i++) {
		std::cout << arguments[i];
		if (i < arguments.size() - 1)
			std::cout << ",";
	}
	std::cout << std::endl;

	for (int i = 0; i < instances.size(); i++) {
		instances[i].printInCSV(arguments);
		std::cout << std::endl;
	}

}

/* Replace the vecort with a new vector.
* 
*  @param toInstance: New vector of instances.
*/
void EntitySet::changeInstance(std::vector<EntityInstance>& toInstance){
	instances = toInstance;
}

/* Print the instances in the vector in Json format.
*
*  @param arguments: Number of spaces to separate the pairs.
*/
void EntitySet::printInJSON(int numSpaces){
	std::cout << "[" << std::endl;

	std::cout << " {" << std::endl;

	for (int i = 0; i < instances.size(); i++) {
		instances[i].printInJSON(numSpaces);
		if (i == instances.size() - 1)
			std::cout << " }" << std::endl;
		else {
			std::cout << " }," << std::endl;
			std::cout << " {" << std::endl;
		}
	}
	std::cout << "]" << std::endl;
}

/* @return Returns the vector of instances.
*/
std::vector<EntityInstance> EntitySet::getEntityInstances()
{
	return instances;
}




//void EntitySet::printInJSONHelper(int numSpaces) {
//	std::ofstream out("test.json");
//
//	out << "[" << std::endl;
//	out << "	{" << std::endl;
//
//	for (int i = 0; i < instances.size(); i++) {
//		instances[i].printInJSONHelper(numSpaces, out);
//		if (i == instances.size() - 1)
//			out << "	}" << std::endl;
//		else {
//			out << "	}," << std::endl;
//			out << "	{" << std::endl;
//
//		}
//	}
//	out << "]" << std::endl;
//}
