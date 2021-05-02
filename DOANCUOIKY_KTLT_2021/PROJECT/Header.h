#ifndef _MY_H_
#define _MY_H_

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <windows.h> 
#include <ctime>
#include <conio.h>

using namespace std;

//khai bao struct
#include "struct.h"

void gotoXY(int x, int y);
void TextColor(int color);
void Flashing(string s);
void Run(string s);

//ham tai khoan
void getPassword(string& a);
void changeUserPassword(string& user_password);
void showUserAccount(UserAccount* pUser, string user_name);
void editUserAccount(UserAccount* pUser, string user_name);
bool checkUserName(UserAccount* pUser, string user_name);
void showTime();
void teacherClass(UserAccount* pUser, Class* pClass);

//ham tao
void createSchoolYear(SchoolYear*& pSchoolYear);
void createSemester(Semester*& pSemester, int year);
void createClass(Class*& pClass, extraStudent* pExtra);
void createCourse(Course*& pCourse);
void createStudent(Student*& pStudent, int &num);
void createTimeTable(Time*& p);

//ham show thong tin
void showSchoolYear(SchoolYear* pSchoolYear);
void showSemesterTime(Semester* pSemester, int year);
void showClass(Class* &pClass, Semester *&pSemester);
void showCourseList(Course* &pCourse);
void showCourse(Course* &pCourse);
void showStudentCourse(StudentCourse* &pStuCourse, Student *&pS);
void showStudentInCourse(StudentInCourse* &pStuInCourse, Course* &pCourse);
void showStudent(Student* &pStudent);
void showMainClass(Class* pClass);
void showStudentList(Student* pStudent, int& num);
void showTimeTable(Time* pT);
Student* searchStudent(string full_name, string id, Class* &pClass, Semester* &pSemester);
void showExtraStudent(extraStudent* pExtra, Class *pClass);

//ham chinh sua
void checkDate(int& date, int& month, int& year, int year2);
void editSchoolYear(SchoolYear*& pSchoolYear);
void editSemester(Semester*& pSemester, int year);
void editClass(Class*& pClass); 
void editCourse(Course*& pCourse);
void editStudent(Student*& pStudent); 

//Ham Nhap Xuat
void inputSchoolYear(SchoolYear* &pSchoolYear);
void inputClass(Class*& pClass, ifstream& input);
void inputTeacher(UserAccount*& pUser, ifstream& input);
void inputCourse(Course*& pCourse, ifstream& input);
void inputTimeTable(Time* p, int a, int b);
void inputExtraStudent(extraStudent*& pExtra);

//ham delete
void deleteClass(Class*& pClass);
void deleteCourse(Course*& pCourse);
void deleteStudent(Student*& pStudent);
void deleteTimeTable(Time*& p);
void deleteUser(UserAccount*& pUser);
void deleteStuInCourse(StudentInCourse*& pTemp2);
void deleteStuCourse(StudentCourse*& pTemp2);
void deleteSchoolYear(SchoolYear* pSchoolYear);
void deleteCourseEnrollment(CourseEnrollment*& pCE);
void deleteExtraStudent(extraStudent*& pE);

//Ham dk hp 
void createCourseEnrollment(CourseEnrollment*& pEnroll, Semester *pSemester);
void editCourseEnrollment(CourseEnrollment*& pEnroll, Semester* pSemester);
void showCourseEnrollment(CourseEnrollment*& pEnroll, Semester* pSemester);
void Enroll(CourseEnrollment* &pEnroll, Student* &pStudent, Course* &pCourse);
void toStudentCourse(Student *&pSC, Course *&pCourse, int no);
void toStudentInCourse(Course*& pC, Student*& pStudent);
void courseClass(StudentInCourse* p);
bool checkSchedule(Time* pTime, Time* pTable);
void removeRegCourse1(Student* &pS, int t);
void removeRegCourse2(Course *&pC, int t);
void schedule(Time* pTime, Time* pTable);
void deschedule(Time* pTime, Time* pTable);
void createHistory(StudentHistory*& pH, Student* pS);
void showStudentHistory(StudentHistory* pH);

//Ham diem
//void inputCourseScore(Course*& pC, Class* pClass); //nhap hoc sinh va diem cua hoc phan
void gPA(Class* pClass);
void randomScore(double &a, double &b, double &c, double &d);
double toGPA (double n, string &grade);
void printCourseScoreboard();
void printClassScoreboard(Class *pClass);
void printStudentScoreboard(Student *pS);
bool failCheck(double n);
void inputCourseScore(Course* pC);

//Ham xuat file
void exportClass(Class *pClass); //student and score/gpa
void exportStudentInCourse(StudentInCourse* pStuInCourse);

//void courseClassEnum(Class* pClass, StudentInCourse* p);
//void eraseTimeTable(Time* p);
//void showCourseClass(Course* pCourse);
//void exportStudentScore(); //gv chon
//void exportStudentHistory();
//void exportCourseScore(StudentInCourse* pStuInCourse); //xuat diem cua 1 khoa hoc
#endif // !_MY_H_