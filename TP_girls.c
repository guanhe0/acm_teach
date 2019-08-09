#include "stdio.h"
#include <memory.h>
#include <stdlib.h>
#include <math.h>
#define GIRLS_MAX 1000000000
#define SQ_MAX 31624
int mindiv(int v)
{
	int div = 1;
	if(v == 1 || v == 2) {
		return div;
	}else if(v >2){
		int i,end = v/2;
		for(i = 2;i<=end;i++){
			if(v % i == 0){
				div = v;
				break;
			}
		}
	}
	return div;
}
int div_count(int n)
{
	int count = 0;
	int i;
	
	if(n == 1 || n == 2){
	return 0;
	}
	double s = n*1.0,sq = 0.0;
	
	sq = sqrt(s);
	for(i = 2;i*1.0<sq;i++){
		if(n%i == 0){
			count++;
		}
	} 
	return count;
}
bool isPrime(int n)
{
		bool ret = true;
	if(n == 2){
		return true;
	}else{
		double r = sqrt(n*1.0);
		int i;

		for(i = 2; i <= r; i++){
			if(n % i == 0){
				ret = false;
				break;
			}
		}
	}
	return ret;	
}

int create_prime_table(int a[],int num)
{
	int i,j=0;
	for(i = 2; i<=num; i++){
		if(isPrime(i)){
			a[j] = i;
			j++;
		}
	}
	return j;
}
int main()
{
	int times = 0;
	int girls_num = 0;
	int girls_take = 0;
	char *current_state_array = (char *)malloc((GIRLS_MAX+1)*sizeof(char));


	int i,divcount = 0;
	memset(current_state_array,1,(GIRLS_MAX+1)*sizeof(char));


	int prime_table[SQ_MAX],table_len = 0;
	memset(prime_table,0,SQ_MAX*sizeof(int));
	table_len = create_prime_table(prime_table,SQ_MAX);
	
	for(i = 0; i<table_len; i++){
		if(i %20 == 0){printf("\n");}
		printf("%d ",prime_table[i]);
	}
	

	scanf("%d",&times);
	
	while(times--)
	{
		scanf("%d",&girls_num);
		girls_take = 0;
		for(i = 1; i<= girls_num; i++){
			if(current_state_array[i] != 0){
				girls_take++;
			}
		}
		printf("%d\n",girls_take);
	}
	free(current_state_array);

	current_state_array = NULL;

	return 0;
}
