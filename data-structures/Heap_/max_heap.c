  //MAX Heap
  #include<stdio.h>
  #define MAX 30
  
  int curser=0,heap[MAX];
  
  int ins(int val){
  	curser++;
  	int pos=curser;
	heap[curser]=val;
  	
  	//floating val to appropriate location
	int par,temp;
	while(1){
		par=(pos/2);
		if(heap[pos] <= heap[par] || par < 1 ){
			return 0;
		}
		else{
			temp=heap[par];
			heap[par]=heap[pos];
			heap[pos]=temp;				
		}
		pos=par;
	}
}

int rem(){
	if(curser == 0){
		printf("\nheap is empty!!!\n");
		return -9999;
	}
	
	int return_value=heap[1];
	heap[1]=heap[curser];
	curser--;
	
	int temp,left,right,pos=1;
	
	while(1){
		left=pos*2;
		right=(pos*2)+1;
		
		if(heap[pos]<heap[right] || heap[pos]<heap[left]){
			if(heap[right] > heap[left]){
				temp=heap[right];
				heap[right]=heap[pos];
				heap[pos]=temp;
				pos=right;
			}
			else{
				temp=heap[left];
				heap[left]=heap[pos];
				heap[pos]=temp;
				pos=left;
			}
		}
		else{
			return return_value;
		}
	}		
}

void disp(){
	int cur=1;
	
	if(curser==0){
		printf("\nheap is empty!!!\n");
		return ;
	}
	
	printf("\n");
	while(cur <= curser){
		printf(" %d ",heap[cur]);
		cur++;
	}
	printf("\n");
	
}

int main(){
	//for debugging purposes
	/*	
	ins(45);
	ins(36);
	ins(54);
	ins(27);
	ins(63);
	ins(72);
	ins(61);
	ins(18);
	disp();
	rem();
	disp();
	*/
	
	//main code starts here
	int opt,x,y;
	
	do{
		printf("\n--MAX HEAP__\n");
		printf("Select option:\n");
		printf("1. Add to heap.\n");
		printf("2. Remove max.\n");
		printf("3. Display heap.\n");
		printf("4. Exit\n");
		scanf("%d",&opt);
		
		switch(opt){
			case 1: printf("...enter data... ");
					scanf("%d",&x);
					y=ins(x);
					if(y==0){
						printf("Success!!!\n\n");
					}
					else{
						printf("Error!!!\n\n");
					}
					break;
					
			case 2: y=rem();
					if(y==-9999){
						printf("\nError!!!\n\n");
					}
					else{
						printf("\nValue removed: %d\n\n", y);
					}
					break;
					
			case 3: disp();
					break;
					
			case 4: break;
			
			default: printf("\nInvalid option!!!\n");
					 break;
		}
	}while(opt != 4);
	
	return 0;
}
