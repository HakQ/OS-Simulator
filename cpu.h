/*******************************************************************************
  Title          : cpu.h
  Author         : Qiuqun Wang
  Created on     : May 4, 2018
  Description    : interface for the "cpu" class
  Purpose        : Class project
*******************************************************************************/


#ifndef __CPU_H__
#define __CPU_H__

#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include "process.h"
using namespace std;

class CPU
{
public:
	CPU();
	bool isIdle();
	void addToCPU(Process p);
	void addTime();
	void termCurrent();
	void exitCPU(Process &p);
	void print();
	int getCurrentPID();
private:
	void assignToCPU();
	Process current;
	list <Process> readyQue[3];
	bool idle;

};

#endif