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
void createCourse(Course*& pCourse);
void createStudent(Student*& pStudent, int &num);
void createCourseEnrollment(CourseEnrollment*& pEnroll);
void createStudentCourse(StudentCourse* &pStudentCourse, Course* pCourse);
void createStudentInCourse(StudentInCourse* &pStuInCourse, Student* pStudent);
void createTimeTable(Student* pStudent);

//ham show thong tin
void showSchoolYear(SchoolYear* pSchoolYear);
void showSemester(Semester* pSemester, int year);
void showSemesterTime(Semester* pSemester, int year);
void showClass(Class* pClass);
void showCourseList(Course* pCourse);
void showCourse(Course* pCourse);
void showStudentCourse(StudentCourse* pStuCourse);
void showStudentInCourse(StudentInCourse* pStuInCourse);
void showCourseEnrollment(CourseEnrollment* pEnroll);
void showStudent(Student* pStudent);
void showMainClass(Class* pClass);
void showStudentList(Student* pStudent, int& num);

//ham chinh sua
void checkDate(int& date, int& month, int& year, int year2);
void editSchoolYear(SchoolYear*& pSchoolYear);
void editSemester(Semester*& pSemester, int year);
void editClass(Class*& pClass); 
void editCourse(Course*& pCourse);
void editStudentCourse(StudentCourse* &pStuCourse);
void editStudentInCourse(StudentInCourse* &pStuInCourse);
void editCourseEnrollment(CourseEnrollment*& pEnroll);
void editStudent(Student*& pStudent); 

//Ham Nhap Xuat
void inputSchoolYear(SchoolYear* &pSchoolYear);
void inputClass(Class*& pClass, ifstream& input);
void inputTeacher(UserAccount*& pUser, ifstream& input);
void inputCourse(Course*& pCourse, ifstream& input);

//ham delete
void deleteClass(Class*& pClass);
void deleteUser(UserAccount*& pUser);

//Hamtinh diem

//Ham dk hp 
void toStudentCourse(StudentCourse *&pSC, Course *pCourse);
void toStudentInCourse(StudentInCourse *&pSIC, Course *pCourse);

//Ham xuat file
void printScoreboard();
#endif // !_MY_H_