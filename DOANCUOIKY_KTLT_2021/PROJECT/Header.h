#ifndef _MY_H_
#define _MY_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>

using namespace std;

//khai bao struct
#include "struct.h"

//ham tai khoan
void changeUserPassword(string& user_password);
void showUserAccount(UserAccount* pUser, string user_name);
void editUserAccount(UserAccount* pUser, string user_name);
bool checkUserName(UserAccount* pUser, string user_name);

//ham tao
void createSchoolYear(SchoolYear*& pSchoolYear);
void createSemester(Semester*& pSemester, int year);
void createClass(Class*& pClass);
void createStudent(Student*& pStudent);

//ham show thong tin
void showSchoolYear(SchoolYear* pSchoolYear);
void showSemester(Semester* pSemester, int year);
void showSemesterTime(Semester* pSemester, int year);
void showClass(Class* pClass);//unfin
void showCourse(Course* pCourse);
void showStudentCourse(StudentCourse* pStuCourse);
void showCourseEnrollment(CourseEnrollment* pEnroll);
void showStudent(Student* pStudent);
void showMainClass(Class* pClass);//unfin
void showStudentList(Student* pStudent);//unfin
void showStudentInCourse(StudentInCourse* pStuInCourse);

//ham chinh sua
void checkDate(int& date, int& month, int& year, int year2);
void editSchoolYear(SchoolYear*& pSchoolYear);
void editSemester(Semester*& pSemester, int year);
void editClass(Class*& pClass); //unfin
void editCourse(Course*& pCourse);
void editCourseEnrollment(CourseEnrollment*& pEnroll);
void editStudent(Student*& pStudent); //unfin

//Ham Nhap Xuat
void inputClass(Class*& pClass, ifstream& input);

//Hamtinh diem

//Ham dk hp

//Ham xuat file
void printScoreboard();
#endif // !_MY_H_