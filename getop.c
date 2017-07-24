#include <ctype.h>
#include <stdio.h> 
#include "calc.h"
#define BUFSIZE 100
/* getop:  get next character or numeric operand */ 
int getop(char s[]) 
{ 
	int i, c; 
	static int bufp = 0;
	static char buf[BUFSIZE];
	
	if (bufp > 0)
		c =  buf[--bufp];
	else
		c = getchar();
	while ((s[0] = c)  == ' ' || c == '\t'){
		if (bufp > 0)
			c =  buf[--bufp];
		else
			c = getchar();		
	}  
	s[1] = '\0'; 
	if (!isdigit(c) && c != '.') 
		return c;      /* not a number */ 
	i = 0; 
	//printf ("1.s is :%s\n",s);
	if (isdigit(c)){    /* collect integer part */
		if (bufp > 0)
			c =  buf[--bufp];
		else
			c = getchar(); 
		while (isdigit(s[++i] = c)) {
			if (bufp > 0)
				c =  buf[--bufp];
			else
				c = getchar();
		} 
		;
	} 
	//printf ("2.s is :%s\n",s);
	if (c == '.') {      /* collect fraction part */ 
		if (bufp > 0)
			c =  buf[--bufp];
		else
			c = getchar();				

		while (isdigit(s[++i] = c)){
			if (bufp > 0)
				c =  buf[--bufp];
			else
				c = getchar();		
		} 
		;
	}
	//printf ("3.s is :%s\n",s); 
	s[i] = '\0'; 
	if (c != EOF){
		if (bufp >= BUFSIZE) 
			printf("ungetch: too many characters\n"); 
		else 
			buf[bufp++] = c; 

	}
	//printf("\n buf is:%s,pos:%d, and string is :%s\n", buf, bufp, s);
	return NUMBER; 
} 
