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
wstring pre_opt;					// ��������ʱ����¼��һ�ΰ��µ���Ч����
double dNum_tmp;					// ��һ�ΰ��Ⱥ�ʱ����¼�Ⱥ�֮ǰ���������
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
}

void Equal(HWND, HWND, HWND, wstring, bool &)
{
}

void hasDot(HWND, HWND, HWND, bool &)
{
}

void Sqrt(HWND, HWND, HWND, bool &)
{
}

void Clear(HWND, HWND, bool &)
{
}
