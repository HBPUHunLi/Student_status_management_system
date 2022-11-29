#include"studentM.h"

char* Sage(int age)
{
	char Birthday[12];
	time_t now = time(NULL);
	tm* tm_t = localtime(&now);
	char year[5];
	char month[3];
	char day[3];
	_itoa(tm_t->tm_year + 1900 - age,year,10);
	_itoa(tm_t->tm_mon + 1, month, 10);
	_itoa(tm_t->tm_mday, day, 10);
	strcpy(Birthday, year);
	strcat(Birthday, "-");
	strcat(Birthday, month);
	strcat(Birthday, "-");
	strcat(Birthday, day);
	return Birthday;
}