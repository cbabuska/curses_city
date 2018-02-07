#ifndef ROAD_H 
#define ROAD_H

#include "Logger.h"
#include "Transit.h"

class Status_grid;

class Road : public Transit
{
  public:
    Road(int y, int x) : Transit(y, x) {Logger::get_instance().write("Road constructed");}
    ~Road() {Logger::get_instance().write("Road destructed");}

    void update_state(const std::vector<std::vector<Cell*> >& grid, std::map<int, Status_grid*>& status_grids);
    unsigned char draw(const std::vector<std::vector<Cell*> >& grid, int& color_pair);

  protected:

  private:
};

#endif

