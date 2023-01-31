#include<iostream>
#include"List.h"
#include"List.cpp"
#include"SortedList.h"
#include"SortedList.cpp"

using namespace std;

void testException() {
	int eiArr[3] = { 1,2,3 };
	List<int> errList(eiArr, -1);
}
void test() {
	int iArr1[5] = { 1,5,4,1,7 };
	int iArr2[4] = { 2,1,2,5 };

	List<int> inputList;
	cout << "Enter capacity and size then, put item in the List " << endl;
	cin >> inputList;
	cout << "inputList: " << inputList << endl;
	List<int> arrList(iArr1, 5);
	cout << "arrList: " << arrList << endl;
	List<int> multipleOfVLsit(4, 4);
	cout << "multipleOfVLsit: " << multipleOfVLsit << endl;
	List<int> oneOfVList(1);
	cout << "oneOfVList: " << oneOfVList << endl;
	List<int> copyList(arrList);
	cout << "copyList: " << copyList << endl;
	List<int> copyList1 = copyList;
	cout << "copList1" << copyList1 << endl;
	List<int> moveList(multipleOfVLsit + oneOfVList);
	cout << "moveList" << moveList << endl;
	List<int> sumList = multipleOfVLsit + oneOfVList;
	cout << "sumList : " << sumList << endl;
	sumList += oneOfVList;
	cout << "sumList += oneOfVList: " << sumList << endl;
	List<int> subList = arrList - multipleOfVLsit;
	cout << "subLsit: " << subList << endl;
	subList -= oneOfVList;
	cout << "subList -= oneOfVList: " << subList << endl;
	cout << "Pre fixed -- to subList: " << --subList << endl;
	cout << "Post fixed -- to subList: " << subList-- << endl;
	cout << "Next Line of post fixed -- to subList: " << subList << endl;
	cout << "Size of subList: " << subList.getSize() << endl;
	cout << "Capacity of subList: " << subList.getCapacity() << endl;
	cout << "Accessing the 3rd Index of arrList with []: " << arrList[2] << endl;
	cout << "Accessing the 3rd Index of arrList with get()" << arrList.getValue(2) << endl;
	cout << "Search number'4' from arrList: Index " << arrList.search(4) << endl;
	arrList.append(1);
	cout << "Appending single value to arrList: " << arrList << endl;
	arrList.append(iArr2, 4);
	cout << "Appending a Arrey to to arrList: " << arrList << endl;
	multipleOfVLsit.insert(10, 2);
	cout << "Insert a single value to 3rd Index of multipleOfVLsit: " << multipleOfVLsit << endl;
	multipleOfVLsit.insert(iArr2, 4, 2);
	cout << "Insert a Arrey to 3rd Index of multipleOfVLsi: t" << multipleOfVLsit << endl;
	multipleOfVLsit.remove(4, false);
	cout << "Remove only first of 4 in multipleOfVList: " << multipleOfVLsit << endl;
	multipleOfVLsit.remove(4, true);
	cout << "Remove all of 4 in multipleOfVList: " << multipleOfVLsit << endl;
	arrList.sort(true);
	cout << "Ascending sort arrList" << arrList << endl;
	arrList.sort(false);
	cout << "Dscending sort arrList" << arrList << endl;

	double dArr1[3] = { 1.2, 3.4, 1.3 };
	double dArr2[2] = { 10.2, 3.5 };

	SortedList<double> inputSortedList;
	cout << "Enter capacity and size then, put item in the SortedList " << endl;
	cin >> inputSortedList;
	cout << "inputSortedList: " << inputSortedList << endl;
	SortedList<double> arrSortedList(dArr1, 3);
	cout << "arrSortedList: " << arrSortedList << endl;
	SortedList<double> multipleOfVSortedList(3.14, 3);
	cout << "multipleOfVSortedList: " << multipleOfVSortedList << endl;
	SortedList<double> oneOfVSortedList(3.4);
	cout << "oneOfVSortedList: " << oneOfVSortedList << endl;
	SortedList<double> copySortedList(arrSortedList);
	cout << "copySortedList: " << copySortedList << endl;
	SortedList<double> copySortedList1 = copySortedList;
	cout << "copySortedList1: " << copySortedList1 << endl;
	SortedList<double> moveSortedList(multipleOfVSortedList + oneOfVSortedList);
	cout << "moveSortedList: " << moveSortedList << endl;
	SortedList<double> sumSortedList = multipleOfVSortedList + oneOfVSortedList;
	cout << "sumSortedList: " << sumSortedList << endl;
	sumSortedList += oneOfVSortedList;
	cout << "sumSortedList += oneOfVSortedList: " << sumSortedList << endl;
	SortedList<double> subSortedList = arrSortedList - oneOfVSortedList;
	arrSortedList -= oneOfVSortedList;
	cout << "arrSortedList -= oneOfVSortedList: " << arrSortedList << endl;
	cout << "pre fixed -- to multipleOfVSortedList" << --multipleOfVSortedList << endl;
	cout << "Post fixed -- to multipleOfVSortedList" << multipleOfVSortedList-- << endl;
	cout << "next line of Post fixed -- to multipleOfVSortedList" << multipleOfVSortedList << endl;
	cout << "Size of copySortedList1: " << copySortedList1.getSize() << endl;
	cout << "Capacity of copySortedList1: " << copySortedList1.getCapacity() << endl;
	cout << "Acessing 2nd index of copySortedList1 with get() " << copySortedList1.getValue(2) << endl;
	cout << "Acessing 2nd index of copySortedList1 with [] " << copySortedList1[2] << endl;
	cout << "Search number '3.4' from copySortedList1: Index" << copySortedList1.search(3.4) << endl;
	copySortedList1.append(3.14);
	cout << "Appending single value to copyList1: " << copySortedList1 << endl;
	copySortedList1.append(dArr2, 2);
	cout << "Appending an array to copyList1: " << copySortedList1 << endl;
	copySortedList1.insert(1.0, 4);
	cout << "Insert a single value to 5th index of copyList1: " << copySortedList1 << endl;
	copySortedList1.insert(dArr2, 2, 0);
	cout << "Insert an arrey to first index of copyList1: " << copySortedList1 << endl;
	multipleOfVSortedList.remove(3.14, false);
	cout << "remove only first '3.14' in multipleOfVSortedList: " << multipleOfVSortedList << endl;
	multipleOfVSortedList.remove(3.14, true);
	cout << "remove all of 3.14 in multipleOfVSortedList: " << multipleOfVSortedList << endl;

}
int main() {
	try {
		test();
		testException();
	}
	catch (out_of_range& err) {
		cout << err.what() << endl;
	}
	return 0;
}

/*
#ifndef LAB_H
#define LAB_H
#include <iostream>

using namespace std;

template <typename T>
class List {
public:
	List(); o
	List(T inputList[], int size); // has to be positive size, throw exception for negative size or use noexcept if funtion doesnt throw exception o
	List(T v, int n); // constructor that creates an object including “n” occurrences of value “v" o

	virtual ~List(); o

	List(const List& obj); // copy constructor has to be const ref &
	List& operator=(const  List& obj); // self-Assignment check!!!!!!!! // assignment operator need to return a list, result has to be able to be used on the left side return list reference


	List(List&& tempObj);// move constructor // list l = f()l <- r value does not exist after it is done it is dying after next line
	List& operator=(List&& tempobj);

	int getSize() const final; // getter for size // final means final implementation dont attempt to override

	int getCapacity() const final; // getter for capacity

	List(T v); // create list with only one value v of size 1

	T getItem(int index) const final; // throw exception for invalid index
	virtual void append(T item); // add item to end of list , has to be changed for sorted
	virtual void append(T v[], int size);
	virtual void insert(T item, int index);
	virtual void insert(T v[], int size, int index);
	virtual void remove(T v, bool all = false);
	void remove(T item, int index);
	virtual void sort(bool asc = true);
	virtual int search(T item);
	void listOutput(List L);
	void listExtract(istream& i);

	// List<T> operator+ (T v); // not necessary as it converts v to list with earlier constructor singel value

	List<T> operator+(const List<T>& obj); // make sure it makes copy and returns copy keeps original list obj without modifying object passed to it or calling it

	List<T> operator-(const List<T>& obj); // read above but for subtraction

	T& operator[](int index); // return T value for that index, return reference so that value can be changed like list1[x] = 9

	//impliment -= & += operators if including - & + operators

	List<T>& operator+=(const List<T>& obj); // must return list reference as it modifies calling object

	List<T>& operator-=(const List<T>& obj); // look above

	List<T>& operator--(); // must implement l1-- & --l1. no input parameter is equal to --l1 prefix format, l value. can write int x = 5; (--x) = 2; l1 after change should be displayed

	List<T> operator--(int dummy); // postfix not an left value returns a copy of a list. make change, return before change

	template <typename U> // need to add another template to be able to use across multiple data types chained together in friend function
	friend ostream& operator<<(ostream& outputStream, const List<U>& myList); // need friend to access private data types

	friend istream& operator>>(istream& outputStream, List<T>& myList);

private:
	T* item; // pointer to the first item in the list
	int size; // number of items in list
	int capacity; // the max number of items that can be in the list


};

template <typename T>
ostream& operator<<(ostream& outputStream, const List<T>& myList); //past list by ref to be faster and be constant, ostream is by ref since it will be changed, return type also ostream to be used in a chain

template <typename T>
istream& operator>>(istream& inputStream, List<T>& myList); // same type as istream as needs to be modified

// user should be able to input 1 2 3 4 from cin>>l1

template<typename T>
List<T>::List() {
	item = nullptr;
	size = 0;
	capacity = 10;
}*/