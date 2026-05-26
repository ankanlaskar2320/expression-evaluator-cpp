CXX = g++
CXXFLAGS = -std=c++17 -Wall -I include
SRC = src/evaluator.cpp

build:
	$(CXX) $(CXXFLAGS) $(SRC) src/main.cpp -o expression_evaluator

test:
	$(CXX) $(CXXFLAGS) $(SRC) tests/test_evaluator.cpp -o run_tests
	./run_tests

run: build
	./expression_evaluator

clean:
	rm -f expression_evaluator run_tests