#include "Pair.hpp"
#include <fstream>
#include <math.h> 

/* Constructor, If the attribute value is a string it will store that string.
*  @param attributeName: Key name.
*  @param attributeName: Value to store.
*/
Pair::Pair(std::string attributeName, std::string attributeValue) : _isNumber{false} {
	_attributeName = attributeName;
	_attributeStringValue = attributeValue;
}

/* Constructor, If the attribute value is a string it will store that string.
*  @param attributeName: Key name.
*  @param value: Value to store.
*/
Pair::Pair(std::string attributeName, double value){
	_isNumber = true;
	_attributeName = attributeName;
	_attributeNumberValue = value;
}

/* @return If the value is a number return true.
*/
bool Pair::isDouble(){
	return _isNumber;
}

/* @return The number value.
*/
double Pair::numberValue(){
	return _attributeNumberValue;
}

/* @return The string value.
*/
std::string Pair::stringValue(){
	return _attributeStringValue;
}
/* 
* @return The key value.
*/
std::string Pair::attributeName(){
	return _attributeName;
}

/* Print the key and string or number values in Json format.
* 
*  @param numSpaces: Number of spaces to separete the pair.
*/
void Pair::printInJSON(int numSpaces){
	for (int x = 0; x < numSpaces; x++) {
		std::cout << " ";
	}

	std::string tempAttribute = "\"" + attributeName() + "\"";

	if (isDouble()) {
		int tempvalue = floor(numberValue());

		if (tempvalue == numberValue()) {
			std::cout << tempAttribute << ": " << std::fixed <<std::setprecision(0) << numberValue();
		}
		else {
			std::cout << std::fixed << std::setprecision(4) << tempAttribute << ": " << numberValue();
		}
	}
	else {
		std::cout << tempAttribute << ":" << "\"" << stringValue() << "\"";
	}
}

/* Print the key and string or number values in CSV format.
*/
void Pair::printInCSV(){

	if (isDouble()) {
		if (attributeName() == "Volume") {
			std::cout << std::setprecision(0) << numberValue();
		}
		else {
			std::cout << std::fixed << std::setprecision(4) << numberValue();
		}
	}
	else {
		std::cout << stringValue();
	}

}


//void Pair::printInJSONHelper(int numSpaces, std::ostream& out){
//	for (int x = 0; x < numSpaces; x++) {
//		out << " ";
//	}
//
//	std::string tempAttribute = "\"" + attributeName() + "\"";
//
//	if (isDouble())
//		out << std::fixed << std::setprecision(4) << tempAttribute << ": " << numberValue();
//	else {
//		out << tempAttribute << ":" << "\"" << stringValue() << "\"";
//	}
//
//}
