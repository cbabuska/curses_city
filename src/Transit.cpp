#include "Transit.h"

#include <curses.h>

#include "Constants.h"

using std::vector;
using std::map;

void Transit::update_state(const vector<vector<Cell*> >& grid, map<int, Status_grid*>& status_maps)
{
  return;
}

unsigned char Transit::draw(const vector<vector<Cell*> >& grid, int& color_pair)
{
  color_pair = color;

  if (((y>0 && (grid[y-1][x]->get_type()==type)) || (y<grid.size()-1 && (grid[y+1][x]->get_type()==type))) &&
      ((x>0 && (grid[y][x-1]->get_type()==type)) || (x<grid[0].size()-1 && (grid[y][x+1]->get_type()==type))))
  {
    return '+';
  }
  else if ((y>0 && (grid[y-1][x]->get_type()==type)) || (y<grid.size()-1 && (grid[y+1][x]->get_type()==type)))
  {
    return '|';
  }
  else if ((x>0 && (grid[y][x-1]->get_type()==type)) || (x<grid[0].size()-1 && (grid[y][x+1]->get_type()==type)))
  {
    return '-';
  }
  else
  {
    return '+';
  }
}
