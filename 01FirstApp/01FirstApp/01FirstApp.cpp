// 01FirstApp.cpp : �������̨Ӧ�ó������ڵ㡣
//

#include "stdafx.h"
#include <windows.h>
#include <iostream>

using namespace std;

int main(int argc, char* argv[])
{
	// ����API����MessageBox
	int nSelect = ::MessageBox(NULL, TEXT("Hello, Windows 10"), TEXT("Greetings"), MB_OKCANCEL);
	if (nSelect == IDOK)
		cout << "�û�ѡ���ˡ�ȷ������ť" << endl;
	else
		cout << "�û�ѡ���ˡ�ȡ������ť" << endl;

	return 0;
}

