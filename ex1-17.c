#include <stdio.h>
#include <string.h>
#define MAX_LEN_LINE 1000
#define MAX_NR_LINE 100

int main() {

	char lines[MAX_NR_LINE][MAX_LEN_LINE];
	char current_line[MAX_LEN_LINE];
	int c, i, it1 = 0, it2 = 0;
	
	

	printf("Enter your text( stop entering with EOF = CTRL + D):\n");
	while ((c = getchar()) != EOF) {
	
		if (it1 > MAX_NR_LINE)
			break;

		if (c == '\n'){
			if (strlen(current_line) > 80){
				strcpy(lines[it1], current_line);
				it1 += 1;
			}
			//printf("\nHad some of mine:%s [%d]\n",current_line,(int)strlen(current_line));
			memset(current_line, 0, sizeof(current_line));
			it2 = 0;
		} else {
			current_line[it2] = c;
			it2 += 1;
		}
	}
	
	printf("\nLines that are longers than 80 chars:\n");
	for ( i = 0 ; i < it1 ; i ++){
		printf("%s\n", lines[i]);	
	}

}
