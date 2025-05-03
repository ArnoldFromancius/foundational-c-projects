#include<stdio.h>
#define EDGE1 4
#define EDGE2 4
int graph[4][4];

int init_matrix(){
	int i,j;
	for(i=0;i<EDGE1;i++){
		for(j=0;j<EDGE2;j++){
			graph[i][j]=0;
		}
	}
}

int addEdge(int edgeStart, int edgeStop){
	graph[edgeStart][edgeStop] = 1;	
}

int displayGraph(){
	int i,j;
	for(i=0;i<EDGE1;i++){
		for(j=0;j<EDGE2;j++){
			printf("%d",graph[i][j]);
		}
		printf("\n");
	}
}

int main(void){
	
	init_matrix();
	displayGraph();
}
