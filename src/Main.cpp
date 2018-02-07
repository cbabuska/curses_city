#include <string>
using std::string;

#include <vector>
using std::vector;

#include <map>
using std::map;

#include <iterator>
using std::iterator;

#include <utility>
using std::make_pair;

#include <cstdlib>
#include <ctime>

#include "Constants.h"
#include "View.h"
#include "Grid.h"
#include "Cursor.h"
#include "Cell_factory.h"
#include "Cell.h"
#include "Status_grid.h"

void update(Grid& grid, map<string, Status_grid*>& status_grids, Status& status);
void update_status_grids_land_values(Grid& grid, map<string, Status_grid*>& status_grids);

int main()
{
  // Initialize random number generator
  time_t init_time = time(NULL);
  srand(gmtime(&init_time)->tm_sec * gmtime(&init_time)->tm_min * gmtime(&init_time)->tm_hour * gmtime(&init_time)->tm_yday);

  map<string, Status_grid*> status_grids;
  for (int i=0; i<NUMBER_OF_ATTRIBUTES; ++i)
  {
    status_grids.insert(make_pair(ATTRIBUTES[i], new Status_grid(ATTRIBUTES[i])));
  }

  Grid grid;
  Cursor cursor;
  Status status;

  View view;
  view.draw_background(status);
  view.draw_grid_window(cursor, grid);
  view.draw_status_window(cursor, status, grid.get_cell(cursor.get_y(), cursor.get_x())->get_land_values(), status_grids);

  timeout(1000);

  bool loop_flag = true;
  int input;
  string status_message;
  Cell* new_cell;
  time_t update_time = time(NULL);
  while (loop_flag)
  {
    if (difftime(time(NULL), update_time) > 5)
    {
      update(grid, status_grids, status);
      status.update_iteration();
      status.update_date();
      update_time = time(NULL);
    }

    input = getch();

    switch (input)
    {
      case 'Q':
        loop_flag = false;
        break;

      case 'h':
      case KEY_LEFT:
        cursor.move_cursor('w');
        break;
      case 'j':
      case KEY_DOWN:
        cursor.move_cursor('s');
        break;
      case 'k':
      case KEY_UP:
        cursor.move_cursor('n');
        break;
      case 'l':
      case KEY_RIGHT:
        cursor.move_cursor('e');
        break;

      case '\n':
        update(grid, status_grids, status);
        status.update_iteration();
        break;
        
      case 'x':
        new_cell = Cell_factory::create_cell(input, cursor.get_y(), cursor.get_x());
        status_message = grid.replace(cursor.get_y(), cursor.get_x(), new_cell);
        update_status_grids_land_values(grid, status_grids);
        break;

      default:
        new_cell = Cell_factory::create_cell(input, cursor.get_y(), cursor.get_x());
        if (new_cell)
        {
          status_message = grid.build(cursor.get_y(), cursor.get_x(), new_cell, status); 
          update_status_grids_land_values(grid, status_grids);
        }
        break;
    }

    view.draw_background(status, status_message);
    view.draw_grid_window(cursor, grid);
    view.draw_status_window(cursor, status, grid.get_cell(cursor.get_y(), cursor.get_x())->get_land_values(), status_grids);
  }
}

// This is the core of the simulation
void update(Grid& grid, map<string, Status_grid*>& status_grids, Status& status)
{
  // Collect taxes
  grid.collect_taxes(status);

  // Pay for services
  grid.pay_for_services(status);

  // Update status grids
  for (map<string, Status_grid*>::iterator it = status_grids.begin(); it != status_grids.end(); ++it)
  {
    it->second->update(grid, status_grids);
  }

  // Calc land values
  grid.calculate_land_values(status_grids);

  // Update cells
  grid.update_state();

  // Update status grids
  for (map<string, Status_grid*>::iterator it = status_grids.begin(); it != status_grids.end(); ++it)
  {
    it->second->update(grid, status_grids);
  }
}

// When a new municipal building is placed do this to get up to date data
void update_status_grids_land_values(Grid& grid, map<string, Status_grid*>& status_grids)
{
  // Update status grids
  for (map<string, Status_grid*>::iterator it = status_grids.begin(); it != status_grids.end(); ++it)
  {
    it->second->update(grid, status_grids);
  }

  // Calc land values
  grid.calculate_land_values(status_grids);
}
