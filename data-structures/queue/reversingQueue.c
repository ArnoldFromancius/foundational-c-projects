/*TITLE: REVERSING A QUEUE.
  DESCRITPTION: TO REVERSE A LINEAR QUEUE USING A STACK.
  AUTHOR: ARNOLD FROMANCIUS.
  DATE: 7/12/2019.
*/

#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node* next;
}node;

node* queue;
node* stack;


int enque(int);
int deque();
void peek();
void disp();
node* reverse(node*);

int main(){
	queue=NULL;
	stack=NULL;
	int x,y,z,opt;
	
	do{
		printf("\nSelect option:\n");
		printf("1. Enque.\n");
		printf("2. Deque.\n");
		printf("3. Reverse.\n");
		printf("4. Peek.\n");
		printf("5. Display.\n");
		printf("6. Exit.\n");
		scanf("%d",&opt);
		
		switch(opt){
			case 1: printf("...enter data... ");
					scanf("%d",&x);
					z=enque(x);
					printf("\nSuccess!!!\n");
					break;
					
			case 2: z=deque();
					if(z==-1){ printf("\nQueue is empty!!!\n"); }
					else{ printf("\nSuccess!!!\n");				}
					break;
					
			case 3: reverse(queue);
					if(queue==NULL){
						printf("\nQueue empty!!!\n");
						break;
					}
					printf("\nSuccess!!!\n");
					break;
					
			case 4: peek();
					break;
					
			case 5: disp();
					break;
					
			case 6: break;
		}
	}while(opt != 6);
	
	return 0;
}

node* reverse(node* q){
	int tmp=0;
	//if not init
	if(q==NULL){
		return NULL;
	}
	//if only one element in q
	if(q->next==NULL){
		return q;
	}
	//push queue elements to stack
	while(q != NULL){
		push(q->data);
		q=q->next;
	}
	//as stack is lifo, popping stack elements into queue will be reversed
	queue=NULL;
	while(tmp != -1){
		tmp=pop();
		if(tmp==-1){
			break;
		}
		enque(tmp);
	}
}

int push(int val){
	node* newnode;
	newnode=malloc(sizeof(node));
	newnode->data=val;
	//check if stack init
	if(stack==NULL){
		stack=malloc(sizeof(node));
		stack->data=val;
		stack->next=NULL;
		return 0;
	}
	newnode->next=stack;
	stack=newnode;
	return 0;
}

int pop(){
	int val;
	node* temp;
	temp=malloc(sizeof(node));
	//if stack empty
	if(stack==NULL){
		return -1;
	}
	//if only one element in stack
	if(stack->next==NULL){
		val=stack->data;
		stack=NULL;
		return val;
	}
	//otherwise
	temp=stack;
	val=temp->data;
	stack=stack->next;
	free(temp);
	return val;
}

int enque(int val){
	node* trav;
	node* newnode;
	trav=malloc(sizeof(node));
	newnode=malloc(sizeof(node));
	newnode->data=val;
	newnode->next=NULL;
	//if queue not init
	if(queue==NULL){
		queue=malloc(sizeof(node));
		queue->data=val;
		queue->next=NULL;
		return 0;
	}
	trav=queue;
	//if only one element in queue
	if(trav->next==NULL){
		trav->next=newnode;
		return 0;
	}
	//otherwise
	while(trav->next != NULL){
		trav=trav->next;
	}
	trav->next=newnode;
	return 0;
}

int deque(){
	int val;
	node* temp;
	temp=malloc(sizeof(node));
	//check if queue init
	if(queue==NULL){
		return -1;
	}
	//if only one element in queue
	if(queue->next==NULL){
		val=queue->data;
		queue=NULL;
		return val;
	}
	//otherwise
	temp=queue;
	queue=queue->next;
	val=temp->data;
	free(temp);
	return val;
}

void peek(){
	//check if queue init
	if(queue==NULL){
		printf("\nQueue is empty!!!\n");
	}
	else{
		printf("\nData in front of queue: %d",queue->data);
	}
}

void disp(){
	node* trav;
	trav=malloc(sizeof(node));
	trav=queue;
	//check if queue init
	if(queue==NULL){
		printf("\nQueue is empty!!!\n");
	}
	while(trav != NULL){
		printf("%d\t",trav->data);
		trav=trav->next;
	}
}
