/*******************************************************************************
  Title          : os.h
  Author         : Qiuqun Wang
  Created on     : May 4, 2018
  Description    : interface for "OS" class
  Purpose        : Class project
*******************************************************************************/

#ifndef __OS_H__
#define __OS_H__

#include <iostream>
#include <list>
#include <cstdlib>
#include <string>
#include <vector>
#include "memory.h"
#include "cpu.h"
#include "disk.h"
using namespace std;

class OS
{
public:
    //OS(); //the default constructor is not used for this assignment
    OS(const long int &r, const long int &ps, const short int &nd);

    //parse the command string and perform if valid else exit program
    void doCommand(string command);

    //required commands for this projects that simulate certain aspect of OS
    void command_A();
    void command_Q();
    void command_t();
    void command_d(const int &number, const string &filename);
    void command_D(const int &number);
    void command_m(const int &address);
    void command_Sr();
    void command_Si();
    void command_Sm();


private:
    long int ram;
    long int pageSize;
    short int numbDisk;
    long int numbFrame;
    long int numbProcess;
    
    Memory myMem;
    vector<Disk> myDisk;
    CPU myCPU;

};
 
#endif