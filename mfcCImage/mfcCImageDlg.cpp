
// mfcCImageDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "mfcCImage.h"
#include "mfcCImageDlg.h"
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


// CmfcCImageDlg 대화 상자



CmfcCImageDlg::CmfcCImageDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCCIMAGE_DIALOG, pParent)
	, inum(15)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CmfcCImageDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, inum);
}

BEGIN_MESSAGE_MAP(CmfcCImageDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//ON_BN_CLICKED(IDC_BUTTON1, &CmfcCImageDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BTN_IMAGE, &CmfcCImageDlg::OnBnClickedBtnImage)
	//ON_BN_CLICKED(BtnSave, &CmfcCImageDlg::OnBnClickedBtnsave)
	//ON_BN_CLICKED(BtnLoad, &CmfcCImageDlg::OnBnClickedBtnload)
	ON_BN_CLICKED(BtnAction, &CmfcCImageDlg::OnBnClickedBtnaction)
	//ON_EN_CHANGE(IDC_EDIT1, &CmfcCImageDlg::OnEnChangeEdit1)
	ON_BN_CLICKED(IDC_BTN_GET_DATA, &CmfcCImageDlg::OnBnClickedBtnGetData)
END_MESSAGE_MAP()


// CmfcCImageDlg 메시지 처리기

BOOL CmfcCImageDlg::OnInitDialog()
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

void CmfcCImageDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CmfcCImageDlg::OnPaint()
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
HCURSOR CmfcCImageDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
#include<cstdlib>
#include<ctime>



//void CmfcCImageDlg::OnBnClickedButton1()
//{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//}

void CmfcCImageDlg::UpdateDisplay()
{

	srand(time(NULL));
	int x;
	int y;
	CClientDC dc(this);
	//x = rand() % 120;
	//y = rand() % 120;
	x = 0;
	y = 0;
	m_image.Draw(dc, x, y);

}


void CmfcCImageDlg::moveRect(int rd)
{
	srand(time(NULL));
	static int nSttX = rand() % 120;
	static int nSttY = rand() % 120;
	int nGray = 80;
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();
	int nRadius = rd; //10
	unsigned char* fm = (unsigned char*)m_image.GetBits();

	memset(fm, 0xff, nWidth * nHeight);
	/*
	for (int j = nSttY; j < nSttY + 48; j++)
	{
		for (int i = nSttX; i < nSttX + 64; i++)
		{

			if (validImgPos(i, j))
				fm[j * nPitch + i] = nGray;

		}
	}
	*/

	drawCircle(fm, nSttX, nSttY, nRadius, nGray);

	//nSttX++;
	//nSttY++;
	UpdateDisplay();
	CString strFile;
	strFile.Format(_T("C:\\image\\image%d.jpg"), nSttX);
	m_image.Save(strFile);





}


void CmfcCImageDlg::OnBnClickedBtnImage()
{
	
	int nWidth = 640;
	int nHeight = 480;
	int nBpp = 8;

	m_image.Create(nWidth, -nHeight, nBpp);
	if (nBpp == 8) {
		static RGBQUAD rgb[256];
		for (int i = 0; i < 256; i++)
			rgb[i].rgbRed = rgb[i].rgbGreen = rgb[i].rgbBlue = i;
		m_image.SetColorTable(0, 256, rgb);

	}
	int nPitch = m_image.GetPitch();
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	memset(fm, 0xff, nWidth * nHeight);

	CClientDC dc(this);
	m_image.Draw(dc, 0, 0);
	m_image.Save(_T("c:\\image\\save.bmp"));





}

BOOL CmfcCImageDlg::validImgPos(int x, int y)
{

	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();

	CRect rect(0, 0, nWidth, nHeight);

	return rect.PtInRect(CPoint(x, y));



}


void CmfcCImageDlg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray)
{
	int nCenterX = x + nRadius;
	int nCenterY = y + nRadius;
	int nPitch = m_image.GetPitch();
	for (int j = y; j < y + nRadius * 2; j++)
	{
		for (int i = x; i < x + nRadius * 2; i++)
		{
			if(inInCircle(i,j,nCenterX,nCenterY,nRadius))
			fm[j * nPitch + i] = nGray;
		}
	}
}

bool CmfcCImageDlg::inInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius)
{
	bool bRet = false;

	double dX = i - nCenterX;
	double dY = j - nCenterY;
	double dDist = dX * dX + dY * dY;

	if (dDist < nRadius * nRadius) {
		bRet = true;
	}

	return bRet;

}


void CmfcCImageDlg::OnBnClickedBtnsave()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CmfcCImageDlg::OnBnClickedBtnload()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CmfcCImageDlg::OnBnClickedBtnaction()
{
	UpdateData(TRUE);
	moveRect(inum);
	UpdateData(false);
		Sleep(10);
}


void CmfcCImageDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}

#include<iostream>
using namespace std;
void CmfcCImageDlg::OnBnClickedBtnGetData()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	unsigned char* fm = (unsigned char*)m_image.GetBits();
	int nWidth = m_image.GetWidth();
	int nHeight = m_image.GetHeight();
	int nPitch = m_image.GetPitch();

	int nTh = 80;
	CRect rect(0, 0, nWidth, nHeight);
	int nSumX = 0;
	int nSumY = 0;
	int nCount = 0;
	for (int j = rect.top; j < rect.bottom; j++)
	{
		for (int i = rect.left; i < rect.right; i++)
		{
			if (fm[j * nPitch + i] == nTh) {
				nSumX += i;
				nSumY += j;
				nCount++;
			}
		}
	}

	double dCenterX = (double)nSumX / nCount;
	double dCenterY = (double)nSumY / nCount;
	cout << dCenterX << '\t' << dCenterY;


}
