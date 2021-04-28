#include "Header.h"

void print_Staff_Menu();
void print_Student_Menu();

int main() {

	UserAccount* pUser = nullptr;
	SchoolYear* pSchoolYear = nullptr;//main year
	SchoolYear* pSSchoolYear = pSchoolYear;
	Semester* pSemester = nullptr;
	Course* pCourse = nullptr; //main
	Student* pStudent = nullptr;
	Student* pTemp10 = nullptr; //of Student
	CourseEnrollment* pEnroll = nullptr;//main
	CourseEnrollment* pEnroll2 = nullptr;
	extraStudent* pExtra = nullptr;

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

	inputExtraStudent(pExtra);

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
	inputt3.close(); }

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
	while (_ != "-1")
	{
		pSchoolYear = pSSchoolYear;
		//dang nhap
		string user_name = "";
		string user_password = "";
		TextColor(6);
		cout << "========================================================================================================================\n\n";
		gotoXY(35, 3);
		cout << "\tVui long dang nhap de tiep tuc.\n";
		gotoXY(35, 4);
		cout << "Hoac bam - 1 de ket thuc chuong trinh. \n\n";
		cout << "========================================================================================================================\n\n";
		gotoXY(35, 8);
		TextColor(7);
		cout << "\tNhap username: "; cin >> user_name;
		if (user_name == "-1") break;
		gotoXY(35, 9);
		cout << "\tNhap mat khau: "; //cin >> user_password;
		getPassword(user_password);

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
				cout << "\nSai mat khau, nhap lai: ";
				cin >> user_password;
				if (i == 3) {
					int h = 0;
					TextColor(6);
					system("cls");
					cout << "========================================================================================================================\n\n";
					TextColor(7);
					cout << "Quen mat khau?";
					cout << "\nNhap 1 de duoc giup do : ";
					cin >> h;
					cout << "Mat khau cua ban la : " << pCur->user_password << endl;
					TextColor(6);
					cout << "========================================================================================================================\n\n";
				}
				i++;
			}
			system("cls");
			TextColor(6);
			cout << "========================================================================================================================\n\n";
			gotoXY(35, 3);
			cout << "\tDang nhap thanh cong!!\n";
			gotoXY(35, 5);
			TextColor(7);
			cout << "Vui long nhap 0 de tiep tuc : ";
			cin >> option;
			TextColor(7);
			//system("cls");
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
			if (pCurClass == nullptr && pCur == nullptr) {
				cout << "\n========================================================================================================================\n\n";
				gotoXY(35, 15);
				Run("\tKhong tim thay tai khoan!\n\n");
				Sleep(100);
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
					cout << "========================================================================================================================\n\n";
					gotoXY(35, 2);
					cout << "\nQuen mat khau?";
					gotoXY(35, 4);
					cout << "\nNhap 1 de duoc giup do : ";
					cin >> h;
					gotoXY(35, 6);
					cout << "\tMat khau cua ban l a: " << pTemp10->user_password << endl;
					cout << "========================================================================================================================\n\n";
				}
				i++;
			}
			system("cls");
			TextColor(6);
			cout << "========================================================================================================================\n\n";
			gotoXY(35, 4);
			cout << "\tDang nhap thanh cong!\n:";
			gotoXY(35, 6);
			TextColor(7);
			cout << "Vui long nhap 0 de tiep tuc : ";
			cin >> option;
			//system("cls");
			goto student;
		}


	teacher:
		while (option != -1) {
			system("CLS");
			TextColor(6);
			print_Staff_Menu();
			TextColor(7);
			teacherClass(pUser, pClass);
			cin >> option;
			int _ = 0;
			//system("cls");

			if (pSSchoolYear != nullptr) {
				Semester* pTempk = pSSchoolYear->pSemester;
				while (pTempk != nullptr) {
					pTempk->pClass = pClass;
					pTempk = pTempk->pNext;
				}
				pSSchoolYear->pSemester->pCourse = pCourse;
				pSSchoolYear->pSemester->pE = pExtra;
				pSSchoolYear->pSemester->pNext->pCourse = pCourse2;
				pSSchoolYear->pSemester->pNext->pE = pExtra;
				if (pSSchoolYear->pSemester->pNext->pNext != nullptr) {
					pSSchoolYear->pSemester->pNext->pNext->pCourse = pCourse3;
					pSSchoolYear->pSemester->pNext->pNext->pE = pExtra;
				}
					
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
						pEnroll2->status = 1;

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
				TextColor(3);
				showUserAccount(pUser, pCur->user_name);
				break;

			case 1: {
				system("cls");
				// view school year infor
				if (pSSchoolYear == nullptr) {
					TextColor(6);
					cout << "========================================================================================================================\n\n";
					gotoXY(37, 2);
					cout << "\tChua co nam hoc nao!\n";
					gotoXY(30, 7);
					TextColor(7);
					cout << "\tNhap nam hoc thu cong (1) hay tu dong (2) : ";
					cin >> _;
					TextColor(6);
					cout << "========================================================================================================================\n\n";
					if (_ == 2) {
						TextColor(9);
						cout << "\n\tDang nhap thong tin nam hoc . . .\n";
						inputSchoolYear(pSSchoolYear);
						Sleep(1000);
						TextColor(10);
						cout << "\tDang nhap khoa hoc . . .\n";
						Sleep(1000);
						TextColor(11);
						cout << "\tDang nhap lop hoc va sinh vien . . . \n\n";
						Sleep(1000);
						TextColor(6);
						cout << "========================================================================================================================\n\n";
						TextColor(7);
						gotoXY(30, 20);
						cout << "\tNhap thanh cong! Bam -1 de tiep tuc : ";
						cin >> _;
					}
					else {

						TextColor(6);
						gotoXY(35, 12);
						cout << "Chua co nam hoc nao!\n";
						TextColor(7);
						gotoXY(35, 15);
						cout << "Vui long nhap 0 de tao nam hoc : \t";
						cin >> option;
						createSchoolYear(pSchoolYear);
						if (pSSchoolYear == nullptr) pSSchoolYear = pSchoolYear;
					}
					//pSchoolYear = new SchoolYear;
				}
				else {
					//pSSchoolYear = pSchoolYear;
					int option1 = 1;
					system("CLS");

					while (option1 != 0) {
						TextColor(6);
						cout << "========================================================================================================================\n\n";
						gotoXY(35, 3);
						cout << "\tChon cac so sau de tiep tuc :" << endl;
						gotoXY(35, 4);
						cout << "\t0. Quay lai." << endl;
						gotoXY(35, 5);
						cout << "\t1. Xem thong tin hoc ki." << endl;
						gotoXY(35, 6);
						cout << "\t2. Xem thoi gian nam hoc. " << endl;
						gotoXY(35, 7);
						TextColor(7);
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
							TextColor(6);
							gotoXY(35, 3);

							cout << "\n\tChon hoc ky: \n";

							while (pTemp->pNext != nullptr) {
								cout << "\t\tHoc ky " << pTemp->no << endl;
								pTemp = pTemp->pNext;
							}
							cout << "\t\tHoc ky " << pTemp->no << endl;
							cout << "========================================================================================================================\n\n";
							TextColor(7);
							gotoXY(25, 9);
							cout << "\tNhap so tuong ung voi hoc ki de truy cap ( nhap -1 de quay lai ) :\t";
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

								TextColor(6);
								gotoXY(35, 3);
								cout << "=================================\n\n"
									<< "\tNhap so de tiep tuc: \n"
									<< "\t1. Xem thong tin cac lop hoc.\n"
									<< "\t2. Xem thong tin cac khoa hoc.\n"
									<< "\t3. Xem thoi gian hoc ky.\n"
									<< "\t4. Xem phien dang ky hoc phan.\n"
									<< "\tNhap 0 de quay lai.";
								gotoXY(35, 11);
								TextColor(7);
								cout << "Lua chon cua ban : ";
								cin >> option;
								TextColor(11);
								switch (option) {
								case 0:
									system("cls");
									break;
								case 1:
									teacherClass(pUser, pClass);
									showClass(pTemp->pClass, pTemp);
									pSSchoolYear->pSemester->pClass = pTemp->pClass;
									break;
								case 2:
									// TƯƠNG TỰ
									showCourseList(pTemp->pCourse);
									pSSchoolYear->pSemester->pCourse = pTemp->pCourse;
									break;
								case 3:
									// TƯƠNG TỰ
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

									cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai : ";
									cin >> option;
									break;
								}
							}
							if (option == 0) continue;
							pSSchoolYear->pSemester = p;
							break;
						}

						case 2:
							TextColor(3);
							showSchoolYear(pSSchoolYear);
							break;
						default:
							TextColor(4);
							cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai : ";
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
				cout << "\tNhap sai cu phap!\n\tNhap 0 de quay lai : ";
				cin.get();
				break;
			}
			//cin >> option;
			//cout << "\tNhap -1 de tiep tuc.";
			system("cls");
		}
	student:
		while (option != -1) {
			system("CLS");
			pSSchoolYear = pSchoolYear;
			print_Student_Menu();
			cin >> option;
			//system("cls");
			switch (option) {
			case 1:
				//xem thong tin hs
				TextColor(3);
				showStudent(pTemp10);
				cin.get();
				break;
			case 2: {

				int option1 = 1;
				while (option1 != 0) {
					system("CLS");

					TextColor(6);
					cout << "========================================================================================================================\n\n";
					cout << "\tChon cac so sau de tiep tuc :" << endl;;
					cout << "\t0. Quay lai." << endl;
					cout << "\t1. Xem thong tin hoc ki." << endl;
					cout << "\t2. Xem thoi gian nam hoc. " << endl;
					cout << "========================================================================================================================\n\n";
					TextColor(7);
					gotoXY(35, 8);
					cout << "\tTiep tuc voi:";

					cin >> option1;
					if (pSSchoolYear == nullptr) {
						if (option1 == 0) break;
						system("cls");
						gotoXY(35, 3);
						cout << "\n\tChua co du lieu. Vui long quay lai sau!\n\tBam -1 de quay lai.\n";
						cin >> option1;
						//system("cls");
						continue;
					}

					Semester* pTemp = pSSchoolYear->pSemester;
					system("cls");
					switch (option1) {
					case 0:
						// back
						//system("cls");
						break;
					case 1: {
						TextColor(3);
						// showSemester
						int no = 0;

						//Semester* pTemp = pSSchoolYear->pSemester;
						cout << "========================================================================================================================\n\n";
						cout << "\n\tChon hoc ky: \n";

						while (pTemp->pNext != nullptr) {
							cout << "\t\tHoc ky " << pTemp->no << endl;
							pTemp = pTemp->pNext;
						}
						cout << "\t\tHoc ky " << pTemp->no << endl;
						cout << "========================================================================================================================\n\n";
						TextColor(7);
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
							TextColor(6);
							cout << "========================================================================================================================\n\n";
							cout << "\tNhap so de tiep tuc: \n"
								<< "\t1. Xem thong tin lop hoc chu nhiem.\n"
								<< "\t2. Xem thong tin phien dang ky hoc phan.\n"
								<< "\t3. Xem khoa hoc da dang ky trong hoc ky.\n"
								<< "\t4. Xem thoi khoa bieu hoc ky.\n"
								<< "\t5. Xem thoi gian hoc ky.\n"
								<< "\tNhap 0 de quay lai.";
							cout << "\n========================================================================================================================\n\n";
							gotoXY(35, 12);
							TextColor(7);
							cout << "\tTiep tuc voi : ";
							Semester* pSemester = pTemp;
							cin >> option;
							int op = 10;
							switch (option) {
							case 0:
								break;
							case 1:
								TextColor(3);
								showMainClass(pCurClass);
								break;
							case 2:
								TextColor(3);
								for (int i = 0; i < 6; i++)
									for (int j =0; j < 4; j++)
										if (pTemp10->pTable[i].session[j] == "X" && pTemp10->pTable->semester_no != pTemp->pEnroll->semester_no)
										{
											cout << "\n\n\tBan da dang ky hoc phan o mot hoc ky khac. Vui long kiem tra lai.\n\tNhap -1 de quay lai.\n\t";
											cin >> option;
											i = 6;
											break;
										}
										else {
											Enroll(pTemp->pEnroll, pTemp10, pTemp->pCourse);
											i = 6;
											break;
										}
											
								
								break;
							case 3:
								TextColor(3);
								showStudentCourse(pTemp10->pStuCourse, pTemp10);
								break;
							case 4:
								system("cls");
								cout << endl << endl;
								TextColor(3);
								showTimeTable(pTemp10->pTable);
								TextColor(7);
								cout << "\tNhap -1 de quay lai.";
								cin >> op;
								break;
							case 5:
								while (op != 0) {
									system("cls");

									TextColor(3);

									cout << "========================================================================================================================\n\n";
									cout << "\tHoc ki " << pSemester->no << ": " << endl;
									cout << "\tThoi gian bat dau : " << pSemester->begin_date << "/" << pSemester->begin_month << "/" << pSemester->begin_year << endl;
									cout << "\tThoi gian ket thuc: " << pSemester->end_date << "/" << pSemester->end_month << "/" << pSemester->end_year << endl;
									cout << "\tNhap 0 de quay lai : " << endl;
									cin >> op;
									switch (op) {
									case 0:
										// back
										break;
									default:
										gotoXY(35, 8);
										TextColor(7);
										cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai : ";
										cin >> op;
										break;
									}
								}
								break;
							default:
								TextColor(7);
								cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai : ";
								cin >> option;
								break;
							}
						}
						break;
					}

					case 2:
						TextColor(3);

						// show school year
						cout << "========================================================================================================================\n\n";
						cout << "\tNam hoc: ";
						cout << pSSchoolYear->begin_year << " / " << pSSchoolYear->end_year << endl;
						cout << "\tNgay bat dau: " << pTemp->begin_date << "/" << pTemp->begin_month << "/" << pTemp->begin_year << endl;
						while (pTemp->pNext != nullptr)
						{
							pTemp = pTemp->pNext;
						}
						cout << "\tNgay ket thuc: " << pTemp->end_date << "/" << pTemp->end_month << "/" << pTemp->end_year << endl;
						cout << "========================================================================================================================\n\n";
						cout << "\tNhap -1 de quay lai : ";
						cin >> option1;
						break;
					default:
						cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai : ";
						cin >> option1;
						break;
					}
					//system("cls");
				}
				break;
			}
			case -1:
				// log out
				break;
			default:
				cout << "\tNhap sai cu phap!\n\tNhap 0 de quay lai : ";
				cin.get();
				break;
			}
			//cin >> option;
			//cout << "\tNhap -1 de tiep tuc.";
			//system("cls");
		}

		system("CLS");
		TextColor(6);
		cout << "========================================================================================================================\n\n";
		cout << endl;
		cout << endl;
		gotoXY(35, 5);
		cout << "\tDang xuat thanh cong!";
		cout << endl;
		cout << endl;
		cout << "========================================================================================================================\n\n";

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
	TextColor(6);
	gotoXY(35, 1);
	cout << "===========================================" << endl;
	gotoXY(35, 3);
	cout << "             WELCOME, TEACHER !     " << endl << endl;
	TextColor(8);
	gotoXY(35, 4);
	//showTime();
	TextColor(6);
	gotoXY(35, 5);
	cout << "\tChon cac so sau de tiep tuc : " << endl;
	gotoXY(35, 6);
	cout << "\t0. Xem thong tin tai khoan. " << endl;
	gotoXY(35, 7);
	cout << "\t1. Xem thong tin nam hoc. " << endl;
	//gotoXY(35, 8);
	//cout << "\t2. Tao nam hoc moi. " << endl;
	gotoXY(35, 9);
	cout << "\t-1. Dang xuat. " << endl;
	gotoXY(35, 10);
	cout << "===========================================" << endl;
	TextColor(7);
	gotoXY(38, 12);
	cout << "Tiep tuc voi : ";

}
void print_Student_Menu() {
	TextColor(6);
	gotoXY(35, 1);
	cout << "=======================================" << endl;
	gotoXY(35, 3);
	cout << "           WELCOME, STUDENT !             " << endl << endl;
	TextColor(8);
	gotoXY(35, 5);
	//showTime();
	TextColor(6);
	gotoXY(35, 5);
	cout << "\tChon cac so sau de tiep tuc : " << endl;
	gotoXY(35, 6);
	cout << "\t1. Xem thong tin sinh vien." << endl;
	gotoXY(35, 7);
	cout << "\t2. Xem thong tin nam hoc. " << endl;
	gotoXY(35, 8);
	//cout << "\t3. FOR WHAT??" << endl;
	cout << "\t-1. Dang xuat. " << endl;
	gotoXY(35, 9);
	cout << "=======================================" << endl;
	gotoXY(38, 12);
	TextColor(7);
	cout << "Tiep tuc voi : ";
}