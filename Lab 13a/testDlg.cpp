//
//// testDlg.cpp : implementation file
////
//
//#include "stdafx.h"
//#include "test.h"
//#include "testDlg.h"
//#include "afxdialogex.h"
//
//#ifdef _DEBUG
//#define new DEBUG_NEW
//#endif
//
//#include <string>
//using std::string;
//
//#include <sstream>
//using std::ostringstream;
//
//#include "Animal.h"
//
//// CAboutDlg dialog used for App About
//
//class CAboutDlg : public CDialogEx
//{
//public:
//	CAboutDlg();
//
//// Dialog Data
//	enum { IDD = IDD_ABOUTBOX };
//
//	protected:
//	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
//
//// Implementation
//protected:
//	DECLARE_MESSAGE_MAP()
//};
//
//CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
//{
//}
//
//void CAboutDlg::DoDataExchange(CDataExchange* pDX)
//{
//	CDialogEx::DoDataExchange(pDX);
//}
//
//BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
//END_MESSAGE_MAP()
//
//
//// CtestDlg dialog
//
//
//
//
//CtestDlg::CtestDlg(CWnd* pParent /*=NULL*/)
//	: CDialogEx(CtestDlg::IDD, pParent)
//{
//	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
//}
//
//void CtestDlg::DoDataExchange(CDataExchange* pDX)
//{
//	CDialogEx::DoDataExchange(pDX);
//}
//
//BEGIN_MESSAGE_MAP(CtestDlg, CDialogEx)
//	ON_WM_SYSCOMMAND()
//	ON_WM_PAINT()
//	ON_WM_QUERYDRAGICON()
//  ON_BN_CLICKED(IDC_BUTTON1, &CtestDlg::OnBnClickedButton1)
//END_MESSAGE_MAP()
//
//
//// CtestDlg message handlers
//
//BOOL CtestDlg::OnInitDialog()
//{
//	CDialogEx::OnInitDialog();
//
//	// Add "About..." menu item to system menu.
//
//	// IDM_ABOUTBOX must be in the system command range.
//	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
//	ASSERT(IDM_ABOUTBOX < 0xF000);
//
//	CMenu* pSysMenu = GetSystemMenu(FALSE);
//	if (pSysMenu != NULL)
//	{
//		BOOL bNameValid;
//		CString strAboutMenu;
//		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
//		ASSERT(bNameValid);
//		if (!strAboutMenu.IsEmpty())
//		{
//			pSysMenu->AppendMenu(MF_SEPARATOR);
//			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
//		}
//	}
//
//	// Set the icon for this dialog.  The framework does this automatically
//	//  when the application's main window is not a dialog
//	SetIcon(m_hIcon, TRUE);			// Set big icon
//	SetIcon(m_hIcon, FALSE);		// Set small icon
//
//	CButton* pRadio1 = (CButton*)GetDlgItem(IDC_RADIO1);
//  pRadio1->SetCheck(BST_CHECKED);
//	return TRUE;  // return TRUE  unless you set the focus to a control
//}
//
//void CtestDlg::OnSysCommand(UINT nID, LPARAM lParam)
//{
//	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
//	{
//		CAboutDlg dlgAbout;
//		dlgAbout.DoModal();
//	}
//	else
//	{
//		CDialogEx::OnSysCommand(nID, lParam);
//	}
//}
//
//// If you add a minimize button to your dialog, you will need the code below
////  to draw the icon.  For MFC applications using the document/view model,
////  this is automatically done for you by the framework.
//
//void CtestDlg::OnPaint()
//{
//	if (IsIconic())
//	{
//		CPaintDC dc(this); // device context for painting
//
//		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);
//
//		// Center icon in client rectangle
//		int cxIcon = GetSystemMetrics(SM_CXICON);
//		int cyIcon = GetSystemMetrics(SM_CYICON);
//		CRect rect;
//		GetClientRect(&rect);
//		int x = (rect.Width() - cxIcon + 1) / 2;
//		int y = (rect.Height() - cyIcon + 1) / 2;
//
//		// Draw the icon
//		dc.DrawIcon(x, y, m_hIcon);
//	}
//	else
//	{
//		CDialogEx::OnPaint();
//	}
//}
//
//// The system calls this function to obtain the cursor to display while the user drags
////  the minimized window.
//HCURSOR CtestDlg::OnQueryDragIcon()
//{
//	return static_cast<HCURSOR>(m_hIcon);
//}
//
//
//
//void CtestDlg::OnBnClickedButton1()
//{
//  CEdit* pEdit1 = (CEdit*)GetDlgItem(IDC_EDIT1);
//  CEdit* pEdit2 = (CEdit*)GetDlgItem(IDC_EDIT2);
//  CEdit* pEdit3 = (CEdit*)GetDlgItem(IDC_EDIT3);
//
//  CString degC, degF;
//  pEdit1->GetWindowText(degC);
//  pEdit2->GetWindowText(degF);
//
//  CButton* pRadio1 = (CButton*)GetDlgItem(IDC_RADIO1);
//  CButton* pRadio2 = (CButton*)GetDlgItem(IDC_RADIO2);
//
//  if (pRadio1->GetCheck())
//  {
//    int iDegC = _ttoi(degC);
//    int iDegF = iDegC * 9 / 5 + 32;
//
//    ostringstream sout; // a buffer
//    sout << iDegF;
//    pEdit2->SetWindowText(CString(sout.str().c_str()));
//  }
//  else if (pRadio2->GetCheck())
//  {
//    int iDegF = _ttoi(degF);
//    int iDegC = (iDegF - 32) * 5 / 9;
//
//    ostringstream sout; // a buffer
//    sout << iDegC;
//    pEdit1->SetWindowText(CString(sout.str().c_str()));
//  }
//
//
//  pEdit3->SetWindowText("Thanks for running this program.\r\nI hope you like the answer.");
//
//  CStatic* pStatic1 = (CStatic*)GetDlgItem(IDC_STATIC1);
//  pStatic1->SetWindowText("Celsius");
//
//  Cat c;
//  Dog d;
//  {
//    ostringstream sout; // a buffer
//    //sout << c;
//    pEdit3->SetWindowText(CString(sout.str().c_str()));
//  }
//
//
//}
