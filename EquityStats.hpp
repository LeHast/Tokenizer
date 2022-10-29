#pragma once

#include <vector>
#include <string>
#include "EntitySet.hpp"
#include "EntityInstance.hpp"

class EquityStats{

public:
	EquityStats(EntitySet& );

	void print();
	void print(std::vector<std::string> attributes);
	void printJson(int);


	void calculateExponentialMovingAverage(int days);
	void calculateMACD();
	void calculateSignal(int days);
private:
	EntitySet entitySet;

	double ema12, ema26, macd;
};

