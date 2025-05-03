//arithmatic progression
#include<stdio.h>

populate_list(int list[],int first_item,int total_items,int common_difference){
	
	int i=0;
	list[i]=first_item;
	i++;
	while(i<total_items){
		list[i]=list[i-1] + common_difference;
		i++;	
	}		
}

void display_list(int *list, int total_items){
	int i=0;
	while(i<total_items)
		printf("%d\n",list[i++]);
}

int nth_term_value(int list[],int cd,int nth_term){
	return 	list[0]+(nth_term-1)*cd;
}

int sum_of_terms(int list[],int cd, int last_term){
	int n,sum,term_step;
	n=sum=0;
	term_step=*list;
	while(n<last_term){
		sum+=term_step;
		term_step+=cd;
		printf(" %d- %d\n",term_step,sum);
		n++;
		
	}
	return sum; 
	
}

int main(){
	
	int list[100];
	
	populate_list(list,2,30,2);
	printf("%d",sum_of_terms(list,2,10));
	//printf("%d",nth_term_value(list,2,5));
	//display_list(list,30);
	
		
}
