#include "Status.h"

Status::Status() : iteration(0), money(STARTING_MONEY) 
{
  date.tm_mon = 0;
  date.tm_year = 0;
}

void Status::update_date()
{
  ++(date.tm_mon);
  if (date.tm_mon == 12)
  {
    date.tm_mon = 0;
    ++(date.tm_year);
  }
}

char* Status::get_date()
{
  char* date_string = new char[100];
  strftime(date_string, 100, "%b %Y\0", &date);
  return date_string;
}
