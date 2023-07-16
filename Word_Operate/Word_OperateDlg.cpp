// Word_OperateDlg.cpp : implementation file
//

#include "stdafx.h"
#include "Word_Operate.h"
#include "Word_OperateDlg.h"

#include "msword.h"
#include "AtlBase.h"


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
// CWord_OperateDlg dialog

CWord_OperateDlg::CWord_OperateDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWord_OperateDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWord_OperateDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CWord_OperateDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWord_OperateDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CWord_OperateDlg, CDialog)
	//{{AFX_MSG_MAP(CWord_OperateDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON_Test, OnBUTTONTest)
	ON_BN_CLICKED(IDC_BUTTON_Word, OnBUTTONWord)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWord_OperateDlg message handlers

BOOL CWord_OperateDlg::OnInitDialog()
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

void CWord_OperateDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CWord_OperateDlg::OnPaint() 
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
HCURSOR CWord_OperateDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CWord_OperateDlg::OnBUTTONTest() 
{
	// TODO: Add your control notification handler code here
	_Application app;
	if (!app.CreateDispatch("Word.Application")) {
		AfxMessageBox("word error");
		return;
	}
	app.SetVisible(true); // 设置 Word 应用程序可见
	app.SetWindowState(1); // 将 Word 窗口最小化
	Documents docs = app.GetDocuments(); // 获取文档集合对象

	_Font font;
	Paragraph para;

	CComVariant Template(_T("")); // 使用空模板创建新文档
	CComVariant NewTemplate(false), DocumentType(0), Visible;
	_Document doc;
	doc = docs.Add(&Template, &NewTemplate, &DocumentType, &Visible); // 新建文档

	Selection sel = app.GetSelection(); // 获取选定区域对象
	sel.TypeText("hello word"); // 输入文本
	sel.TypeParagraph(); // 插入段落
	
	//设置页眉页脚
	Window   mWindowActive;   //定义活动窗口对象
	View   mViewActive;   //定义活动视图对象
	Pane   mPane;   //定义当前窗格对象
	Fields fields;
	mWindowActive=app.GetActiveWindow(); //获得当前窗口 
	mPane=mWindowActive.GetActivePane();   //获得当前窗格
	mViewActive=mPane.GetView();   //获得当前视图
	mViewActive.SetSeekView(9);   //设置页眉视图
	font.SetSize(15);
	sel.TypeText("页眉，，，，，，，，，，，，，"); 
	font.SetSize(7);
	mViewActive.SetSeekView(10);   //设置页脚视图
	sel.TypeText("- ");
	fields.Add(sel.GetRange(),COleVariant(short(33)),COleVariant("PAGE  "),COleVariant(short(1))); //增加页码域
	sel.TypeText(" -");
	font.SetSize(6);
	para.SetAlignment(1);   //居中
	sel.TypeText("设置页脚视图"); 
	para.SetAlignment(1);   //居中
	mViewActive.SetSeekView(0); //回到正文视图


	// 使用 COleVariant 类定义变量
	COleVariant vtOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR), vtTrue((short)TRUE), vtFalse((short)FALSE);

	Paragraphs paras = doc.GetParagraphs(); // 获取段落集合对象
	para = paras.Item(1); // 获取文档的第一段
	para.SetAlignment(2); // 设置段落右对齐
	para.SetSpaceAfter(6); // 设置段落行距
	Range range = para.GetRange(); // 获取段落的文本范围对象
	font = range.GetFont(); // 获取字体对象
	font.SetSize(18); // 设置字体大小
	font.SetBold(1); // 设置粗体
	range.SetFont(font); // 应用字体设置到文本范围

	sel.TypeText(_T("\t\t\t\t\t\t\t\t\t姓名:史桢\t性别:男\t\t 年龄:22\t"));

	para.SetAlignment(1); // 设置段落居中对齐

	para = paras.Item(2); // 获取文档的第二段
	para.SetAlignment(1); // 设置段落居中对齐
	para.SetSpaceAfter(6); // 设置段落行距
	range = para.GetRange(); // 获取段落的文本范围对象
	font = range.GetFont(); // 获取字体对象
	font.SetSize(12); // 设置字体大小
	range.SetFont(font); // 应用字体设置到文本范围

	sel.TypeParagraph(); // 输入空白段落
	sel.TypeParagraph();
	sel.TypeText(_T("学生表\r\n")); 

	para.SetAlignment(1); // 设置段落居中对齐
	// 添加表格
	_Document saveDoc = app.GetActiveDocument(); // 获取当前激活的文档
	Tables tables = saveDoc.GetTables(); // 获取表格集合对象
	CComVariant defaultBehavior(1), AutoFitBehavior(1);  //设置表格的默认行为和自适应行为的参数
	tables.Add(sel.GetRange(), 3, 6, &defaultBehavior, &AutoFitBehavior); // 添加一个 3 行 3 列的表格
	Table table = tables.Item(1); // 获取第一个表格
	sel.TypeText(_T("学号")); // 输入表格内容
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("姓名"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("性别")); 
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("年龄"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("专业")); 
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("班级")); 
	sel.MoveDown(COleVariant((short)4),COleVariant((short)1),COleVariant((short)0));
	sel.TypeText(_T("1025454256")); 
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("张三"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("男"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("20"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("电子信息"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("电信一班")); 
	sel.MoveDown(COleVariant((short)4),COleVariant((short)1),COleVariant((short)0));
	sel.TypeText(_T("1234566666")); 
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("李四"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("男"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("20"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("计算机科学与技术"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("计科一班"));

	sel.MoveDown(COleVariant((short)4),COleVariant((short)1),COleVariant((short)0));
	sel.MoveDown(COleVariant((short)5),COleVariant((short)1),COleVariant((short)0));
	

	app.SetVisible(TRUE); // 设置 Word 应用程序可见
	table.ReleaseDispatch();
	tables.ReleaseDispatch();
	sel.ReleaseDispatch();
	docs.ReleaseDispatch();
	saveDoc.ReleaseDispatch();
	app.ReleaseDispatch();
	app.SetVisible(TRUE); // 设置 Word 应用程序可见

}

void CWord_OperateDlg::OnBUTTONWord() 
{
	// TODO: Add your control notification handler code here
	_Application app;
	if(!app.CreateDispatch("Word.Application")){
		AfxMessageBox("word error");
		return;
	}
	app.SetVisible(true);
	app.SetWindowState(1); 
	Documents docs = app.GetDocuments();
	CComVariant Template(_T("")); 
	CComVariant NewTemplate(false),DocumentType(0),Visible;
	_Document doc;
	doc = docs.Add(&Template,&NewTemplate,&DocumentType,&Visible);

	CString strName="小猪",strSex="男",strAge="24";
	Selection sel = app.GetSelection();
	sel.TypeText("安徽工业大学计算机科学与技术学院\r\n209教研室");
	sel.TypeParagraph();
	sel.TypeText("姓名:"+strName+"\t性别:"+strSex+"\t\t 年龄:"+strAge+"\t");

	sel.TypeText("\t\t\t\t\t\t\t");
	COleVariant vtOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR),vtTrue((short)TRUE),vtFalse((short)FALSE);// 使用COleVariant类，定义变量
	sel.InsertDateTime(COleVariant("yyyy-MM-dd HH-mm-ss"),vtFalse,vtOptional,vtOptional,vtOptional);//设置当前时间

	
	Paragraphs paras = doc.GetParagraphs();
	Paragraph para = paras.Item(1);//paras.Item(1)  选定文档第一段
	para.SetAlignment(1);//居中对齐（函数参数值可以改变）
	para.SetSpaceAfter(6);//设置段落行距
	Range range = para.GetRange();
	_Font font = range.GetFont();// 获取字体对象
	font.SetSize(18);//设置字体大小
	font.SetBold(1);//粗体
	range.SetFont(font);//绑定
	

	para = paras.Item(2);
	para.SetAlignment(2); 
	para.SetSpaceAfter(6); 
	range = para.GetRange();
	font = range.GetFont();
	font.SetSize(12); 
	range.SetFont(font); 


	sel.TypeParagraph();sel.TypeParagraph();sel.TypeParagraph();
	sel.TypeText(_T("\t\t\t\t\t\t\t--------------成绩表\r\n"));  
	//设置时间（同上）
	COleDateTime dt=COleDateTime::GetCurrentTime();  
	CString strDT=dt.Format("%Y-%m-%d");  
	CString str("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");  
	str+=strDT;  
	str+="\r\n";  
	sel.TypeText(str);  

	//添加表格
	_Document saveDoc=app.GetActiveDocument();  
	Tables tables=saveDoc.GetTables();  
	CComVariant defaultBehavior(1),AutoFitBehavior(1);  
	tables.Add(sel.GetRange(),7,11,&defaultBehavior,&AutoFitBehavior);  
	Table table=tables.Item(1);  
	sel.TypeText(_T("Test1"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test2"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test3"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test4"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test5"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test6"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test7"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test8"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test9"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test10"));  
	sel.MoveRight(COleVariant((short)1),COleVariant(short(1)),COleVariant(short(0)));  
	sel.TypeText(_T("Test11"));  
	for(int i=2;i<7;i+=2)  
	{  
		Cell c1=table.Cell(i,1);  // Cell对象代表表格中的一个单元格
		Cell c2=table.Cell(i+1,1);  
		c1.Merge(c2);  
		c1.ReleaseDispatch();  
		c2.ReleaseDispatch();  
	}  

	app.SetVisible(TRUE);  
	table.ReleaseDispatch();  
	tables.ReleaseDispatch();  
	sel.ReleaseDispatch();  
	docs.ReleaseDispatch();  
	saveDoc.ReleaseDispatch();  
	app.ReleaseDispatch();  
	app.SetVisible(TRUE);  

}
