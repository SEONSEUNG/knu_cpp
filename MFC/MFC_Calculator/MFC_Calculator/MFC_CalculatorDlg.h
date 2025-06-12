
// MFC_CalculatorDlg.h: 헤더 파일
//

#pragma once


// CMFCCalculatorDlg 대화 상자
class CMFCCalculatorDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCCalculatorDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CALCULATOR_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString m_strNum1Edit;
	CString m_strNum2Edit;
	CString m_strResultEdit;
	afx_msg void OnBnClickedBtnclear();
	afx_msg void OnBnClickedBtnadd();
	afx_msg void OnBnClickedBtnsubtract();
	afx_msg void OnBnClickedBtnmultiply();
	afx_msg void OnBnClickedBtndivide();
};
