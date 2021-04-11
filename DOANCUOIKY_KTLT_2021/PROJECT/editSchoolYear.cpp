#include <iostream>
#include <string>
using namespace std;

struct SchoolYear {
	int begin_year;
	int end_year;
	Semester* pSemester;
	SchoolYear* pNext;
};

struct Semester {
	int no;
	int begin_date, begin_month, begin_year;
	int end_date, end_month, end_year;
	Semester* pNext;
};
void editSchoolYear(SchoolYear*& pSchoolYear, Semester*& pSemester);

//ham sua
void editSchoolYear(SchoolYear*& pSchoolYear, Semester*& pSemester)
{
	int year = 0;
	pSchoolYear->pSemester = nullptr;
	cout << "====================================\n\n"
		<< "\t Nhap lai nam hoc ban can chinh sua (nien khoa - YYYY): ";
	cin >> year;

	while (year <= 0 || year > 9999) {
		cout << "\tVui long nhap lai nam: ";
		cin >> year;
	}
	pSchoolYear->begin_year = year;
	pSchoolYear->end_year = year + 1;

	cout << "====================================\n\n"
		<< "\tChinh sua nam hoc thanh cong!\n"
		<< "\tNam hoc: " << pSchoolYear->begin_year << " - " << pSchoolYear->end_year << endl
		<< " Nhap 0 de quay lai:" << endl;
}
