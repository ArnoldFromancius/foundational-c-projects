//removes comments from a c program
#include<stdio.h>
#define MAXLINE 1000
#define BUFFER_SIZE 100000
#define IN 1
#define OUT 0

void view_buff(char buff[], int buff_pos){
	int i=0;
	//printf("\n");
	while(i<buff_pos){
		printf("%c",buff[i]);
		i++;
	}
}

int getline(char line[], int maxlength){
	int i=0,c;
	c=getchar();
	if(c==EOF)
			return -1;
	
	line[i++]=c;
	while((c=getchar())!='\n' && i<maxlength){
		line[i]=c;
		i++;
	}
	line[i++]='\n';
	return i;
}

int analyse(char line[], int state, int *l_curs){
	//returns state 
	int i,j,count; 
	char temp[MAXLINE];
	
	append(temp,line,0,0,*l_curs);	//copy line to temp
	
	count=i=j=0;
	//scan the line for comments and store non comments in temp
	//appropiately copy temp elements back to line
	if(state==OUT){
		while(i<*l_curs){
			if(temp[i]=='/'&&temp[i+1]=='/'){
				if(count==0){
					*l_curs=-1;
					return state=OUT;
				}
				else{
					line[j]='\n';
					*l_curs=j;
					return state=OUT;
				}
			}
			if(temp[i]=='/'&&temp[i+1]=='*'){
				while(i<*l_curs){
					if(temp[i]=='*'&&temp[i+1]=='/'){
						if(temp[i+2]=='\n' && count==0){	//if entire line is comment 
							*l_curs=-1;
							return state=OUT;
						}
						i+=2;
						state=OUT;
						break;			
					}
					else if(i+1==*l_curs){
						line[j]='\n';
						*l_curs=j;
						return state=IN;
					}
					i++;
				}
			}
			count++;
			line[j]=temp[i];
			j++;
			i++;
		}
		
		line[j]='\n';
		*l_curs=j;
		//view_buff(line,j);
		return state=OUT;
	}
	
	else if(state==IN){
		while(i<*l_curs){
			if(temp[i]=='*'&&temp[i+1]=='/'){
				i+=2;
				while(i<*l_curs){
					line[j]=temp[i];
					i++;
					j++;
				}
				line[j]='\n';
				*l_curs=j;
				return state=OUT;
			}
			i++;
		}
		*l_curs=-1;
		return state=IN;
	}
}
 
int append(char buff[], char line[], int buff_pos, int lower, int upper){
	while(lower<upper){
		buff[buff_pos]=line[lower];
		buff_pos++;
		lower++;
	}	
	return buff_pos;
}

int main(){
	int state,buff_pos,lower,upper;
	char line[MAXLINE],buffer[BUFFER_SIZE];

	state=OUT;
	buff_pos=lower=0;
	printf("...enter[type in] a valid c program. enter[ctrl Z] on blank line to process:\n");
	while((upper=getline(line, MAXLINE)) != -1){
		state=analyse(line,state,&upper);
		if(upper>0)
		    buff_pos=append(buffer,line,buff_pos,lower,upper);
		else
			;
	}

	view_buff(buffer,buff_pos);
	return 0;
}
