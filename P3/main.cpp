#include "fitnessAppWrapper.h"

/*******************************************************************************
* Programmer: Weiren Lai                                                      *
* Class: CptS 122                                                             *
* Programming Assignment: PA4                                                 *
* Date: 07/05/2018                                                            *
*                                                                             *
* Description: write a basic fitness application, in C++, that allows the user*
of the application to manually edit ¡°diet¡± and ¡°exercise¡± plans. For this     * 
application you will need to create three classes: DietPlan, ExercisePlan,    *
and FitnessAppWrapper.                                                        *
*                                                                             *
* Relevant Formulas: Refer to each function definition.                       *
*                                                                             *
* Format of record in input file (input.dat): dietPlans.txt  exercise.txt
Plan name																      *
Goal																		  *
Date in the form mm/dd/yyyy													  *
(blank line)																  *
Plan name                                                                     *
Goal																		  *
Date in the form mm/dd/yyyy          
*                                                                             *
* Format of output file (output.dat): See problem specification.              *
******************************************************************************/

// Credits: (Can't remember the websites, so I will just credit them all)

//Geeksforgeeks.com 
//www.runoob.com
//Chegg.com
//www.cplusplus.com


int main(void)
{
	fitnessAppwrapper app;

	app.runApp();

	system("pause");

	return 0;
}