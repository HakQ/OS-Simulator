/*******************************************************************************
  Title          : memory.cpp
  Author         : Qiuqun Wang
  Created on     : May 4, 2018
  Description    : implementation for the "memory" class
  Purpose        : Class project
*******************************************************************************/
#include "memory.h"
using namespace std;


MemEntry::MemEntry(const int &new_pid, const int &new_page, const int &new_frame)
{
	frame = new_frame;
	page = new_page;
	pid = new_pid;
}
    
MemEntry& MemEntry::operator = (const MemEntry &m)
{
	this->frame = m.frame;
	this->page = m.page;
	this->pid = m.pid;
	return *this;
}

int MemEntry::getFrame()
{
	return frame;
}

int MemEntry::getPID()
{
	return pid;
}

int MemEntry::getPage()
{
	return page;
}

bool operator == (const MemEntry &m1, const MemEntry &m2)
{
	if (m1.pid == m2.pid) return true;

    return false;
}

void MemEntry::changePID(const int &x)
{
	pid = x;
}

void MemEntry::print()
{
	cout << pid << "\t" << frame << "\t" << page << endl;
}

void Memory::setupFrame(const int &x)
{
	for(int i = x - 1; 0 <= i; i--)
	{
		availFrame.push(i);
	}
}

void Memory::remove_LRU()
{
	
	memTable.pop_front();
}

void Memory::allocate(const int &processPID, const int &pageNumb)
{
	if(availFrame.empty())
	{
		MemEntry temp = memTable.front();
		int returnFrame = temp.getFrame();
		availFrame.push(returnFrame);
		memTable.pop_front();
	}

	MemEntry newEntry(processPID, pageNumb, availFrame.top());
	availFrame.pop();

	memTable.push_back(newEntry);
}

void Memory::deallocate(const int &processPID)
{
	for (list<MemEntry>::iterator it = memTable.begin(); it != memTable.end();)
	{
		if(it->getPID() == processPID)
		{
			availFrame.push(it->getFrame());
			memTable.erase(it++);
		}
		else
		{
			it++;
		}
	}

}

void Memory::updatePM(const int &processPID, const int &pageNumb)
{

	bool alreadyInTable = false;

	for (list<MemEntry>::iterator it = memTable.begin(); it != memTable.end(); it++)
	{
		if(it->getPID() == processPID && it->getPage() == pageNumb)
		{
			MemEntry temp = *it;
			memTable.push_back(temp);
			memTable.erase(it++);
			alreadyInTable = true;
		}
	}

	if(!alreadyInTable)
	{
		int giveFrame;

		if(availFrame.empty())
		{
			MemEntry temp = memTable.front();
			giveFrame = temp.getFrame();
			memTable.pop_front();
		}
		else
		{
			giveFrame = availFrame.top();
			availFrame.pop();
		}
		
		MemEntry newEntry(processPID, pageNumb, giveFrame);
		memTable.push_back(newEntry);
	}

}

void Memory::print()
{

	cout << "PID\tFrame\tPage" << endl;
	for(auto x : memTable)
	{
		x.print();
	}

}

