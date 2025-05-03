#include<stdio.h>

void reverse(char *s){
	char *tmp,temp;
	int i=0;
	while(*(s+i)!='\0')
		i++;
	tmp=(s+i)-1;
	i=0;
	while((s+i)<tmp){
		temp=*(s+i);
		*(s+i)=*tmp;
		*tmp=temp;
		tmp--;
		i++;
	}
}
int strend(char *s1, char *s2){	//checks if s2 occurs at end of s1
	reverse(s1);
	reverse(s2);
	int i=0,ret;
	while(*(s1+i)==*(s2+i) != '\0')
		i++;
	if(*(s2+i)=='\0')
		ret=1;
	else
		ret=0;
	reverse(s1);
	reverse(s2);
	return ret;
}

int main(){
	char s1[]="chocolatebar";
	char s2[]="ebar";
	int result=strend(s1,s2);
	//reverse(s1);
	printf("%d",result);
}
