#include <stdio.h>

/*Exercise 1-7*/
int main() {

	int c;
       	char output[10000]; 
	int it = 0;

	printf("Enter your text to convert:\n");
	while((c = getchar()) != EOF) {

		if ( c == 8) {
			output[it] = '\\';
			it += 1;
			output[it] = 'b';
		}
		else if (c == '\t') {
			output[it] = '\\';
			it += 1;
			output[it] = 't';
		}else if (c == '\\') {
			output[it] = '\\';
			it += 1;
			output[it] = '\\';	
		}
		else
			output[it] = c;
		it += 1;
	}
	printf("\nThe converted text is:\n%s\n", output);
}
