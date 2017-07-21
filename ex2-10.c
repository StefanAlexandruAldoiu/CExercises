#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void lower(char *s) {
	
	int i = 0;
	for (i = 0 ; i < (int)strlen(s); i++) {
		s[i] = (s[i] <= 90 && s[i] >= 65) ? s[i] + 32 : s[i];
	}
}

int main(){

	char s1[100];
	int c, i = 0; 	

	printf("\nEnter The string to lower-ize:\n");
	while ((c = getchar()) != EOF) {

		if (c == '\n')
			break;
		s1[i] = c;
		i += 1;
	}
	s1[i] = '\0';
	
	lower(s1);

	printf("\nThe result is:%s\n", s1);
}
