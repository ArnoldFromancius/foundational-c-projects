//reverses a string via recursion
		#include<stdio.h>
#define MAXSTRING 20

void swap(char *s, char *c, char *lim){
	char tmp=*s;
	if(s==c){
		*s=*lim;
		*lim=tmp;
		return ;	
	}
	*s=*lim;
	*lim=tmp;
	swap((s+1),c,(lim-1));
}

void reverse(char s[]){
	
	int len=0,mid_val;
	while(s[len]!='\0')	//find lenth of string
		len++;			//i dont trust strlen()
	--len;
	
	mid_val=len/2;			//noting the middle most char in string
	char *m=&s[mid_val];	//collecting address of middle val
	
	swap(s,m,&s[len]);		//recursively swap values in string to reverse it
}

int main(){
	int i=0;
	char s[MAXSTRING];
	do{
		printf("\nenter string to reverse(* to quit): ");
		scanf("%s",s);
		reverse(s);
		printf("%s",s);	
	}while(s[i]!='*');
	
}
