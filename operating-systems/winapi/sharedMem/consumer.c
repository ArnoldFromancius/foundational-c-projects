#include<stdio.h>
#include<windows.h>

int main(){
	HANDLE hMapFile;
	LPVOID lpMapAddress;
	
	hMapFile=OpenFileMapping(FILE_MAP_ALL_ACCESS,
		FALSE,
		TEXT("sHAREDoBJECT")
	);
	
	lpMapAddress=MapViewOfFile(hMapFile,
		FILE_MAP_ALL_ACCESS,
		0,
		0,
		1000
	);
	
	printf("message in mem: %s",lpMapAddress);
	UnmapViewOfFile(lpMapAddress);
	CloseHandle(hMapFile);
}
