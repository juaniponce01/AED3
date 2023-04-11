CC := g++ -I ./Eigen/
FLAGS := -g -Wall -std=c++0x
EXTRAFLAGS := -O2
HEADS := matrix.h fileHandler.h
CPPS := matrix.cpp fileHandler.cpp
MAIN := main

.PHONY: all clean cleandebug cleanall

tp: $(MAIN).cpp $(CPPS) $(HEADS) Makefile
	g++ $(FLAGS) $(EXTRAFLAGS) $< $(CPPS) -o $@

debug: $(MAIN).cpp $(CPPS) $(HEADS) Makefile
	g++ $(FLAGS) $< $(CPPS) -o $@

all: tp debug

clean:
	rm -f tp

cleandebug:
	rm -f debug

cleanall: clean cleandebug


run: tp
	./tp 0.76 "../tests/test_aleatorio_desordenado.txt"
