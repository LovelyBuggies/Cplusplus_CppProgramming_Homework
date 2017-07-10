#include <iostream>
#include "date.hpp"

void Date::setDate(int year,int month,int day)
{
  year_=year;
  month_=month;
  day_=day;
}

int Date::day() const
{
  return day_;
}

int Date::month() const
{
  return month_;
}

int Date::year() const
{
  return year_;
}

int Date::daysOfMonth(int year, int month) const
{
  year=Date::year_;
  month=Date::month_;
  int m[12]={31,0,31,30,31,30,31,31,30,31,30,31};
  if ((year%400==0)||((year%4==0)&&(year%100!=0)))
  m[1]=29;
  else 
  m[1]=28;
  return m[month-1];
}

void Date::increment()
{
  int dom;
  dom=Date::daysOfMonth(Date::year_,Date::month_);
  Date::day_++;
  if (Date::day_>dom)
   {
       Date::day_=1;
       Date::month_++;
     }
  if (Date::month_>12)
   {
       Date::month_=1;
       Date::year_++;
     }
}

void Date::decrement()
{
  Date::day_--;
  if (Date::day_<1)
   {
   Date::month_--;
       if(month_==0)
       {
        month_=12;
        year_--;
        day_=31;
       }
       else
   day_=daysOfMonth(year_,month_);  
     }
}