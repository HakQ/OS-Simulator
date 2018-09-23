/*********************************************************s**********************
  Title          : cpu.cpp
  Author         : Qiuqun Wang
  Created on     : May 4, 2018
  Description    : implementation for the "cpu" class
  Purpose        : Class project
*******************************************************************************/
#include "cpu.h"
using namespace std;

CPU::CPU()
{
	idle = true;
}

int CPU::getCurrentPID()
{
	return current.pidAccess();
}


bool CPU::isIdle()
{
	return idle;
}

void CPU::addToCPU(Process p)
{
	if(idle)
	{
		current = p;
		idle = false;
	}
	else if(current.queLevelAccess() > p.queLevelAccess())
	{
		readyQue[current.queLevelAccess()].push_front(current);
		current = p;
	}
	else if(current.queLevelAccess() <= p.queLevelAccess())
	{
		readyQue[p.queLevelAccess()].push_back(p);
	}
	else
	{
		cerr << "Unexpected Error in CPU, Program exit!" << endl;
	}	
}

void CPU::assignToCPU()
{
	if(!readyQue[0].empty())
	{
		current = readyQue[0].front();
		readyQue[0].pop_front();
		idle = false;
	}
	else if(!readyQue[1].empty())
	{
		current = readyQue[1].front();
		readyQue[1].pop_front();
		idle = false;
	}
	else if(!readyQue[2].empty())
	{
		current = readyQue[2].front();
		readyQue[2].pop_front();
		idle = false;
	}
	else //all the queues are empty
	{
		//because we are trying to assign a new process to CPU but there are none left
		current.terminate();
		idle = true;
	}
}

void CPU::addTime()
{
	//If there is no process in the CPU, then adding time quantum has no effect
	if(idle)
		return;

	current.incre_timeq();
	if(current.queLevelAccess() == 0)
	{
		current.queLevelMutate(1);
		current.timeqMutate(0);
		readyQue[current.queLevelAccess()].push_back(current);
		assignToCPU();
	}
	else if(current.queLevelAccess() == 1)
	{
		//if timeq is less than 2 then this process get to continue use of the CPU
		/*if(current.timeqAccess() < 2)
		{
			readyQue[current.queLevelAccess()].push_back(current);
			
		}
		else
		{
			current.queLevelMutate(2);
			current.timeqMutate(0);
			readyQue[current.queLevelAccess()].push_back(current);
		}

		assignToCPU();*/

		if(current.timeqAccess() >= 2)
		{
			current.queLevelMutate(2);
			current.timeqMutate(0);
			readyQue[current.queLevelAccess()].push_back(current);
			assignToCPU();
		}
	}
	else if(current.queLevelAccess() == 2)
	{
		//Do nothing because we are at the lowest, Level adding a time quantum
		//should not change the CPU from preempting the process because its FCFS
	}
	else
	{
		cerr << "Unexpected Error on CPU, program exiting!" << endl;
		exit(1);
	}

}

void CPU::termCurrent()
{
	current.terminate();
	assignToCPU();
}

void CPU::exitCPU(Process &p)
{
	p = current;
	assignToCPU();
}

void CPU::print()
{

	cout << "Process currently using CPU: " << endl;
	if(current.pidAccess() >= 0)
	{
		cout << "\t" << "Process PID: " << current.pidAccess() << " | ";
		cout << "Queue Level: " << current.queLevelAccess() << endl;
	}

	cout << "Process in Ready Queue Level 0: " << endl;
	for(auto x : readyQue[0])
	{
		cout << "\t" << "Process PID: " << x.pidAccess() << endl;
	}

	cout << "Process in Ready Queue Level 1: " << endl;
	for(auto x : readyQue[1])
	{
		cout << "\t" << "Process PID: " << x.pidAccess() << endl;
	}

	cout << "Process in Ready Queue Level 2: " << endl;
	for(auto x : readyQue[2])
	{
		cout << "\t" << "Process PID: " << x.pidAccess() << endl;
	}
}
