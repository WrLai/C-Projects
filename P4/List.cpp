#include "List.h"


//add information
void List::addNode(string recordNumber, string id, string name, string email, string units, string program, string lvl) {
	if (mpRoot == NULL)
	{
		mpRoot = new Node(recordNumber, id, name, email, units, program, lvl);
	}
	else
	{
		Node *pMem = new Node(recordNumber, id, name, email, units, program, lvl);
		pMem->setNext(mpRoot);
		mpRoot = pMem;
		/*mpRoot->setNext(tem);*/
	}
}

//displaylist
void List::displayList() {
	Node *temp = mpRoot;
	while (temp != NULL) {
		cout <<  temp->getRecordNumber() << endl
			<< temp->getId() << temp->getName()  
			<< temp -> getEmail() 
			<< temp->getUnits()  <<temp->getProgram()  
			<<temp->getLevel()  <<endl;
		temp = temp->getNext();
	}
}

//destructor
List::~List()
{
	deleteList(mpRoot);
}

//helper function for destruction 
void List::deleteList(Node *pHead)
{
	(this->mpRoot) = pHead;
	//Node *pCur = pHead;
	Node *Next;

	while ((this->mpRoot) != NULL)
	{
		Next = (this->mpRoot)->getNext();
		delete (this->mpRoot);
		(this->mpRoot) = Next;
	}
}

Node * List::getHead()
{
	return mpRoot;
}
//List&List::operator=(List &rhs)
//{
//	Node *temp = rhs.getHead();
//	Node *lhsTemp = this->getHead();
//	if (lhsTemp = nullptr)
//	{
//		lhsTemp = new Node(temp->getAbsences(), temp -> getEmail(), temp -> getId(), temp->getLevel(), temp->getName(), temp->getProgram(), temp->getRecordNumber());
//		
//	}
//	lhsTemp = lhsTemp->getNext();
//
//}