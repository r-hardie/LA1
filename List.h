#ifndef LIST_H
#define LIST_H

#include<iostream>
using namespace std;

template<typename T>
class List {
public:
	List();//defualt con
	List(T inputList[], int size);
	List(T v, int n);//if n is negative, exception.
	List(T v); // create list with only one value v of size.
	virtual ~List();

	List(const List& obj);//copy constructor has to be const ref &  always....
	List& operator=(const List& obj);//self assignment check!,assignment operator need to return a list (ref &)
	List(List&& tempobj);//move constructor
	List& operator=(List&& tempobj);//move assignment operator

	virtual int getSize()const final;
	virtual int getCapacity()const final;
	virtual T getValue(int index)const final;

	virtual void append(T v);
	virtual void append(T v[], int size);
	virtual void insert(T v, int index);
	virtual void insert(T v[], int size, int index);
	void remove(T v, bool all = false);
	virtual void sort(bool asc = true);//true = ascending order, false = descending order
	virtual int search(T v);

	List<T> operator+(T v);

	List<T> operator+(const List<T>& obj);//(l+l)or(x+l);
	List<T> operator-(const List<T>& obj);

	List<T>& operator+=(const List<T>& obj);
	List<T>& operator-=(const List<T>& obj);

	List<T>& operator--();
	List<T> operator--(int dummy);

	T& operator[](int index);

	template<typename U>
	friend ostream& operator<<(ostream& outputStream, const List<U>& myList);

	template<typename U>
	friend istream& operator>>(istream& inputStream, List<U>& myList);

protected:
	T* Arr; // a pointer to the first item of the list.
	int size; // the number of items in the list
	int capacity; // The miximum number of items that can be in the list.
private:
};

template<typename T>
ostream& operator<<(ostream& outputStream, const List<T>& myList);

template<typename T>
istream& operator>>(istream& inputStream, List<T>& myList);
#endif