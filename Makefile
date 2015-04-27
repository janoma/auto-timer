CXX=g++
CXXFLAGS=-O3 -Wall -Wextra -Werror

all: test

test: test.cpp
	$(CXX) $(CXXFLAGS) -o test test.cpp

clean:
	rm -f test
