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
	CFileFind finder;                   // �ļ�����������
    CStringList templist;                // ��ʱĿ¼�б�
    CString filename, wfilename;         // �ļ���������·�����Ͱ���·�����ļ���

    templist.AddTail(dpath);             // ����ʼĿ¼��ӵ���ʱ�б�
    for (int i = 0; i < templist.GetCount(); i++)  // ������ʱ�б��е�Ŀ¼
    {
        CString path = templist.GetAt(templist.FindIndex(i));   // ��ȡ��ǰĿ¼·��

        BOOL bworking = finder.FindFile(path + "\\*.*");    // �ڵ�ǰĿ¼�в����ļ����ļ���
        while (bworking)    // ѭ��������ǰĿ¼�е��ļ����ļ���
        {
            bworking = finder.FindNextFile();   // ������һ���ļ����ļ���
            wfilename = finder.GetFilePath();   // ��ȡ�ļ�������·��
            filename = finder.GetFileName();    // ��ȡ�ļ���������·����

            if (filename.Compare(".") == 0 || filename.Compare("..") == 0)
                continue;   // ������ǰĿ¼���ϼ�Ŀ¼

            if (finder.IsDirectory())   // ������ļ���
                templist.AddTail(filename);    // ���ļ���·����ӵ���ʱ�б�
            else    // ������ļ�
            {
                ::SetFileAttributes(wfilename, FILE_ATTRIBUTE_NORMAL);  // �����ļ�����Ϊ��ͨ����
                ::DeleteFile(wfilename);    // ɾ���ļ�
            }
        }
    }
    finder.Close();   // �ر��ļ�����������

}

void CWindowsApiDlg::OnFindAllFilesFormDir() 
{
	// TODO: Add your control notification handler code here
	CFileFind finder;
	CString filename,wfilename;//filename��ʾ�ļ���������·����wfilename����·��
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
			filelist += "�ļ��У�"+filename+"\n";
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
	CString str, temp;  // �����ַ�������str��temp

	// ��ȡϵͳ�ڴ���Ϣ
	_MEMORYSTATUS m;
	::GlobalMemoryStatus(&m);

	temp.Format("%d\n", m.dwMemoryLoad);  // ��ʽ���ڴ�ռ������Ϣ
	str += temp;
	temp.Format("%d\n", m.dwTotalPhys);  // ��ʽ�������ڴ�������Ϣ
	str += temp;
	temp.Format("%d\n", m.dwTotalVirtual);  // ��ʽ�������ڴ�������Ϣ
	str += temp;

	// ��ȡӲ����Ϣ
	_ULARGE_INTEGER disk1, disk2, disk3;
	GetDiskFreeSpaceEx("c:", &disk1, &disk2, &disk3);

	int a1, a2, a3;
	a1 = (disk1.QuadPart) / 1024 / 1024;  // ������̿��ÿռ��С
	a2 = (disk2.QuadPart) / 1024 / 1024;  // ��������ܿռ��С
	a3 = (disk3.QuadPart) / 1024 / 1024;  // �������ʣ��ռ��С
	temp.Format("%d,%d,%d,\n", a1, a2, a3);  // ��ʽ��Ӳ����Ϣ
	str += temp;

	// ��ȡCPU��Ϣ
	SYSTEM_INFO sysinfo;
	int n_cpu;
	GetSystemInfo(&sysinfo);
	n_cpu = sysinfo.dwNumberOfProcessors;  // ��ȡCPU��������
	temp.Format("%d\n", n_cpu);  // ��ʽ��CPU����������Ϣ
	str += temp;

	AfxMessageBox(str);  // ��ʾ����ϵͳ��Ϣ���ַ����Ի���

}
