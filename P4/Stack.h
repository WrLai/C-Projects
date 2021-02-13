#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <time.h>
#include <cstdbool>

using std::cout;
using std::cin;
using std::endl;
using std::fstream;
using std::ostream;
using std::ifstream;
using std::getline;
using std::string;

template <class T>
class Stack
{
public:
	Stack(int newSize = 0);
	~Stack();

	bool push(T &newItem);
	bool pop(T &poppedItem);
	bool peek(T &item);
	bool isEmpty();
	int absencesCount;
	Stack<T>&operator=(Stack<T> &rhs);
private:
	int mIndex;
	int mMaxSize;
	T *mData;
};

template <class T>
Stack<T>::Stack(int newSize)
{
	mIndex = newSize;
	mMaxSize = 100;
	mData = new T[100];
}

template <class T>
Stack<T>::~Stack()
{
	delete[] this->mData;

}

/*************************************************************
* Function:push
* Date Created: 07/10/2018
* Date Last Modified: 07/15/2018
* Description:add item
* Input parameters: template T & newItem
* Returns:
* Preconditions:
* Postconditions:item added
*************************************************************/
template <class T>
bool Stack<T>::push(T &newItem)
{
	if ((mIndex + 1) <= mMaxSize)
	{
		mData[mIndex] = newItem;
		mIndex++;
		return true;
	}
	return false;
}

/*************************************************************
* Function:pop
* Date Created: 07/10/2018
* Date Last Modified: 07/15/2018
* Description:delete item
* Input parameters:template T &poppedItem
* Returns:
* Preconditions:
* Postconditions:item deleted
*************************************************************/
template <class T>
bool Stack<T>::pop(T &poppedItem)
{
	if (!Stack<T>::isEmpty())
	{
		poppedItem = mData[mIndex - 1];
		mIndex--;
		return true;
	}
	else {
		return false;
	}
}

/*************************************************************
* Function:peek
* Date Created: 07/10/2018
* Date Last Modified: 07/15/2018
* Description: the very first one
* Input parameters: T&item
* Returns:
* Preconditions:
* Postconditions:access the very first one
*************************************************************/
template <class T>
bool Stack<T>::peek(T &item)
{
	if (!Stack<T>::isEmpty)
	{
		item = mData[mIndex - 1];
		return true;
	}
	else {
		return false;
	}
}

/*************************************************************
* Function:isEmpty
* Date Created: 07/10/2018
* Date Last Modified: 07/15/2018
* Description:check if its empty
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:
*************************************************************/
template <class T>
bool Stack<T>::isEmpty()
{
	if (mIndex == 0)
	{
		return true;
	}
	else {
		return false;
	}
}

//equal operator 
template<class T>
Stack<T>&Stack<T>::operator=(Stack<T> &rhs) {
	Stack<T> temp;
	T cur;
	while (!rhs.isEmpty())
	{
		rhs.pop(cur);
		temp.push(cur);
	}
	while (!temp.isEmpty())
	{
		string cur = "";
		temp.pop(cur);
		rhs.push(cur);
		this->push(cur);
	}
	return *this;
}

