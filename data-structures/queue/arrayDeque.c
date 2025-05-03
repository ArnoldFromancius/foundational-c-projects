/*TITLE: DOUBLE ENDED QUEUE(ARRAY IMPLEMENTATION).
  DESCRIPTION: AN ARRAY IMPLEMENTETION OF A DEQUE, DOUBLE ENDED QUEUE.
  AUTHOR: ARNOLD FROMANCIUS.
  DATE: 2/12/2019.
 */
 
 #include<stdio.h>
 #define MAX 10
 
 int queue[MAX];
 int front=-1;
 int rear=-1;  
 
 int insFront(int);
 int insRear(int);
 int delFront();
 int delRear();
 void disp();
 void peek();
 
 int main(){
 	int opt,x,y,z;
 	
 	do{
 		printf("\nSelect option:\n");
 		printf("1. Insert at front.\n");
 		printf("2. Insert at rear.\n");
 		printf("3. Remove from front.\n");
 		printf("4. Remove from rear.\n");
 		printf("5. Peek.\n");
 		printf("6. Display queue.\n");
 		printf("7. Exit\n");
 		scanf("%d",&opt);
 		
 		switch(opt){
 			case 1: printf("\n...enter data... ");
 					scanf("%d",&x);
 					z=insFront(x);
 					if(z==-1){
 						printf("\nQueue is full!!!\n");
 						break;
					 }
					 else{
					 	printf("\nSuccess!!!\n");
					 	break;
					 }
					 
			case 2: printf("\n...enter data... ");
 					scanf("%d",&x);
 					z=insRear(x);
 					if(z==-1){
 						printf("\nQueue is full!!!\n");
 						break;
					 }
					 else{
					 	printf("\nSuccess!!!\n");
					 	break;
					 }
					 
			case 3: z=delFront();
					if(z==-1){
						printf("\nQueue is empty!!!\n");
						break;
					}
					else{
						printf("\nSuccess!!! data deleted: %d\n",z);
						break;
					}
					
			case 4: z=delRear();
					if(z==-1){
						printf("\nQueue is empty!!!\n");
						break;
					}
					else{
						printf("\nSuccess!!! data deleted: %d\n",z);
						break;
					}
					
			case 5: peek();
					break;
					
			case 6: disp();
					break;
					
			case 7: break;
		 }
	 }while(opt != 7);
 	
 	return 0;
 }
 
 int insFront(int val){
 	
 	//condition 1(queue not initialised)
 	if(front==-1 && rear==-1){
 		front=rear=0;
 		queue[front]=val;
 		return 0;
	 }
	//condition 2: if front<rear ie: "<-[f][][][r][][]"  or  "[][][]<-[f][][r][][]"  or  "[][][<-f,r][][][]"
	if(front<=rear && rear<MAX-1){
		if(front==0){
			front=MAX-1;
			queue[front]=val;
			return 0;
		}
		else{
			front--;
			queue[front]=val;
			return 0;
		}
	}
	//condition 3: if front>rear ie: "[][r][][]<-[f][]" or [][r][][][][]<-[f]
	if(front>rear && (front-1) != rear){
		front--;
		queue[front]=val;
		return 0;
	}
	//else overflow
	return -1;
 }
 
 int insRear(int val){
 	//condition 1(check if queue initialised)
	 if(rear==-1 && front==-1){
	 	rear=front=0;
	 	queue[rear]=val;
	 	return 0;
	 }	
	 //condition2: if rear>=front but less than max ie: "[f][][]->[r][][][]" or "[][][f][][r]->[][]"
	 if(rear>=front && rear<(MAX-1)){
	 	rear++;
	 	queue[rear]=val;
	 	return 0;
	 }
	 //condition 3: if r>F & r=Max ie "[][f][][][][r]"
	 if(rear>=front && rear==(MAX-1)){
	 	rear=0;
	 	queue[rear];
	 	return 0;
	 }
	 //condition 4: if rear<front ie: "[][][r]->[][][f][][]"
	 if(rear<front && (rear+1) != front){
	 	rear++;
	 	queue[rear]=val;
	 	return 0;
	 }
	 //else overflow
	 return -1;
 }
 
 int delFront(){
 	int rtval;
 	rtval=queue[front];
 	//check for underflow
 	if(front==-1){
 		return -1;
	 }
	 //condition 1: if f and r at same pos ie: "[f,r][][][][][]" 
	 if(front==rear){
	 	front=rear=-1;
	 	return rtval;
	 }
	 //condition 2: if f<r ie: "[f]->[][][][r][][]
	 if(front<rear){
	 	front++;
	 	return rtval;
	 }
	 //condition 3: if f>r ie: "[][][][r][][][f->][]
	 if(front>rear){
	 	if(front==MAX-1){
	 		front=0;
	 		return rtval;
		 }
		 else{
		 	front++;
		 	return rtval;
		 }
	 }
 }
 
 int delRear(){
 	int rtval=queue[rear];
 	//check for underflow
	 if(rear==-1){
	 	return -1;
	 }	
	 //condition 1: if r and f are at same pos ie: "[f,r][][][][][]"
	 if(rear==front){
	 	rear=front=-1;
	 	return rtval;
	 }
	 //condition 2: if r>f ie: "[f][][r][][][]"
	 if(rear>front){
	 	rear--;
	 	return rtval;
	 }
	 //condtion 3: if r<f ie: "[][][r][][f][][]" or "[r][][][f][][]"
	 if(rear<front){
	 	if(rear==0){
	 		rear=MAX-1;
	 		return rtval;
		 }
		 else{
		 	rear--;
		 	return rtval;
		 }
	 }
 }
 
 void peek(){
 	//check for underflow
 	if(front==-1 && rear==-1){
 		printf("\nQueue is empty!!!\n");
	 }
	 else{
	 	printf("\nValue at front: %d\n",queue[front]);
	 	printf("\nValue at end: %d\n",queue[rear]);
	 }
 }
  
 void disp(){
 	int i=front;
	 //check for underflow
 	if(front==-1 && rear==-1){
 		printf("\nDeque is empty!!!\n");
	 }
	 else if(front<=rear){
	 	printf("\n\n");
		 while(i<=rear){
	 		printf("%d\t",queue[i]);
	 		i++;
		 }
	 }
	 else if(front>rear){
	 	while(i<=MAX-1){
	 		printf("%d\t",queue[i]);
	 		i++;
		 }
		 i=0;
		 while(i<=rear){
		 	printf("%d\t",queue[i]);
	 		i++;
		 }
	 }
 }
