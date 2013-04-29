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

/**A templated dynamic unbounded array list
@author Jesus Garcia*/

template <typename T>
class MyList {
	public:
		/**Default Constructor*/
		MyList();
		/**Constructor with set capacity
		@param capacity The max amount that fits in list*/
		MyList(int capacity);
		/**Destructor*/
		~MyList();
		/**Adds item to back of list.
		@param fname Item to be pushed in list*/
		void push_back(const T& fname);
		/**Returns size
		@return Size of list*/
		int size();
		/**Returns item at location
		@param loc Location of item
		@return Reference to item*/
		T& at(int loc);
		/**Removes item from list
		@param val Item to be removed
		@return Boolean whether or not the item was removed*/
		bool remove(T val);
		/**Removes item from list
		@param Location where the item is
		@return Item removed*/
		T pop(int loc);
		/**Operator overloader of brackets
		@param loc Location of item
		@return Item*/
		T& operator[](int loc);
		/**Clears list*/
		void clear();
		/**Return front of list
		@return Reference to item*/
		T& front();
		/**Return back of list
		@return Reference to item*/
		T& back();
	private:
		/**Array*/
		T *data_;
		/**Size*/
		int size_;
		/**Capacity*/
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
