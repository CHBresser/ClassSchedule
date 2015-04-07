#ifndef INCLUDED_RECORDSTRUCTURES_H
#define INCLUDED_RECORDSTRUCTURES_H
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

class classSchedule
{
	private:
		string classDepartment;
		int classNumber;

		string teacherLastName;
		string teacherFirstName;
		string roomWingAndNumber;
		string displayOrNot;
	public:
	    double currentGPA;
	    int creditHours;
		classSchedule();    // Default Constructor
		int inputFromFile(classSchedule []);
		void outputToConsole(classSchedule [], int numElems);
		void addEntry(classSchedule [], int& numElems);
		void deleteEntry(classSchedule [], int numElems);
		void upGPA(classSchedule [], int& numElems);
		void downGPA(classSchedule [], int& numElems);
		void downCredit(classSchedule [], int& numElems);
		void upCredit(classSchedule [], int& numElems);
		void outputToFile(classSchedule [], int& numElems);
};


#endif //INCLUDED_RECORDSTRUCTURES_H
