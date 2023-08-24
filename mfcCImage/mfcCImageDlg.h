
// mfcCImageDlg.h: 헤더 파일
//

#pragma once


// CmfcCImageDlg 대화 상자
class CmfcCImageDlg : public CDialogEx
{
// 생성입니다.
private:
	CImage m_image;
public:
	CmfcCImageDlg(CWnd* pParent = nullptr);	// 표준 생성자입니다.

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCCIMAGE_DIALOG };
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
	//afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedBtnImage();
	void UpdateDisplay();
	void moveRect(int rd);
	BOOL validImgPos(int x, int y);
	void drawCircle(unsigned char* fm, int i, int j, int nRadius, int nGray);
	bool inInCircle(int i, int j, int nCenterX, int nCenterY, int nRadius);
	//void CmfcCImageDIg::drawCircle(unsigned char* fm, int x, int y, int nRadius, int nGray)
	afx_msg void OnBnClickedBtnsave();
	afx_msg void OnBnClickedBtnload();
	afx_msg void OnBnClickedBtnaction();
	afx_msg void OnEnChangeEdit1();
	int inum;
	afx_msg void OnBnClickedBtnGetData();
};
