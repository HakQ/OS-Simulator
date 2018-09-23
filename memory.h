/*******************************************************************************
  Title          : memory.h
  Author         : Qiuqun Wang
  Created on     : May 4, 2018
  Description    : interface for the "memory" class
  Purpose        : Class project
*******************************************************************************/
#ifndef __MEMORY_H__
#define __MEMORY_H__

#include <stack>
#include "process.h"
using namespace std;

class MemEntry
{
public:
    //MemEntry(); //will not be used
    MemEntry(const int &new_pid, const int &new_page, const int &new_frame);
    int getFrame();
    int getPID();
    int getPage();
    void changePID(const int &x);
    void print();
    
    MemEntry& operator = (const MemEntry &m);
    friend bool operator == (const MemEntry &m1, const MemEntry &m2);
    

private:
	int frame;
	int page;
	int pid;
};


class Memory
{
public:
  void remove_LRU();
  void allocate(const int &processPID, const int &pageNumb);
  void deallocate(const int &processPID);
  void updatePM(const int &processPID, const int &pageNumb);
  void setupFrame(const int &x);
  void print();
private:
	list <MemEntry> memTable;
	stack <int> availFrame;
};

#endif
