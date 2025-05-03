#include<stdio.h>
#include<windows.h>

int main(){
	
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	
	//allocate memort
	ZeroMemory(&si,sizeof(si));
	si.cb=sizeof(si);
	ZeroMemory(&pi,sizeof(pi));
	puts("press any key to create child process#\n");
	getch();
	BOOL psuccess;
	//create a process
	psuccess=CreateProcess(NULL,	//use cmd line
		"threads.exe",	//command to pass
		NULL,	//dont inherit process handle
		NULL,	//dont inherit thread handle
		FALSE,	//disable handle inheritance
		0,		//no creation flag
		NULL,	//use parents env block
		NULL,	//use parents directory
		&si,
		&pi
	);
	
	
	if(!psuccess){
		printf("error: unable to start process!\n");
		return -1;
	}
	DWORD pid,thid;
	pid=pi.dwProcessId;
	thid=pi.dwThreadId;
	printf("child process created with pid-%d \n...executing...\n",pid);
	//parent will wait for child to complete
	WaitForSingleObject(pi.hProcess,INFINITE);
	printf("\nchild process with pid: %d threadid: %d completed.\n",pid,thid);
	CloseHandle(pi.hThread);
	CloseHandle(pi.hProcess);
	getch();
	return 0;
}		
