#include <stdio.h>

char* strncpy(char *s, char *t, int n){
	int i = 0;
	char *rez = t;
	
	while(i < n && *s) {
		*t = *s;
		t++;
		s++;
		i++;
	}

	if (i < n)
		printf("Source string is shorter than specified length\n");
	return rez;
}

char* strncat(char *s, char *t, int n){
	int i = 0;
	char *rez = t;

	while(i < n && *s) {
		*t = *s;
		t++;
		s++;
		i++;
	}

	if (i < n)
		printf("Source string is shorter than specified length\n");
	return rez;
}
int strncmp(char *s, char *t, int n){
	int i = 0;
	
	int ok = 0;
	while(i < n && *s && *t) {
		if (*t != *s) {
			ok = 1;
			break;
		}
		t++;
		s++;
	}

	return ok;
}



int main(){
	char s[100] = " ana ?";
	char t[100] = "are mere";
	char copy_t[100];

	printf("Verifying the strncat:%s\n", strncat(s, t, 6));
 	printf("Verifying the strncpy:%s\n", strncpy(s, t, 6));
	
	strncpy(t, copy_t, 14);
	printf("Verifying the strncpy:%d\n", strncmp(t, copy_t, 14)); 
}
