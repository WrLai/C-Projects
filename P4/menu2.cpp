#include "menu.h"
//menu::menu(string newcourseFilename, string newmasterFilename, string newreportFilename, string newreportFileTHname)
//{
//	this->coursefilename = newcourseFilename;
//	this->masterfilename = newmasterFilename;
//	this->reportfilename = newreportFilename;
//	this->reportfileTHname = newreportFileTHname;
//}

menu::menu(string newcourseFilename, string newmasterFilename , string newreportFilename,
	string newreportfileTHname)
{
	this->coursefilename = newcourseFilename;
	this->masterfilename = newmasterFilename;
	this->reportfilename = newreportFilename;
	this->reportfileTHname = newreportfileTHname;
}

menu::~menu()
{}

/*************************************************************
* Function:importcourselist
* Date Created: 07/10/2018
* Date Last Modified: 07/15/2018
* Description:import course list
* Input parameters:filename
* Returns:
* Preconditions:
* Postconditions:courselist imported
*************************************************************/
void menu::importCourseList(string filename) {
	ifstream file;
	file.open(filename);
	string line;
	string recordnumber;
	string id;
	string name, firstname, lastname;
	string email;
	string units;
	string program;
	string lvl;
	string space;
	getline(file, line);
	char delim = ',';
	char spacedelim = '\n';
	if (file.is_open())
	{
		system("cls");
		while (!file.eof())
		{

			getline(file, recordnumber, delim);
			//cout << "record: " << recordnumber << endl;
			getline(file, id, delim);
			//cout << "id: " << id << endl;
			getline(file, firstname, delim);
			getline(file, lastname, delim);
			name = firstname + lastname;
			//cout << "name: " << name<< endl;
			getline(file, email, delim);
			//cout << "email: " << email << endl;
			getline(file, units, delim);
			//cout << "units: " << units << endl;
			getline(file, program, delim);
			//cout << "program: " << program << endl;
			getline(file, lvl, '\n');
			//cout << "level: " << lvl << endl;
			if (id != "");
			{
				(this -> classlist).addNode(recordnumber,id,name,email,units,program,lvl);
			}
			recordnumber = " ";
			id = "";
			
		}
		file.close();
	}
	//this->classlist = (this->classlist);
	classlist.displayList();
}

/*************************************************************
* Function:loadmasterlist
* Date Created: 07/10/2018
* Date Last Modified: 07/15/2018
* Description:load masterlist
* Input parameters:filename
* Returns:
* Preconditions:
* Postconditions:masterlist loaded
*************************************************************/
void menu::loadMasterList(string filename) {
	ifstream file;
	file.open(filename);
	string line;
	string recordnumber;
	string id;
	string name, firstname, lastname;
	string email;
	string units;
	string program;
	string lvl;
	string space;
	//List tem;
	//file >> line;
	getline(file, line);
	char delim = ',';
	char spacedelim = '\n';
	if (file.is_open())
	{
		system("cls");
		while (!file.eof())
		{

			getline(file, recordnumber, delim);
			//cout << "record: " << recordnumber << endl;
			getline(file, id, delim);
			//cout << "id: " << id << endl;
			getline(file, firstname, delim);
			getline(file, lastname, delim);
			name = firstname + lastname;
			//cout << "name: " << name<< endl;
			getline(file, email, delim);
			//cout << "email: " << email << endl;
			getline(file, units, delim);
			//cout << "units: " << units << endl;
			getline(file, program, delim);
			//cout << "program: " << program << endl;
			getline(file, lvl, '\n');
			//cout << "level: " << lvl << endl;
			if (recordnumber != " ");
			{
				(this->classlist).addNode(recordnumber, id, name, email, units, program, lvl);

				//tem.addNode(line, line, line, line, line, line, line);
			}
			recordnumber = " ";
			//List addNode(string  recordNumber, string  id, string name, string email, string  units, string program, string lvl);
		}
		file.close();
	}
	this->classlist = (this->classlist);
	classlist.displayList();
}

/*************************************************************
* Function:storemasterList
* Date Created: 07/10/2018
* Date Last Modified: 07/15/2018
* Description:store master list
* Input parameters:filename
* Returns:
* Preconditions:
* Postconditions:masterlist stored
*************************************************************/
void menu::storeMasterList(string filename) 
{
	std::ofstream file;
	file.open(filename);
	Node *temp = classlist.getHead();
	for (; temp != NULL;) {
		file << temp->getRecordNumber() << "," << temp->getId() << "," << temp->getName() << "," << temp->getEmail() << ",";
		file << temp->getUnits() << "," << temp->getProgram() << "," << temp->getLevel() << "," << temp->getNumberOfAbsences() << "\n";
		temp = temp->getNext();
	}
	file.close();
	cout << "\nMaser list data saved to file.";
}

/*************************************************************
* Function:mark absences
* Date Created: 07/10/2018
* Date Last Modified: 07/15/2018
* Description: mark student absences
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:student absences marked
*************************************************************/
void menu::markAbsences() {
	string idNo;
	int absent = 0;
	cout << "\nEnter id no. : " << endl;
	cin >> idNo;
	time_t t = time(0);   // get time now
	char MY_TIME[100];

	struct tm * now = localtime(&t);

	strftime(MY_TIME, 15, "%D", now);
	string timeofdate(MY_TIME);
	cout << (now->tm_year + 1900) << '-'

		<< (now->tm_mon + 1) << '-'

		<< now->tm_mday

		<< endl;
	Node *temp = classlist.getHead();
	for (; temp != NULL;) {
		
		cout << "STUDENT: " << temp->getName() << endl
			<< "Is this student absent? Enter 1 if so ";
		cin >> absent;
		if (absent == 1) {
			temp->setNumberOfAbsences(temp->getNumberOfAbsences() + 1);
			(temp->getAbsences()).push(timeofdate);
		}

		temp = temp->getNext();
	}
	

}

/*************************************************************
* Function: report
* Date Created: 07/10/2018
* Date Last Modified: 07/15/2018
* Description:generating a report
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:generated a report
*************************************************************/
void menu::report()
{
	classlist.displayList();

}

/*************************************************************
* Function:mainMenu
* Date Created: 07/10/2018
* Date Last Modified: 07/15/2018
* Description:App runner, putting everything together and make it work
* Input parameters:
* Returns:
* Preconditions:
* Postconditions:
*************************************************************/
int menu::mainMenu() {

	int option = 0, choice = 0; int success = 0;
	do {
		//system("cls");
		cout << "1. Import course list";
		cout << "\n2. Load master list";
		cout << "\n3. Store master list";
		cout << "\n4. Mark absences";
		cout << "\n5. Edit absences";
		cout << "\n6. Generate report";
		cout << "\n7. Exit";
		cout << "\nEnter choice: ";
		cin >> option;
		switch (option) {
		case 1:
			importCourseList("ClassList.csv");
			break;
		case 2:
			loadMasterList("master.txt");
			break;
		case 3:
			storeMasterList("master.txt");
			break;
		case 4:
			markAbsences();
			break;
		case 5:

			break;
		case 6:
				do {
					cout << "Generate a full report(1) or students with absences(2)" << endl;
					cin >> choice;
					if (choice == 1)
					{
						this->classlist.displayList();
						success = 1;
					}
					/*else (choice = 2)
					{

					}*/

				} while (success != 1);
			break;
		case 7:
			cout << "Thanks for using the attendance program" << endl;
			break;
		}
	} while (option != 7);
	return option;
}

ostream &operator<<(ostream&lhs, Node&rhs)
{
	lhs << "Record Number: " << rhs.getRecordNumber()
		<< endl << "ID: " << rhs.getId() << endl << "Name: " << rhs.getName()
		<< "Email: " << rhs.getEmail() << "Units: " << rhs.getUnits() << "Program: " << rhs.getProgram()
		<< "Level: " << rhs.getLevel();
	return lhs;
}

fstream & operator >> (fstream & lhs, Node &rhs)
{
	char recordNumber[100], id[100], name[100], email[100], units[100], program[100], level[100];
	int absentCount; 

	lhs.getline(recordNumber, 100);
	lhs.getline(id, 100);
	lhs.getline(name, 100);
	lhs.getline(email, 100);
	lhs.getline(units, 100);
	lhs.getline(program, 100);
	lhs.getline(level, 100);

	rhs.setInformation(recordNumber, id, name, email, units, program, level, absentCount);
	return lhs;
}

fstream & operator << (fstream &lhs, Node &rhs)
{
	lhs << rhs.getRecordNumber() << endl << rhs.getId() << endl << rhs.getName() << endl
		<< rhs.getEmail() << endl << rhs.getUnits() << endl << rhs.getProgram() << endl << rhs.getLevel() << endl;
	return lhs;
}