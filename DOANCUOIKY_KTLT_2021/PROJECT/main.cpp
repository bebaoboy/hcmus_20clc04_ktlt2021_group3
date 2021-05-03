#include "Header.h"

void print_Staff_Menu();
void print_Student_Menu();

int main() {
	//system("Color F4");
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
	}

	//main program
	string _ = " ";
	while (_ != "-1")
	{
		pSchoolYear = pSSchoolYear;
		//dang nhap
		string user_name = "";
		string user_password = "";
		TextColor(14);
		cout << "========================================================================================================================\n\n";
		gotoXY(35, 3);
		cout << "\tVui long dang nhap de tiep tuc.\n";
		gotoXY(35, 4);
		cout << "Hoac bam - 1 de ket thuc chuong trinh. \n\n";
		cout << "========================================================================================================================\n\n";
		gotoXY(35, 8);
		TextColor(15);
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
			int i = 1;
			cout << endl;
			while (pCur->user_password != user_password) {
				gotoXY(35, i+9);
				cout << "\tSai mat khau, nhap lai: ";
				getPassword(user_password);
				if (i >= 3) {
					int h = 0;
					TextColor(14);
					system("cls");
					cout << "========================================================================================================================\n\n";
					TextColor(15);
					cout << "\n\tQuen mat khau?";
					cout << "\n\tNhap 1 de duoc giup do : ";
					cin >> h;
					cout << "\n\tMat khau cua ban la : " << pCur->user_password << endl;
					cout << "\tNhap -1 de nhap lai : ";
					cin >> h;
					system("cls");
					gotoXY(35, i + 5);
					cout << "\tNhap lai mat khau: ";
					getPassword(user_password);
					//TextColor(14);
					//cout << "========================================================================================================================\n\n";
				}
				i++;
			}
			system("cls");
			TextColor(14);
			cout << "========================================================================================================================\n\n";
			gotoXY(35, 3);
			cout << "\tDang nhap thanh cong!!\n";
			gotoXY(35, 5);
			TextColor(15);
			cout << "Vui long nhap 0 de tiep tuc : ";
			cin >> option;
			TextColor(15);
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
				Run("\n\tKhong tim thay tai khoan!\n\n");
				Sleep(100);
				gotoXY(35, 17);
				system("pause");
				system("cls");
				continue;
			}
			int i = 1;
			cout << endl;
			while (pTemp10->user_password != user_password) {
				gotoXY(35, i + 9);
				cout << "\tSai mat khau, nhap lai: ";
				getPassword(user_password);
				if (i >= 3) {
					int h = 0;
					cout << "========================================================================================================================\n\n";
					TextColor(15);
					gotoXY(35, 2);
					cout << "\n\tQuen mat khau?";
					gotoXY(35, 4);
					cout << "\n\tNhap 1 de duoc giup do : ";
					cin >> h;
					gotoXY(35, 6);
					cout << "\n\tMat khau cua ban la: " << pTemp10->user_password << endl;
					cout << "\tNhap -1 de nhap lai : ";
					cin >> h;
					system("cls");
					gotoXY(35, i + 5);
					cout << "\tNhap lai mat khau: ";
					getPassword(user_password);
					//cout << "========================================================================================================================\n\n";
				}
				i++;
			}
			system("cls");
			TextColor(14);
			cout << "========================================================================================================================\n\n";
			gotoXY(35, 4);
			cout << "\tDang nhap thanh cong!\n:";
			gotoXY(35, 6);
			TextColor(15);
			cout << "Vui long nhap 0 de tiep tuc : ";
			cin >> option;
			//system("cls");
			goto student;
		}


	teacher:
		while (option != -1) {
			system("CLS");
			TextColor(14);
			gPA(pClass);
			print_Staff_Menu();
			TextColor(15);
			teacherClass(pUser, pClass);
			cin >> option;
			int __ = 10;
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

				//input hs vao khoa hoc 
				if (pCourse->pStuInCourse == nullptr) {
					StudentInCourse* pL = pCourse->pStuInCourse;
					Course* pM = pCourse;
					Class* pTT = pClass;
					while (pTT != nullptr)
						if (pTT->class_name == "20CLC04")
							break;
						else
							pTT = pTT->pNext;

					while (pM->course_id != "CSC10006") {
						Student* pO = pTT->pStudent;
						for (int i = 1; i <= 8; i++) {
							srand(time(0));
							pO->num_of_course++;
							toStudentCourse(pO, pM, pSSchoolYear->pSemester->no);
							toStudentInCourse(pM, pO);
							schedule(pM->pTime, pO->pTable);
							pO->pTable->semester_no = pSSchoolYear->pSemester->no;
							pM->num_of_student++;

							pO = pO->pNext;
						}
						pM = pM->pNext;
					}
				}

			}

			switch (option) {
			case 0:
				TextColor(14);
				showUserAccount(pUser, pCur->user_name);
				break;

			case 1: {
				system("cls");
				// view school year infor
				if (pSSchoolYear == nullptr) {
					TextColor(14);
					cout << "========================================================================================================================\n\n";
					gotoXY(37, 2);
					cout << "\tChua co nam hoc nao!\n";
					gotoXY(30, 7);
					TextColor(15);
					cout << "\tNhap nam hoc thu cong (1) hay tu dong (2) : ";
					cin >> _;
					TextColor(14);
					cout << "========================================================================================================================\n\n";
					if (_ == 2) {
						inputSchoolYear(pSSchoolYear);
						cout << endl;
						cout << "========================================================================================================================\n\n";
						cout << endl << endl;
						TextColor(9);
						cout << "\n\t\t\tDang nhap thong tin nam hoc . . .\n";
						Sleep(500);
						TextColor(10);
						cout << "\t\t\tDang nhap khoa hoc . . .\n";
						Sleep(500);
						TextColor(11);
						cout << "\t\t\tDang nhap lop hoc va sinh vien . . . \n\n";
						Sleep(500);
						TextColor(14);
						cout << endl << endl << endl;
						cout << "========================================================================================================================\n\n";
						TextColor(15);
						gotoXY(30, 24);
						cout << "\tNhap thanh cong! Bam -1 de tiep tuc : ";
						cin >> _;
						if (pSchoolYear == nullptr) pSchoolYear = pSSchoolYear;
					}
					else {

						TextColor(14);
						gotoXY(35, 12);
						cout << "Chua co nam hoc nao!\n";
						TextColor(15);
						gotoXY(30, 15);
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
						TextColor(14);
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
						cout << "\t3. Xuat thong tin lop hoc. " << endl;
						gotoXY(35, 9);
						TextColor(15);
						cout << "\tTiep tuc voi: ";
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
							TextColor(14);
							gotoXY(35, 3);

							cout << "\n\tChon hoc ky: \n";

							while (pTemp->pNext != nullptr) {
								cout << "\t\tHoc ky " << pTemp->no << endl;
								pTemp = pTemp->pNext;
							}
							cout << "\t\tHoc ky " << pTemp->no << endl;
							//cout << "========================================================================================================================\n\n";
							TextColor(15);
							gotoXY(25, 9);
							cout << "\tNhap so tuong ung voi hoc ki de truy cap ( nhap -1 de quay lai ): ";
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
								TextColor(14);
								gotoXY(35, 3);
								cout << "=================================\n\n";
								cout << "\t\t\tNhap so de tiep tuc: \n"
									<< "\t\t\t1. Xem thong tin cac lop hoc.\n"
									<< "\t\t\t2. Xem thong tin cac khoa hoc.\n"
									<< "\t\t\t3. Xem thoi gian hoc ky.\n"
									<< "\t\t\t4. Xem phien dang ky hoc phan.\n"
									<< "\n\t\t\tNhap 0 de quay lai.";
								//gotoXY(35, 11);
								TextColor(15);
								cout << "\n\n\t\t\tLua chon cua ban : ";
								cin >> option;
								TextColor(14);
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
							TextColor(14);
							showSchoolYear(pSSchoolYear);
							break;
						case 3:
							exportClass(pClass);
							break;
						default:
							TextColor(14);
							cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai : ";
							cin >> option1;
							break;
						}
						system("cls");
					}
				}
				break;
			}

			//them nam hoc moi - easter egg
			case 2:
				while (__ != 0) {
					system("cls");
					TextColor(14);
					cout << "\n\n\t\t\t\tChon nam hoc (nhap nam bat dau de chon): \n\n";
					SchoolYear* pY = pSchoolYear;
					while (pY != nullptr) {
						cout << "\t\t\t\t\t" << pY->begin_year << " - " << pY->end_year << endl;
						pY = pY->pNext;
					}
					cout << "\n\n\t\t\t\tNhap -1 de tao nam hoc moi.\n";
					cout << "\t\t\t\tNhap 0 de quay lai.\n\t\t\t\t";
					pY = pSchoolYear;
					cin >> __;
					switch (__) {
					case 0: 
						break;
					case -1:
						system("cls");
						TextColor(15);
						gotoXY(30, 7);
						cout << "\n\n\t\t\tNhap nam hoc thu cong (1) hay tu dong (2) : ";
						cin >> __;
						if (__ == 2) {
							//cout << "\n\n========================================================================================================================\n\n";
							if (pY == nullptr)
							{
							}
							else {
								while (pY->pNext != nullptr)
									pY = pY->pNext;
							}
							inputSchoolYear(pY);
							cout << endl;
							cout << "========================================================================================================================\n\n";
							cout << endl << endl;
							TextColor(9);
							cout << "\n\t\t\tDang nhap thong tin nam hoc . . .\n";
							Sleep(500);
							TextColor(10);
							cout << "\t\t\tDang nhap khoa hoc . . .\n";
							Sleep(500);
							TextColor(11);
							cout << "\t\t\tDang nhap lop hoc va sinh vien . . . \n\n";
							Sleep(500);
							TextColor(14);
							cout << endl << endl << endl;
							cout << "========================================================================================================================\n\n";
							TextColor(15);
							gotoXY(30, 20);
							cout << "\tNhap thanh cong! Bam -1 de tiep tuc : ";
							cin >> __;

						}
						else {
						TextColor(14);
						createSchoolYear(pSchoolYear);
						}
						break;
					default:
						while (pY != nullptr) {
							if (pY->begin_year == __)
								break;
							else
								pY = pY->pNext;
							
						}
						if (pY == pSSchoolYear) {
							__ = 0;
							break;
						}
						else {
							pSSchoolYear = pY;
							goto teacher;
						}
						break;
					}
				}
				break;

			case -1:
				// log out
				break;
			default:
				cout << "\tNhap sai cu phap!\n\tNhap 0 de quay lai : ";
				cin.get();
				break;
			}
			system("cls");
		}
	student:
		while (option != -1) {
			system("CLS");
			//pSSchoolYear = pSchoolYear;
			gPA(pClass);
			print_Student_Menu();
			cin >> option;
			//system("cls");
			switch (option) {
			case 1:
				//xem thong tin hs
				TextColor(14);
				//showStudent(pTemp10);
				{
					int o = 10;
					Student* pStudent = pTemp10;
					while (o != 0) {
						system("cls");
						if (pStudent == nullptr) {
							cout << "\n\n\tKhong co hoc sinh nay!\n\tNhap 0 de quay lai : ";
							cin >> o;
							break;
						}
						cout << "\t\t\t\t=====================================\n\n"
							<< "\tUsername: " << pStudent->user_name
							<< "\n\tPassword: Bam 1 de xem"
							<< "\n\tFull name: " << pStudent->full_name
							<< "\n\tMSSV: " << pStudent->id
							<< "\n\tGioi tinh: " << ((pStudent->gender == 'M') ? "Nam" : "Nu")
							<< "\n\tNgay sinh: " << pStudent->dob << "/" << pStudent->mob << "/" << pStudent->yob
							//<< "\n\tSocial ID: " 
							<< "\n\tGPA_10: " << pStudent->GPA_10
							<< "\n\tGPA: " << pStudent->GPA
							<< "\n\tGrade: " << pStudent->grade
							<< "\n\tLop chu nhiem: " << pStudent->mainclass << endl;
						//cout << "\tNhap 2 de xem danh sach hoc phan da dang ky." << endl;
						cout << "\tNhap 3 de xem thoi khoa bieu." << endl;
						cout << "\tNhap 4 de xem bang diem hoc ky." << endl;
						cout << "\tNhap 5 de chinh sua thong tin." << endl;
						cout << "\tNhap 0 de quay lai.";
						cout << "\n\t\t\t\t=====================================\n\n";
						cout << "\n\t\t\t\tTiep tuc voi : ";
						cin >> o;
						system("cls");
						switch (o) {
						case 1:
							gotoXY(35, 3);
							cout << "==================================\n\n"
								<< "\t\tMat khau la: " << pStudent->user_password << endl;
							cout << "\tNhap -1 de quay lai: ";
							cin >> o;
							system("cls");
							break;
						case 5:
							editStudent(pStudent);
							break;
						case 0:
							break;
						/*case 2:
							showStudentCourse(pStudent->pStuCourse, pStudent);
							system("cls");
							break;*/
						case 3:
							cout << endl;
							showTimeTable(pStudent->pTable);
							cout << "\n\tNhap -1 de quay lai : ";
							cin >> o;
							system("cls");
							break;
						case 4:
							printStudentScoreboard(pStudent);
							break;
						default:
							cout << "\tNhap sai cu phap\nNhap -1 de tiep tuc : ";
							cin >> o;
							break;
						}
					}
				}
				cin.get();
				break;
			case 2: {
				TextColor(14);
				int option1 = 1;
				while (option1 != 0) {
					system("CLS");

					TextColor(14);
					cout << "========================================================================================================================\n\n";
					cout << "\tChon cac so sau de tiep tuc :" << endl;;
					cout << "\t0. Quay lai." << endl;
					cout << "\t1. Xem thong tin hoc ki." << endl;
					cout << "\t2. Xem thoi gian nam hoc. " << endl;
					cout << "========================================================================================================================\n\n";
					TextColor(15);
					gotoXY(35, 8);
					cout << "\tTiep tuc voi:";

					cin >> option1;
					if (pSSchoolYear == nullptr) {
						if (option1 == 0) break;
						system("cls");
						gotoXY(35, 3);
						TextColor(15);
						cout << "\n\tChua co du lieu. Vui long quay lai sau!\n\tBam -1 de quay lai : \n";
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
						//TextColor(11);
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
						TextColor(15);
						cout << "\tNhap -1 de quay lai : ";
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
							TextColor(14);
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
							TextColor(15);
							cout << "\tTiep tuc voi : ";
							Semester* pSemester = pTemp;
							cin >> option;
							int op = 10;
							switch (option) {
							case 0:
								break;
							case 1:
								TextColor(14);
								showMainClass(pCurClass);
								break;
							case 2:
								TextColor(14);
								for (int i = 0; i < 6; i++)
									for (int j = 0; j < 4; j++)
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
								TextColor(14);
								{
									system("cls");
									StudentCourse* p = pTemp10->pStuCourse;
									StudentCourse* pC = pTemp10->pStuCourse;

									int o3 = 10;
									int o = 10, o2 = 10;
									while (o != 0) {
										p = pTemp10->pStuCourse;
										system("cls");
										gotoXY(35, 3);
										cout << "====================================\n\n"
											<< "\tDanh sach khoa hoc da dang ky (Bam so de xem): \n\n";
										int i = 0;
										if (p == nullptr) {
											cout << "\n\n\tKhong co khoa hoc nao! Nhap 0 de quay lai : ";
											cin >> o;
											break;
										}
										while (p != nullptr) {
											cout << "\t" << i + 1 << ". " << "(HK" << p->semester_no << ") " << p->course_name << endl;
											p = p->pNext;
											i++;
										}

										p = pTemp10->pStuCourse;
										StudentInCourse* pSIC = pC->pCourse->pStuInCourse;
										StudentCourse* pTemp2 = pTemp10->pStuCourse;
										int t = 0;
										cout << "\tNhap -1 + so thu tu de huy dang ky khoa hoc.\n";
										//cout << "\tNhap -2 de xem bang diem hoc sinh theo tung mon.\n";
										cout << "\tNhap 0 de quay lai.\n\t";
										cout << "Tiep tuc voi : ";
										cin >> o;
										switch (o) {
										case 0:
											break;
										case -1:
											//xoa
											cin >> t;
											removeRegCourse1(pTemp10, t);
											pTemp10->num_of_course--;
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
													pC = pTemp10->pStuCourse;
													for (int j = 1; j < o; j++)
														pC = pC->pNext;
													gotoXY(35, 3);
													cout << "================================\n\n";
													cout << "\tTen khoa hoc: " << pC->course_name << endl
														<< "\tMa hoc phan: " << pC->course_id << endl
														<< "\tTen GVLT: " << pC->course_teacher << endl
														<< "\tSo tin chi: " << pC->num_of_credit << endl;
													showTimeTable(pC->pTime);
													cout << "\n\tGPA: " << pC->GPA
														<< "\n\tDiem tong: " << pC->total_mark
														<< "\n\tFinal: " << pC->final_mark
														<< "\n\tMidterm: " << pC->midterm_mark;

													cout << "\n\tNhap 1 de xem danh sach hoc sinh cua hoc phan.";
													
													cout << "\n\tNhap 0 de quay lai.";
													cout << "\n\tTiep tuc voi : ";
													cin >> o2;
													StudentInCourse* pL = pC->pCourse->pStuInCourse;
													switch (o2) {
													case 0:
														break;
													case 1:
														while (o3 != 0) {
															system("cls");
															pSIC = pC->pCourse->pStuInCourse;
															gotoXY(35, 3);
															cout << "===================================\n\n";
															gotoXY(35, 5);
															cout << "\tDanh sach hoc sinh da dang ky: \n\n";
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
																cout << "\tNhap sai cu phap, nhap -1 de quay lai : ";
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
								break;
							case 4:
								system("cls");
								cout << endl << endl;
								TextColor(11);
								showTimeTable(pTemp10->pTable);
								TextColor(14);
								cout << "\tNhap -1 de quay lai : ";
								cin >> op;
								break;
							case 5:
								while (op != 0) {
									system("cls");

									TextColor(14);

									cout << "========================================================================================================================\n\n";
									cout << "\tHoc ki " << pSemester->no << ": " << endl;
									cout << "\tThoi gian bat dau : " << pSemester->begin_date << "/" << pSemester->begin_month << "/" << pSemester->begin_year << endl;
									cout << "\tThoi gian ket thuc: " << pSemester->end_date << "/" << pSemester->end_month << "/" << pSemester->end_year << endl;
									TextColor(15);
									cout << "\tNhap 0 de quay lai : " << endl;
									cin >> op;
									switch (op) {
									case 0:
										// back
										break;
									default:
										gotoXY(35, 8);
										TextColor(15);
										cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai : ";
										cin >> op;
										break;
									}
								}
								break;
							default:
								TextColor(15);
								cout << "\tNhap sai cu phap!\n\tNhap -1 de quay lai : ";
								cin >> option;
								break;
							}
						}
						break;
					}

					case 2:
						TextColor(11);

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
						TextColor(15);
						cout << "\tNhap -1 de quay lai : ";
						cin >> option1;
						break;
					default:
						TextColor(15);
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
		TextColor(14);
		cout << "========================================================================================================================\n\n";
		cout << endl;
		cout << endl;
		gotoXY(35, 5);
		cout << "\tDang xuat thanh cong!";
		cout << endl;
		cout << endl;
		cout << "========================================================================================================================\n\n";
		//cout << "\t\t";
		gotoXY(35, 10);
		system("pause");
		system("cls");
	}

	//ham delete 
	while (pSchoolYear != nullptr) {
		SchoolYear* pSSS = pSchoolYear;
		pSchoolYear = pSchoolYear->pNext;
		deleteSchoolYear(pSSS);
	}

	gotoXY(35, 11);
	cout << "Chuong trinh ket thuc!!!";

	system("cls");
	gotoXY(35, 13);
	system("pause");
	return 0;
}

void print_Staff_Menu() {
	TextColor(14);
	gotoXY(35, 1);
	cout << "===========================================" << endl;
	gotoXY(35, 3);
	cout << "             WELCOME, TEACHER !     " << endl << endl;
	TextColor(8);
	gotoXY(35, 4);
	//showTime();
	TextColor(14);
	gotoXY(35, 5);
	cout << "\tChon cac so sau de tiep tuc : " << endl;
	gotoXY(35, 6);
	cout << "\t0. Xem thong tin tai khoan. " << endl;
	gotoXY(35, 7);
	cout << "\t1. Xem thong tin nam hoc. " << endl;
	//gotoXY(35, 8);
	//cout << "\t2. Chuyen nam hoc. " << endl;
	gotoXY(35, 9);
	cout << "\t-1. Dang xuat. " << endl;
	gotoXY(35, 10);
	cout << "===========================================" << endl;
	TextColor(15);
	gotoXY(38, 12);
	cout << "Tiep tuc voi : ";

}
void print_Student_Menu() {
	TextColor(14);
	gotoXY(35, 1);
	cout << "=======================================" << endl;
	gotoXY(35, 3);
	cout << "           WELCOME, STUDENT !             " << endl << endl;
	TextColor(8);
	gotoXY(35, 5);
	//showTime();
	TextColor(14);
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
	TextColor(15);
	cout << "Tiep tuc voi : ";
}
