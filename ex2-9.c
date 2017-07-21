#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int bitCount(signed int x) {
	
	int count = 0;
	
	while (x!= 0) {
		x &= (x - 1);
		count += 1;	
	}
	return count;
}

int main() {

	char s1[100];
	int c, i = 0; 
	signed int x;

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

	printf("\nThe result is:%d\n", bitCount(x));
}
