#include <cstring>
#include <string>
#include <iostream>
#include <fstream>
#include "RecordStructures.h"

using namespace std;

/*void retrieveFromFile(classSchedule currentSchedule[])
{
    ifstream fileIn;

    fileIn.open("classes.txt");

    // If file opened continue
    if (fileIn.is_open())
	{
		int counter = 0;
		while (!fileIn.eof())
		{
			fileIn >> currentSchedule[counter].classDepartment
				>> currentSchedule[counter].creditHours
				>> currentSchedule[counter].teacherLastName
				>> currentSchedule[counter].teacherFirstName
				>> currentSchedule[counter].roomWingAndNumber
				>> currentSchedule[counter].currentGPA;
			counter++;
		}
	}


    // If file did not open, output error message
    else
        cout << endl << "Error Opening File.";

    // Close file when done with it
    // While this step is not necessary for execution
    // it is still good practice.
    fileIn.close();
}*/
