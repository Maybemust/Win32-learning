
// MFCCalculatorDlg.h : ͷ�ļ�
//

#pragma once


// CMFCCalculatorDlg �Ի���
class CMFCCalculatorDlg : public CDialogEx
{
// ����
public:
	CMFCCalculatorDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedId0();
	afx_msg void OnBnClickedId1();
	afx_msg void OnBnClickedId2();
	afx_msg void OnBnClickedId3();
	afx_msg void OnBnClickedId4();
	afx_msg void OnBnClickedId5();
	afx_msg void OnBnClickedId6();
	afx_msg void OnBnClickedId7();
	afx_msg void OnBnClickedId8();
	afx_msg void OnBnClickedId9();
	afx_msg void OnBnClickedIdDot();
	afx_msg void OnBnClickedIdAc();
	afx_msg void OnBnClickedIdSqrt();
	afx_msg void OnBnClickedIdMod();
	afx_msg void OnBnClickedIdPlus();
	afx_msg void OnBnClickedIdMinus();
	afx_msg void OnBnClickedIdTimes();
	afx_msg void OnBnClickedIdOver();
	afx_msg void OnBnClickedIdEqual();
	afx_msg void OnMenuFileExit();
};
