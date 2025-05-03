#include<stdio.h>
#include<string.h>
#define MAXBUFF 100000
#define MAXLINE 10000
#define MAXLINES 1000
//buffer stores text lines
char buffer[MAXBUFF];
int buff_curs=0;	//buffer curser 

int getline(char line[], int max){
	//gets a line from stdin
	int c,i=0;
	c=getchar();
	if(c==EOF)
		return -1;
	line[i++]=c;
	while((c=getchar()) !='\n' && i<max)
		line[i++]=c;	
	line[i++]='\0';
	return i;
}

int append(char buff[], char line[]){
	//appends a line to buffer
	int i=0;
	while((buff[buff_curs++]=line[i++])!='\0')
		;
	return buff_curs;
}

int readlines(char *lineptr[], int maxlines){
	//
	int len,nlines=0;
	char line[MAXLINE];
	char *p;
	
	while(len=getline(line,MAXLINE)){
		if(len<0)
			break;
		if(len+buff_curs >= MAXBUFF || nlines >= maxlines)
			return -1;
		p=&buffer[buff_curs];
		append(buffer,line);
		lineptr[nlines++]=p;
	}
	return nlines;
}

int process_arg(int *d, int argc, char *argv[]){
	if(argc==2){
		if(strcmp(argv[1],"-d")==0){
			*d=1;
			return 0;
		}
	}
	return 1;
}

void writelines(char *lineptr[], int nlines){
	int i=0;
	while(i<nlines)
		printf("%s\n",lineptr[i++]);
}

void ascend(char *records[], int i, int j){
	char *tmp;
	if(strcmp(records[i],records[j])>0){
		tmp=records[i];
		records[i]=records[j];
		records[j]=tmp;
	}
}

void descend(char *records[], int i, int j){
	char *tmp;
	if(strcmp(records[i],records[j])<0){
		tmp=records[i];
		records[i]=records[j];
		records[j]=tmp;
	}
}

void sort(char *records[], int nlines, void (*analyse)(char *rec[],int,int)){
	
	int i,j,flag;
	i=0;
	while(i<nlines){
		j=flag=0;
		while(j<nlines-1){
			analyse(records,j,j+1);
			j++;		
		}
		i++;
	}
}

int main(int argc, char *argv[]){
	
	//processing arguments
	int d_switch=0;	//d_switch=1 if sort in descending order 
	if(argc>1)
		if(process_arg(&d_switch,argc,argv)){
			printf("\nUsage: qsort -option.\n");
			printf("Option: -d :: sort in descending fashion.\n");
			return -1;
		}
	
	printf("\nDebug: d_switch=%d\n",d_switch);
	
	char *records[MAXLINES];
	int nlines;
	if((nlines=readlines(records,MAXLINES))>0){
		if(d_switch==0){
			printf("\nSorted lines(Ascending order):\n"); 
			sort(records,nlines,ascend);	
		}
		else if(d_switch==1){
			printf("\nSorted lines(Descending order):\n");
			sort(records,nlines,descend);
		}			
		writelines(records,nlines);
		return 0;
	}
	else{
		printf("\nError: buffer overflow!!!\n");
		printf("lines too long to sort.\n");
		return -1;
	}		
}
