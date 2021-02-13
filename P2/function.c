#include "header.h"
/*************************************************************
* Function:   menu                                      *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:   menu, with choices               *
* Input                                 *
* Returns:    option                              *
* Preconditions:    prompt user to type numbers                          *
* Postconditions:    number typed and recorded                 *
*************************************************************/

int menu()
{
	printf("Welcome to Digital Music Manager!\n");
	printf("Menu options are shown below:\n\n");
	printf("1. Load  2. Store\n3. Display  4. Insert\n5. Delete  6. Edit\n7. Sort  8. Rate\n9. play  10. shuffle\n11. exit!\n");
	int option = 0;
	scanf("%d", &option);
	return option;
}

/*************************************************************
* Function: makenode                                         *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:  make a node, allocate space                *
* Input     record newNum                            *
* Returns:        pMem                          *
* Preconditions:    Node exists                          *
* Postconditions:      space allocated             *
*************************************************************/
Node * makeNode(Record newNum)
{
	Node *pMem = malloc(sizeof(Node));
	if (pMem != NULL) //if we allocated space correctly
	{
		pMem->pNext = NULL;
		pMem->pPrev = NULL;
		strcpy(pMem->data.artist, newNum.artist);
		strcpy(pMem->data.album, newNum.album);
		strcpy(pMem->data.song, newNum.song);
		strcpy(pMem->data.gen, newNum.gen);
		pMem->data.length.minutes = newNum.length.minutes;
		pMem->data.length.seconds = newNum.length.seconds;
		pMem->data.timesPlayed = newNum.timesPlayed;
		pMem->data.rating = newNum.rating;
	}

	return pMem;
}
/*************************************************************
* Function:  insertfront                                       *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:   insert at front               *
* Input         plist, newNum                        *
* Returns:          void                        *
* Preconditions:   plist newnum, pMem space allocated                          *
* Postconditions:   insert  at front of the list                 *
*************************************************************/

void insertFront(Node **pList, Record newNum)
{
	Node *pMem = NULL;
	pMem = makeNode(newNum);
	if (pMem == NULL)
	{
		*pList = pMem;
	}
	else {
		pMem->pNext = *pList;
		pMem->pPrev = *pList;
		*pList = pMem;
	}
}

/*************************************************************
* Function:   load                                      *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:  load the data                *
* Input      phead, music                           *
* Returns:        void                         *
* Preconditions:    file not NULL, so we can read the file                          *
* Postconditions:    file read and recorded(number of music recorded as well)                 *
*************************************************************/

void load(Node **pHead, Record music)
{
	FILE *infile = fopen("musicPlayList.csv", "r");
	Node *pMem = NULL;
	int index = 0;
	char *rep = NULL, line[150];
	pMem = *pHead;
	//printf("DID WE CALL?\n");
	if (infile != NULL)
	{

		while(fgets(line, 150, infile) !=NULL)
		{
			
			
			rep = strtok(line, ",");
			
			strcpy(music.artist, rep);


			if (line[0] == '\"')
			{

				rep = strtok(NULL, ",");
				strcat(music.artist, ",");
				strcat(music.artist, rep);

			}
			rep = strtok(NULL, ",");

			strcpy(music.album, rep);
		
			rep = strtok(NULL, ",");

			strcpy(music.song, rep);
			
			rep = strtok(NULL, ",");

			strcpy(music.gen, rep);
			
			rep = strtok(NULL, ":");

			music.length.minutes = atoi(rep);
			
			rep = strtok(NULL, ",");

			music.length.seconds = atoi(rep);
			
			rep = strtok(NULL, ",");

			music.timesPlayed = atoi(rep);
			
			rep = strtok(NULL, ",");

			music.rating = atoi(rep);

			pMem = makeNode(music);

			//insertFront;

			pMem->pNext = *pHead;
			if (*pHead != NULL) {
				(*pHead)->pPrev = pMem;
				
			}
			*pHead = pMem;
			index++;
			//printf("HIT STUFF\n");
			
		}
		pMem->data.count = index;
		system("cls");
		printf("Successfully Loaded!\n");
		fclose(infile);
	}
	return pMem;

}

/*************************************************************
* Function:    store                                     *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:    over writes the previes contents              *
* Input                                 *
* Returns:         void                         *
* Preconditions:     file not empty                         *
* Postconditions:     writes the current records in the dynamic doubly linked list to the music file(over write)                *
*************************************************************/

void store(Node *pHead)
{
	FILE *outfile = fopen("musicPlayList.csv", "w");
	Node *pTemp = pHead;
	for (;pTemp != NULL;)
	{
		fprintf(outfile, "%s,", pTemp->data.artist);
		fprintf(outfile, "%s,", pTemp->data.album);
		fprintf(outfile, "%s,", pTemp->data.song);
		fprintf(outfile, "%s,", pTemp->data.gen);
		fprintf(outfile, "%d:%d,", pTemp->data.length.minutes, pTemp->data.length.seconds);

		fprintf(outfile, "%d,", pTemp->data.timesPlayed);
		fprintf(outfile, "%d\n", pTemp->data.rating);
		pTemp = pTemp->pNext;


	}
	fclose(outfile);
}

/*************************************************************
* Function:   display                                    *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:   display the music               *
* Input         plist                        *
* Returns:                                  *
* Preconditions:    file read and recorded                          *
* Postconditions:    information displayed                *
*************************************************************/

void display(Node *pList)
{
	int ans = 0;
	char artist[20] = "\0";
	Node *pMem = pList;
	pMem->pPrev = NULL;
	printf("Would you like to see\n 1. All music records\n2. Records for one artist\n");
	scanf("%d", &ans);

	if (ans == 1)
	{
		for (;pMem != NULL;)
		{
			printf("%s\n", pMem->data.artist);
			printf("%s\n", pMem->data.album);
			printf("%s\n", pMem->data.song);
			printf("%s\n", pMem->data.gen);
			printf("%d:%d\n", pMem->data.length.minutes, pMem->data.length.seconds);
			printf("Times Played: %d\n", pMem->data.timesPlayed);
			printf("Rating: %d\n", pMem->data.rating);
			printf("\n\n");
			pMem = pMem->pNext;
		}
		printf("Number of songs: %d\n\n", pList->data.count);
	}

	else if (ans == 2)
	{
		pMem = pList;
		printf("If the artist has a first and last name please enter the last then the first with just a space.\n");
		//system("pause");
		printf("If the artist includes a first and last name, type it in quotes\n");
		printf("What artist would you like to see records?\n");
		scanf(" %s", artist); 
		printf("Artist: %s\n", artist);


		for (;strcmp(artist, pMem->data.artist) != 0 && pMem != NULL;)
		{
			pMem = pMem->pNext;
		}
		if (strcmp(artist, pMem->data.artist) == 0)
		{
			printf("%s\n", pMem->data.artist);
			printf("%s\n", pMem->data.album);
			printf("%s\n", pMem->data.song);
			printf("%s\n", pMem->data.gen);
			printf("%d:%d\n", pMem->data.length.minutes, pMem->data.length.seconds);
			printf("Times Played: %d\n", pMem->data.timesPlayed);
			printf("Rating: %d\n", pMem->data.rating);
			//system("pause");
		}
		else {
			printf("Something went wrong... \n");
			exit(1);
		}
	}
}

/*************************************************************
* Function:  edit                                    *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:   edition             *
* Input                                 *
* Returns:    void                              *
* Preconditions:    edit must allow user to find record by artist                          *
* Postconditions:   modification made                *
*************************************************************/


void edit(Node **pHead)
{
	// always sets pTemp to start of list
	Node *pTemp = *pHead; 
	char artist[20] = "\0", strings[50] = "\0";
	int duplicate = 0, song = 0, edit = 0, i = 0;
	int newint = 0;

	printf("Type in the artist of the record you would like to edit.\n");
	printf("Type in artist now.\n");
	scanf(" %s", artist);

	// while loop finds all records matching artist and displays them
	for (;pTemp != NULL;)
	{

		if (strcmp(artist, pTemp->data.artist) == 0) // if the artist entered has a match in the database
		{
			duplicate++;
			printf("Option %d\n", duplicate);
			printf("%s\n", pTemp->data.artist);
			printf("%s\n", pTemp->data.album);
			printf("%s\n", pTemp->data.song);
			printf("%s\n", pTemp->data.gen);
			printf("%d:%d\n", pTemp->data.length.minutes, pTemp->data.length.seconds);
			printf("Times Played: %d\n", pTemp->data.timesPlayed);
			printf("Rating: %d\n\n\n", pTemp->data.rating);
			//system("pause");

		}
		pTemp = pTemp->pNext;
	}
	pTemp = *pHead;
	// points to the first record matching artist since there's only one
	if (duplicate == 1)
	{
		for (;strcmp(artist, pTemp->data.artist) != 0 && pTemp != NULL;)
		{
			pTemp = pTemp->pNext;
		}
	}
	// points to record that user selected for artist
	else if (duplicate > 1) // if there is more than one song for artist
	{
		printf("Which song would you like to modify? (Enter number)\n");
		scanf("%d", &song);

		for (;i < song;)
		{
			if (strcmp(artist, pTemp->data.artist) == 0)
			{
				i++;
			}
			pTemp = pTemp->pNext;
		}
	}
	printf("Would you like to modify\n1. Artist\n2. Album\n3. Song\n4. gen\n5. Minutes\n6. Seconds\n7. Times Played\n8. Rating\n");
	scanf("%d", &edit);
	if (edit > 0 && edit < 5)
	{
		if (edit == 1)
		{
			printf("Enter new artist:\n");
			scanf(" %s", strings);
			strcpy(pTemp->data.artist, strings);
		}
		else if (edit == 2)
		{
			printf("Enter new album:\n");
			scanf(" %s", strings);
			strcpy(pTemp->data.album, strings);
		}
		else if (edit == 3)
		{
			printf("Enter new song name:\n");
			scanf(" %s", strings);
			strcpy(pTemp->data.song, strings);
		}
		else if (edit == 4)
		{
			printf("Enter new gen:\n");
			scanf(" %s", strings);
			strcpy(pTemp->data.gen, strings);
		}
	}

	if (edit > 4 && edit < 9)
	{
		if (edit == 5)
		{
			printf("Enter new minute time:\n");
			scanf("%d", &newint);
			pTemp->data.length.minutes = newint;
		}
		else if (edit == 6)
		{
			printf("Enter new seconds time:\n");
			scanf("%d", &newint);
			pTemp->data.length.seconds = newint;
		}
		else if (edit == 7)
		{
			printf("Enter new number of times played:\n");
			scanf("%d", &newint);
			pTemp->data.timesPlayed = newint;
		}
		else if (edit == 8)
		{
			printf("Enter new rating:\n");
			scanf("%d", &newint);
			pTemp->data.rating = newint;
		}
	}

	return pTemp;
}
/*************************************************************
* Function:  rate                                   *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:   rate the songs             *
* Input        phead                         *
* Returns:    void                              *
* Preconditions:    information recorded                          *
* Postconditions:  songs rated from 1-5              *
*************************************************************/

void rate(Node **pHead)
{
	Node * pTemp = *pHead; //sets temp pointer to head of list
	int rating = 0;
	char song_title[20] = "\0";

	printf("Here is your library!\n\n");
	printList(*pHead);
	system("cls");
	printf("What song would you like to rate?\n");
	scanf(" %s", song_title);

	for (pTemp;pTemp != NULL && (strcmp(song_title, pTemp->data.song) != 0);)
	{
		pTemp = pTemp->pNext;
	}
	printf("Song: %s", pTemp->data.song);
	printf("Enter new rating for %s\n(1-5)\n", song_title);
	scanf("%d", &rating);
	if (rating < 1 || rating > 5)
	{
		printf("That rating was not between 1-5 dingdong. Enter new rating:\n");
		scanf("%d", &rating);
	}
	pTemp->data.rating = rating;
	printList(*pHead);
	return pTemp;
}

/*************************************************************
* Function:  insert                                    *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:   edition             *
* Input        phead, music                         *
* Returns:    void                              *
* Preconditions:   space allocated                          *
* Postconditions:   songs details inserted               *
*************************************************************/

void insert(Node **pHead, Record music)
{
	Node *pTemp = makeNode(music);
	int min, sec, num, rate;

	if (pTemp != NULL) // allocated mem for node
	{
		printf("Enter new artist (please enter artists with two names '\"last, first'\". Include quotes: \n");
		scanf(" %s", pTemp->data.artist);

		printf("Enter new album:\n");
		scanf(" %s", pTemp->data.album);

		printf("Enter new song title:\n");
		scanf(" %s", pTemp->data.song);

		printf("Enter new gen:\n");
		scanf(" %s", pTemp->data.gen);

		printf("Enter how many minutes the song lasts:\n");
		scanf("%d", &min);
		pTemp->data.length.minutes = min;

		printf("Enter how many seconds the song lasts:\n");
		scanf("%d", &sec);
		pTemp->data.length.seconds = sec;

		printf("Enter the number of times it's been played:\n");
		scanf("%d", &num);
		pTemp->data.timesPlayed = num;

		printf("Enter a rating for this song:\n");
		scanf("%d", &rate);
		pTemp->data.rating = rate;
	}
	pTemp->pNext = *pHead;
	*pHead = pTemp;
	return pTemp;
}
/*************************************************************
* Function:  deleteNode                                    *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:   delete a song record             *
* Input         phead                        *
* Returns:    void                              *
* Preconditions:    prompt the user, and songs recorded, if they match, delete                         *
* Postconditions:   songs deleted               *
*************************************************************/

void deleteNode(Node **pHead)
{
	Node *pMem = NULL;
	char song[50];
	pMem = *pHead;
	
	printf("What song would you like to delete?\n");
	scanf("%s", song);

	while (pMem != NULL && (strcmp(pMem->data.song, song) != 0)) 
	{
		pMem = pMem->pNext;
	}
	
	if (pMem != NULL) {
		if (pMem == *pHead) {
		*pHead = (*pHead)->pNext;
		free(pMem);
	}
		else if(pMem->pNext != NULL){
			pMem->pPrev = pMem->pNext;
			(pMem->pNext)->pPrev = pMem->pPrev;
			free(pMem);
		}
		else {
			if (pMem->pNext == NULL)
			{
				pMem = NULL;
			}
		}
	}


}
/*************************************************************
* Function:  sort                                    *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:   sorting aritis, album, rating, and times played from largest to smallest             *
* Input      phead                           *
* Returns:    void                              *
* Preconditions:    songs recorded, prompt the user for sorting method                         *
* Postconditions:  list sorted by the user's choice              *
*************************************************************/

void sort(Node **pHead)
{
	Node *pCur = *pHead;
	Node *pTemp = NULL;
	int length = 0, i = 0, option = 0;

	while (pCur != NULL)
	{
		pCur = pCur->pNext; //finds length
		length++;
	}
	pCur = *pHead; //pCur is null after the loop
	i = length - 1;
	printf("Would you like to sort by\n 1. Artist\n2. Album\n3. Rating\n4. Number of times played\n");
	scanf("%d", &option);
	for (; i > 1;i--)
	{
		pCur = *pHead;
		for (;pCur != NULL && pCur->pNext != NULL;)
		{

			if (option == 2) // sort by artist
			{
				if ((strcmp(pCur->data.album, pCur->pNext->data.album) > 0))
				{
					if (*pHead == pCur)
					{
						*pHead = pCur->pNext;
					}
					pTemp = pCur->pNext;
					if (pTemp->pNext != NULL)
					{
						pTemp->pNext->pPrev = pCur;
					}
					pCur->pNext = pTemp->pNext; // pcur pnext pnext
					pTemp->pPrev = pCur->pPrev;
					pTemp->pNext = pCur;
					pCur->pPrev = pTemp;

				}
			}

			pCur = pCur->pNext;

		}
	}
}

/*************************************************************
* Function:  printlist                                    *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:  print the list of songs recorded             *
* Input        plist                         *
* Returns:    void                              *
* Preconditions:    songs recorded                          *
* Postconditions:  songs printed out              *
*************************************************************/

void printList(Node *pList)
{
	Node *pMem = pList;

	for (;pMem != NULL;)
	{
		printf("%s\n", pMem->data.artist);
		printf("%s\n", pMem->data.album);
		printf("%s\n", pMem->data.song);
		printf("%s\n", pMem->data.gen);
		printf("%d:%d\n", pMem->data.length.minutes, pMem->data.length.seconds);
		printf("Times Played: %d\n", pMem->data.timesPlayed);
		printf("Rating: %d\n", pMem->data.rating);
		printf("\n");
		pMem = pMem->pNext;
	}
}
/*************************************************************
* Function:  play                                   *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:  play each song              *
* Input       phead                          *
* Returns:    void                              *
* Preconditions:   songs recorded            *
* Postconditions:  songs are played, it goes to the next song after a certain amount of time, used Windows.h Sleep to pause temporarily
*************************************************************/

void play(Node **pHead) {
	Node * pMem = *pHead;
	for (;pMem != NULL;) {

		printf("Now Playing..... (please act it's playing, there is a song in your mind....):\n\n");

		printf("Artist: %s\nSong Title: %s\nAlbum Title: %s\nDuration: %d:%d\nGenre: %s\nNumber of Plays: %d\nRating: %d\n\n", pMem->data.artist, pMem->data.song, pMem->data.album, pMem->data.length.minutes, pMem->data.length.seconds, pMem->data.gen, pMem->data.timesPlayed, pMem->data.rating);

		pMem->data.timesPlayed += 1;

		pMem = pMem->pNext;

		Sleep(4000); //Learned it from paul

		system("cls");

	}

	system("cls");

}


/*************************************************************
* Function:  randomArray                       *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:  creat a randomarray
* Input         plist, count        *
* Returns:    int                            *
* Preconditions:   number of songs recorded, space allocated 
* Postconditions:  randomarray created
*************************************************************/

int *randomArray(Node *pList, int count) {
	Node *pMem = pList;

	int *random = NULL;

	int i = 0, j = 0;

	count = pList->data.count;

	random = (int)malloc((sizeof(int) * count));

	while (i < count) {
		random[i] = i;
		i++;
	}

	while (j < count) {
		int tem = random[j];
		int ranI = rand() % count;
		random[j] = random[ranI];
		random[ranI] = tem;
		j++;
	}

	return random;

}
/*************************************************************
* Function:  shuffle                           *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:   shuffle  songs
* Input                                 *
* Returns:    void                              *
* Preconditions:   plist, random array *
* Postconditions:   songs are shuffled
Got the idea from internet
URL: https://www.chegg.com/homework-help/questions-and-answers/please-code-c-language-assignment-complete-digital-music-manager-started-pa-2-must-impleme-q23846314
*************************************************************/

void shuffle(Node *pList) {
	Node *pMem = NULL;
	pMem = pList;

	int *randArry = NULL;

	randArry = randomArray(pList, pMem->data.count);

	pshuffledList(randArry, pList);

}


/*************************************************************
* Function:  pshuffledlist        *
* Date Created:06/28/2018                                   *
* Date Last Modified:      06/28/2018                       *
* Description:  print shuffledlist
* Input        random array, plist
* Returns:   void                         *
* Preconditions:   shuffled list.
* Postconditions: shuffled list printed.

This was also connected to the website.
URL: https://www.chegg.com/homework-help/questions-and-answers/please-code-c-language-assignment-complete-digital-music-manager-started-pa-2-must-impleme-q23846314

*************************************************************/
void pshuffledList(int randArry[], Node *pList) {

	int count = 0, cur = 0, next = 0, i = 0;

	Node *pMem = pList;

	next = randArry[i];

	do {

		printf("Now Playing:\n\n");

		if (cur < next) {

			while (i = cur && i < next) {
				pMem = pMem->pNext;
					i++;
			}

		}

		else {
			while (i = cur&&i > next) {
				pMem = pMem->pPrev;
				i--;
			}



		}

		printf("Artist: %s\nSong Title: %s\nAlbum Title: %s\nDuration: %d:%d\nGenre: %s\nTimes played: %d\nRating: %d\n\n",

			pMem->data.artist, pMem->data.song, pMem->data.album, pMem->data.length.minutes, pMem->data.length.seconds,

			pMem->data.gen, pMem->data.timesPlayed, pMem->data.rating);

		Sleep(4000);

		system("cls");

		count = count + 1;

		i = i + 1;

		pMem->data.timesPlayed = pMem->data.timesPlayed + 1;

		if (count < pMem->data.count) {

			cur = next;

			next = randArry[i];

		}

	} while (count < pList->data.count);

}