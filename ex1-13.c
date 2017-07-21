#include <stdio.h>
#include <string.h>
#define MAX_WORDS 100

int main() {

	char words[100][MAX_WORDS];
	char spaces[101];
	int c, i, j, it1 = 0, it2 = 0;
	
	int len, max_len = 0;

	/*Extract words from imput in string array words*/
	while ((c = getchar()) != EOF) {
	
		if (it1 > MAX_WORDS)
			break;

		if (c == '\n'
		|| c == ','
		|| c == '.'
		|| c == ' '
		|| c == '\\'){
			
			it1 += 1;

			if (it2 > max_len)
				max_len = it2; /* save the maximum length*/
			it2 = 0;

		} else {
			words[it1][it2] = c;
			it2 += 1;
		}	
	}
	

	for ( i = 0 ; i < 100 ; i ++){
		spaces[i] = ' ';
	}
	spaces[100] = '\0';

	for (i = 0 ; i < max_len ; i++) {
		for (j = 0 ; j < it1 ; j++) {
		
			len = strlen(words[j]);

			if (len >= (max_len - i)) {
			
				if (len % 2 == 0) {
					printf("%s", &spaces[100 - len/2]);
					printf("|");
					printf("%s", &spaces[100 - len/2 + 1]);
				}else {
					printf("%s", &spaces[100 - len/2]);
					printf("|");
					printf("%s", &spaces[100 - len/2]);

				}
			}else {
				/* Print " " x (strlen)*/
				printf("%s", &spaces[ 100 - (strlen(words[j]))]);
			}
			printf(" ");
		}

		printf("\n");
	}

	for (i = 0 ; i < it1 ; i++) {
		printf("%s ",words[i]);
	}

}
