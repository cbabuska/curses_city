#ifndef TRANSIT_H
#define TRANSIT_H

#include "Logger.h"
#include "Cell.h"

class Status_grid;

class Transit : public Cell
{
  public:
    Transit(int y, int x, int type, int color) : Cell(y, x, type, color) 
      {Logger::get_instance().write("Transit constructed");}
    virtual ~Transit() {Logger::get_instance().write("Transit destructed");}

    void update_state(const std::vector<std::vector<Cell*> >& grid, std::map<int, Status_grid*>& status_grids);
    unsigned char draw(const std::vector<std::vector<Cell*> >& grid, int& color_pair);

  protected:

  private:
};

#endif
