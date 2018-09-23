# Makefile for OS project
# Originally written by Stewart Weiss, modified by Qiuqun Wang 
# This is designed for the first project in CSci 335, Spring 2018
#
# Type  make to build the executable, which is named project
# Type make clean to remove all .o files
# Type make cleanall to remove all .o files and the project1 executable.
# If you want to force a recompile, type "touch *.cpp" and then "make"

CXX       := /usr/bin/g++ -std=c++0x
CXXFLAGS  += -W -g 

all: project

.PHONY: clean  cleanall
clean:
	rm -f *.o

cleanall:
	rm -f *.o project
	
project:  main.o  os.o  memory.o  disk.o  cpu.o  process.o
	$(CXX) $(CXXFLAGS) -o project  main.o os.o memory.o disk.o cpu.o process.o

main.o: main.cpp os.h memory.h disk.h cpu.h process.h 
	$(CXX) $(CXX_FLAGS)  -c main.cpp

os.o: os.cpp os.h 
	$(CXX) $(CXX_FLAGS)  -c os.cpp

memory.o: memory.cpp memory.h 
	$(CXX) $(CXX_FLAGS)  -c memory.cpp

disk.o: disk.cpp disk.h 
	$(CXX) $(CXX_FLAGS)  -c disk.cpp

cpu.o: cpu.cpp cpu.h 
	$(CXX) $(CXX_FLAGS)  -c cpu.cpp

tree.o: process.cpp process.h
	$(CXX) $(CXX_FLAGS) -c process.cpp
