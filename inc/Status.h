#ifndef STATUS_H
#define STATUS_H

#include "Constants.h"

class Status
{
  public:
    Status();
    ~Status() {}

    void add_money(int amount) {money += amount;}
    void sub_money(int amount) {money -= amount;}
    int get_money() {return money;}

    void update_iteration() {++iteration;}
    int get_iteration() {return iteration;}

    void update_date();
    char* get_date();

  protected:

  private:
    tm date;
    int iteration;
    int money;
};

#endif
