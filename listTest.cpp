#include "List.h"
#include <iostream>
#include <fstream>
using namespace std;

int main{
	ofstream testFile;
	testFile.open("listText.txt");

	List<int> list1 = new List();

	printList(testFile, list1, "list1");



	testFile.close;
	return 0;
}


//***testing functions only***
template<typename T>
void printList(ofstream file, List<T> l, string listName) {
	file << listName << endl;
	file << "\tsize: " << l.getSize() << endl;
	file << "\tcapacity: " << l.getCapacity() << endl;
	
	file << "\tArr: ";
	if (l.getSize == 0) {
		file << "empty list";
	} else {
		for (int i = 0; i < l.getSize(); i++) {
				file << l.getValue(i) << " ";
			}
	}
	
	file << endl;
}