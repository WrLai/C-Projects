#include"menu.h"
/*******************************************************************************
* Programmer: Weiren Lai                                                      *
* Class: CptS 122                                                             *
* Programming Assignment: PA5                                                 *
* Date: 07/14/2018                                                            *
*                                                                             *
* Description: You are required to use a dynamic singly linked list to store 
student records. As each record is imported from the file, the record must be 
inserted at the front of the list. Inserting at the front of a dynamic linked 
list is very efficient (constant time). You are required to implement two classes 
for the list. One class is the node class, which stores the fields acquired from 
each record. In addition to the fields in the file, you are required to add two 
extra fields in your node. These fields include number of absences and a stack 
(may be implemented using an array) for storing the dates of absences. The most 
recent absence date will always be at the top (Last-In First-Out, LIFO)! The 
second class is the List class, which is a container for the nodes. The List 
class will be considered your master list. You are required to implement only 
one class for the Stack. The Stack class will be implemented using an array. 
The Stack class must support push (), pop (), peek (), and isEmpty () operations. 
All of these should execute in constant time.     
* Relevant Formulas: Refer to each function definition.                       *
*                                                                             *
* Format of record in input file (input.dat): ClassList.csv
-      record number (max 3 digits)

-      ID number (max 9 digits)

-      name (last, first)

-      email

-      units (number of credits for class or AU for audit)

-      program (major)

-      level (freshman, sophomore, junior, senior, graduate)
*                                                                             *
* Format of output file (output.dat): See problem specification.              *
******************************************************************************/

//Credits
//Paul,Chris
//Geeksforgeeks.com 
//www.runoob.com
//Chegg.com
//www.cplusplus.com



//I rewrote the entire PA again, but still could figure some critical issue: "no appropriate default constructor available". I checked everything but it still
//appears. This PA is harder than I thought it would be, from stack to node, from node to list, and last one from list to menu.
//Tried....
//Spent too much time on this PA(didn't even start PA6).


int main()
{
	menu menu;
	menu.mainMenu();
	return 0;
}