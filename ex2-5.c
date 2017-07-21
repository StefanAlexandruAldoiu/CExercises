#include <stdio.h>
#include <string.h>

int any(char *s1, char *s2){
	int i, j;
	char ok = 0;
	for (i = 0 ; i < (int)strlen(s1) ; i++){
		for (j = 0 ; j < (int)strlen(s2); j++){
			if (s1[i] == s2[j]){
				ok = 1;
				break;
			}
		}
		if (ok == 1)
			return i;
	}
	return -1;
}

int main(){


	char s1[100], s2[100];
	int c, i = 0;
	

	printf("\nEnter The first string and press enter:\n");
	while ((c = getchar()) != EOF) {

		if (c == '\n')
			break;
		s1[i] = c;
		i += 1;
	}
	s1[i] = '\0';

	i = 0;
	printf("\nEnter The second string and press enter:\n");
	while ((c = getchar()) != EOF) {

		if (c == '\n')
			break;
		s2[i] = c;
		i += 1;
	}
	s2[i]= '\0';

	printf("\nThe result is:%d\n",any(s1, s2));
}
