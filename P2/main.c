#include "header.h"

int main(void)
{
	Record songn = { 0 };
	Node *pHead = NULL;
	int * numSong = 0;
	int option = 0;
	//choices from 1 - 11, each choice leads to a function/functions that potentially solve problems
	do
	{
		option = menu();
		switch (option)
		{
		case 1:
			load(&pHead, songn);
			break;
		case 2:
			store(pHead);
			system("cls");
			break;
		case 3:
			display(pHead);
			break;
		case 4:
			insert(&pHead, songn);
			printList(pHead);
			break;
		case 5:
			deleteNode(&pHead);
			break;
		case 6:
			edit(&pHead);
			system("pause");
			system("cls");
			printList(pHead);
			store(pHead);
			break;
		case 7:
			sort(&pHead);
			printList(pHead);
			break;
		case 8:
			rate(&pHead);
			store(pHead);
			break;
		case 9:
			play(&pHead);
			break;
		case 10:
			shuffle(&pHead);

		}
	} while (option != 11);

	return 0;
}
