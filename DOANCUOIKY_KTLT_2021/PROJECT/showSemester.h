#pragma once
#include <iostream>
using namespace std;
struct Semester {
	int no;
	int begin_date, begin_month, begin_year;
	int end_date, end_month, end_year;
	Semester* pNext;
};

void print_SemesterMenu_ofStaff();
void showSemester_forStaff(Semester *pSemester);
void editSemester(Semester *pSemester);