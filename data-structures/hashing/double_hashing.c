//double hashing
#include<stdio.h>
#define MAX 15

int htable[MAX];

void init_htable(){
	int cur=0;
	while(cur <= MAX){
		htable[cur]=-1;
		cur++;
	}
}

int hash(int val){
	int probe=0,H,h1,h2,m1=MAX,m2=MAX-2;
	h1=val%m1;
	h2=val%m2;
	H=(h1+(probe*h2))%MAX;
	if(htable[H]==-1){
		return H;
	}
	while(htable[H] != -1){
		probe++;
		H=(h1+(probe*h2))%MAX;
		if(probe > MAX){
			return -1;
		}
	}
	return H;
}

int ins(int val){
	int hash_val;
	hash_val=hash(val);
	if(hash_val==-1){
		return -1;
	}
	htable[hash_val]=val;
	return 0;
}

int del(int val){
	int H,h1,h2,m1=MAX,m2=MAX-2,probe=0;
	h1=val%m1;
	h2=val%m2;
	
	H=(h1 + (probe*h2))%MAX;
	if(htable[H] == val){
		htable[H]=-1;
		return 0;
	}
	while(1){
		probe++;
		H=(h1 + (probe*h2))%MAX;
		
		if(probe>=MAX || htable[H]==-1){
			return -1;
		}
		if(htable[H] == val){
			htable[H]=-1;
		return 0;
		}
	}
}

void disp(){
	int cur=0;
	printf("\n*** debug info ***\n");
	printf(" displaying hash table contents...\n");
	while(cur<MAX){
		printf(" * %d\n",htable[cur]);
		cur++;
	}
}

int main(){
	init_htable();
	int x,y,opt;
	do{
		printf("\n_ HASH TABLE(Double Hashing ##) _\n");
		printf(" 1. insert. \n");
		printf(" 2. delete. \n");
		printf(" 3. display. \n");
		printf(" 4. exit. \n");
		scanf("%d",&opt);
		
		switch(opt){
			case 1: printf("...enter data... ");
					scanf("%d",&x);
					y=ins(x);
					if(y==-1){
						printf("\nError!!!\n");
					}
					else{
						printf("\nSuccess!!!\n");
					}
					break;
					
			case 2: printf("...enter data... ");
					scanf("%d",&x);
					y=del(x);
					if(y==-1){
						printf("\nError!!!\n");
					}
					else{
						printf("\nSuccess!!!\n");
					}
					break;
			
			case 3: disp();
					break;
					
			case 4: break;
			
			default: printf("\ninvalid option!\n");
		}
	}while(opt != 4);
	return 0;
}
