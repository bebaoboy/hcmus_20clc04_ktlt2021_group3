#include "Header.h"
#include "struct.h"

//trong ham: nhap 0 quay lai, trong switch: nhap -1 quay lai

//for teacher only
void changeUserPassword(string& user_password) {
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
	UserAccount* pB = pUser;
	int opt = 10;
	while (pUser != nullptr) {
		if (pUser->user_name == user_name) break;
		else {
			pUser = pUser->pNext;
		}
	}
	while (opt != 0) {
		cout << "=============================\n\n"
			<< "\tUsername: " << pUser->user_name
			<< "\n\tFullname: " << pUser->full_name
			<< "\n\tLop chu nhiem: " << pUser->user_class
			<< "\n\tPassword: Nhap 3 de xem\n\tNhap 1 de doi password."
			<< "\n\tNhap 2 de thay doi thong tin!"
			<< "\n\tNhap 0 de quay lai.";
		cin.ignore();
		cin >> opt;
		system("cls");
		switch (opt) {
		case 1:
			changeUserPassword(pUser->user_password);
			break;
		case 2:
			editUserAccount(pB, pUser->user_name);
			break;
		case 3:
			system("cls");
			cout << "================================\n\n"
				<< "\tPassword: " << pUser->user_password
				<< endl;
			cout << "\tNhap -1 de tiep tuc.";
			cin >> opt;
			break;
		case 0:
			return;
		default:
			cout << "\tNhap sai cu phap.";
			break;
		}

		system("cls");
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

//ham tao
void createSchoolYear(SchoolYear*& pSchoolYear) {
	int year = 0;
	if (pSchoolYear == nullptr)
		pSchoolYear = new SchoolYear;
	else {
		pSchoolYear->pNext = new SchoolYear;
		pSchoolYear = pSchoolYear->pNext;
	}
	pSchoolYear->pSemester = nullptr;
	system("cls");
	cout << "====================================\n\n"
		<< "\tNhap nam bat dau (nien khoa - YYYY): ";
	cin >> year;
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
void createClass(Class*& pClass) {
	Class* pB = pClass;
	while (pB->pNext != nullptr) {
		pB = pB->pNext;
	}
}
void createCourse(Course*& pCourse) {
	Course* pB = pCourse;
	while (pB->pNext != nullptr) {
		pB = pB->pNext;
	}
}
void createStudent(Student*& pStudent, int& num) {
	system("cls");

	if (pStudent == nullptr)
		pStudent = new Student;
	else {
		while (pStudent->pNext != nullptr)
			pStudent = pStudent->pNext;
		pStudent->pNext = new Student;
		pStudent = pStudent->pNext;
	}
	int opt = 10;
	string n = "";
	cout << "===================================\n\n"
		<< "\tNhap 0 de quay lai.\n"
		<< "\tNhap Fullname: ";
	cin.ignore();
	getline(cin, n, '\n');
	if (n == "0") return;
	num++;
	pStudent->full_name = n;
	cout << "\tNhap MSSV: ";
	cin >> pStudent->id;
	cout << "\tNhap gioi tinh (nam = M, nu = F): ";
	cin >> pStudent->gender;
	cout << "\tNhap ngay sinh: dd/mm/yyyy: ";
	getline(cin, pStudent->dob, '/');
	getline(cin, pStudent->mob, '/');
	getline(cin, pStudent->yob, '\n');
	pStudent->user_name = pStudent->id;
	pStudent->user_password = "";
	pStudent->user_password = pStudent->user_password + pStudent->dob + pStudent->mob + pStudent->yob;
	pStudent->pStuCourse = nullptr;
	pStudent->pNext = nullptr;
	createTimeTable(pStudent);
}
void createTimeTable(Student* pStudent) {
	pStudent->pTable = new Time[6];
	Time* p = pStudent->pTable;
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
void showStudent(Student* pStudent) {
	system("cls");
	int o = 10;
	while (o != 0) {
		cout << "=====================================\n\n"
			<< "\tUsername: " << pStudent->user_name
			<< "\n\tPassword: Bam 1 de xem"
			<< "\n\tFull name: " << pStudent->full_name
			<< "\n\tMSSV: " << pStudent->id
			<< "\n\tGioi tinh: " << ((pStudent->gender == 'M') ? "Nam" : "Nu")
			<< "\n\tNgay sinh: " << pStudent->dob << "/" << pStudent->mob << "/" << pStudent->yob
			//<< "\n\tSocial ID: " 
			<< "\n\tLop chu nhiem: " << pStudent->mainclass << endl;
		cout << "\tNhap 2 de xem danh sach hoc phan da dang ky." << endl;
		cout << "\tNhap 3 de chinh sua thong tin" << endl;
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
		case 2:
			//goi ham courseinstudent
			break;
		case 3:
			editStudent(pStudent);
			break;
		case 0:
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
		while (o > i) {
			cout << "\tSo khong hop le, vui long nhap lai: ";
			cin >> o;
		}
			for (int j = 1; j < o; j++) {
				pStudent = pStudent->pNext;
			}
			showStudent(pStudent);
		}

	}
}
void showCourse(Course* pCourse) {
	int o = 10;
	while (o != 0) {
		system("cls");
		cout << "================================\n\n";
		cout << "\tTen khoa hoc: " << pCourse->course_name << endl
			<< "\tMa hoc phan: " << pCourse->course_id << endl
			<< "\tTen GVLT: " << pCourse->course_mainteacher << endl
			<< "\tTen GVTH: " << pCourse->course_name << endl
			<< "\tSo tin chi: " << pCourse->num_of_credit << endl
			<< "\tSo hoc sinh toi da: " << pCourse->max_student << endl
			<< "\tSo hoc sinh da dang ky: " << pCourse->num_of_student << endl;
		cout << "\tThoi gian hoc: \n";
		cout << "\tS1 = 7h30, S2 = 9h30, S3 = 13h30, S4 = 15h30\n";
		
		Time* pT = pCourse->pTime;
		for (int i = 0; i < 6; i++) {
			cout << "\t" << pT[i].day << ": ";
			for (int j = 0; j < 4; j++) {
				if (pT[i].session[j] == "X")
					cout << "\tS" << j;
				cout << " ";
			}
			cout << endl;
		}
		cout << "\n\tNhap 0 de quay lai.";
		cin >> o;
	}
}
void showCourseList(Course* pCourse) {
	int o = 10;	
	Course* pB = pCourse;
	while (o != 0) {
		pCourse = pB;
		system("cls");
		cout << "================================\n\n"
			<< "\tDanh sach khoa hoc (Bam so tuong ung de truy cap): \n";
		int i = 1;
		while (pCourse != nullptr) {
			cout << "\t";
			cout << i << ". " << pCourse->course_name << endl;
			pCourse = pCourse->pNext;
			i++;
		}
		pCourse = pB;
		Course* pTmp = pCourse;
		cout << "\tBam 0 de quay lai\n"
			<< "\tBam -1 + so thu tu de xoa khoa hoc\n"
			<< "\tBam 1 de them khoa hoc\n\t";
		cin >> o;
		int t = 0;
		switch (o) {
		case 0:
			return;
		case 1:
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
			while (o > i) {
				cout << "\tSo khong hop le, vui long nhap lai: ";
				cin >> o;
			}
			for (int j = 1; j < o; j++) {
				pCourse = pCourse->pNext;
			}
			showCourse(pCourse);
			break;
		}
	}
}
void showClass(Class* &pClass) {
	int opt = 100;
	while (opt != 0) {
		system("cls");
		int i = 1, t = -10;
		Class* pB = pClass;
		cout << "====================================\n\n"
			<< "\tDanh sach lop chu nhiem: (Bam so tuong ung de truy cap) \n";
		while (pB != nullptr) {
			cout << "\t" << i << ". ";
			cout << pB->class_name << endl;
			i++;
			pB = pB->pNext;
		}
		pB = pClass;
		cout << "\n\tNhap -1 + so thu tu lop hoc de xoa lop hoc\n"
			<< "\tNhap -2 de tao lop hoc\n"
			<< "\tNhap 0 de quay lai.\n";
		cin >> opt;
	system("cls");
	Class* pTemp2 = pClass;
		switch (opt) {
		case 0:
			break;
		case -1:
			//ham xoa
			cin >> t;
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
			createClass(pB);
			break;
		default:
			if (opt < 0 || opt > i) {
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
						<< "\n\tNhap 0 de quay lai.";
					cin >> o;
					system("cls");
					switch (o) {
					case 0:
						break;
					case 1:
						showStudentList(pTemp2->pStudent, pTemp2->num_of_student);
						break;
					case 2:
						editClass(pTemp2);
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
void showSemester(Semester* pSemester, int year) {
	//chay list ngpai main
	//goi ham show class	
	int option = 10;
	while (option!=0)
	system("cls");
	cout << "=================================\n\n"
		<< "\tNhap so de tiep tuc: \n"
		<< "\t1. Xem thong tin cac lop hoc.\n"
		<< "\t2. Xem thong tin cac khoa hoc.\n"
		<< "\t3. Xem thoi gian hoc ky.\n"
		<< "\tNhap 0 de quay lai.";
	cin >> option;
	switch (option) {
	case 0:
		break;
	case 1:
		//show class
		break;
	case 2:
		//show course
		break;
	case 3:
		showSemesterTime(pSemester, year);
		break;
	default:
		cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
		cin >> option;
		break;
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
		cout << "\tNhap 1 de chinh sua thoi gian. " << endl;
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
	system("cls");
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
		cout << "\tNhap 1 de chinh sua nam hoc.\n";
		cout << "\tNhap 0 de quay lai.";
		cin >> opt;
		switch (opt) {
		case 0:
			break;
		case 1:
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
	p->begin_month = 1;
	p->begin_year = 2020;
	p->end_date = 1;
	p->end_month = 4;
	p->end_year = 2020;

	p->pNext = new Semester;
	p = p->pNext;
	p->no = 2;
	p->begin_date = 1;
	p->begin_month = 5;
	p->begin_year = 2020;
	p->end_date = 1;
	p->end_month = 7;
	p->end_year = 2020;

	p->pNext = new Semester;
	p = p->pNext;
	p->no = 3;
	p->begin_date = 1;
	p->begin_month = 8;
	p->begin_year = 2020;
	p->end_date = 1;
	p->end_month = 10;
	p->end_year = 2020;
	p->pNext = nullptr;

	p->pClass = nullptr;
	p->pCourse = nullptr;
	p->pEnroll = nullptr;
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
		pTemp->user_password = "";
		pTemp->user_password = pTemp->user_password + pTemp->dob + pTemp->mob + pTemp->yob;
		//getline(input, n, ','); //cmnd
		pTemp->mainclass = pClass->class_name;
		pTemp->pNext = nullptr;
		createTimeTable(pTemp);
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
	Course* pB = pCourse;
	//int l = 1;
	while (!input.eof()) {
		if (pCourse == nullptr) {
			pCourse = new Course;
			pB = pCourse;
		}
		else {
			pCourse->pNext = new Course;
			pCourse = pCourse->pNext;
		}
		pCourse->pTime = new Time[6];
		Time* p = pCourse->pTime;
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

//ham dkhp
void toStudentCourse(StudentCourse*& pSC, Course* pCourse) {

}
void toStudentInCourse(StudentInCourse*& pSIC, Course* pCourse) {

}

//ham phu
void deleteClass(Class* &pClass) {
	Student* p = pClass->pStudent;
	while (p != nullptr) {
		deleteStudent(p);
	}
	delete pClass;
}
void deleteStudent(Student*& pStudent) {
	Student* pTmp = pStudent;
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
	for (int i = 0; i < 6; i++) {
		delete[] pCourse->pTime[i].session;
	}
	delete[] pCourse->pTime;
	delete pCourse;
}
void deleteUser(UserAccount*& pUser) {
	while (pUser != nullptr) {
		UserAccount* p = pUser;
		pUser = pUser->pNext;
		delete p;
	}
}
void courseClass(StudentInCourse* p) {

}
void checkDate(int& date, int& month, int& year, int year2) {
	while (year < year2 || year > year2 + 1) {
		cout << "Nhap sai nam, vui long nhap lai: ";
		cin >> year;
	}
	while (month <= 0 || month > 12) {
		cout << "Nhap sai thang, vui long nhap lai: ";
		cin >> month;
	}
	while (date <= 0 || date > 31) {
		cout << "Nhap sai ngay, vui long nhap lai: ";
		cin >> date;
	}
	while (month == 2 && (((date >= 29) && (year % 4 != 0 && year % 100 != 0)) || date > 28)) { //k phai nam nhuan ma nhap 29 ngay
		cout << "Nhap sai ngay, vui long nhap lai: ";
		cin >> date;
	}
	while (date > 30 && (month == 4 || month == 6 || month == 9 || month == 11)) {
		cout << "Nhap sai ngay, vui long nhap lai: ";
		cin >> date;
	}
	while (date > 31 && (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)) {
		cout << "Nhap sai ngay, vui long nhap lai: ";
		cin >> date;
	}
	//system("cls");

}