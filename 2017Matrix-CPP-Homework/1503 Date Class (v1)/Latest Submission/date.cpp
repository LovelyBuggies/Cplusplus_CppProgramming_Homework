 #include "date.hpp"
Date::Date()
{
  year=2017;
  month=1;
  day=28;
}

Date::Date (int y, int m, int d)
{
  year=y;
  month=m;
  day=d;
  Date::normalize();
}

bool Date::equals(const Date&date) const
{
  bool r=false;
  if (date.getYear()==year)
     if (date.getMonth()==month)
         if (date.getDay()==day)
              r=true;
  return r;
}

bool Date::smallerThan(const Date&date) const
{
  bool r=true;
  if (date.getYear()<year)
     r=false;
  else if ((date.getYear()==year)&&(date.getMonth()<month))
     r=false;
  else if ((date.getYear()==year)&&(date.getMonth()==month)&&(date.getDay()<day))
     r=false;
  else r=true;
  return r;
}

void Date::normalize()
{
  int i;
  while (month > 12 )
   {
    month-=12;  
    year++;
   }
  while (day > daysOfMonth(year, month))
   {
    day=day-daysOfMonth(year,month);
    month++;  
    }
  while (month > 12 )
   {
    month-=12;  
    year++;
   }
       
  
}