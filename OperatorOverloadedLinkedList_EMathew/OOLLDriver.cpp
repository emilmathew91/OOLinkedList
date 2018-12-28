///////////////////////////////////////////////////////////////////////////////
// Author: Mark Dencler
// Description: This is an implementation and demo of a simple Linked List.
//              This is the DRIVER file.
///////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <stdlib.h>		// for srand(), rand()
#include <time.h>		// for time()
#include <conio.h>		// for _getch()
#include "OOLLSpecification.h"

using namespace std;
//RANGES FOR THE NUMBER OF ITERATIONS THE VALUES WILL BE ENTERED
const int LOWER_RANDOM_RANGE = 100;
const int UPPER_RANDOM_RANGE = 100000;

//RANGES FOR THE VALUES TO BE ENTERED
const int VALUE_LOWER = 1;
const int VALUE_UPPER = 100;
//USED FOR RANDOMIZING THE INTERVAL
int randInterval(int lower, int upper);

int main() {
	//DECLARES
	int listSize = 0;
	int listSizeInBytes = 0;
	int* elementList;
	// Seed the RNG.
	srand((unsigned int)time(NULL));
	//INITIALIZE
	OOLList myList;
	//RANDOMIZE ITERATIONS
	int randomIterations = randInterval(LOWER_RANDOM_RANGE, UPPER_RANDOM_RANGE);
	for (int i = 0; i < 100; i++) {
		cout << endl << right << setw(22) << setfill('*') << "ROUND " << i + 1 << " OF 100 " << " ROUNDS";
		cout << right << setw(22) << setfill('*') << " " << endl <<  endl;
		cout << right << setw(30) << setfill('*') << "PRINTING LIST";
		cout << right << setw(30) << setfill('*') << " " << endl << endl;
		//EMPTY LIST BUT IT DOES WORK
		//ALLOCATE MEMORY FOR THE ARRAY OF ELEMENTS
		elementList = new int[myList.getListSize()];//INITALIZES ELEMENT LIST
		myList.getListElements(elementList);
		//POPULATE LIST AND RETURN VALUES
		int elementCount1 = randInterval(LOWER_RANDOM_RANGE, UPPER_RANDOM_RANGE);
		for (int i = 0; i < elementCount1; i++) {
			myList.addElement(randInterval(VALUE_LOWER, VALUE_UPPER));
		}
		//POPULATE LIST WITH OVERLOADED OPERATOR
		int elementCount2 = randInterval(LOWER_RANDOM_RANGE, UPPER_RANDOM_RANGE);
		for (int i = 0; i < elementCount2; i++) {
			myList + (randInterval(VALUE_LOWER, VALUE_UPPER));
		}
		cout << endl << "ADDING " << elementCount1 + elementCount2 << " ELEMENTS TO THE LIST" << endl;
		cout << endl << "ADDING ELEMENTS FOR ROUND " << i + 1 << " OF 100 " << " COMPLETE" << endl;
		cout << endl;
		listSize = myList.getListSize();
		cout << "THE LIST CONTAINS " << listSize << " ELEMENTS AFTER ADDITION" << endl;
		listSizeInBytes = myList.getListSizeInBytes();
		cout << "THE LIST HOLDS " << listSizeInBytes << " BYTES OF DATA AFTER ADDITION" << endl;
		// myList.getListElements(elementList); //THIS IS HERE IN CASE YOU WANTED TO PRINT THE ARRAY OUT
		cout << endl << "**ADDITION COMPLETE***" << endl;
		cout << endl;
		cout << "**SUBTRACTION COMMENCED**" << endl;
		//POP ELEMENTS OFF
		for (int i = 1; i <= 50; i++) {
			bool diffNextElement = myList.deleteElement(i);
			while (!diffNextElement) {
				diffNextElement = myList.deleteElement(i);
			}
		}
		//POP ELEMENTS USING AN OVERLOADED OPERATOR
		for (int i = 51; i <= 100; i++) {
			bool diffNextElement = myList-(i);
			while (!diffNextElement) {
				diffNextElement = myList-(i);
			}
		}
		cout << endl << "SUBTRACTING ELEMENTS FOR ROUND " << i + 1 << " OF 100 " << " COMPLETE" << endl;
		cout << endl;
		listSize = myList.getListSize();
		cout << "THE LIST CONTAINS " << listSize << " ELEMENTS AFTER SUBTRACTION" << endl;
		listSizeInBytes = myList.getListSizeInBytes();
		cout << "THE LIST HOLDS " << listSizeInBytes << " BYTES OF DATA AFTER SUBTRACTION" << endl << endl;
	}
	cout << "PROGRAM RAN SUCCESSFULLY " << endl;
	_getch();
	return 0;
}
	
int randInterval(int lower, int upper) {
	return lower + (rand() % (upper - lower + 1));
}