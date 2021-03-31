#ifndef _MY_S_
#define _MY_S_
#include "Header.h"

struct UserAccount {
	long int id;
	string full_name;
	string user_name;
	string user_password;
	string user_class;
	int user_type; //1 = GV, 2 = SV
	UserAccount* pNext;
};

struct StudentCourse {
	string course_id;
	string course_name;
};

struct StudentInCourse {
	string full_name;
	string id;
	char gender;
	int dob, mob, yob;
	string mainclass;
};

struct Student {
	string full_name;
	string id;
	char gender; //M , F
	int dob, mob, yob; //ngay thang nam sinh
	string social_id; //cmnnd
	string mainclass;
	StudentCourse* pStuCourse;

};

struct Course {
	string course_id;
	string course_class;
	string course_name;
	string course_mainteacher; //gvlt
	string course_teacher; //gvth
	int num_of_credit;
	int max_student;
	int num_of_student;
	//THOIKHOABIEU ???
	StudentInCourse* pStuInCourse;
};

struct CourseEnrollment {
	int start_date, start_month;
	int end_date, end_month;
	Course* pCourse;
};

struct Class {
	string class_code;
	string class_name;
	string class_teacher; //gvcn
	int num_of_student;
	Student* pStudent;
	CourseEnrollment* pEnroll;
};

struct Semester {
	int no;
	int begin_date, begin_month;
	int end_date, end_month;
	Class* pClass;
	Course* pCourse;
};


struct SchoolYear {
	int begin_year;
	int end_year;
	Semester* pSemester;
};


#endif // !_MY_S_


