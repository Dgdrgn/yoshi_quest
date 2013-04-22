#ifndef LLIST_H
#define LLIST_H
#include <stdexcept>

using namespace std;

template <typename T>
struct Item {
  T val;
  Item<T> *next;
};

template <typename T>
class LList {
 public:
  LList();
  ~LList();
  T& operator[] (int loc);
  bool empty() const;
  int size() const;
  void push_back(const T& new_val);
  void pop_front();
  T& peek_front() const;
  T& at(int loc) const;
  void clear();
 protected:
  Item<T> *getNodeAt(int loc) const;

 protected:
  Item<T> *head_;
  int size_;
};

// Write the constructor here
template <typename T>
LList<T>::LList()
{
	head_ = NULL;
	size_ = 0;
}

// Write the destructor here
template <typename T>
LList<T>::~LList()
{
  clear();
}

template <typename T>
T& LList<T>::operator[] (int loc) {
	return at(loc);
}

template <typename T>
bool LList<T>::empty() const
{
	if(head_ == NULL)
		return true;
	return false;
}

template <typename T>
int LList<T>::size() const
{
	return size_;
}

template <typename T>
Item<T>* LList<T>::getNodeAt(int loc) const
{
	Item<T> *temp = head_;
	if(loc < 0) {
		throw invalid_argument("Out of bounds.");
	}
	while(temp != NULL && loc > 0) {
		temp = temp->next;
		loc--;
	}
	if(temp == NULL) {
		throw invalid_argument("Out of bounds.");
	}
	return temp;
}

template <typename T>
void LList<T>::push_back(const T& new_val)
{
	Item<T>* newPtr = new Item<T>;
	newPtr->val = new_val;
	newPtr->next = NULL;
	
	if(head_ == NULL) 
		head_ = newPtr;
		
	else {
		Item<T>* temp = head_;
		while(temp->next) {
			temp = temp->next;
		}
		temp->next = newPtr;
	}
	size_++;
} 

template <typename T>
void LList<T>::pop_front()
{
	if(size_ == 0)
		throw invalid_argument("List is empty.");
	Item<T>* temp = head_;
	head_ = head_->next;
	delete temp;
	size_--;
}

template <typename T>
T& LList<T>::peek_front() const
{
	if(size_ == 0)
		throw invalid_argument("List is empty.");
	return at(0);
}

template <typename T>
T& LList<T>::at(int loc) const
{
	Item<T>* temp = getNodeAt(loc);
	return temp->val;
}


template <typename T>
void LList<T>::clear()
{
  while(head_ != NULL){
    Item<T> *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  size_ = 0;
}
#endif
