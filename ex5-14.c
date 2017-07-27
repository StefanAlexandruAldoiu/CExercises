#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXLINES 5000
#define MAXLEN 1000

char *lineptr[MAXLINES];

int igetline(char *, int);
char *alloc(int);
int ireadlines(char *lineptr[], int nlines);
void iwritelines(char *lineptr[], int nlines);

void iqsort(void *lineptr[], int left, int right, int (* comp)(void *, void *));
int numcmp(char*, char*);
int minus_numcmp(char *, char*);
int minus_strcmp(char *, char*);

int main(int argc, char *argv[]) {


	int nlines;
	int numeric = 0;
	int reverse = 0;
	
	int (*f) (char *, char*);

	if (argc > 2){
		f = &minus_numcmp;
	}else if (argc > 1 && strcmp(argv[1], "-n") == 0)
		f = &numcmp;
	else if (argc > 1 && strcmp(argv[1], "-r") == 0)
		f = &minus_strcmp;
	else
		f = (int (*)(char *, char*))strcmp;

	if ((nlines = ireadlines(lineptr, MAXLINES)) >=0) {
		iqsort((void **)lineptr, 0, nlines - 1,
		(int (*)(void *, void*))(f));
		iwritelines(lineptr, nlines);
		return 0;
	} else {
		printf("Input too big to sort\n");
		return 1;
	}
	
}


void iqsort(void *v[], int left, int right, int (*comp)(void *, void*)) {
	
	int i, last;
	
	void swap(void *v[], int, int);

	if (left >= right)
		return
	swap(v, left, (left + right) / 2);
	last = left;

	for (i = left + 1 ; i < right ; i++)
		if((*comp)(v[i], v[left]) < 0)
			swap(v, ++last, i);
	swap(v, left, last);
	iqsort(v, left, last - 1, comp);
	iqsort(v, last + 1, right, comp);
}

int numcmp(char *s1, char *s2){

	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 < v2)
		return -1;
	else if (v2 < v1)
		return 1;
	else
		return 0;
}
int minus_numcmp(char *s1, char *s2){

	double v1, v2;

	v1 = atof(s1);
	v2 = atof(s2);

	if (v1 < v2)
		return 1;
	else if (v2 < v1)
		return -1;
	else
		return 0;
}
int minus_strcmp(char *s1, char *s2){
	return -strcmp(s1, s2);
}

void swap(void *v[], int i, int j){

	void *temp;

	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}




int ireadlines(char *lineptr[], int maxlines){
	int len, nlines;
	char *p, line[MAXLEN];

	nlines = 0;
	
	while ((len = igetline(line, MAXLEN)) > 0){
		if (nlines >= maxlines || (p = alloc(len)) == NULL)
			return -1;
		else{
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}
	}
	return nlines;

}

void iwritelines(char *lineptr[], int nlines){

	int i;
	for (i = 0 ; i < nlines; i++)
		printf("%s\n", lineptr[i]);
}

char * alloc(int n){
	return malloc(sizeof(char) * n);
}

int igetline(char s[], int lim){
	int c, i;
	
	i = 0;
	
	while(--lim > 0 && (c = getchar()) != EOF && c != '\n')
		s[i++] = c;
	if (c == '\n')
		s[i++] = c;

	s[i] = '\0';
	
	return i;
}
