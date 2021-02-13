#pragma once
#include <string>
#include <iostream>
#include <fstream>
//#include <ostream>
//#include <istream>
#include <time.h>
#include <Windows.h>
#include <stdbool.h>
#include <stdlib.h>
#include "List.h"


using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::istream;
using std::ostream;
using std::fstream;
using std::ifstream;
using std::ofstream;


class menu 
{
public:
	menu(string newcourseFilename = "course.csv", string newmasterFilename = "master.csv", string newreportFilename = "reportfile.txt", 
		string newreportfileTHname = "reportfileTH.txt");
	//menu(string newcourseFilename, string newmasterFilename, string newreportFilename, string newreportFileTHname);
	//menu();
	~menu();


	void importCourseList(string filename);
	void loadMasterList(string filename);
	void storeMasterList(string filename);
	void markAbsences();
	void report();
	int mainMenu();
	
private:
	List classlist;

	ofstream courseList, masterList;
	fstream reportFile, reportFileTH;
	string coursefilename, masterfilename, reportfilename, reportfileTHname;

};

ostream & operator<<(ostream&lhs, Node&rhs);
fstream & operator >> (fstream & lhs, Node &rhs);
fstream & operator << (fstream &lhs, Node &rhs);
