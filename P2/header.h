#ifndef PA3
#define PA3

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>
#include <time.h>
int menu(void);
//struct
typedef struct duration {
	int seconds;
	int minutes;

}Duration;
typedef struct record
{
	char artist[100];
	char album[100];
	char song[100];
	char gen[100];
	Duration length;
	int timesPlayed;
	int rating;
	int count;

}Record;


typedef struct node
{
	Record data;
	struct node *pNext, *pPrev; // must be node not Node or else it would keep calling itself
} Node;

Node * makeNode(Record newEntry);
void insertFront(Node **pList, Record newEntry);
void load(Node **pHead, Record music);
void store(Node *pHead);

void display(Node *pList);
void edit(Node **pHead);
void rate(Node **pHead);
void insert(Node **pHead, Record music);
void deleteNode(Node **pHead);
void sort(Node **pHead);
void play(Node **pHead);
void printList(Node *pList);
void pshuffledList(int randArry[], Node *pList);
void shuffle(Node *pList);
int *randomArray(Node *pList, int count);

#endif // PA2&3
