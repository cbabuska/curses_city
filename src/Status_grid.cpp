#include "Status_grid.h"

using std::vector;
using std::map;
using std::string;

#include "Constants.h"
#include "Municipal.h"

Status_grid::Status_grid(string attribute) : attribute(attribute)
{
  Logger::get_instance().write("Status grid constructed");

  status_grid.resize(Y_SIZE);
  for (unsigned int y=0; y<status_grid.size(); ++y)
  {
    status_grid[y].resize(X_SIZE);
  }
}

void Status_grid::update(Grid& grid, map<string, Status_grid*>& status_grids)
{
  // Identify cells with attribute
  for (int y=0; y<Y_SIZE; ++y)
  {
    for (int x=0; x<X_SIZE; ++x)
    {
      status_grid[y][x] = 0;

      for (unsigned int i=0; i<(grid.get_cell(y, x))->get_attributes().size(); ++i)
      {  
        if ((grid.get_cell(y, x))->get_attributes()[i].first == attribute)
        {
          switch (grid.get_cell(y, x)->get_state())
          {
            case ACTIVE:
              status_grid[y][x] = (grid.get_cell(y, x))->get_attributes()[i].second+1; 
              break;

            case LOW_DENSITY:
              status_grid[y][x] = (grid.get_cell(y, x))->get_attributes()[i].second+1; 
              break;

            case MEDIUM_DENSITY:
              status_grid[y][x] = (grid.get_cell(y, x))->get_attributes()[i].second*5+1; 
              break;

            case HIGH_DENSITY:
              status_grid[y][x] = (grid.get_cell(y, x))->get_attributes()[i].second*20+1; 
              break;
          }
        }
      }
    }
  }

  // Fan out scores for entire grid
  for (int i=0; i<Y_SIZE+X_SIZE; ++i)
  {
    for (int y=0; y<Y_SIZE; ++y)
    {
      for (int x=0; x<X_SIZE; ++x)
      {
        if (y>0 && status_grid[y-1][x]>status_grid[y][x])
        {
          status_grid[y][x] = status_grid[y-1][x]-1;
        }
        if (y<Y_SIZE-1 && status_grid[y+1][x]>status_grid[y][x])
        {
          status_grid[y][x] = status_grid[y+1][x]-1;
        }
        if (x>0 && status_grid[y][x-1]>status_grid[y][x])
        {
          status_grid[y][x] = status_grid[y][x-1]-1;
        }
        if (x<X_SIZE-1 && status_grid[y][x+1]>status_grid[y][x])
        {
          status_grid[y][x] = status_grid[y][x+1]-1;
        }
      }
    }
  }

  // Translate to 0-100 scores
  for (int y=0; y<Y_SIZE; ++y)
  {
    for (int x=0; x<X_SIZE; ++x)
    {
      if (status_grid[y][x] > 0)
      {
        //status_grid[y][x] = 100;
      }
    }
  }
  
  // Modify scores based on grid


}
