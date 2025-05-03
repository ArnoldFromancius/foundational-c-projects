#include<stdio.h>
#include<windows.h>

int main(){
	HANDLE hFile,hMapFile;
	LPVOID lpMapAddress;
	
	hFile=CreateFile("temp.txt",
		GENERIC_READ|GENERIC_WRITE,
		0,
		NULL,
		OPEN_ALWAYS,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	
	hMapFile=CreateFileMapping(
		INVALID_HANDLE_VALUE,
		NULL,
		PAGE_READWRITE,
		0,
		1000,
		TEXT("sHAREDoBJECT")
	);
	
	lpMapAddress=MapViewOfFile(hMapFile,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		0
	);
	
	char MSG[]="Shared memory message...";
	strcpy(lpMapAddress,MSG);
	
	printf("%s",lpMapAddress);
	
	UnmapViewOfFile(lpMapAddress);
	
	CloseHandle(hFile);
	CloseHandle(hMapFile);
}
