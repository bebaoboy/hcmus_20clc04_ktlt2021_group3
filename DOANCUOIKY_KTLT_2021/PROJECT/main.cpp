#include "Header.h"

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
	pUser->user_type = 2;
	pUser->pNext = new UserAccount;

	pUser->pNext->full_name = "H M Bap";
	pUser->pNext->id = 20127004;
	pUser->pNext->user_class = "20CLC02";
	pUser->pNext->user_name = "bebaoboy2";
	pUser->pNext->user_password = "abcdefgh";
	pUser->pNext->user_type = 2;
	pUser->pNext->pNext = nullptr;

	showUserAccount(pUser, pUser->pNext->user_name);}

	// PHAN 1: DANG NHAP

	cout << "End program" << endl;

	// PHAN 2: CHUONG TRINH

	system("pause");
	return 0;
}
