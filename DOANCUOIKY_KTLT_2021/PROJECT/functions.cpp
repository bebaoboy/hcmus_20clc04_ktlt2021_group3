#include "Header.h"

//trong ham: nhap 0 quay lai, trong switch: nhap -1 quay lai

//for teacher only
void getPassword(string& a) {
	char c = '0';

	while (c != '\r')
	{
		c = _getch();
		if (c == '\b')
		{
			if (a.length() > 0)
			{
				a.erase(a.length() - 1, 1);
				cout << "\b \b";
			}
		}
		else if (c != '\r')
		{
			cout << "*";
			a.push_back(c);
		}
	}
}
void changeUserPassword(string& user_password) {
	system("cls");
	string temp_password1, temp_password2, old_password;
	cin.ignore();
	cout << "=====================================\n\n"
		<< "\tNhap password cu: ";
	getline(cin, old_password);
	while (old_password != user_password) {
		cout << "\tSai mat khau cu. Vui long nhap lai: ";
		getline(cin, old_password);
	}
	system("cls");

	cout << "=====================================\n\n"
		<< "\tNhap password moi: ";
	getline(cin, temp_password1);
	cout << "\tNhap lai password moi: ";
	getline(cin, temp_password2);

	while (temp_password1 != temp_password2) {
		cout << "\tPassword moi khong trung khop. Vui long nhap lai: ";
		getline(cin, temp_password2);
	}
	user_password = temp_password2;
	system("cls");

	cout << "==================================\n\n"
		<< "\tDoi mat khau thanh cong!\n\tBam -1 de quay lai!\n"
		<< "===================================\n";
	cin.get();
	return;
}
bool checkUserName(UserAccount* pUser, string user_name) {
	int count = 0;
	while (pUser != nullptr) {
		if (pUser->user_name == user_name)
			count++;
		else
			pUser = pUser->pNext;
		if (count == 2)
			return 0;
	}
	return 1;
}
void showUserAccount(UserAccount* pUser, string user_name) {
	//system("cls");
	UserAccount* pB = pUser;
	
	int opt = 10, o = 10, i = 1;
	while (pUser != nullptr) {
		if (pUser->user_name == user_name) break;
		else {
			pUser = pUser->pNext;
		}
	}
	Class* pTemp2 = pUser->pClass;
	while (opt != 0) {
		system("cls");
		cout << "=============================\n\n"
			<< "\tUsername: " << pUser->user_name
			<< "\n\tFullname: " << pUser->full_name
			<< "\n\tLop chu nhiem: " << pUser->user_class
			<< "\n\tPassword: Nhap 1 de xem\n\tNhap 2 de doi password."
			<< "\n\tNhap 3 de thay doi thong tin!";
		if (pUser->user_class != "Giao vien bo mon")
			cout << "\n\tNhap 4 de xem thong tin lop chu nhiem.";
		cout << "\n\tNhap 0 de quay lai.";
		cin.ignore();
		cin >> opt;
		system("cls");
		switch (opt) {
		case 2:
			changeUserPassword(pUser->user_password);
			break;
		case 3:
			editUserAccount(pB, pUser->user_name);
			break;
		case 1:
			//system("cls");
			cout << "================================\n\n"
				<< "\tPassword: " << pUser->user_password
				<< endl;
			cout << "\tNhap -1 de tiep tuc.";
			cin >> opt;
			break;
		case 4:
			if (pTemp2 == nullptr) {
				cout << "\n\n\tChua co du lieu. Nhap -1 de quay lai.";
				cin >> opt;
			}
			else
			while (o != 0) {
				cout << "=====================================\n\n"
					<< "\tLop: " << pTemp2->class_name << endl
					<< "\tGVCN: " << pTemp2->class_teacher << endl
					<< "\tSo luong hoc sinh: " << pTemp2->num_of_student << endl
					<< "\n\tNhap 1 de xem danh sach hoc sinh: "
					<< "\n\tNhap 2 de chinh sua thong tin"
					<< "\n\tNhap 3 de xem GPA cua lop"
					<< "\n\tNhap 0 de quay lai.";
				cin >> o;
				system("cls");
				switch (o) {
				case 0:
					break;
				case 1:
					if (pTemp2->pStudent == nullptr) {
						cout << "\n\n\tChua co hoc sinh nao. Bam -1 de quay lai.";
						cin >> o;
					}
					else
						showStudentList(pTemp2->pStudent, pTemp2->num_of_student);
					break;
				case 2:
					editClass(pTemp2);
					break;
				case 3:
					//xem gpa tung nguoi va overall (list)
					break;
				default:
					cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
					cin >> o;
					break;
				}
			}
			break;
		case 0:
			return;
		default:
			cout << "\tNhap sai cu phap.";
			break;
		}
		//system("cls");
	}
}
void editUserAccount(UserAccount* pUser, string user_name) {
	system("cls");
	cin.ignore();

	UserAccount* pB = pUser;
	int opt = 10;
	while (pUser != nullptr) {
		if (pUser->user_name == user_name) break;
		else {
			pUser = pUser->pNext;
		}
	}

	while (opt != -1) {
		cout << "==================================\n\n"
			<< "\tNhap 1 de doi username\n"
			<< "\tNhap 2 de doi fullname\n"
			<< "\tNhap 3 de doi lop chu nhiem\n"
			<< "\tNhap -1 de quay lai.";
		
		string temp;
		cin >> opt;
		system("cls");
		cin.ignore();
		switch (opt) {
		case 1:
			cout << "=================================\n\n"
				<< "\tNhap username moi(Nhap 0 de quay lai): ";
			getline(cin, temp);
			if (temp != "0") {
				while (!checkUserName(pB, temp)) {
					cout << "\n\tTen da duoc su dung boi tai khoan khac. Vui long nhap lai:";
					getline(cin, temp);
				}
				pUser->user_name = temp;
				cout << "\tDoi username thanh cong!\n";
			}
			break;
		case 2:
			cout << "=================================\n\n"
				<< "\tNhap fullname moi(Nhap 0 de quay lai): ";
			getline(cin, temp);
			if (temp != "0") {
				pUser->full_name = temp;
				cout << "\tDoi fullname thanh cong!\n";
			}
			break;
		case 3:
			cout << "=================================\n\n"
				<< "\tNhap lop chu nhiem moi(Nhap 0 de quay lai): ";
			getline(cin, temp);
			if (temp != "0") {
				pUser->user_class = temp;
				cout << "\tDoi lop thanh cong!\n";
			}
			break;

		case -1:
			return;
		default:
			cout << "\tNhap sai cu phap.";
			break;

		}
		cout << "\tNhap -1 de tiep tuc.";
		cin >> opt;
		system("cls");
	}
	
}
void showTime() {
	struct tm ltm;
	time_t now = time(0);
	localtime_s(&ltm, &now);
	cout << "\tCurrent time: ";
	if (ltm.tm_hour < 10)
		cout << "0" << ltm.tm_hour << ":";
	else
		cout << ltm.tm_hour << ":";
	if (ltm.tm_min < 10)
		cout << "0" << ltm.tm_min << ":";
	else
		cout << ltm.tm_min << ":";
	if (ltm.tm_sec < 10)
		cout << "0" << ltm.tm_sec;
	else
		cout << ltm.tm_sec;
	cout << endl;
}
void teacherClass(UserAccount* pUser, Class* pClass) {
	UserAccount* p = pUser;
	while (p != nullptr) {
		if (p->user_class == "Giao vien bo mon")
		{
		}
		else {
			Class* pC = pClass;
			while (pC != nullptr) {
				if (pC->class_name == p->user_class) {
					pC->pU = p;
					p->pClass = pC;
				}
				else 
					p->pClass = nullptr;
				pC = pC->pNext;
			}
		}
		p = p->pNext;
	}
}

//ham tao
void createSchoolYear(SchoolYear*& pSchoolYear) {
	int year = 0;
	string n = "";
	SchoolYear* p = pSchoolYear;
	if (p == nullptr) {
		p = new SchoolYear;
		pSchoolYear = p;
	}	
	else {
		while (pSchoolYear->pNext != nullptr)
			pSchoolYear = pSchoolYear->pNext;
		pSchoolYear->pNext = new SchoolYear;
		pSchoolYear = pSchoolYear->pNext;
	}
	pSchoolYear->pSemester = nullptr;
	system("cls");

	cout << "====================================\n\n"
		<< "\tNhap 0 de quay lai.\n"
		<< "\tNhap nam bat dau (YYYY): ";
	cin >> n;
	if (n == "0") {
		if (p == pSchoolYear) {
			delete p;
			p = nullptr;
		}
		else {
			SchoolYear* pT = p;
			while (pT->pNext != pSchoolYear)
				pT = pT->pNext;
			delete pSchoolYear;
			pT->pNext = nullptr;
		}
			
		return;
	}
	year = stoi(n);
	while (year <= 0 || year > 9999) {
		cout << "\tVui long nhap lai nam: ";
		cin >> year;
	}
	pSchoolYear->begin_year = year;
	pSchoolYear->end_year = year + 1;

	cout << "====================================\n\n"
		<< "\tTao nam hoc thanh cong!\n"
		<< "\tNam hoc: " << pSchoolYear->begin_year << " - " << pSchoolYear->end_year << endl
		<< "\t\tNhap 1 de tiep tuc den tao hoc ky cho nam hoc nay!";

	cin >> year;
	createSemester(pSchoolYear->pSemester, pSchoolYear->begin_year);
}
void createSemester(Semester*& pSemester, int year) {
	Semester* pBeginning = pSemester;
	int i = 1;
	for (i = 1; i <= 3; i++) {
		system("cls");
		if (i > 2) {
			cout << "\n\tNhap tiep hoc ky 3 (3 = yes, -1 = no): ";
			cin >> i;
			if (i == -1) break;
		}
		if (pSemester == nullptr) {
			pSemester = new Semester;
			pBeginning = pSemester;
		}	
		else {
			pSemester->pNext = new Semester;
			pSemester = pSemester->pNext;
		}

		string n = "";
		pSemester->no = i;
		//cin.ignore();
		cout << "===================================\n\n"
			<< "\tHoc ky " << i << endl
			<< "\tNhap ngay bat dau (DD/MM/YYYY): ";
		getline(cin, n, '/');
		pSemester->begin_date = stoi(n);
		getline(cin, n, '/');
		pSemester->begin_month = stoi(n);
		getline(cin, n, '\n');
		pSemester->begin_year = stoi(n);
		checkDate(pSemester->begin_date, pSemester->begin_month, pSemester->begin_year, year);

		cout << "\tNhap ngay ket thuc (DD/MM/YYYY): ";
		getline(cin, n, '/');
		pSemester->end_date = stoi(n);
		getline(cin, n, '/');
		pSemester->end_month = stoi(n);
		getline(cin, n, '\n');
		pSemester->end_year = stoi(n);
		checkDate(pSemester->end_date, pSemester->end_month, pSemester->end_year, year);
		pSemester->pNext = nullptr;
		pSemester->pClass = nullptr;
		pSemester->pCourse = nullptr;
		pSemester->pEnroll = nullptr;
	}
	
	pSemester = pBeginning;
	cout << "=================================\n\n"
		<< "\tNhap hoc ky thanh cong!\n\tBam -1 de quay lai!";
	cin >> i;

}
void createClass(Class*& pClass, extraStudent *pExtra) {
	system("cls");
	int o = 10;
	Class* pB = pClass;
	if (pClass == nullptr) {
		pClass = new Class;
		pB = pClass;
	}
	else {
		while (pB->pNext != nullptr)
			pB = pB->pNext;
		pB->pNext = new Class;
		pB = pB->pNext;
	}
	while (o != 0) {
		string n = "";
		cout << "====================================\n\n"
			<< "\tNhap 0 de quay lai!.\n";
		cout << "\tNhap ten lop hoc: ";
		cin.ignore();
		getline(cin, n);
		if (n == "0") {
			if (pClass == pB) {
				delete pClass;
				pClass = nullptr;
			}
			else {
				Class* pT = pClass;
				while (pT->pNext != pB)
					pT = pT->pNext;
				delete pB;
				pT->pNext = nullptr;
			}
				
			return;
		}
		pB->class_name = n;
		cout << "\tNhap ten giao vien chu nhiem: ";
		getline(cin, pB->class_teacher);

		pB->pNext = nullptr;
		pB->pStudent = nullptr;
		showExtraStudent(pExtra, pB);
		cout << "\n\tNhap lop hoc thanh cong. Nhan 0 de quay lai!\n";
		cin >> o;
		system("cls");
	}

}
void createCourse(Course*& pCourse) {
	system("cls");
	int o = 10;
	Course* pB = pCourse;
	if (pCourse == nullptr) {
		pCourse = new Course;
		pB = pCourse;
	}	
	else {
		while (pB->pNext != nullptr)
			pB = pB->pNext;
		pB->pNext = new Course;
		pB= pB->pNext;
	}

	while (o != 0) {
		string n = "";
		cout << "====================================\n\n"
			<< "\tNhap 0 de quay lai!.\n";
		cout << "\tNhap ten hoc phan: ";
		cin.ignore();
		getline(cin, n);
		if (n == "0") {
			if (pCourse == pB) {
				delete pCourse;
				pCourse = nullptr;
			}
			else {
				Course* pT = pCourse;
				while (pT->pNext != pB)
					pT = pT->pNext;
				delete pB;
				pT->pNext = nullptr;
			}
				
			return;
		}
		pB->course_name = n;
		cout << "\tNhap ma hoc phan: ";
		cin >> pB->course_id;
		cin.ignore();
		cout << "\tNhap ten giao vien ly thuyet: ";
		getline(cin, pB->course_mainteacher);
		cout << "\tNhap ten giao vien thuc hanh: ";
		getline(cin, pB->course_teacher);
		cout << "\tNhap so tin chi: ";
		cin >> pB->num_of_credit;
		cout << "\n\tNhap thoi gian hoc: Ngay trong tuan + Tiet hoc \n\n"
			<< "\tNgay trong tuan: 2 -> 7 cho thu 2 -> thu 7\n"
			<< "\tTiet hoc: S1 = 7h30, S2 = 9h30, S3 = 13h30, S4 = 15h30\n\n";
		cout << "\tVi du: Thu 2 (tiet 1) thi nhap vao: 2 1\n\tNhap tung tiet hoc mot!\n";
		cout << "\tNhap -1 de dung lai!\n";
		
		createTimeTable(pB->pTime);

		int a = 0, b = 0;
		while (a != -1) {
			cout << "\tThoi gian hoc: ";
			cin >> a;
			if (a == -1) break;
			cin >> b;
			inputTimeTable(pB->pTime, a, b);
		}

		pB->pNext = nullptr;
		pB->pStuInCourse = nullptr;
		cout << "\tNhap khoa hoc thanh cong. Nhan 0 de quay lai!\n";
		cin >> o;
		system("cls");
	}
	
}
void createStudent(Student*& pS, int& num) {
	system("cls");
	Student* pSS = pS;
	if (pSS == nullptr) {
		pSS = new Student;
		pS = pSS;
	}	
	else {
		while (pS->pNext != nullptr)
			pS = pS->pNext;
		pS->pNext = new Student;
		pS = pS->pNext;
	}
	int opt = 10;
	string n = "";
	int l = 0, m = 0, p = 0;
	cout << "===================================\n\n"
		<< "\tNhap 0 de quay lai.\n"
		<< "\tNhap Fullname: ";
	cin.ignore();
	getline(cin, n, '\n');
	if (n == "0") {
		if (pSS == pS) {
			delete pSS;
			pSS = nullptr;
		}
		else {
			Student* pT = pSS;
			while (pT->pNext != pS)
				pT = pT->pNext;
			delete pS;
			pT->pNext = nullptr;
		}
			
		return;
	}
	num++;
	pS->full_name = n;
	cout << "\tNhap MSSV: ";
	cin >> pS->id;
	cout << "\tNhap gioi tinh (nam = M, nu = F): ";
	cin >> pS->gender;
	cin.ignore();
	cout << "\tNhap ngay sinh: dd/mm/yyyy: ";
	getline(cin, pS->dob, '/');
	getline(cin, pS->mob, '/');
	getline(cin, pS->yob, '\n');


	l = stoi(pS->dob);
	m = stoi(pS->mob);
	p = stoi(pS->yob);
	checkDate(l,m, p, p);
	pS->dob = to_string(l);
	pS->mob = to_string(m);
	pS->yob = to_string(p);

	pS->user_name = pS->id;
	pS->user_password = "";
	pS->user_password = pS->user_password + pS->dob + pS->mob + pS->yob;
	pS->pStuCourse = nullptr;
	pS->pNext = nullptr;
	createTimeTable(pS->pTable);
	cout << "\tNhap hoc sinh thanh cong. Nhap 0 de quay lai!\n";
	cin >> n;
	system("cls");
}
void createTimeTable(Time* &p) {
	//create student
	//input class
	p = new Time[6];
	p[0].day = "Mon";
	p[1].day = "Tue";
	p[2].day = "Wed";
	p[3].day = "Thu";
	p[4].day = "Fri";
	p[5].day = "Sat";
	for (int i = 0; i <= 5; i++) {
		p[i].session = new string[4];
		for (int j = 0; j < 4; j++) {
			p[i].session[j] = "0";
		}
	}
}

//ham xem
void showStudent(Student* &pStudent) {
	int o = 10;
	while (o != 0) {
		system("cls");
		if (pStudent == nullptr) {
			cout << "\n\n\tKhong co hoc sinh nay!\n\tNhap 0 de quay lai.";
			cin >> o;
			break;
		}
		cout << "=====================================\n\n"
			<< "\tUsername: " << pStudent->user_name
			<< "\n\tPassword: Bam 1 de xem"
			<< "\n\tFull name: " << pStudent->full_name
			<< "\n\tMSSV: " << pStudent->id
			<< "\n\tGioi tinh: " << ((pStudent->gender == 'M') ? "Nam" : "Nu")
			<< "\n\tNgay sinh: " << pStudent->dob << "/" << pStudent->mob << "/" << pStudent->yob
			//<< "\n\tSocial ID: " 
			<< "\n\tGPA: " << pStudent->GPA
			<< "\n\tLop chu nhiem: " << pStudent->mainclass << endl;
		cout << "\tNhap 2 de xem danh sach hoc phan da dang ky." << endl;
		cout << "\tNhap 3 de xem thoi khoa bieu" << endl;
		cout << "\tNhap 4 de xem bang diem hoc ky" << endl;
		cout << "\tNhap 5 de chinh sua thong tin" << endl;
		cout << "\tNhap 0 de quay lai!";
		cin >> o;
		system("cls");
		switch (o) {
		case 1:
			cout << "==================================\n\n"
				<< "\tMat khau la: " << pStudent->user_password << endl;
			cout << "\tNhap -1 de quay lai: ";
			cin >> o;
			system("cls");
			break;
		case 5:
			editStudent(pStudent);
			break;
		case 0:
			break;
		case 2:
			showStudentCourse(pStudent->pStuCourse, pStudent);
			system("cls");
			break;
		case 3:
			cout << endl;
			showTimeTable(pStudent->pTable);
			cout << "\n\tNhap -1 de quay lai.";
			cin >> o;
			system("cls");
			break;
		case 4:
			printStudentScoreboard(pStudent);
			break;
		default:
			cout << "\tNhap sai cu phap\nNhap -1 de tiep tuc.";
			cin >> o;
			break;
		}
	}
	
}
void showStudentList(Student* pStudent, int &num) {
	//nhap 0
	Student* pB = pStudent;
	int o = -1;
	while (o != 0) {
		system("cls");
		int i = 1;
		cout << "====================================\n\n"
			<< "\tDanh sach hoc sinh (Bam so de xem): \n";
		
		if (pStudent == nullptr) {
			cout << "\tKhong co hoc sinh nao. Nhan 0 de quay lai.";
			cin >> o;
			break;
		}

		pStudent = pB;
		while (pStudent->pNext != nullptr) {
			cout << "\t" << i << ". " << pStudent->full_name << endl;
			pStudent = pStudent->pNext;
			i++;
		}
		cout << "\t" << i << ". " << pStudent->full_name << endl;
		cout << "\tNhap -1 + so thu tu de xoa hoc sinh.\n";
		cout << "\tNhap -2 de them hoc sinh.\n"
			<< "\tNhap 0 de quay lai.";
		cin >> o;
		int  t = 0;
		pStudent = pB;
		Student* pTemp2 = pB;
		system("cls");

		if (o == 0) break;
		else if (o == -2) {
			//tao sv
			createStudent(pStudent, num);
			if (pStudent!=nullptr)
				pStudent->mainclass = pB->mainclass;
		}
		else if (o == -1) {
			//xoa sv
			cin >> t;
			for (int i = t - 2; i > 0; i--) {
				pStudent = pStudent->pNext;
			}

			for (int i = t - 1; i > 0; i--) {
				pTemp2 = pTemp2->pNext;
			}
			pStudent->pNext = pTemp2->pNext;
			if (pTemp2 == pStudent)
				pB = pB->pNext;
			deleteStudent(pTemp2);
			num--;
		}
		else
		{	pStudent = pB;
		if (o > i||o<-2) {
			cout << "\tSo khong hop le, nhap -1 de quay lai: ";
			cin >> o;
			break;
		}
		else {
			for (int j = 1; j < o; j++) {
				pStudent = pStudent->pNext;
			}
			showStudent(pStudent);
		}	
		}

	}
}
void showCourse(Course* &pCourse) {
	int o = 10;
	StudentInCourse* p = nullptr;
	while (o != 0) {
		system("cls");
		cout << "================================\n\n";
		cout << "\tTen khoa hoc: " << pCourse->course_name << endl
			<< "\tMa hoc phan: " << pCourse->course_id << endl
			<< "\tTen GVLT: " << pCourse->course_mainteacher << endl
			<< "\tTen GVTH: " << pCourse->course_teacher << endl
			<< "\tSo tin chi: " << pCourse->num_of_credit << endl
			<< "\tSo hoc sinh toi da: " << pCourse->max_student << endl
			<< "\tSo hoc sinh da dang ky: " << pCourse->num_of_student << endl;
		//xem thoi gian hoc
		Time* pT = pCourse->pTime;
		showTimeTable(pT);
		cout << "\n\tNhap 1 de chinh sua khoa hoc";
		cout << "\n\tNhap 2 de xem danh sach sv dang ky khoa hoc.";
		cout << "\n\tNhap 0 de quay lai.";
		cin >> o;
		if (o == 0) {
			break;
		}
		else if (o==1)
		{
			editCourse(pCourse);
		}
		else if (o==2) {
			courseClass(pCourse->pStuInCourse);
			showStudentInCourse(pCourse->pStuInCourse,pCourse);
		}
		else {
			cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
			cin >> o;
		}
	}
}
void showCourseClass(Course* pCourse) {

}
void showCourseList(Course* &pCourse) {
	int o = 10;	
	Course* pB = pCourse;
	while (o != 0) {
		pCourse = pB;
		system("cls");
		cout << "=================================================\n\n"
			<< "\tDanh sach khoa hoc\n\t(Bam so tuong ung de truy cap): \n";
		int i = 0;
		while (pCourse != nullptr) {
			cout << "\t";
			cout << i+1 << ". " << pCourse->course_name << endl;
			pCourse = pCourse->pNext;
			i++;
		}
		pCourse = pB;
		Course* pTmp = pB;
		cout << "\n\tBam 0 de quay lai\n"
			<< "\tBam -1 + so thu tu de xoa khoa hoc\n"
			<< "\tBam -2 de them khoa hoc\n\t";
		cin >> o;
		int t = 0;
		switch (o) {
		case 0:
			return;
		case -2:
			//them khoa hoc
			createCourse(pCourse);
			break;
		case -1:
			//xoa khoa hoc
			cin >> t;
			for (int i = t-1; i > 0; i--) {
				pTmp = pTmp->pNext;
			}
			for (int i = t-2; i > 0; i--) {
				pCourse = pCourse->pNext;
			}
			pCourse->pNext = pTmp->pNext;
			if (pCourse == pTmp)
				pB = pB->pNext;
			deleteCourse(pTmp);
			break;
		default:
			if (o > i||o<-2) {
				cout << "\tSo khong hop le, nhap -1 de quay lai: ";
				cin >> o;
			}
			else {
				for (int j = 1; j < o; j++) {
					pTmp = pTmp->pNext;
				}
				showCourse(pTmp);
			}
			break;
		}
	}
}
void showClass(Class* &pClass, Semester* &pSemester) {
	int opt = 100;
	Student* ps = nullptr;
	string name = "", id = "";
	while (opt != 0) {
		system("cls");
		int i = 0, t = -10;
		Class* pB = pClass;

		cout << "====================================\n\n"
			<< "\tDanh sach lop chu nhiem:\n\t(Bam so tuong ung de truy cap) \n";
		while (pB != nullptr) {
			cout << "\t" << i+1 << ". ";
			cout << pB->class_name << endl;
			i++;
			pB = pB->pNext;
		}
		pB = pClass;
		cout << "\n\tNhap -1 + so thu tu lop hoc de xoa lop hoc\n"
			<< "\tNhap -2 de tao lop hoc\n"
			<< "\tNhap -3 de TRA CUU hoc sinh.\n\t"			
			<< "\tNhap 0 de quay lai.\n\t";
		cin >> opt;
	system("cls");
	Class* pTemp2 = pClass;
		switch (opt) {
		case 0:
			break;
		case -1:
			//ham xoa
			cin >> t;
			if (t > i) {
				cout << "\n\tNhap sai cu phap. Nhap -1 de quay lai.";
				cin >> opt;
				break;
			}
			for (int i = t-1; i > 0; i --) {
				pB = pB->pNext;
			}

			for (int i = t-2; i > 0; i --) {
				pTemp2 = pTemp2->pNext;
			}
			pTemp2->pNext = pB->pNext;
			if (pTemp2 == pB)
				pClass = pClass->pNext;
			deleteClass(pB);
			break;
		case -2:
			//ham tao -> unpractical
			createClass(pB, pSemester->pE);
			break;
		case -3:
			cin.ignore();
			system("cls");
			cout << "\n\n\tTRA CUU SINH VIEN"
				<< "\n\tNhap 0 de quay lai.";
			cout << "\n\tNhap ten sinh vien: ";
			getline(cin, name);
			if (name == "0") break;
			cout << "\tNhap mssv: ";
			cin >> id;
			ps = searchStudent(name, id, pClass, pSemester);
			if (ps!=nullptr)
				showStudent(ps);
			break;
		default:
			if (opt > i||opt<-2) {
				cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
				cin >> opt;
			}
			else {
				//ham xem lop
				int o = 10;
				for (int j = 1; j < opt; j++) {
					pTemp2 = pTemp2->pNext;
				}
				while (o != 0) {
					cout << "=====================================\n\n"
						<< "\tLop: " << pTemp2->class_name << endl
						<< "\tGVCN: " << pTemp2->class_teacher << endl
						<< "\tSo luong hoc sinh: " << pTemp2->num_of_student << endl
						<< "\n\tNhap 1 de xem danh sach hoc sinh: "
						<< "\n\tNhap 2 de chinh sua thong tin"
						<< "\n\tNhap 3 de xem GPA cua lop"
						<< "\n\tNhap 0 de quay lai.";
					cin >> o;
					system("cls");
					switch (o) {
					case 0:
						break;
					case 1:
						if (pTemp2->pStudent == nullptr) {
							cout << "\n\n\tChua co hoc sinh nao. Bam -1 de quay lai.";
							cin >> o;
						}
						else
						showStudentList(pTemp2->pStudent, pTemp2->num_of_student);
						break;
					case 2:
						editClass(pTemp2);
						break;
					case 3:
						//xem gpa tung nguoi va overall (list)
						break;
					default:
						cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
						cin >> o;
						break;
					}
				}
			}
			break;
		}
	}
}
void showMainClass(Class* pClass) {
	//cua hoc sinh
	int o1 = 10;
	Student* pStudent = pClass->pStudent;
	while (o1 != 0) {
		system("cls");
		cout << "=====================================\n\n"
			<< "\tLop: " << pClass->class_name << endl
			<< "\tGVCN: " << pClass->class_teacher << endl
			<< "\tSo luong hoc sinh: " << pClass->num_of_student << endl
			<< "\n\tNhap 1 de xem danh sach hoc sinh: "
			<< "\n\tNhap 0 de quay lai.";
		cin >> o1;
		int o = -1;
		system("cls");
		switch (o1) {
		case 0:
			break;
		case 1:
			//system("cls");
			while (o != 0) {
				int i = 1;
				cout << "====================================\n\n"
					<< "\tDanh sach hoc sinh: \n";
				while (pStudent != nullptr) {
					cout << "\t" << i << ". " << pStudent->full_name << endl;
					pStudent = pStudent->pNext;
					i++;
				}
				cout << "\tNhap 0 de quay lai.";
				cin >> o;
				system("cls");
				if (o == 0) break;
			}
			break;
		default:
			cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
			cin >> o1;
			break;
		}
	}
}
void showSemesterTime(Semester* pSemester, int year) {
	//chay list ngpai main
	//goi ham show class	
	int op = 10;
	while (op != 0) {
		system("cls");
		cout << "===================================" << endl;
		cout << "\tHoc ki " << pSemester->no << ": " << endl;
		cout << "\tThoi gian bat dau : " << pSemester->begin_date << "/" << pSemester->begin_month << "/" << pSemester->begin_year << endl;
		cout << "\tThoi gian ket thuc: " << pSemester->end_date << "/" << pSemester->end_month << "/" << pSemester->end_year << endl;
		cout << "\n\tNhap 1 de chinh sua thoi gian. " << endl;
		cout << "\tNhap 0 de quay lai." << endl;
		cin >> op;
		switch (op) {
		case 0:
			// back
			break;
		case 1:
			editSemester(pSemester, year);
			break;
		default:
			cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
			cin >> op;
			break;
		}
	}
}
void showSchoolYear(SchoolYear* pSchoolYear) {
	int opt = 10;
	Semester* p = pSchoolYear->pSemester;
	while (opt != 0) {
		system("cls");
		cout << "===================================\n\n"
			<< "\tNam hoc: ";
		cout << pSchoolYear->begin_year << " / " << pSchoolYear->end_year << endl;
		cout << "\tThoi gian bat dau: " << pSchoolYear->pSemester->begin_date << "/" << pSchoolYear->pSemester->begin_month << "/" << pSchoolYear->pSemester->begin_year << endl;
		
		while (pSchoolYear->pSemester->pNext != nullptr) {
			pSchoolYear->pSemester = pSchoolYear->pSemester->pNext;
		}
		cout << "\tThoi gian bat dau: " << pSchoolYear->pSemester->end_date << "/" << pSchoolYear->pSemester->end_month << "/" << pSchoolYear->pSemester->end_year << endl;
		cout << "\n\tNhap 1 de chinh sua nam hoc.\n";
		cout << "\tNhap 0 de quay lai.";
		cin >> opt;
		switch (opt) {
		case 0:
			break;
		case 1:
			pSchoolYear->pSemester = p;
			editSchoolYear(pSchoolYear);
			break;
		default:
			cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
			cin >> opt;
			break;
		}
	}
	pSchoolYear->pSemester = p;
}
void showTimeTable(Time* pT) {
	cout << "\tThoi gian hoc: \n";
	cout << "\tS1 = 7h30, S2 = 9h30, S3 = 13h30, S4 = 15h30\n";
	cout << "\t\tS1\tS2\tS3\tS4\n";
	for (int i = 0; i < 6; i++) {
		cout << "\t" << pT[i].day << ":\t";
		for (int j = 0; j < 4; j++) {
			cout << pT[i].session[j] << "\t";
		}
		cout << endl;
	}
}
Student* searchStudent(string full_name, string id, Class* &pClass, Semester*& pSemester) {
	Class* pCurClass = pClass;
	Student* pTemp = nullptr;
	int _ = 0;
	system("cls");
	cout << "\n\n\tDang tim kiem . . . \n\n";
	Sleep(1000);
	while (pCurClass != nullptr) {
		pTemp = pCurClass->pStudent;
		while (pTemp != nullptr) {
			if (pTemp->full_name == full_name && pTemp->id == id) {
				cout << "\tDa tim thay!\n\n\tBam -1 de xem hoc sinh.\n\tBam 0 de dang ky hoc phan cho sv.\n\t";
				cin >> _;
				if (_ == -1)
					return pTemp;
				else if (_ == 0) {
					Enroll(pSemester->pEnroll, pTemp, pSemester->pCourse);
					return nullptr;
				}
				else {
					while (_ != 0 && _ != -1) {
						cout << "\tSai cu phap. Nhap lai: ";
						cin >> _;
						if (_ == -1)
							return pTemp;
						else
							return nullptr;
					}
				}
			}	
			else
				pTemp = pTemp->pNext;
		}
		if (pTemp == nullptr) {
			pCurClass = pCurClass->pNext;
		}
		else
			break;
	}
	if (pCurClass == nullptr) {
		cout << "==================================\n\n"
			<< "\tKhong tim thay sinh vien!\n\tBam -1 de quay lai";
		cin >> _;
		return nullptr;
	}
}
void showExtraStudent(extraStudent* pExtra, Class* pClass) {
	extraStudent* pB = pExtra;
	int o = -1, t = 0, j = 1;
	while (o != 0) {
		Student* pS = pClass->pStudent;
		system("cls");
		int i = 0;
		cout << "====================================\n\n"
			<< "\tDanh sach hoc sinh: \n";

		pExtra = pB;
		while (pExtra != nullptr) {
			if (pExtra->active == 1) {
				cout << "\t" << i + 1 << ". " << pExtra->full_name << endl;
				i++;
			}
			pExtra = pExtra->pNext;
		}

		pExtra = pB;
		cout << "\n\tNhap -1 + so thu tu de them hoc sinh vao lop.\n"
			<< "\tNhap 0 de quay lai.";
		cin >> o;
		switch (o) {
		case 0: 
			return;
		default: 
			cin >> t;
			if (t > i+1 || t < -1) {
				cout << "\tNhap sai cu phap. Nhap -1 de quay lai.";
				cin >> o;
			}
			else {
				if (pClass->pStudent == nullptr) {
					pClass->pStudent = new Student;
					pS = pClass->pStudent;
				}
				else {
					while (pS->pNext != nullptr)
						pS = pS->pNext;
					pS->pNext = new Student;
					pS = pS->pNext;
				}
				for (int i = 1; i < t; i++)
					pExtra = pExtra->pNext;

				pS->full_name = pExtra->full_name;
				pS->id = pExtra->id;
				pS->gender = pExtra->gender;
				pS->dob = pExtra->dob;
				pS->mob = pExtra->mob;
				pS->yob = pExtra->yob;
				pS->mainclass = pClass->class_name;
				pS->no = j;
				j++;
				createTimeTable(pS->pTable);
				pS->user_name = pS->id;
				
				pS->user_password = "";
				pS->user_password = pS->user_password + pS->dob + pS->mob + pS->yob;
				pS->pNext = nullptr;
				pS->pStuCourse = nullptr;
				pExtra->active = 0;
			}
			break;
		}
		system("cls");
	}
}

//ham edit
void editSchoolYear(SchoolYear*& pSchoolYear) {
	int opt = 10, year = 0;
	system("cls");

	while (opt != 0) {
		cout << "====================================\n\n"
			<< "\tNhap 0 de quay lai: " << endl
			<< "\t Nhap lai nam hoc (nien khoa - YYYY): ";

		cin >> year;
		if (year == 0) {
			opt = 0;
			break;
		}
		while (year <= 0 || year > 9999) {
			cout << "\tVui long nhap lai nam: ";
			cin >> year;
		}

		pSchoolYear->begin_year = year;
		pSchoolYear->end_year = year + 1;
		int m = pSchoolYear->pSemester->begin_year;
		int n = year - m;
		
		//if (n < 0) {
		//	int _ = 0;
		//	while (n < 0) {
		//		_++;
		//		n++;
		//	}
		//	//n = _;
		//}

		Semester* p = pSchoolYear->pSemester;
		while (p != nullptr) {
			if (p->begin_year == p->end_year) {
				p->begin_year = p->begin_year + n;
				p->end_year = p->end_year + n;
			}
			else {
				p->begin_year = p->begin_year + n;
				p->end_year = p->end_year + n + 1;
			}
			p = p->pNext;
		}


		system("cls");
		cout << "====================================\n\n"
			<< "\tChinh sua nam hoc thanh cong!\n"
			<< "\tNam hoc: " << pSchoolYear->begin_year << " - " << pSchoolYear->end_year << endl
			<< "\tNhap 0 de quay lai:" << endl;
		cin >> opt;
	}
}
void editSemester(Semester*& pSemester, int year) {
	//chinh sua hoc ky duoc chi den
	int option = 1;
	string n = "";
	while (option != 0) {
		system("cls");
		cout << "\n\tNhap 0 de quay lai" << endl;
		cout << "\tNam hoc: " << year << " - " << year + 1 << endl;
		switch (option) {
		case 0:
			break;
		case 1:
			cout << "====================================\n\n";
			cout << "\tNhap lai ngay bat dau (dd/mm/yyyy) : ";
			getline(cin, n, '/');
			if (n == "0") {
				option = 0;
				break;
			}
			pSemester->begin_date = stoi(n);
			getline(cin, n, '/');
			pSemester->begin_month = stoi(n);
			getline(cin, n, '\n');
			pSemester->begin_year = stoi(n);
			checkDate(pSemester->begin_date, pSemester->begin_month, pSemester->begin_year, year);
			cout << endl;

			cout << "\tNhap lai ngay ket thuc (dd/mm/yyyy) : ";
			getline(cin, n, '/');
			pSemester->end_date = stoi(n);
			getline(cin, n, '/');
			pSemester->end_month = stoi(n);
			getline(cin, n, '\n');
			pSemester->end_year = stoi(n);
			checkDate(pSemester->end_date, pSemester->end_month, pSemester->end_year, year);

			cout << "\n\tChinh sua ngay thanh cong! Nhap 0 de quay lai." << endl;
			cin >> option;
			break;
		default:
			cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
			cin >> option;
			break;
		}
	}
}
void editClass(Class*& pClass) {
	int o = 10;
	while (o != 0) {
		cout << "=====================================\n\n"
			<< "\tLop: " << pClass->class_name << endl
			<< "\tGVCN: " << pClass->class_teacher << endl
			<< "\tSo luong hoc sinh: " << pClass->num_of_student << endl
			<< "\n\tNhap 1 de sua ten lop"
			<< "\n\tNhap 2 de sua ten GVCN"
			<< "\n\tNhap 0 de quay lai.";
		cin >> o;
		system("cls");
		switch (o) {
		case 0:
			break;
		case 1:
			cout << "===================================\n\n"
				<< "\tNhap ten lop moi: ";
			cin >> pClass->class_name;
			system("cls");
			cout << "===================================\n\n"
				<< "\tNhap ten lop thanh cong! Nhan -1 de quay lai.";
			cin >> o;
			break;
		case 2:
			cout << "===================================\n\n"
				<< "\tNhap ten GVCN moi: ";
			cin >> pClass->class_teacher;
			system("cls");
			cout << "===================================\n\n"
				<< "\tNhap ten GVCN thanh cong! Nhan -1 de quay lai.";
			cin >> o;
			break;
		default:
			cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
			cin >> o;
			break;
		}
	}
}
void editStudent(Student*& pStudent) {
	int opt = 10;
	while (opt != 0) {
		system("cls");
		cout << "\n\tFull name: " << pStudent->full_name
			<< "\n\tMSSV: " << pStudent->id
			<< "\n\tGioi tinh: " << ((pStudent->gender == 'M') ? "Nam" : "Nu")
			<< "\n\tNgay sinh: " << pStudent->dob << "/" << pStudent->mob << "/" << pStudent->yob << endl;
		cout << "\tNhap 1 de thay doi Full name\n"
			<< "\tNhap 2 de thay doi MSSV\n"
			<< "\tNhap 3 de thay doi gioi tinh\n"
			<< "\tNhap 4 de thay doi ngay sinh\n"
			<< "\tNhap 0 de quay lai.";
		//<< "\n\tSocial ID: " 
		cin >> opt;
		cin.ignore();
		system("cls");
		string n = " ";
		int l = 0, m = 0, p = 0;
		switch (opt) {
		case 0:
			break;
		case 1:
			cout << "==================================\n\n"
				<< "\tNhap Full name moi: ";
			getline(cin, pStudent->full_name);
			cout << "\tDoi ten thanh cong!. Nhap -1 de quay lai!";
			cin >> opt;
			break;
		case 2:
			cout << "==================================\n\n"
				<< "\tNhap MSSV moi: ";
			cin >> pStudent->id;
			cout << "\tDoi MSSV thanh cong!. Nhap -1 de quay lai!";
			cin >> opt;
			break;
		case 3:
			cout << "==================================\n\n"
				<< "\tNhap gioi tinh moi (nam = M, nu = F): ";
			cin >> pStudent->gender;
			cout << "\tDoi gioi tinh thanh cong!. Nhap -1 de quay lai!";
			cin >> opt;
			break;
		case 4:
			cout << "====================================\n\n"
				<< "\tNhap ngay sinh: dd/mm/yyyy: ";
			getline(cin, pStudent->dob, '/');
			getline(cin, pStudent->mob, '/');
			getline(cin, pStudent->yob, '\n');

			l = stoi(pStudent->dob);
			m = stoi(pStudent->mob);
			p = stoi(pStudent->yob);
			checkDate(l,m, p, p);
			pStudent->dob = to_string(l);
			pStudent->mob = to_string(m);
			pStudent->yob = to_string(p);

			cout << "\tDoi ngay sinh thanh cong!. Ngay sinh cua ban la: " << pStudent->dob << "/" << pStudent->mob << "/" << pStudent->yob << endl
				<< "\tNhap -1 de quay lai!";
			cin >> opt;
			break;
		default:
			cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
			cin >> opt;
			break;
		}
	}
	
}
void editCourse(Course*& pCourse) {
	int o = 10;
	//system("cls");
	while (o != 0) {
		system("cls");
		cout << "================================\n\n";
		cout << "\tTen khoa hoc: " << pCourse->course_name << endl
			<< "\tMa hoc phan: " << pCourse->course_id << endl
			<< "\tTen GVLT: " << pCourse->course_mainteacher << endl
			<< "\tTen GVTH: " << pCourse->course_teacher << endl
			<< "\tSo tin chi: " << pCourse->num_of_credit << endl
			<< "\tSo hoc sinh toi da: " << pCourse->max_student << endl
			<< "\tSo hoc sinh da dang ky: " << pCourse->num_of_student << endl;
		
		Time* pT = pCourse->pTime;
		showTimeTable(pT);

		cout << "\n\tNhap 1 de chinh ten khoa hoc\n"
			<< "\tNhap 2 de chinh ma hoc phan\n"
			<< "\tNhap 3 de chinh giao vien ly thuyet\n"
			<< "\tNhap 4 de chinh giao vien thuc hanh\n"
			<< "\tNhap 5 de chinh so tin chi\n"
			<< "\tNhap 6 de chinh so hoc sinh toi da\n"
			<< "\tNhap 7 de chinh thoi gian hoc\n";
		cout << "\n\tNhap 0 de quay lai.";
		cin >> o;
		int a = 0, b = 0;
		cin.ignore();
		system("cls");
		switch (o) {
		case 0:
			break;
		case 1:
			cout << "==================================\n\n"
				<< "\tNhap ten khoa hoc moi: ";
			getline(cin, pCourse->course_name);
			cout << "\tDoi ten khoa hoc thanh cong!. Nhap -1 de quay lai!";
			cin >> o;
			break;
		case 2:
			cout << "==================================\n\n"
				<< "\tNhap ma hoc phan moi: ";
			getline(cin, pCourse->course_id);
			cout << "\tDoi ma hoc phan thanh cong!. Nhap -1 de quay lai!";
			cin >> o;
			break;
		case 3:
			cout << "==================================\n\n"
				<< "\tNhap ten GV ly thuyet: ";
			getline(cin, pCourse->course_mainteacher);
			cout << "\tDoi ten GV ly thuyet thanh cong!. Nhap -1 de quay lai!";
			cin >> o;
			break;
		case 4:
			cout << "==================================\n\n"
				<< "\tNhap ten GV thuc hanh moi: ";
			getline(cin, pCourse->course_teacher);
			cout << "\tDoi ten GV thuc hanh thanh cong!. Nhap -1 de quay lai!";
			cin >> o;
			break;
		case 5:
			cout << "==================================\n\n"
				<< "\tNhap so tin chi moi: ";
			cin >> pCourse->num_of_credit;
			cout << "\tDoi so tin chi thanh cong!. Nhap -1 de quay lai!";
			cin >> o;
			break;
		case 6:
			cout << "==================================\n\n"
				<< "\tNhap so hoc sinh toi da: ";
			cin >> pCourse->max_student;
			cout << "\tDoi thanh cong!. Nhap -1 de quay lai!";
			cin >> o;
			break;
		case 7: {
			cout << "\n\tNhap so tuong ung de huy/chon them thoi gian hoc.\n\n";
			cout << "\n\tNgay trong tuan: 2 -> 7 cho thu 2 -> thu 7\n"
				<< "\tTiet hoc: S1 = 7h30, S2 = 9h30, S3 = 13h30, S4 = 15h30\n\n";
			cout << "\tVi du: Thu 2 (tiet 1) thi nhap vao: 2 1\n\tNhap tung tiet hoc mot!\n\n";
			cout << "\tNhap -1 de dung lai!\n";

			showTimeTable(pT);

			while (a != -1) {
				cout << "\tThoi gian hoc: ";
				cin >> a;
				if (a == -1) break;
				cin >> b;
				a -= 2;
				b -= 1;
				if (pT[a].session[b] == "0")
					pT[a].session[b] = "X";
				else
					pT[a].session[b] = "0";
			}	
			cout << "\n\n\tNhap thoi gian thanh cong!. Bam -1 de quay lai.";
			cin >> o;
			break;
		}
		default:
			cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
			cin >> o;
			break;
		}
	}
}

//ham input
void inputSchoolYear(SchoolYear*& pSchoolYear) {
	pSchoolYear = new SchoolYear;
	pSchoolYear->begin_year = 2020;
	pSchoolYear->end_year = 2021;
	pSchoolYear->pSemester = new Semester;
	Semester* p = pSchoolYear->pSemester;
	p->no = 1;
	p->begin_date = 1;
	p->begin_month = 9;
	p->begin_year = 2020;
	p->end_date = 1;
	p->end_month = 12;
	p->end_year = 2020;
	p->pEnroll = nullptr;
	p->pClass = nullptr;
	p->pCourse = nullptr;

	p->pNext = new Semester;
	p = p->pNext;
	p->no = 2;
	p->begin_date = 1;
	p->begin_month = 1;
	p->begin_year = 2021;
	p->end_date = 1;
	p->end_month = 4;
	p->end_year = 2021;
	p->pEnroll = nullptr;
	p->pClass = nullptr;
	p->pCourse = nullptr;

	p->pNext = new Semester;
	p = p->pNext;
	p->no = 3;
	p->begin_date = 1;
	p->begin_month = 5;
	p->begin_year = 2021;
	p->end_date = 1;
	p->end_month = 7;
	p->end_year = 2021;
	p->pEnroll = nullptr;
	p->pNext = nullptr;
	p->pClass = nullptr;
	p->pCourse = nullptr;
}
void inputClass(Class*& pClass, ifstream& input) {
	if (pClass == nullptr)
		pClass = new Class;
	else {
		pClass->pNext = new Class;
		pClass = pClass->pNext;
	}
	
	string n = " ";
	getline(input, pClass->class_name, '\n');
	getline(input, pClass->class_teacher, '\n');
	getline(input, n, '\n');
	pClass->num_of_student = stoi(n);

	pClass->pStudent = nullptr;		
	Student* pTemp = pClass->pStudent;
	
	while (!input.eof()) {
		if (pTemp == nullptr)
			pTemp = new Student;
		else {
			pTemp->pNext = new Student;
			pTemp = pTemp->pNext;
		}
		getline(input, n, ',');
		if (n == "") return;
		pTemp->no = stoi(n);
		getline(input, pTemp->id, ',');
		getline(input, pTemp->full_name, ',');
		getline(input, pTemp->dob, '/');
		getline(input, pTemp->mob, '/');
		getline(input, pTemp->yob, ',');
		getline(input, n, '\n');
		if (n == "Nam") pTemp->gender = 'M';
		else pTemp->gender = 'F';
		pTemp->user_name = pTemp->id;
		pTemp->user_password = "";
		pTemp->user_password = pTemp->user_password + pTemp->dob + pTemp->mob + pTemp->yob;
		//getline(input, n, ','); //cmnd
		pTemp->mainclass = pClass->class_name;
		pTemp->pNext = nullptr;
		pTemp->pStuCourse = nullptr;
		createTimeTable(pTemp->pTable);
		if (pClass->pStudent == nullptr) pClass->pStudent = pTemp;
	}
	pClass->pNext = nullptr;
}
void inputTeacher(UserAccount*& pUser, ifstream& input) {
	UserAccount* pB = pUser;
	while (!input.eof()) {
		if (pUser == nullptr) {
			pUser = new UserAccount;
			pB = pUser;
		}
		else {
			pUser->pNext = new UserAccount;
			pUser = pUser->pNext;
		}
		getline(input, pUser->full_name, '\n');
		input >> pUser->user_name;
		input >> pUser->user_password;
		input.ignore();
		getline(input, pUser->user_class, '\n');
		input.ignore(2, '\n');
		pUser->pNext = nullptr;
	}
	pUser = pB;
}
void inputCourse(Course*& pCourse, ifstream& input) {
	//int l = 1;
	Course* pB = pCourse;
	while (!input.eof()) {
		if (pCourse == nullptr) {
			pCourse = new Course;
			pB = pCourse;
		}
		else {
			pCourse->pNext = new Course;
			pCourse = pCourse->pNext;
		}
		createTimeTable(pCourse->pTime);

		string n = "";
		char _ = ' ';
		getline(input, pCourse->course_name, ',');
		getline(input, pCourse->course_id, ',');
		getline(input, n, ',');
		//pCourse->course_class = 0;
		pCourse->num_of_credit = stoi(n);
		pCourse->num_of_student = 0;
		getline(input, pCourse->course_mainteacher, ',');
		getline(input, pCourse->course_teacher, ',');
		
		int i = 0;
		
		for (int j = 1; j <= pCourse->num_of_credit; j++) {
			getline(input, n, '(');
			for (i = 0; i < 6; i++) {
				if (pCourse->pTime[i].day == n) {
					break;
				}
			}
			getline(input, n, ')');
			pCourse->pTime[i].session[stoi(n)-1] = "X";
			if (j < pCourse->num_of_credit)
				input >> _;
			else
				input.ignore(2);
		}

		pCourse->pNext = nullptr;
		pCourse->pStuInCourse = nullptr;
		//l++;
	}
	pCourse = pB;
}
void inputTimeTable(Time* p, int a, int b) {
	a -= 2;
	b -= 1;
	p[a].session[b] = "X";
}
void inputExtraStudent(extraStudent*& pExtra) {
	ifstream input("StudentList.csv");
	string line = "";
	string n = "";
	extraStudent* pTemp = pExtra;
	getline(input, line);
	while (!input.eof()) {
		if (pExtra == nullptr) {
			pExtra = new extraStudent;
			pTemp = pExtra;
		}
		else {
			pTemp->pNext = new extraStudent;
			pTemp = pTemp->pNext;
		}
		getline(input, pTemp->id, ',');
		getline(input, pTemp->full_name, ',');
		getline(input, pTemp->dob, '/');
		getline(input, pTemp->mob, '/');
		getline(input, pTemp->yob, ',');
		getline(input, n, '\n');
		if (n == "Nam") pTemp->gender = 'M';
		else pTemp->gender = 'F';
	}

	input.close();
}

//ham dkhp
void createCourseEnrollment(CourseEnrollment*& pEnroll, Semester* pSemester) {
	CourseEnrollment* p = pEnroll;
	system("cls");
	if (pEnroll == nullptr) {
		pEnroll = new CourseEnrollment;
		p = pEnroll;
		cout << "\n\tChua co phien dang ky nao! Vui long tao:\n";
	}
	else {
		while (p->pNext != nullptr) 
			p = p->pNext;
		p->pNext = new CourseEnrollment;
		p = p->pNext;
	}
		
		cout << "======================================\n\n"
			<< "\tPhien dang ky hoc phan - Hoc ky " << pSemester->no << endl
			<< "\tThoi gian hoc ky: " << pSemester->begin_date << "/" << pSemester->begin_month << "/" << pSemester->begin_year << " - " << pSemester->end_date << "/" << pSemester->end_month << "/" << pSemester->end_year << endl
			<< "\tNhap 0 de quay lai. ";
		
		cout << "\n\n\tNhap ma phien dkhp: ";
		string n = "";
		cin >> n;
		if (n == "0") {
			if (pEnroll == p) { 
				delete pEnroll;
				pEnroll = nullptr; 
			}
			else
			{
				CourseEnrollment* pT = pEnroll;
				while (pT->pNext != p)
					pT = pT->pNext;
				delete p;
				pT->pNext = nullptr;
			}
				
			return;
		}
		p->id = n;
		cin.ignore();
		cout << "\n\tNhap ngay bat dau (dd/mm): ";
		getline(cin, n, '/');
		p->start_date = stoi(n);
		getline(cin, n, '\n');
		p->start_month = stoi(n);
		while ( ((p->start_month==pSemester->begin_month) && p->start_date < pSemester->begin_date) || p->start_month < pSemester->begin_month || p->end_month > pSemester->end_month) {
			cout << "\tNhap sai ngay thang. Nhap lai (dd/mm): ";
			getline(cin, n, '/');
			p->start_date = stoi(n);
			getline(cin, n, '\n');
			p->start_month = stoi(n);
		}
		p->start_year = pSemester->begin_year;
		checkDate(p->start_date, p->start_month, p->start_year, pSemester->begin_year);

		cout << "\n\tNhap ngay ket thuc (dd/mm/yyyy): ";
		getline(cin, n, '/');
		p->end_date = stoi(n);
		getline(cin, n, '/');
		p->end_month = stoi(n);
		while ( ((p->end_month == pSemester->end_month) && p->end_date > pSemester->end_date) || p->end_month > pSemester->end_month) {
			cout << "\tNhap sai ngay thang. Nhap lai (dd/mm): ";
			getline(cin, n, '/');
			p->end_date = stoi(n);
			getline(cin, n, '\n');
			p->end_month = stoi(n);
		}
		getline(cin, n, '\n');
		p->end_year = stoi(n);
		checkDate(p->end_date, p->end_month, p->end_year, pSemester->begin_year);
		while (p->end_year > pSemester->end_year) {
			cout << "\tNhap sai nam. Nhap lai: ";
			cin >> p->end_year;
		}

		system("cls");
		cout << "\n\n\tTao phien dang ky hoc phan thanh cong. Bam 0 de quay lai.";
		cin >> n;

		p->semester_no = pSemester->no;
		p->pCourse = pSemester->pCourse;
		p->pNext = nullptr;
}
void showCourseEnrollment(CourseEnrollment*& pEnroll, Semester* pSemester) {
	//xoa phien dkhp
	CourseEnrollment* p = pEnroll;
	int o = 10, o2 = 10, t = 0;
	while (o != 0) {
		system("cls");
		pEnroll = p;
		cout << "===============================================\n\n"
			<< "\tBam so tuong ung de truy cap: "
			<< "\n\tCac phien dang ky hoc phan trong hoc ky " << pSemester->no << ": " << endl;
		int i = 0;
		while (pEnroll != nullptr) {
			cout << "\t" << i+1 << ". ";
			if (pEnroll->status == 1)
				cout << "(On) ";
			else
				cout << "(Off) ";
			cout << pEnroll->id << " (" << pEnroll->start_date << "/" << pEnroll->start_month << ")" << endl;
			pEnroll = pEnroll->pNext;
			i++;
		}
		pEnroll = p;
		cout << "\n\tNhan -1 + so thu tu de bat/tat phien dkhp."
			<< "\n\tNhap -2 de them phien dang ky hoc phan.\n\t" 
			<< "\n\tNhap 0 de quay lai.";
		cin >> o;
		switch (o) {
		case 0:
			break;
		case -1:
			cin >> t;
			for (int j = 1; j < t; j++) {
				pEnroll = pEnroll->pNext;
			}
			pEnroll->status = 1;
			break;
		case -2:
			createCourseEnrollment(pEnroll, pSemester);
			break;
		default:
			while (o > i||o<-2) {
				cout << "\tNhap sai cu phap. Vui long nhap lai: ";
				cin >> o;
			}
				for (int j = 1; j < o; j++) {
					pEnroll = pEnroll->pNext;
				}
				o2 = 10;
				while (o2 != 0) {
					system("cls");
					cout << "================================\n\n"
						<< "\tPhien dang ky hoc phan " << pEnroll->id << " - Hoc ky " << pSemester->no << endl
						<< "\tThoi gian: " << pEnroll->start_date << "/" << pEnroll->start_month << "/" << pEnroll->start_year << " - " << pEnroll->end_date << "/" << pEnroll->end_month << "/" << pEnroll->end_year << endl
						<< "\n\tNhap 1 de chinh sua thoi gian.\n"
						<< "\tNhap 2 de xem danh sach khoa hoc.\n";
					cout << "\tNhap 3 de xem hoc sinh da vao phien dkhp.\n"
						<< "\tNhap 0 de quay lai.\n";
					cin >> o2;
					switch (o2) {
					case 0:
						break;
					case 1:
						editCourseEnrollment(pEnroll, pSemester);
						break;
					case 2:
						showCourseList(pEnroll->pCourse);
						break;
					case 3:
						showStudentHistory(pEnroll->pStudentHistory);
						break;
					default:
						cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
						cin >> o2;
						break;
					}
				}
			
			break;
		}
	}
	pEnroll = p;
}
void Enroll(CourseEnrollment* &pEnroll, Student* &pStudent, Course* &pCourse) { 
	//pStudent = tk cua sv
	//student num of course ++, max = 5
	//cho sv dang ky show list cac phien dkhp
	int no = pEnroll->semester_no;
	CourseEnrollment* p = pEnroll;
	CourseEnrollment* pTempp = pEnroll;
	Course* P = pCourse;
	Course* &pC = pCourse;
	int o = 10, o2 = 10, t = 0;
	int _ = 0;
	while (o != 0) {
		system("cls");
		pEnroll = p;
		if (pEnroll == nullptr) {
			cout << "\n\n\tChua co phien dang ky hoc phan nao. Vui long quay lai sau!\n\tBam 0 de quay lai.";
			cin >> o;
			break;
		}
		cout << "===============================================\n\n"
			<< "\tBam so tuong ung de truy cap: \n"
			<< "\tCac phien dang ky hoc phan: \n";
		int i = 0;
		while (pEnroll != nullptr) {
			if (pEnroll->status == 1) {
				cout << "\t" << i + 1 << ". ";
				cout << pEnroll->id << " (" << pEnroll->start_date << "/" << pEnroll->start_month << ")" << endl;
				i++;
			}
			pEnroll = pEnroll->pNext;
		}
		pEnroll = p;
		cout << "\n\tNhap 0 de quay lai!\n\t";
		cin >> o;
		switch (o) {
		case 0:
			break;
		default:
			if (o > i || o < 0) {
				cout << "\tNhap sai cu phap. Nhap -1 de quay lai.";
				cin >> o;
				break;
			}
			else {
				for (int j = 1; j <= o; j++) {
					if (pEnroll->status == 0)
						i--;
					else if (o == 1) break;
					else
					pEnroll = pEnroll->pNext;
				}
				while (pTempp != nullptr) {
					if (pTempp->id == pEnroll->id)
						break;
					else
						pTempp = pTempp->pNext;
				}
				createHistory(pTempp->pStudentHistory, pStudent);
				o2 = 10;
				while (o2 != 0) {
					pC = P;
					system("cls");
					
					cout << "================================\n\n"
						<< "\tPhien dang ky hoc phan " << pEnroll->id << endl
						<< "\tThoi gian: " << pEnroll->start_date << "/" << pEnroll->start_month << "/" << pEnroll->start_year << " - " << pEnroll->end_date << "/" << pEnroll->end_month << "/" << pEnroll->end_year << endl;
					cout << "\n\tDanh sach khoa hoc (Bam so de xem): \n";
					int i = 0;
					while (pC != nullptr) {
						cout << "\t";
						cout << i + 1 << ". " << pC->course_name << endl;
						pC = pC->pNext;
						i++;
					}
					if (i == 0) {
						cout << "\tChua co phien dkhp nao. Vui long nhap 0 de quay lai.";
						cin >> o2;
						break;
					}
					cout << endl;
					cout << "\n\tNhap -1 + so thu tu de dang ky khoa hoc.\n";
					cout << "\tNhap 0 de quay lai.\n\t";
					pC = P;
					cin >> o2;
					switch (o2) {
					case 0:
						break;
					case -1:
						cin >> t;
						
						for (int j = 1; j < t; j++) {
							pC = pC->pNext;
						}
						cout << "\n\tBan co chac muon dang ky khoa hoc: " << pC->course_name << "?(Yes = 1, No = 0)\n\t";
						cin >> _;
						system("cls");
						//Sleep(2000);
						if (_ == 0) break;
						else {
							if (checkSchedule(pC->pTime, pStudent->pTable)) {
								pStudent->num_of_course++;
								if (pStudent->num_of_course > 5) {
									cout << "\n\n\tVuot qua gioi han hoc phan toi da (5). \n\tNhap -1 de quay lai.";
									pStudent->num_of_course--;
									cin >> o2;
									break;
								}	
								toStudentCourse(pStudent, pC, no);
								toStudentInCourse(pC, pStudent);
								schedule(pC->pTime, pStudent->pTable);
								pC->num_of_student++;
								//thanh cong
								cout << "\n\n\tDang ky thanh cong!\n\tNhap -1 de quay lai.";
								cin >> o2;
							}
							else {
								//ko thanh cong
								cout << "\n\n\tTrung TKB, khong the dang ky khoa hoc nay!.\n\tNhap -1 de quay lai.";;
								cin >> o2;
							}
							
						}
						break;
					default:
						if (o2 < i && o2 > -1) {
							for (int j = 1; j < o2; j++)
								pC = pC->pNext;
							system("cls");
							cout << "================================\n\n";
							cout << "\tTen khoa hoc: " << pC->course_name << endl
								<< "\tMa hoc phan: " << pC->course_id << endl
								<< "\tTen GVLT: " << pC->course_mainteacher << endl
								<< "\tTen GVTH: " << pC->course_teacher << endl
								<< "\tSo tin chi: " << pC->num_of_credit << endl
								<< "\tSo hoc sinh toi da: " << pC->max_student << endl
								<< "\tSo hoc sinh da dang ky: " << pC->num_of_student << endl;
							//xem thoi gian hoc
							cout << "\n\tThoi gian hoc: \n";
							cout << "\tS1 = 7h30, S2 = 9h30, S3 = 13h30, S4 = 15h30\n";
							cout << "\t\tS1\tS2\tS3\tS4\n";
							Time* pT = pC->pTime;
							showTimeTable(pT);
							cout << "\n\tNhap -1 de quay lai.";
							cin >> o2;
						}
						else {
							cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
							cin >> o2;
						}
						break;
						
					}
				}
			}
			break;
		}
	}
}
void editCourseEnrollment(CourseEnrollment*& pEnroll, Semester* pSemester) {
	int o = 10;
	CourseEnrollment* p = pEnroll;
	while (o != 0) {
		system("cls");
		string n = "";
		cout << "=====================================\n\n" << endl;
		cout << "Chinh sua phien dang ki hoc phan ! " << endl;

		cout << "\tPhien dang ky hoc phan - Hoc ky " << pSemester->no << endl
			<< "\tThoi gian hoc ky: " << pSemester->begin_date << "/" << pSemester->begin_month << "/" << pSemester->begin_year << " - " << pSemester->end_date << "/" << pSemester->end_month << "/" << pSemester->end_year << endl
			<< "\tNhap 0 de quay lai. ";

		cout << "\n\tNhap ngay bat dau (dd/mm): ";
		getline(cin, n, '/');
		if (n == "0") {
			o = 0;
			break;
		}
		p->start_date = stoi(n);
		getline(cin, n, '\n');
		p->start_month = stoi(n);
		while (((p->start_month == pSemester->begin_month) && p->start_date < pSemester->begin_date) || p->start_month < pSemester->begin_month || p->end_month > pSemester->end_month) {
			cout << "\tNhap sai ngay thang. Nhap lai (dd/mm): ";
			getline(cin, n, '/');
			p->start_date = stoi(n);
			getline(cin, n, '\n');
			p->start_month = stoi(n);
		}
		p->start_year = pSemester->begin_year;
		checkDate(p->start_date, p->start_month, p->start_year, pSemester->begin_year);

		cout << "\n\tNhap ngay ket thuc (dd/mm/yyyy): ";
		getline(cin, n, '/');
		p->end_date = stoi(n);
		getline(cin, n, '/');
		p->end_month = stoi(n);
		while (((p->end_month == pSemester->end_month) && p->end_date > pSemester->end_date) || p->end_month > pSemester->end_month) {
			cout << "\tNhap sai ngay thang. Nhap lai (dd/mm): ";
			getline(cin, n, '/');
			p->end_date = stoi(n);
			getline(cin, n, '\n');
			p->end_month = stoi(n);
		}
		getline(cin, n, '\n');
		p->end_year = stoi(n);
		checkDate(p->end_date, p->end_month, p->end_year, pSemester->begin_year);
		while (p->end_year > pSemester->end_year) {
			cout << "\tNhap sai nam. Nhap lai (yyyy): ";
			cin >> p->end_year;
		}

		system("cls");
		cout << "\n\n\tChinh sua phien dang ky hoc phan thanh cong. Bam 0 de quay lai.";
		cin >> n;
	}
}
void toStudentCourse(Student*& pSC, Course* &pCourse, int no) {
	//course to student course list
	StudentCourse* p = pSC->pStuCourse;
	if (pSC->pStuCourse == nullptr) {
		pSC->pStuCourse = new StudentCourse;
		p = pSC->pStuCourse;
	}
	else {
		while (p->pNext != nullptr)
			p = p->pNext;
		p->pNext = new StudentCourse;
		p = p->pNext;
	}
	p->course_name = pCourse->course_name;
	p->course_id = pCourse->course_id;
	p->course_teacher = pCourse->course_mainteacher;
	p->num_of_credit = pCourse->num_of_credit;
	p->pNext = nullptr;
	p->pCourse = pCourse;
	p->semester_no = no;
	Time* pCT = pCourse->pTime;
	createTimeTable(p->pTime);
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			p->pTime[i].session[j] = pCT[i].session[j];
		}
	}

}
void toStudentInCourse(Course* &pC, Student*&pStudent) {
	//current student into student in course
	StudentInCourse* p = pC->pStuInCourse;
	if (pC->pStuInCourse == nullptr) {
		pC->pStuInCourse = new StudentInCourse;
		p = pC->pStuInCourse;
	}
	else {
		while (p->pNext != nullptr)
			p = p->pNext;
		p->pNext = new StudentInCourse;
		p = p->pNext;
	}
	p->course_id = pC->course_id;
	p->pStudent = pStudent;
	courseClass(p);
	p->pNext = nullptr;
}
void showStudentCourse(StudentCourse* &pStuCourse, Student *&pS) {
	//chay list pCourse
	system("cls");
	StudentCourse* p = pStuCourse;
	StudentCourse* pC = pStuCourse;
	
	int o3 = 10;
	int o = 10, o2 = 10;
	while (o != 0) {
		p = pStuCourse;
		system("cls");
		cout << "====================================\n\n"
			<< "\tDanh sach khoa hoc da dang ky (Bam so de xem): \n\n";
		int i = 0;
		if (p == nullptr) {
			cout << "\n\n\tKhong co khoa hoc nao! Nhap 0 de quay lai.";
			cin >> o;
			break;
		}
		while (p != nullptr) {
			cout << "\t" << i+1 << ". " << "(HK" << p->semester_no << ") " << p->course_name << endl;
			p = p->pNext;
			i++;
		}
		
		p = pStuCourse;
		StudentInCourse* pSIC = pC->pCourse->pStuInCourse;
		StudentCourse* pTemp2 = pStuCourse;
		int t = 0;
		cout << "\tNhap -1 + so thu tu de huy dang ky khoa hoc.\n";
		cout << "\tNhap -2 de xem bang diem hoc sinh theo tung mon.\n";
		cout << "\tNhap 0 de quay lai!\n\t";
		cin >> o;
		switch (o) {
		case 0:
			break;
		case -1:
			//xoa
			cin >> t;
			removeRegCourse1(pS, t);
			pS->num_of_course--;
			break;
		case -2:
			//xem scoreboard
			break;
		default:
			if (o > i || o < -2) {
				cout << "\tSo khong hop le, vui long nhap lai: ";
				cin >> o;
			}
			else {
				o2 = 10;
				while (o2 != 0) {
					system("cls");
					pC = pStuCourse;
					for (int j = 1; j < o;j++)
						pC = pC->pNext;
					cout << "================================\n\n";
					cout << "\tTen khoa hoc: " << pC->course_name << endl
						<< "\tMa hoc phan: " << pC->course_id << endl
						<< "\tTen GVLT: " << pC->course_teacher << endl
						<< "\tSo tin chi: " << pC->num_of_credit << endl;
					showTimeTable(pC->pTime);
					cout << "\n\tGPA: " << pC->GPA
						<< "\n\tDiem tong: " << pC->final_mark
						<< "\n\tFinal: " << pC->final_mark
						<< "\n\tMidterm: " << pC->midterm_mark;
					
					cout << "\n\tNhap 1 de xem danh sach hoc sinh cua hoc phan.";
					cout << "\n\tNhap 0 de quay lai.";
					cin >> o2;
					switch (o2) {
					case 0:
						break;
					case 1:
						while (o3 != 0) {
							system("cls");
							pSIC = pC->pCourse->pStuInCourse;
							cout << "===================================\n\n"
								<< "\tDanh sach hoc sinh da dang ky: \n\n";
							int i = 0;
							while (pSIC != nullptr) {
								cout << "\t" << i + 1 << ". " << "(Class " << pSIC->course_class << ") " << pSIC->pStudent->full_name << endl;
								pSIC = pSIC->pNext;
								i++;
							}
							pSIC = pC->pCourse->pStuInCourse;
							cout << "\n\tNhap 0 de quay lai!";
							cin >> o3;
							switch (o3) {
							case 0:
								break;
							default:
								cout << "\tNhap sai cu phap, nhap -1 de quay lai.";
								cin >> o3;
								break;
							}
						}
						break;
					default:
						cout << "\tSo khong hop le, vui long nhap lai: ";
						cin >> o2;
						break;
					}
				}
				
			}
			break;
		}
	}

}
void showStudentInCourse(StudentInCourse* &pStuInCourse, Course *&pCourse) {
	//chay list 
	StudentInCourse* p = pStuInCourse;
	int o = 10, o2 = 10, t = 0;
	while (o != 0) {
		system("cls");
		p = pStuInCourse;
		cout << "===================================\n\n"
			<< "\tDanh sach hoc sinh da dang ky: (Bam so de xem)\n\n";
		int i = 0;
		while (p != nullptr) {
			cout << "\t" << i + 1 << ". " << "(Class " << p->course_class << ") " << p->pStudent->full_name << endl;
			p = p->pNext;
			i++;
		}
		p = pStuInCourse;
		cout << "\n\tNhap 0 de quay lai!";
		cout << "\n\tNhap -1 + so thu thu de xoa hoc sinh da dang ky.";
		cin >> o;
		StudentInCourse* pTemp2 = pStuInCourse;
		StudentCourse* p2 = nullptr;
		switch (o) {
		case 0:
			break;
		case -1:
			cin >> t;
			removeRegCourse2(pCourse, t);
			pCourse->num_of_student--;
			break;
		default:
			if (o > i || o < -2) {
				cout << "\tNhap sai cu phap, nhap -1 de quay lai.";
				cin >> o;
				break;
			}
			else {
				for (int j = 1;j < o;j++) {
					p = p->pNext;
				}
				showStudent(p->pStudent);
			}
			break;
		}
	}
}
void courseClass(StudentInCourse* p) {
	//ham chia lop trong hoc phan
	//cout ds lop trong 1hp
	while (p != nullptr) {
		int j = 1;
		for (int i = 1; i <= 15; i++) {
			if (p->course_class != 0) {
				p = p->pNext;
				break;
			}
			p->course_class = j;
			StudentCourse* pTemp = p->pStudent->pStuCourse;
			while (pTemp != nullptr) {
				if (pTemp->course_id == p->course_id) {
					pTemp->course_class = p->course_class;
					return;
				}
				else pTemp = pTemp->pNext;
			}
			p = p->pNext;
		}
		j++;
	}
}
bool checkSchedule(Time* pTime, Time* pTable) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (pTime[i].session[j]=="X")
				if (pTime[i].session[j] == pTable[i].session[j]) {
					return false;
				}
		}
	}
	return true;
}
void removeRegCourse1(Student* &pS, int t) {
	StudentCourse* P = pS->pStuCourse;
	StudentCourse* pT = pS->pStuCourse;
	StudentCourse* &pTemp = pS->pStuCourse;
	StudentCourse* p = pS->pStuCourse;
	for (int i = t - 2; i > 0; i--) {
		p = p->pNext;
	}

	for (int i = t - 1; i > 0; i--) {
		pTemp = pTemp->pNext;
	}
	pT = pTemp;
	p->pNext = pTemp->pNext;
	deschedule(pT->pCourse->pTime, pS->pTable);
	pT->pCourse->num_of_student--;
	StudentInCourse*pT2 = pT->pCourse->pStuInCourse;
	StudentInCourse* P2 = pT->pCourse->pStuInCourse;
	StudentInCourse* p2 = pT->pCourse->pStuInCourse;
	StudentInCourse* &pTemp2 = pT->pCourse->pStuInCourse;

	while (pTemp2 != nullptr)
		if (pTemp2->pStudent->full_name == pS->full_name)
			break;
		else
			pTemp2 = pTemp2->pNext;
	pT2 = pTemp2;
	while (p2->pNext != nullptr)
		if (p2->pNext == pTemp2)
			break;
		else
			p2 = p2->pNext;
	p2->pNext = pTemp2->pNext;
	if (pTemp2 == p2)
		if (pS->pStuCourse != nullptr) {
			pS->pStuCourse->pCourse->pStuInCourse = pS->pStuCourse->pCourse->pStuInCourse->pNext;
			P2 = pS->pStuCourse->pCourse->pStuInCourse;
		}
	if (pTemp == p) {
		pS->pStuCourse = pS->pStuCourse->pNext;
		P = pS->pStuCourse;
	}

	deleteStuInCourse(pT2);
	deleteStuCourse(pT);
	pTemp2 = P2;
	pTemp = P;
	
}
void removeRegCourse2(Course* &pC, int t) {
	StudentInCourse* P = pC->pStuInCourse;
	StudentInCourse* pT = pC->pStuInCourse;
	StudentInCourse*& pTemp = pC->pStuInCourse; //mainpointer
	StudentInCourse* p = pC->pStuInCourse;
	for (int i = t - 2; i > 0; i--) {
		p = p->pNext;
	}

	for (int i = t - 1; i > 0; i--) {
		pTemp = pTemp->pNext;	
	}
	pT = pTemp;
	p->pNext = pTemp->pNext;
	/*if (pTemp == p) {
		pC->pStuInCourse = pC->pStuInCourse->pNext;
		P = pC->pStuInCourse;
	}*/
	pT->pStudent->num_of_course--;
	deschedule(pC->pTime, pT->pStudent->pTable);
	StudentCourse* P2 = pT->pStudent->pStuCourse;
	StudentCourse*pT2 = pT->pStudent->pStuCourse;
	StudentCourse* p2 = pT->pStudent->pStuCourse;
	StudentCourse* &pTemp2 = pT->pStudent->pStuCourse;

	while (pTemp2 != nullptr)
		if (pTemp2->pCourse->course_id == pC->course_id)
			break;
		else
			pTemp2 = pTemp2->pNext;
	pT2 = pTemp2;

	while (p2->pNext != nullptr)
		if (p2->pNext == pTemp2)
			break;
		else
			p2 = p2->pNext;
	p2->pNext = pTemp2->pNext;

	if (pTemp2 == p2)
		if (pC->pStuInCourse != nullptr) {
			pC->pStuInCourse->pStudent->pStuCourse = pC->pStuInCourse->pStudent->pStuCourse->pNext;
			P2 = pC->pStuInCourse->pStudent->pStuCourse;
		}
	if (pTemp == p) {
		pC->pStuInCourse = pC->pStuInCourse->pNext;
		P = pC->pStuInCourse;
	}
	deleteStuCourse(pT2);
	deleteStuInCourse(pT);
	pTemp2 = P2;
	pTemp = P;

}
void schedule(Time* pTime, Time* pTable) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (pTime[i].session[j] == "X")
				pTable[i].session[j] = pTime[i].session[j];
		}
	}
}
void deschedule(Time* pTime, Time* pTable) {
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 4; j++) {
			if (pTime[i].session[j] == "X")
				pTable[i].session[j] = "0";
		}
	}
}
void createHistory(StudentHistory*& pH, Student* pS) {
	//copy pS qua pH
	StudentHistory* p = pH;
	if (pH == nullptr) {
		pH = new StudentHistory;
		p = pH;
	}
	else {
		while (p->pNext != nullptr)
			p = p->pNext;
		p->pNext = new StudentHistory;
		p = p->pNext;
	}
	p->time = "";
	struct tm ltm;
	time_t now = time(0);
	localtime_s(&ltm, &now);

	if (ltm.tm_hour < 10)
		p->time += "0" + to_string(ltm.tm_hour);
	else
		p->time += to_string(ltm.tm_hour);
	p->time += ":";
	if (ltm.tm_min < 10)
		p->time += "0" + to_string(ltm.tm_min);
	else
		p->time += to_string(ltm.tm_min);
	p->time += ":";
	if (ltm.tm_sec < 10)
		p->time += "0" + to_string(ltm.tm_sec);
	else
		p->time += to_string(ltm.tm_sec);

	p->pStudent = pS;
	p->pNext = nullptr;
}
void showStudentHistory(StudentHistory* pH) {
	system("cls");
	int i = 0;
	cout << "\n\n\tHoc sinh da vao xem: \n";
	while (pH != nullptr) {
		cout << "\t" << i + 1 << ". " << pH->pStudent->full_name << " (" << pH->time << ")" << endl;
		pH = pH->pNext;
		i++;
	}
	cout << "\tNhan 0 de quay lai!";
	cin >> i;
}

//ham diem(score)
double toGPA(int n, string &grade) {
	if (n < 0 || n > 10) {
		grade = "F";
		return 0;
	}
	if (n <= 9) {
		grade = "A+";
		return 4;
	}
	else if (n <= 8) {
		grade = "A";
		return 3.5;
	}
	else if (n <= 7) {
		grade = "B+";
		return 3;
	}	
	else if (n <= 6) {
		grade = "B";
		return 2.5;
	}
	else if (n <= 5) {
		grade = "C";
		return 2;
	}	
	else if (n <= 4) {
		grade = "D";
		return 1.5;
	}	
	else if (n <= 3) {
		grade = "F";
		return 1;
	}
	else {
		grade = "F-";
		return 0;
	}
}
void printCourseScoreboard() {

}
void printClassScoreboard() {

}
void printStudentScoreboard(Student *pS) {
	system("cls");
	int _ = 0;
	StudentCourse* pSC = pS->pStuCourse;
	cout << "\n\n\tSo khoa hoc trong hoc ki: " << pS->num_of_course << endl << endl;
	cout << setw(60) << left << "\tMon hoc";
	cout << "\tMidterm   Final   Progress   Total   GPA   Grade" << endl;

	while (pSC != nullptr) {
		cout << setw(60) << left << "\t" << pSC->course_name << "\t" << pSC->midterm_mark << "   " << pSC->final_mark << "   " << pSC->progress_mark << "   " << pSC->total_mark << "   " << pSC->GPA <<"   " << pSC->grade << endl;
		pSC = pSC->pNext;
	}

	cout << "\n\tNhap 0 de quay lai.";
	cin >> _;

}

//ham delete tung cai
void deleteClass(Class* &pClass) {
	Student* p = pClass->pStudent;
	while (p != nullptr) {
		deleteStudent(p);
	}
	delete pClass;
}
void deleteStudent(Student*& pStudent) {
	Student* pTmp = pStudent;
	deleteTimeTable(pStudent->pTable);
	pStudent = pStudent->pNext;
	delete pTmp;
}
void deleteCourse(Course*& pCourse) {
	StudentInCourse* p = pCourse->pStuInCourse;
	while (p != nullptr) {
		StudentInCourse* pTmp = p;
		p = p->pNext;
		delete pTmp;
	}
	deleteTimeTable(pCourse->pTime);
	delete pCourse;
}
void deleteTimeTable(Time*& p) {
	for (int i = 0; i < 6; i++) {
		delete[] p[i].session;
	}
	delete[] p;
}
void deleteUser(UserAccount*& pUser) {
	while (pUser != nullptr) {
		UserAccount* p = pUser;
		pUser = pUser->pNext;
		delete p;
	}
}
void deleteStuInCourse(StudentInCourse*& pTemp2) {
	pTemp2->pStudent = nullptr;
	delete pTemp2;
	pTemp2 = nullptr;
}
void deleteStuCourse(StudentCourse*& pTemp2) {
	pTemp2->pCourse = nullptr;
	Time* p = pTemp2->pTime;
	deleteTimeTable(p);
	delete pTemp2;
	pTemp2 = nullptr;
	p = nullptr;
}
void checkDate(int& date, int& month, int& year, int year2) {
	while (year < year2 || year > year2 + 1) {
		cout << "\tNhap sai nam, vui long nhap lai nam: ";
		cin >> year;
	}
	while (month <= 0 || month > 12) {
		cout << "\tNhap sai thang, vui long nhap lai thang: ";
		cin >> month;
	}
	while (date <= 0 || date > 31) {
		cout << "\tNhap sai ngay, vui long nhap lai ngay: ";
		cin >> date;
	}
	while (month == 2 && (((date > 29) && ( (year % 4 == 0 && year % 100 != 0) || (year%400==0) )) || date > 28)) { //k phai nam nhuan ma nhap 29 ngay
		cout << "\tNhap sai ngay, vui long nhap lai ngay: ";
		cin >> date;
		//nam nhuan = chia het cho 4 va k chia het cho 100 || chia het cho 400
	}
	while (date > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
		cout << "\tNhap sai ngay, vui long nhap lai ngay: ";
		cin >> date;
	}
	while (date > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
		cout << "\tNhap sai ngay, vui long nhap lai ngay: ";
		cin >> date;
	}
	//system("cls");

}
//void courseClassEnum(Class* pClass, StudentInCourse* p) {
//	//nhap lop hp cho hoc sinh
//	while (p != nullptr) {
//		Class* pC = pClass;
//		while (pC != nullptr) {
//			Student* pS = pC->pStudent;
//			while (pS != nullptr) {
//				if (pS->full_name == p->full_name) {
//					StudentCourse* psc = pS->pStuCourse;
//					while (psc != nullptr) {
//						if (psc->course_id == p->course_id) { //psc da co san id cua hoc phan
//							psc->course_class = p->course_class;
//							psc = nullptr;
//							pS = nullptr;
//							pC = nullptr;
//							break;
//						}
//						else psc = psc->pNext;
//					}
//				}
//				else pS = pS->pNext;
//			}
//			if (pC != nullptr) pC = pC->pNext;
//		}
//		p = p->pNext;
//	}
//}

//ham export
void exportClass(Class* pClass) {
	system("cls");
	int _ = 0;
	ofstream output("ClassScoreboard.csv");

	if (!output.is_open()) {
		cout << "\n\n\tKhong  mo duoc file. Nhap -1 de quay lai.";
		cin >> _;
		return;
	}
	else {
		cout << "\n\n\tDang nhap file . . .\n";
		output << "Ten lop,Ten hoc sinh,MSSV,Gioi tinh,STT,Ngay thang nam sinh,username,password,GPA" << endl;
		while (pClass != nullptr) {
			Student* pS = pClass->pStudent;
			while (pS != nullptr) {
				output << pClass->class_name << ","
					<< pS->id << ","
					<< pS->full_name << ","
					<< pS->gender << ","
					<< pS->no << ","
					<< pS->dob << "/" << pS->mob << "/" << pS->yob << ","
					<< pS->user_name << ","
					<< pS->user_password << "," 
					<< pS->GPA << "," << endl;
				pS = pS->pNext;
			}
			pClass = pClass->pNext;
		}
		output.close();

		cout << "\tXuat file thanh cong! Nhan -1 de quay lai.";
		cin >> _;
		return;
	}
}

//ham console
void gotoXY(int x, int y) {
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void TextColor(int color) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void Flashing(string s) {
	while (1) {
		system("cls");
		gotoXY(1, 0);
		TextColor(rand() % 15 + 1);
		cout << s.c_str();
		if (_kbhit())
			break;
		Sleep(500);
	}
	TextColor(15);
}
void Run(string s) {
	Word a;
	a.x = 1;
	a.y = 1;
	a.t = RIGHT;
	while (1) {
		system("cls");
		gotoXY(a.x, a.y);
		TextColor(rand() % 15 + 1);
		cout << s.c_str();

		if (_kbhit())
			break;

		if (a.x >= 30)
			a.t = LEFT;
		else if (a.x <= 0)
			a.t = RIGHT;

		if (a.t == LEFT)
			a.x--;
		else if (a.t == RIGHT)
			a.x++;
		Sleep(30);
	}
}