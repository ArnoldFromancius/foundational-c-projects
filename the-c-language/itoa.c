//converts an int to string
#include<stdio.h>
#define MAXWIDTH 10 //width of number in string	

void ita(int num, char s[], int width){
	//converts int to string
	int i,n,sign=0;
	
	//considering negative numbers
	if(num<0){
		sign=-1;
		num*=-1;
	}
	
	//generate digits (in reverse order)
	i=0;
	while(1){
		s[i++]=num%10+'0';
		//printf("%d\n",s[i]);
		num/=10;
		if(num/10 <= 0){
			s[i++]=num%10+'0';
			break;
		}
			
	}
	
	if(sign==-1)
		s[i++]='-';
		
	//checking for width
	while(i<width-1)
		s[i++]=' ';
			
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
	int num=-765156;
	char s[MAXWIDTH];
	ita(num,s,MAXWIDTH);
	printf("%s",s);	
}
