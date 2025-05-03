//converts an int to other base
#include<stdio.h>
#define MAXWIDTH 10 //width of number in string	

void itob(int num, char s[], int base){
	//converts int to base base
	int i,n,sign=0;
	
	//considering negative numbers
	if(num<0){
		sign=-1;
		num*=-1;
	}
	
	//generate digits (in reverse order)
	i=0;
	while(num > 0){
		n=num%base;
		if(n<='9')
			s[i++]=n+'0';
		else 
			s[i++]=n+'a'-10;			
		num/=base;			
	}
	
	if(sign==-1)
		s[i++]='-';
		
	s[i]='\0';
	
	//reverse the string to get correct data
	int tmp,j=i-1;
	for(i=0;i<j;i++,j--){
		tmp=s[i];
		s[i]=s[j];
		s[j]=tmp;
	}
}
int main(){
	int num=512,base=2;
	char s[MAXWIDTH];
	itob(num,s,base);
	printf("%s",s);	
}
