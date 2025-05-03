#include<stdio.h>
#include<stdlib.h>

int main(){
	int i,m,n,arr[20],stk[20];
	
	printf("Enter no. of elements: ");
	scanf("%d",&n);
	
	printf("Enter elements:\n");
	for(i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	
	m=n-1;
	for(i=0;i<n;i++){
		stk[m]=arr[i];
		m--;
	}
	printf("\n\nReversed E:\n");
	for(i=0;i<n;i++){
		printf("%d\t",stk[i]);
	}
	
	return 0;
	
}
