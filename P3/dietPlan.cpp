#include "dietplan.h"
//constructor
dietPlan::dietPlan(int iCalories, string iplan, string iDate)
{
	plan = iplan;
	calories = iCalories;
	date = iDate;
}
//copy constructor
dietPlan::dietPlan(dietPlan &idietPlan)
{
	plan = idietPlan.plan;
	calories = idietPlan.calories;
	date = idietPlan.date;
}

// copy with equal operator
dietPlan & dietPlan::operator = (dietPlan &rhs)
{
	if (this != &rhs)
	{
		this->plan = rhs.plan;
		this->calories = rhs.calories;
		this->date = rhs.date;
	}
	return *THISPOINTER;
}
//destructor
dietPlan :: ~dietPlan(void)
{}
//set calorries
void dietPlan::setCalories(int icalories)
{
	calories = icalories;
}
//set date
void dietPlan::setdate(string idate)
{
	date = idate;
}
//set name
void dietPlan::setname(string iname)
{
	plan = iname;
}

//get calories
int dietPlan::getCalories(void) const
{
	return calories;
}
//get date
string dietPlan::getDate(void) const
{
	return date;
}
//get name
string dietPlan::getName(void) const
{
	return plan;
}

//same as exercise.cpp
void dietPlan::editName(void)
{
	char input = NULL;
	char inputnPlan[100];
	int success = 0;
	string nPlan;

	do {
		cout << "Give new diet plan name" << endl;
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
void dietPlan::editGoal(void)
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

// same as exercise.cpp
void dietPlan::editDate(void)
{
	char input = NULL, inputnPlan[100];
	int success = 0;
	string nDate;

	do {
		cout << "Give your new date " << endl;
		cin.getline(inputnPlan, 100);
		cin.getline(inputnPlan, 100);
		nDate = inputnPlan;
	
		cout << "Do you want to change the date from " << date << " to " << nDate << "?" << endl << "Enter (Y/y for Yes) or (N/n for No)" << endl;
			cin >> input;
			success = 0;
		if (input == 'Y' || 'y')
		{
			date = nDate;
		}
		
	} while (success != 0);
	system("cls");
}

//same to exercise.cpp, they are almost the same


void dietPlan::setDietPlan(int icalories, string iplan, string idate)
{
	setname(iplan);
	setCalories(icalories);
	setdate(idate);
}

ostream &operator<<(ostream&lhs, dietPlan&rhs)
{
	lhs << "Name of the plan: " << rhs.getName() << endl << "Date: " << rhs.getDate() << endl << "Goal: " << rhs.getCalories();
	return lhs;
}

istream & operator >> (istream &lhs, dietPlan &rhs)
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

fstream & operator >> (fstream & lhs, dietPlan &rhs)
{
	char tCalories[100], date[100], name[100], temp[100];
	int calories = 0;
	lhs.getline(name, 100);
	lhs.getline(tCalories, 100);
	lhs.getline(date, 100);
	lhs.getline(temp, 100);

	calories = atoi(tCalories);

	rhs.setDietPlan(calories, (string)name, (string)date);
	return lhs;
}

fstream & operator << (fstream &lhs, dietPlan &rhs)
{
	lhs << rhs.getName() << endl << rhs.getCalories() << endl << rhs.getDate() << endl;

	return lhs;
}
