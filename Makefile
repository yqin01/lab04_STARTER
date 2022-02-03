# Makefile
CXX = g++


all: testbst
	./testbst


testbst:intbst.cpp intbst.h testbst.cpp
	g++ -Wall -g intbst.cpp testbst.cpp -o testbst


clean:
	rm testbst