//reverses input line
#include<stdio.h>
#define MAXLINE 1000
#define BUFFER_SIZE 10000

int getline(char line[], int length){
	int i=0,c;
	c=getchar();
	if(c==EOF)
		return -1;
	line[i++]=c;
	
	while((c=getchar())!='\n' && i<length)
		line[i++]=c;
		
	line[i++]='\n';
	line[i]='\0';
	return i;
}

int reverse(char line[]){
	int i=0,j,rt;
	char temp;
	//go to end of line
	while(line[i]!='\n')
		i++;
	rt=i;
	//leave '\n' in place
	i--;
	//beginning of line
	j=0;
	while(j<i){
		temp=line[j];
		line[j]=line[i];
		line[i]=temp;
		j++;
		i--;
	}
	return ++rt;
}

void disp(char line[], int i, int j){
	int x=i; int y=j;
	while(x<y){
		printf("%c",line[x++]);
	}
}
int main(){
	int i,j;
	char line[MAXLINE];
	while((i=getline(line,MAXLINE))!=-1){
		j=reverse(line);
		disp(line,0,j);
	}
	return 0;
}
