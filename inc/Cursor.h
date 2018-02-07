#ifndef CURSOR_H
#define CURSOR_H

#include "Logger.h"

class Cursor
{
  public:
    Cursor() : y(0), x(0) {Logger::get_instance().write("Cursor constructed");}
    ~Cursor() {Logger::get_instance().write("Cursor destructed");}

    void move_cursor(char direction);

    const int get_y() {return y;}
    const int get_x() {return x;}

  protected:

  private:
    int y;
    int x;
};

#endif
