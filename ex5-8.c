#include <stdio.h>


static char daytab[2][13] = { 
	{0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, 
	{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} 
}; 
/* day_of_year:  set day of year from month & day */ 
int day_of_year(int year, int month, int day) 
{ 
	int i, leap; 
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
	
	if (month > 12 || month < 0 ||
		day < 0 || day > 31 ||
		year < 0 || daytab[leap][month] < day ){

		printf("Invalid value for selected day/ month\n");
		return -1;
		}
		
	for (i = 1; i < month; i++) 
		day += daytab[leap][i]; 
	return day; 
} 

/* month_day:  set month, day from day of year */ 
void month_day(int year, int yearday, int *pmonth, int *pday) 
{ 
	int i, leap; 
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
	
	int limit = (leap == 0) ? 365 : 366;
	
	if (!(yearday <= limit)){
		printf("Day is invalid, bigger than can exist!\n");		
		return;	
	}	
	
	for (i = 1; yearday > daytab[leap][i]; i++) 
		yearday -= daytab[leap][i];	
	*pmonth = i; 
	*pday = yearday; 
} 


int main(){

	int pmonth, pday;	
	printf("Printing dayOfYear for year 2000, month 3 and day 10:%d\n", day_of_year(2000, 3, 10));
	printf("Printing dayOfYear for year 2000, month 3 and day 40:%d\n", day_of_year(2000, 3, 40));
	
	month_day(2000, 100, &pmonth, &pday);
	printf("Calculated mounthDay for year 2000, and day 100: month=%d and day=%d\n", pmonth, pday);

	month_day(2000, 400, &pmonth, &pday);
	printf("Calculated mounthDay for year 1000, and day 400: month=%d and day=%d\n", pmonth, pday);	
}
