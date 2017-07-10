#include "date.hpp"

void Date::setDate(int year, int month, int day) {
  year_ = year;
  month_ = month;
  day_ = day;
}

int Date::year() const { return year_; }
int Date::month() const { return month_; }
int Date::day() const { return day_; }

int Date::daysOfMonth(int year, int month) const {
  if (month == 2) {
    return ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) ? 29 : 28;
  } else {
    int daysOfMonth[13] = { -1, 31, -1, 31, 30,
                                31, 30, 31, 31,
                                30, 31, 30, 31 };
    return daysOfMonth[month];
  }
}

void Date::increment() {
  ++day_;
  if (day_ > daysOfMonth(year_, month_)) {
    day_ = 1;
    ++month_;
    if (month_ > 12) {
      month_ = 1;
      ++year_;
    }
  }
}

void Date::decrement() {
  --day_;
  if (day_ < 1) {
    --month_;
    if (month_ < 1) {
      month_ = 12;
      --year_;
    }
    day_ = daysOfMonth(year_, month_);
  }
}