#include "Node.h"

/*************************************************************
* Function:Constructor
* Date Created: 07/10/2018
* Date Last Modified: 07/15/2018
* Description: constructor
* Input parameters: recordNumber, id, name, email, units, program, lvl
* Returns:
* Preconditions: 
* Postconditions: 
*************************************************************/
Node::Node(string recordNumber, string id, string name, string email, string units, string program, string lvl)
{
	this->recordNumber = recordNumber;
	this->id = id;
	this->name = name;
	this->email = email;
	this->units = units;
	this->program = program;
	this->lvl = lvl;
	this->pNext = NULL;
}

//Node::Node()
//{
//	this->recordNumber = recordNumber;
//	this->id = id;
//	this->name = name;
//	this->email = email;
//	this->units = units;
//	this->program = program;
//	this->lvl = lvl;
//	this->pNext = NULL;
//}

//desructor
Node::~Node(void)
{}
//set Number of absences
void Node::setNumberOfAbsences(int n) {
	absentCount = n;

}
//set next
void Node::setNext(Node *next) {
	pNext = next;
}
//getter function
string Node::getRecordNumber() {
	return recordNumber;
}
//getter function for id
string Node::getId() {
	return id;
}

//getter function for name
string Node::getName() {
	return name;
}
//getter function for email
string Node::getEmail() {
	return email;
}
//getter function for units
string Node::getUnits() {
	return units;
}
//getter function for program
string Node::getProgram() {
	return program;
}
//getter function for level
string Node::getLevel() {
	return lvl;
}
//getter function for number of absences
int Node::getNumberOfAbsences() {
	return absentCount;
}

//get next 
Node *Node::getNext()
{
	return pNext;
}
//get absences - stack
Stack<string> & Node::getAbsences() {
	return absences;
}
//setting information 
void Node::setInformation(string irecordNumber, string iid, string iname, string iemail, string iunits, string iprogram, string ilevel, int newabsentCount)
{
	this->recordNumber = irecordNumber;
	this->id = iid;
	this->name = iname;
	this->email = iemail;
	this->units = iunits;
	this->program = iprogram;
	this->lvl = ilevel;
	this->absentCount = newabsentCount;
}



Node & Node::operator = (Node &rhs)
{
	//No EQUALS OPERATOR FOR NODE YET SO CANT USE THIS
	//if (this != &rhs)
	//{
	this->id = rhs.getId();
	this->lvl = rhs.getLevel();
	this->name = rhs.getName();
	this->recordNumber = rhs.getRecordNumber();
	this->email = rhs.getEmail();
	this->program = rhs.getProgram();
	this->units = rhs.getUnits();
	//ABSENCES IS A STACK. THERE IS AN = OPERATOR FOR STACK
	this->absences = rhs.getAbsences();
	this->absentCount = rhs.getNumberOfAbsences();
	//}
	return *this;
}