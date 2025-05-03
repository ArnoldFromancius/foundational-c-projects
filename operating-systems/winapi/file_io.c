#include<stdio.h>
#include<windows.h>
#define MAXFNAME 55
#define MAXBUFF 1000

int main(){
	
	char ifname[MAXFNAME],ofname[MAXFNAME];
	printf("enter input file name: ");
	scanf("%s",ifname);
	printf("enter ouput file name: ");
	scanf("%s",ofname);
	
	HANDLE hInf,hOutf;
	
	//open input file
	hInf=CreateFile(ifname,
		GENERIC_READ,
		FILE_SHARE_READ,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	
	//error handling for input file
	if(hInf==INVALID_HANDLE_VALUE){
		printf("error: unable to open input file!\n");
		return -1;
	}
	
	//open output file
	hOutf=CreateFile(ofname,
		GENERIC_WRITE,
		FILE_SHARE_WRITE,
		NULL,
		OPEN_EXISTING,
		FILE_ATTRIBUTE_NORMAL,
		NULL
	);
	
	//error handling for output file
	if(hInf==INVALID_HANDLE_VALUE){
		printf("error: unable to open or create output file!\n");
		return -1;
	}
	
	char buffer[MAXBUFF];
	
	DWORD dwmaxbuff=MAXBUFF-1, dwread, dwwritten;
	BOOL fsuccess;
	
	//read from input file to buffer
	fsuccess=ReadFile(hInf,buffer,dwmaxbuff,&dwread,NULL);
	if(!fsuccess){
		printf("error: unable to read input file!\n");
		return -1;
	}	
	
	//write from buffer to output file
	fsuccess=WriteFile(hOutf,buffer,dwread,&dwwritten,NULL);
	if(!fsuccess){
		printf("error: unable to write to output file!\n");
		return -1;
	}
		
	//on success
	printf("Success!!!\n");
	CloseHandle(hInf);
	CloseHandle(hOutf);
	return 0;
}
