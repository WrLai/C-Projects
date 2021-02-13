#include <iostream>
#include <stdlib.h>
#include "exercisePlan.h"
#include "dietplan.h"
#include <Windows.h>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
using std::fstream;
using std::ifstream;
using std::ofstream;

class fitnessAppwrapper
{
public:
	fitnessAppwrapper();
	~fitnessAppwrapper();

	void runApp(void);

	int menu(void);
	

	void showDailydietplan(dietPlan &day);
	void showweeklydietplan(void);

	void showDailyexerciseplan(exercisePlan &day);
	void showweeklyexerciseplan(void);

	void editDietplan(void);
	void editExerciseplan(void);

	void loadDailydp(fstream &dietfile, dietPlan &plan);
	void loadWeeklydp(fstream &dietfile);

	void loadDailyep(fstream &exercisefile, exercisePlan &day);
	void loadWeeklyep(fstream &exercisefile);

	void saveDailydp(fstream&dietfile, dietPlan &day);
	void saveWeeklydp(fstream&dietfile);

	void saveDailyep(fstream&exercisefile, int day);
	void saveWeeklyep(fstream&dietfile);
private:
	dietPlan *dietplan;
	exercisePlan *exersiseplan;
	fstream dietfile, exercisefile, dietplana, exerciseplana;
};
