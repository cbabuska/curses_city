#ifndef STATUS_GRID_H
#define STATUS_GRID_H

#include <vector>
#include <map>
#include <string>

#include "Logger.h"
#include "Grid.h"

class Cell;

class Status_grid
{
  public:
    Status_grid(std::string attribute);
    virtual ~Status_grid() {Logger::get_instance().write("Status grid destructed");}

    virtual void update(Grid& grid, std::map<std::string, Status_grid*>& status_grids);
    const std::vector<std::vector<int> >& get_grid() {return status_grid;}

  protected:
    std::vector<std::vector<int> > status_grid;
    std::string attribute;

  private:                    
};

#endif
