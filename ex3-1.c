#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include <stdint.h>
#include <unistd.h>
#define BILLION  1000000000L;

uint64_t rdtsc() {
	uint32_t lo, hi;
	__asm__ __volatile__ (
		"xorl %%eax, %%eax\n"
		"cpuid\n"
		"rdtsc\n"
		: "=a" (lo), "=d" (hi)
		:
		: "%ebx", "%ecx");
	return (uint64_t)hi << 32 | lo;
}

int binnary1(int x, int *array, int n) {

	int min = 0, max = n;
	int mid;

	while(min < max){

		mid = (min + max) >> 1;
		if (x > array[mid])
			min = mid + 1;
		else
			max = mid;
	}
	return min;	
}

int binnary2(int x, int *array, int n){

	int min = 0, max = n - 1;
	int mid;
	
	while(min <= max){
		
		mid = (min + max) >> 1;
		if (x > array[mid])
			min = mid + 1;
		else if (x < array[mid])
			max = mid;
		else return mid;
	}

	return -1;	
}


int main(){


	int numbers[2000000];
	int c, i = 0; 
	int number;
	int ok;
	char s1[10000];
	unsigned long long b, e;
	unsigned long long sumO, sumNO;
	clock_t begin,  end;
	clock_t sO, sNO;
	number = 3;

	for ( i = 0 ; i < 2000000 ; i++)
		numbers[i] = i;
	
	printf("\n################## Variation of  dataset size: ###############################\n");
	printf("\n N = 1000 numbers\n");
	number = 300;
	b = rdtsc();
	ok = binnary2(number, numbers, 1000);
	e = rdtsc();
	printf("Unoptimized solution  took:%lld \\", e - b);
	
	b = rdtsc();
	ok = binnary1(number, numbers, 1000);
	e = rdtsc();
	printf(" Optimized solution took:%lld\n", e - b);
	
	printf("\n N = 10000 numbers\n");
	number = 3000;
	b = rdtsc();
	ok = binnary2(number, numbers, 10000);
	e = rdtsc();
	printf("Unoptimized solution  took:%lld \\", e - b);
	
	b = rdtsc();
	ok = binnary1(number, numbers, 10000);
	e = rdtsc();
	printf(" Optimized solution took:%lld\n", e - b);
	
	printf("\n N = 100000 numbers\n");
	number = 30000;
	b = rdtsc();
	ok = binnary2(number, numbers, 100000);
	e = rdtsc();
	printf("Unoptimized solution  took:%lld \\", e - b);
	
	b = rdtsc();
	ok = binnary1(number, numbers, 100000);
	e = rdtsc();
	printf(" Optimized solution took:%lld\n", e - b);
	
	printf("\n N = 1000000 numbers\n");
	number = 300000;
	b = rdtsc();
	ok = binnary2(number, numbers, 1000000);
	e = rdtsc();
	printf("Unoptimized solution  took:%lld \\", e - b);
	
	b = rdtsc();
	ok = binnary1(number, numbers, 1000000);
	e = rdtsc();
	printf(" Optimized solution took:%lld\n", e - b);
	
	printf("\n N = 2000000 numbers\n");
	number = 600000;
	b = rdtsc();
	ok = binnary2(number, numbers, 2000000);
	e = rdtsc();
	printf("Unoptimized solution  took:%lld \\", e - b);
	
	b = rdtsc();
	ok = binnary1(number, numbers, 2000000);
	e = rdtsc();
	printf(" Optimized solution took:%lld\n", e - b);

	printf("\n################## Variation of statements: Random searching nunbers ###############################\n");   
	printf("\n For 10 searching numbers in a 2 milion interval\n");
	sumO = 0;
	sumNO = 0;

	for (i = 0; i < 10 ; i++){
		srand(time(NULL));
		number = rand() % 2000000;
		b = rdtsc();
		ok = binnary2(number, numbers, 2000000);
		e = rdtsc();
		sumNO += (e - b);
	
		b = rdtsc();
		ok = binnary1(number, numbers, 2000000);
		e = rdtsc();
		sumO += (e - b); 
	}
	sumNO /= 10;
	sumO /= 10;
	printf("Unoptimized solution  took:%lld \\", sumNO);
	printf(" Optimized solution took:%lld\n", sumO);
	
	printf("\n For 100 searching numbers in a 2 milion interval\n");
	sumO = 0;
	sumNO = 0;
	for (i = 0; i < 100 ; i++){
		srand(time(NULL));
		number = rand() % 20000;
		b = rdtsc();
		ok = binnary2(number, numbers, 2000000);
		e = rdtsc();
		sumNO += (e - b);
	
		b = rdtsc();
		ok = binnary1(number, numbers, 2000000);
		e = rdtsc();
		sumO += (e - b); 
	}
	sumNO /= 100;
	sumO /= 100;
	printf("Unoptimized solution  took:%lld \\", sumNO);
	printf(" Optimized solution took:%lld\n", sumO);
		
	
		
	printf("\n For 1000 searching numbers in a 2 milion interval\n");
	sumO = 0;
	sumNO = 0;
	for (i = 0; i < 1000 ; i++){
		srand(time(NULL));
		number = rand() % 20000;
		b = rdtsc();
		ok = binnary2(number, numbers, 2000000);
		e = rdtsc();
		sumNO += (e - b);
	
		b = rdtsc();
		ok = binnary1(number, numbers, 2000000);
		e = rdtsc();
		sumO += (e - b); 
	}
	sumNO /= 1000;
	sumO /= 1000;
	printf("Unoptimized solution  took:%lld \\", sumNO);
	printf(" Optimized solution took:%lld\n", sumO);
		
	printf("\n For 10000 searching numbers in a 2 milion interval\n");
	sumO = 0;
	sumNO = 0;
	for (i = 0; i < 10000 ; i++){
		srand(time(NULL));
		number = rand() % 20000;
		b = rdtsc();
		ok = binnary2(number, numbers, 2000000);
		e = rdtsc();
		sumNO += (e - b);
	
		b = rdtsc();
		ok = binnary1(number, numbers, 2000000);
		e = rdtsc();
		sumO += (e - b); 
	}
	sumNO /= 10000;
	sumO /= 10000;
	printf("Unoptimized solution  took:%lld \\", sumNO);
	printf(" Optimized solution took:%lld\n", sumO);
}
