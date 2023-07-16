// WindowsApiDlg.cpp : implementation file
//

#include "stdafx.h"
#include "WindowsApi.h"
#include "WindowsApiDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWindowsApiDlg dialog

CWindowsApiDlg::CWindowsApiDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWindowsApiDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWindowsApiDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWindowsApiDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWindowsApiDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWindowsApiDlg, CDialog)
	//{{AFX_MSG_MAP(CWindowsApiDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_DeleteDirectory, OnDeleteDirectory)
	ON_BN_CLICKED(IDC_FindAllFilesFormDir, OnFindAllFilesFormDir)
	ON_BN_CLICKED(IDC_NowPath, OnNowPath)
	ON_BN_CLICKED(IDC_ObtainSystemHardwareInformation, OnObtainSystemHardwareInformation)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWindowsApiDlg message handlers

BOOL CWindowsApiDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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

void CWindowsApiDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWindowsApiDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CWindowsApiDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}



void CWindowsApiDlg::OnDeleteDirectory() 
{
	// TODO: Add your control notification handler code here
	DeleteDirectory("E:\\vc6.0\\mfc\\WindowsApi\\test");
}

void CWindowsApiDlg::DeleteDirectory(CString dpath)
{
	CFileFind finder;                   // 文件查找器对象
    CStringList templist;                // 临时目录列表
    CString filename, wfilename;         // 文件名（不含路径）和包含路径的文件名

    templist.AddTail(dpath);             // 将初始目录添加到临时列表
    for (int i = 0; i < templist.GetCount(); i++)  // 遍历临时列表中的目录
    {
        CString path = templist.GetAt(templist.FindIndex(i));   // 获取当前目录路径

        BOOL bworking = finder.FindFile(path + "\\*.*");    // 在当前目录中查找文件和文件夹
        while (bworking)    // 循环遍历当前目录中的文件和文件夹
        {
            bworking = finder.FindNextFile();   // 查找下一个文件或文件夹
            wfilename = finder.GetFilePath();   // 获取文件的完整路径
            filename = finder.GetFileName();    // 获取文件名（不含路径）

            if (filename.Compare(".") == 0 || filename.Compare("..") == 0)
                continue;   // 跳过当前目录和上级目录

            if (finder.IsDirectory())   // 如果是文件夹
                templist.AddTail(filename);    // 将文件夹路径添加到临时列表
            else    // 如果是文件
            {
                ::SetFileAttributes(wfilename, FILE_ATTRIBUTE_NORMAL);  // 设置文件属性为普通属性
                ::DeleteFile(wfilename);    // 删除文件
            }
        }
    }
    finder.Close();   // 关闭文件查找器对象

}

void CWindowsApiDlg::OnFindAllFilesFormDir() 
{
	// TODO: Add your control notification handler code here
	CFileFind finder;
	CString filename,wfilename;//filename表示文件名不包括路径，wfilename包括路径
	CString filelist;

	BOOL bworking=finder.FindFile("E:\\vc6.0\\mfc\\WindowsApi\\*.*");
	while(bworking)
	{
		bworking=finder.FindNextFile();
		wfilename = finder.GetFilePath();
		filename = finder.GetFileName();
		if(filename.Compare(".")==0||filename.Compare("..")==0)
			continue;

		filelist+=filename+"\n";
		if( finder.IsDirectory() )
		{
			filelist += "文件夹："+filename+"\n";
		}	
	}
	finder.Close();	
	AfxMessageBox(filelist);

}

void CWindowsApiDlg::OnNowPath() 
{
	// TODO: Add your control notification handler code here
	CString strAppPath;
	TCHAR szBuffer[MAX_PATH];
    GetCurrentDirectory(MAX_PATH,szBuffer);
    strAppPath.Format("%s",szBuffer);
	AfxMessageBox(strAppPath);

}

void CWindowsApiDlg::OnObtainSystemHardwareInformation() 
{
	// TODO: Add your control notification handler code here
	CString str, temp;  // 定义字符串变量str和temp

	// 获取系统内存信息
	_MEMORYSTATUS m;
	::GlobalMemoryStatus(&m);

	temp.Format("%d\n", m.dwMemoryLoad);  // 格式化内存占用率信息
	str += temp;
	temp.Format("%d\n", m.dwTotalPhys);  // 格式化物理内存总量信息
	str += temp;
	temp.Format("%d\n", m.dwTotalVirtual);  // 格式化虚拟内存总量信息
	str += temp;

	// 获取硬盘信息
	_ULARGE_INTEGER disk1, disk2, disk3;
	GetDiskFreeSpaceEx("c:", &disk1, &disk2, &disk3);

	int a1, a2, a3;
	a1 = (disk1.QuadPart) / 1024 / 1024;  // 计算磁盘可用空间大小
	a2 = (disk2.QuadPart) / 1024 / 1024;  // 计算磁盘总空间大小
	a3 = (disk3.QuadPart) / 1024 / 1024;  // 计算磁盘剩余空间大小
	temp.Format("%d,%d,%d,\n", a1, a2, a3);  // 格式化硬盘信息
	str += temp;

	// 获取CPU信息
	SYSTEM_INFO sysinfo;
	int n_cpu;
	GetSystemInfo(&sysinfo);
	n_cpu = sysinfo.dwNumberOfProcessors;  // 获取CPU核心数量
	temp.Format("%d\n", n_cpu);  // 格式化CPU核心数量信息
	str += temp;

	AfxMessageBox(str);  // 显示包含系统信息的字符串对话框

}
