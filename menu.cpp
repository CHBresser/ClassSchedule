#include <iostream>
#include <string>
#include "menu.h"
#include "RecordStructures.h"

using namespace std;

void menu(classSchedule schedule[], int& numElems)
{
	int menuOption;

	cout << endl << "What would you like to do: "
		 << endl << "1. Sort then display the schedule."
		 << endl << "2. Add a new Item."
		 << endl << "3. Delete a Item."
		 << endl << "4. Display the Unsorted Schedule." << endl;
	cin >> menuOption;
	switch(menuOption)
	{
		case(1):
			sort(schedule, numElems);
			break;
		case(2):
			schedule->addEntry(schedule, numElems);
			break;
        case(3):
			schedule->deleteEntry(schedule, numElems);
			break;
		case(4):
			schedule->outputToConsole(schedule, numElems);
			break;
	}
}
void sort(classSchedule schedule[], int& numElems)
{
	int menuItem;
	cout << endl << "How would you like to sort?"
		 << endl << "1. Ascending by GPA."
		 << endl << "2. Descending by GPA."
		 << endl << "3. Ascending by Credit Hours."
		 << endl << "4. Descending by Credit Hours." << endl;
	cin >> menuItem;


	switch(menuItem)
	{
        case(1):
			schedule->upGPA(schedule, numElems);
			schedule->outputToConsole(schedule, numElems);
			break;
		case(2):
            schedule->downGPA(schedule, numElems);
            schedule->outputToConsole(schedule, numElems);
            break;
		case(3):
			schedule->upCredit(schedule, numElems);
			schedule->outputToConsole(schedule, numElems);
			break;
		case(4):
			schedule->downCredit(schedule, numElems);
			schedule->outputToConsole(schedule, numElems);
			break;
	}

	char saveOrNo;
	cout << endl << "Would you like to save all changes?(Y/N)";
	cin >> saveOrNo;

	if (saveOrNo == 'Y' || saveOrNo == 'y')
        schedule->outputToFile(schedule, numElems);
}

