#include "stdafx.h"
#include "menu.h"
#include "function.h"
void print_Staff_Menu() {
	cout << "===========================================" << endl;
	cout << "             WELCOME, TEACHER !     " << endl;
	cout << "Chon cac so sau de tiep tuc : " << endl;
	cout << "0. Xem thong tin tai khoan. " << endl;
	cout << "1. Xem thong tin nam hoc. " << endl;
	cout << "2. Xem......... " << endl;
	cout << "-1. Dang xuat. " << endl;
	cout << "Tiep tuc voi : ";
}
void print_schoolyearinfor() {
	cout << "Chon cac so sau de tiep tuc :" << endl;;
	cout << "0. Quay lai." << endl;
	cout << "1. Xem thong tin hoc ki." << endl;
	cout << "2. Xem thoi gian nam hoc. " << endl;
	cout << "Tiep tuc voi:";
}
void show_Staff_Menu() {
	system("CLS");
	int option;
	string temp;
	print_Staff_Menu();
	cin >> option;
	getline(cin, temp);
	system("CLS");
	while (!option) {
		switch (option) {
		case 0: 
			//show user accout function
		case 1: {
			// view school year infor
			print_schoolyearinfor();
			int option1;
			string temp1;
			cin >> option1;
			getline(cin, temp1);
			system("CLS");
			while (!option1) {
				switch (option1) {
				case 0:
					// back
				case 1:
					// showSemester
				case 2:
					// show school year
				defalt:
					break;
				}
			}
		}
		case -1:
			// log out
		/*defalt:
			break;*/
		}
	}
}
void print_Student_Menu() {
	cout << "=======================================" << endl;
	cout << "           WELCOME, STUDENT !             " << endl;
	cout << "Chon cac so sau de tiep tuc : " << endl;
	cout << "0. Xem thong tin tai khoan.  " << endl;
	cout << "1. Xem thong tin sinh vien." << endl;
	cout << "2. Xem thong tin nam hoc. " << endl;
	cout << "3. FOR WHAT??" << endl;
	cout << "-1. Dang xuat. " << endl;
	cout << "Tiep tuc voi : ";
}
void show_Student_Menu() {
	system("CLS");
	int option;
	string temp;
	print_Student_Menu();
	cin >> option;
	getline(cin, temp);
	system("CLS");
	while (!option) {
		switch (option) {
		case 0: {
			// show user account
			break;
		}
		case 1: {
			// show student's profile
			print_schoolyearinfor();
			int option1;
			string temp1;
			cin >> option1;
			getline(cin, temp1);
			system("CLS");
			while (!option1) {
				switch (option1) {
				case 1:
				{
					cout << "===============" << endl;
					cout << "     Chon hoc ki:   " << endl;
					cout << "0. Quay lai. " << endl;
					cout << "1" << endl;
					cout << "2" << endl;
					cout << "3" << endl;
					cout << "Lua chon cua ban :" << endl;
					int option2;
					string temp2;
					cin >> option2;
					getline(cin, temp2);
					system("CLS");
					// check semester after do:

				}
				case 2: 
					// 


					/*defalt:
						break;*/
				}
			}
		}
		case -1:
			// log out
		/*defalt:
			break;*/
		}
	}
}
