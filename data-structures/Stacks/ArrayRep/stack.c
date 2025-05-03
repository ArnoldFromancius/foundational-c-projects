#include<stdio.h>
#include<stdlib.h>

int peek(int*);
int pop(int*);
void push(int*,int);
main(){
	int top,max,stack[10];
	int v1,v2;
	
	stack[0]=4;
	stack[1]=9;
	stack[2]=7;
	stack[3]=5;
	stack[4]=0;
	
	//push(stack,10);
	//push(stack,23);
	
	//v2=pop(stack);
	v1=peek(stack);
	printf("%d ",v1);
}

int peek(int *stack){
	int top=0;
	
	while(*(stack+top) != 0){
		top++;
		if(*(stack+top+1)==0){
			break;
		}
	}
	return *(stack+top);
}

int pop(int *stack){
	int top=0,var;
	
	while(*(stack+top) != 0){
		top++;
		if(*(stack+top+2)==0){
			var=*(stack+top+1);
			*(stack+top+1)=0;
			break;
		}
	}
	return var;
}

void push(int *stack,int var){
	int top=0;
	
	while(*(stack+top) != 0){
		top++;
		if(*(stack+top+1)==0){
			*(stack+top+1)=var;
			*(stack+top+2)=0;
			break;
		}
	}
}


