#include <iostream>
#include <fstream>
#include "Token.hpp"
#include "Tokenizer.hpp"
#include "JSONParser.hpp"
#include "EquityStats.hpp"
#include "EntitySet.hpp"



int main(int argc, char* argv[]) {

    if (argc != 3) {
        std::cout << "3 arguments need it.";
        exit(5);
    }

    std::string argument = argv[1];
    if (argument != "-json" && argument != "-csv") {
        std::cout << "Argument has to be json or csv";
        exit(5);
    }
;
    std::ifstream inputStream;
    inputStream.open(argv[2], std::ios::in);    // open for reading
    if (!inputStream.is_open()) {
        std::cout << "Unable top open " << argv[2] << ". Terminating...";
        exit(2);
    }
    inputStream.close();

    std::vector<std::string> vec = { "Date","Open","High","Low","Close","Volume","EMA-12","EMA-26","MACD","Signal" };

    JSONParser p(argv[2]);
    EntitySet settemp = p.parseJSONEntity();
    EquityStats stats = EquityStats(settemp);

    stats.calculateExponentialMovingAverage(12);
    stats.calculateExponentialMovingAverage(26);
    stats.calculateMACD();
    stats.calculateSignal(9);
 
    if (argument == "-json") {
        stats.printJson(6);
    }
    else if (argument == "-csv") {
        stats.print(vec);
    }



    return 0;
}