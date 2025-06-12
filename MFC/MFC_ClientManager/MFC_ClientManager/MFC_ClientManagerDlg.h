
// MFC_ClientManagerDlg.h: 헤더 파일
//


#pragma once
#include "ClientManager.h"


// CMFCClientManagerDlg 대화 상자
class CMFCClientManagerDlg : public CDialogEx
{
// 생성입니다.
public:
	CMFCClientManagerDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFC_CLIENTMANAGER_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	bool m_bIgnoreListSelectionChange; // 리스트 선택 무시 플래그

	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CListCtrl m_listClient;
	ClientManager m_manager;
	afx_msg void OnLvnItemchangedListclient(NMHDR* pNMHDR, LRESULT* pResult);
	CString m_strNumberEdit;
	CString m_strIdEdit;
	CString m_strNameEdit;
	CString m_strSelectedItemEdit;
	afx_msg void OnBnClickedBtnadd();
	int m_nSelectedItem;
	afx_msg void OnBnClickedBtnclear();
	CListCtrl m_listClientVector;
	afx_msg void OnBnClickedBtndelete();
	afx_msg void OnBnClickedBtndisplay();
	afx_msg void OnBnClickedBtnmodify();
	afx_msg void OnEnChangeEditnumber();
	afx_msg void OnLvnItemchangedListvector(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnBnClickedBtninsert();
	afx_msg void OnEnChangeEditname3();
	CString m_strAttendanceEdit;
	CString m_strGradeEdit;
};
