/*******************************************************************************
  Title          : disk.cpp
  Author         : Qiuqun Wang
  Created on     : May 4, 2018
  Description    : implementation for the "disk" class
  Purpose        : Class project
*******************************************************************************/
#include "disk.h"
using namespace std;

Disk::Disk()
{
	idle = true;
}

bool Disk::isIdle()
{
	return idle;
}

void Disk::addToDisk(Process p)
{
	if(idle)
	{
		current = p;
		idle = false;
	}
	else
	{
		diskQue.push_back(p);
	}
}

void Disk::exitDisk(Process &p)
{
	current.timeqMutate(0);
	p = current;

	if(!diskQue.empty())
	{
		current = diskQue.front();
		diskQue.pop_front();
		idle = false;
	}
	else
	{
		current.terminate();
		idle = true;
	}
}

void Disk::print(const int &x)
{
	cout << "Process currently using Disk " << x << ": " << endl;
	if(current.pidAccess() >= 0)
	{
		cout << "\t" << "Process PID: " << current.pidAccess() << " | ";
		cout << "File the process requested: " << current.getFilename() << endl;
	}

	cout << "Process in Disk " << x << " Queue's: " << endl;
	for(auto x : diskQue)
	{
		cout << "\t" << "Process PID: " << x.pidAccess() << " | ";
		cout << "File the process requested: " << x.getFilename() << endl;;
	}

	cout << endl;
}
