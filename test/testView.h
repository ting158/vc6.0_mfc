// testView.h : interface of the CTestView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TESTVIEW_H__F97CE7F3_D746_4900_B581_744478CDB896__INCLUDED_)
#define AFX_TESTVIEW_H__F97CE7F3_D746_4900_B581_744478CDB896__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

typedef struct
{
	POINT posL; //���嵯�����ϽǶ��㣨�þ���ģ�ⵯ�ɣ�
	float len,width; //���嵯�ɵĳ��ȺͿ��
	float k; //���嵯�ɵĵ���ϵ��
	float s; //���嵯�ɱ������ĳ��ȣ�����Ϊ����ѹ��Ϊ����
}MySpring; //���嵯�ɽṹ��

typedef struct
{
	POINT center; //�������С������
	int radius; //�������С�򣩰뾶
	float m,v,a; //�������С���������ٶȣ����ٶ�
}MyObject; //��������ṹ��


class CTestView : public CView
{
protected: // create from serialization only
	CTestView();
	DECLARE_DYNCREATE(CTestView)

// Attributes
public:
	CTestDoc* GetDocument();

// Operations
public:
	MySpring m_spring;
	MyObject m_object;


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTestView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	void DrawLine(CDC *pDC, MySpring spring, MyObject object);
	void DrawObject(CDC *pDC, MyObject object);
	void DrawSpring(CDC *pDC, MySpring spring);
	virtual ~CTestView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTestView)
	afx_msg void OnMStart();
	afx_msg void OnMStop();
	afx_msg void OnTimer(UINT nIDEvent);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in testView.cpp
inline CTestDoc* CTestView::GetDocument()
   { return (CTestDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TESTVIEW_H__F97CE7F3_D746_4900_B581_744478CDB896__INCLUDED_)
