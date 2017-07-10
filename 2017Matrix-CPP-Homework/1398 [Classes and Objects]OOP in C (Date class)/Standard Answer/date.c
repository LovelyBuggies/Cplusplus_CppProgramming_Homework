#include "date.h"
#include <stdlib.h>
#include <stdio.h>

Date* CreateDate(int year, int month, int day) {
  Date* date = (Date*)malloc(sizeof(Date));
  date->year = year;
  date->month = month;
  date->day = day;
  return date;
}

void DestroyDate(Date** p) {
  if (*p) {
    free(*p);
    *p = NULL;
  }
}

Date* CopyDate(const Date* date) {
  Date* new_date = (Date*)malloc(sizeof(Date));
  new_date->year = GetYear(date);
  new_date->month = GetMonth(date);
  new_date->day = GetDay(date);
  return new_date;
}

int GetYear(const Date* date) { return date->year; }
int GetMonth(const Date* date) { return date->month; }
int GetDay(const Date* date) { return date->day; }
void SetYear(Date* date, int year) { date->year = year; }
void SetMonth(Date* date, int month) { date->month = month; }
void SetDay(Date* date, int day) { date->day = day; }
void SetDate(Date* date, int year, int month, int day) {
  date->year = year;
  date->month = month;
  date->day = day;
}

char* GetDateString(const Date* date) {
  const int length_of_date_string = 10;
  char* date_string = (char*)malloc(sizeof(char)*(length_of_date_string + 1));
  snprintf(date_string,
          length_of_date_string + 1,
          "%04d-%02d-%02d",
          GetYear(date), GetMonth(date), GetDay(date));
  return date_string;
}

void DestroyDateString(char** p) {
  if (*p) {
    free(*p);
    *p = NULL;
  }
}

int GetDaysOfMonth(int year, int month) {
  if (month == 2) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28;
  } else {
    int daysOfMonth[13] = { -1, 31, -1, 31, 30,
                                31, 30, 31, 31,
                                30, 31, 30, 31 };
    return daysOfMonth[month];
  }
}

void IncreaseDate(Date* date) {
  ++date->day;
  if (date->day > GetDaysOfMonth(date->year, date->month)) {
    date->day = 1;
    ++date->month;
    if (date->month > 12) {
      date->month = 1;
      ++date->year;
    }
  }
}

void DecreaseDate(Date* date) {
  --date->day;
  if (date->day < 1) {
    --date->month;
    if (date->month < 1) {
      date->month = 12;
      --date->year;
    }
    date->day = GetDaysOfMonth(date->year, date->month);
  }
}