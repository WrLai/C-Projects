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

class dietPlan {
public:\
	dietPlan(int iCalories = 0, string iplan = "None input", string iDate = "None input");
	~dietPlan();
	dietPlan(dietPlan &idietPlan);//copy
	dietPlan &operator = (dietPlan &rhs);// copy

	void setCalories(int icalories);
	void setdate(string idate);
	void setname(string iname);

	string getName(void) const;
	int dietPlan::getCalories(void) const;
	string getDate(void) const;

	void editName(void);
	void editGoal(void);
	void editDate(void);
	


	void setDietPlan(int icalories, string iplan, string idata);

private:
	string plan;
	int calories;
	string date;
};
ostream &operator<<(ostream&lhs, dietPlan&rhs);
istream & operator >> (istream &lhs, dietPlan &rhs);
fstream & operator >> (fstream & lhs, dietPlan &rhs);
fstream & operator << (fstream &lhs, dietPlan &rhs);