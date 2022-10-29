#include "EntityInstance.hpp"
#include <vector>
#include <string>

/* Add the pair into the vector.
*  
* @param pair: Pair variable to add.
*/
void EntityInstance::addPair(Pair& pair){
	entityPairs.push_back(pair);
}

/* @return Returns the size of the pair vector.
*/
int EntityInstance::numAttributes(){
	return entityPairs.size();
}

/* @return: Returns a vector with all the key values of the pairs.
*/
std::vector<std::string> EntityInstance::attributeNames(){
	std::vector<std::string> tempvec;

	for (int x = 0; x < entityPairs.size(); x++) {
		tempvec.push_back(entityPairs[x].attributeName());
	}
	return tempvec;
}

/* Print all the pairs into the vector in Json format.
* 
*  @param numSpaces: The number of spaces to separate.
*/
void EntityInstance::printInJSON(int numSpaces){
	//std::vector<std::string> vec = { "Open", "High", "Low", "Close", "Volume", "Dividends", "Stock Splits" , "Date", "Timestamp",
	//"EMA-12", "SMA-12", "EMA-26", "SMA-26", "MACD", "Signal", "id", "action" };
	
	//for (int i = 0; i < vec.size(); i++) {
	for (int x = 0; x < entityPairs.size(); x++) {
		entityPairs[x].printInJSON(numSpaces);
		if (x < entityPairs.size() - 1) {
			std::cout << ',' << std::endl;
		}
		else {
			std::cout << std::endl;
		}
	}
	//}
}

/* Print the pairs that are into the arguments in CSV format.
*
*  @param arguments: A vector of key values to print.
*/
void EntityInstance::printInCSV(std::vector<std::string> arguments){
	for (int i = 0; i < arguments.size(); i++) {
		for (int x = 0; x < entityPairs.size(); x++) {
			if (arguments[i] == entityPairs[x].attributeName()) {
				entityPairs[x].printInCSV();
			}
		}	
		if (i < arguments.size() - 1)
		std::cout << ",";
	}

}

/* @return Return the number value of "Close".
*/
double EntityInstance::close(){
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs[i].attributeName() == "Close") {
			return entityPairs[i].numberValue();
		}
	}
	return 0.0;
}

/* @return Return the number value of "EMA-12".
*/
double EntityInstance::ema12(){
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs[i].attributeName() == "EMA-12") {
			return entityPairs[i].numberValue();
		}
	}
	return 0.0;

}

/* @return Return the number value of "EMA-26".
*/
double EntityInstance::ema26(){
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs[i].attributeName() == "EMA-26") {
			return entityPairs[i].numberValue();
		}
	}
	return 0.0;

}

/* @return Return the number value of "MACD".
*/
double EntityInstance::macd() {
	for (int i = 0; i < entityPairs.size(); i++) {
		if (entityPairs[i].attributeName() == "MACD") {
			return entityPairs[i].numberValue();
		}
	}
	std::cout << "MACD No Found.";
	return 0.0;

}



//void EntityInstance::printInJSONHelper(int numSpaces, std::ofstream& out){
//	for (int i = 0; i < entityPairs.size(); i++) {
//		entityPairs[i].printInJSONHelper(numSpaces, out);
//		if (i < entityPairs.size() - 1) {
//			out << ',' << std::endl;
//		}
//		else {
//			out << std::endl;
//		}
//	}
//}
