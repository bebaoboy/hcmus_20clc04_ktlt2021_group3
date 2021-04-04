#include "Header.h"
#include "struct.h"

void removeAccount(UserAccount*& pUser, string user_name) {
	UserAccount* pCur = pUser, *pPre = nullptr;
	while (pCur->user_name != user_name && pCur != nullptr) {
		pPre = pCur;
		pCur = pCur->pNext;
	}
	if (pCur->user_name == user_name) {
		pPre->pNext = pCur->pNext;
		delete pCur;
	}
	else return;
}
void changeUserPassword(string& user_password) {
	string temp_password1, temp_password2, old_password;
	cin.ignore();
	cout << "=====================================\n\n"
		<< "\tNhap password cu: ";
	getline(cin, old_password);
	while (old_password != user_password) {
		cout << "\tSai mat khau cu. Vui long nhap lai: ";
		getline(cin, old_password);
	}
	system("cls");

	cout << "=====================================\n\n"
		<< "\tNhap password moi: ";
	getline(cin, temp_password1);
	cout << "\tNhap lai password moi: ";
	getline(cin, temp_password2);

	while (temp_password1 != temp_password2) {
		cout << "\tPassword moi khong trung khop. Vui long nhap lai: ";
		getline(cin, temp_password2);
	}
	user_password = temp_password2;
	system("cls");

	cout << "==================================\n\n"
		<< "\tDoi mat khau thanh cong!\n\tBam -1 de quay lai!\n"
		<< "===================================\n";
	cin.get();
}
bool checkUserName(UserAccount* pUser, string user_name) {
	int count = 0;
	while (pUser != nullptr) {
		if (pUser->user_name == user_name)
			count++;
		else
			pUser = pUser->pNext;
		if (count == 2)
			return 0;
	}
	return 1;
}
void showUserAccount(UserAccount* pUser, string user_name) {
	UserAccount* pB = pUser;
	int opt = 10;
	while (pUser != nullptr) {
		if (pUser->user_name == user_name) break;
		else {
			pUser = pUser->pNext;
		}
	}
	while (opt != 0) {
		cout << "=============================\n\n"
			<< "\tUsername: " << pUser->user_name
			<< "\n\tFullname: " << pUser->full_name
			<< "\n\tLop chu nhiem: " << pUser->user_class
			<< "\n\tPassword: Nhap 3 de xem\n\tNhap 1 de doi password."
			<< "\n\tNhap 2 de thay doi thong tin!"
			<< "\n\tNhap 4 de xoa tai khoan."
			<< "\n\tNhap 0 de quay lai.";

		cin >> opt;
		system("cls");
		switch (opt) {
		case 1:
			changeUserPassword(pUser->user_password);
			break;
		case 2:
			editUserAccount(pB, pUser->user_name);
			break;
		case 3:
			system("cls");
			cout << "================================\n\n"
				<< "\tPassword: " << pUser->user_password
				<< endl;
			cout << "\tNhap -1 de tiep tuc.";
			cin >> opt;
			break;
		case 4:
			removeAccount(pB, pUser->user_name);
			cout << "================================\n\n"
				<< "\tXoa thanh cong.";
			cout << "\tNhap -1 de tiep tuc.";
			cin >> opt;
			return;
		case 0:
			return;
		default:
			cout << "\tNhap sai cu phap.";
			break;
		}

		system("cls");
	}
}
void editUserAccount(UserAccount* pUser, string user_name) {
	system("cls");
	cin.ignore();

	UserAccount* pB = pUser;
	int opt = 10;
	while (pUser != nullptr) {
		if (pUser->user_name == user_name) break;
		else {
			pUser = pUser->pNext;
		}
	}

	while (opt != -1) {
		cout << "==================================\n\n"
			<< "\tNhap 1 de doi username\n"
			<< "\tNhap 2 de doi fullname\n"
			<< "\tNhap 3 de doi lop chu nhiem\n"
			<< "\tNhap -1 de quay lai.";
		
		string temp;
		cin >> opt;
		cin.ignore();
		switch (opt) {
		case 1:
			cout << "=================================\n\n"
				<< "\tNhap username moi(Nhap 0 de quay lai): ";
			getline(cin, temp);
			if (temp != "0") {
				while (!checkUserName(pB, temp)) {
					cout << "\n\tTen da duoc su dung boi tai khoan khac. Vui long nhap lai:";
					getline(cin, temp);
				}
				pUser->user_name = temp;
				cout << "\tDoi username thanh cong!\n\tNhap 0 de quay lai.";
			}
			break;
		case 2:
			cout << "=================================\n\n"
				<< "\tNhap fullname moi(Nhap 0 de quay lai): ";
			getline(cin, temp);
			if (temp != "0") {
				pUser->full_name = temp;
				cout << "\tDoi fullname thanh cong!\n\tNhap 0 de quay lai.";
			}
			break;
		case 3:
			cout << "=================================\n\n"
				<< "\tNhap lop chu nhiem moi(Nhap 0 de quay lai): ";
			getline(cin, temp);
			if (temp != "0") {
				pUser->user_class = temp;
				cout << "\tDoi lop thanh cong!\n\tNhap 0 de quay lai.";
			}
			break;

		case -1:
			return;
		default:
			cout << "\tNhap sai cu phap.";
			break;

		}
		cout << "\tNhap -1 de tiep tuc.";
		cin >> opt;
		cin.get();
		system("cls");
	}
	
}
