; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CMainFrame
LastTemplate=CFormView
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Aab.h"
LastPage=0

ClassCount=8
Class1=CAabApp
Class2=CAabDoc
Class3=CAabView
Class4=CMainFrame

ResourceCount=5
Resource1=IDR_MAINFRAME
Resource2=IDD_DIgMyView
Class5=CAboutDlg
Class6=CMyView
Resource3=IDD_ABOUTBOX
Resource4=IDD_DlgDrawCircle
Class7=CDrawCircleView
Class8=CDrawRectangleView
Resource5=IDD_DIgDrawRectangle

[CLS:CAabApp]
Type=0
HeaderFile=Aab.h
ImplementationFile=Aab.cpp
Filter=N

[CLS:CAabDoc]
Type=0
HeaderFile=AabDoc.h
ImplementationFile=AabDoc.cpp
Filter=N

[CLS:CAabView]
Type=0
HeaderFile=AabView.h
ImplementationFile=AabView.cpp
Filter=C


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=ID_M_DrawRectangle




[CLS:CAboutDlg]
Type=0
HeaderFile=Aab.cpp
ImplementationFile=Aab.cpp
Filter=D
LastObject=CAboutDlg

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[MNU:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_SAVE_AS
Command5=ID_FILE_PRINT
Command6=ID_FILE_PRINT_PREVIEW
Command7=ID_FILE_PRINT_SETUP
Command8=ID_FILE_MRU_FILE1
Command9=ID_APP_EXIT
Command10=ID_EDIT_UNDO
Command11=ID_EDIT_CUT
Command12=ID_EDIT_COPY
Command13=ID_EDIT_PASTE
Command14=ID_VIEW_TOOLBAR
Command15=ID_VIEW_STATUS_BAR
Command16=ID_APP_ABOUT
Command17=ID_M_DrawCircle
Command18=ID_M_DrawRectangle
CommandCount=18

[ACL:IDR_MAINFRAME]
Type=1
Class=CMainFrame
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_FILE_PRINT
Command5=ID_EDIT_UNDO
Command6=ID_EDIT_CUT
Command7=ID_EDIT_COPY
Command8=ID_EDIT_PASTE
Command9=ID_EDIT_UNDO
Command10=ID_EDIT_CUT
Command11=ID_EDIT_COPY
Command12=ID_EDIT_PASTE
Command13=ID_NEXT_PANE
Command14=ID_PREV_PANE
CommandCount=14

[TB:IDR_MAINFRAME]
Type=1
Class=?
Command1=ID_FILE_NEW
Command2=ID_FILE_OPEN
Command3=ID_FILE_SAVE
Command4=ID_EDIT_CUT
Command5=ID_EDIT_COPY
Command6=ID_EDIT_PASTE
Command7=ID_FILE_PRINT
Command8=ID_APP_ABOUT
CommandCount=8

[DLG:IDD_DIgMyView]
Type=1
Class=CMyView
ControlCount=0

[CLS:CMyView]
Type=0
HeaderFile=MyView.h
ImplementationFile=MyView.cpp
BaseClass=CFormView
Filter=D
LastObject=CMyView

[DLG:IDD_DlgDrawCircle]
Type=1
Class=CDrawCircleView
ControlCount=0

[DLG:IDD_DIgDrawRectangle]
Type=1
Class=CDrawRectangleView
ControlCount=0

[CLS:CDrawCircleView]
Type=0
HeaderFile=DrawCircleView.h
ImplementationFile=DrawCircleView.cpp
BaseClass=CFormView
Filter=D
LastObject=CDrawCircleView
VirtualFilter=VWC

[CLS:CDrawRectangleView]
Type=0
HeaderFile=DrawRectangleView.h
ImplementationFile=DrawRectangleView.cpp
BaseClass=CFormView
Filter=D
LastObject=CDrawRectangleView
VirtualFilter=VWC

