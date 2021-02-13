#include "header.h"

/*******************************************************************************
* Programmer: Weiren Lai                                                      *
* Class: CptS 121; Lab Section 0                                              *
* Programming Assignment: 1                                                   *
* Date: 06/12/2018                                                            *
*                                                                             *
* Description: Read Data and compute it, write it in a new file               *
*                                                                             *
*                                                                             *
* Relevant Formulas: Refer to each function definition.                       *
*                                                                             * 
*                                                                             *
* Format of output file (Result.csv): See problem specification.              *
******************************************************************************/

int main(void)
{
	//initialize file and read it
	FILE *data = NULL, *results = NULL;
	data = fopen("FitBitData.csv", "r");
	results = fopen("Results.csv", "w");
	FitbitData TodaysData[1440] = { {'\0'}, 0.0, 0.0, 0, 0, 0, 0 };

	if (data == NULL)
	{
		printf("Oops, something went wrong, didn't get the file.\n");
	}

	//I didn't get the read_file, I tried so many times. The reason was I didn't create a Fitbitdata, I added an existing item which did not exist. 
	read_file(data, TodaysData);

	//calories burnt
	double total_calories = cal_total_calories(TodaysData);

	printf("%lf Calories were burned today\n", total_calories);

	//distance walked
	double total_miles = cal_distance_walked(TodaysData);

	printf("%lf miles were walked today\n", total_miles);

	//floors walked
	int total_floors = cal_floors_walked(TodaysData);

	printf("%d floors were walked today\n", total_floors);

	//steps taken
	int total_steps = cal_steps(TodaysData);

	printf("%d steps were taken today\n", total_steps);
	
	//average heart rate
	double average_heart_rate = cal_ave_hrate(TodaysData);

	printf("The average heart rate for the day was %lf bpm\n", average_heart_rate);

	//max steps in a min
	int max_steps = cal_max_steps(TodaysData);

	printf("The max steps taken in a minute was %d\n", max_steps);

	//calculate the range 
	char starttime[10], endtime[10];

	cal_worst_sleep(starttime, endtime, TodaysData);

	//write results to outfile
	fprintf(results, "Total Calories: %lf\n\nTotal Distance: %lf\n\nTotal Floors: %d\n\nTotal Steps: %d\n\nAvg Heartrate: %lf\n\nMax Steps: %d\n\nWorst Sleep: %s - %s\n\n", total_calories, total_miles, total_floors, total_steps, average_heart_rate, max_steps, starttime, endtime);

	//close files
	fclose(data);

	fclose(results);

	return 0;
}


