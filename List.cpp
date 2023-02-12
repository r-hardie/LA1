#include<iostream>
#include"List.h"

using namespace std;

template<typename T>
List<T>::List() : size(0), capacity(0), Arr(nullptr) {
}

template<typename T>
List<T>::List(T inputList[], int size) : size(size) {
	if (size < 0) {
		throw out_of_range("The Size of List can not be negative");
	}
	capacity = size;
	Arr = new T[capacity];
	for (int i = 0; i < size; i++) {
		Arr[i] = inputList[i];
	}
}

template<typename T>
List<T>::List(T v, int n) : size(n) {
	if (size < 0) {
		throw out_of_range("The Size of List can not be negative");
	}
	Arr = new T[n];
	for (int i = 0; i < n; i++) {
		Arr[i] = v;
	}
	capacity = size;
}

template<typename T>
List<T>::List(T v) : size(1), capacity(1) {
	Arr = new T[1];
	Arr[0] = v;
}

template<typename T>
List<T>::List(const List& obj) : size(obj.size), capacity(obj.capacity) {
	Arr = new T[obj.capacity];
	for (int i = 0; i < size; i++) {
		Arr[i] = obj.Arr[i];
	}
}

template<typename T>
List<T>& List<T>:: operator=(const List& obj) {
	if (this != &obj) {
		if (this->Arr != nullptr) {
			delete[] this->Arr;
		}
		Arr = new T[obj.size];
		for (int i = 0; i < obj.size; i++) {
			Arr[i] = obj.Arr[i];
		}
		size = obj.size;
		capacity = obj.capacity;
	}
	return *this;
}

template<typename T>
List<T>::List(List&& tempobj) : Arr(tempobj.Arr), size(tempobj.size), capacity(tempobj.capacity) {
	tempobj.Arr = nullptr;
}

template<typename T>
List<T>& List <T>::operator=(List&& tempobj) {
	if (this != tempobj) {
		Arr = tempobj.Arr;
		size = tempobj.size;
		capacity = tempobj.capacity;

		tempobj.Arr = nullptr;
	}
	return *this;
}

template<typename T>
List<T>::~List() {
	delete[] Arr;
	Arr = nullptr;
	size = 0;
	capacity = 0;
}

template<typename T>
int List<T>::getSize() const {
	return size;
}

template<typename T>
int List<T>::getCapacity() const {
	return capacity;
}

template<typename T>
T List<T>::getValue(int index) const {
	if (index < 0 || index > capacity) {
		throw out_of_range("Index out of capacity.");
	}
	return Arr[index];
}

template<typename T>
void List<T>::append(T v) {
	if (size == capacity) {
		T* tTemp = new T[size + 1];

		for (int i = 0; i < size; i++) {
			tTemp[i] = Arr[i];
		}

		delete[] Arr;
		tTemp[size] = v;
		Arr = tTemp;
		size++;
		capacity = size;
	}
	else {
		size++;
		Arr[size] = v;
	}
}

template<typename T>
void List<T>::append(T v[], int sizeOfv) {
	if (capacity < size + sizeOfv) {
		T* tTemp = new T[capacity + sizeOfv];

		for (int i = 0; i < size; i++) {
			tTemp[i] = Arr[i];
		}
		for (int i = size; i < size + sizeOfv; i++) {
			tTemp[i] = v[i - size];
		}

		delete[] Arr;
		Arr = tTemp;
		size = size + sizeOfv;
		capacity = size;

	}
	else {
		for (int i = size; i < size + sizeOfv; i++) {
			Arr[i] = v[i];
		}
		size = size + sizeOfv;
	}
}


template<typename T>
void List<T>::insert(T v, int index) {
	if (size == capacity) {
		T* tTemp = new T[size + 1];

		for (int i = 0; i < index; i++) {
			tTemp[i] = Arr[i];
		}

		tTemp[index] = v;

		for (int i = index; i < size; i++) {
			tTemp[i + 1] = Arr[i];
		}
		size++;
		capacity = size;
		delete[] Arr;
		Arr = tTemp;
	}
	else {
		T* tTemp = new T[capacity];

		for (int i = 0; i < index; i++) {
			tTemp[i] = Arr[i];
		}

		tTemp[index] = v;

		for (int i = index; i < size; i++) {
			tTemp[i + 1] = Arr[i];
		}

		size++;
		delete[] Arr;
		Arr = tTemp;
	}
}

template<typename T>
void List<T>::insert(T v[], int sizeOfv, int index) {
	if (capacity < size + sizeOfv) {
		T* tTemp = new T[size + sizeOfv];

		for (int i = 0; i < index; i++) {
			tTemp[i] = Arr[i];
		}

		for (int i = 0; i < sizeOfv; i++) {
			tTemp[i + index] = v[i];
		}

		for (int i = index; i < size; i++) {
			tTemp[i + sizeOfv] = Arr[i];
		}

		delete[] Arr;
		Arr = tTemp;
		size = size + sizeOfv;
		capacity = size;
	}
	else {
		T* tTemp = new T[capacity];

		for (int i = 0; i < index; i++) {
			tTemp[i] = Arr[i];
		}

		for (int i = 0; i < sizeOfv; i++) {
			tTemp[i + index] = v[i];
		}

		for (int i = index; i < size; i++) {
			tTemp[i + sizeOfv] = Arr[i];
		}

		delete[] Arr;
		Arr = tTemp;
		size = size + sizeOfv;
	}
}

template<typename T>
void List<T>::remove(T v, bool all) {
	T* tTemp;
	int tTempIndex = 0;
	if (all == true) {
		int tempSize = size;

		for (int i = 0; i < size; i++) {
			if (Arr[i] == v) {
				tempSize--;
			}
		}

		tTemp = new T[tempSize];

		for (int i = 0; i < size; i++) {
			if (Arr[i] == v) {
				continue;
			}

			tTemp[tTempIndex] = Arr[i];
			tTempIndex++;
		}

		delete[] Arr;
		Arr = tTemp;
		size = tempSize;
	}
	else {
		int iCounter;
		tTemp = new T[size - 1];
		for (int i = 0; i < size; i++) {
			if (Arr[i] == v) {
				break;
			}
			tTemp[i] = Arr[i];
			tTempIndex++;
		}

		for (int i = tTempIndex; i < size - 1; i++) {
			tTemp[i] = Arr[i + 1];
		}

		delete[] Arr;
		Arr = tTemp;
		size--;

	}
}

template<typename T>
void List<T>::quickSort_DSC(T list[], int first, int last) {
	if (last > first) {
		int pivotIndex = partition_DSC(list, first, last);
		quickSort_DSC(list, first, pivotIndex - 1);
		quickSort_DSC(list, pivotIndex + 1, last);
	}
}
template<typename T>
int List<T>::partition_DSC(T list[], int low, int high) {
	T pivot = list[low];

	int j = low;
	for (int i = low + 1; i <= high; i++) {
		if (list[i] > pivot) {
			j++;
			T temp = list[i];
			list[i] = list[j];
			list[j] = temp;
		}
	}
	list[low] = list[j];
	list[j] = pivot;
	return j;
}

template<typename T>
void List<T>::quickSort_ASC(T list[], int first, int last) {
	if (last > first) {
		int pivotIndex = partition_ASC(list, first, last);
		quickSort_ASC(list, first, pivotIndex - 1);
		quickSort_ASC(list, pivotIndex + 1, last);
	}
}
template<typename T>
int List<T>::partition_ASC(T list[], int low, int high) {
	T pivot = list[low];

	int j = low;
	for (int i = low + 1; i <= high; i++) {
		if (list[i] < pivot) {
			j++;
			T temp = list[i];
			list[i] = list[j];
			list[j] = temp;
		}
	}
	list[low] = list[j];
	list[j] = pivot;
	return j;
}
template<typename T>
void List<T>::sort(bool asc) {
	if (asc == true) {
		quickSort_ASC(Arr, 0, size - 1);
	}
	else {
		quickSort_DSC(Arr, 0, size -1);
	}
}

template<typename T>
int List<T>::search(T key) {
	for (int i = 0; i < size; i++) {
		if (Arr[i] == key) {
			return i;
		}
	}
	return -1;//no exist v in the list;
}

template<typename T>
List<T> List<T>::operator+(T v) {
	List operand(v);
	List<T> result;

	result.Arr = new T[++capacity];
	result.size = size + operand.size;
	result.capacity = capacity + operand.capacity;

	for (int i = 0; i < size; i++) {
		result.Arr[i] = Arr[i];
	}

	for (int i = size; i < result.size; i++) {
		result.Arr[i] = operand.Arr[i - size];
	}

	return result;
}

template<typename T>
List<T> List<T>::operator+(const List<T>& obj) {
	List<T> result;

	result.Arr = new T[capacity + obj.capacity];
	result.size = size + obj.size;
	result.capacity = capacity + obj.capacity;

	for (int i = 0; i < size; i++) {
		result.Arr[i] = Arr[i];
	}

	for (int i = size; i < result.size; i++) {
		result.Arr[i] = obj.Arr[i - size];
	}

	return result;
}

template<typename T>
List<T> List<T>::operator-(const List<T>& obj) {
	List<T> result;
	result.Arr = new T[capacity];
	result.capacity = capacity;

	int resultIndex = 0;
	int tempSize = size;

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < obj.size; j++) {
			if (Arr[i] == obj.Arr[j]) {
				tempSize--;
				break;
			}
		}
	}

	result.size = tempSize;

	for (int i = 0; i < size; i++) {
		bool exist = false;
		for (int j = 0; j < obj.size; j++) {
			if (Arr[i] == obj.Arr[j]) {
				exist = true;
				break;
			}
		}
		if (exist == false) {
			result.Arr[resultIndex] = Arr[i];
			resultIndex++;
		}
	}

	return result;
}

template<typename T>
List<T>& List<T>::operator+=(const List<T>& obj) {
	T* tTemp = new T[capacity + obj.capacity];

	for (int i = 0; i < size; i++) {
		tTemp[i] = Arr[i];
	}
	for (int i = 0; i < obj.size; i++) {
		tTemp[i + size] = obj.Arr[i];
	}

	delete[] Arr;
	Arr = tTemp;
	size = size + obj.size;
	capacity = capacity + obj.capacity;

	return *this;
}

template<typename T>
List<T>& List<T>::operator-=(const List<T>& obj) {
	T* tTemp;
	int tempSize = size;
	int tempIndex = 0;
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < obj.size; j++) {
			if (Arr[i] == obj.Arr[j]) {
				tempSize--;
				break;
			}
		}
	}

	tTemp = new T[tempSize];

	for (int i = 0; i < size; i++) {
		bool exsist = false;
		for (int j = 0; j < obj.size; j++) {
			if (Arr[i] == obj.Arr[j]) {
				exsist = true;
				break;
			}
		}
		if (exsist == false) {
			tTemp[tempIndex] = Arr[i];
			tempIndex++;
		}
	}

	delete[] Arr;
	Arr = tTemp;
	size = tempSize;

	return *this;
}

template<typename T>//--l
List<T>& List<T>::operator--() {
	T* tTemp = new T[capacity];

	for (int i = 0; i < size - 1; i++) {
		tTemp[i] = Arr[i];
	}

	delete[]Arr;
	Arr = tTemp;
	size--;

	return *this;

}

template<typename T>//l--
List<T> List<T>::operator--(int dummy) {
	List result(*this);

	delete[]Arr;
	Arr = nullptr;
	size--;
	Arr = new T[capacity];

	for (int i = 0; i < size; i++) {
		Arr[i] = result.Arr[i];
	}

	return result;
}

template<typename T>
T& List<T>::operator[](int index) {
	return Arr[index];
}

template<typename T>
ostream& operator<<(ostream& outputStream, const List<T>& myList) {
	for (int i = 0; i < myList.size; i++) {
		outputStream << myList.Arr[i] << " ";
	}
	return outputStream;
}

template<typename T>
istream& operator>>(istream& inputStream, List<T>& myList) {

	delete[] myList.Arr;
	myList.Arr = nullptr;
	inputStream >> myList.capacity;
	inputStream >> myList.size;

	myList.Arr = new T[myList.capacity];

	for (int i = 0; i < myList.size; i++) {
		inputStream >> myList.Arr[i];
	}

	return inputStream;
}