#include <stdio.h>
#include <string.h>
#include <stdlib.h>
/*Exercise 3-2*/

void escape(char *s, char *t) {
	
	int i, it = 0;
	
	for (i = 0 ; i < (int)strlen(s) ; i++) {

		switch (s[i]) {

		case '\n': 
			t[it] = '\\';
			it += 1;
			t[it] = 'n';
			it += 1;
			break;

		case '\t': 
			t[it] = '\\';
			it += 1;
			t[it] = 't';
			it += 1;
			break;

		default:
			t[it] = s[i];
			it += 1;
			break;
		
		}
	}

}

void deEscape(char *s, char *t) {
	
	int i, it = 1;
	char prev;

	t[0] = s[0];
	prev = s[0];
	for (i = 1 ; i < (int)strlen(s) ; i++) {

		switch (s[i]) {
			
		case 'n': 
			if (prev == '\\'){
				t[it - 1] = '\n';
				prev = '\n';
				break;	
			}else{
				t[it] = 'n';
				prev = 'n';
				it += 1; 
				break;
			
			}

			

		case 't':
			if (prev == '\\'){
				t[it - 1] = '\t';
				prev = '\t';
				break;
			}else{
				t[it] = 't';
				prev = 't';
				it += 1; 
				break;
			}

		default:
			t[it] = s[i];
			it += 1;
			prev = s[i]; 
			break;
			
		}
	}

}

int main() {

	int c;
       	char output[10000]; 
	int it = 0;
	char source[100], destination[100];

	printf("Enter your text to convert with function escape:\n");
	while((c = getchar()) != EOF) {

		source[it] = c;
		it += 1;
	}
	escape(source, destination);
	printf("\nThe converted text is:\n%s\n", destination);

	it = 0;
	memset (source, 0, sizeof(source));

	printf("Enter your text to convert with function deEscape:\n");
	while((c = getchar()) != EOF) {

		source[it] = c;
		it += 1;
	}
	deEscape(source, destination);
	printf("\nThe converted text is:\n%s\n", destination);
}
