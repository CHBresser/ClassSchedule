//----------------------------------------------------------|
//Programmer Name: Zach Bresser                             |
//Date Written: 1/27/15                                     |
//Purpose: A console application that displays a college    |
//    schedule and allows you to interact with it in a      |
//    variety of ways                                       |
//Project Files:                                            |
//    Source:                                               |
//       classSchedule.cpp                                  |
//       menu.cpp                                           |
//       RecordStructures.cpp                               |
//    Header Files:                                         |
//       menu.h                                             |
//       RecordStructures.h                                 |
//----------------------------------------------------------|

#include <iostream>
#include <string>
#include "RecordStructures.h"
#include "menu.h"

using namespace std;

// Declare Constants
const int MAX_CLASSES = 50;

int main()
{

	// Declare an instance of classSchedule
	classSchedule currentSchedule[MAX_CLASSES];
	int numElems = 0;
	numElems = currentSchedule->inputFromFile(currentSchedule);
	char contin = 'Y';
	while (contin == 'Y' || contin == 'y')
	{
        menu(currentSchedule, numElems);
        cout << endl << "Would you like to Continue(Y/N)?: ";
        cin >> contin;
	}




}

