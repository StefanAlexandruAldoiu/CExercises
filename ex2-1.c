#include <stdio.h>
#include <limits.h>

int main(){


	printf("#######################Limits from header################\n");
	
	printf("UpperLimit UnsignedChar : %d\n", UCHAR_MAX);
	printf("LowerLimit         Char : %d\n", CHAR_MIN);
	printf("UpperLimit         Char : %d\n", CHAR_MAX);

	printf("UpperLimit UnsignedShort : %u\n", USHRT_MAX);
	printf("LowerLimit         Short : %d\n", SHRT_MIN);
	printf("UpperLimit         Short : %d\n", SHRT_MAX);


	printf("UpperLimit UnsignedInt : %u\n", UINT_MAX);
	printf("LowerLimit         Int : %d\n", INT_MIN);
	printf("UpperLimit         Int : %d\n", INT_MAX);

	printf("UpperLimit UnsignedLong : %lu\n", ULONG_MAX);
	printf("LowerLimit         Long : %ld\n", LONG_MIN);
	printf("UpperLimit         Long : %ld\n", LONG_MAX);

	printf("#######################Limits from computation ################\n");

	unsigned char a1;
	char a2, a3;

	unsigned int b1, c1;

	int b2, b3, c2, c3;

	unsigned long d1;
	long d2, d3;


	a1 = 0;
	a1 = ~a1;

	a2 = 0;
	a2 = ~0U >> 1;

	printf("UpperLimit UnsignedChar : %d\n", a1);
	printf("LowerLimit         Char : %d\n", a2);
	printf("UpperLimit         Char : %d\n", a3);
	
	printf("UpperLimit UnsignedShort : %u\n", b1);
       	printf("LowerLimit         Short : %d\n", b2);
	printf("UpperLimit         Short : %d\n", b3);
	
	printf("UpperLimit UnsignedInt : %u\n", c1);
	printf("LowerLimit         Int : %d\n", c2);
	printf("UpperLimit         Int : %d\n", c3);
										  
	printf("UpperLimit UnsignedLong : %lu\n", d1);
	printf("LowerLimit         Long : %ld\n", d2);		
	printf("UpperLimit         Long : %ld\n", d3);
}
