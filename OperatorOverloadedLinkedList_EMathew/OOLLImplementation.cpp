///////////////////////////////////////////////////////////////////////////////
// Author: Mark Dencler
// Description: This is an implementation and demo of a simple Linked List.
//              This is the IMPLEMENTATION file for the 'OOLList'.
///////////////////////////////////////////////////////////////////////////////
#include "OOLLSpecification.h"

OOLList::OOLList() {
	this->start = NULL;
}

//GETS LIST SIZE
int OOLList::getListSize() {
	int listSize = 0;
	OOLNode* iterator = this->start;//ITERATOR COMBS THROUGH THE LINKED LIST
	if (iterator == NULL) {//LOOKS FOR EMPTY LIST
		cout << "THE LIST HAS 0 ELEMENTS" << endl;
	}
	while (iterator != NULL) {//INCREMENTS LISTSIZE UNTILL TAIL OF LINKED LIST
		listSize++;
		iterator = iterator->next;
	}
	return listSize;
}

int OOLList::getListSizeInBytes() {//SAME IMPLEMENTATION AS LIST SIZE
	int listSizeInBytes = 0;
	OOLNode* iterator = this->start;
	if (iterator == NULL) {
		cout << "THE LIST HOLDS 0 BYTES" << endl;
	}
	while (iterator != NULL) {
		listSizeInBytes = listSizeInBytes + sizeof iterator;//USES SIZE OF TO GET BYTE SIZE
		iterator = iterator->next;
	}
	return listSizeInBytes;
}

int OOLList::getListElements(int* populateMeWithElements) {//POPULATES AN ARRAY WITH THE LINKED LIST PAYLOADS
	int ListSize = getListSize();
	populateMeWithElements = new int[ListSize];//ALLOCATES MEMORY BASED ON LINKED LIST SIZE
	OOLNode* iterator = this->start;//ITERATOR
	for (int i = 0; i < ListSize-1; i++) {//POPULATES ARRAY WITH LIST PAYLOADS
		if (iterator == nullptr) {//CHECKS FOR EMPTY ARRAY
			cout << "THE LIST HAS 0 ELEMENTS" << endl;
			delete[] populateMeWithElements;
			}
		else {
			if (iterator->next != nullptr) {//IF IT IS NOT AN EMPTY LIST, ASSIGNS PAYLOAD TO ARRAY
				populateMeWithElements[i] = iterator->payload;
				iterator = iterator->next;
				}
			}
	}
	for (int i = 0; i < ListSize -1; i++) {//PRINTS ARRAY
		cout << populateMeWithElements[i] << endl;
	}
	delete[] populateMeWithElements;
	return true;
}


int OOLList::addElement(int addme) {//ADDS ELEMENT TO LINKED LIST
	OOLNode* pushMe = nullptr;//WILL CREATE NEW NODE
	pushMe = new(OOLNode);//CREATES NEW NODE
	if (pushMe == nullptr) {//CHECKS IF NODE WAS CREATED
		return false;
	}
	pushMe->next = nullptr;//ASSIGNS NODE POINTER TO NULL
	pushMe->payload = addme;//ASSIGNS NODE PAYLOAD TO ADD VALUE

	if (this->start == nullptr) {//IF EMPTY LIST
		this->start = pushMe;
		return true;
	}
	else
	{
		OOLNode* iterator = this->start;//ITERATOR
		OOLNode* prevNode = this->start;//LOOKS FOR PREVIOUS NODE
		while (pushMe->payload >= iterator->payload) {//WHILE PAYLOAD IS GREATER THAT LIST PAYLOAD WE WILL INCREMENT ITERATOR
			if (iterator->next != nullptr) {//ALLOWS TO POPULATE ORDERED LINKED LIST
				iterator = iterator->next;
			}
			else {
				iterator->next = pushMe;//WHEN WE GET TO THE END, ASSUMES WE HAVE THE LARGEST VALUE, PUSHES TO END OF LINKED LIST
				return true;
			}
		}
		if (iterator->payload == start->payload) { //CHECKS TO SEE IF WE ARE AT THE HEAD OF THE LIST
			pushMe->next = this->start;//PUSHES TO HEAD
			this->start = pushMe;
			return true;
		}
		while (prevNode->next->payload != iterator->payload) {//ITERATES TO FIND NODE PREVIOUS TO THE LARGER VALUE
			prevNode = prevNode->next;
		}
		prevNode->next = pushMe;//SETS IT TO THE ADD VALUE
		pushMe->next = iterator;
		return true;
	}
	return true;
}

bool OOLList::deleteElement(int& deleteMe) {
	if (this->start == nullptr) {
		cout << "THE LIST IS EMPTY" << endl;
		return true;
	}

	// BORDER CASE #2 - The list has a single element.
	else if (this->start->next == nullptr && start->payload == deleteMe) {
		delete this->start;
		this->start = nullptr;
		return true;
	}

	else {
		OOLNode* iterator = this->start;
		OOLNode* prevNode = this->start;
		OOLNode* currentNode = this->start;

		//ITERATE TO FIND THE VALUE
		//CHECKS IF ITERATOR IS EQUAL TO DELETE VALUE AND ITERATOR IS NOT THE LAST LINK
		while (iterator->payload != deleteMe && iterator->next != nullptr){ 
			iterator = iterator->next;
		}
		currentNode = iterator;//SETS CURRENTNODE TO ITERATOR
		//IF WE WENT THROUGH THE LIST AND DIDNT FIND A MATCH
		//ALSO CHECKS TO ENSURE ITS NOT THE LAST VALUE WITH MATCH
		if (iterator->next == nullptr && iterator->payload != deleteMe) {
			cout << "NOT FOUND" << endl;
		}
		//IF ITERATOR IS NOT THE START VALUE
		else if (iterator != start) {
			//SETS PREVIOUS NODE
			while (prevNode->next->payload != iterator->payload) {
				prevNode = prevNode->next;
			}
			prevNode->next = iterator->next;
			delete currentNode;
			if (iterator->payload == deleteMe) {
				return false;
			}
		}
		//IF ITERATOR IS THE START VALUE
		else if (currentNode == this->start) {//CHECKS IF WE ARE START VALUE
			this->start = this->start->next;
			delete currentNode;
			if (this->start->payload == deleteMe) {//CHECKS IF THE NEXT VALUE IS THE SAME SO THAT WE CAN DELETE IT AS WELL
				return false;
			}
			return true;
		}
		//MAY NOT BE NEEDED*//IF ITERATOR IS THE LAST AND VALUE IS MORE THAN THE DELETE VALUE
		else if (iterator->next == nullptr && iterator->payload > deleteMe) {
			cout << "Value out of range" << endl;
			return true;
		}

	}
	return true;
}
