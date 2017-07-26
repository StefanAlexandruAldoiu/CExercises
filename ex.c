#include <stdio.h>
#include <stdlib.h>

void manipulate(int **p){

	*p = malloc (10 * sizeof(int));
	*p[0] = 10;
	printf("value:%d\n",*p[0]);
	
}

void manipulate_i(int *p){

	p = malloc (10 * sizeof(int));
	p[0] = 10;
	printf("value:%d\n",p[0]);
	
}
void manipulate_x(int *x){
	*x = 20;
	printf("xs:%p\n",x);
	printf("xs:%p\n",&x);
}
void manipulate_one_column(int **a){

	a[1]= malloc(10 * sizeof(int));
	a[1][0] = 10;
}
int main(){

	int *p = NULL;
	int x = 10;	
	int **a;


	a = malloc(2 * sizeof(int *));
	a[0] = malloc(10 * sizeof(int));

	p =  NULL;
	printf("p:%p\n", p);
	printf("p:%p\n", &p);
	
	manipulate(&p);

	printf("p:%p\n", p);
	printf("p:%p\n", &p);
	
	manipulate_x(&x);

	manipulate_x(p);
	printf("x:%d\n",x);
	printf("value:%d\n",p[0]);

	manipulate_one_column(a);
	printf("Impresion: %d",a[1][0]);
}
