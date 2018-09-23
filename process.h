/*******************************************************************************
  Title          : process.h
  Author         : Qiuqun Wang
  Created on     : May 4, 2018
  Description    : interface for the "Process" class
  Purpose        : Class project
*******************************************************************************/


#ifndef __PROCESS_H__
#define __PROCESS_H__

#include <iostream>
#include <list>
#include <string>
#include <sstream>
#include <cstdlib>
using namespace std;

class Process
{
public:
    //constructors and 
    Process();
    Process(const int new_pid);

    //copy constructor that copy info from one process to another
    Process& operator = (const Process &p);

    //friend operator that return true if two process are equal. Use pid as comparator
    friend bool operator == (const Process &p1, const Process &p2);

    //some accessor and mutator functions for the data contain inside process
    int pidAccess();
    void pidMutate(const int &x);//this function shouldn't be used in this assignment

    int timeqAccess();
    void timeqMutate(const int &x);

    int queLevelAccess();
    void queLevelMutate(const int &x);

    void diskInfoAccess(int &number, string &file_name);
    void diskInfoMutate(const int &number, const string &file_name);

    //change terminated to true so we know process is terminated
    void terminate();

    //check if the process is active or not
    bool active();

    //Increment queLevel or timeq by 1
    void incre_timeq();
    void incre_queLevel();

    //get the file the process want to use
    string getFilename();
    int getDiskNumb();

private:
    int pid;
    int timeq;
    int queLevel;
    int usingDisk;
    string workFile;
    int pages;
    bool terminated;
};

#endif