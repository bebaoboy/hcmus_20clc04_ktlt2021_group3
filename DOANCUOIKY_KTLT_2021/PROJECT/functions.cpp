#include "Header.h"
#include "struct.h"

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
	createSemester(pSchoolYear->pSemester);
}
void createSemester(Semester*& pSemester) {
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

		cout << "\tNhap ngay ket thuc (DD/MM/YYYY): ";
		getline(cin, n, '/');
		pSemester->end_date = stoi(n);
		getline(cin, n, '/');
		pSemester->end_month = stoi(n);
		getline(cin, n, '\n');
		pSemester->end_year = stoi(n);
		pSemester->pNext = nullptr;
	}
	
	pSemester = pBeginning;
	cout << "=================================\n\n"
		<< "\tNhap hoc ky thanh cong!\n\tBam -1 de quay lai!";
	cin >> i;

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
		case 0:
			break;
		default:
			cout << "\tNhap sai cu phap\nNhap -1 de tiep tuc.";
			cin >> o;
			break;
		}
	}
	
}

//ham input
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
		if (pClass->pStudent == nullptr) pClass->pStudent = pTemp;
	}
	pClass->pNext = nullptr;
}

