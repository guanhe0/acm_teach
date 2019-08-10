#include "stdio.h"
#include <memory.h>
#include <stdlib.h>
#include <math.h>
#define GIRLS_MAX 1000000000
#define SQ_MAX 31624
int isPrime(int n)
{
	int ret = 0;
	if(n == 2 || n == 1){
		return 0;
	}else{
		double r = sqrt(n*1.0);
		int i;

		for(i = 2; i <= r; i++){
			if(n % i == 0){
				ret = i;
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
int findIndex(int prime_table[],int num,int key)
{
	int i;
	for(i = 0; i < num; i++){
		if(key == prime_table[i]){
			break;
		}
	}
	return i;
}
int main()
{
	int times = 0;
	int girls_num = 0;
	int girls_take = 0;
	char *current_state_array = (char *)malloc((GIRLS_MAX+1)*sizeof(char));


	int i;
	memset(current_state_array,1,(GIRLS_MAX+1)*sizeof(char));

	int prime_table[SQ_MAX],table_len = 0;
	memset(prime_table,0,SQ_MAX*sizeof(int));
	table_len = create_prime_table(prime_table,SQ_MAX);
		
	printf("prime max == %d\n",prime_table[table_len-1]);
	return 0;
	int exp_count[SQ_MAX];
	memset(exp_count,0,SQ_MAX*sizeof(int));
	
	int mindiv = 0;
	int index = 0;
	int j;
	int value;
	int is_prime = 0;
	for(i = 2; i<= GIRLS_MAX; i++){
		value = i;
		mindiv = isPrime(value);
		if(mindiv == 0){
			current_state_array[i] = 0;
		}else{
			index = findIndex(prime_table,SQ_MAX,mindiv);
			
			exp_count[index]++;
			value = value/mindiv;
			
			is_prime = isPrime(value);
			while(is_prime != 0)
			{
				
			}
			index = findIndex(prime_table,SQ_MAX,value);
			exp_count[index]++;
			value = 1;
		}	
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
