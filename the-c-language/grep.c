#include<stdio.h>
#include<string.h>
#define MAXBUFF 500000
#define MAXLINE 10000
#define MAXPATT 100


int argument_flag=0;	//indicates whether cmd arguments are provided

int getline(char s[], int max){
	//gets a line from std input
	int c,i=0;
	c=getchar();
	if(c==EOF)
		return -1;
	s[i++]=c;
	while(((c=getchar()) != '\n') && i<max)
		s[i++]=c;
	s[i++]='\0';
	return i;
}

int append(char buff[], char line[], int bp){
	//appends a line to buffer
	int i=0;
	while(line[i]!='\0')
		buff[bp++]=line[i++];
		
	buff[bp++]='\n';
	return bp;
}
void show_output_no_lcount(char buff[], int bp){
	//prints output without line numbers
	int i=0;
	while(i<bp)
		printf("%c",buff[i++]);
}

void show_output_lcount(char buff[], int bp, int lc[], int lim){
	//printfs output with line numbers
	int i,j;
	i=j=0;
	printf("ln#:%d ",lc[j++]);
	while(i<bp){
		printf("%c",buff[i]);
		if(buff[i]=='\n')
			if(j<lim)
				printf("ln#:%d ",lc[j++]);
		i++;
	}	
}

void arg_analysis(char *arg1, char *arg2, int argc, int *ln_switch, int *xm_switch)
{
	//analyses arguments	
	if(argc>2){
		if(arg1!=NULL){
			if(strcmp(arg1,"-xn")==0 || strcmp(arg1,"-nx")==0)
				*ln_switch=*xm_switch=1;
			else if(strcmp(arg1,"-x")==0)
				*xm_switch=1;
			else if(strcmp(arg1,"-xn"))
				*ln_switch=1;
		}
		if(arg2!=NULL){
			if(strcmp(arg2,"-x")==0)
				*xm_switch=1;
			else if(strcmp(arg2,"-xn"))
				*ln_switch=1;
		}
	}
	
}
int main(int argc, char *argv[]){
	char *arg1=NULL;
	char *arg2=NULL;
	char *pattern=NULL;
	
	
	//checking if pattern is provided via arguments
	if(argc>1){
		argument_flag=1;
		pattern=argv[1];
		if(argc==3)
			arg1=argv[2];
		else if(argc==4){
			arg1=argv[2];
			arg2=argv[3];
		}
		else if(argc>4){
			printf("\nUsage: grep pattern -options\n");
			printf("Options: (-n) show line #no.\n");
			printf("\t (-x) show lines that do not have pattern\n");
			return -1;
		}			
	}
	
	//command line argument analysis
	int ln_switch=0;	//switch to print line no.s in output
	int xm_switch=0;	//switch to exempt lines with pattern in output
	
	arg_analysis(arg1, arg2, argc, &ln_switch, &xm_switch);
	printf("Debug:pattern: %s ln_switch: %d xm_switch: %d\n",pattern,ln_switch,xm_switch);
	
	//incase pattern not provided via cmd arguments
	if(argument_flag==0){
		char patt[MAXPATT];
		int x;
		printf("Enter pattern to search: ");
		x=getline(patt,MAXPATT);
		if(x<0)
			return -1;
		pattern=patt;
	}
	
	//read main input lines
	int buff_pos=0,line_len;
	char buffer[MAXBUFF]; //buffer for text lines
	char line[MAXLINE];	//used to collect an input line at a time 
	char *ptr;			//returns pos of pattern in line or null if ... 
	int icount[MAXLINE];	//stores line no of lines containing pattern
	int jcount[MAXLINE];	//stores line no of lines not containing patt...
	int lc=0,i=0,j=0;
	
	//gets input lines from user and appends them appropriately to buffer
	//depending on cmd argument switches ie line count & xm_switch
	printf("\nInput text lines: \n");
	while((line_len=getline(line,MAXLINE)) > 0){
		lc++;
		ptr=strstr(line,pattern);
		if(xm_switch==1 && ptr==NULL){	//append lines not containing patter...
			buff_pos=append(buffer,line,buff_pos);
			icount[i++]=lc;
		}	
		else if(xm_switch==0 && ptr!=NULL){ //append lines containing pattern...
			buff_pos=append(buffer,line,buff_pos);
			jcount[j++]=lc;
		}
	}
	
	//output 
	//use appropriat line count storage
	if(xm_switch==0)
		if(ln_switch==0)
			show_output_no_lcount(buffer,buff_pos);
		else
			show_output_lcount(buffer,buff_pos,jcount,j);
	else if(xm_switch==1)
		if(ln_switch==0)
			show_output_no_lcount(buffer,buff_pos);
		else
			show_output_lcount(buffer,buff_pos,icount,i);
	return 0;	
}
