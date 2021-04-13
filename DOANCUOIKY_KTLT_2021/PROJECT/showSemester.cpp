#include "stdafx.h"
#include "showSemester.h"

void print_SemesterMenu_ofStudent() {
	cout << "Nhap 0 de quay lai. " << endl;
}
void print_SemesterMenu_ofStaff() {
	print_SemesterMenu_ofStudent();
	cout << "Nhap 1 de chinh sua thoi gian. " << endl;
	
}
void showSemester_forStaff(Semester *pSemester) {
	// truyền pSemester = học kì muốn truy cập
	// chắc là có data c sẽ làm hàm này sauuu =))))))))
	cout << "===================================" << endl;
	cout << "Hoc ki " << pSemester->no << ": " << endl;
	cout << "Thoi gian bat dau : " << pSemester->begin_date << "/" << pSemester->begin_month << "/" << pSemester->begin_year << endl;
	cout << "Thoi gian ket thuc: " << pSemester->end_date << "/" << pSemester->end_month << "/" << pSemester->end_year << endl;
	print_SemesterMenu_ofStaff();
	cout<<"================================" << endl;
	cout << "Lua chon cua ban: ";
	int option;
	cin >> option;
	switch (option) {
	case 0:
		// back
	case 1:
		editSemester(pSemester);
	}
}
void showSemester_forStudent(Semester *pSemester) {
	cout << "===================================" << endl;
	cout << "Hoc ki " << pSemester->no << ": " << endl;
	cout << "Thoi gian bat dau : " << pSemester->begin_date << "/" << pSemester->begin_month << "/" << pSemester->begin_year << endl;
	cout << "Thoi gian ket thuc: " << pSemester->end_date << "/" << pSemester->end_month << "/" << pSemester->end_year << endl;
	print_SemesterMenu_ofStudent();
	cout << "======================================" << endl;
	// back
}
void editSemester(Semester *pSemester) {
	pSemester = nullptr;
	cout << "Nhap 0 de quay lai" << endl;
	cout << "Nhap 1 de tiep tuc ";
	int option;
	switch (option) {
	case 0:
		showSemester_forStaff(pSemester);
		break;
	case 1:
		cout << "Nhap hoc ki ban muon chinh sua: ";
		cin >> pSemester->no;
		cout << "Nhap lai ngay bat dau (dd/mm/yyyy) : ";
		cin >> pSemester->begin_date >> pSemester->begin_month >> pSemester->begin_year;
		cout << endl;
		cout << "Nhap lai ngay ket thuc (dd/mm/yyyy) : ";
		cin >> pSemester->end_date >> pSemester->end_month >> pSemester->end_year;
		cout << endl;
		break;
	}
	showSemester_forStaff(pSemester);
}