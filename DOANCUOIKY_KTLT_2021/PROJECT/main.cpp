#include "Header.h"

void print_Staff_Menu();
void print_Student_Menu();

int main() {
	system("Color F4");
	UserAccount* pUser = nullptr;
	SchoolYear* pSchoolYear = nullptr;//main year
	SchoolYear* pSSchoolYear = pSchoolYear;
	Semester* pSemester = nullptr;
	Course* pCourse = nullptr; //main
	Student* pStudent = nullptr;
	Student* pTemp10 = nullptr; //of Student
	CourseEnrollment* pEnroll = nullptr;//main
	CourseEnrollment* pEnroll2 = nullptr;

	//ham input sv
	Class* pClass = nullptr; //not main pointer
	Class* pCClass = pClass;
	{ifstream input("Class.txt");
	inputClass(pCClass, input);
	pClass = pCClass;
	ifstream input2("Class2.txt");
	inputClass(pCClass, input2);
	ifstream input3("Class3.txt");
	inputClass(pCClass, input3);
	ifstream input4("Class4.txt");
	inputClass(pCClass, input4);
	ifstream input5("Class5.txt");
	inputClass(pCClass, input5);
	input.close();
	input2.close();
	input3.close();
	input4.close();
	input5.close();
	}

	//ham input Teacher account
	{
		ifstream input("TeacherUser.txt");
		inputTeacher(pUser, input);
		/*pUser = new UserAccount;
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
		pUser->pNext->pNext->pNext = nullptr;*/

		//showUserAccount(pUser, pUser->pNext->user_name);
		input.close();
	}

	Course* pCourse2 = nullptr, * pCourse3 = nullptr;
	//input courses
	{ifstream inputt("Courses.txt");
	inputCourse(pCourse, inputt);
	ifstream inputt2("Courses2.txt");
	inputCourse(pCourse2, inputt2);
	ifstream inputt3("Courses3.txt");
	inputCourse(pCourse3, inputt3);
	inputt.close();
	inputt2.close();
	inputt3.close();}

	//input phien dkhp hk1 (unused)
	{
		/*pEnroll = new CourseEnrollment;
		pEnroll2 = pEnroll;
		pEnroll2->id = "WX00001";
		pEnroll2->start_date = 1;
		pEnroll2->start_month = 5;
		pEnroll2->start_year = 2020;
		pEnroll2->end_date = 1;
		pEnroll2->end_month = 6;
		pEnroll2->end_year = 2020;

		pEnroll2->pNext = new CourseEnrollment;
		pEnroll2 = pEnroll2->pNext;
		pEnroll2->id = "WX00002";
		pEnroll2->start_date = 15;
		pEnroll2->start_month = 5;
		pEnroll2->start_year = 2020;
		pEnroll2->end_date = 20;
		pEnroll2->end_month = 6;
		pEnroll2->end_year = 2020;

		pEnroll2->pNext = new CourseEnrollment;
		pEnroll2 = pEnroll2->pNext;
		pEnroll2->id = "WX00003";
		pEnroll2->start_date = 1;
		pEnroll2->start_month = 5;
		pEnroll2->start_year = 2020;
		pEnroll2->end_date = 1;
		pEnroll2->end_month = 6;
		pEnroll2->end_year = 2020;

		pEnroll2->pNext = nullptr;
		pEnroll2 = pEnroll;*/

	}

	//main program
	string _ = " ";
	while ( _ != "-1")
	{
		pSchoolYear = pSSchoolYear;
	//dang nhap
	string user_name = " ";
	string user_password = " ";

	cout << "=======================================================\n\n"
		<< "\tVui long dang nhap de tiep tuc.\n\tHoac bam -1 de ket thuc chuong trinh: \n\n";
	cout << "\tNhap username: "; cin >> user_name;
	if (user_name == "-1") break;
	cout << "\tNhap mat khau: "; cin >> user_password;

	UserAccount* pCur = pUser; //temporary variables
	Class* pCurClass = pClass;
	int option = 0;

	//tim kiem thong tin gv
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
		while (pCurClass != nullptr) {
			//if (pSchoolYear == nullptr) break;
			pTemp10 = pCurClass->pStudent;
			while (pTemp10 != nullptr) {
				if (pTemp10->id == user_name) break;
				else
					pTemp10 = pTemp10->pNext;
			}
			if (pTemp10 == nullptr) {
				pCurClass = pCurClass->pNext;
			}
			else
				break;
		}
		if (pCurClass == nullptr && pCur==nullptr) {
			cout << "============================\n\n"
				<< "\tKhong tim thay tai khoan!\n\n";
			system("pause");
			system("cls");
			continue;
		}
		int i = 0;
		while (pTemp10->user_password != user_password) {
			cout << "\tSai mat khau, nhap lai: ";
			cin >> user_password;
			if (i == 3) {
				int h = 0;
				cout << "\tQuen mat khau? Nhap 1 de duoc giup do!";
				cin >> h;
				cout << "\tMat khau cua ban la: " << pTemp10->user_password << endl;
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
		int _ = 0;
		system("cls");

		if (pSSchoolYear != nullptr) {
			Semester* pTempk = pSSchoolYear->pSemester;
			while (pTempk != nullptr) {
				pTempk->pClass = pClass;
				pTempk = pTempk->pNext;
			}
			pSSchoolYear->pSemester->pCourse = pCourse;
			pSSchoolYear->pSemester->pNext->pCourse = pCourse2;
			pSSchoolYear->pSemester->pNext->pNext->pCourse = pCourse3;

			Semester* pp = pSSchoolYear->pSemester;
			
			while (pp != nullptr) {
				//phien 1: 1 - 15 tay thang dau tien
				if (pp->pEnroll == nullptr) {
					pEnroll = new CourseEnrollment;
					pEnroll2 = pEnroll;
					pEnroll2->id = "WX00001";
					pEnroll2->start_date = pp->begin_date;
					pEnroll2->start_month = pp->begin_month;
					pEnroll2->start_year = pp->begin_year;
					pEnroll2->end_date = pp->begin_date + 15;
					pEnroll2->end_month = pp->begin_month;
					pEnroll2->end_year = pp->begin_year;
					pEnroll2->pCourse = pp->pCourse;
					pEnroll2->semester_no = pp->no;

					pEnroll2->pNext = new CourseEnrollment;
					pEnroll2 = pEnroll2->pNext;
					pEnroll2->id = "WX00002";
					pEnroll2->start_date = 1;
					pEnroll2->start_month = pp->begin_month + 1;
					pEnroll2->start_year = pp->begin_year;
					pEnroll2->end_date = 20;
					pEnroll2->end_month = pp->begin_month + 1;
					pEnroll2->end_year = pp->begin_year;
					pEnroll2->pCourse = pp->pCourse;
					pEnroll2->semester_no = pp->no;

					pEnroll2->pNext = nullptr;
					pEnroll2 = pEnroll;
					pEnroll = nullptr;

					pp->pEnroll = pEnroll2;
				}
				
				pp = pp->pNext;
			}
			
		}

		switch (option) {
		case 0:
			showUserAccount(pUser, pCur->user_name);
			break;

		case 1: {
			// view school year infor
			if (pSSchoolYear == nullptr) {
				cout << "==============================\n\n"
					<< "\tChua co nam hoc nao!\n"
					<< "\tNhap nam hoc thu cong (1) hay tu dong (2)?";
				cin >> _;
				if (_ == 2) {
					cout << "\n\tDang nhap thong tin nam hoc ...\n";
					inputSchoolYear(pSSchoolYear);
					cout << "\tNhap thanh cong! Bam -1 de tiep tuc\n\t";
					cin >> _;
				}
				else {
					system("cls");
					cout << "\n\n\tChua co nam hoc nao!\n\tVui long nhap 0 de tao nam hoc:\n\n";
					cin >> option;
					createSchoolYear(pSchoolYear);
					if (pSchoolYear == nullptr) pSSchoolYear = pSchoolYear;
				}
				//pSchoolYear = new SchoolYear;
			}
			else {
				//pSSchoolYear = pSchoolYear;
				int option1 = 1;
				system("CLS");
				while (option1 != 0) {
					cout << "==================================\n\n";
					cout << "\tChon cac so sau de tiep tuc :" << endl;;
					cout << "\t0. Quay lai." << endl;
					cout << "\t1. Xem thong tin hoc ki." << endl;
					cout << "\t2. Xem thoi gian nam hoc. " << endl;
					cout << "\tTiep tuc voi:";
					cin >> option1;
					system("cls");
					Semester* p = pSSchoolYear->pSemester;
					switch (option1) {
					case 0:
						// back
						break;
					case 1: {
						// showSemester //bam -1 de quay lai
						//chay list
						int no = 0;
						Semester* pTemp = pSSchoolYear->pSemester;
						cout << "\n\tChon hoc ky: \n";

						while (pTemp->pNext != nullptr) {
							cout << "\t\tHoc ky " << pTemp->no << endl;
							pTemp = pTemp->pNext;
						}
						cout << "\t\tHoc ky " << pTemp->no << endl;
						
						cout << "\tNhap -1 de quay lai\n\t";
						cin >> no;
						if (no == -1) break;

						while (no > pTemp->no) {
							cout << "\tNhap sai hoc ky. Nhap lai: ";
							cin >> no;
						}
						if (no == 0) break;

						pTemp = pSSchoolYear->pSemester;
						while (pTemp != nullptr) {
							if (pTemp->no == no) break;
							else
								pTemp = pTemp->pNext;
						}
						
						//chay list ngpai main	
						int option = 10;
						while (option != 0) {
							system("cls");
							cout << "=================================\n\n"
								<< "\tNhap so de tiep tuc: \n"
								<< "\t1. Xem thong tin cac lop hoc.\n"
								<< "\t2. Xem thong tin cac khoa hoc.\n"
								<< "\t3. Xem thoi gian hoc ky.\n"
								<< "\t4. Xem phien dang ky hoc phan.\n"
								<< "\tNhap 0 de quay lai.";
							cin >> option;
							switch (option) {
							case 0:
								system("cls");
								break;
							case 1:
								showClass(pTemp->pClass, pTemp);
								pSSchoolYear->pSemester->pClass = pTemp->pClass;
								break;
							case 2:
								showCourseList(pTemp->pCourse);
								pSSchoolYear->pSemester->pCourse = pTemp->pCourse;
								break;
							case 3:
								showSemesterTime(pTemp, pSSchoolYear->begin_year);
								break;
							case 4:
								if (pTemp->pEnroll == nullptr) {
									createCourseEnrollment(pTemp->pEnroll, pTemp);
								}
								else {
									showCourseEnrollment(pTemp->pEnroll, pTemp);
								}	
								break;
							default:
								cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
								cin >> option;
								break;
							}
						}
						if (option == 0) continue;
						pSSchoolYear->pSemester = p;
						break;
					}

					case 2:
						showSchoolYear(pSSchoolYear);
						break;
					default:
						cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
						cin >> option1;
						break;
					}
					system("cls");
				}
			}
			break;
		}

		//case 2: tao nam hoc

		case -1:
			// log out
			break;
		default:
			cout << "\tNhap sai cu phap!\n\tNhap 0 de quay lai!";
			cin.get();
			break;
		}
		//cin >> option;
		//cout << "\tNhap -1 de tiep tuc.";
		system("cls");
	}

student:
	while (option != -1) {
		pSSchoolYear = pSchoolYear;
		print_Student_Menu();
		cin >> option;
		system("cls");
		switch (option) {
		case 1:
			//xem thong tin hs
			showStudent(pTemp10);
			cin.get();
			break;
		case 2: {
			system("CLS");
			int option1 = 1;
			while (option1 != 0) {
				cout << "==================================\n\n";
				cout << "\tChon cac so sau de tiep tuc :" << endl;;
				cout << "\t0. Quay lai." << endl;
				cout << "\t1. Xem thong tin hoc ki." << endl;
				cout << "\t2. Xem thoi gian nam hoc. " << endl;
				cout << "\tTiep tuc voi:";

				cin >> option1;
				if (pSSchoolYear == nullptr) {
					if (option1 == 0) break;
					system("cls");
					cout << "\n\tChua co du lieu. Vui long quay lai sau!\n\tBam -1 de quay lai.\n";
					cin >> option1;
					system("cls");
					continue;
				}
				
				Semester* pTemp = pSSchoolYear->pSemester;
				system("cls");
				switch (option1) {
				case 0:
					// back
					system("cls");
					break;
				case 1: {
					// showSemester
					int no = 0;

					//Semester* pTemp = pSSchoolYear->pSemester;
					cout << "\n\tChon hoc ky: \n";

					while (pTemp->pNext != nullptr) {
						cout << "\t\tHoc ky " << pTemp->no << endl;
						pTemp = pTemp->pNext;
					}
					cout << "\t\tHoc ky " << pTemp->no << endl;
					cout << "\tNhap -1 de quay lai\n\t";
					cin >> no;
					if (no == -1) break;

					while (no > pTemp->no) {
						cout << "\tNhap sai hoc ky. Nhap lai: ";
						cin >> no;
						
					}
					if (no == 0) break;
					pTemp = pSSchoolYear->pSemester;
					while (pTemp != nullptr) {
						if (pTemp->no == no) break;
						else
							pTemp = pTemp->pNext;
					}
					
					int option = 10;
					while (option != 0) {
						system("cls");
						cout << "=================================\n\n"
							<< "\tNhap so de tiep tuc: \n"
							<< "\t1. Xem thong tin lop hoc chu nhiem.\n"
							<< "\t2. Xem thong tin phien dang ky hoc phan.\n"
							<< "\t3. Xem khoa hoc da dang ky trong hoc ky.\n"
							<< "\t4. Xem thoi khoa bieu hoc ky.\n"
							<< "\t5. Xem thoi gian hoc ky.\n"
							<< "\tNhap 0 de quay lai.";
						Semester* pSemester = pTemp;
						cin >> option;
						int op = 10;
						switch (option) {
						case 0:
							break;
						case 1:
							showMainClass(pCurClass);
							break;
						case 2:
							Enroll(pTemp->pEnroll, pTemp10, pTemp->pCourse);
							break;
						case 3:
							showStudentCourse(pTemp10->pStuCourse, pTemp10);
							break;
						case 4:
							system("cls");
							cout << endl << endl;
							showTimeTable(pTemp10->pTable);
							cout << "\tNhap -1 de quay lai.";
							cin >> op;
							break;
						case 5:
							while (op != 0) {
								system("cls");
								cout << "===================================\n\n" << endl;
								cout << "\tHoc ki " << pSemester->no << ": " << endl;
								cout << "\tThoi gian bat dau : " << pSemester->begin_date << "/" << pSemester->begin_month << "/" << pSemester->begin_year << endl;
								cout << "\tThoi gian ket thuc: " << pSemester->end_date << "/" << pSemester->end_month << "/" << pSemester->end_year << endl;
								cout << "\tNhap 0 de quay lai." << endl;
								cin >> op;
								switch (op) {
								case 0:
									// back
									break;
								default:
									cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
									cin >> op;
									break;
								}
							}
							break;
						default:
							cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
							cin >> option;
							break;
						}
					}
					break;
				}
					
				case 2:
					// show school year
					cout << "===================================\n\n"
						<< "\tNam hoc: ";
					cout << pSSchoolYear->begin_year << " / " << pSSchoolYear->end_year << endl;
					cout << "\tNgay bat dau: " << pTemp->begin_date << "/" << pTemp->begin_month << "/" << pTemp->begin_year << endl;
					while (pTemp->pNext != nullptr)
					{
						pTemp = pTemp->pNext;
					}
					cout << "\tNgay ket thuc: " << pTemp->end_date << "/" << pTemp->end_month << "/" << pTemp->end_year << endl;
					cout << "\tNhap -1 de quay lai.";
					cin >> option1;
					break;
				default:
					cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai!";
					cin >> option1;
					break;
				}
				system("cls");
			}
			break;
		}
		case -1:
			// log out
			break;
		default:
			cout << "\tNhap sai cu phap!\n\tNhap 0 de quay lai!";
			cin.get();
			break;
		}
		//cin >> option;
		//cout << "\tNhap -1 de tiep tuc.";
		system("cls");
	}

	cout << "===================================\n\n"
		<< "\tDang xuat thanh cong!"
		<< "\n\n===================================="
		<< endl << endl;

	system("pause");
	system("cls");
}
	
	cout << "\n\n\tChuong trinh ket thuc!!!\n\n\n";
	exportClass(pClass);
	//ham delete 
	{
		deleteClass(pClass);
		deleteUser(pUser);
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
	cout << "\t2. Tao nam hoc moi. " << endl;
	cout << "\t-1. Dang xuat. " << endl;
	cout << "\tTiep tuc voi : ";
}
void print_Student_Menu() {
	cout << "=======================================" << endl;
	cout << "           WELCOME, STUDENT !             " << endl;
	cout << "\tChon cac so sau de tiep tuc : " << endl;
	cout << "\t1. Xem thong tin sinh vien." << endl;
	cout << "\t2. Xem thong tin nam hoc. " << endl;
	//cout << "\t3. FOR WHAT??" << endl;
	cout << "\t-1. Dang xuat. " << endl;
	cout << "\tTiep tuc voi : ";
}


