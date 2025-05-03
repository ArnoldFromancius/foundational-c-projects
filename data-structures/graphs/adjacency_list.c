#include<stdio.h>
#define max_vertices 4

typedef struct list{
	int data;
	struct list *next;	
}list;

list *graph[max_vertices];

int init_matrix(){
	int i;
	for(i=0;i<max_vertices;i++){
		//graph[i]=(list*)malloc(sizeof(list));
		graph[i]->data=0;
		graph[i]->next=NULL;
	}
}

void disp_matrix(){
	int i;
	for(i=0;i<max_vertices;i++){
		//graph[i]=(list*)malloc(sizeof(list));
		printf("%d\n",graph[i]->data);
	}
}

int main(void){
	init_graph();
	disp_graph();
}
