#include<iostream>
#include <cassert>
using namespace std;

#include "List.h"

List::List()
	:mySize(0){}

bool List::empty() const {
	return mySize == 0;
}

ostream& operator<<(ostream& out, const List& aList) {
	aList.display(out);
	return out;
}

void List::display(ostream& out) const{
	for (int i = 0; i < mySize; i++)
		out << myArray[i] << " ";
}

void List::insert(ElementType item, int pos) {
	if (mySize == CAPACITY) {
		cerr << "*** Illegal location to insert -- " << pos << ". List unchanged. ***\n";
		exit(1);
	}

	if (pos<0 || pos>mySize) {
		cerr << "*** Illegal location to insert -- " << pos << ". List unchanged. ***\n";
		return;
	}

	for (int i = mySize; i > pos; i--)
		myArray[i] = myArray[i - 1];

	myArray[pos] = item;
	mySize++;
}

void List::erase(int pos) {
	if (mySize == 0) {
		cerr << "*** List is empty ***\n";
		return;
	}

	if (pos < 0 || pos >= mySize) {
		cerr << "Illegal location to delete -- " << pos << ". List unchanged. ***\n";
		return;
	}

	for (int i = pos; i < mySize; i++)
		myArray[i] = myArray[i + 1];

	mySize--;
}