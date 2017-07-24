#include <stdio.h> 
#include <stdlib.h>  /* for  atof() */ 
#include <ctype.h>
#define MAXOP   100  /* max size of operand or operator */ 
#include "calc.h"

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
			if (nr_ops == 2) {
	       			push(pop() * pop());
				nr_ops = 1;
			}  
 
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
