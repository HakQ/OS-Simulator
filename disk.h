/*******************************************************************************
  Title          : disk.h
  Author         : Qiuqun Wang
  Created on     : May 4, 2018
  Description    : interface for the "disk" class
  Purpose        : Class project
*******************************************************************************/
#ifndef __DISK_H__
#define __DISK_H__

#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include "process.h"
using namespace std;

class Disk
{
public:
	Disk();
	bool isIdle();
	void addToDisk(Process p);
	void exitDisk(Process &p);
	void print(const int &x);
private:
	Process current;
	list <Process> diskQue;
	bool idle;

};

#endif
