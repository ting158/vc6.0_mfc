; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CControl_SystemView
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "Control_System.h"
LastPage=0

ClassCount=7
Class1=CControl_SystemApp
Class2=CControl_SystemDoc
Class3=CControl_SystemView
Class4=CMainFrame

ResourceCount=4
Resource1=IDR_MAINFRAME
Resource2=IDD_ABOUTBOX
Class5=CAboutDlg
Class6=CDlgSet
Resource3=IDD_Set
Class7=CDlgSetEfficiency
Resource4=IDD_DIALOG1

[CLS:CControl_SystemApp]
Type=0
HeaderFile=Control_System.h
ImplementationFile=Control_System.cpp
Filter=N

[CLS:CControl_SystemDoc]
Type=0
HeaderFile=Control_SystemDoc.h
ImplementationFile=Control_SystemDoc.cpp
Filter=N

[CLS:CControl_SystemView]
Type=0
HeaderFile=Control_SystemView.h
ImplementationFile=Control_SystemView.cpp
Filter=C
BaseClass=CView
VirtualFilter=VWC
LastObject=ID_M_Efficiency


[CLS:CMainFrame]
Type=0
HeaderFile=MainFrm.h
ImplementationFile=MainFrm.cpp
Filter=T
LastObject=CMainFrame




[CLS:CAboutDlg]
Type=0
HeaderFile=Control_System.cpp
ImplementationFile=Control_System.cpp
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
Command1=ID_M_Start
Command2=ID_M_Stop
Command3=ID_M_Restart
Command4=ID_M_YunSu
Command5=ID_M_YunJiaSu
Command6=ID_M_ZhengXian
Command7=ID_M_Set
Command8=ID_M_AllCurve
Command9=ID_M_WeiYi
Command10=ID_M_SuDu
Command11=ID_M_JiaSuDu
Command12=ID_M_Friction
Command13=ID_M_Efficiency
CommandCount=13

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

[DLG:IDD_Set]
Type=1
Class=CDlgSet
ControlCount=17
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_KpX,edit,1350631552
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_KpV,edit,1350631552
Control9=IDC_KpA,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_KiX,edit,1350631552
Control13=IDC_KiV,edit,1350631552
Control14=IDC_KiA,edit,1350631552
Control15=IDC_KdX,edit,1350631552
Control16=IDC_KdV,edit,1350631552
Control17=IDC_KdA,edit,1350631552

[CLS:CDlgSet]
Type=0
HeaderFile=DlgSet.h
ImplementationFile=DlgSet.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgSet

[DLG:IDD_DIALOG1]
Type=1
Class=CDlgSetEfficiency
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_Efficiency,edit,1350631552
Control4=IDC_STATIC,static,1342308352

[CLS:CDlgSetEfficiency]
Type=0
HeaderFile=DlgSetEfficiency.h
ImplementationFile=DlgSetEfficiency.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDlgSetEfficiency

