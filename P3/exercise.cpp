#include "exercisePlan.h"
//constructor

exercisePlan::exercisePlan(int iCalories, string iplan, string iDate)
{
	plan = iplan;
	calories = iCalories;
	date = iDate;
}
//copy constructor
exercisePlan::exercisePlan(exercisePlan &iexercisePlan)
{
	plan = iexercisePlan.plan;
	calories = iexercisePlan.calories;
	date = iexercisePlan.date;
}

// copy with equal operator
exercisePlan & exercisePlan::operator = (exercisePlan &rhs)
{
	if (THISPOINTER != &rhs)
	{
		this->plan = rhs.plan;
		this->calories = rhs.calories;
		this->date = rhs.date;
	}
	return *THISPOINTER;
}
//destructor
exercisePlan :: ~exercisePlan(void)
{}
//set calorries
void exercisePlan::setCalories(int icalories)
{
	calories = icalories;
}
//set date
void exercisePlan::setdate(string idate)
{
	date = idate;
}
//set name
void exercisePlan::setname(string iname)
{
	plan = iname;
}

//get calories
int exercisePlan::getCalories(void) const
{
	return calories;
}
//get Date
string exercisePlan::getDate(void) const
{
	return date;
}
//get name
string exercisePlan::getName(void) const
{
	return plan;
}

/*************************************************************
* Function:editName
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:edit name
* Input parameters:
* Returns:void
* Preconditions:files read, prompted the user
* Postconditions:name of the plan edited
*************************************************************/
void exercisePlan::editName(void)
{
	char input = NULL;
	char inputnPlan[100];
	int success = 0;
	string nPlan;

	do {
		cout << "Give new exercise plan name" << endl;
		cin.getline(inputnPlan, 100);
		if (success != 0)
		{
			cout << "Do you want to change the name from" << plan << " to " << nPlan << " ?" << endl << "Enter(Y / y for Yes) or (N / n for No)" << endl;
			cin >> input;
			if (input == 'Y' || 'y')
			{
				success = 1;
				plan = nPlan;
			}
		}
		system("cls");
	} while (success != 0);
	system("cls");
}

//edit goal
void exercisePlan::editGoal(void)
{
	char input = NULL; int nGoal = 0, success = 0;

	do {
		cout << "Give your new goal: " << endl;
		cin >> nGoal;
		success = 1;
		if (success != 0)
		{
			cout << "Do you want to change the goal calories from " << calories << " to " << nGoal << " ?" << endl << "Enter (Y/y for Yes) or (N/n for No)" << endl;
			cin >> input;

			if (input == 'Y' || 'y')
			{
				calories = nGoal;
				success = 0;
			}
		}
		system("cls");
	} while (success != 0);

	system("cls");
}


/*************************************************************
* Function:editDate
* Date Created: 07/01/2018
* Date Last Modified: 07/05/2018
* Description:edit date
* Input parameters:
* Returns:void
* Preconditions:files read, prompted the user
* Postconditions:dates edited
*************************************************************/
void exercisePlan::editDate(void)
{
	char input = NULL, inputnPlan[100];
	int success = 0;
	string nDate;

	do {
		cout << "Give your new date " << endl;
		cin.getline(inputnPlan, 100);
		cin.getline(inputnPlan, 100);
		nDate = inputnPlan;
		success = 1;
		if (success != 0)
		{
			cout << "Do you want to change the date from " << date << " to " << nDate << "?" << endl << "Enter (Y/y for Yes) or (N/n for No)" << endl;
			cin >> input;
		}
		if (input == 'Y' || 'y')
		{
			success = 0;
			date = nDate;
		}
		system("cls");
	} while (success != 0);
	system("cls");
}



//Did most of this in lab (similar)
//set all values of exerciseplan 
//input: int icalories, string iplan, string idate
void exercisePlan::setExercisePlan(int icalories, string iplan, string idate)
{
	setname(iplan);
	setCalories(icalories);
	setdate(idate);
}
//print the exercise class
ostream &operator<<(ostream&lhs, exercisePlan&rhs)
{
	lhs << "Name of the plan: " << rhs.getName() << endl << "Date: " << rhs.getDate() << endl << "Goal: " << rhs.getCalories();
	return lhs;
}
//insert exercise plan
istream & operator >> (istream &lhs, exercisePlan &rhs)
{
	string getPlan;
	int getGoal = 0;
	string getDate;

	rhs.editName();
	rhs.editGoal();
	rhs.editDate();

	system("cls");

	return lhs;
}
//take a single plan from a file
fstream & operator >> (fstream & lhs, exercisePlan &rhs)
{
	char tCalories[100], date[100], name[100], temp[100];
	int calories = 0;

	lhs.getline(name, 100);
	lhs.getline(tCalories, 100);
	lhs.getline(date, 100);
	lhs.getline(temp, 100);

	calories = atoi(tCalories);

	rhs.setExercisePlan(calories, (string)name, (string)date);
	return lhs;
}
//write to file
fstream & operator << (fstream &lhs, exercisePlan &rhs)
{
	lhs << rhs.getName() << endl << rhs.getCalories() << endl << rhs.getDate() << endl;

	return lhs;
}
