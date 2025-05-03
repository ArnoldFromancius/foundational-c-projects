#include<stdio.h>
#define MAXSTRING 20

float atof(char s[]){
	int i;
	double sign;
	i=0;
	
	if(s[i]=='-'){
		sign=-1.0;
		i++;
	}
	else if(s[i]=='+'){
		sign=1.0;
		i++;
	}
	else
		sign=1.0;
	
	//working out the decimal part	
	double ret_val;	
	ret_val=0.0;
	while(s[i]!='\0'){
		if(s[i]>='0' && s[i]<='9')
			ret_val=ret_val*10.0 + s[i]-'0';
		else if(s[i]=='.'){
			i++;
			break;	
		}
		else
			return -1.0;
		i++;
	}
	if(s[i]=='\0')
		return ret_val*sign;
	
	//working out the fractional part	
	double pow=1.0;
	while(s[i]!='\0'){
		if(s[i]=='e' || s[i]=='E'){
			i++;
			break;
		}
		ret_val=ret_val*10.0 + s[i]-'0';
		pow*=10.0;
		i++;
	}
	if(s[i]=='\0')
		return (ret_val/pow)*sign;	
	
	//working out the exponetial part
	int exp_sign,exponent;
	if(s[i]=='-'){
		exp_sign=-1;
		i++;
	}
	else if(s[i]=='+'){
		exp_sign=1;
		i++;
	}
	else
		exp_sign=1;
	
	exponent=0;
	while(s[i]!='\0'){
		exponent=exponent*10 + (s[i]-'0');
		i++;	
	}
	exponent*=exp_sign;
	exponent--;			//just how the math works
	ret_val=((ret_val/pow)*sign);
	double temp=ret_val;
	if(exp_sign==-1){
		while(exponent<0){
			ret_val=ret_val/temp;
			exponent++;
		}
	}
	else if(exp_sign==1){
		while(exponent>0){
			ret_val=ret_val*temp;
			exponent--;
		}
	}
	return ret_val;
	
}

int main(){
	
	double val;
	char s[MAXSTRING];
	scanf("%s",s);
	val=atof(s);
	printf("\n%f",val);
	
}
