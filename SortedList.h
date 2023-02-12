#ifndef SORT_LIST
#define SORT_LIST

#include<iostream>
#include"List.h"

template<typename T>
class SortedList : public List<T> {
private:
	bool order;

public:
	SortedList();//defualt con
	SortedList(T inputList[], int size);//if
	SortedList(T v, int n);//if n is negative, exception.
	SortedList(T v); // create list with only one value v of size.
	SortedList(const List<T>& obj);//copy constructor has to be const ref &  always....
	SortedList(List<T>&& tempobj);//move co
	~SortedList();

	
	SortedList<T>& operator+=(const SortedList<T>& obj);
	void setOrder(bool asc);
	bool getOrder();


	void sort(bool asc = true) override;
	void append(T v) override;
	void append(T v[], int size) override;
	void insert(T v, int index) override;
	void insert(T v[], int size, int index) override;
	int search(T v) override;
};
#endif
