#include<stdio.h>
int getmax(int array[], int n){
	int max=array[0];
	int i=0;
	while(i<n){
		if(array[i]>max){
			max=array[i];
		}
		i++;
	}
	return max;
}

//coont sort
void countsort(int array[], int n, int dig){
	int output[n];
	int i=0,count[10]={};
	
	//store count of occurences in count
	while(i<n){
		count[(array[i]/dig) % 10]++;
		i++;
	}
	 
	//change count[i] so count[i] now contains actual postion of digit in out
	i=1;
	while(i<10){
		count[i]+=count[i-1];
		i++;
	}
	
	
	
	//build the output array
	i=n-1;
	while(i>=0){
		output[count[(array[i] / dig)%10]-1]=array[i];
		count[(array[i]/dig)%10]--;
		i--;
	}
	
	//copy out to array
	i=0;
	while(i<n){
		array[i]=output[i];
		i++;
	}
	printf(" \n");
	
}

//radix sort
void radix(int array[], int n){
	int m=getmax(array,n),dig;
	dig=1;
	while(m/dig>0){
		countsort(array,n,dig);
		dig*=10;
	}
}

//print array
void disp(int array[],int n){
	int i;
	for(i=0;i<n;i++){
		printf(" %d ",array[i]);
	}
}

int main(){
	int arr[]={140,65,85,110,612,54,12,86};
	int n=8;
	radix(arr,n);
	disp(arr,n);
	return 0;
}
