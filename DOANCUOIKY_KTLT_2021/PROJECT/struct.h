#ifndef _MY_S_
#define _MY_S_
#include "Header.h"

struct SchoolYear;
struct Semester;
struct Course;
struct Class;
struct Student;
struct extraStudent;
struct StudentCourse;
struct StudentInCourse;
struct Time;
struct StudentHistory;
struct CourseEnrollment;
struct UserAccount;

enum Status { LEFT, RIGHT };
struct Word
{
	string s;
	int x, y;
	Status t;
};

struct Time {
	string day; //mon to sat
	string *session; //1(7h30), 2(9h30), 3(1h30), 4(15h30)
};

struct StudentCourse {
	int semester_no;
	string course_id;
	string course_name;
	int course_class;
	string course_teacher;
	int num_of_credit;
	double progress_mark = 0;
	double final_mark=0;
	double midterm_mark=0;
	double total_mark=0;
	double GPA=0;
	StudentCourse* pNext;
	Time* pTime;
	Course* pCourse;
};

struct Student
{
//student in class
	int no;
	string full_name;
	string id;
	char gender; //M , F
	string dob, mob, yob; //ngay thang nam sinh
	string social_id; //cmnnd
	string mainclass;
	StudentCourse* pStuCourse = nullptr;
	int num_of_course = 0;
	Student* pNext;
	Time* pTable;
	string user_name;
	string user_password;
	double GPA = 0;
	//int user_type = 1;

};

struct extraStudent
{
	int no;
	int active = 1;
	string full_name;
	string id;
	char gender; //M , F
	string dob, mob, yob;
	extraStudent* pNext = nullptr;
};

struct StudentInCourse
{
/*string full_name;
string id;
char gender;
string dob, mob, yob;
string mainclass;*/
	int course_class=0;
	string course_classroom;
	string course_id;
	double final_mark = 0;
	double midterm_mark = 0;
	double progress_mark = 0;
	double total_mark = 0;
	double GPA = 0;
	StudentInCourse* pNext;
	Student* pStudent;
};

struct StudentHistory
{
	Student* pStudent;
	StudentHistory* pNext = nullptr;
	string time;
};

struct UserAccount { //teacher only
	string full_name;
	string user_name;
	string user_password;
	string user_class;
	//int user_type = 2; //1 = GV, 2 = SV
	UserAccount* pNext;
	Class* pClass = nullptr;
};

struct Course {
	string course_id;
	string course_name;
	string course_mainteacher; //gvlt
	string course_teacher; //gvth
	int num_of_credit;
	int max_student = 15;
	int num_of_student = 0;
	int num_of_class = 0;
	double *class_GPA;
	Time* pTime;
	StudentInCourse* pStuInCourse;
	Course* pNext;
};

struct CourseEnrollment {
	int status = 0;
	int semester_no = 0;
	string id;
	int start_date, start_month, start_year;
	int end_date, end_month, end_year;
	Course* pCourse;
	CourseEnrollment* pNext;
	StudentHistory* pStudentHistory=nullptr;
};

struct Class {
	string class_name;
	string class_teacher; //gvcn
	int num_of_student=0;
	Student* pStudent;
	double GPA = 0;
	Class* pNext;
	UserAccount* pU = nullptr;
};

struct Semester {
	int no;
	int begin_date, begin_month, begin_year;
	int end_date, end_month, end_year;
	Class* pClass;
	Course* pCourse;
	CourseEnrollment* pEnroll;
	Semester* pNext;
	extraStudent* pE;
};

struct SchoolYear {
	int begin_year;
	int end_year;
	Semester* pSemester;
	SchoolYear* pNext;
};


#endif // !_MY_S_


