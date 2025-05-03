#include<stdio.h>
#define TABINC 8
#define MAXBUFF 1000

int main(){
	int c,nb,bp,tab,pos;
	char buff[MAXBUFF];
	
	
	bp=pos=0;
	while((c=getchar())!=EOF){
		if(c==' '){
			tab=TABINC;
			nb=tab-((pos-1)%tab);
			if(nb==1){
				buff[bp++]=' ';
				pos++;
				continue;
			}
			while(nb>0){
				buff[bp++]=' ';
				pos++;
				nb--;
			}
		}
		else if(c=='\n'){
			buff[bp++]='\n';
			pos=1;
		}
		else{
			buff[bp++]=c;
			pos++;
		}
	}
	buff[bp]='\0';
	
	printf("\n%s",buff);
}
