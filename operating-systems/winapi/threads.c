//returns max,min and average of a list
#include<stdio.h>
#include<windows.h>
#define LISTSIZE 20
#define MAXTHREADS 3

//create and init the list
DWORD LIST[LISTSIZE]={
12,4,6,78,9,4,5,3,44,5,66,7,3,33,7,8,997,7,88,8};

DWORD WINAPI max_val(LPVOID lst){
	DWORD i=0,ReturnValue;
	PDWORD list=(DWORD*)lst;
	ReturnValue=*list;
	i++;
	while(i<LISTSIZE-1){
		if(*(list+i)>ReturnValue)
			ReturnValue=*(list+i);
		i++;
	}
	printf("Max: %d\n",ReturnValue);
	return 0;
}

DWORD WINAPI min_val(LPVOID lst){
	DWORD i=0,ReturnValue;
	PDWORD list=(DWORD*)lst;
	ReturnValue=*list;
	i++;
	while(i<LISTSIZE-1){
		if(*(list+i)<ReturnValue)
			ReturnValue=*(list+i);
		i++;
	}
	printf("Min: %d\n",ReturnValue);
}

DWORD WINAPI avg_val(LPVOID lst){
	DWORD i=0,ReturnValue=0;
	PDWORD list=(DWORD*)lst;
	while(i<LISTSIZE-1){
		ReturnValue+=*(list+i);
		i++;	
	}	
	printf("Average: %d\n",ReturnValue/LISTSIZE);
}


int main(){
	DWORD average,minimum,maximum;
	
	LPVOID LIST_POINTER=LIST;
	HANDLE Thread1_Handle,Thread2_Handle,Thread3_Handle;
	HANDLE ThreadList[MAXTHREADS];
	DWORD Th1Flag,Th2Flag,Th3Flag;
	
	//creating the threads
	Thread1_Handle=CreateThread(
		NULL,
		0,
		max_val,
		LIST_POINTER,
		0,
		&Th1Flag
	);
	if(Thread1_Handle==NULL){
		fprintf(stderr,"error creating thread 1#\n");
		return 1;
	}

	Thread2_Handle=CreateThread(
		NULL,
		0,
		min_val,
		LIST_POINTER,
		0,
		&Th2Flag
	);
	if(Thread2_Handle==NULL){
		fprintf(stderr,"error creating thread 2#\n");
		return 1;
	}
	
	Thread3_Handle=CreateThread(
		NULL,
		0,
		avg_val,
		LIST_POINTER,
		0,
		&Th3Flag
	);
	if(Thread3_Handle==NULL){
		fprintf(stderr,"error creating thread 3#\n");
		return 1;
	}
		
	ThreadList[0]=Thread1_Handle;
	ThreadList[1]=Thread2_Handle;
	ThreadList[2]=Thread3_Handle;
	
	WaitForMultipleObjects(MAXTHREADS,ThreadList,TRUE,INFINITE);
	CloseHandle(Thread1_Handle);
	CloseHandle(Thread2_Handle);
	CloseHandle(Thread3_Handle);
	
	return 0;
}
