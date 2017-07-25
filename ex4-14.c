#include <stdio.h>
#define swap(t , x , y) {\
	t aux;\
	aux = x;\
	x = y;\
	y = aux;}

int main(){

	int x  = 1;
	int y  = 3;
	printf("Before interchange x=%d and y=%d\n", x ,y);
	swap(int, x, y);
	printf(" After interchange x=%d and y=%d\n", x ,y);
}
