#ifndef RESIDENTIAL_H
#define RESIDENTIAL_H

#include "Logger.h"
#include "Zone.h"

class Status_grid;

class Residential : public Zone
{
  public:
    Residential(int y, int x) : Zone(y, x) {Logger::get_instance().write("Residential constructed");}
    ~Residential() {Logger::get_instance().write("Residential destructed");}

    void update_state(const std::vector<std::vector<Cell*> >& grid, std::map<int, Status_grid*>& status_grids);
    unsigned char draw(const std::vector<std::vector<Cell*> >& grid, int& color_pair);

  protected:

  private:
};

#endif 
