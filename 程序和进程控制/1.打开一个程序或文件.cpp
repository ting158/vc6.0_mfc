#include <iostream>
#include <windows.h>

using namespace std;




int main() {

	 ShellExecute(NULL, "open", "a.txt", NULL, NULL, SW_SHOWNORMAL);
	
//	WinExec("D:\\VC6.0\\MyProjects\\mfc\\̰����\\Debug\\̰����.exe", SW_SHOW);


	return 0;
}