#include <stdio.h>

/*Exercise 1-3*/
int main(){
	
	float fahr, celsius, lower, upper, step;
	
	lower = 0;
	upper = 300;
	step = 20;
	printf("Farenheit	Celsius\n");

	fahr = lower;
	while(fahr <= upper){
		celsius = (5.0 / 9.0) * (fahr - 32.0);
		printf("%3.0f		%6.1f\n", fahr, celsius);
		fahr = fahr + step;
	}
}
