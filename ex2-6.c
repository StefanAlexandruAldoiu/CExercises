#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned pow2(unsigned exponent) {
	int i, r = 1;
	for (i = 0 ; i < exponent; i++) {
		r = r * 2;
	}
	return r;
}

unsigned setBits(unsigned x, int p, int n, unsigned y) {
	int i, j;
	char ok = 0;
	
	unsigned OrNumber;
	unsigned AndNumber;
	
	OrNumber = (y & ~(~0 << n)) << (p + 1 - n) ;
	AndNumber = (~0 << (p + 1)) | (pow2(p + 2 - n) -1);
 
	return (x & AndNumber) | OrNumber;
}

int main(){


	char s1[100];
	int c, i = 0;
	int p, n; 
	unsigned x, y;
	

	printf("\nEnter The x:\n");
	while ((c = getchar()) != EOF) {

		if (c == '\n')
			break;
		s1[i] = c;
		i += 1;
	}
	s1[i] = '\0';
	x = atoi(s1);
	memset(s1, 0, sizeof(s1));
	i = 0;

	printf("\nEnter The y:\n");
	while ((c = getchar()) != EOF) {

		if (c == '\n')
			break;
		s1[i] = c;
		i += 1;
	}
	s1[i] = '\0';
	y = atoi(s1);
	memset(s1, 0, sizeof(s1));
	i = 0;

	printf("\nEnter The p:\n");
	while ((c = getchar()) != EOF) {

		if (c == '\n')
			break;
		s1[i] = c;
		i += 1;
	}
	s1[i] = '\0';
	p = atoi(s1);
	memset(s1, 0, sizeof(s1));
	i = 0;
	
	printf("\nEnter The n:\n");
	while ((c = getchar()) != EOF) {

		if (c == '\n')
			break;
		s1[i] = c;
		i += 1;
	}
	s1[i] = '\0';
	n = atoi(s1);
	memset(s1, 0, sizeof(s1));
	i = 0;

	printf("\nThe result is:%d\n", setBits(x, p, n, y));
}
