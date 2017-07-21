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

	unsigned char a1,aux;
	char a2, a3;

	unsigned short b1;
	short b2, b3;


	unsigned int c1;
	int  c2, c3;

	unsigned long d1;
	long d2, d3;


	a1 = 0;
	a1 = ~a1;
	//a2 = -(1 << (sizeof(char) * 8 - 1));
	//a3 =  (1 << (sizeof(char) * 8 - 1)) - 1;
	a2 = 0;
	a2 = 1 << (sizeof(char) * 8 - 1);
	a3 = (1 << (sizeof(char) * 8 - 1)) - 1;

	b1 = 0;
	b1 = ~b1;
	b2 = (1 << (sizeof(short) * 8 - 1));
	b3 =  (1 << (sizeof(short) * 8 - 1)) - 1;

	c1 = 0;
	c1 = ~c1;
	c2 = (1U << (sizeof(int) * 8 - 1));
	c3 = (1U << (sizeof(int) * 8 - 1)) - 1;
	
	d1 = 0;
	d1 = ~d1;
	d2 = (1UL << (sizeof(long) * 8 - 1));
	d3 = (1UL << (sizeof(long) * 8 - 1)) - 1;

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
