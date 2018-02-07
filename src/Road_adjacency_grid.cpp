#include "Road_adjacency_grid.h"

using std::vector;
using std::map;

#include "Constants.h"
#include "Transit.h"

void Road_adjacency_grid::update(const vector<vector<Cell*> >& grid, map<int, Status_grid*>& status_grids)
{
  for (int y=0; y<Y_SIZE; ++y)
  {
    for (int x=0; x<X_SIZE; ++x)
    {
      if ((y>0 && dynamic_cast<Transit*>(grid[y-1][x]) && ((grid[y-1][x])->get_type()==ROAD)) ||
          (y<Y_SIZE-1 && dynamic_cast<Transit*>(grid[y+1][x]) && ((grid[y+1][x])->get_type()==ROAD)) ||
          (x>0 && dynamic_cast<Transit*>(grid[y][x-1]) && ((grid[y][x-1])->get_type()==ROAD)) ||
          (x<X_SIZE-1 && dynamic_cast<Transit*>(grid[y][x+1]) && ((grid[y][x+1])->get_type()==ROAD)))
      {
        status_grid[y][x] = 1;
      }
      else
      {
        status_grid[y][x] = 0;
      }
    }
  }
}
