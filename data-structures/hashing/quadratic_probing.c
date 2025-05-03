//quadratic probing
#include<stdio.h>
#define MAX 15


int htable[MAX];

void init_htable(){
	int cur=0;
	while(cur<=MAX){
		htable[cur]=-1;
		cur++;
	}
}

int hash(int val){
	
	int probe_no=0,hk=val%MAX,return_val;
	int pfactor_1=3,pfactor_2=5;
	return_val=(hk + (pfactor_1*probe_no) + (pfactor_2*probe_no)) % MAX;
	
	while(1){
		if(htable[return_val] == -1){
			return return_val;
		}
		else if(probe_no > MAX){
			return -1;
		}
		probe_no++;
		return_val=(hk +  (pfactor_1*probe_no) + (pfactor_2*probe_no)) % MAX;
	}	
}

int ins(int val){
	int hash_val;
	hash_val=hash(val);
	if(hash_val == -1){
		return -1; //overflow
	}
	htable[hash_val]=val;
	return 0;	
}

int del(int val){
	int hk,pno=0,hash_val;
	int pf_1=3,pf_2=5;
	//calculation location
	hk=val%MAX;
	hash_val=(hk +  (pf_1*pno) + (pf_2*pno))%MAX;
	while(htable[hash_val] != val){
		pno++;
		hash_val=(hk +  (pf_1*pno) + (pf_2*pno))%MAX;
		if(pno >= MAX){
			return -1;
		}
	}
	if(htable[hash_val] == val){
		htable[hash_val]=-1;
		return 0;
	}
}

void disp(){
	int cur=0;
	printf("\n*** debug ***\n");
	printf(" displaying values in hash table... \n");
	while(cur <= MAX){
		printf(" * %d \n",htable[cur]);
		cur++;
	}
}

int main(){
	init_htable();
	int x,y,opt;
	do{
		printf("\n_ HASH TABLE(Quadratic probing) _\n");
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
