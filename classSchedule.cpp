#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include "RecordStructures.h"
#include "menu.h"

using namespace std;

classSchedule::classSchedule() //Default constructor
{
	classDepartment = "";
	classNumber = -1;
	creditHours = -1;
	teacherLastName = "";
	teacherFirstName = "";
	roomWingAndNumber = "";
	currentGPA = -1.0;
	displayOrNot = "";
}
void classSchedule::outputToConsole(classSchedule currentSchedule[], int numElems)
{
    int i;
    cout << endl << "Dept" << "\t" << "Class Number\t" "Credit Hours" << "\t" << "Name"
         << "\t" << "Room Number" << "\tGPA"
         << endl << "----" << "\t------------" << "\t-------------   ----"
         << "\t-----------" << "\t---";
    for (i = 0; i < numElems; i++)
    {
        if (currentSchedule[i].displayOrNot == "FALSE")
            i++;
        if(currentSchedule[i].currentGPA == -1)
        {
            continue;
        }
        cout << endl << currentSchedule[i].classDepartment << "         " << currentSchedule[i].classNumber << "    \t"
             << "      " << currentSchedule[i].creditHours << "    \t"
             << currentSchedule[i].teacherLastName << " " << currentSchedule[i].teacherFirstName
             << "\t" << currentSchedule[i].roomWingAndNumber << "\t" << currentSchedule[i].currentGPA;
    }

}
int classSchedule::inputFromFile(classSchedule currentSchedule[])
{
    int counter = 0;
    ifstream fileIn;

    fileIn.open("class.txt");

    // If file opened continue
    if (fileIn.is_open())
	{

		while (!fileIn.eof())
		{
			fileIn >> currentSchedule[counter].classDepartment
                >> currentSchedule[counter].classNumber
				>> currentSchedule[counter].creditHours
				>> currentSchedule[counter].teacherLastName
				>> currentSchedule[counter].teacherFirstName
				>> currentSchedule[counter].roomWingAndNumber
				>> currentSchedule[counter].currentGPA
				>> currentSchedule[counter].displayOrNot;
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
    return counter;
}

void classSchedule::addEntry(classSchedule schedule[], int& numElems)
{
    cout << endl << "Please Enter the Department of the class: ";
    cin >> schedule[numElems - 1].classDepartment;
    cout << endl << "Please Enter the Class Number of the Class: ";
    cin >> schedule[numElems - 1].classNumber;
    cout << endl << "Please Enter the Credit Hours of the class: ";
    cin >> schedule[numElems - 1].creditHours;
    cout << endl << "Please Enter the Teacher's Last Name: ";
    cin >> schedule[numElems - 1].teacherLastName;
    cout << endl << "Please Enter the Teacher's First Name: ";
    cin >> schedule[numElems - 1].teacherFirstName;
    cout << endl << "Please Enter the Room Wing and Number: ";
    cin >> schedule[numElems - 1].roomWingAndNumber;
    cout << endl << "Please Enter Current GPA In Class: ";
    cin >> schedule[numElems - 1].currentGPA;
    schedule[numElems].displayOrNot = "TRUE";

    numElems++;

    outputToConsole(schedule, numElems);

}

void classSchedule::outputToFile(classSchedule schedule[], int& numElems)
{
    ofstream fileOut;

    fileOut.open("class.txt");

    for (int counter = 0; counter < numElems; counter++)
    {
        if(schedule[counter].displayOrNot == "TRUE")
        {
            fileOut << schedule[counter].classDepartment
            << " " << schedule[counter].classNumber
            << " " << schedule[counter].creditHours
            << " " << schedule[counter].teacherLastName
            << " " << schedule[counter].teacherFirstName
            << " " << schedule[counter].roomWingAndNumber
            << " " << schedule[counter].currentGPA
            << " " << schedule[counter].displayOrNot;
            fileOut << endl;
        }
    }

    fileOut.close();
}

void classSchedule::deleteEntry(classSchedule schedule[], int numElems)
{
    string entryToDelete;
    cout << endl << "Enter the Teacher's Last Name of the Entry you want to delete: ";
    cin >> entryToDelete;

    for (int i = 0; i < numElems; i++)
    {
        if (schedule[i].teacherLastName == entryToDelete)
        {
            schedule[i].displayOrNot = "FALSE";
            outputToFile(schedule, numElems);
            ofstream fileOut;

            fileOut.open("deletedEntries.txt");
            if (fileOut.is_open())
            {
                fileOut << schedule[i].classDepartment
                        << " " << schedule[i].classNumber
                        << " " << schedule[i].creditHours
                        << " " << schedule[i].teacherLastName
                        << " " << schedule[i].teacherFirstName
                        << " " << schedule[i].roomWingAndNumber
                        << " " << schedule[i].currentGPA
                        << " " << schedule[i].displayOrNot;
            }
            numElems--;
        }
    }

}

// The following lines
template<class order> // template called order
struct order_by_t {
  order f; //Instantiate a type of order named f
  order_by_t(order in):f(in) {}
  order_by_t(order_by_t const& o):f(o.f) {}
  template<class LS, class RS> // LS = left side RS = right side
  bool operator()( LS const& lS, RS const& rS ) const
  {
    return f(lS) < f(rS); //
  }
};
bool orderByGPA( classSchedule const& lS, classSchedule const& rS )
{
  return lS.currentGPA < rS.currentGPA; //Return bool value
}
void classSchedule::upGPA(classSchedule schedule[], int& numElems)
{
    classSchedule* start = &schedule[0];  //Declare pointer start
    classSchedule* finish = start+numElems; //Declare pointer finish
    sort( start, finish, orderByGPA); //Call std::sort with stated parameters

}

void classSchedule::downGPA(classSchedule schedule[], int& numElems)
{
    //Sorts it ascending then calls standard reverse function
    upGPA(schedule, numElems);
    classSchedule* start = &schedule[0];
    classSchedule* finish = start+numElems;
    reverse(start, finish);

}
bool orderByCredit( classSchedule const& lS, classSchedule const& rS )
{
  return lS.creditHours < rS.creditHours; //Return bool value
}
void classSchedule::upCredit(classSchedule schedule[], int& numElems)
{
    classSchedule* starts = &schedule[0];  //Declare pointer starts
    classSchedule* finishs = starts+numElems; //Declare pointer finishs
    sort( starts, finishs, orderByCredit); //Call std::sort with stated parameters
}
void classSchedule::downCredit(classSchedule schedule[], int& numElems)
{
    //Sorts it ascending then calls standard reverse function
    upCredit(schedule, numElems);
    classSchedule* start = &schedule[0];
    classSchedule* finish = start+numElems;
    reverse(start, finish);
}
