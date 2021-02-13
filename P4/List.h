#pragma once
#include<iostream>
#include<time.h>
#include<string.h>
#include <fstream>
#include<stdlib.h>
#include "Node.h"

class List {
public:
	//constructor
	List() { mpRoot = NULL; }
	~List();
	void addNode(string  recordNumber, string  id, string name, string email, string  units, string program, string lvl);
	void displayList();
	Node * getHead();
	void deleteList(Node *pHead);
	//List&List::operator=(List &rhs);

//	List&List::operator=(const List &rhs);
	/*List&List::operator=(List &rhs);*/
private:
	Node *mpRoot;
	
};



