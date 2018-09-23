/*******************************************************************************
  Title          : main.cpp
  Author         : Qiuqun Wang
  Created on     : May 4, 2018
  Description    : A simulation of certain OS features
  Purpose        : Class project
*******************************************************************************/
#include "os.h"
#include <cstdlib>
#include <climits>
using namespace std;

//set up the arguments needed for OS simulation, if the inputs are bad, program exits.
void startup(long int &ram, long int &pageSize, short int &numbDisk);

int main()
{
    long int ram;
    long int pageSize;
    short int numbDisk;

    //get the parameters from user input and check if they are valid, 
    //exit program if they are not valid. This function does some error checking
    startup(ram, pageSize, numbDisk);

    //pass the given parameter to OS and simulation begins
    OS mySim(ram, pageSize, numbDisk);

    string command;

    //infinit loop of commands until use choose to stop
    while(getline(cin, command))
    {
        //cout << "Given Command: " << command; 
        mySim.doCommand(command);
    }

}

void startup(long int &ram, long int &pageSize, short int &numbDisk)
{
    cout << "Enter the amount of Ram the machine has: ";
    if(!(cin >> ram))
    {
        cerr << "Invalid input, program exiting now!" << endl;
        exit(1);
    }
    
    cout << "Enter the page/frame size of the machine: ";
    if(!(cin >> pageSize))
    {
        cerr << "Invalid input, program exiting now!" << endl;
        exit(1);
    }

    cout << "Enter the number of disk the machine has: ";
    if(!(cin >> numbDisk))
    {
        cerr << "Invalid input, program exiting now!" << endl;
        exit(1);
    }

    if(ram > 4000000000)
    {
        cerr << "Error: requested RAM is way too much, program exiting now!" << endl;
        exit(1);
    }

    if(pageSize > ram)
    {
        cerr << "Error: page size cannot be greater than RAM, bad input program exiting now!" << endl;
        exit(1);
    }

    if(ram <= 0 || pageSize <= 0 || numbDisk <= 0)
    {
        cerr << "Error: You entered value that are less than or equal to 0, program exiting now" << endl;
        exit(1);
    }

    cout << "Thank you for your inputs, you may begin the simulation now: " << endl;
    cin.clear();
    cin.ignore(INT_MAX, '\n');

}