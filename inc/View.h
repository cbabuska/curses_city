#ifndef VIEW_H
#define VIEW_H

#include <vector>
#include <map>

#include <curses.h>

#include "Grid.h"
#include "Cursor.h"

class Cell;
class Status_grid;

class View
{
  public:
    View();
    ~View();

    void draw_background(Status& status, std::string status_message = "");
    void draw_grid_window(Cursor& cursor, Grid& grid);
    void draw_status_window(Cursor& cursor, Status& status, std::map<std::string, int> land_values, std::map<std::string, Status_grid*> status_grids);

  protected:

  private:
    WINDOW* background;
    WINDOW* grid_window;
    WINDOW* status_window;

};

#endif
