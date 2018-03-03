
// MFCCalculatorDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCCalculator.h"
#include "MFCCalculatorDlg.h"
#include "afxdialogex.h"
#include "operate.h"
#include <mmsystem.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

wstring input_operator;			// ��¼ǰ������������
bool isEqual = false;		// �Ƿ��µȺ�


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CMFCCalculatorDlg �Ի���



CMFCCalculatorDlg::CMFCCalculatorDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_MFCCALCULATOR_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMFCCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_SETFOCUS()
	ON_BN_CLICKED(BTN_ID_0, &CMFCCalculatorDlg::OnBnClickedId0)
	ON_BN_CLICKED(BTN_ID_1, &CMFCCalculatorDlg::OnBnClickedId1)
	ON_BN_CLICKED(BTN_ID_2, &CMFCCalculatorDlg::OnBnClickedId2)
	ON_BN_CLICKED(BTN_ID_3, &CMFCCalculatorDlg::OnBnClickedId3)
	ON_BN_CLICKED(BTN_ID_4, &CMFCCalculatorDlg::OnBnClickedId4)
	ON_BN_CLICKED(BTN_ID_5, &CMFCCalculatorDlg::OnBnClickedId5)
	ON_BN_CLICKED(BTN_ID_6, &CMFCCalculatorDlg::OnBnClickedId6)
	ON_BN_CLICKED(BTN_ID_7, &CMFCCalculatorDlg::OnBnClickedId7)
	ON_BN_CLICKED(BTN_ID_8, &CMFCCalculatorDlg::OnBnClickedId8)
	ON_BN_CLICKED(BTN_ID_9, &CMFCCalculatorDlg::OnBnClickedId9)
	ON_BN_CLICKED(BTN_ID_DOT, &CMFCCalculatorDlg::OnBnClickedIdDot)
	ON_BN_CLICKED(BTN_ID_AC, &CMFCCalculatorDlg::OnBnClickedIdAc)
	ON_BN_CLICKED(BTN_ID_SQRT, &CMFCCalculatorDlg::OnBnClickedIdSqrt)
	ON_BN_CLICKED(BTN_ID_MOD, &CMFCCalculatorDlg::OnBnClickedIdMod)
	ON_BN_CLICKED(BTN_ID_PLUS, &CMFCCalculatorDlg::OnBnClickedIdPlus)
	ON_BN_CLICKED(BTN_ID_MINUS, &CMFCCalculatorDlg::OnBnClickedIdMinus)
	ON_BN_CLICKED(BTN_ID_TIMES, &CMFCCalculatorDlg::OnBnClickedIdTimes)
	ON_BN_CLICKED(BTN_ID_OVER, &CMFCCalculatorDlg::OnBnClickedIdOver)
	ON_BN_CLICKED(BTN_ID_EQUAL, &CMFCCalculatorDlg::OnBnClickedIdEqual)
	ON_COMMAND(IDR_MENU_FILE_EXIT, &CMFCCalculatorDlg::OnMenuFileExit)
END_MESSAGE_MAP()


// CMFCCalculatorDlg ��Ϣ�������

BOOL CMFCCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	CMenu m_Menu;
	m_Menu.LoadMenu(IDR_MENU1);
	SetMenu(&m_Menu);

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������
	CFont *m_Font = new CFont;
	m_Font->CreateFont(80, 35, 0, 0, 100,
		FALSE, FALSE,0, ANSI_CHARSET, OUT_DEFAULT_PRECIS,
		CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, FF_SWISS, _T("Segoe UI Bold"));
	CStatic* screen_hwnd_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_hwnd_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	screen_hwnd_main->SetFont(m_Font);
	screen_hwnd_main->SetWindowText(_T("0"));
	screen_hwnd_sub->SetWindowText(_T(""));

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CMFCCalculatorDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCCalculatorDlg::OnBnClickedId0()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	wstring input = _T("0");
	Number(screen_main, screen_sub, input, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedId1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	wstring input = _T("1");
	Number(screen_main, screen_sub, input, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedId2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	wstring input = _T("2");
	Number(screen_main, screen_sub, input, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedId3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	wstring input = _T("3");
	Number(screen_main, screen_sub, input, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedId4()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	wstring input = _T("4");
	Number(screen_main, screen_sub, input, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedId5()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	wstring input = _T("5");
	Number(screen_main, screen_sub, input, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedId6()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	wstring input = _T("6");
	Number(screen_main, screen_sub, input, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedId7()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	wstring input = _T("7");
	Number(screen_main, screen_sub, input, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedId8()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	wstring input = _T("8");
	Number(screen_main, screen_sub, input, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedId9()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	wstring input = _T("9");
	Number(screen_main, screen_sub, input, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedIdDot()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	Dot(screen_main, screen_sub, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedIdAc()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	input_operator.clear();
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	Clear(screen_main, screen_sub, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedIdSqrt()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	Sqrt(screen_main, screen_sub, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedIdMod()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	input_operator = _T("%");
	Operator(screen_main, screen_sub, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedIdPlus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	input_operator = _T("+");
	Operator(screen_main, screen_sub, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedIdMinus()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	input_operator = _T("-");
	Operator(screen_main, screen_sub, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedIdTimes()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	input_operator = _T("*");
	Operator(screen_main, screen_sub, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedIdOver()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	input_operator = _T("/");
	Operator(screen_main, screen_sub, input_operator, isEqual);
}


void CMFCCalculatorDlg::OnBnClickedIdEqual()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CStatic* screen_main = (CStatic*)GetDlgItem(SCREEN_MAIN);
	CStatic* screen_sub = (CStatic*)GetDlgItem(SCREEN_SUB);
	input_operator = _T("=");
	Operator(screen_main, screen_sub, input_operator, isEqual);
}

void CMFCCalculatorDlg::OnMenuFileExit()
{
	DestroyWindow();
}
