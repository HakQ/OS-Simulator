/*******************************************************************************
  Title          : process.cpp
  Author         : Qiuqun Wang
  Created on     : May 4, 2018
  Description    : implementation for the "Process" class
  Purpose        : Class project
*******************************************************************************/


#include "process.h"
using namespace std;


Process::Process()
{
    pid = -1;
    timeq = 0;
    queLevel = 0;
    usingDisk = -1;
    workFile = "";
    pages = 0;
    terminated = false;
}

Process::Process(const int new_pid)
{
    pid = new_pid;
    timeq = 0;
    queLevel = 0;
    usingDisk = -1;
    workFile = "";
    pages = 0;
    terminated = false;
}  

Process& Process::operator = (const Process &p)
{
    this->pid = p.pid;
    this->timeq = p.timeq;
    this->queLevel = p.queLevel;
    this->usingDisk = p.usingDisk;
    this->workFile = p.workFile;
    this->pages = p.pages;
    this->terminated = p.terminated;
    return *this;
}

bool operator == (const Process &p1, const Process &p2)
{
    if (p1.pid == p2.pid) return true;

    return false;
}

int Process::pidAccess()
{
    if(terminated == false)
    {
        return pid;
    }
    else
    {
        return -1;
    }
}

void Process::pidMutate(const int &x)
{
    pid = x;
}

int Process::timeqAccess()
{
    return timeq;
}

void Process::timeqMutate(const int &x)
{
    timeq = x;
}

int Process::queLevelAccess()
{
    return queLevel;
}

void Process::queLevelMutate(const int &x)
{
    queLevel = x;
}

void Process::diskInfoAccess(int &number, string &file_name)
{
    number = usingDisk;
    file_name = workFile;
}

void Process::diskInfoMutate(const int &number, const string &file_name)
{
    usingDisk = number;
    workFile = file_name;
}

void Process::terminate()
{
    terminated = true;
}

bool Process::active()
{
    return !terminated;
}

void Process::incre_timeq()
{
    timeq++;
}

void Process::incre_queLevel()
{
    queLevel++;
}

string Process::getFilename()
{
    return workFile;
}

int Process::getDiskNumb()
{
    return usingDisk;
}