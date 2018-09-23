/*******************************************************************************
  Title          : os.cpp
  Author         : Qiuqun Wang
  Created on     : May 4, 2018
  Description    : implementation for "OS" class
  Purpose        : Class project
*******************************************************************************/

#include "os.h"
using namespace std;

OS::OS(const long int &r, const long int &ps, const short int &nd)
{
    ram = r;
    pageSize = ps;
    numbDisk = nd;
    numbFrame = ram / ps;
    numbProcess = 1;
    string command = "";

    //tell the memory how many frames are available
    myMem.setupFrame(numbFrame);

    //set up number of disks there are
    for(int i = 0; i < numbDisk; i++)
    {
    	Disk tempDisk;
    	myDisk.push_back(tempDisk);
    }

}

void OS::doCommand(string command)
{

	if(command[0] == 'A' && command.length() == 1)
	{
		command_A();
	}
	else if(command[0] == 'Q' && command.length() == 1)
	{
		command_Q();
	}
	else if(command[0] == 't' && command.length() == 1)
	{
		command_t();
	}
	else if(command[0] == 'd')
	{
		//command will be parse into these variables
		string cmd;
		int number;
		string filename;

		//used to parse the command
		stringstream ss;
		string temp;
		ss << command;

		//parse the command and some error checking
		ss >> cmd;
    	if(!(cmd.length() == 1))
    	{
        	cerr << "Error, bad command given to OS program exiting now! " << endl;
        	exit(1);
    	}
    	if(!(ss >> number) || number < 0)
    	{
        	cerr << "Error, bad command given OS, program exiting now!" << endl;
        	exit(1);
    	}
    	ss >> filename;
    	if(filename.empty())
    	{
        	cerr << "Error, bad command given OS, program exiting now!" << endl;
        	exit(1);
    	}
    	ss >> temp;
    	if(!temp.empty())
    	{
        	cerr << "Error, bad command given OS, program exiting now!" << endl;
        	exit(1);
   	 	}

		command_d(number, filename);
	}
	else if(command[0] == 'D')
	{
		//command will be parse into these variables
		string cmd;
		int number;

		//used to parse the command
		stringstream ss;
		string temp;
		ss << command;

		//parse the command and some error checking
		ss >> cmd;
    	if(!(cmd.length() == 1))
    	{
        	cerr << "Error, bad command given to OS program exiting now! " << endl;
        	exit(1);
    	}
    	if(!(ss >> number) || number < 0)
    	{
        	cerr << "Error, bad command given OS, program exiting now!" << endl;
        	exit(1);
    	}
    	ss >> temp;
    	if(!temp.empty())
    	{
        	cerr << "Error, bad command given OS, program exiting now!" << endl;
        	exit(1);
   	 	}

		command_D(number);
	}
	else if(command[0] == 'm')
	{
		//command will be parse into these variables
		string cmd;
		int number;

		//used to parse the command
		stringstream ss;
		string temp;
		ss << command;

		//parse the command and some error checking
		ss >> cmd;
    	if(!(cmd.length() == 1))
    	{
        	cerr << "Error, bad command given to OS program exiting now! " << endl;
        	exit(1);
    	}
    	if(!(ss >> number) || number < 0)
    	{
        	cerr << "Error, bad command given OS, program exiting now!" << endl;
        	exit(1);
    	}
    	ss >> temp;
    	if(!temp.empty())
    	{
        	cerr << "Error, bad command given OS, program exiting now!" << endl;
        	exit(1);
   	 	}

		command_m(number);
	}
	else if(command[0] == 'S' && command[1] == ' ' &&  command[2] == 'r' && command.length() == 3)
	{
		command_Sr();
	}
	else if(command[0] == 'S' && command[1] == ' ' &&  command[2] == 'i' && command.length() == 3)
	{
		command_Si();
	}
	else if(command[0] == 'S' && command[1] == ' ' &&  command[2] == 'm' && command.length() == 3)
	{
		command_Sm();
	}
	else
	{
		/*cerr << "Error: bad command given to os, program exiting now!" << endl;
		exit(1);*/
		cout << "You entered a bad command!!" << endl;
	}

	command = "";
}

void OS::command_A()
{
	Process temp(numbProcess);
	numbProcess ++;
	myCPU.addToCPU(temp);
	int memPID = temp.pidAccess();

	myMem.allocate(memPID, 0);
	
	//cout << "Executing command_A()" << endl;
}

void OS::command_Q()
{
	myCPU.addTime();

	//cout << "Executing command_Q()" << endl;
}

void OS::command_t()
{
	int memPID = myCPU.getCurrentPID();

	myCPU.termCurrent();

	myMem.deallocate(memPID);

	//cout << "Executing command_t()" << endl;
}

void OS::command_d(const int &number, const string &filename)
{
	//Since there are no process that are in CPU right now, we are not doing anything
	if(myCPU.isIdle())
		return;

	Process temp;
	myCPU.exitCPU(temp);//copy the process that was in cpu before to temp
	temp.diskInfoMutate(number, filename);

	if(number > numbDisk -1)
	{
		cerr << "Error, no such Disk you are trying to access. Program exit now!" << endl;
		exit(1);
	}

	myDisk[number].addToDisk(temp);

	//cout << "Executing command_d()" << endl;
}

void OS::command_D(const int &number)
{
	if(number > numbDisk -1)
	{
		cerr << "Error, no such Disk you are trying to access. Program exit now!" << endl;
		exit(1);
	}

	//Since there are no process that are in this Disk right now, we are not doing anything
	if(myDisk[number].isIdle())
		return;

	Process temp;
	myDisk[number].exitDisk(temp);//copy the process that was in Disk to temp

	myCPU.addToCPU(temp);

	//cout << "Executing command_D()" << endl;
}

void OS::command_m(const int &address)
{
	int memPID = myCPU.getCurrentPID();
	int page = address / pageSize;
	myMem.updatePM(memPID, page);

	//cout << "Executing command_m()" << endl;
}

void OS::command_Sr()
{
	cout << "--------------------------------------------------------------------------------------------" << endl;
	
	myCPU.print();

	cout << "--------------------------------------------------------------------------------------------" << endl;

	//cout << "Executing command_Sr()" << endl;
}

void OS::command_Si()
{
	cout << "--------------------------------------------------------------------------------------------" << endl;	
	
	int counter = 0;
	for(auto x : myDisk)
	{
		x.print(counter);
		counter++;
	}
	//cout << "Executing command_Si()" << endl;
	
	cout << "--------------------------------------------------------------------------------------------" << endl;
}

void OS::command_Sm()
{
	cout << "--------------------------------------------------------------------------------------------" << endl;
	
	myMem.print();

	cout << "--------------------------------------------------------------------------------------------" << endl;
}
