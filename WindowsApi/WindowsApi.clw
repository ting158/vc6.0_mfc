; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CWindowsApiDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "WindowsApi.h"

ClassCount=3
Class1=CWindowsApiApp
Class2=CWindowsApiDlg
Class3=CAboutDlg

ResourceCount=3
Resource1=IDD_ABOUTBOX
Resource2=IDR_MAINFRAME
Resource3=IDD_WINDOWSAPI_DIALOG

[CLS:CWindowsApiApp]
Type=0
HeaderFile=WindowsApi.h
ImplementationFile=WindowsApi.cpp
Filter=N

[CLS:CWindowsApiDlg]
Type=0
HeaderFile=WindowsApiDlg.h
ImplementationFile=WindowsApiDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_ObtainSystemHardwareInformation

[CLS:CAboutDlg]
Type=0
HeaderFile=WindowsApiDlg.h
ImplementationFile=WindowsApiDlg.cpp
Filter=D

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WINDOWSAPI_DIALOG]
Type=1
Class=CWindowsApiDlg
ControlCount=6
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_DeleteDirectory,button,1342242816
Control4=IDC_FindAllFilesFormDir,button,1342242816
Control5=IDC_NowPath,button,1342242816
Control6=IDC_ObtainSystemHardwareInformation,button,1342242816

