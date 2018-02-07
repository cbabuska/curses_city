#include "Road.h"

#include <curses.h>

#include "Constants.h"

using std::vector;
using std::map;

void Road::update_state(const vector<vector<Cell*> >& grid, map<int, Status_grid*>& status_maps)
{
  return;
}

unsigned char Road::draw(const vector<vector<Cell*> >& grid, int& color_pair)
{
  color_pair = WHITE;

  if (((y>0 && dynamic_cast<Road*>(grid[y-1][x])) || (y<grid.size()-1 && dynamic_cast<Road*>(grid[y+1][x]))) &&
      ((x>0 && dynamic_cast<Road*>(grid[y][x-1])) || (x<grid[0].size()-1 && dynamic_cast<Road*>(grid[y][x+1]))))
  {
    return '+';
  }
  else if ((y>0 && dynamic_cast<Road*>(grid[y-1][x])) || (y<grid.size()-1 && dynamic_cast<Road*>(grid[y+1][x])))
  {
    return '|';
  }
  else if ((x>0 && dynamic_cast<Road*>(grid[y][x-1])) || (x<grid[0].size()-1 && dynamic_cast<Road*>(grid[y][x+1])))
  {
    return '-';
  }
  else
  {
    return '+';
  }
}
