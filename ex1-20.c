#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define INPUT_LEN 1000

int main(int argc, char **argv) {

	int tab_len = 4;
	char output[INPUT_LEN];
	int c, i = 0;
	char prev = 'a';
	
	if (argc > 1){
		tab_len = atoi(argv[1]);
	}

	printf("Enter your text( stop entering with EOF = CTRL + D):\n");
	while ((c = getchar()) != EOF) {
			
		if (i > INPUT_LEN)
			break;
		if (c == '\t') {
			if (i % tab_len == 0){
				if (prev != ' '){
					output[i] = ' ';
					i += 1;
					
					while( i % tab_len != 0){	
						output[i] = ' ';
						i += 1;
					}

					prev = output[i - 1];
				}
			} else {
				output[i] = ' ';
				i += 1;

				while( i % tab_len != 0){
					output[i] = ' ';
					i += 1;
				}
				prev = output[i - 1];
			}
		} else {
			output[i] = c;
			i += 1;
			prev = output[i - 1];
		}
		
	}
	
	printf("\nThe resulting text:\n%s\n",output);
}
