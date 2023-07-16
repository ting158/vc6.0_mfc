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
	app.SetVisible(true); // ���� Word Ӧ�ó���ɼ�
	app.SetWindowState(1); // �� Word ������С��
	Documents docs = app.GetDocuments(); // ��ȡ�ĵ����϶���

	_Font font;
	Paragraph para;

	CComVariant Template(_T("")); // ʹ�ÿ�ģ�崴�����ĵ�
	CComVariant NewTemplate(false), DocumentType(0), Visible;
	_Document doc;
	doc = docs.Add(&Template, &NewTemplate, &DocumentType, &Visible); // �½��ĵ�

	Selection sel = app.GetSelection(); // ��ȡѡ���������
	sel.TypeText("hello word"); // �����ı�
	sel.TypeParagraph(); // �������
	
	//����ҳüҳ��
	Window   mWindowActive;   //�������ڶ���
	View   mViewActive;   //������ͼ����
	Pane   mPane;   //���嵱ǰ�������
	Fields fields;
	mWindowActive=app.GetActiveWindow(); //��õ�ǰ���� 
	mPane=mWindowActive.GetActivePane();   //��õ�ǰ����
	mViewActive=mPane.GetView();   //��õ�ǰ��ͼ
	mViewActive.SetSeekView(9);   //����ҳü��ͼ
	font.SetSize(15);
	sel.TypeText("ҳü��������������������������"); 
	font.SetSize(7);
	mViewActive.SetSeekView(10);   //����ҳ����ͼ
	sel.TypeText("- ");
	fields.Add(sel.GetRange(),COleVariant(short(33)),COleVariant("PAGE  "),COleVariant(short(1))); //����ҳ����
	sel.TypeText(" -");
	font.SetSize(6);
	para.SetAlignment(1);   //����
	sel.TypeText("����ҳ����ͼ"); 
	para.SetAlignment(1);   //����
	mViewActive.SetSeekView(0); //�ص�������ͼ


	// ʹ�� COleVariant �ඨ�����
	COleVariant vtOptional((long)DISP_E_PARAMNOTFOUND, VT_ERROR), vtTrue((short)TRUE), vtFalse((short)FALSE);

	Paragraphs paras = doc.GetParagraphs(); // ��ȡ���伯�϶���
	para = paras.Item(1); // ��ȡ�ĵ��ĵ�һ��
	para.SetAlignment(2); // ���ö����Ҷ���
	para.SetSpaceAfter(6); // ���ö����о�
	Range range = para.GetRange(); // ��ȡ������ı���Χ����
	font = range.GetFont(); // ��ȡ�������
	font.SetSize(18); // ���������С
	font.SetBold(1); // ���ô���
	range.SetFont(font); // Ӧ���������õ��ı���Χ

	sel.TypeText(_T("\t\t\t\t\t\t\t\t\t����:ʷ��\t�Ա�:��\t\t ����:22\t"));

	para.SetAlignment(1); // ���ö�����ж���

	para = paras.Item(2); // ��ȡ�ĵ��ĵڶ���
	para.SetAlignment(1); // ���ö�����ж���
	para.SetSpaceAfter(6); // ���ö����о�
	range = para.GetRange(); // ��ȡ������ı���Χ����
	font = range.GetFont(); // ��ȡ�������
	font.SetSize(12); // ���������С
	range.SetFont(font); // Ӧ���������õ��ı���Χ

	sel.TypeParagraph(); // ����հ׶���
	sel.TypeParagraph();
	sel.TypeText(_T("ѧ����\r\n")); 

	para.SetAlignment(1); // ���ö�����ж���
	// ��ӱ��
	_Document saveDoc = app.GetActiveDocument(); // ��ȡ��ǰ������ĵ�
	Tables tables = saveDoc.GetTables(); // ��ȡ��񼯺϶���
	CComVariant defaultBehavior(1), AutoFitBehavior(1);  //���ñ���Ĭ����Ϊ������Ӧ��Ϊ�Ĳ���
	tables.Add(sel.GetRange(), 3, 6, &defaultBehavior, &AutoFitBehavior); // ���һ�� 3 �� 3 �еı��
	Table table = tables.Item(1); // ��ȡ��һ�����
	sel.TypeText(_T("ѧ��")); // ����������
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("����"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("�Ա�")); 
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("����"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("רҵ")); 
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("�༶")); 
	sel.MoveDown(COleVariant((short)4),COleVariant((short)1),COleVariant((short)0));
	sel.TypeText(_T("1025454256")); 
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("����"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("��"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("20"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("������Ϣ"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("����һ��")); 
	sel.MoveDown(COleVariant((short)4),COleVariant((short)1),COleVariant((short)0));
	sel.TypeText(_T("1234566666")); 
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("����"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("��"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("20"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("�������ѧ�뼼��"));
	sel.MoveRight(COleVariant((short)1), COleVariant((short)1), COleVariant((short)0));
	sel.TypeText(_T("�ƿ�һ��"));

	sel.MoveDown(COleVariant((short)4),COleVariant((short)1),COleVariant((short)0));
	sel.MoveDown(COleVariant((short)5),COleVariant((short)1),COleVariant((short)0));
	

	app.SetVisible(TRUE); // ���� Word Ӧ�ó���ɼ�
	table.ReleaseDispatch();
	tables.ReleaseDispatch();
	sel.ReleaseDispatch();
	docs.ReleaseDispatch();
	saveDoc.ReleaseDispatch();
	app.ReleaseDispatch();
	app.SetVisible(TRUE); // ���� Word Ӧ�ó���ɼ�

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

	CString strName="С��",strSex="��",strAge="24";
	Selection sel = app.GetSelection();
	sel.TypeText("���չ�ҵ��ѧ�������ѧ�뼼��ѧԺ\r\n209������");
	sel.TypeParagraph();
	sel.TypeText("����:"+strName+"\t�Ա�:"+strSex+"\t\t ����:"+strAge+"\t");

	sel.TypeText("\t\t\t\t\t\t\t");
	COleVariant vtOptional((long)DISP_E_PARAMNOTFOUND,VT_ERROR),vtTrue((short)TRUE),vtFalse((short)FALSE);// ʹ��COleVariant�࣬�������
	sel.InsertDateTime(COleVariant("yyyy-MM-dd HH-mm-ss"),vtFalse,vtOptional,vtOptional,vtOptional);//���õ�ǰʱ��

	
	Paragraphs paras = doc.GetParagraphs();
	Paragraph para = paras.Item(1);//paras.Item(1)  ѡ���ĵ���һ��
	para.SetAlignment(1);//���ж��루��������ֵ���Ըı䣩
	para.SetSpaceAfter(6);//���ö����о�
	Range range = para.GetRange();
	_Font font = range.GetFont();// ��ȡ�������
	font.SetSize(18);//���������С
	font.SetBold(1);//����
	range.SetFont(font);//��
	

	para = paras.Item(2);
	para.SetAlignment(2); 
	para.SetSpaceAfter(6); 
	range = para.GetRange();
	font = range.GetFont();
	font.SetSize(12); 
	range.SetFont(font); 


	sel.TypeParagraph();sel.TypeParagraph();sel.TypeParagraph();
	sel.TypeText(_T("\t\t\t\t\t\t\t--------------�ɼ���\r\n"));  
	//����ʱ�䣨ͬ�ϣ�
	COleDateTime dt=COleDateTime::GetCurrentTime();  
	CString strDT=dt.Format("%Y-%m-%d");  
	CString str("\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t");  
	str+=strDT;  
	str+="\r\n";  
	sel.TypeText(str);  

	//��ӱ��
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
		Cell c1=table.Cell(i,1);  // Cell����������е�һ����Ԫ��
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
