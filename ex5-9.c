#include <stdio.h>
#include <stdlib.h>
/* day_of_year:  set day of year from month & day */ 
int day_of_year(int year, int month, int day, char (*daytab)[13]) 
{ 
	int i, leap; 
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0; 
	
	if (month > 12 || month < 0 ||
		day < 0 || day > 31 ||
		year < 0 || *(*(daytab + leap) + month) < day ) {
		printf("Invalid value for selected day/ month\n");
		return -1;
		}

	char *year_type = *(daytab + leap);
    i = 0;
    year_type ++;

    while (i < month) {        
        day += *year_type;
        year_type ++;
        i++;       
    } 
    return day;
} 

/* month_day:  set month, day from day of year */ 
void month_day(int year, int yearday, int *pmonth, int *pday, char (*daytab)[13]) 
{
	int i, leap; 
	leap = year%4 == 0 && year%100 != 0 || year%400 == 0;
	
	int limit = (leap == 0) ? 365 : 366;
	
	if (!(yearday <= limit)) {
		printf("Day is invalid, bigger than can exist!\n");		
		return;	
	}	
	if (!(year >= 0)) {
		printf("Year is invalid!\n");		
		return;	
	}
	
	char *year_type = *(daytab + leap);
	for (i = 1; yearday > *(year_type + i); i++) 
		yearday -= *(year_type + i);	
	*pmonth = i; 
	*pday = yearday; 
} 




int main(){

	int pmonth, pday;
	char (*daytab)[13] = NULL;      
	daytab = (char [][13]){ {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},{0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}};
	printf("Printing dayOfYear for year 2000, month 3 and day 10:%d\n", day_of_year(2000, 3, 10, daytab));
	printf("Printing dayOfYear for year 2000, month 3 and day 40:%d\n", day_of_year(2000, 3, 40, daytab));
	
	month_day(2000, 100, &pmonth, &pday, daytab);
	printf("Calculated mounthDay for year 2000, and day 100: month=%d and day=%d\n", pmonth, pday);

	month_day(2000, 400, &pmonth, &pday, daytab);
	printf("Calculated mounthDay for year 1000, and day 400: month=%d and day=%d\n", pmonth, pday);	


	month_day(2000, 100, &pmonth, &pday, daytab);
	printf("Calculated mounthDay for year 1000, and day 100: month=%d and day=%d\n", pmonth, pday);
}

