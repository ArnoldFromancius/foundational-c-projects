//simple hex to dec string converter
#include<stdio.h>
#define INLENGTH 10
#define OUTLENGTH 15

long htoi(char s[]){
	int i=0;
	if(s[i]=='*'){
		return -9999;
	}
	
	while(s[i]=='0' && s[i+1]=='x'||s[i+1]=='X')
		i+=2;
		
	int hex,count;
	hex=count=0;
	while(s[i]!='\0'){
		if(s[i]>='0'&&s[i]<='9'){
			hex+=(s[i]-'0');
		}
		else if(s[i]>='A'&&s[i]<='F'){
			hex+=(s[i]-'A')+10;
		}
		else if(s[i]>='a'&&s[i]<='f'){
			hex+=(s[i]-'a')+10;
		}
		else
			return hex=-1111;
		i++;
	}

	return hex;
}

int main(){
	
	char s[INLENGTH];
	int hex=0;
	
	while(1){
		printf("'*' to exit:  ");
		scanf("%s",s);
		hex=htoi(s);
		if(hex==-1111)
			printf("Invalid!");
		else if(hex==-9999)
			return 0;
		else
			printf("%ld",hex);
		putchar('\n');
	}	
}
