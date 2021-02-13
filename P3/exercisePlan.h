#include <iostream> 
#include <fstream> 
#include <string> 
#include <stdlib.h>
#define THISPOINTER this

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
using std::fstream;

class exercisePlan {
public:
	exercisePlan(int iCalories = 0, string iplan = "None input", string iDate = "None input");
	~exercisePlan();
	exercisePlan(exercisePlan &iexercisePlan);//copy
	exercisePlan &operator = (exercisePlan &rhs);// copy

	void setname(string iname);

	void setCalories(int icalories);
	void setdate(string idate);

	string getName(void) const;
	int exercisePlan::getCalories(void) const;
	string getDate(void) const;

	void editName(void);
	void editGoal(void);
	void editDate(void);


	void setExercisePlan(int icalories, string iplan, string idata);

private:
	string plan;
	int calories;
	string date;
};

ostream &operator<<(ostream&lhs, exercisePlan&rhs);
istream & operator >> (istream &lhs, exercisePlan &rhs);
fstream & operator >> (fstream & lhs, exercisePlan &rhs);
fstream & operator << (fstream &lhs, exercisePlan &rhs);