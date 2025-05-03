#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

int peek(struct node *stack);
struct node* pop(struct node *stack);
struct node* push(struct node *stack, int var);

main(){
	struct node* stack;
	struct node* trav;
	struct node* ptr;
	stack=malloc(sizeof(struct node));
	trav=malloc(sizeof(struct node));
	ptr=malloc(sizeof(struct node));
	stack=NULL;
	int* i,j,k;
	stack=push(stack,34);
	stack=push(stack,56);
	stack=push(stack,11);
	stack=push(stack,8);
	stack=push(stack,4);
	stack=push(stack,5);
	stack=push(stack,78);
	
	//j=(peek(stack))+(peek(stack));
	stack=pop(stack);
	stack=pop(stack);

	
	//printf("%d\n\n\n",j);//peek(stack));
	
	
	trav=stack;
	
	do{
		if(trav == NULL){
			printf("UNDERFLOW!;");
			getch();
			exit(0);
		}
		
		printf("%d-> ",trav->data);	
		trav=trav->next;
		if(trav->next == NULL){
			printf("%d\n",trav->data);
		}
	}
	while(trav->next != NULL);
	
}

struct node* pop(struct node *stack){
	if(stack==NULL){
		return NULL;
	}
	struct node* top;
	top=malloc(sizeof(struct node));
	top=stack;
	stack=stack->next;
	
	free(top);
	
	return stack;
}

int peek(struct node *stack){
	if(stack==NULL){
		return -1;
	}
	return stack->data;
}

struct node* push(struct node *stack, int var){
	struct node* top;
	top=malloc(sizeof(struct node));
	
	if(stack==NULL){
		top->data=var;
		top->next=NULL;
		stack=top;
		return stack;
	}
	top->data=var;
	top->next=stack;
	return top;
}
