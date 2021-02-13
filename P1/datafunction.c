/*************************************************************
* Function: read_file                                       *
* Date Created: 06/12/2018                                  *
* Date Last Modified:06/12/2018                             *
* Description:read the csv file                             *
* Input parameters: infile, Fitbitdata                      *
* Returns:   void                                           *
* Preconditions: csv file                                   *
* Postconditions: read and record, with the help of place   *
                  holder                                    *  
*************************************************************/


#include "header.h"
void read_file(FILE *infile, FitbitData TodaysData[1440])
{
	int count = 0;
	//read data
	char store[66];
	double dub = 0;
	char delim[5] = ",";
	int curData = 0;
	char *temp = { '\0' };
	fgets(store, 66, infile);

	//when its not the end of the file

	while (fgets(store, 66, infile) != NULL)
	{
		//Calls string from file
		//fgets(store, 66, infile);
		//Adds check value
		placeholder(store);
		//save minutes
		temp = strtok(store, delim); 
		strcpy(TodaysData[count].minute, temp);

		//save calories
		temp = strtok(NULL, delim);
			dub = atof(temp);
			TodaysData[count].calories = dub;
	

		//store # floors walked 
		temp = strtok(NULL, delim);
		
			dub = atof(temp);
			TodaysData[count].distance = dub;
		

		//store heart rate
		temp = strtok(NULL, delim);
		
			curData = atoi(temp);
			TodaysData[count].floors = curData;
		

		//heart Rate
		temp = strtok(NULL, delim);
		curData = atoi(temp);
		TodaysData[count].heartRate = curData;

		//Steps
		temp = strtok(NULL, delim);
		curData = atoi(temp);
		TodaysData[count].steps = curData;

		//Sleeplevel
		temp = strtok(NULL, delim);
		curData = atoi(temp);
		TodaysData[count].sleepLevel = curData;

		count++;
		//system("pause");

	}


}

/*************************************************************
* Function:cal_total_calories                               *
* Date Created:06/11/2018                                   *
* Date Last Modified:      06/12/2018                       *
* Description:calculate the total calories                  *
* Input parameters:fibitdata                                *
* Returns:   total calories                                 *
* Preconditions: read fibitdata                             *
* Postconditions: total calories calcu                      *
*************************************************************/

double cal_total_calories(FitbitData TodaysData[1440])
{
	double totalcalories = 0;
	int a = 0, count = 0;
	while (count < 1440)
	{
		if (TodaysData[a].calories != '#') {
			totalcalories += TodaysData[a].calories;
		}
		a++;
		count++;
	}
		

	return totalcalories;
}

/*************************************************************
* Function:cal_distance_walked                              *
* Date Created: 06/10/2018                                  *
* Date Last Modified:06/12/2018                             *
* Description: calculate the distance walked                *
* Input parameters:fibitdata                                *
* Returns:total miles                                       *
* Preconditions: read the file                              *
* Postconditions: total miles walked calculated             *
*************************************************************/

double cal_distance_walked(FitbitData TodaysData[1440])
{
	double totalmiles = 0;
	int A = 0;
	int count = 0;
	while (count < 1440)
	{
		if (TodaysData[A].distance != '#') {
			totalmiles += TodaysData[A].distance;
		}
		A++;
		count++;
	}
	return totalmiles;
}
/*************************************************************
* Function: cal_floor_walked                                 *
* Date Created:  06/09/2018                                  *
* Date Last Modified: 06/12/2018                             *
* Description: calculate the floors walked                   *
* Input parameters:   fibitdata                              *
* Returns:total floors                                       *
* Preconditions: read file                                   *
* Postconditions:  total floors calculated                   *
*************************************************************/
int cal_floors_walked(FitbitData TodaysData[1440])
{
	int totalfloors = 0;
	int index=0, count = 0;
	while (count < 1440)
	{
		if (TodaysData[index].floors != '#') {
			totalfloors += TodaysData[index].floors;
		}
		index++;
		count++;
	}

	return totalfloors;
}
/*************************************************************
* Function: cal_steps                                        *
* Date Created: 06/09/2018                                   *
* Date Last Modified:06/12/2018                              *
* Description: calculate the total steps                     *
* Input parameters:fibitdata                                 *
* Returns:total steps                                        *
* Preconditions:read the file                                *
* Postconditions:total steps calculated                      *
*************************************************************/
int cal_steps(FitbitData TodaysData[1440])
{
	int totalsteps=0, index=0, count = 0;
	
		while (count < 1440)
		{
			if (TodaysData[index].steps != '#') {
				totalsteps += TodaysData[index].steps;
			}
			index++;
			count++;
		
	}
		
	return totalsteps;
}
/*************************************************************
* Function:cal_ave_hrate                                     *
* Date Created:06/10/2018                                    *
* Date Last Modified:06/12/2018                              *
* Description: calculate the average of the heart rate       *
* Input parameters:fitbitdata                                *
* Returns:average heart rate / 1440                          *
* Preconditions: read file                                   *
* Postconditions: ave heart rate calculated                  *
*************************************************************/

double cal_ave_hrate(FitbitData TodaysData[1440])
{
	double ave=0, count2 = 0;
	int index = 0;
	
		while (count2 < 1440)
		{
			if (TodaysData[index].heartRate != '#') {
				ave += TodaysData[index].heartRate;
			}
			index++;
			count2++;
		}
	
	return ave / 1440;
}
/*************************************************************
* Function: cal_max_steps                                    *
* Date Created:06/10/2018                                    *
* Date Last Modified:06/12/2018                              *
* Description:calculate the max steps walked                 *
* Input parameters:fibitdta                                  * 
* Returns:maxsteps                                           *
* Preconditions:read file                                    *
* Postconditions: max steps calculated                       *
*************************************************************/
int cal_max_steps(FitbitData TodaysData[1440])
{
	int maxsteps=0, count=0, index = 0;
	
		while (count < 1440)
		{
			if ((TodaysData[index].steps!='#') && (TodaysData[index].steps >= maxsteps))
			{
				maxsteps = TodaysData[index].steps;
			}
			index++;
			count++;
		}
	
	return maxsteps;
}
/*************************************************************
* Function:calculate worst sleep                             *
* Date Created:06/11/2018                                    *
* Date Last Modified:06/12/2018                              *
* Description:calculate worst sleep, (modified a little bit)I got this part from URL: http://www.chegg.com/homework-help/questions-and-answers/please-following-c-fitbit-company-builds-wearable-technology-devices-track-various-activit-q17925842
                                                             *
* Input parameters: start, end, fibitdata                    *
* Returns:void                                               *
* Preconditions:read file                                    *
* Postconditions:the range of the worst sleep calculated     *
*************************************************************/

void cal_worst_sleep(char *start, char*end, FitbitData TodaysData[1440])
{
	int count = 0, cur = 0, maxstart = 0, maxend = 0, maxsum = 0;
	int index = 0, count1 = 0,count2 = 0;
	while (count1 < 1440)
	{
		if ((TodaysData[index].sleepLevel > (100-99)) && (TodaysData[index].sleepLevel != '#'))
		{
			do { cur += TodaysData[count2].sleepLevel; count2++; }
			while(TodaysData[count2].sleepLevel > (101-100));

			if (cur > maxsum)
			{
				maxstart = index;
				maxend = count2;
				maxsum = cur;
			}
		}
		cur = 0;
		count1++;
	}
	strncpy(start, TodaysData[maxstart].minute, 9);
	strncpy(end, TodaysData[maxend].minute, 9);
	printf("The period of worst sleep was %s to %s\n", start, end);
}
/*************************************************************
* Function:placeholder                                       *
* Date Created: 06/11/2018                                   *
* Date Last Modified: 06/12/2018                             *
* Description:replace the "no value" with a #, copy a string and modify it, then replace the old string it with the modified one                                            *
* Input parameters: str                                      *
* Returns:placeholder                                        *
* Preconditions: files read                                  *
* Postconditions: add # between commas and after the commas where there is no value                                          *
*************************************************************/
//Credit: Paul, the idea was Originally from Paul. 
char placeholder(char * str)
{
	int index = 0, index2 = 0, index3 = 0, length = strlen(str);
	char temp[100] = { '\0' };
	for (index = 0; index < length; index++) {
		temp[index] = str[index];
		if (str[index] == ',' && (str[index + 1] == ',' || str[index + 1] == '\n'))
		{
			temp[index + 1] = '#';
			index3 = index + 2;
			for (index2 = index + 1; index2 < strlen(str); index2++) {
				temp[index3] = str[index2];
				index3++;
			}
			strcpy(str, temp);
			length = strlen(str);
		}
	}
}