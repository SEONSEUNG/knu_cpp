
// MFC_CalculatorDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_Calculator.h"
#include "MFC_CalculatorDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
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


// CMFCCalculatorDlg 대화 상자



CMFCCalculatorDlg::CMFCCalculatorDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_CALCULATOR_DIALOG, pParent)
	, m_strNum1Edit(_T(""))
	, m_strNum2Edit(_T(""))
	, m_strResultEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCCalculatorDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT_num1, m_strNum1Edit);
	DDX_Text(pDX, IDC_EDIT_num2, m_strNum2Edit);
	DDX_Text(pDX, IDC_EDIT_result, m_strResultEdit);
}

BEGIN_MESSAGE_MAP(CMFCCalculatorDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BTN_clear, &CMFCCalculatorDlg::OnBnClickedBtnclear)
	ON_BN_CLICKED(IDC_BTN_add, &CMFCCalculatorDlg::OnBnClickedBtnadd)
	ON_BN_CLICKED(IDC_BTN_subtract, &CMFCCalculatorDlg::OnBnClickedBtnsubtract)
	ON_BN_CLICKED(IDC_BTN_multiply, &CMFCCalculatorDlg::OnBnClickedBtnmultiply)
	ON_BN_CLICKED(IDC_BTN_divide, &CMFCCalculatorDlg::OnBnClickedBtndivide)
END_MESSAGE_MAP()


// CMFCCalculatorDlg 메시지 처리기

BOOL CMFCCalculatorDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
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

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CMFCCalculatorDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CMFCCalculatorDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCCalculatorDlg::OnBnClickedBtnclear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	m_strNum1Edit = "";
	m_strNum2Edit = "";
	m_strResultEdit = "";

	UpdateData(FALSE);

}

void CMFCCalculatorDlg::OnBnClickedBtnadd()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//to get values from edit;
	UpdateData(TRUE);

	double num1 = _ttof(m_strNum1Edit);
	double num2 = _ttof(m_strNum2Edit);

	double result = num1 + num2;

	m_strResultEdit.Format(_T("%.2f"), result);

	//to update edits;
	UpdateData(FALSE);

}

void CMFCCalculatorDlg::OnBnClickedBtnsubtract()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//to get values from edit;
	UpdateData(TRUE);

	double num1 = _ttof(m_strNum1Edit);
	double num2 = _ttof(m_strNum2Edit);

	double result = num1 - num2;

	m_strResultEdit.Format(_T("%.2f"), result);

	//to update edits;
	UpdateData(FALSE);

}

void CMFCCalculatorDlg::OnBnClickedBtnmultiply()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//to get values from edit;
	UpdateData(TRUE);

	double num1 = _ttof(m_strNum1Edit);
	double num2 = _ttof(m_strNum2Edit);

	double result = num1 * num2;

	m_strResultEdit.Format(_T("%.2f"), result);

	//to update edits;
	UpdateData(FALSE);

}

void CMFCCalculatorDlg::OnBnClickedBtndivide()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	//to get values from edit;
	UpdateData(TRUE);

	double num1 = _ttof(m_strNum1Edit);
	double num2 = _ttof(m_strNum2Edit);

	double result = num1 / num2;

	m_strResultEdit.Format(_T("%.2f"), result);

	//to update edits;
	UpdateData(FALSE);

}
