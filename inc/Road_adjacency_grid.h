#ifndef ROAD_ADJACENCY_GRID_H
#define ROAD_ADJACENCY_GRID_H

#include "Status_grid.h"

class Road_adjacency_grid : public Status_grid
{
  public:
    Road_adjacency_grid() {Logger::get_instance().write("Road adjacency grid constructed");}
    ~Road_adjacency_grid() {Logger::get_instance().write("Road adjacency grid destructed");}

    void update(const std::vector<std::vector<Cell*> >& grid, std::map<int, Status_grid*>& status_grids);

  protected:

  private:

};

#endif 
