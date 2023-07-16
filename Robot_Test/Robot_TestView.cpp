// Robot_TestView.cpp : implementation of the CRobot_TestView class
//

#include "stdafx.h"
#include "Robot_Test.h"

#include "Robot_TestDoc.h"
#include "Robot_TestView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRobot_TestView

IMPLEMENT_DYNCREATE(CRobot_TestView, CView)

BEGIN_MESSAGE_MAP(CRobot_TestView, CView)
	//{{AFX_MSG_MAP(CRobot_TestView)
	ON_COMMAND(ID_M_Select, OnMSelect)
	ON_COMMAND(ID_M_Update, OnMUpdate)
	ON_COMMAND(ID_M_Create, OnMCreate)
	ON_COMMAND(ID_M_DeleteRobot, OnMDeleteRobot)
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRobot_TestView construction/destruction

CRobot_TestView::CRobot_TestView()
{
	// TODO: add construction code here

}

CRobot_TestView::~CRobot_TestView()
{
}

BOOL CRobot_TestView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CRobot_TestView drawing

void CRobot_TestView::OnDraw(CDC* pDC)
{
	CRobot_TestDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
	
	m_Robot.InitRobot();
	m_Robot.Draw(pDC);
	
	
}

/////////////////////////////////////////////////////////////////////////////
// CRobot_TestView printing

BOOL CRobot_TestView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CRobot_TestView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CRobot_TestView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CRobot_TestView diagnostics

#ifdef _DEBUG
void CRobot_TestView::AssertValid() const
{
	CView::AssertValid();
}

void CRobot_TestView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CRobot_TestDoc* CRobot_TestView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CRobot_TestDoc)));
	return (CRobot_TestDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CRobot_TestView message handlers

void CRobot_TestView::OnMSelect() 
{
	// TODO: Add your command handler code here

	//将当前robot名称赋值给对话框
	m_dlg.m_RobotName = m_Robot.m_CurRobotName;

	if(m_dlg.DoModal()==IDOK)
	{
		//输入要查询的机器人名称
		m_Robot.m_CurRobotName = m_dlg.m_RobotName;
		m_Robot.InitRobot();
	}

	//进行查询(刷新)
	Invalidate(true);
}

void CRobot_TestView::OnMUpdate() 
{
	// TODO: Add your command handler code here
	CString value;

	m_Robot.m_dlg.m_RobotName = m_Robot.m_CurRobotName;
	value.Format("%d",m_Robot.m_X);
	m_Robot.m_dlg.m_X = value;

	value.Format(_T("%d"), m_Robot.m_Y);
	m_Robot.m_dlg.m_Y = value;

	value.Format(_T("%f"), m_Robot.m_Xhead);
	m_Robot.m_dlg.m_Xhead = value;

	value.Format(_T("%f"), m_Robot.m_Yhead);
	m_Robot.m_dlg.m_Yhead = value;

	value.Format(_T("%f"), m_Robot.m_Rhead);
	m_Robot.m_dlg.m_Rhead = value;

	value.Format(_T("%f"), m_Robot.m_Xlefteye);
	m_Robot.m_dlg.m_Xlefteye = value;

	value.Format(_T("%f"), m_Robot.m_Ylefteye);
	m_Robot.m_dlg.m_Ylefteye = value;

	value.Format(_T("%f"), m_Robot.m_Rlefteye);
	m_Robot.m_dlg.m_Rlefteye = value;

	value.Format(_T("%f"), m_Robot.m_Xrighteye);
	m_Robot.m_dlg.m_Xrighteye = value;

	value.Format(_T("%f"), m_Robot.m_Yrighteye);
	m_Robot.m_dlg.m_Yrighteye = value;

	value.Format(_T("%f"), m_Robot.m_Rrighteye);
	m_Robot.m_dlg.m_Rrighteye = value;

	value.Format(_T("%f"), m_Robot.m_Xnose);
	m_Robot.m_dlg.m_Xnose = value;

	value.Format(_T("%f"), m_Robot.m_Ynose);
	m_Robot.m_dlg.m_Ynose = value;

	value.Format(_T("%f"), m_Robot.m_Lnose);
	m_Robot.m_dlg.m_Lnose = value;

	value.Format(_T("%f"), m_Robot.m_Xmouth);
	m_Robot.m_dlg.m_Xmouth = value;

	value.Format(_T("%f"), m_Robot.m_Ymouth);
	m_Robot.m_dlg.m_Ymouth = value;

	value.Format(_T("%f"), m_Robot.m_Lmouth);
	m_Robot.m_dlg.m_Lmouth = value;

	value.Format(_T("%f"), m_Robot.m_Smouth);
	m_Robot.m_dlg.m_Smouth = value;

	value.Format(_T("%f"), m_Robot.m_Xneck);
	m_Robot.m_dlg.m_Xneck = value;

	value.Format(_T("%f"), m_Robot.m_Yneck);
	m_Robot.m_dlg.m_Yneck = value;

	value.Format(_T("%f"), m_Robot.m_Wneck);
	m_Robot.m_dlg.m_Wneck = value;

	value.Format(_T("%f"), m_Robot.m_Hneck);
	m_Robot.m_dlg.m_Hneck = value;

	value.Format(_T("%f"), m_Robot.m_Xleftarm);
	m_Robot.m_dlg.m_Xleftarm = value;

	value.Format(_T("%f"), m_Robot.m_Yleftarm);
	m_Robot.m_dlg.m_Yleftarm = value;

	value.Format(_T("%f"), m_Robot.m_Wleftarm);
	m_Robot.m_dlg.m_Wleftarm = value;

	value.Format(_T("%f"), m_Robot.m_Hleftarm);
	m_Robot.m_dlg.m_Hleftarm = value;

	value.Format(_T("%f"), m_Robot.m_Xrightarm);
	m_Robot.m_dlg.m_Xrightarm = value;

	value.Format(_T("%f"), m_Robot.m_Yrightarm);
	m_Robot.m_dlg.m_Yrightarm = value;

	value.Format(_T("%f"), m_Robot.m_Wrightarm);
	m_Robot.m_dlg.m_Wrightarm = value;

	value.Format(_T("%f"), m_Robot.m_Hrightarm);
	m_Robot.m_dlg.m_Hrightarm = value;

	value.Format(_T("%f"), m_Robot.m_Xbody);
	m_Robot.m_dlg.m_Xbody = value;

	value.Format(_T("%f"), m_Robot.m_Ybody);
	m_Robot.m_dlg.m_Ybody = value;

	value.Format(_T("%f"), m_Robot.m_Wbody);
	m_Robot.m_dlg.m_Wbody = value;

	value.Format(_T("%f"), m_Robot.m_Hbody);
	m_Robot.m_dlg.m_Hbody = value;

	value.Format(_T("%f"), m_Robot.m_Xleftleg);
	m_Robot.m_dlg.m_Xleftleg = value;

	value.Format(_T("%f"), m_Robot.m_Yleftleg);
	m_Robot.m_dlg.m_Yleftleg = value;

	value.Format(_T("%f"), m_Robot.m_Wleftleg);
	m_Robot.m_dlg.m_Wleftleg = value;

	value.Format(_T("%f"), m_Robot.m_Hleftleg);
	m_Robot.m_dlg.m_Hleftleg = value;

	value.Format(_T("%f"), m_Robot.m_Xrightleg);
	m_Robot.m_dlg.m_Xrightleg = value;

	value.Format(_T("%f"), m_Robot.m_Yrightleg);
	m_Robot.m_dlg.m_Yrightleg = value;

	value.Format(_T("%f"), m_Robot.m_Wrightleg);
	m_Robot.m_dlg.m_Wrightleg = value;

	value.Format(_T("%f"), m_Robot.m_Hrightleg);
	m_Robot.m_dlg.m_Hrightleg = value;

	value.Format(_T("%f"), m_Robot.m_Xleftfoot);
	m_Robot.m_dlg.m_Xleftfoot = value;

	value.Format(_T("%f"), m_Robot.m_Yleftfoot);
	m_Robot.m_dlg.m_Yleftfoot = value;

	value.Format(_T("%f"), m_Robot.m_Wleftfoot);
	m_Robot.m_dlg.m_Wleftfoot = value;

	value.Format(_T("%f"), m_Robot.m_Hleftfoot);
	m_Robot.m_dlg.m_Hleftfoot = value;

	value.Format(_T("%f"), m_Robot.m_Xrightfoot);
	m_Robot.m_dlg.m_Xrightfoot = value;

	value.Format(_T("%f"), m_Robot.m_Yrightfoot);
	m_Robot.m_dlg.m_Yrightfoot = value;

	value.Format(_T("%f"), m_Robot.m_Wrightfoot);
	m_Robot.m_dlg.m_Wrightfoot = value;

	value.Format(_T("%f"), m_Robot.m_Hrightfoot);
	m_Robot.m_dlg.m_Hrightfoot = value;


	if(m_Robot.m_dlg.DoModal()==IDOK)
	{
		m_Robot.UpdateRobot();
		Invalidate(true);

	}
}

void CRobot_TestView::OnMCreate() 
{
	// TODO: Add your command handler code here
	if(m_Robot.m_dlg.DoModal()==IDOK)
	{
		m_Robot.CreateRobot();

	}
}

void CRobot_TestView::OnMDeleteRobot() 
{
	// TODO: Add your command handler code here

	//删除当前选择的机器人
	m_Robot.DeleteRobot();
	Invalidate(true);
}
