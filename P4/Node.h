#pragma once
#include<iostream>
#include<time.h>
#include<string.h>
#include <fstream>
#include<stdlib.h>
#include "Stack.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::fstream;
using std::ostream;
using std::ifstream;

class Node {
public:
	//constructor
	Node(string recordNumber, string id, string name, string email, string units, string program, string lvl);
	~Node();//destructor
	
	//string absenceCount[100];

	Node() {
		recordNumber = "";
		id = "";
		name = "";
		email = "";
		units = "";
		program = "";
		lvl = "";
		absentCount = 0;

		pNext = nullptr;
	}

	void setNumberOfAbsences(int n);
	void setNext(Node *next);
	string getRecordNumber();
	string getId();
	string getName();
	string getEmail();
	string getUnits();
	string getProgram();
	string getLevel();
	int getNumberOfAbsences();
	Stack<string> & getAbsences();

	void setInformation(string irecordNumber, string iid, string iname, string iemail, string iunits, string iprogram, string ilevel, int newabsentCount);



	Node &operator = (Node &rhs);
	Node *getNext();

	//Stack<int> absences;
	

private:

	string recordNumber;
	string id;
	string name;
	string email;
	string units;
	string program;
	string lvl;
	//string absenceCount;
	Node *pNext;
	Stack<string> absences;
	int absentCount;
};


