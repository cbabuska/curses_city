#ifndef GRID_H
#define GRID_H

#include <vector>
#include <map>
#include <string>

#include "Logger.h"
#include "Status.h"

class Cell;
class Status_grid;

class Grid
{
  public:
    Grid();
    ~Grid();

    std::string build(int y, int x, Cell* new_cell, Status& status);
    std::string replace(int y, int x, Cell* new_cell);

    void collect_taxes(Status& status);
    void pay_for_services(Status& status);
    void calculate_land_values(std::map<std::string, Status_grid*>& status_grids);
    void update_state();

    Cell* get_cell(int y, int x) {return grid[y][x];}

  protected:

  private:
    std::vector<std::vector<Cell*> > grid;

};

#endif
