#include "Header.h"

void print_Staff_Menu();
void print_Student_Menu();

int main() {
	UserAccount* pUser;

	{//ham input user account, set pUser vao Node dau tien.
	}

	{//test ham showUserAccount
		pUser = new UserAccount;
		pUser->full_name = "H M Bao";
		pUser->user_class = "20CLC04";
		pUser->user_name = "bebaoboy";
		pUser->user_password = "abcdefgh";
		pUser->pNext = new UserAccount;

		pUser->pNext->full_name = "H M Bap";
		pUser->pNext->user_class = "20CLC02";
		pUser->pNext->user_name = "bebaoboy2";
		pUser->pNext->user_password = "abcdefgh";
		pUser->pNext->pNext = new UserAccount;

		pUser->pNext->pNext->full_name = "H M aaaBap";
		pUser->pNext->pNext->user_class = "20CLC02";
		pUser->pNext->pNext->user_name = "bebaoboy3";
		pUser->pNext->pNext->user_password = "abcdefgh";
		pUser->pNext->pNext->pNext = nullptr;

		//showUserAccount(pUser, pUser->pNext->user_name);
	}

	SchoolYear* pSchoolYear = nullptr;
	Semester* pSemester = nullptr;
	Class* pClass = nullptr;
	string _ = " ";

	while ( _ != "-1")
	{
	string user_name = " ";
	string user_password = " ";

	cout << "=======================================\n\n"
		<< "\tVui long dang nhap de tiep tuc\n\tHoac bam -1 de ket thuc chuong trinh: \n";
	cout << "\tNhap username: "; cin >> user_name;
	if (user_name == "-1") break;
	cout << "\tNhap mat khau: "; cin >> user_password;

	UserAccount* pCur = pUser;
	Class* pCurClass = pClass;

	system("CLS");
	int option = 0;

	while (pCur != nullptr) {
		if (pCur->user_name == user_name)
			break;
		else
			pCur = pCur->pNext;
	}
	//neu la gv
	if (pCur != nullptr) {
		int i = 0;
		while (pCur->user_password != user_password) {
			cout << "\tSai mat khau, nhap lai: ";
			cin >> user_password;
			if (i == 3) {
				int h = 0;
				cout << "\tQuen mat khau? Nhap 1 de duoc giup do!";
				cin >> h;
				cout << "\tMat khau cua ban la: " << pCur->user_password << endl;
			}
			i++;
		}
		system("cls");
		cout << "===============================\n\n"
			<< "\tDang nhap thanh cong!!\n\tNhap 0 de tiep tuc.";
		cin >> option;
		system("cls");
		goto teacher;
	}

	//neu la sv
	else {
		Student* pTemp = nullptr;
		while (pCurClass != nullptr) {
			pTemp = pCurClass->pStudent;
			while (pTemp != nullptr || pTemp->id != user_name) {
				pTemp = pTemp->pNext;
			}
			if (pTemp == nullptr) {
				pCurClass = pCurClass->pNext;
				pTemp = pCurClass->pStudent;
			}
			else
				break;
		}
		if (pCurClass == nullptr) {
			cout << "============================\n\n"
				<< "\tKhong tim thay tai khoan!\n\n";
			return -1;
		}
		int i = 0;
		while (pTemp->user_password != user_password) {
			cout << "\tSai mat khau, nhap lai: ";
			cin >> user_password;
			if (i == 3) {
				int h = 0;
				cout << "\tQuen mat khau? Nhap 1 de duoc giup do!";
				cin >> h;
				cout << "\tMat khau cua ban la: " << pTemp->user_password << endl;
			}
			i++;
		}
		system("cls");
		cout << "===============================\n\n"
			<< "\tDang nhap thanh cong!!\n\tNhap 0 de tiep tuc.";
		cin >> option;
		system("cls");
		goto student;
	}

teacher:
	while (option != -1) {
		print_Staff_Menu();
		cin >> option;
		system("cls");
		switch (option) {
		case 0:
			showUserAccount(pUser, pCur->user_name);
			break;

		case 1: {
			// view school year infor
			if (pSchoolYear == nullptr) {
				//ham tao nam hoc
				//pSchoolYear = new SchoolYear;
			}
			else {
				int option1 = 1;
				system("CLS");
				while (option1 != 0) {
					cout << "\tChon cac so sau de tiep tuc :" << endl;;
					cout << "\t0. Quay lai." << endl;
					cout << "\t1. Xem thong tin hoc ki." << endl;
					cout << "\t2. Xem thoi gian nam hoc. " << endl;
					cout << "\tTiep tuc voi:";
					cin >> option1;

					switch (option1) {
					case 0:
						// back
						break;
					case 1:
						// showSemester
						break;
					case 2:
						// show thoi gian school year
						break;
					default:
						break;
					}
				}
			}
			break;
		}

		case -1:
			// log out
			break;
		default:
			break;
		}
		//cin >> option;
		//cout << "\tNhap -1 de tiep tuc.";
		system("cls");
	}

student:
	while (option != -1) {
		print_Student_Menu();
		cin >> option;
		system("cls");
		switch (option) {
		case 1:
			//xem thong tin hs
			break;
		case 2: {

			system("CLS");
			int option1 = 1;
			while (option1 != 0) {
				cout << "\tChon cac so sau de tiep tuc :" << endl;;
				cout << "\t0. Quay lai." << endl;
				cout << "\t1. Xem thong tin hoc ki." << endl;
				cout << "\t2. Xem thoi gian nam hoc. " << endl;
				cout << "\tTiep tuc voi:";

				cin >> option1;
				switch (option1) {
				case 0:
					// back
					break;
				case 1:
					// showSemester
					break;
				case 2:
					// show school year
					break;
				default:
					break;
				}
			}
			break;
		}
		case -1:
			// log out
			break;
		default:
			break;
		}
		//cin >> option;
		//cout << "\tNhap -1 de tiep tuc.";
		system("cls");
	}

	cout << "===================================\n\n"
		<< "\tDang xuat thanh cong!"
		<< "\n\n===================================="
		<< endl;

	// PHAN 2: CHUONG TRINH

	system("pause");
	system("cls");
}
	cout << "\tChuong trinh ket thuc!!!\n";
	return 0;
}

void print_Staff_Menu() {
	cout << "===========================================" << endl;
	cout << "             WELCOME, TEACHER !     " << endl;
	cout << "\tChon cac so sau de tiep tuc : " << endl;
	cout << "\t0. Xem thong tin tai khoan. " << endl;
	cout << "\t1. Xem thong tin nam hoc. " << endl;
	cout << "\t2. Xem......... " << endl;
	cout << "\t-1. Dang xuat. " << endl;
	cout << "\tTiep tuc voi : ";
}

void print_Student_Menu() {
	cout << "=======================================" << endl;
	cout << "           WELCOME, STUDENT !             " << endl;
	cout << "\tChon cac so sau de tiep tuc : " << endl;
	cout << "\t1. Xem thong tin sinh vien." << endl;
	cout << "\t2. Xem thong tin nam hoc. " << endl;
	cout << "\t3. FOR WHAT??" << endl;
	cout << "\t-1. Dang xuat. " << endl;
	cout << "\tTiep tuc voi : ";
}


