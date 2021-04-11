#include <iostream>
#include <string>
#include<string.h>
using namespace std;
struct Class {
	string class_name;
	string class_teacher; //gvcn
	int num_of_student;
	Class* pNext;
};
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

//ham sua
void editClass(Class*& pClass)
{
	string newclass_name;
	string newclass_teacher;
	
	if (newclass_name != pClass->class_name)
	{
		cout << " Nhap lai ten lop: "; cin >> newclass_name;
	}
	if(newclass_teacher != pClass->class_teacher)
	{
		cout << " Nhap lai ten GVCN: "; cin >> newclass_teacher;
	}
	
	cout << "====================================\n\n";
	cout << "Lop: " << pClass->class_name << endl;
	cout << "Tong hoc sinh: " << pClass->num_of_student << endl;
	cout << "GVCN: " << pClass->class_teacher << endl;
	cout << "Nhap 1 de chinh sua ten lop\n"
		<< "Nhap 2 de chinh sua ten GVCN\n"
		<< "Nhap 0 de quay lai" << endl;
}
