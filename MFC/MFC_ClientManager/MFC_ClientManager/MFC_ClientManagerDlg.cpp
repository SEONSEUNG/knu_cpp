
// MFC_ClientManagerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "MFC_ClientManager.h"
#include "MFC_ClientManagerDlg.h"
#include "afxdialogex.h"
#include <atlconv.h>


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


// CMFCClientManagerDlg 대화 상자



CMFCClientManagerDlg::CMFCClientManagerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFC_CLIENTMANAGER_DIALOG, pParent)
	, m_strNumberEdit(_T(""))
	, m_strIdEdit(_T(""))
	, m_strNameEdit(_T(""))
	, m_strSelectedItemEdit(_T(""))
	, m_bIgnoreListSelectionChange(false) // 추가!
	, m_strAttendanceEdit(_T(""))
	, m_strGradeEdit(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCClientManagerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST_client, m_listClient);
	DDX_Text(pDX, IDC_EDIT_number, m_strNumberEdit);
	DDX_Text(pDX, IDC_EDIT_id, m_strIdEdit);
	DDX_Text(pDX, IDC_EDIT_name, m_strNameEdit);
	DDX_Text(pDX, IDC_EDIT_selectItem, m_strSelectedItemEdit);
	DDX_Control(pDX, IDC_LIST_vector, m_listClientVector);
	DDX_Text(pDX, IDC_EDIT_attendance, m_strAttendanceEdit);
	DDX_Text(pDX, IDC_EDIT_grade, m_strGradeEdit);
}

BEGIN_MESSAGE_MAP(CMFCClientManagerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_client, &CMFCClientManagerDlg::OnLvnItemchangedListclient)
	ON_BN_CLICKED(IDC_BTN_add, &CMFCClientManagerDlg::OnBnClickedBtnadd)
	ON_BN_CLICKED(IDC_BTN_clear, &CMFCClientManagerDlg::OnBnClickedBtnclear)
	ON_BN_CLICKED(IDC_BTN_delete, &CMFCClientManagerDlg::OnBnClickedBtndelete)
	ON_BN_CLICKED(IDC_BTN_display, &CMFCClientManagerDlg::OnBnClickedBtndisplay)
	ON_BN_CLICKED(IDC_BTN_modify, &CMFCClientManagerDlg::OnBnClickedBtnmodify)
	ON_EN_CHANGE(IDC_EDIT_number, &CMFCClientManagerDlg::OnEnChangeEditnumber)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_LIST_vector, &CMFCClientManagerDlg::OnLvnItemchangedListvector)
	ON_BN_CLICKED(IDC_BTN_insert, &CMFCClientManagerDlg::OnBnClickedBtninsert)
	ON_EN_CHANGE(IDC_EDIT_name3, &CMFCClientManagerDlg::OnEnChangeEditname3)
END_MESSAGE_MAP()


// CMFCClientManagerDlg 메시지 처리기

BOOL CMFCClientManagerDlg::OnInitDialog()
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

	// TODO: Add extra initialization here

	//to make gridlines;
	//m_listClient.SetExtendedStyle(m_listClient.GetExtendedStyle() | LVS_EX_GRIDLINES);
	m_listClient.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);


	//to insert columns;
	m_listClient.InsertColumn(0, _T("number"), LVCFMT_CENTER, 110);
	m_listClient.InsertColumn(1, _T("id"), LVCFMT_CENTER, 100);
	m_listClient.InsertColumn(2, _T("name"), LVCFMT_CENTER, 110);
	m_listClient.InsertColumn(3, _T("attendance"), LVCFMT_CENTER, 106);
	m_listClient.InsertColumn(4, _T("grade"), LVCFMT_CENTER, 107);


	////to write initial values;
	//m_listClient.InsertItem(0, _T("1"));
	//m_listClient.SetItemText(0, 1, _T("id01"));
	//m_listClient.SetItemText(0, 2, _T("cherlhee"));


	////to write initial values;
	//m_listClient.InsertItem(1, _T("2"));
	//m_listClient.SetItemText(1, 1, _T("id02"));
	//m_listClient.SetItemText(1, 2, _T("jcradar"));




	///////////; vector;///////////////////////


	//to make gridlines;
	m_listClientVector.SetExtendedStyle(LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

	//to add columns;
	m_listClientVector.InsertColumn(0, _T("number"), LVCFMT_CENTER, 100);
	m_listClientVector.InsertColumn(1, _T("id"), LVCFMT_CENTER, 100);
	m_listClientVector.InsertColumn(2, _T("name"), LVCFMT_CENTER, 100);
	m_listClientVector.InsertColumn(3, _T("attendance"), LVCFMT_CENTER, 86);
	m_listClientVector.InsertColumn(4, _T("grade"), LVCFMT_CENTER, 86);


	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCClientManagerDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CMFCClientManagerDlg::OnPaint()
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
HCURSOR CMFCClientManagerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMFCClientManagerDlg::OnLvnItemchangedListclient(NMHDR* pNMHDR, LRESULT* pResult)
{
	if (m_bIgnoreListSelectionChange) {
		*pResult = 0;
		return;
	}

	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);

	m_nSelectedItem = pNMLV->iItem;
	if (m_nSelectedItem == -1) {
		*pResult = 0;
		return;
	}

	m_strSelectedItemEdit = m_listClient.GetItemText(m_nSelectedItem, 0);
	m_strNumberEdit = m_listClient.GetItemText(m_nSelectedItem, 0);
	m_strIdEdit = m_listClient.GetItemText(m_nSelectedItem, 1);
	m_strNameEdit = m_listClient.GetItemText(m_nSelectedItem, 2);

	// 새로 추가된 부분
	m_strAttendanceEdit = m_listClient.GetItemText(m_nSelectedItem, 3);
	m_strGradeEdit = m_listClient.GetItemText(m_nSelectedItem, 4);

	UpdateData(FALSE);
	*pResult = 0;
}



void CMFCClientManagerDlg::OnBnClickedBtnadd()
{
	// Edit Control에 랜덤 데이터 생성해서 자동 채우기

	// 번호 자동 생성
	int count = m_listClient.GetItemCount();
	CString number;
	number.Format(_T("%d"), count + 1);

	// 랜덤 ID 생성
	int nRandom = rand() % 100000;
	CString id;
	id.Format(_T("%d"), nRandom);

	// 이름 생성
	CString name = _T("jcr-") + number;

	// 랜덤 출석
	int attendanceVal = rand() % 101;  // 0~100 포함하도록 변경
	CString attendance;
	attendance.Format(_T("%d"), attendanceVal);

	// 출석 점수에 따른 성적 결정
	CString grade;
	if (attendanceVal >= 70)
		grade = _T("A");
	else if (attendanceVal >= 50)
		grade = _T("B");
	else if (attendanceVal >= 30)
		grade = _T("C");
	else if (attendanceVal >= 20)
		grade = _T("D");
	else
		grade = _T("F");

	// Client 객체 생성 (5개 필드)
	Client client(number, id, name, attendance, grade);

	// 벡터에 추가
	m_manager.AddClient(client);

	// 리스트 컨트롤에 추가
	int index = m_listClient.GetItemCount();
	m_listClient.InsertItem(index, client.number);
	m_listClient.SetItemText(index, 1, client.id);
	m_listClient.SetItemText(index, 2, client.name);
	m_listClient.SetItemText(index, 3, client.attendance);
	m_listClient.SetItemText(index, 4, client.grade);

	UpdateData(FALSE);
}




void CMFCClientManagerDlg::OnBnClickedBtnclear()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	m_strNumberEdit.Empty();
	m_strIdEdit.Empty();
	m_strNameEdit.Empty();
	m_strAttendanceEdit.Empty();   // 새로 추가
	m_strGradeEdit.Empty();        // 새로 추가
	m_strSelectedItemEdit = "";

	UpdateData(FALSE);
}


void CMFCClientManagerDlg::OnBnClickedBtndelete()
{
	UpdateData(TRUE);

	// 현재 선택된 항목 번호 가져오기
	CString selectedNumber = m_listClient.GetItemText(m_nSelectedItem, 0);

	// 리스트에서 항목 삭제
	m_listClient.DeleteItem(m_nSelectedItem);

	// 삭제 후 리스트의 번호(0번 컬럼)를 다시 매김
	for (int i = m_nSelectedItem; i < m_listClient.GetItemCount(); i++) {
		CString strIndex;
		strIndex.Format(_T("%d"), i + 1);
		m_listClient.SetItemText(i, 0, strIndex);
	}

	// 벡터에서도 삭제
	for (auto it = m_manager.clientVector.begin(); it != m_manager.clientVector.end(); ++it) {
		if (it->number == selectedNumber) {
			m_manager.clientVector.erase(it);
			break;
		}
	}

	UpdateData(FALSE);
}


void CMFCClientManagerDlg::OnBnClickedBtndisplay()
{
	// 기존 내용 삭제
	m_listClientVector.DeleteAllItems();

	// 벡터를 순회하며 리스트에 추가
	for (int i = 0; i < m_manager.clientVector.size(); ++i) {
		const Client& client = m_manager.clientVector[i];

		m_listClientVector.InsertItem(i, client.number);
		m_listClientVector.SetItemText(i, 1, client.id);
		m_listClientVector.SetItemText(i, 2, client.name);
		m_listClientVector.SetItemText(i, 3, client.attendance);
		m_listClientVector.SetItemText(i, 4, client.grade);
	}
}


void CMFCClientManagerDlg::OnBnClickedBtnmodify()
{
	UpdateData(TRUE);

	int selectedIndex = m_listClient.GetNextItem(-1, LVNI_SELECTED);
	if (selectedIndex == -1) {
		AfxMessageBox(_T("no item is selected."));
		return;
	}

	// 기존 number 값 저장 (Vector에서 검색용)
	CString selectedNumber = m_listClient.GetItemText(selectedIndex, 0);

	// 리스트 선택 이벤트 무시
	m_bIgnoreListSelectionChange = true;

	// 리스트 컨트롤 데이터 수정 (5개 컬럼 모두)
	m_listClient.SetItemText(selectedIndex, 0, m_strNumberEdit);
	m_listClient.SetItemText(selectedIndex, 1, m_strIdEdit);
	m_listClient.SetItemText(selectedIndex, 2, m_strNameEdit);
	m_listClient.SetItemText(selectedIndex, 3, m_strAttendanceEdit);
	m_listClient.SetItemText(selectedIndex, 4, m_strGradeEdit);

	// 벡터에서 기존 number를 기준으로 수정
	for (Client& client : m_manager.clientVector)
	{
		if (client.number == selectedNumber)
		{
			client.number = m_strNumberEdit;
			client.id = m_strIdEdit;
			client.name = m_strNameEdit;
			client.attendance = m_strAttendanceEdit;
			client.grade = m_strGradeEdit;
			break;
		}
	}

	// 이벤트 다시 허용
	m_bIgnoreListSelectionChange = false;

	UpdateData(FALSE);
}




void CMFCClientManagerDlg::OnEnChangeEditnumber()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

void CMFCClientManagerDlg::OnLvnItemchangedListvector(NMHDR* pNMHDR, LRESULT* pResult)
{
	LPNMLISTVIEW pNMLV = reinterpret_cast<LPNMLISTVIEW>(pNMHDR);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	*pResult = 0;
}

void CMFCClientManagerDlg::OnBnClickedBtninsert()
{
	UpdateData(TRUE); // Edit Control 값 가져오기

	// 입력값이 비어있는지 확인
	if (m_strNumberEdit.IsEmpty() || m_strIdEdit.IsEmpty() || m_strNameEdit.IsEmpty()
		|| m_strAttendanceEdit.IsEmpty() || m_strGradeEdit.IsEmpty())
	{
		AfxMessageBox(_T("모든 필드를 입력해주세요."));
		return;
	}

	// 새로운 Client 객체 생성 (출석과 성적도 포함)
	Client client(m_strNumberEdit, m_strIdEdit, m_strNameEdit, m_strAttendanceEdit, m_strGradeEdit);

	// 벡터에 추가
	m_manager.AddClient(client);

	// 리스트 컨트롤에 추가 (5개 컬럼 모두)
	int index = m_listClient.GetItemCount(); // 마지막 줄에 추가
	m_listClient.InsertItem(index, client.number);
	m_listClient.SetItemText(index, 1, client.id);
	m_listClient.SetItemText(index, 2, client.name);
	m_listClient.SetItemText(index, 3, client.attendance);
	m_listClient.SetItemText(index, 4, client.grade);

	// 필요하면 입력 초기화
	// m_strNumberEdit.Empty();
	// m_strIdEdit.Empty();
	// m_strNameEdit.Empty();
	// m_strAttendanceEdit.Empty();
	// m_strGradeEdit.Empty();
	// UpdateData(FALSE);
}



void CMFCClientManagerDlg::OnEnChangeEditname3()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// ENM_CHANGE가 있으면 마스크에 ORed를 플래그합니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
