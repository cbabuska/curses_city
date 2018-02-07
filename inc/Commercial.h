#ifndef COMMERCIAL_H
#define COMMERCIAL_H

#include "Logger.h"
#include "Zone.h"

class Status_grid;

class Commercial : public Zone
{
  public:
    Commercial(int y, int x) : Zone(y, x) {Logger::get_instance().write("Commercial constructed");}
    ~Commercial() {Logger::get_instance().write("Commercial destructed");}

    void update_state(const std::vector<std::vector<Cell*> >& grid, std::map<int, Status_grid*>& status_grids);
    unsigned char draw(const std::vector<std::vector<Cell*> >& grid, int& color_pair);

  protected:

  private:
};

#endif 
