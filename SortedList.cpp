#include<iostream>
#include"SortedList.h"
#include"List.h"

using namespace std;

template<typename T>
SortedList<T>::SortedList() : List<T>(), order(true) {
	sort(order);
}

template<typename T>
SortedList<T>::SortedList(T inputList[], int size) : List<T>(inputList, size), order(true) {
	sort(order);
}

template<typename T>
SortedList<T>::SortedList(T v, int n) : List<T>(v, n), order(true) {
	sort(order);
}

template<typename T>
SortedList<T>::SortedList(T v) : List<T>(v), order(true) {
	sort(order);
}

template<typename T>
SortedList<T>::SortedList(const List<T>& obj) : List<T>(obj), order(true) {
	sort(order);
}

template<typename T>
SortedList<T>::SortedList(List<T>&& tempobj) : List<T>(tempobj), order(true) {
	sort(order);
}

template<typename T>
SortedList<T>::~SortedList() {}

template<typename T>
SortedList<T>& SortedList<T>::operator+=(const SortedList<T>& obj) {
	T* tTemp = new T[this->capacity + obj.capacity];

	for (int i = 0; i < this->size; i++) {
		tTemp[i] = this->Arr[i];
	}
	for (int i = 0; i < obj.size; i++) {
		tTemp[i + this->size] = obj.Arr[i];
	}

	delete[] this->Arr;
	this->Arr = tTemp;
	this->size = this->size + obj.size;
	this->capacity = this->capacity + obj.capacity;

	sort(order);
	return *this;
}

template<typename T>
void SortedList<T>::setOrder(bool asc) {
	order = asc;
}

template<typename T>
bool SortedList<T>::getOrder() {
	return order;
}


template<typename T>
void SortedList<T>::append(T v) {
	if (this->size == this->capacity) {
		T* tTemp = new T[this->size + 1];

		for (int i = 0; i < this->size; i++) {
			tTemp[i] = this->Arr[i];
		}

		delete[] this->Arr;
		tTemp[this->size] = v;
		this->Arr = tTemp;
		this->size++;
		this->capacity = this->size;
	}
	else {
		this->size++;
		this->Arr[this->size] = v;
	}

	sort(order);
}

template<typename T>
void SortedList<T>::append(T v[], int sizeOfv) {
	if (this->capacity < this->size + sizeOfv) {
		T* tTemp = new T[this->capacity + sizeOfv];

		for (int i = 0; i < this->size; i++) {
			tTemp[i] = this->Arr[i];
		}
		for (int i = this->size; i < this->size + sizeOfv; i++) {
			tTemp[i] = v[i - this->size];
		}

		delete[] this->Arr;
		this->Arr = tTemp;
		this->size = this->size + sizeOfv;
		this->capacity = this->size;

	}
	else {
		for (int i = this->size; i < this->size + sizeOfv; i++) {
			this->Arr[i] = v[i];
		}
		this->size = this->size + sizeOfv;
	}

	sort(order);
}

template<typename T>
void SortedList<T>::insert(T v, int index) {
	if (this->size == this->capacity) {
		T* tTemp = new T[this->size + 1];

		for (int i = 0; i < index; i++) {
			tTemp[i] = this->Arr[i];
		}

		tTemp[index] = v;

		for (int i = index; i < this->size; i++) {
			tTemp[i + 1] = this->Arr[i];
		}
		this->size++;
		this->capacity = this->size;
		delete[] this->Arr;
		this->Arr = tTemp;
	}
	else {
		T* tTemp = new T[this->capacity];

		for (int i = 0; i < index; i++) {
			tTemp[i] = this->Arr[i];
		}

		tTemp[index] = v;

		for (int i = index; i < this->size; i++) {
			tTemp[i + 1] = this->Arr[i];
		}

		this->size++;
		delete[] this->Arr;
		this->Arr = tTemp;
	}

	sort(order);
}

template<typename T>
void SortedList<T>::insert(T v[], int sizeOfv, int index) {
	if (this->capacity < this->size + sizeOfv) {
		T* tTemp = new T[this->size + sizeOfv];

		for (int i = 0; i < index; i++) {
			tTemp[i] = this->Arr[i];
		}

		for (int i = 0; i < sizeOfv; i++) {
			tTemp[i + index] = v[i];
		}

		for (int i = index; i < this->size; i++) {
			tTemp[i + sizeOfv] = this->Arr[i];
		}

		delete[] this->Arr;
		this->Arr = tTemp;
		this->size = this->size + sizeOfv;
		this->capacity = this->size;
	}
	else {
		T* tTemp = new T[this->capacity];

		for (int i = 0; i < index; i++) {
			tTemp[i] = this->Arr[i];
		}

		for (int i = 0; i < sizeOfv; i++) {
			tTemp[i + index] = v[i];
		}

		for (int i = index; i < this->size; i++) {
			tTemp[i + sizeOfv] = this->Arr[i];
		}

		delete[] this->Arr;
		this->Arr = tTemp;
		this->size = this->size + sizeOfv;
	}

	sort(this->order);
}

template<typename T>
int SortedList<T>::search(T v) {
	for (int i = 0; i < this->size; i++) {
		if (this->Arr[i] == v) {
			return i;
		}
	}
	return -1;
}

template<typename T>
void SortedList<T>::sort(bool asc) {
	if (this->size <= 1) {
		return;
	}

	T tTemp;

	if (asc == true) {

		while (true) {

			bool sortFinish = true;

			for (int i = 0; i < this->size - 1; i++) {
				if (this->Arr[i] > this->Arr[i + 1]) {
					tTemp = this->Arr[i];
					this->Arr[i] = this->Arr[i + 1];
					this->Arr[i + 1] = tTemp;

					sortFinish = false;
				}
			}

			if (sortFinish == true) {
				break;
			}
		}
	}
	else {

		while (true) {

			bool sortFinish = true;

			for (int i = 0; i < this->size - 1; i++) {
				if (this->Arr[i] < this->Arr[i + 1]) {
					tTemp = this->Arr[i];
					this->Arr[i] = this->Arr[i + 1];
					this->Arr[i + 1] = tTemp;

					sortFinish = false;
				}
			}

			if (sortFinish == true) {
				break;
			}
		}
	}
}