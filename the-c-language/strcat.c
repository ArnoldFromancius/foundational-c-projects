#include<stdio.h>

void strncant(char *s1, char *s2){
	int i=0;
	while(*(s1+i) != '\0')
		i++;
	while((*(s1+i) = *s2++)!='\0')
		i++;
}

int main(){
	char s1[]="hello";
	char s2[]=" world";
	strncant(s1,s2);
	printf("%s",s1);
}
