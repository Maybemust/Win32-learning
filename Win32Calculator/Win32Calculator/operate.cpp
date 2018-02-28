#include "stdafx.h"
#include "operate.h"

void ShowMainScreen(HWND);
void ShowSubScreen(HWND);


// ״̬ת�Ʊ�־
bool isNum = true;				// false��ʾ֮ǰ���������״̬��true��ʾ֮ǰ��������״̬
bool isDot = false;				// false��ʾ֮ǰ��С��״̬��true��ʾ֮ǰС��״̬
bool isSqrt = false;			// false��ʾ֮ǰδ���¸���״̬��true��ʾ֮ǰ���¸���״̬

double dNum1 = 0.0;				// ��������
double dNum2 = 0.0;				// ������
wstring operators;				// ��¼����
WCHAR tmp[256];					// ��¼����Ļ�ϵ�ֵ���м�ֵ��
wstring mainText;				// ��¼����Ļ�ϵ�ֵ
wstring record;					// ��¼��ʽ
wstring record_tmp;				// ��¼��Ч���ż���ǰ����ʽ
int cnt = 0;					// ������Ч���������
wstring pre_opt;				// ��������ʱ����¼��һ�ΰ��µ���Ч����
double dNum_tmp;				// ��һ�ΰ��Ⱥ�ʱ����¼�Ⱥ�֮ǰ���������
int cntEqual = 0;				// ��¼�����ȺŴ���

void Number(HWND hwnd, HWND screen_hwnd_main, HWND screen_hwnd_sub, wstring num, wstring opt, bool &isEqual)
{
	// ���������¶�λ����������
	SetFocus(hwnd);
	// �����ȺŴ�������
	cntEqual = 0;
	// ��¼ǰ����Ч�����
	pre_opt = opt;
	// �Ⱥż����ֱ���������֣������
	if (isEqual == true)
	{
		Clear(screen_hwnd_main, screen_hwnd_sub, isEqual);
	}
	// ��ȡ����Ļ�ϵ�����
	GetWindowText(screen_hwnd_main, tmp, 256);
	wstringstream buffer;
	buffer << tmp;
	buffer >> mainText;
	buffer.clear();

	// isNum��false��ǰһ�����������ֱ���滻��ǰ��Ļ�е�����
	if (isNum == false)	
	{
		wstringstream buffer;
		buffer << num;
		buffer >> tmp;
		buffer.clear();
		SetWindowText(screen_hwnd_main, tmp);
	}
	else
	{
		// �ж�ǰ��0�����ǣ�ֱ���滻��ǰ��Ļ�е�����
		if (mainText.length() == 1 && mainText[0] == '0')
		{
			wstringstream buffer;
			buffer << num;
			buffer >> tmp;
			buffer.clear();
			SetWindowText(screen_hwnd_main, tmp);
		}
		else if (mainText.length() < 11)
		{
			if (isSqrt == false)
			{
				mainText += num[0];
			}
			else
			{
				record = record_tmp;
				mainText = num[0];
				ShowSubScreen(screen_hwnd_sub);
			}
			ShowMainScreen(screen_hwnd_main);
		}
	}

	isNum = true;
	isSqrt = false;
}

void Operator(HWND hwnd, HWND screen_hwnd_main, HWND screen_hwnd_sub, wstring opt, bool &isEqual)
{
	// ���������¶�λ����������
	SetFocus(hwnd);
	// �����ȺŴ�������
	cntEqual = 0;
	// ��ȡ����Ļ�ϵ�����
	GetWindowText(screen_hwnd_main, tmp, 256);
	wstringstream buffer;
	buffer << tmp;
	buffer >> mainText;
	buffer.clear();
	// ȥ������Ҫ������ĩβС����
	if (mainText[mainText.length() - 1] == '.')
	{
		mainText.erase(mainText.end() - 1);
		//MessageBox(NULL, mainText.c_str(), TEXT("ȥС����"), MB_OK);
	}
	//MessageBox(NULL, tmp, TEXT("����Ļ�м�ֵ"), MB_OK);
	// ��֮ǰ���еȺż�������������������ţ��������Ϊ������������ʼ��һ�ֵļ���
	if (isEqual == true)
	{
		double dtmp = 0.0;
		buffer << tmp;
		buffer >> dtmp;
		buffer.clear();
		Clear(screen_hwnd_main, screen_hwnd_sub, isEqual);
		ShowMainScreen(screen_hwnd_main);
		dNum1 = dtmp;
	}

	// �����һ����Ч���������������ǰ����Ļ������Ϊ��������
	if (cnt == 0)
	{
		//MessageBox(NULL, NULL, tmp, MB_OK);
		buffer << tmp;
		buffer >> dNum1;
		buffer.clear();
	}

	// isNumΪfalse����ǰһ��Ϊ�������ֱ���滻��ǰ����Ļ�����һλ�����
	if (isNum == false)
	{
		record[record.length() - 1] = opt[0];
		ShowSubScreen(screen_hwnd_sub);
	}
	// isNumΪtrue,��������²���
	// Step 1 ����һ����Ч�������¼����
	// Step 2 record += (mainText + op[0])
	// Step 3 ��������Ч������Ĵ�������1ʱ������ǰһ���Ľ��
	// Step 4 ����ؽ���ֱ�Ž�����Ļ
	else
	{
		//pre_opt = opt;
		//MessageBox(NULL, pre_opt.c_str(), NULL, MB_OK);

		// �������
		if (isSqrt == false)
		{
			record += mainText;
		}
		record += opt[0];

		ShowSubScreen(screen_hwnd_sub);
		if (cnt > 0)
		{
			Equal(hwnd, screen_hwnd_main, screen_hwnd_sub, pre_opt, isEqual);
		}
		cnt++;
	}

	isNum = false;
	isDot = false;
	isSqrt = false;
}

void Equal(HWND hwnd, HWND screen_hwnd_main, HWND screen_hwnd_sub, wstring opt, bool &isEqual)
{
	// ���������¶�λ����������
	SetFocus(hwnd);
	// �����ȺŴ�������
	cntEqual = 0;
	// ��ȡ����Ļ�ϵ�����
	GetWindowText(screen_hwnd_main, tmp, 256);
	wstringstream buffer;
	buffer << tmp;
	buffer >> dNum2;
	buffer.clear();
	
	//MessageBox(NULL, tmp, tmp, MB_OK);

	if (cntEqual == 0)
	{
		dNum_tmp = dNum2;
	}

	if (isEqual == true)
	{
		dNum2 = dNum_tmp;
	}

	// ���м���
	double epsilon = 1e-8;
	switch (opt[0])
	{
	case '+':
		dNum1 += dNum2;
		break;
	case '-':
		dNum1 -= dNum2;
		break;
	case '*':
		dNum1 *= dNum2;
		break;
	case '/':
		if (fabs(dNum2 - 0.0) < epsilon)
		{
			MessageBox(NULL, _T("��������Ϊ0��"), _T("����"), MB_OK | MB_ICONEXCLAMATION);
			Clear(screen_hwnd_main, screen_hwnd_sub, isEqual);
			return;
		}
		dNum1 /= dNum2;
		break;
	case '%':
	{
		if (fabs(dNum2 - 0.0) < epsilon)
		{
			MessageBox(NULL, _T("�޷�������ģ���㣡"), _T("����"), MB_OK | MB_ICONEXCLAMATION);
			Clear(screen_hwnd_main, screen_hwnd_sub, isEqual);
			return;
		}
		int nNum1, nNum2;
		bool isInt_1 = false;
		bool isInt_2 = false;

		// �����ȣ���һ��С���㹻�ӽ�һ������ʱ������Ϊ������������
		if (dNum1 > epsilon && fabs(dNum1 - (int)(dNum1 + 0.5)) < epsilon)
		{
			isInt_1 = true;
			nNum1 = (int)(dNum1 + 0.5);
		}
		if (dNum2 > epsilon && fabs(dNum2 - (int)(dNum2 + 0.5)) < epsilon)
		{
			isInt_2 = true;
			nNum2 = (int)(dNum2 + 0.5);
		}
		if (dNum1 < -1.0 * epsilon && fabs(dNum1 - (int)(dNum1 - 0.5)) < epsilon)
		{
			isInt_1 = true;
			nNum1 = (int)(dNum1 - 0.5);
		}
		if (dNum2 < -1.0 * epsilon && fabs(dNum1 - (int)(dNum1 - 0.5)) < epsilon)
		{
			isInt_2 = true;
			nNum2 = (int)(dNum2 - 0.5);
		}
		if (isInt_1 == true && isInt_2 == true)
		{
			nNum1 %= nNum2;
			dNum1 = nNum1;
		}
		else
		{
			MessageBox(NULL, _T("�޷���0��С����ģ���㣡"), _T("���棡"), MB_OK | MB_ICONEXCLAMATION);
			Clear(screen_hwnd_main, screen_hwnd_sub, isEqual);
			return;
		}
	}
		break;
	default:
		break;
	}

	// ��ʾ���
	// ����Ļ
	if (dNum1 > 1e+308 || dNum1 < -1.0 * 1e+308)
	{
		MessageBox(NULL, _T("�޷����м��㣡"), _T("���棡"), MB_OK | MB_ICONEXCLAMATION);
		Clear(screen_hwnd_main, screen_hwnd_sub, isEqual);
		return;
	}

	buffer << tmp;
	buffer >> mainText;
	buffer.clear();

	// ����������Ⱥŵĸ���Ļ
	if (isEqual == true && cntEqual > 0)
	{
		if (cnt == 0)
		{
			return;
		}
		record.clear();
		record += (mainText + pre_opt);
		buffer << dNum_tmp;
		buffer >> mainText;
		buffer.clear();
		record += (mainText + _T("="));
		ShowSubScreen(screen_hwnd_sub);
	}

	// ��һ�ΰ����ں�ʱ�ĸ���Ļ
	if (isEqual == true && cntEqual == 0)
	{
		if (mainText[mainText.length() - 1] == '.')
		{
			mainText.erase(mainText.end() - 1);
		}
		if (isSqrt == false)
		{
			record += mainText;
		}
		record += _T("=");
		cntEqual++;
	}
	ShowSubScreen(screen_hwnd_sub);

	// ����Ļ
	if (cnt == 0)
	{
		ShowMainScreen(screen_hwnd_main);
		return;
	}
	buffer << setprecision(9) << dNum1;
	buffer >> mainText;
	buffer.clear();
	ShowMainScreen(screen_hwnd_main);
}

void Dot(HWND hwnd, HWND screen_hwnd_main, HWND screen_hwnd_sub, bool &isEqual)
{
	// ����������������
	SetFocus(hwnd);

	if (isDot == true)
	{
		return;
	}
	else
	{
		wstringstream buffer;

		// ���ղŰ��µȺź�С����
		if (isEqual == true)
		{
			Clear(screen_hwnd_main, screen_hwnd_sub, isEqual);
		}
		// ��ȡ����Ļ�ϵ�����
		GetWindowText(screen_hwnd_main, tmp, 256);
		buffer << tmp;
		buffer >> mainText;
		buffer.clear();
		// �������µ��������ղ�Ϊδȷ���ĸ��ż�������ղ���Ϊ0
		if (isNum == false || isSqrt == true)
		{
			if (isSqrt == true)
			{
				record = record_tmp;
				ShowSubScreen(screen_hwnd_sub);
			}
			mainText = _T("0");
		}
		if (mainText.length() < 11)
		{
			mainText += _T(".");
		}
		ShowMainScreen(screen_hwnd_main);
	}
	isDot = true;
	isNum = true;
	isSqrt = false;
}

void Sqrt(HWND hwnd, HWND screen_hwnd_main, HWND screen_hwnd_sub, bool &isEqual)
{
	SetFocus(hwnd);

	if (isSqrt == false)
	{
		record_tmp = record;
	}

	GetWindowText(screen_hwnd_main, tmp, 256);
	wstringstream buffer;
	buffer << tmp;
	buffer >> dNum2;
	buffer.clear();

	if (dNum2 >= 0.0)
	{
		dNum2 = sqrt(dNum2);
		buffer << dNum2;
		buffer >> mainText;
		buffer.clear();

		if (isSqrt == true)
		{
			record = record_tmp;
		}
		record += _T("��(");
		record += tmp;
		record += _T(")");
	}
	else
	{
		MessageBox(NULL, _T("��Ч���룡"), _T("���棡"), MB_OK | MB_ICONEXCLAMATION);
		mainText = _T("0");
		Clear(screen_hwnd_main, screen_hwnd_sub, isEqual);
		return;
	}

	ShowMainScreen(screen_hwnd_main);
	ShowSubScreen(screen_hwnd_sub);

	isSqrt = true;
	isNum = true;
}

void Clear(HWND screen_hwnd_main, HWND screen_hwnd_sub, bool &isEqual)
{
	isNum = true;
	isDot = false;
	isSqrt = false;
	isEqual = false;
	dNum1 = dNum2 = dNum_tmp = 0.0;
	cnt = cntEqual = 0;
	operators.clear();
	record.clear();
	pre_opt.clear();
	SetWindowText(screen_hwnd_main, _T("0"));
	SetWindowText(screen_hwnd_sub, _T(""));
}

void ShowSubScreen(HWND screen_hwnd_sub)
{
	wstringstream buffer;
	buffer << record;
	buffer >> tmp;
	buffer.clear();
	SetWindowText(screen_hwnd_sub, tmp);
}

void ShowMainScreen(HWND screen_hwnd_main)
{
	wstringstream buffer;
	buffer << mainText;
	buffer >> tmp;
	buffer.clear();
	SetWindowText(screen_hwnd_main, tmp);
}
