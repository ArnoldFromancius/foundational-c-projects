#include<stdio.h>

int main(){
	int n=7,i=1,j,k;
	
	while(i<=n){
		j=1;
		while(j<=i){
			printf(" %d ",j++);
		}
		k=j;
		while(k<=n){
			printf(" * ");
			k++;	
		}
		printf("\n");
		i++;
	}
}
