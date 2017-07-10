#include <stdio.h>
#include "date.h"
#include <stdlib.h>

Date* CreateDate(int year, int month, int day)
{
  Date* instance = (Date*)malloc (sizeof(Date));
  instance->year = year;
  instance->month = month;
  instance->day = day;
  return instance;
}
//constructor
void DestroyDate(Date** pppp)
{
  free(*pppp);
  *pppp=NULL;
}  
//destructor
Date* CopyDate(const Date* date)
{
  Date *p = (Date*) malloc (sizeof(Date));
  p->year = date->year;
  p->month = date->month;
  p->day = date->day;
  return p;
}
//copy Date



int GetYear(const Date* date)
{
  return date->year;
}
int GetMonth(const Date* date)
{
  return date->month;
}
int GetDay(const Date* date)
{
  return date->day;
}
//Get functions



void SetYear(Date* date, int year)
{
  date->year = year;
}
void SetMonth(Date* date, int month)
{
  date->month = month;
}
void SetDay(Date* date, int day)
{
  date->day = day;
}
void SetDate(Date* date, int year, int month, int day)
{
  date->year = year;
  date->month = month;
  date->day = day;
}
//Set functions





char* GetDateString(const Date* date)
{
  char *pppp = (char*)malloc(20*sizeof(char));
  sprintf(pppp,"%04d-%02d-%02d", date->year, date->month, date->day);
  return pppp;
}
void DestroyDateString(char** pppp)
{
  free (*pppp);
  *pppp=NULL;
}
//DateString functions






void IncreaseDate(Date* date)
{
  int daysOfMonth(int, int);
  int dom;
  dom=daysOfMonth(date->year,date->month);
  (date->day)++;
  if ((date->day)>dom)
   {
       (date->day)=1;
       (date->month)++;
     }
  if ((date->month)>12)
   {
       (date->month)=1;
       (date->year)++;
     }
  
}

void DecreaseDate(Date* date)
{
  int daysOfMonth(int, int);
  (date->day)--;
  if ((date->day)<1)
   {
   (date->month)--;
       if((date->month)==0)
       {
        (date->month)=12;
        (date->year)--;
        (date->day)=31;
       }
       else
   (date->day)=daysOfMonth((date->year),(date->month));  
   }
}


int daysOfMonth(int year, int month)
{
	switch (month)
{
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		return 31;
	case 4: case 6: case 9: case 11:
		return 30; 
  case 2:
		if ((year % 4 == 0 && year % 100 != 0) ||year % 400 == 0) 				return 29;
  default: break;
}
  return 28;
}