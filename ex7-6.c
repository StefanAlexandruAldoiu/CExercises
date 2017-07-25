#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(int argc, char *argv[]) {

	FILE *fp1, *fp2;
	
	char *line1, *line2;
	size_t len1 = 0, len2 = 0;
	ssize_t read1, read2;
	
	if (argc < 3){
		printf("To few args: ./exec file1 file2\n");	
		return 0;
	}

	fp1 = fopen(argv[1], "r");
	fp2 = fopen(argv[2], "r");

	if (fp1 == NULL || fp2 == NULL)
		exit(EXIT_FAILURE);
	while((read1 = getline(&line1, &len1, fp1 )) != -1 && (read2 = getline(&line2, &len2, fp2 )) != -1) {

		
		if (strcmp (line1, line2) != 0) {
			
			fclose(fp1);
			fclose(fp2);
			printf ("FP1:%s\n", line1);
			printf ("FP2:%s\n", line2);
			return 0;
		}
	}
	
	if (feof(fp1) == 0) {
		read1 = getline(&line1, &len1, fp1 );
		printf ("FP1:%s\n", line1);
		printf ("FP2: is closed.\n");
	}
	 
        if (feof(fp2) == 0) {
                read1 = getline(&line2, &len2, fp2 );
		printf ("FP1: is closed.\n");
                printf ("FP2:%s\n", line2);
        }
	
	fclose(fp1);
	fclose(fp2);
}
