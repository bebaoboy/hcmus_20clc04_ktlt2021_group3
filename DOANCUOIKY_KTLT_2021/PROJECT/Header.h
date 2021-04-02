#ifndef _MY_H_
#define _MY_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//khai bao struct
#include "struct.h"

void changeUserPassword(string& user_password);
void showUserAccount(UserAccount* pUser, string user_name);
void editUserAccount(UserAccount* pUser, string user_name);
bool checkUserName(UserAccount* pUser, string user_name);

void showSchoolYear(SchoolYear* pSchoolYear, Semester* pSemester);
void showSemester(Semester* pSemester);
void showClass(Class* pClass);
void showCourse(Course* pCourse);
void showStudentCourse(StudentCourse* pStuCourse);
void showCourseEnrollment(CourseEnrollment* pEnroll);
void showStudent(Student* pStudent);
void showStudentList(Student* pStudent);
void showStudentInCourse(StudentInCourse* pStuInCourse);

void editSchoolYear(SchoolYear*& pSchoolYear, Semester*& pSemester);
void editSemester(Semester*& pSemester);
void editClass(Class*& pClass);
void editCourse(Course*& pCourse);
void editCourseEnrollment(CourseEnrollment*& pEnroll);
void editStudent(Student*& pStudent);

//Ham Nhap Xuat

//Hamtinh diem

//Ham dk hp

//Ham xuat file
#endif // !_MY_H_