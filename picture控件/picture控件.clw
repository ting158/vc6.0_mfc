; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CDlgPaintHuoJian
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "picture控件.h"
LastPage=0

ClassCount=7
Class1=CPictureApp
Class2=CPictureDoc
Class3=CPictureView
Class4=CMainFrame

ResourceCount=4
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Class5=CAboutDlg
Class6=CDlgHuoJian
Resource3=IDD_DIALOG1
Class7=CDlgPaintHuoJian
Resource4=IDD_DIALOG2

[CLS:CPictureApp]
Type=0
HeaderFile=picture控件.h
ImplementationFile=picture控件.cpp
Filter=N

[CLS:CPictureDoc]
Type=0
HeaderFile=picture控件Doc.h
ImplementationFile=picture控件Doc.cpp
Filter=N

[CLS:CPictureView]
Type=0
HeaderFile=picture控件View.h
ImplementationFile=picture控件View.cpp
Filter=C
LastObject=CPictureView
BaseClass=CView
VirtualFilter=VWC


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
BaseClass=CFrameWnd
VirtualFilter=fWC
LastObject=IDD_DIALOG2




[CLS:CAboutDlg]
Type=0
HeaderFile=picture控件.cpp
ImplementationFile=picture控件.cpp
Filter=D

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
Command17=IDB_HuoJian
Command18=IDD_DIALOG2
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

[DLG:IDD_DIALOG1]
Type=1
Class=CDlgHuoJian
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342177294

[CLS:CDlgHuoJian]
Type=0
HeaderFile=DlgHuoJian.h
ImplementationFile=DlgHuoJian.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgHuoJian

[DLG:IDD_DIALOG2]
Type=1
Class=CDlgPaintHuoJian
ControlCount=2
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342177294

[CLS:CDlgPaintHuoJian]
Type=0
HeaderFile=DlgPaintHuoJian.h
ImplementationFile=DlgPaintHuoJian.cpp
BaseClass=CDialog
Filter=D
LastObject=CDlgPaintHuoJian
VirtualFilter=dWC

