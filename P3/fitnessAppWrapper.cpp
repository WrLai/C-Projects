#include "fitnessAppWrapper.h"


/*************************************************************
* Function: fitnessAppwrapper                               *
* Date Created:        07/01/2018                           *
* Date Last Modified:     07/05/2018                        *
* Description: constructor                                  *
* Input parameters:void                                     *
* Returns:                                                  *
* Preconditions:                                            *
* Postconditions:                                           *
*************************************************************/
fitnessAppwrapper::fitnessAppwrapper(void)
{
	this->dietplan = new dietPlan[7];
	this->exersiseplan = new exercisePlan[7];
}
/*************************************************************
* Function: ~futbessAoowraooer
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:destructor
* Input parameters:
* Returns:
* Preconditions:constructor
* Postconditions:clear the space
*************************************************************/
fitnessAppwrapper::~fitnessAppwrapper(void)
{
	delete[] this->dietplan;
	delete[] this->exersiseplan;
}

/*************************************************************
* Function:runApp
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:App runnner
* Input parameters:
* Returns:
* Preconditions: everything, this function gathers all functions 
* Postconditions: Run the app
*************************************************************/
void fitnessAppwrapper::runApp(void)
{
	int exit = 1, dcheck = 0, echeck = 0;
	char dOption = NULL, eOption = NULL;
	

	while (exit != 0)
	{
		switch (menu())
		{
		case 1:
			dcheck = 1;
			dietplana.open("dietPlans.txt");
			loadWeeklydp(dietplana);
			dietplana.close();
			break;
		case 2:
			echeck = 1;
			exerciseplana.open("excersice.txt");
			loadWeeklyep(exerciseplana);
			exerciseplana.close();
			break;
		case 3:
			if (dcheck)
			{
				saveWeeklydp(dietfile);
				dietfile.close();
			}
			else {
				cout << "You need to load it first." << endl;
				Sleep(2000);
				system("cls");
			}
			break;
		case 4:
			if (echeck)
			{
				saveWeeklyep(exercisefile);
				exercisefile.close();
			}
			else
			{
				cout << "You need to load it first." << endl;
				Sleep(2000);
				system("cls");
			}
			break;
		case 5:
			if (dcheck)
			{
				showweeklydietplan();
			}
			else
			{
				cout << "Data not loaded. You need to load it first!" << endl;
				cout << "If you insist to show the weekly diet plan, enter (Y/y) for yes." << endl;
				cin >> dOption;
				if (dOption == 'y' || dOption == 'Y')
				{
					showweeklydietplan();
				}
				else {
					cout << "Return to main menu.";
					Sleep(2000);
					system("cls");
				}

				
			}
			break;
		case 6:
			if (echeck)
			{
				showweeklyexerciseplan();
			}
			else {
				cout << "Data not loaded. You need to load it first!" << endl;
				cout << "If you insist to show the weekly exercise plan, enter (Y/y) for yes." << endl;
				cin >> eOption;
				if (eOption == 'y' || eOption == 'Y')
				{
					showweeklyexerciseplan();
				}
				else {
					cout << "Return to main menu.";
					Sleep(2000);
					system("cls");
				}
				
			}
			break;
		case 7:
			if (dcheck)
			{
				editDietplan();
			}
			else {
				cout << "Data not loaded. You need to load it first!" << endl;
				Sleep(2000);
				system("cls");
			}
			break;
		case 8:
			if (echeck)
			{
				editExerciseplan();
			}
			else {
				cout << "Data not loaded. You need to load it first!" << endl;
				Sleep(2000);
				system("cls");
			}
			break;
		case 9:
			exit = 0;
		}
	}
}
/*************************************************************
* Function: menu
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description: display the menu
* Input parameters:
* Returns: option
* Preconditions:
* Postconditions: get the user's input value and interact with run App
*************************************************************/
int fitnessAppwrapper:: menu(void)
{
	int option = 0;

	cout << "Welcome to the fitness Application." << endl;
	
	do {
		cout << "Main Menu: " << endl
			<< "Please make your selection (1-9)" << endl
			<< "1.Load weekly dietplan from the file" << endl
			<< "2.Load weekly exercise plan from the file" << endl
			<< "3.Save weekly diet plan to file" << endl
			<< "4.Save weekly exercise plan to file" << endl
			<< "5.Display weekly diet plan to screen" << endl
			<< "6.Display weekly exercise plan to screen" << endl
			<< "7.Edit your daily diet plan" << endl
			<< "8.Edit your daily exercise plan" << endl
			<< "9.Exit" << endl << "Enter your selection below: " << endl;

		cin >> option;
		if ((option <= 0) || (option >= 12))
		{
			cout << "Please enter a valid number from 1 - 11" << endl;
			Sleep(2000);
		}
			
	} while ((option <= 0) || (option >= 12));
		return option;
}
/*************************************************************
* Function:showDailydietplan
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:show daily diet plan
* Input parameters: dietPlan &day
* Returns:
* Preconditions: files exist
* Postconditions: daily plan shown
*************************************************************/
void fitnessAppwrapper::showDailydietplan(dietPlan &day)
{
	cout << day << endl;
}
/*************************************************************
* Function:showweeklydietplan
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:show weekly diet plan
* Input parameters:
* Returns:
* Preconditions: daily diet plan
* Postconditions: show a weekly diet plan
*************************************************************/
void fitnessAppwrapper::showweeklydietplan(void)
{
	cout << "Displaying weekly diet plan";
	Sleep(500);
	cout<< ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	int count = 0;
	while (count < 7)
	{
		showDailydietplan(this->dietplan[count]);
		count++;
	}
	system("pause");
	cout << "Returning to Main menu";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	system("cls");
}
/*************************************************************
* Function:showDailyexerciseplan
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:show daily exerciseplan
* Input parameters:exercisePlan &day
* Returns:
* Preconditions:files exist
* Postconditions:daily exercise plan shown
*************************************************************/
void fitnessAppwrapper::showDailyexerciseplan(exercisePlan &day)
{
	cout << day << endl;
}
/*************************************************************
* Function:showweeklyexerciseplan
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:show a weekly exercise plan
* Input parameters:
* Returns:
* Preconditions:show daily exercise plan
* Postconditions:A weekly exercise plan shown
*************************************************************/
void fitnessAppwrapper::showweeklyexerciseplan(void)
{
	cout << "Displaying weekly exercise plan";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	int count = 0;
	while (count < 7)
	{
		showDailyexerciseplan(this->exersiseplan[count]);
		count++;
	}
	system("pause");
	cout << "Returning to Main menu";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	system("cls");
}
/*************************************************************
* Function:editDietplan
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:edit diet plan
* Input parameters:
* Returns:
* Preconditions: files read
* Postconditions: day edited
*************************************************************/
void fitnessAppwrapper::editDietplan(void)
{
	int temp = 0;

	do {
		cout << "From Monday to Sunday (1 - 7), enter the day you want to edit: " << endl;
		cin >> temp;
	} while ((temp <= 0) || (temp >= 8));

	cin >> this->dietplan[temp - 1];
	cout << this->dietplan[temp - 1] << endl << "Return to Main menu";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	system("cls");

}
/*************************************************************
* Function:editExerciseplan
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:edit exercise plan
* Input parameters:
* Returns:
* Preconditions:files read
* Postconditions:day edited
*************************************************************/
void fitnessAppwrapper::editExerciseplan(void)
{
	int temp = 0;
	do {
		cout << "From Monday to Sunday (1 - 7), enter the day you want to edit: " << endl;
		cin >> temp;
	} while ((temp <= 0) || (temp >= 8));

	cin >> this->exersiseplan[temp - 1];
	cout << this->exersiseplan[temp - 1] << endl << "Return to Main menu";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	system("cls");
}
/*************************************************************
* Function:loadDailydp
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:load daily diet plan from a file
* Input parameters:fstream &dietfile, dietPlan &plan
* Returns:
* Preconditions:files exist
* Postconditions:files loaded
*************************************************************/
void fitnessAppwrapper::loadDailydp(fstream &dietfile, dietPlan &plan)
{
	dietfile >> plan;
}
/*************************************************************
* Function:Loadweeklydp
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:load weekly diet plan
* Input parameters:fstream &dietfile
* Returns:
* Preconditions: load daily diet plan
* Postconditions: weekly diet plan loaded
*************************************************************/
void fitnessAppwrapper::loadWeeklydp(fstream &dietfile)
{
	int count = 0;
	while (count < 7)
	{
		loadDailydp(dietfile, this->dietplan[count]);
		count++;
	}
	cout << "Reading weekly diet plan = Done." << endl << "Returning to Main menu";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	system("cls");
}
/*************************************************************
* Function:loadDailyep
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description: load daily exercise plan
* Input parameters:fstream &exercisefile, exercisePlan &day
* Returns:
* Preconditions:files exist 
* Postconditions:daily exercise plan loaded
*************************************************************/
void fitnessAppwrapper::loadDailyep(fstream &exercisefile, exercisePlan &day)
{
	exercisefile >> day;
}
/*************************************************************
* Function:loadWeeklyep
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:load weekly exercise plan
* Input parameters:fstream &exercisefile
* Returns:
* Preconditions:load daily exercise plan
* Postconditions:weekly exercise plan loaded
*************************************************************/
void fitnessAppwrapper::loadWeeklyep(fstream &exercisefile)
{
	int count = 0;
	while (count < 7)
	{
		loadDailyep(exercisefile, this->exersiseplan[count]);
		count++;
	}
	cout << "Reading weekly exercise plan = Done." << endl << "Returning to Main menu";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	system("cls");
}
/*************************************************************
* Function:saveDailydp
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:store daily diet plan
* Input parameters:fstream&dietfile, dietPlan &day
* Returns:
* Preconditions:space allocated
* Postconditions:daily diet plan stored
*************************************************************/
void fitnessAppwrapper::saveDailydp(fstream&dietfile, dietPlan &day)
{
	dietfile << day;
}
/*************************************************************
* Function:saveWeeklydp
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:store weekly diet plan
* Input parameters:fstream &dietfile
* Returns:
* Preconditions:savedailydp function
* Postconditions:weekly diet plan stored
*************************************************************/
void fitnessAppwrapper::saveWeeklydp(fstream&dietfile)
{
	int count = 0;
	while (count < 7)
	{
		saveDailydp(dietfile, this->dietplan[count]);
		count++;
	}
	cout << "Saving weekly diet plan = Done." << endl << "Returning to Main menu";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	system("cls");
}
/*************************************************************
* Function:saveDailyep
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:store daily exercise plan
* Input parameters:fstream&exercisefile, int day
* Returns:
* Preconditions:space allocated
* Postconditions:daily exercise plan stored
*************************************************************/
void fitnessAppwrapper::saveDailyep(fstream&exercisefile, int day)
{
	exercisefile << day;
}
/*************************************************************
* Function:saveWeeklyep
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:store weekly exercise plan
* Input parameters:fstream &exercisefile
* Returns:
* Preconditions:savedailyep
* Postconditions:weekly exercise plan stored
*************************************************************/
void fitnessAppwrapper::saveWeeklyep(fstream&exercisefile)
{
	int count = 0;
	while (count < 7)
	{
		saveDailyep(exercisefile, count);
		count++;
	}
	cout << "Saving weekly diet plan = Done." << endl << "Returning to Main menu";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	cout << ".";
	Sleep(500);
	system("cls");
}


