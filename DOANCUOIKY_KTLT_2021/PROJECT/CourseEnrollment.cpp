#include "stdafx.h"
#include "CourseEnrollment.h"

void Edit_CourseRegistrationSession(CourseEnrollment*& pCourseEnrollment) {
	pCourseEnrollment = nullptr;
	cout << "=====================================" << endl;
	cout << "Chinh sua phien dang ki hoc phan ! " << endl;
	cout << "=======================================" << endl;
	int d, m;
	cout << "Vui long nhap lai ngay, thang bat dau ( cach nhau boi space ): ";
	cin >> d >> m;
	int ed, em;
	cout << "Vui long nhap lai ngay thang ket thuc ( cach nhau boi space ) :  ";
	cin >> ed >> em;
	if (pCourseEnrollment == nullptr) {
		pCourseEnrollment = new CourseEnrollment;
		pCourseEnrollment->status = 0;
		pCourseEnrollment->start_date = d;
		pCourseEnrollment->start_month = m;
		pCourseEnrollment->end_date = ed;
		pCourseEnrollment->end_month = em;
		pCourseEnrollment->pCourse = nullptr;
		cout << "Thoi gian bat dau : "<< pCourseEnrollment->start_date << "/" << pCourseEnrollment->start_month<<endl;
		cout << "Thoi gian ket thuc : " << pCourseEnrollment->end_date << "/" << pCourseEnrollment->end_month << endl;
	}
	
	
		
}