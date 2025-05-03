#include<stdio.h>

void strncop(char *s1, char *s2){
	int i=0;
	while(*(s1+i)=*(s2+i)!= '\0')
		i++;
}
int main(){
	char s1[]="hello";
	char *s2;
	strncop(s2,s1);
	printf("%s",s2);
}
