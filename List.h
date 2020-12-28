#include <iostream>

#ifndef LIST
#define LIST

const int CAPACITY = 1024;
typedef int ElementType;

class List {
private:
	int mySize; //current size of list stores in myArray
	ElementType myArray[CAPACITY];  //array to store list elements

public:
	List();
	bool empty() const;
	void insert(ElementType item, int pos);
	void erase(int pos);
	void display(ostream& out)const;
};

ostream& operator<<(ostream& out, const List& aList);

#endif // LIST

