#include <stdio.h> 
#include <stdlib.h>  /* for  atof() */ 
#include <ctype.h>
#define MAXOP   100  /* max size of operand or operator */ 
#define NUMBER  '0'  /* signal that a number was found */ 
#define MAXVAL  100  /* maximum depth of val stack */ 
#define BUFSIZE 100
int sp = 0;          /* next free stack position */ 
double val[MAXVAL];  /* value stack */ 
char buf[BUFSIZE];    /* buffer for ungetch */ 
int bufp = 0;         /* next free position in buf */ 
 
/* push:  push f onto value stack */ 
void push(double f) 
{ 
	if (sp < MAXVAL) 
	   val[sp++] = f; 
	else 
	   printf("error: stack full, can't push %g\n", f); 
}
/* pop:  pop and return top value from stack */ 
double pop() 
{ 
	if (sp > 0) 
	   return val[--sp]; 
	else { 
	   printf("error: stack empty\n"); 
	   return 0.0;
	} 
}   

int getch(void)  /* get a (possibly pushed-back) character */ 
{ 
	return (bufp > 0) ? buf[--bufp] : getchar(); 
} 
void ungetch(int c)   /* push character back on input */ 
{ 
	if (bufp >= BUFSIZE) 
   		printf("ungetch: too many characters\n"); 
	else 
   		buf[bufp++] = c; 
} 

/* getop:  get next character or numeric operand */ 
int getop(char s[]) { 
	int i, c; 
	while ((s[0] = c = getch()) == ' ' || c == '\t') 
   	; 
	s[1] = '\0'; 
	if (!isdigit(c) && c != '.') 
   		return c;      /* not a number */ 
	i = 0; 
	if (isdigit(c))    /* collect integer part */ 
   		while (isdigit(s[++i] = c = getch())) 
      		; 
	if (c == '.')      /* collect fraction part*/
   		while (isdigit(s[++i] = c = getch())) 
      	; 
	s[i] = '\0'; 
	if (c != EOF) 
   		ungetch(c); 
	return NUMBER; 	
	}

 
int main() {
	int type; 
	double op2; 
	char s[MAXOP];
       	int nr_ops = 0;	
	while ((type = getop(s)) != EOF) { 
		switch (type) { 
		case NUMBER: 
			push(atof(s));
		       	nr_ops += 1;	
			break; 
	   	case '+': 
			if (nr_ops == 2) {
	      	 		push(pop() + pop());
				nr_ops = 1;
			} 
			break; 
	   	case '*': 
	       		push(pop() * pop()); 
	       		break; 
	  	case '-':
			if (nr_ops == 2) { 
	      			op2 = pop(); 
	       			push(pop() - op2); 
				nr_ops = 1;
	       		} else
				push(0 - pop());

			break;
	   	case '/': 
	       		op2 = pop(); 
	       		if (op2 != 0.0){ 
		   		push(pop() / op2);
 				nr_ops = 1;
			} else 
		   		printf("error: zero divisor\n"); 
	       		break;
		case '%':
			op2 = pop();
			push((int)pop() % (int)op2);
			break;	
	   	case '\n': 
	       		printf("\t%.8g\n", pop());
		       	nr_ops = 0;	
	       		break; 
	   	default: 
	       		printf("error: unknown command %s\n", s); 
	       		break; 
	   	} 
	} 
	return 0; 
}




