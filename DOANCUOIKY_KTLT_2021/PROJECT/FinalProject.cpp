#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct UserAccount {
	string full_name, user_name, user_password, user_class;
	int user_type, option;
	long int id;
		UserAccount* pUser;
};

void userlogin(UserAccount&pUser)
{
	string username01, password01, username02, password02;
	int option;

	ifstream file01;
	file01.open("student.txt", ios::in);
	getline(file01, username01);
	getline(file01, password01);

	ifstream file02;
	file02.open("teacher.txt", ios::in);
	getline(file02, username02);
	getline(file02, password02);

	cout << "\nNhap tai khoan: "; cin >> pUser.user_name;
	cout << "Nhap mat khau: "; cin >> pUser.user_password;

	while (username01 != password01) {
			if (pUser.user_name == username01 && pUser.user_password == password01)
				cout << "Dang nhap thanh cong!" << endl;
			break;
			 if (pUser.user_name != username01 || pUser.user_password != password01)
			{
				cout << "Tai khoan hoac mat khau cua ban da sai! Vui long dang nhap lai!\n";
				cout << "Nhap lai tai khoan: "; cin >> pUser.user_name;
				cout << "Nhap lai mat khau: "; cin >> pUser.user_password;
				cout << "Nhap lop cua ban:"; cin >> pUser.user_class;
			}
			else if (pUser.user_name != username01 && pUser.user_password != password01)
			{
				cout << "\nQuen mat khau?\nBan co muon tao tai khoan moi khong ne?\n";
				cout << "0: Co\n1: Khong";
				cout << " \nNhap so ban chon:"; cin >> option;
				switch (option)
				{
				case 0:
					cout << "\nHay nhap tai khoan moi: "; cin >> pUser.user_name;
					cout << "Hay nhap mat khau moi:"; cin >> pUser.user_password;
					cout << "Nhap lop cua ban:"; cin >> pUser.user_class;
					return;
				case 1:
					break;
				}
			}
	}
	
	while (username02 != password02)
	{
		if (pUser.user_name == username02 && pUser.user_password == password02)
			cout << "Dang nhap thanh cong!" << endl;
		break;
		if (pUser.user_name != username02 || pUser.user_password != password02)
		{
			cout << "Tai khoan hoac mat khau cua ban da sai! Vui long dang nhap lai!\n";
			cout << "Nhap lai tai khoan: "; cin >> pUser.user_name;
			cout << "Nhap lai mat khau: "; cin >> pUser.user_password;
		}
		else if (pUser.user_name != username02 && pUser.user_password != password02)
		{
			cout << "\nQuen mat khau?\nBan co muon tao tai khoan moi khong ne?\n";
			cout << "0: Co\n1: Khong";
			cout << " \nNhap so ban chon:"; cin >> option;
			switch (option)
			{
			case 0:
				cout << "\nHay nhap tai khoan moi: "; cin >> pUser.user_name;
				cout << "Hay nhap mat khau moi:"; cin >> pUser.user_password;
				return;
			case 1:
				break;
			}
		}
	}
}

int main()
{
	UserAccount pUser;

	cout << "=======================================================\n";
	cout << "  Chao Mung Ban Den Voi He Thong Dang Ky Hoc Phan!\n";
	
	int choice;
	cout << "Nhap 0 de thoat chuong trinh\n";
	cout << "Nhap 1 de tao tai khoan moi\n";
	cout << "Nhap 2 de nhap tai khoan\n";
	cout << "\nNhap so ban chon: "; cin >> choice;
	switch (choice)
	{
	case 0:
		cout << "===================================================\n";
		cout << "  Dang xuat thanh cong!\n  Hen gap lai!\n";
		cout << "===================================================\n";
		break;
	case 1:
		int x;
		cout << "\nNhap so 1 neu ban la sinh vien\n";
		cout << "Nhap so 2 neu ban la giao vien\n";
		cout << "Nhap so ban chon: "; cin >> x;

		cout << "\nHay nhap tai khoan moi: "; cin >> pUser.user_name;
		cout << "Hay nhap mat khau moi:"; cin >> pUser.user_password;
		if (x == 1)
		{
			cout << "Nhap lop cua ban: "; cin >> pUser.user_class;
			cout << "Welcome sinh vien " << pUser.user_name << " - " << pUser.user_class << endl;
		}
		else
		{
			cout << "Welcome giao vien " << pUser.user_name << "!" << endl;
		}
	case 2:
		int user_type;
		cout << "\nNhap so 1 neu ban la sinh vien\n";
		cout << "Nhap so 2 neu ban la giao vien\n";
		cout << "Nhap so ban chon: "; cin >> user_type;
		switch (user_type)
		{
		case 1://student
			userlogin(pUser);
			cout << "Nhap lop cua ban:"; cin >> pUser.user_class;
			cout << "=======================================================\n";
			cout << " Welcome sinh vien " << pUser.user_name << " - " << pUser.user_class << endl;
			cout << " Xem cac so sau de tiep tuc:\n";
			int option1;
			cout << " 0 de xem thong tin tai khoan\n";
			cout << " 1 de xem thong tin sinh vien\n";
			cout << " 2 de xem thong tin nam hoc\n";
			cout << " -1 de dang xuat";
			cout << "\nNhap so ban chon: "; cin >> option1;
			switch (option1)
			{
			case 0:
				cout << " Thong tin tai khoan:\n ";
			case 1:
				cout << " Thong tin sinh vien\n";
			case 2:
				cout << " Thong tin nam hoc\n";
			case -1:
				cout << " Ban da dang xuat thanh cong!\n";
			}
			cout << "=======================================================\n";

		case 2://teacher
			userlogin(pUser);
			cout << "=======================================================\n";
			cout << " Welcome teacher " << pUser.user_name << "!" << endl;
			cout << " Xem cac so sau de tiep tuc:\n";

			int option2;
			cout << " 0 de xem thong tin tai khoan\n";
			cout << " 1 de xem thong tin nam hoc\n";
			cout << " -1 de dang xuat";
			cout << "\nNhap so ban chon: "; cin >> option2;
			switch (option2)
			{
			case 0:
				cout << " Thong tin tai khoan:\n ";
			case 1:
				cout << " Thong tin nam hoc\n";
			case -1:
				cout << " Ban da dang xuat thanh cong!\n";
			}
			cout << "=======================================================";
		}
	}

	ofstream file01;
	file01.open("student.txt",ios::out);
	file01.close();
	
	ofstream file02;
	file02.open("teacher.txt",ios::out);
	file02.close();

	system("pause");
	return 0;
}
