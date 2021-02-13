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


#ifndef FITBIT_H
#define FITBIT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef enum sleep
{
	NONE = 0, ASLEEP = 1, AWAKE = 2, REALLYAWAKE = 3
} Sleep;

typedef struct fitbit
{
	char minute[9];
	double calories;
	double distance;
	unsigned int floors;
	unsigned int heartRate;
	unsigned int steps;
	Sleep sleepLevel;
} FitbitData;

void read_file(FILE *infile, FitbitData T_d[1440]);
double cal_total_calories(FitbitData TodaysData[1440]);
double cal_distance_walked(FitbitData TodaysData[1440]);
int cal_floors_walked(FitbitData TodaysData[1440]);
int cal_steps(FitbitData TodaysData[1440]);
double cal_ave_hrate(FitbitData TodaysData[1440]);
int cal_max_steps(FitbitData TodaysData[1440]);
void cal_worst_sleep(char *start, char*end, FitbitData TodaysData[1440]);
char placeholder(char *str);
#endif