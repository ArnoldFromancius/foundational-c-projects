//Removes leading blanks from an input line
#include<stdio.h>
#define MAXLINE 1000
#define BUFFER_SIZE 10000

int analyse(char string[]){
	//analyses string for trailing white spaces and blank lines.
	//returns the index from where whitespace' ' ends.
	int i=0;
	while(string[i]==' '|| string[i]=='\t')
		i++;
	//checks if line is completly blank
	if(string[i]=='\n')
		return -1;
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
	
	while((c=getchar())!=EOF){
		line[count]=c;
		if(c=='\n'){
			line[++count]='\n';
			i=analyse(line);	
			pos=append(buff,line,pos,i,count);			
			count=0;
		}
		else{
			++count;
		}
	}

	dis_buff(buff,pos);
	
	return 0;
}
