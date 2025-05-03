#include<stdio.h>
#define TABINC 8
#define MAXBUFF 1000

int main(){
	int c,nb,bp,tab,pos;
	char buff[MAXBUFF];
	
	
	bp=pos=0;
	while((c=getchar())!=EOF){
		if(c=='\t'){
			tab=TABINC;
			nb=tab-((pos-1)%tab);
			while(nb>0){
				buff[bp]=' ';
				bp++;
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
	
	printf("\n%s",buff);
}
