#ifndef QUEUE_H
#define QUEUE_H
#include "llist.h"

template <typename T>
class Queue : public LList<T> {
	public:
		Queue();
		~Queue();
		T& front();
		T& back();
};

template <typename T>
Queue<T>::Queue() : LList<T>() {
	
}

template <typename T>
Queue<T>::~Queue() {
	LList<T>::clear();
}

//returns front of list
template <typename T>
T& Queue<T>::front() {
	return LList<T>::peek_front();
}

//returns back of list
template <typename T>
T& Queue<T>::back() {
	int loc = LList<T>::size_ - 1;
	return LList<T>::at(loc);
}
#endif
