#include "EquityStats.hpp"
#include <math.h>

/* Sets the entitySet.
*  @param set: Set to add.
*/ 
EquityStats::EquityStats(EntitySet& set){
	entitySet = set;
}
/* Print all the instances into the vector in Json format
*  with 3 white spaces.
*
*/
void EquityStats::print(){
	entitySet.printInJSON(3);
}

/* Print all the instances into the vector in CSV format.
*
*  @param attributes: The number of spaces to separate.
*/
void EquityStats::print(std::vector<std::string> attributes){
	entitySet.printInCSV(attributes);
}

/* Print all the instances into the vector in Json format.
*
*  @param spaces: The number of spaces to separate.
*/
void EquityStats::printJson(int spaces){
	entitySet.printInJSON(spaces);
}

/* Calculate the exponential moving average then adds new the pais into the entitySet.
*
*  @param days: days for EMA
*/
void EquityStats::calculateExponentialMovingAverage(int days){
	std::vector<EntityInstance> instemp = entitySet.getEntityInstances();
	double emayesterday = 0.0;
	double ematoday = 0.0;
	double smooth = (2.0 / (1.0 + days));
	double averagetemp = 0;
	std::string ematemp = ("EMA-" + std::to_string(days));

	for (int i = 0; i < instemp.size(); i++) {
		averagetemp += instemp[i].close();
		if (i >= days - 1) {
			if (i == days - 1) {
				emayesterday = averagetemp / days;
				Pair pairtemp(ematemp, emayesterday);
				instemp[i].addPair(pairtemp);
			}
			else {
				ematoday = (instemp[i].close() * smooth) + emayesterday * (1.0 - smooth);
				emayesterday = ematoday;
				Pair pairtemp(ematemp, ematoday);
				instemp[i].addPair(pairtemp);
				//std::cout << std::setprecision(16) << instemp[i].close() << " * " << smooth << " + " << emayesterday << " * (" << (1.0 - smooth);
			}
		}
	}
	entitySet.changeInstance(instemp);
}

/* Calculate the MACD then adds new the pais into the entitySet.
*/
void EquityStats::calculateMACD(){
	std::vector<EntityInstance> instemp = entitySet.getEntityInstances();
	for (int i = 25; i < instemp.size(); i++) {
		double macd = (instemp[i].ema12() - instemp[i].ema26());
		Pair pairtemp("MACD", macd);
		instemp[i].addPair(pairtemp);
	}


	entitySet.changeInstance(instemp);
}

/* Calculate the signal then adds new the pais into the entitySet.
*
*  @param days: days for the signal.
*/
void EquityStats::calculateSignal(int days){
	int newDays = days + 24;

	std::vector<EntityInstance> instemp = entitySet.getEntityInstances();
	double emayesterday = 0.0;
	double ematoday = 0.0;
	double smooth = (2.0 / (1.0 + days));
	double averagetemp = 0;
	std::string ematemp = ("Signal" );

	for (int i = 25; i < instemp.size(); i++) {
		if (i <= newDays) {
			averagetemp += instemp[i].macd();
		}
		if (i > newDays) {
			ematoday = (instemp[i].macd() * smooth) + emayesterday * (1.0 - smooth);
			emayesterday = ematoday;
			Pair pairtemp(ematemp, ematoday);
			instemp[i].addPair(pairtemp);
			//std::cout << std::setprecision(16) << instemp[i].close() << " * " << smooth << " + " << emayesterday << " * (" << (1.0 - smooth);
		}	
		else if (i == newDays) {
			emayesterday = averagetemp / days;
			Pair pairtemp(ematemp, emayesterday);
			instemp[i].addPair(pairtemp);
		}
	}
	entitySet.changeInstance(instemp);
}



