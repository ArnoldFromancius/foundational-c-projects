//rudimentary calculator
#include<stdio.h>
#include<string.h>


double atof(char s[]){
	int i=0,sign;
	
	if(s[i]=='-'){
		sign=-1;
		i++;	
	}
	else
		sign=1;
	
	double ret_val=0;
	while(s[i]!='\0'){
		if(s[i]>='0' && s[i]<='9')
			ret_val=ret_val*10 + s[i]-'0';
		else if(s[i]=='.')
			break;
		else
			return -1;
		i++;
	}
	
	if(s[i]=='\0')
		return (ret_val*1.0)*sign;
		
	i++;
	double pow=1.0;
	while(s[i]!='\0'){
		
		if(s[i]>='0' && s[i]<='9'){
			ret_val=ret_val*10 + s[i]-'0';
			pow*=10.0;	
		}	
		else
			return -1;
		i++;
	}
	
	return (ret_val/pow)*sign;
}

int getline(char line[], int lim){
	int i,c;
	c=getchar();
	if(c==EOF)
		return -1;
	i=0;
	line[i++]=c;
	while((c=getchar())!='\n')
		line[i++]=c;
	line[i]='\0';
	return i;
}

int main(){
	double sum=0, temp;
	char s[20];
	
	while(getline(s,20) > 0){
		temp=atof(s);
		if(temp!=-1)
			sum+=temp;
	}
	printf("\n%f",sum);
	return 0;
}
