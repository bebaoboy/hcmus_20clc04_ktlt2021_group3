#include "stdafx.h"
#include "menu.h"

void print_Staff_Menu() {
	cout << "===========================================" << endl;
	cout << "             WELCOME, TEACHER !             " << endl;
	cout << "0. Back. " << endl;
	cout << "1. View WWHAT????. " << endl;
	cout << "2. View school year infor " << endl;
	cout << "-1. Log out. " << endl;
	cout << "Your option: ";
}
void print_schoolyearinfor() {
	cout << "Enter the following number to continue :" << endl;;
	cout << "0. Back" << endl;
	cout << "1. View semester infor" << endl;
	cout << "2. View ... " << endl;
	cout << "Your option:";
}
void show_Staff_Menu() {
	system("CLS");
	int option;
	string temp;
	print_Staff_Menu();
	cin >> option;
	getline(cin, temp);
	system("CLS");
	while (option != 0) {
		switch (option) {
		case 1: {
			// view profile
		}
		case 2: {
			// view school year infor
			print_schoolyearinfor();
			int option1;
			string temp1;
			cin >> option1;
			getline(cin, temp1);
			system("CLS");
			while (option1 != 0) {
				switch (option1) {
				case 1:
					//
				case 2:
					//
				defalt:
					break;
				}
			}
		}
		case -1:
			// log out
		defalt:
			break;
		}
	}
}
void print_Student_Menu() {
	cout << "=======================================" << endl;
	cout << "           WELCOME, STUDENT !             " << endl;
	cout << "Press the number to continue : " << endl;
	cout << "0. View WHAT? " << endl;
	cout << "1. View student's profile" << endl;
	cout << "2. View school year info" << endl;
	cout << "3. FOR WHAT??" << endl;
	cout << "-1. Log out" << endl;
	cout << "Your option: ";
}
void show_Student_Menu() {
	system("CLS");
	int option;
	string temp;
	print_Student_Menu();
	cin >> option;
	getline(cin, temp);
	system("CLS");
	while (option != -1) {
		switch (option) {
		case 1: {
			// view profile
		}
		case 2: {
			// view school year infor
			print_schoolyearinfor();
			int option1;
			string temp1;
			cin >> option1;
			getline(cin, temp1);
			system("CLS");
			while (option1 != 0) {
				switch (option1) {
				case 1:
					//
				case 2:
					//
				defalt:
					break;
				}
			}
		}
		case -1:
			// log out
		defalt:
			break;
		}
	}
}
