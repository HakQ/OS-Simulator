#include <iostream>
#include <list>
#include <string>
#include <cstdlib>
#include "process.h"
#include <stdexcept>
#include <sstream>
using namespace std;
//g++ -std=c++0x ...

int main()
{
    stringstream ss;
    string sentence;
    string cmd;
    int number;
    string filename;
    string temp;
    cout << "enter your command" << endl;
    while(getline(cin, sentence))
    {
        cout << "You entered: " << sentence << endl;
    }

}




/*int main()
{
    int x;
    cin >> x;
    int arr[x];

    for(int i = 0; i < x; i++)
    {
        arr[i] = 1;
    }

    for(int i = 0; i < x; i++)
    {
        cout << arr[i] << endl;
    }

}*/

/*int main()
{
    list<Process> mylist;
    Process p0(0), p1(1), p2(2);

    mylist.push_back(p0);
    mylist.push_back(p1);
    mylist.push_back(p2);

    mylist.remove(p0);

    while(!mylist.empty())
    {
        Process temp = mylist.front();
        mylist.pop_front();

        cout << temp.pidAccess() << endl;
    }



}*/

/*int main()
{
    list<int> level[3];
    
    for(int i = 0; i < 5; i++)
        level[0].push_back(i);

    for(int i = 5; i < 10; i++)
        level[1].push_back(i);

    for(int i = 10; i < 15; i++)
        level[2].push_back(i);


    for(int i : level[0])
    {
        const int x = i; 
        level[0].remove(x);
    }

    for(int i = 0; i <3; i++)
    {
        for(auto x : level[i])
        {
            cout << x << " ";
        }

        cout << endl;
    }
        while(!level[i].empty())
        {
            cout << level[i].front();
            level[i].pop_front();
        }

}

*/