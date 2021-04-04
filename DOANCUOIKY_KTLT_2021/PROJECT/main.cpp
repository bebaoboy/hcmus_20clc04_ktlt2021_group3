#include "Header.h"

void print_Staff_Menu();
void print_Student_Menu();

int main() {
	string user_name = " ";
	string user_password = " ";
	UserAccount* pUser;

	{//ham input user account, set pUser vao Node dau tien.
	}

	{//test ham showUserAccount
	pUser = new UserAccount;
	pUser->full_name = "H M Bao";
	pUser->id = 20127004;
	pUser->user_class = "20CLC04";
	pUser->user_name = "bebaoboy";
	pUser->user_password = "abcdefgh";
	pUser->user_type = 1;
	pUser->pNext = new UserAccount;

	pUser->pNext->full_name = "H M Bap";
	pUser->pNext->id = 20127004;
	pUser->pNext->user_class = "20CLC02";
	pUser->pNext->user_name = "bebaoboy2";
	pUser->pNext->user_password = "abcdefgh";
	pUser->pNext->user_type = 2;
	pUser->pNext->pNext = new UserAccount;

	pUser->pNext->pNext->full_name = "H M aaaBap";
	pUser->pNext->pNext->id = 20127004;
	pUser->pNext->pNext->user_class = "20CLC02";
	pUser->pNext->pNext->user_name = "bebaoboy3";
	pUser->pNext->pNext->user_password = "abcdefgh";
	pUser->pNext->pNext->user_type = 2;
	pUser->pNext->pNext->pNext = nullptr;

	//showUserAccount(pUser, pUser->pNext->user_name);
	}

	// PHAN 1: DANG NHAP
	UserAccount* pCur = pUser;
	cout << "End program" << endl;

	// PHAN 2: CHUONG TRINH
	SchoolYear* pSchoolYear = nullptr;
	Semester* pSemester = nullptr;
	system("CLS");
	int option = 0;
	switch (pCur->user_type) {
	case 1: //gv
	{
		
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
		break;
	}

	case 2: //sv
	{
		while (option != -1) {
			print_Student_Menu();
			cin >> option;
			system("cls");
			switch (option) {
			case 0:
				showUserAccount(pUser, pCur->user_name);
				break;
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
		break;
	}

	}

	system("pause");
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
	cout << "\t0. Xem thong tin tai khoan.  " << endl;
	cout << "\t1. Xem thong tin sinh vien." << endl;
	cout << "\t2. Xem thong tin nam hoc. " << endl;
	cout << "\t3. FOR WHAT??" << endl;
	cout << "\t-1. Dang xuat. " << endl;
	cout << "\tTiep tuc voi : ";
}


