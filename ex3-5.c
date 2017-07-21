#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
/*Exercise 1-7*/

void itob(int n, char *s, int b){
	
	char modulus[10];
	char aux;
	int i;

	while(n != 0) {
		sprintf(modulus, "%d" , n % b);
		strcat(s,modulus);
		memset(modulus, 0 ,sizeof(modulus));
		n /= b;
	}

	for (i = 0 ; i < (int)strlen(s) / 2 ; i++) {	
		aux = s[i];
		s[i] = s[strlen(s) - i - 1];
		s[strlen(s) - i - 1] = aux;	
	}
}

int main() {

	int c;
       	char output[10000]; 
	int it = 0;
	int number;
	int base;

	printf("Enter your number to convert:\n");
	while((c = getchar()) != '\n') {
		output[it] = c;
		it += 1;
	}
	number = atoi(output);
	memset(output, 0 , sizeof(output));
	it = 0;

	printf("Enter your converting base:\n");
	while((c = getchar()) != '\n') {
		output[it] = c;
		it += 1;
	}

	base = atoi(output);
	memset(output, 0 , sizeof(output));
	
	itob(number, output, base);
	printf("\nThe converted number is:\n%s\n", output);
}
