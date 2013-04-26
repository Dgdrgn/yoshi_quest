#ifndef MYLIST_H
#define MYLIST_H
#ifndef STRING_H
#define STRING_H
#ifndef VECTOR_H
#define VECTOR_H
#include <stdexcept>
#include <iostream>

using namespace std;

const int DEFAULT_CAPACITY = 3;

template <typename T>
class MyList {
	public:
		MyList();
		MyList(int capacity);
		~MyList();
		void push_back(const T& fname);
		int size();
		T& at(int loc);
		bool remove(T val);
		T pop(int loc);
		T& operator[](int loc);
		void clear();
		T& front();
		T& back();
	private:
		T *data_;
		int size_;
		int capacity_;
};

template <typename T>
MyList<T>::MyList() {
	data_ = new T[DEFAULT_CAPACITY];
	size_ = 0;
	capacity_ = DEFAULT_CAPACITY;
}

template <typename T>
MyList<T>::MyList(int capacity) {
	data_ = new T[capacity];
	size_ = 0;
	capacity_ = capacity;
}

template <typename T>
MyList<T>::~MyList() {
	delete [] data_;
}

template <typename T>
void MyList<T>::push_back(const T& fname) {
	if(size_ == capacity_) {
		capacity_ *= 2;
		T *tempData = data_;
		data_ = new T[capacity_];
		for(int j = 0; j < size_; j++) {
			data_[j] = tempData[j];
		}
		delete [] tempData;
	}
	data_[size_] = fname;
	size_++;
}

template <typename T>
int MyList<T>::size() {
	return size_;
}

template <typename T>
T& MyList<T>::at(int loc) {
	if(loc >= size_) {
		throw invalid_argument("Out of bounds");
	}
	return data_[loc];
}

template <typename T>
bool MyList<T>::remove(T val) {
	for(int i = 0; i < size_; i++) {
		if(data_[i] == val) {
			for(int j = i; j < size_-1; j++) {
				data_[j] = data_[j+1];
			}
			size_--;
			return true;
		}
	}
	return false;
}

template <typename T>
T MyList<T>::pop(int loc) {
	if(loc >= size_) {
		throw invalid_argument("Out of bounds");
	}
	T val = at(loc);
	remove(val);
	return val;
}

template <typename T>
T& MyList<T>::operator[] (int loc) {
	return at(loc);
}

template <typename T>
void MyList<T>::clear () {
	for(int i = size_; i > 0; i--) {
		remove(data_[i-1]);
	}
	size_ = 0;
}

template <typename T>
T& MyList<T>::front()
{
	return at(0);
}

template <typename T>
T& MyList<T>::back()
{
	return at(size_-1);
}

#endif
#endif
#endif
