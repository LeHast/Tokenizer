
project3.x: Pair.o EntityInstance.o EntitySet.o Token.o Tokenizer.o JSONParser.o main.o EquityStats.o
	g++ -std=c++17 Pair.o EntityInstance.o EntitySet.o Token.o main.o \
		Tokenizer.o JSONParser.o EquityStats.o -o project3.x

EntitySet.o: EntitySet.cpp EntitySet.hpp EntityInstance.hpp Pair.hpp
	g++ -std=c++17 EntitySet.cpp -o EntitySet.o -c

EntityInstance.o: EntityInstance.cpp EntityInstance.hpp Pair.hpp
	g++ -std=c++17 EntityInstance.cpp -o EntityInstance.o -c 

Pair.o: Pair.cpp Pair.hpp 
	g++ -std=c++17 Pair.cpp -o Pair.o -c

Token.o: Token.cpp Token.hpp
	g++ -std=c++17 Token.cpp -o Token.o -c

Tokenizer.o: Tokenizer.cpp Tokenizer.hpp Token.hpp
	g++ -std=c++17 Tokenizer.cpp -o Tokenizer.o -c

JSONParser.o: JSONParser.cpp JSONParser.hpp EntityInstance.hpp Pair.hpp \
  EntitySet.hpp Tokenizer.hpp Token.hpp
	g++ -std=c++17 JSONParser.cpp -o JSONParser.o -c

EquityStats.o: EquityStats.cpp EquityStats.hpp EntitySet.hpp EntityInstance.hpp 
	g++ -std=c++17 EquityStats.cpp -o EquityStats.o -c

main.o: main.cpp Token.hpp Tokenizer.hpp JSONParser.hpp EntityInstance.hpp Pair.hpp \
  EntitySet.hpp Tokenizer.hpp Token.hpp EquityStats.hpp
	g++ -std=c++17 main.cpp -o main.o -c
