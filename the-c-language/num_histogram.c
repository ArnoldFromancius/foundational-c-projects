//prints histogram of frequency of input intergers
#include<stdio.h>
#define NUMSET 10
#define MAX_BAR_WIDTH 15

int main(){
	int i,k,c,minnum,numcount[NUMSET]={[0 ... 9]=0};
	int tmp,temp[NUMSET];
	printf("Pliz enter a sequence of numbers (ctrl Z to stop): \n");
	while((c=getchar())!=EOF)
		numcount[c-'0']++;
		
	//copy numcount[] data to temp[]
	for(i=0;(temp[i]=numcount[i]),i<NUMSET;i++)
		;
	//traverse through temp printing histogram bars from largest to smallest	
	tmp=MAX_BAR_WIDTH;
	printf("\n");
	while(tmp>=0){
		i=0;
		while(i<NUMSET){
			if(temp[i] >= tmp){
				k=0;
				printf(" %d - TOTAL: %2d|",i,temp[i]);
				while(k<=tmp){
					printf("*");
					k++;
				}
				printf("|\n");
				temp[i]=-1;
			}
			i++;
		}
		tmp--;
	}
	printf("\t       ---------------");
}
