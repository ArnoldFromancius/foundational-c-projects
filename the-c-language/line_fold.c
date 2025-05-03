#include<stdio.h>
#define SCREENWIDTH 10

char line[SCREENWIDTH];

void printl(int pos){
	int i;
	for(i=0;i<pos;i++)
		putchar(line[i]);
	putchar('\n');
}

int findblnk(int pos){
	while(pos>=0 && line[pos]!=' ')
		pos--;
	if(pos==0)	//if no blank space present in line
		return SCREENWIDTH;
	return pos;
}

int newpos(int pos){
	if(pos==0)
		return pos;
	else if(line[pos]==' ');
		pos++;
		
	int i,j;
	i=0;
	j=pos;
	while(j<=SCREENWIDTH){
		line[i]=line[j];
		i++;
		j++;
	}
	return i;
}

int main(){
	int c,pos;
	pos=0;
	while((c=getchar())!=EOF){
		line[pos]=c;
		if(c=='\n'){
			printl(pos);
			pos=0;
		}
		else if(pos >= SCREENWIDTH){
			pos=findblnk(pos);
			printl(pos);
			pos=newpos(pos);
		}
		else	
			pos++;
	}
}
