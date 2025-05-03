/*TITLE: MULTIPLE QUEUES
  DESCRIPTION: IMPLEMENTING MULTIPLE QUEUES USING A SINGLE ARRAY,
  			   BASICALLY PARTITION THE ARRAY INTO SMALLER QUEUES.
  AUTHOR: ARNOLD FROMANCIUS.
  DATE: 01/12/2019.
*/
#include<stdio.h>
#define MAX 10

int queue[MAX];
int aFront=-1;
int aRear=-1;
int bFront=MAX;
int bRear=MAX;

int insA(int);
int insB(int);
void dispA();
void dispB();

int main(){
	int opt,x,y,z;
	do{
		printf("\nSelect option:\n");
		printf("1. Enque queue A.\n");
		printf("2. Dequeu queue A\n");
		printf("3. Display queue A.\n");
		printf("4. Enque queue B.\n");
		printf("5. Dequeu queue B\n");
		printf("6. Display queue B.\n");
		printf("7. Exit.\n");
		scanf("%d",&opt);
		
		switch(opt){
			// QUEUE A OPTIONS
			case 1: printf("...enter data... ");
					scanf("%d",&x);
					z=insA(x);
					if(z==-1){
						printf("\nQueue is full!!!\n");
						break;
					}
					else{
						printf("\nSuccess!!!\n");
						break;
					}
					
			case 2: z=delA();
					if(z==-1){
						printf("\nQueue is empty!!!\n");
						break;
					}
					else{
						printf("\nSuccess: Value deleted :: %d",z);
						break;
					}
			case 3: dispA();
					break;
			
			// QUEUE B OPTIONS
			case 4: printf("...enter data... ");
					scanf("%d",&x);
					z=insB(x);
					if(z==-1){
						printf("\nQueue is full!!!\n");
						break;
					}
					else{
						printf("\nSuccess!!!\n");
						break;
					}
					
			case 5: z=delB();
					if(z==-1){
						printf("\nQueue is empty!!!\n");
						break;
					}
					else{
						printf("\nSuccess: Value deleted :: %d",z);
						break;
					}
			case 6: dispB();
					break;
					
			case 7: break;
		}
	}while(opt != 7);
		
	
	return 0;
}

int delA(){
	//check for underflow
	if(aRear == -1){
		return -1;
	}
	else{
		aRear--;
		return 0;
	}
}

int delB(){
	//check for underflow
	if(bRear == MAX){
		return -1;
	}
	else{
		bRear++;
		return 0;
	}
}

void dispA(){
	int i=aFront;
	//check for underflow
	if(aRear == -1){
		printf("\nQueue is empty!!!\n");
	}
	else{
		printf("\nQueue A:\n");
		while(i<=aRear){
			printf("%d\t",queue[i]);
			i++;
		}
	}
}

void dispB(){
	int i=bFront;
	//check for underflow
	if(bRear == MAX){
		printf("\nQueue is empty!!!\n");
	}
	else{
		printf("\nQueue B:\n");
		while(i >= bRear){
			printf("%d\t",queue[i]);
			i--;
		}
	}
}

int insA(int val){
	//check for overflow
	if(aRear == bRear-1){
		return -1;
	}
	//check if queue A is initialised, if not init
	else if(aRear == -1){
		aFront=aRear=0;
		queue[aRear]=val;
		return 0;
	}
	//if queue is initialised && queue is not full, add new element
	else{
		aRear++;
		queue[aRear]=val;
		return 0;
	}
}

int insB(int val){
	//check for overflow
	if(bRear == aRear+1){
		return -1;
	}
	//check if queue B is initialised, if not init
	else if(bRear == MAX){
		bFront=bRear=MAX-1;
		queue[bRear]=val;
		return 0;
	}
	//if queue is initialised && is not full, add new element
	else{
		bRear--;
		queue[bRear]=val;
		return 0;
	}
}
