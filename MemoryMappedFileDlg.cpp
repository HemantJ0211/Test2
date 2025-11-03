
// MemoryMappedFileDlg.cpp : implementation file
//

#include "stdafx.h"
#include "MemoryMappedFile.h"
#include "MemoryMappedFileDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CMemoryMappedFileDlg dialog




CMemoryMappedFileDlg::CMemoryMappedFileDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CMemoryMappedFileDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMemoryMappedFileDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMemoryMappedFileDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDOK, &CMemoryMappedFileDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// CMemoryMappedFileDlg message handlers

BOOL CMemoryMappedFileDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
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

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMemoryMappedFileDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMemoryMappedFileDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMemoryMappedFileDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CMemoryMappedFileDlg::OnBnClickedOk()
{

	TCHAR szName[]=TEXT("Global\\MyFileMappingObject123");
	#define BUF_SIZE 1273741824
	SYSTEM_INFO sysInfo = {0};
	GetSystemInfo(&sysInfo);
	DWORD dwCBView = sysInfo.dwAllocationGranularity;

	// TODO: Add your control notification handler code here
	const char *pSrcBuf = "When a process writes to a copy-on-write page, the system copies the original page to\
							  a new page that is private to the process. The new page is backed by the paging file.\
							  The protection of the new page changes from copy-on-write to read/write.\
							  When a process writes to a copy-on-write page, the system copies the original page to a\
							  new page that is private to the process. The new page is backed by the paging file. The protection\
							  of the new page changes from copy-on-write to read/write.When a process writes to a copy-on-write\
							  page, the system copies the original page to a new page that is private to the process. The new page\
							  is backed by the paging file. The protection of the new page changes from copy-on-write to read/write.\
							  When a process writes to a copy-on-write page, the system copies the original page to a new page that\
							  is private to the process. The new page is backed by the paging file. The protection of the new page\
							  changes from copy-on-write to read/write.When a process writes to a copy-on-write page, the system\
							  copies the original page to a new page that is private to the process. The new page is backed by the\
							  paging file. The protection of the new page changes from copy-on-write to read/write.";


	const char *pSrcBuf1 = "****When a process writes to a copy-on-write page, the system copies the original page to\
							  a new page that is private to the process. The new page is backed by the paging file.\
							  The protection of the new page changes from copy-on-write to read/write.\
							  When a process writes to a copy-on-write page, the system copies the original page to a\
							  new page that is private to the process. The new page is backed by the paging file. The protection\
							  of the new page changes from copy-on-write to read/write.When a process writes to a copy-on-write\
							  page, the system copies the original page to a new page that is private to the process. The new page\
							  is backed by the paging file. The protection of the new page changes from copy-on-write to read/write.\
							  When a process writes to a copy-on-write page, the system copies the original page to a new page that\
							  is private to the process. The new page is backed by the paging file. The protection of the new page\
							  changes from copy-on-write to read/write.When a process writes to a copy-on-write page, the system\
							  copies the original page to a new page that is private to the process. The new page is backed by the\
							  paging file. The protection of the new page changes from copy-on-write to read/write.";

	const char *pSrcBuf2 = "****123When a process writes to a copy-on-write page, the system copies the original page to\
							  a new page that is private to the process. The new page is backed by the paging file.\
							  The protection of the new page changes from copy-on-write to read/write.\
							  When a process writes to a copy-on-write page, the system copies the original page to a\
							  new page that is private to the process. The new page is backed by the paging file. The protection\
							  of the new page changes from copy-on-write to read/write.When a process writes to a copy-on-write\
							  page, the system copies the original page to a new page that is private to the process. The new page\
							  is backed by the paging file. The protection of the new page changes from copy-on-write to read/write.\
							  When a process writes to a copy-on-write page, the system copies the original page to a new page that\
							  is private to the process. The new page is backed by the paging file. The protection of the new page\
							  changes from copy-on-write to read/write.When a process writes to a copy-on-write page, the system\
							  copies the original page to a new page that is private to the process. The new page is backed by the\
							  paging file. The protection of the new page changes from copy-on-write to read/write.";


	const char *pSrcBuf3 = "****223When a process writes to a copy-on-write page, the system copies the original page to\
							  a new page that is private to the process. The new page is backed by the paging file.\
							  The protection of the new page changes from copy-on-write to read/write.\
							  When a process writes to a copy-on-write page, the system copies the original page to a\
							  new page that is private to the process. The new page is backed by the paging file. The protection\
							  of the new page changes from copy-on-write to read/write.When a process writes to a copy-on-write\
							  page, the system copies the original page to a new page that is private to the process. The new page\
							  is backed by the paging file. The protection of the new page changes from copy-on-write to read/write.\
							  When a process writes to a copy-on-write page, the system copies the original page to a new page that\
							  is private to the process. The new page is backed by the paging file. The protection of the new page\
							  changes from copy-on-write to read/write.When a process writes to a copy-on-write page, the system\
							  copies the original page to a new page that is private to the process. The new page is backed by the\
							  paging file. The protection of the new page changes from copy-on-write to read/write.";

	const char *pSrcBuf4 = "****999When a process writes to a copy-on-write page, the system copies the original page to\
							  a new page that is private to the process. The new page is backed by the paging file.\
							  The protection of the new page changes from copy-on-write to read/write.\
							  When a process writes to a copy-on-write page, the system copies the original page to a\
							  new page that is private to the process. The new page is backed by the paging file. The protection\
							  of the new page changes from copy-on-write to read/write.When a process writes to a copy-on-write\
							  page, the system copies the original page to a new page that is private to the process. The new page\
							  is backed by the paging file. The protection of the new page changes from copy-on-write to read/write.\
							  When a process writes to a copy-on-write page, the system copies the original page to a new page that\
							  is private to the process. The new page is backed by the paging file. The protection of the new page\
							  changes from copy-on-write to read/write.When a process writes to a copy-on-write page, the system\
							  copies the original page to a new page that is private to the process. The new page is backed by the\
							  paging file. The protection of the new page changes from copy-on-write to read/write. *Hemant Joshi* ";


	   HANDLE hMapFile;
	   const char *pBuf = NULL;
	   SIZE_T objT;

	   objT = GetLargePageMinimum();

	   hMapFile = CreateFileMapping(
					 INVALID_HANDLE_VALUE,    // use paging file
					 NULL,                    // default security
					 PAGE_READWRITE,          // read/write access
					 0,                       // maximum object size (high-order DWORD)
					 BUF_SIZE,                // maximum object size (low-order DWORD)
					 szName);                 // name of mapping object

	   if (hMapFile == NULL)
	   {
		  
		  return;
	   }
	   pBuf = (const char*) MapViewOfFile(hMapFile,   // handle to map object
							FILE_MAP_ALL_ACCESS , // read/write permission
							0,
							0,
							BUF_SIZE);

	   if (pBuf == NULL)
	   {
		 
		   CloseHandle(hMapFile);

		  return ;
	   }
	
	  int iLen = strlen(pSrcBuf);
	  int iLen1 = strlen(pSrcBuf1);
	  int iLen2 = strlen(pSrcBuf2);
	  int iLen3 = strlen(pSrcBuf3);
	  int iLen4 = strlen(pSrcBuf4);

	  int iIndex = 0;
	  for(int ii = 0; ii < 1000; ii++)
	  {
		 memcpy( (void*)(pBuf + iIndex) ,(void*)pSrcBuf,iLen);
		//CopyMemory((PVOID)(pBuf + iIndex), pSrcBuf, iLen);
		iIndex += iLen;
	  }

	  for(int ii1 = 0; ii1 < 1000; ii1++)
	  {
		  memcpy((void*)(pBuf + iIndex) ,(void*)pSrcBuf1 ,iLen1);
		  //CopyMemory((PVOID)(pBuf + iIndex), pSrcBuf1, iLen1);
		  iIndex += iLen1;
	  }

	  for(int ii2 = 0; ii2 < 1000; ii2++)
	  {
		  memcpy((void*)(pBuf + iIndex) ,(void*)pSrcBuf2 ,iLen2);
		 // CopyMemory((PVOID)(pBuf + iIndex), pSrcBuf2, iLen2);
		  iIndex += iLen2;
	  }

	  for(int ii3 = 0; ii3 < 1000; ii3++)
	  {
		  memcpy((void*)(pBuf + iIndex) ,(void*)pSrcBuf3 ,iLen3);
		  //CopyMemory((PVOID)(pBuf + iIndex), pSrcBuf3, iLen3);
		  iIndex += iLen3;
	  }

	  for(int ii4 = 0; ii4 < 1000; ii4++)
	  {
		 memcpy((void*)(pBuf + iIndex) ,(void*)pSrcBuf4 ,iLen4);
		 // CopyMemory((PVOID)(pBuf + iIndex), pSrcBuf4, iLen4);
		  iIndex += iLen4;
	  }
	
	  BOOL bFound = FALSE;
	  for(int iiF = 0; iiF < iIndex; iiF++)
	  {
		  if(*(pBuf + iiF) == '*')
		  {
			  if(*(pBuf + iiF + 1) == 'H')
			  {
				  if(*(pBuf + iiF + 2) == 'e')
				  {
					  bFound = TRUE;
				  }
			  }
		  }  	
	  }

	  UnmapViewOfFile(pBuf);

	  CloseHandle(hMapFile);

	//OnOK();
}
