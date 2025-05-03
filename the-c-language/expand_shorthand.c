//expands shorthands a-z,a-z0-1 etc into string of all chars in between
#include<stdio.h>
#define STRINGLEN 10
#define LINELEN 100

void expand(char s1[], char s2[]){
	int i,j,m,n,c;
	i=j=0;
	while((c=s1[i++])!='\0'){
		if(s1[i]=='-'){
			m=c;
			n=s1[i+1];
			while(m<=n){
				s2[j++]=m++;
			}
		}
	}
	s2[j]='\0';
} 

int main(){
	char s1[STRINGLEN],s2[LINELEN];
	scanf("%s",s1);
	expand(s1,s2);
	printf("%s",s2);
	return 0;
}
