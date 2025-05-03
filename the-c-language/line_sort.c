#include<stdio.h>
#include<string.h>
#define MAXMEM	1000	//max allocatable memory
#define MAXLINES 5000	//max no of lines to be sorted
#define MAXLEN 1000	//maxlength of a given line

char allocbuff[MAXMEM];
char *allocptr=allocbuff;

char *alloc(int size){
	int offset=allocptr-allocbuff;
	char *return_val;
	
	if(size+offset <= MAXMEM){
		return_val=allocptr;
		allocptr+=size;
		return return_val;
	}
	printf("Error: stack overflow!!!\n");
	return NULL;		
}

char *lineptr[MAXLINES];

int getline(char s[], int lim){
	int c,i=0;
	c=getchar();
	if(c==EOF)
		return -1;
	else if(c=='\n')
		return 1;
	s[i++]=c;
	while((c=getchar())!='\n')
		s[i++]=c;
	s[i]='\0';
	return ++i;
}

int readlines(char *lineptr[], int maxlines){
	char *p,line[MAXLEN];
	int nlines=0,len;
	
	while((len=getline(line,MAXLEN))>0){
		if((p=alloc(len))==NULL || nlines>=maxlines){
			return -1;
		}
		if(len==1)		//ignores empty lines
			continue;		
		strcpy(p,line);
		lineptr[nlines]=p;
		nlines++;
	}
	return nlines;
}

void writelines(char *lineptr[], int nlines){
	int i=0;
	while(i<nlines){
		printf("%s\n",lineptr[i]);
		i++;
	}
}
	

void sort(char *lineptr[], int n){
	int i=0,j,flag,x;
	char *temp;
	while(i<n){
		j=flag=0;
		
		while(j<n-1){
			if(x=(strcmp(lineptr[j],lineptr[j+1]))>0){
				
				temp=lineptr[j+1];
				lineptr[j+1]=lineptr[j];
				lineptr[j]=temp;
			}		
			j++;
		}		
		i++;
	}
}

main(){
	printf("Enter lines of text. (ctrl-z) on blank line to continue...\n");
	int nlines;		//no of input lines
	if((nlines=readlines(lineptr,MAXLINES)) >= 0){
		sort(lineptr,nlines);
		printf("\nSorted output:\n");
		writelines(lineptr,nlines);
		return 0;
	}
	else{
		printf("Error: input too big to sort!\n");
		return 1;		
	}
}
