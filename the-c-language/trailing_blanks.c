//Removes trailing blanks from an input line
#include<stdio.h>
#define MAXLINE 1000
#define BUFFER_SIZE 10000

int getline(char line[], int length){
	int i=0,c;
	c=getchar();
	if(c==EOF){
		return -1;
	}
	else{
		line[i]=c;
		i++;
	}
	while((c=getchar())!='\n' && i<length){
		line[i]=c;
		i++;
	}
	line[i]='\n';
	return i;
}

int analyse(char string[]){
	//analyses string for leading white spaces and blank lines.
	//returns the index of start of string.
	int i=0;
	//finds end of line
	while(string[i]!='\n')	
		i++;
	//navigates through trailing blanks	
	while(string[i]==' ' || string[i]=='\t')  
		i--;
	//checks if line is completly blank
	if(i==0){
		return -1;
	}
	//modifies line to exclude trailing blanks
	i++;
	string[i]='\n';
	return i;
}

int append(char buff[], char txt[], int pos, int lower_bound, int upper_bound){
	//appends given line to main buffer. returns curser position of buffer.
	//pos->current curser position of buffer
	//l_bound->index of string from where to begin copying used to mitigate white spaces#
	//h_bound->limit index where to stop copying
	
	//checks if line is completly blank
	if(upper_bound==1|| lower_bound==-1)
		return pos;
	//copying to buffer	
	while(lower_bound<upper_bound){
		buff[pos]=txt[lower_bound];
		++pos;
		++lower_bound;
	}
	return pos;
}


void dis_buff(char buff[], int len){
	//prints buffer content
	int i;
	for(i=0;i<len;++i)
		printf("%c",buff[i]);
}

main(){
	int i,c,pos=0,count=0; 
	char buff[BUFFER_SIZE],line[MAXLINE];
	
	while((c=getline(line,MAXLINE))!=-1){
		i=analyse(line);
		if(i!=-1)
			pos=append(buff,line,pos,0,i);		
	}

	dis_buff(buff,pos);
	
	return 0;
}
