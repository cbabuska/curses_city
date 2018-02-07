#ifndef INDUSTRIAL_H
#define INDUSTRIAL_H

#include "Logger.h"
#include "Zone.h"

class Status_grid;

class Industrial : public Zone
{
  public:
    Industrial(int y, int x) : Zone(y, x) {Logger::get_instance().write("Industrial constructed");}
    ~Industrial() {Logger::get_instance().write("Industrial destructed");}

    void update_state(const std::vector<std::vector<Cell*> >& grid, std::map<int, Status_grid*>& status_grids);
    unsigned char draw(const std::vector<std::vector<Cell*> >& grid, int& color_pair);

  protected:

  private:
};

#endif 
