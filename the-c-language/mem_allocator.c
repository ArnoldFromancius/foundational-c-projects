#include<stdio.h>
#define ALLOCSIZE 10000		//maximum storage allocatable

char alloc_buff[ALLOCSIZE];	//buffer of maximum storage allocatable
char *allocp=alloc_buff;	//curser pointing to position in buffer
char *alloc(int n){
	//return pointer to first element of allocated storage
	//n-> size to allocate
	char *return_val;
	if(allocp+n <= alloc_buff+ALLOCSIZE){
		return_val=allocp;
		allocp+=n;
		return	return_val;
	}
	else 
		return NULL;
	
}

void afree(char *p){
	if(p>allocp && p<alloc_buff+ALLOCSIZE)
		allocp=p;
}

int main(){
	char *ptr;
	ptr=alloc(1000000);
	afree(ptr);
	printf("%d",ptr);
}
